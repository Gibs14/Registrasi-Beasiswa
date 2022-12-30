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
    p.statusNeger = statusNegeri;
    p.akreditas = akreditasi;
    return p;
}

adrBeasiswa createAdrBeasiswa(string nama, string instansi, string benefit, infoSyarat syarat) {
    adrBeasiswa p;
    p = new elmBeasiswa;
    info(p).nama = nama;
    info(p).instansi = instansi;
    info(p).benefit = benefit;
    info(p).infoSyarat = infoSyarat;
    next(p) = nil;
    return p;
}


infoMhs inputDataMhs(string nama, string nim, float ipk, int semester) {
    infoMhs p;
    p.nama = nama;
    p.nim = niml
    p.ipk = ipk;
    p.semester = semester;
    return p;
}

//prosedur untuk child dari elmMahasiswa
void mendaftarBeasiswa(adrMhs pendaftar, adrBeasiswa inBeasiswa) {
    adrChildBeasiswa p = terdaftarBeasiswa(pendaftar), temp = new childBeasiswa;
    
    connect(temp) = inBeasiswa
    next(temp) = nil;
    
    if(terdaftarBeasiswa(pendaftar) == nil){
        terdaftarBeasiswa(pendaftar) = temp;
    } else {
        while(next(p) != nil){
            p = next(p)
        }
        
        next(p) = temp;
    }
    
    
    
    
} //insertlastChildBeasiwa

void keluarBeasiswa(adrMhs pendaftar, adrBeasiswa inBeasiswa) {
    adrChildBeasiswa p = terdaftarBeasiswa(pendaftar);
    if (p == nil){
    } else if (next(p) == nil){
        
    } else {
        while(next(p) != nil){
            if(next(p) == inBeasiswa){
                next(p) = next(next(p);
                break;
            }
            p = next(p);
        }
    }
   
} //deleteChildBeasiwa

void terimaBeasiswa(adrMhs pendaftar) {
    
} //cek mahasiswa memenuhi syarat atau tidak. Jika tidak, remove.

void pindahUniv(adrMhs pendaftar, adrUniv asalUniv) {
    keluarUniv(pendaftar);
    masukUniv(pendaftar, asalUniv);
} //kalau kira2 tidak diperlukan remove aja

void masukUniv(adrMhs pendaftar, adrUniv asalUniv) {
    if (asalUniv(pendaftar) == nil){
        asalUniv(pendaftar) = asalUniv;
    }
} //
                               
void keluarUniv(adrMhs pendaftar) {
    if (asalUniv(pendaftar) != nil){
        asalUniv(pendaftar) = nil;
    }
}

void removeNullUniv(adrMhs pendaftar) {
    
} //remove beasiswa atau univ yg null setelah delete

void removeNullBeasiswa(adrMhs pendaftar) {
    
}
//end

adrMhs createAdrMhs(infoMhs infoM, adrUniv asalUniv, adrChildBeasiswa inBeasiswa) {

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

void deleteUniv(listUniv &U, adrUniv p) {
    
}

void deleteBeasiswa(listBeasiswa &B, adrBeasiswa p) {
    
}

void deleteMhs(listMhs &M, adrMhs p) {
    
}
