#ifndef REGIS_H_INCLUDED
#define REGIS_H_INCLUDED

#include <iostream>

#define first(L) ((L).first)
#define info(P) (P)->info

#define nextUniv(P) (P)->nextUniv
#define nextMhs(P) (P)->nextMhs
#define nextBeasiswa(P) (P)->nextBeasiswa
#define asalUniv(P) (P)->asalUniv

#define terdaftarBeasiswa(P) (P)->terdaftarBeasiswa
#define nextDaftar(P) (P)->nextDaftar
#define nil NULL

using namespace std;

struct mhs {
    string nama,nim;
    float ipk;
    int semester;
};

typedef mhs infoMhs;

struct beasiswa {
    string nama, instansi, benefit;
    //benefit isinya mau apa aja? atau mau dipersimpel jadi besaran uang aja?
    infoSyarat syarat; //string ati mau di how-in?
                        //Maksudnya string ati apa ya? -Gibran
};

struct syaratBeasiswa{
    float ipkMin;
    int semester;
  
    bool statusNegeri;
    char akreditasi;
}

typedef syaratBeasiswa infoSyarat;

struct univ {
    string nama;
    bool statusNegeri;
    char akreditasi;
};

typedef struct elmMhs *adrMhs;
typedef struct elmUniv *adrUniv;
typedef struct elmBeasiswa *adrBeasiswa;

typedef struct childBeasiswa *adrChildBeasiswa;

struct elmMhs {
    infoMhs info;
    adrUniv asalUniv;
    adrChildBeasiswa terdaftarBeasiswa;
    adrMhs nextMhs;
};

struct elmUniv {
    univ info;
    adrUniv nextUniv;
};

struct elmBeasiswa {
    beasiswa info;
    adrBeasiswa nextBeasiswa;
};

struct childBeasiswa{
    //diperlukan supaya mahasiswa bisa daftar lebih dari 1 beasiswa
    adrBeasiswa connectBeasiswa; //rename jika ada yg lebih clear
    adrChildBeasiswa nextDaftar;
} //Gw msh bingung disini (bingung buat function/prosedurnya) biar lbh jelasnya sok lihat bagian bwh, mhn bantuannya -Gibran

struct listMhs {
    adrMhs first;
};

struct listUniv {
    adrUniv first;
};

struct listBeasiswa {
    adrBeasiswa first;
};

void createListMhs(listMhs &M);
void createListUniv(listUniv &U);
void createListBeasiswa(listBeasiswa &B);

adrUniv createAdrUniv(string nama, bool statusNegri, char Akreditasi);

infoSyarat inputSyaratBeasiswa(float ipkMin, int semester, bool statusNegeri, char akreditasi);
adrBeasiswa createAdrBeasiswa(string nama, string instansi, string benefit, infoSyarat syarat);

infoMhs inputDataMhs(string nama, string nim, float ipk, int semester);
//DIsini kudunya ada func/proc buat si adrChildBeasiswa, atau kalo ada cara lbh better sok aja (janlup jelasin wkwk)
//adrUniv gaperlu lg soalnya udh di atas, jd sisa yg kata adrChildBeasiswa aj yg w bingung (yg udh w mention di atas jg)
adrMhs createAdrMhs(infoMhs infoM, adrUniv asalUniv, adrChildBeasiswa inBeasiswa);

void addUniv(listUniv &U, adrUniv p);
void addBeasiswa(listBeasiswa &B, adrBeasiswa p);
void addMhs(listMhs &M, adrMhs p);


#endif // REGIS_H_INCLUDED
