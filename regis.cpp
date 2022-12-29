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

//DIsini kudunya ada func/proc buat si adrChildBeasiswa, atau kalo ada cara lbh better sok aja (janlup jelasin wkwk)
//adrUniv gaperlu lg soalnya udh di atas, jd sisa yg kata adrChildBeasiswa aj yg w bingung (yg udh w mention di atas jg)

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
        adrUniv b = first(B);   
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
        adrUniv m = first(M);   
        while (next(m) != nil) {
            m = next(m);   
        }
        next(m) = p;
    }
}
