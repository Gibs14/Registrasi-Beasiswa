#ifndef REGIS_H_INCLUDED
#define REGIS_H_INCLUDED

#include <iostream>

#define info(P) (P)->info
#define nextUniv(P) (P)->nextUniv
#define nextMhs(P) (P)->nextMhs
#define nextBeasiswa(P) (P)->nextBeasiswa

using namespace std;

struct mhs {
  string nama,nim;
  int ipk,semester;
};

struct beasiswa {
  string nama,instansi,benefit;
  string syarat; //string ati mau di how-in?
};

struct univ {
  string nama;
  bool statusNegeri;
  char akreditasi;
};

typedef struct elmMhs *adrMhs;
typedef struct elmUniv *adrUniv;
typedef struct elmBeasiswa *adrBeasiswa;

struct elmMhs {
    mhs info;
    adrUniv nextUniv;
    adrBeasiswa nextBeasiswa;
    adrMhs nextMhs;
};

struct elmUniv {
    beasiswa info;
    adrUniv nextUniv;
};

struct elmBeasiswa {
    beasiswa info;
    adrBeasiswa nextBeasiswa;
};

struct listMhs {
    adrMhs first;
    //adrMhs last; ::Mau Pake Last?::
};

struct listBeasiswa {
    adrBeasiswa first;
    //adrMhs last; ::Mau Pake Last?::
};

#endif // REGIS_H_INCLUDED
