#ifndef REGIS_H_INCLUDED
#define REGIS_H_INCLUDED

#include <iostream>

#define first(L) ((L).first)
#define info(P) (P)->info
#define next(P) (P)->next

#define asalUniv(P) (P)->asalUniv
#define terdaftarBeasiswa(P) (P)->terdaftarBeasiswa
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

struct elmUniv {
    univ info;
    adrUniv next;
};

struct elmBeasiswa {
    beasiswa info;
    adrBeasiswa next;
};

struct childBeasiswa{
    //diperlukan supaya mahasiswa bisa daftar lebih dari 1 beasiswa
    adrBeasiswa connectBeasiswa; //rename jika ada yg lebih clear
    adrChildBeasiswa next;
}; //Gw msh bingung disini (bingung buat function/prosedurnya) biar lbh jelasnya sok lihat bagian bwh, mhn bantuannya -Gibran

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
adrMhs createAdrMhs(infoMhs infoM, adrUniv asalUniv);

//prosedur untuk child dari elmMahasiswa
void mendaftarBeasiswa(adrMhs pendaftar, adrBeasiswa inBeasiswa); //inserlastChildBeasiwa
void keluarBeasiswa(adrMhs pendaftar, adrBeasiswa inBeasiswa); //deleteChildBeasiwa
void terimaBeasiswa(adrMhs pendaftar); //cek mahasiswa memenuhi syarat atau tidak. Jika tidak, remove.

void pindahUniv(adrMhs pendaftar, adrUniv asalUniv); //kalau kira2 tidak diperlukan remove aja
void masukUniv(adrMhs pendaftar, adrUniv asalUniv); //
void keluarUniv(adrMhs pendaftar);

void removeNullUniv(adrMhs pendaftar); //remove beasiswa atau univ yg null setelah delete
void removeNullBeasiswa(adrMhs pendaftar);
//end


void addUniv(listUniv &U, adrUniv p);
void addBeasiswa(listBeasiswa &B, adrBeasiswa p);
void addMhs(listMhs &M, adrMhs p);

void deleteUniv(listUniv &U, adrUniv p);
void deleteBeasiswa(listBeasiswa &B, adrBeasiswa p);
void deleteMhs(listMhs &M, adrMhs p);

#endif // REGIS_H_INCLUDED
