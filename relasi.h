#ifndef RELASI_H_INCLUDED
#define RELASI_H_INCLUDED
#include "dokumen.h"
#include "kategori.h"

using namespace std;

// SINGLE LIST BIASA
// INSERT FIRST

typedef struct elmrel *adr_rel;

struct elmrel {
    adr_rel next;
    adr_dok p_dok;
    adr_kat p_kat;
};

struct listrel{
    adr_rel first;
};

void creatlistrel(listrel &l);
void dealokasirel(adr_rel &p);
adr_rel findelmrel(listrel l,adr_dok p,adr_kat q);
adr_rel alokasirel(adr_dok p,adr_kat q);
void insertfirstrel( listrel &l, adr_dok p, adr_kat q);
void deleterelasi(listrel &l, adr_rel &p);
void deleterelasibydok(listrel &l, adr_dok p);
void deleterelasibykat(listrel &l, adr_kat p);
adr_kat findDokKat(listkat l, string x);
adr_dok findKatDok(listdok ld, string x);
adr_rel findKattt(adr_rel q, adr_kat p);
adr_rel findDokkk(adr_rel q, adr_dok p);
void printDokKat ( listrel l, listkat lk, string x);
void printKatDok (listrel l, listdok ld, string x);


#endif // RELASI_H_INCLUDED
