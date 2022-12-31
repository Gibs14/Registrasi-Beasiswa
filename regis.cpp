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

//prosedur untuk child dari elmMahasiswa
void mendaftarBeasiswa(adrMhs pendaftar, adrBeasiswa inBeasiswa) { 
    //insertlastChildBeasiwa
    adrChildBeasiswa p = terdaftarBeasiswa(pendaftar), temp = new childBeasiswa;
    
    connect(temp) = inBeasiswa
    next(temp) = nil;
    
    
    if(terdaftarBeasiswa(pendaftar) == nil){
        terdaftarBeasiswa(pendaftar) = temp;
    } else {
        while(next(p) != nil){
            p = next(p);
        }
        
        next(p) = temp;
    }
} 

void keluarBeasiswa(adrMhs pendaftar, adrBeasiswa outBeasiswa) {//unfinished
    adrChildBeasiswa p = terdaftarBeasiswa(pendaftar);
    if (p == nil){
        cout << "Tidak ada beasiswa yang terdaftar" << endl;
    } else if (connect(p) == outBeasiswa){
        terdaftarBeasiswa(pendaftar) = next(p);
    } else {
        while(next(p) != nil){
            if(connect(next(p)) == outBeasiswa){
                if(p == terdaftarBeasiswa(pendaftar)) terdaftarBeasiswa = next(p);
                next(p) = next(next(p);
                break;
            }
            p = next(p);
        }
    }
} //deleteChildBeasiwa

void terimaBeasiswa(adrMhs pendaftar) {
//cek mahasiswa memenuhi syarat atau tidak. Jika tidak, remove.
    adrChildBeasiswa p = terdaftarBeasiswa(pendaftar);
    
    while(p != nil){
        if(diterima(p) == false{
            if(connect(p) == nil){
                p = next(p)
                keluarBeasiswa(pendaftar, nil);
            } else {
                diterima(p) = info(connect(p)).statusNegeri == info(asalUniv(pendaftar)).statusNegeri
                                && info(connect(p)).akreditasi >= info(asalUniv(p)).akreditasi
                                && info(connect(p)).semester == info(pendaftar).semester
                                && info(connect(p)).ipkMin <= info(pendaftar).ipk);
                if(diterima==false){
                    p = next(p)
                    keluarBeasiswa(pendaftar, connect(p));
                } else {
                    p = next(p);
                }
            }
        }
    }
}
           
void pindahUniv(adrMhs pendaftar, adrUniv newUniv) {
    keluarUniv(pendaftar);
    masukUniv(pendaftar, newUniv);
}

void masukUniv(adrMhs pendaftar, adrUniv newUniv) {
    if (asalUniv(pendaftar) == nil){
        asalUniv(pendaftar) = newUniv;
    } else {
        cout << info(pendaftar).nama << " sudah terdaftar di universitas lain" < endl;
    }
}
                               
void keluarUniv(adrMhs pendaftar) {
    asalUniv(pendaftar) = nil;
}
                               
void removeNullBeasiswa(adrMhs pendaftar) {
    adrChildBeasiswa p = terdaftarBeasiswa(pendaftar);
    
    while(p != nil){
        if(connect(p) == nil){
            p = next(p)
            keluarBeasiswa(pendaftar, nil);
        } else {
            p = next(p);
        } 
    }
}
//end

adrMhs createAdrMhs(infoMhs infoM) {
    adrMhs p;
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
    adrMhs m = first(M);
    if (first(U) != nil) {
        while (m != nil) { //utk putus koneksi mhs dgn univ
            if (asalUniv(m).nama == info(p).nama) {
                asalUniv(m) = nil;    
            }
            m = next(m);
        }
        
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
    } else {
        cout << "List Universitas sudah kosong!" << endl;
    }
}

void deleteBeasiswa(listBeasiswa &B, adrBeasiswa p) {
    
}

void deleteMhs(listMhs &M, adrMhs p) {
    
}

           
void showMahasiswa(listMhs M) {
    if (first(M) != nil) {
        adrMhs p = first(M);
        while (p != nil) {
            adrBeasiswa x = connect(terdaftarBeasiswa(p));
            cout << "Nama mahasiswa : " << info(p).nama << endl;
            cout << "NIM " << info(p).nama << " : " << info(p).nim << endl;
            cout << "IPK " << info(p).nama << " : " << info(p).ipk << endl;
            cout << "Semester " << info(p).nama << " : " << info(p).semester << endl;
            cout << "Nama universitas yang diikuti oleh " << info(p).nama << " : " << info(p).asalUniv.nama << endl;
            
            if (x == nil) {
                cout << info(p).nama << " Tidak terdaftar di beasiswa apapun" << endl;   
            } else {
                while (x != nil) {
                    cout << "Nama beasiswa yang diambil oleb " << info(p).nama << " : " << x.nama << endl;
                    x = next(x);
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
        adrBeasiswa p = first(B);
        while (p != nil) {
            cout << "Berikut nama beasiswanya : " << info(p).nama << endl;
            cout << "Berikut instansi pemberi beasiswanya : " << info(p).instansi << endl;
            cout << "Berikut benefit penerima beasiswa : " << info(p).benefit << endl << endl;
            cout << "Berikut syarat minimal IPK penerima beasiswa : " << info(p).syarat.ipkMin << endl;
            cout << "Berikut syarat minimal semester penerima beasiswa : " << info(p).syarat.semester << endl;
            if (info(p).syarat.statusNegeri == true) {
                cout << "Syarat status universitas penerima beasiswa : Negeri" << endl;
            } else {
                cout << "Syarat status universitas penerima beasiswa : Swasta" << endl;   
            }
            cout << "Berikut syarat minimal akreditasi universitas penerima beasiswa : " << info(p).syarat.akreditasi << endl;
            p = next(p);
        }
    } else {
        cout << "List beasiswa masih kosong, silahkan isi terlebih dahulu!" << endl;   
    }
}
           
void showUniversitas(listUniv U) {
    if (first(U) != nil) {
        adrUniv p = first(U);
        while (p != nil) {
            cout << "Nama Universitas : " << info(p).nama << endl;
            cout << "Akreditasi Universitas : " << info(p).akreditasi << endl;
            if (info(p).statusNegeri == true) {
                cout << "Status universitas : Negeri" << endl;
            } else {
                cout << "Status universitas : Swasta" << endl;   
            }
            p = next(p);
        }
    } else {
        cout << "List universitas masih kosong, silahkan isi terlebih dahulu!" << endl;   
    }
}
