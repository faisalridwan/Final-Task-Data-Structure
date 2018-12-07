#ifndef DOKUMEN_H_INCLUDED
#define DOKUMEN_H_INCLUDED
#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <stdio.h>
#include <string>

//DOUBLE LIST CIRCULAR
//INSERT TER URUT

using namespace std;
typedef struct elmdok* adr_dok;
struct infotypedok {
    string namadok;
    int tahundok;
    string hlmdok;
    int counter;
};

struct elmdok {
    infotypedok info;
    adr_dok next;
    adr_dok prev;
};
struct listdok {
    adr_dok first;
    adr_dok last;
};

void creatlistdok( listdok &l);
adr_dok alokasidok( infotypedok x);
void dealokasidok( adr_dok &p);
void insertfirstdok(listdok &l, adr_dok P);
void insertlastdok(listdok &l, adr_dok p);
void insertterurutdok( listdok &l, adr_dok p);
adr_dok findelmdok(listdok &l, infotypedok x );
void deletefirstdok(listdok &l, adr_dok &pd);
void deletelastdok(listdok &l, adr_dok &pd);
void deletedok(listdok &l, adr_dok prec, adr_dok &pd);
void deleteelmdok( listdok &l, infotypedok p);
void tampildok (listdok l);
#endif // DOKUMEN_H_INCLUDED
