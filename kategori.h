#ifndef KATEGORI_H_INCLUDED
#define KATEGORI_H_INCLUDED
#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <stdio.h>
#include <string>

//DOUBLE LIST BIASA
//INSERT LAST

using namespace std;

typedef struct elmkat* adr_kat;

struct infotypekat {
    string namakat;
    int counter;
};

struct elmkat{
    infotypekat info;
    adr_kat next;
    adr_kat prev;
};

struct listkat {
    adr_kat first;
    adr_kat last;
};

void creatlistkat( listkat &l);
adr_kat alokasikat( infotypekat x);
void dealokasikat(adr_kat &p);
void insertlastkat( listkat &l, adr_kat p);
adr_kat findelmkat(listkat l, infotypekat x);
void deletefirstkat(listkat &l, adr_kat &pk);
void deletelastkat(listkat &l, adr_kat &pk);
void deleteafterkat(listkat &l, adr_kat prec, adr_kat &pk);
void deleteelmkat(listkat &l, infotypekat x);
void tampilkat ( listkat l);


#endif // KATEGORI_H_INCLUDED
