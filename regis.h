#ifndef REGIS_H_INCLUDED
#define REGIS_H_INCLUDED

#include <iostream>
using namespace std;

struct mhs {
  string nama,nim;
  int nim,semester;
};

struct beasiswa {
  string nama,instansi,benefit;
  string syarat;
};

struct univ {
  string nama;
  bool statusNegeri;
  char akreditasi;
};

#endif // REGIS_H_INCLUDED
