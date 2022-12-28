#ifndef REGIS_H_INCLUDED
#define REGIS_H_INCLUDED

#include <iostream>

#define info(P) (P)->info

#define nextUniv(P) (P)->nextUniv
#define nextMhs(P) (P)->nextMhs
#define nextBeasiswa(P) (P)->nextBeasiswa
#define asalUniv(P) (P)->asalUniv

#define terdaftarBeasiswa(P) (P)->terdaftarBeasiswa
#define nextDaftar(P) (P)->nextDaftar

using namespace std;

struct mhs {
    string nama,nim;
    float ipk;
    int semester;
};

struct beasiswa {
    string nama, instansi, benefit;
    //benefit isinya mau apa aja? atau mau dipersimpel jadi besaran uang aja?
    syaratBeasiswa syarat; //string ati mau di how-in?
};

struct syaratBeasiswa{
    float ipkMin;
    int semester;
  
    bool statusNegeri;
    char akreditasi;
}

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
    mhs info;
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
}

struct listMhs {
    adrMhs first;
    //adrMhs last; ::Mau Pake Last?::
};

struct listUniv {
    adrUniv first;
    //adrMhs last; ::Mau Pake Last?::
};

struct listBeasiswa {
    adrBeasiswa first;
    //adrMhs last; ::Mau Pake Last?::
};

#endif // REGIS_H_INCLUDED
