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

}

adrBeasiswa createAdrBeasiswa(string nama, string instansi, string benefit, infoSyarat syarat) {

}


infoMhs inputDataMhs(string nama, string nim, float ipk, int semester) {

}

//DIsini kudunya ada func/proc buat si adrChildBeasiswa, atau kalo ada cara lbh better sok aja (janlup jelasin wkwk)
//adrUniv gaperlu lg soalnya udh di atas, jd sisa yg kata adrChildBeasiswa aj yg w bingung (yg udh w mention di atas jg)

adrMhs createAdrMhs(infoMhs infoM, adrUniv asalUniv, adrChildBeasiswa inBeasiswa) {

}


void addUniv(listUniv &U, adrUniv p) {

}

void addBeasiswa(listBeasiswa &B, adrBeasiswa p) {

}

void addMhs(listMhs &M, adrMhs p) {

}
