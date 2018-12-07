#ifndef FUNGSIO_H_INCLUDED
#define FUNGSIO_H_INCLUDED
#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <stdio.h>
#include <string>
#include "relasi.h"

using namespace std;
void tambahdokumen(listdok &ld);
void tambahkategori(listkat &lk);
void hapusdokumen(listrel &lr,listdok &ld);
void hapuskategori(listrel &lr, listkat &lk);
void tampilalldata(listdok ld, listkat lk);
void tambildokumenbykategori(listrel lr, listkat lk, string x);
void tampilkategoribydokumen(listrel lr, listdok ld, string x);
void tampildokterbanyak(listdok ld,listrel lr,listkat lk, string y);
void tampildoktersedikit(listdok ld, listrel lr, listkat lk, string y);
#endif // FUNGSIO_H_INCLUDED
