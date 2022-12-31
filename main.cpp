#include "regis.h"

int main()
{
    listMhs M;
    listUniv U;
    listBeasiswa B;

    adrMhs mhs;
    adrUniv univ;
    adrBeasiswa bea;

    //Input & Delete Data Mahasiswa
    createListMhs(M);
    addMhs(M, createAdrMhs(inputDataMhs("Budi", "1320656", 3.45, 4)));
    addMhs(M, createAdrMhs(inputDataMhs("Asep", "1320666", 3.23, 5)));
    addMhs(M, createAdrMhs(inputDataMhs("Jajang", "1320548", 3.75, 4)));
    addMhs(M, createAdrMhs(inputDataMhs("Naka", "2135610", 3.50, 4)));
    addMhs(M, createAdrMhs(inputDataMhs("Abdi", "1653204", 3.80, 5)));
    addMhs(M, createAdrMhs(inputDataMhs("Urang", "1356203", 3.44, 5)));
    addMhs(M, createAdrMhs(inputDataMhs("Simkuring", "1526470", 3.80, 4)));

    showMahasiswa(M);

    deleteMhs(M, mhs);
    deleteMhs(M, mhs);

    showMahasiswa(M);

    //Input & Delete Data Universitas
    createListUniv(U);
    addUniv(U, createAdrUniv("Telkom University", false, 'A'));
    addUniv(U, createAdrUniv("ITB", true, 'A'));
    addUniv(U, createAdrUniv("BINUS", false, 'A'));
    addUniv(U, createAdrUniv("UNPAD", true, 'A'));
    addUniv(U, createAdrUniv("Universitas Kristen Maranatha", false, 'B'));

    showUniversitas(U);

    deleteUniv(U, univ);

    showUniversitas(U);

    //Input & Delete Data Beasiswa
    createListBeasiswa(B);
    addBeasiswa(B, createAdrBeasiswa("Beasiswa Pintar", "Telkom Indonesia", "Beasiswa Full sampai Lulus", inputSyaratBeasiswa(3.50, 5, false, 'A')));
    addBeasiswa(B, createAdrBeasiswa("Beasiswa Indonesia Cerdas", "KEMENDIKBUD-RISTEK", "Beasiswa Full sampai Lulus + tunjagan bulanan", inputSyaratBeasiswa(3.00, 5, false, 'A')));
    addBeasiswa(B, createAdrBeasiswa("Indonesia Student Scholarship", "LPDP", "Tunjangan Bulanan + Beasiswa Full", inputSyaratBeasiswa(3.45, 4, true, 'A')));

    showBeasiswa(B);

    deleteBeasiswa(B, bea);

    showBeasiswa(B);

    //Pendaftaran Beasiswa
    mendaftarBeasiswa(searchMahasiswa(mhs, "1320656"));

    return 0;
}
