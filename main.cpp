#include "regis.h"

int main() {
    listMhs M;
    listUniv U;
    listBeasiswa B;

    adrMhs mhs;
    adrUniv univ;
    adrBeasiswa bea;


    cout << "================================" << endl;
    cout << "= PROGRAM PENDAFTARAN BEASISWA =" << endl;
    cout << "================================" << endl;

    //Input & Delete Data Universitas
    createListUniv(U);
    createListBeasiswa(B);
    createListMhs(M);

    addUniv(U, createAdrUniv("Telkom University", false, 'A'));
    addUniv(U, createAdrUniv("ITB", true, 'A'));
    addUniv(U, createAdrUniv("BINUS", false, 'A'));
    addUniv(U, createAdrUniv("UNPAD", true, 'A'));
    addUniv(U, createAdrUniv("Universitas Kristen Maranatha", false, 'B'));

    showUniversitas(U);
    cout << "Tekan ENTER untuk melanjutkan" << endl;
    cin.ignore();
    cout << endl;

    deleteUniv(U, M, "BINUS");
    cout << "== Menghapus Universitas BINUS sukses =="<< endl;
    cout << "Tekan ENTER untuk melanjutkan" << endl;
    cin.ignore();

    showUniversitas(U);
    cout << "Tekan ENTER untuk melanjutkan";
    cin.ignore();
    cout << endl;

    //Input & Delete Data Beasiswa


    addBeasiswa(B, createAdrBeasiswa("Beasiswa Ikatan Dinas", "Telkom Indonesia", "Beasiswa Full sampai Lulus", inputSyaratBeasiswa(3.00, 5, false, 'B')));
    addBeasiswa(B, createAdrBeasiswa("Beasiswa Pendidikan Indonesia", "KEMENDIKBUD-RISTEK", "Beasiswa Full sampai Lulus + tunjagan bulanan", inputSyaratBeasiswa(3.00, 5, false, 'B')));
    addBeasiswa(B, createAdrBeasiswa("Beasiswa Reguler LPDP", "LPDP & KEMENKEU", "Tunjangan Bulanan + Beasiswa Full", inputSyaratBeasiswa(3.00, 5, true, 'B')));
    addBeasiswa(B, createAdrBeasiswa("Global Korean Scholarship", "Ministry of Foreign and Education Korea", "Tunjagan + Beasiswa Full", inputSyaratBeasiswa(3.00, 5, false, 'B')));

    showBeasiswa(B);
    cout << "Tekan ENTER untuk melanjutkan";
    cin.ignore();
    cout << endl;

    deleteBeasiswa(B, M, "Global Korean Scholarship");
    cout << "== Menghapus beasiswa Global Korean Scholarship sukses =="<< endl;
    cout << "Tekan ENTER untuk melanjutkan" << endl;
    cin.ignore();

    showBeasiswa(B);
    cout << "Tekan ENTER untuk melanjutkan";
    cin.ignore();
    cout << endl;

    //Input & Delete Data Mahasiswa
    mhs = createAdrMhs(inputDataMhs("Budi", "1320656", 3.45, 5));
    addMhs(M, mhs);
    masukUniv(mhs, searchUniversitas(U, "Universitas Kristen Maranatha"));

    mhs = createAdrMhs(inputDataMhs("Asep", "1320666", 3.23, 5));
    addMhs(M, mhs);
    masukUniv(mhs, searchUniversitas(U, "ITB"));

    mhs = createAdrMhs(inputDataMhs("Jajang", "1320548", 3.75, 6));
    addMhs(M, mhs);
    masukUniv(mhs, searchUniversitas(U, "Universitas Kristen Maranatha"));

    mhs = createAdrMhs(inputDataMhs("Naka", "2135610", 3.50, 4));
    addMhs(M, mhs);
    masukUniv(mhs, searchUniversitas(U, "Telkom University"));

    mhs = createAdrMhs(inputDataMhs("Abdi", "1653204", 3.80, 5));
    addMhs(M, mhs);
    masukUniv(mhs, searchUniversitas(U, "UNPAD"));

    mhs = createAdrMhs(inputDataMhs("Urang", "1356203", 3.44, 5));
    addMhs(M, mhs);
    masukUniv(mhs, searchUniversitas(U, "ITB"));

    mhs = createAdrMhs(inputDataMhs("Simkuring", "1526470", 3.80, 4));
    addMhs(M, mhs);
    masukUniv(mhs, searchUniversitas(U, "Telkom University"));

    showMahasiswa(M);

    deleteMhs(M, "1526470");
    cout << "== Menghapus mahasiswa dengan NIM 1526470 sukses ==" << endl;
    cout << "Tekan ENTER untuk melanjutkan" << endl;
    cin.ignore();
    deleteMhs(M, "1356203");
    cout << "== Menghapus mahasiswa dengan NIM 1356203 sukses =="<< endl;
    cout << "Tekan ENTER untuk melanjutkan" << endl;
    cin.ignore();

    showMahasiswa(M);
    cout << "Tekan ENTER untuk melanjutkan";
    cin.ignore();
    cout << endl;

    //Pindah Universitas
    pindahUniv(searchMahasiswa(M, "1320666"), searchUniversitas(U, "Telkom University"));
    cout << "== Pindah Universitas dengan NIM 1320666 sukses! ==" << endl;
    cout << "Tekan ENTER untuk melanjutkan" << endl;
    cin.ignore();
    showMahasiswa(M);

    //Pendaftaran Beasiswa
    cout << "================================" << endl;
    cout << "= PENDAFTARAN BEASISWA DIBUKA  =" << endl;
    cout << "================================" << endl;

    mendaftarBeasiswa(searchMahasiswa(M, "1320656"), searchBeasiswa(B, "Beasiswa Ikatan Dinas"));
    mendaftarBeasiswa(searchMahasiswa(M, "1320666"), searchBeasiswa(B, "Beasiswa Reguler LPDP"));
    mendaftarBeasiswa(searchMahasiswa(M, "1320666"), searchBeasiswa(B, "Beasiswa Pendidikan Indonesia"));
    mendaftarBeasiswa(searchMahasiswa(M, "1320548"), searchBeasiswa(B, "Beasiswa Reguler LPDP"));
    mendaftarBeasiswa(searchMahasiswa(M, "2135610"), searchBeasiswa(B, "Beasiswa Ikatan Dinas"));
    mendaftarBeasiswa(searchMahasiswa(M, "2135610"), searchBeasiswa(B, "Beasiswa Pendidikan Indonesia"));
    mendaftarBeasiswa(searchMahasiswa(M, "1653204"), searchBeasiswa(B, "Beasiswa Ikatan Dinas"));
    cout << "== Pendaftaran Beasiswa Sukses! ==" << endl;
    cout << "Tekan ENTER untuk melanjutkan" << endl;
    cin.ignore();
    showMahasiswa(M);

    //Mahasiswa dengan NIM dibawah tidak jadi ikut beasiswa
    keluarBeasiswa(searchMahasiswa(M, "1320666"), searchBeasiswa(B, "Beasiswa Reguler LPDP"));
    cout << "== Mahasiswa Dengan NIM 1320666 Batal mendaftar Beasiswa Reguler LPDP! ==" << endl;
    cout << "Tekan ENTER untuk melanjutkan" << endl;
    cin.ignore();
    showMahasiswa(M);

    cout << "================================" << endl;
    cout << "= PENDAFTARAN BEASISWA DITUTUP =" << endl;
    cout << "================================" << endl <<endl;


    //Cek apakah sesuai syarat atau tidak nya
    terimaBeasiswa(searchMahasiswa(M, "1320656"));
    terimaBeasiswa(searchMahasiswa(M, "1320666"));
    terimaBeasiswa(searchMahasiswa(M, "1320548"));
    terimaBeasiswa(searchMahasiswa(M, "2135610"));
    terimaBeasiswa(searchMahasiswa(M, "1653204"));
    cout << "Tekan ENTER untuk melanjutkan" << endl;
    cin.ignore();
    cout << endl;
    cout << "================================" << endl;
    cout << "= SELEKSI PERSYARATAN BEASISWA =" << endl;
    cout << "================================" << endl <<endl;

    showMahasiswa(M);


    cout << "================================" << endl;
    cout << "=   PROGRAM BEASISWA SELESAI   =" << endl;
    cout << "================================" << endl;

    return 0;
}
