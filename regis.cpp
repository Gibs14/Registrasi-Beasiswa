#include "regis.h"

void createListMhs(listMhs &M) {
    first(M) = nil;
}

void createListUniv(listUniv &U) {
    first(U) = nil;
}

void createListBeasiswa(listBeasiswa &B) {
    first(B) = nil;
}

adrUniv createAdrUniv(string nama, bool statusNegri, char Akreditasi) {
    adrUniv p;
    p = new elmUniv;
    info(p).nama = nama;
    info(p).statusNegeri = statusNegri;
    info(p).akreditasi = Akreditasi;
    next(p) = nil;
    return p;
}


infoSyarat inputSyaratBeasiswa(float ipkMin, int semester, bool statusNegeri, char akreditasi) {
    infoSyarat p;
    p.ipkMin = ipkMin;
    p.semester = semester;
    p.statusNegeri = statusNegeri;
    p.akreditasi = akreditasi;
    return p;
}

adrBeasiswa createAdrBeasiswa(string nama, string instansi, string benefit, infoSyarat syarat) {
    adrBeasiswa p;
    p = new elmBeasiswa;
    info(p).nama = nama;
    info(p).instansi = instansi;
    info(p).benefit = benefit;
    info(p).syarat = syarat;
    next(p) = nil;
    return p;
}


infoMhs inputDataMhs(string nama, string nim, float ipk, int semester) {
    infoMhs p;
    p.nama = nama;
    p.nim = nim;
    p.ipk = ipk;
    p.semester = semester;
    return p;
}

//Masih?
//prosedur untuk child dari elmMahasiswa
void mendaftarBeasiswa(adrMhs pendaftar, adrBeasiswa inBeasiswa) {
    //insertlastChildBeasiwa
    adrChildBeasiswa p = terdaftarBeasiswa(pendaftar), temp = new childBeasiswa;

    connect(temp) = inBeasiswa;
    diterima(temp) = false;
    next(temp) = nil;
    
    bool sudahTerdaftar = false;

    if(terdaftarBeasiswa(pendaftar) == nil){
        terdaftarBeasiswa(pendaftar) = temp;
    } else {
        while(next(p) != nil){
            if(connect(p) == inBeasiswa){
                sudahTerdaftar = true;
                cout << info(pendaftar).nama << " sudah mendaftar di beasiswa ini" << endl;
                break;
            }
            p = next(p);
        }

        if(sudahTerdaftar == false) next(p) = temp;
    }
}

//Masih?
void keluarBeasiswa(adrMhs pendaftar, adrBeasiswa outBeasiswa) {//unfinished
    adrChildBeasiswa p = terdaftarBeasiswa(pendaftar), prec;
    adrBeasiswa x = connect(p);
    
    if (p == nil){
        cout << info(pendaftar).nama << " belum mendaftar di beasiswa manapun" << endl;
    } else if (x == outBeasiswa){
        terdaftarBeasiswa(pendaftar) = next(p);
    } else {
        prec = p;
        p = next(p);
        x = connect(p);
        
        while(p != nil){
            if(x == outBeasiswa){
                next(prec) = next(p);
                next(p) = nil;
                break;
            }
                               
            prec = p;
            p = next(p);
            x = connect(p);
        }
    }
} //deleteChildBeasiwa

void terimaBeasiswa(adrMhs pendaftar) {
//cek mahasiswa memenuhi syarat atau tidak. Jika tidak, remove.
    adrChildBeasiswa p = terdaftarBeasiswa(pendaftar);
    adrBeasiswa x = connect(p);

    while(p != nil){
        if(diterima(p) == false){
            if(connect(p) == nil){
                p = next(p);
                keluarBeasiswa(pendaftar, nil);
            } else {
                diterima(p) = info(x).syarat.statusNegeri == info(asalUniv(pendaftar)).statusNegeri
                                && info(x).syarat.akreditasi >= info(asalUniv(pendaftar)).akreditasi
                                && info(x).syarat.semester <= info(pendaftar).semester
                                && info(x).syarat.ipkMin <= info(pendaftar).ipk;
                
                p = next(p);
                x = connect(p);
                if(diterima(p)==false) keluarBeasiswa(pendaftar, x);
            }
        }
    }
}

void pindahUniv(adrMhs pendaftar, adrUniv newUniv) {
    keluarUniv(pendaftar);
    masukUniv(pendaftar, newUniv);
}

void masukUniv(adrMhs pendaftar, adrUniv newUniv) {
    if (asalUniv(pendaftar) == nil) asalUniv(pendaftar) = newUniv;
    else cout << info(pendaftar).nama << " sudah terdaftar di universitas lain" << endl;
}

void keluarUniv(adrMhs pendaftar) {
    if (asalUniv(pendaftar) != nil) asalUniv(pendaftar) = nil;
    else cout << info(pendaftar).nama << " belum terdaftar di universitas manapun" << endl;
}

void removeNullUniv(listMhs &M, adrUniv p){
    adrMhs m = first(M);
    
    while (m != nil) {
        if (asalUniv(m) == p) {
            keluarUniv(m);
        }
        m = next(m);
    }
}

void removeNullBeasiswa(listMhs &M, adrBeasiswa p){
    adrMhs m = first(M);

    while(m != nil){
        keluarBeasiswa(m, p);
        m = next(m);
    }
}
//end

adrMhs createAdrMhs(infoMhs infoM) {
    adrMhs p = new elmMhs;
    info(p) = infoM;
    asalUniv(p) = nil;
    terdaftarBeasiswa(p) = nil;
    next(p) = nil;
    return p;
}


void addUniv(listUniv &U, adrUniv p) {
    if (first(U) == nil) {
        first(U) = p;
    } else {
        adrUniv u = first(U);
        while (next(u) != nil) {
            u = next(u);
        }
        next(u) = p;
    }
}

void addBeasiswa(listBeasiswa &B, adrBeasiswa p) {
    if (first(B) == nil) {
        first(B) = p;
    } else {
        adrBeasiswa b = first(B);
        while (next(b) != nil) {
            b = next(b);
        }
        next(b) = p;
    }
}

void addMhs(listMhs &M, adrMhs p) {
    if (first(M) == nil) {
        first(M) = p;
    } else {
        adrMhs m = first(M);
        while (next(m) != nil) {
            m = next(m);
        }
        next(m) = p;
    }
}

void deleteUniv(listUniv &U, listMhs &M, adrUniv p) {
    adrUniv x = first(U);
    if (first(U) != nil) {
        while (next(x) != nil) {// X nnti akan = last(U)
            x = next(x);
        }

        if (first(U) == p) { // delete first
            first(U) = next(first(U));
            next(p) = nil;
        } else if (p == x) { // delete last
            x = first(U);
            while (next(next(x)) != nil) { // x nanti = 1 elemen sebelum last(U)
                x = next(x);
            }
            next(x) = nil;
        } else {
            x = first(U);
            while (next(x) != p) { // x akan = 1 elemen sebelum p
                x = next(x);
            }
            next(x) = next(p);
            next(p) = nil;
        }
        
        removeNullUniv(M, p);
    } else {
        cout << "List Universitas sudah kosong!" << endl;
    }
}

void deleteBeasiswa(listBeasiswa &B, listMhs &M, adrBeasiswa p) {
    if (first(B) != nil) {
        adrBeasiswa x = first(B);
        while (next(x) != nil) {//x nnti akan = last(B)
            x = next(x);
        }

        if (first(B) == p) {
            first(B) = next(first(B));
            next(p) = nil;
        } else if (p == x) {
            x = first(B);
            while (next(next(x)) != nil) { // x akan = 1 elemen sblum last(B)
                x = next(x);
            }
            next(x) = nil;
        } else {
            x = first(B);
            while (next(x) != p) { // x akan = 1 elemen sblum p
                x = next(x);
            }
            next(x) = next(p);
            next(p) = nil;
        }
        removeNullBeasiswa(M, p);
    } else {
        cout << "List Beasiswa sudah kosong!" << endl;
    }
}

void deleteMhs(listMhs &M, adrMhs p) {
    if (first(M) != nil) {
        adrMhs x = first(M);
        while (next(x) != nil) {//x nnti akan = last(M)
            x = next(x);
        }

        if (first(M) == p) {
            first(M) = next(first(M));
            asalUniv(p) = nil;
            terdaftarBeasiswa(p) = nil;
            next(p) = nil;
        } else if (p == x) {
            x = first(M);
            while (next(next(x)) != nil) { // x nanti = 1 elemen sebelum last(M)
                x = next(x);
            }
            asalUniv(p) = nil;
            terdaftarBeasiswa(p) = nil;
            next(x) = nil;
        } else {
            x = first(M);
            while (next(x) != p) { // x akan = 1 elemen sebelum p
                x = next(x);
            }
            asalUniv(p) = nil;
            terdaftarBeasiswa(p) = nil;
            next(x) = next(p);
            next(p) = nil;
        }

    } else {
        cout << "List Mahasiswa sudah kosong!" << endl;
    }

}


void showMahasiswa(listMhs M) {
    if (first(M) != nil) {
        cout << "Mahasiswa" << endl << endl;
        adrMhs p = first(M);
        adrBeasiswa x;
        adrChildBeasiswa childB;
        int i;
        while (p != nil) {
            childB = terdaftarBeasiswa(p);
            cout << "Nama     : " << info(p).nama << endl;
            cout << "NIM      : " << info(p).nim << endl;
            cout << "IPK      : " << info(p).ipk << endl;
            cout << "Semester :" << info(p).semester << endl;
            cout << "Asal universitas : " << info(asalUniv(p)).nama << endl;
            
            i = 0;
            if (childB == nil) {
                cout << info(p).nama << " Tidak terdaftar di beasiswa apapun" << endl;
            } else {
                x = connect(childB);
                cout << "Beasiswa yang terdaftar :" << info(x).nama << endl;
                while (childB != nil) {
                    cout << i++ << ". " << info(x).nama << endl;
                    childB = next(childB);
                    x = connect(childB);
                }
            }

            p = next(p);
        }
    } else {
        cout << "List mahasiswa masih kosong, silahkan isi terlebih dahulu!" << endl;
    }
}

void showBeasiswa(listBeasiswa B) {
    if (first(B) != nil) {
        cout << "Beasiswa" << endl << endl;
        adrBeasiswa p = first(B);
        while (p != nil) {
            cout << "Nama     : " << info(p).nama << endl;
            cout << "Instansi : " << info(p).instansi << endl;
            cout << "Benefit  : " << info(p).benefit << endl;
            cout << "Syarat beasiswa :" << endl;
            cout << "    IPK minimal         : " << info(p).syarat.ipkMin << endl;
            cout << "    Semester minimal    : " << info(p).syarat.semester << endl;
            cout << "    Status universitas  : ";
            
            if (info(p).syarat.statusNegeri == true) {
                cout << "Negeri" << endl;
            } else {
                cout << "Swasta" << endl;
            }
            cout << "    Akreditasi minimal : " << info(p).syarat.akreditasi << endl << endl;
            p = next(p);
        }
    } else {
        cout << "List beasiswa masih kosong, silahkan isi terlebih dahulu!" << endl;
    }
}

void showUniversitas(listUniv U) {
    if (first(U) != nil) {
        cout << "Universitas" << endl << endl;
        adrUniv p = first(U);
        while (p != nil) {
            cout << "Nama : " << info(p).nama << endl;
            cout << "Akreditasi : " << info(p).akreditasi << endl;
            if (info(p).statusNegeri == true) {
                cout << "Status : Negeri" << endl;
            } else {
                cout << "Status : Swasta" << endl;
            }
            p = next(p);
        }
    } else {
        cout << "List universitas masih kosong, silahkan isi terlebih dahulu!" << endl;
    }
}

adrMhs searchMahasiswa(listMhs M, string NIM) {
    adrMhs p = first(M);
    adrMhs hasil;
    bool ketemu = false;
    while (p != nil && !ketemu) {
        if (info(p).nim == NIM) {
            hasil = p;
            ketemu = true;
        }
        p = next(p);
    }
    if (ketemu) {
        return hasil;
    } else {
        return nil;
    }
}

adrUniv searchUniversitas(listUniv U, string nama) {
    adrUniv p = first(U);
    adrUniv hasil;
    bool ketemu = false;
    while (p != nil && !ketemu) {
        if (info(p).nama == nama) {
            hasil = p;
            ketemu = true;
        }
        p = next(p);
    }
    if (ketemu) {
        return hasil;
    } else {
        return nil;
    }
}

adrBeasiswa searchBeasiswa(listBeasiswa B, string nama) { // nyari berdasar nama beasiswa kan (?)
    adrBeasiswa p = first(B);
    adrBeasiswa hasil;
    bool ketemu = false;
    while (p != nil && !ketemu) {
        if (info(p).nama == nama) {
            hasil = p;
            ketemu = true;
        }
        p = next(p);
    }
    if (ketemu) {
        return hasil;
    } else {
        return nil;
    }
}
