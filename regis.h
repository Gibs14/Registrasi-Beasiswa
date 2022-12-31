#ifndef REGIS_H_INCLUDED
#define REGIS_H_INCLUDED

#include <iostream>

#define first(L) ((L).first)
#define info(P) (P)->info
#define next(P) (P)->next

#define asalUniv(P) (P)->asalUniv
#define terdaftarBeasiswa(P) (P)->terdaftarBeasiswa

#define connect(P) (P)->connectBeasiswa

#define nil NULL

using namespace std;

struct mhs {
    string nama,nim;
    float ipk;
    int semester;
};

struct syaratBeasiswa{
    float ipkMin;
    int semester;

    bool statusNegeri;
    char akreditasi;
};

typedef mhs infoMhs;
typedef syaratBeasiswa infoSyarat;

struct beasiswa {
    string nama, instansi, benefit;
    //benefit isinya mau apa aja? atau mau dipersimpel jadi besaran uang aja?
    infoSyarat syarat;
};


struct univ {
    string nama;
    bool statusNegeri; //Yakin bool aja? Gamau string gtu? Jd nnti ditulis "Negeri" OR "Swasta" (?) - Gibran
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
    adrMhs next;
};

struct childBeasiswa{
    //diperlukan supaya mahasiswa bisa daftar lebih dari 1 beasiswa
    adrBeasiswa connectBeasiswa; //rename jika ada yg lebih clear
    adrChildBeasiswa next;
};

struct elmUniv {
    univ info;
    adrUniv next;
};

struct elmBeasiswa {
    beasiswa info;
    adrBeasiswa next;
};

struct listMhs {
    adrMhs first;
};

struct listUniv {
    adrUniv first;
};

struct listBeasiswa {
    adrBeasiswa first;
};


//mhs
void createListMhs(listMhs &M);
infoMhs inputDataMhs(string nama, string nim, float ipk, int semester);
adrMhs createAdrMhs(infoMhs infoM, adrUniv asalUniv);
void addMhs(listMhs &M, adrMhs p);
void deleteMhs(listMhs &M, adrMhs p);

//child dari mhs
void mendaftarBeasiswa(adrMhs pendaftar, adrBeasiswa inBeasiswa); //inserlastChildBeasiwa
void keluarBeasiswa(adrMhs pendaftar, adrBeasiswa inBeasiswa); //deleteChildBeasiwa
void terimaBeasiswa(adrMhs pendaftar); //cek mahasiswa memenuhi syarat atau tidak. Jika tidak, remove.

void pindahUniv(adrMhs pendaftar, adrUniv asalUniv);
void masukUniv(adrMhs pendaftar, adrUniv asalUniv);
void keluarUniv(adrMhs pendaftar);

void removeNullUniv(adrMhs pendaftar); //remove beasiswa atau univ yg null setelah delete
void removeNullBeasiswa(adrMhs pendaftar);


//univ
void createListUniv(listUniv &U);
adrUniv createAdrUniv(string nama, bool statusNegri, char Akreditasi);
void addUniv(listUniv &U, adrUniv p);
void deleteUniv(listUniv &U, adrUniv p);

//beasiswa
void createListBeasiswa(listBeasiswa &B);
adrBeasiswa createAdrBeasiswa(string nama, string instansi, string benefit, infoSyarat syarat);
infoSyarat inputSyaratBeasiswa(float ipkMin, int semester, bool statusNegeri, char akreditasi);
void addBeasiswa(listBeasiswa &B, adrBeasiswa p);
void deleteBeasiswa(listBeasiswa &B, adrBeasiswa p);

#endif // REGIS_H_INCLUDED
