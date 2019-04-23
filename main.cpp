#include "fungsio.h"
void cotinu(){
    cout<<"\n Press <Enter> to Continue...";getch();
}
void header(){
    system("CLS");
    cout<<" ===================================================\n";
    cout<<" =            Data Dokumen&Kategorinya             =\n";
    cout<<" ===================================================\n";
}

void menuUtama(){
    string pil;
    listdok ld;
    listkat lk;
    listrel lr;
    creatlistdok(ld);
    creatlistkat(lk);
    creatlistrel(lr);
    string x;
    string y;
    string r;

    cout<<" ===================================================\n";
    cout<<" =                 Selamat datang                  =\n";
    cout<<" =                  Tubes-KOFU                     =\n";
    cout<<" =                  Data Dokumen                   =\n";
    cout<<" =                  Created by :                   =\n";
    cout<<" =             FAISAL RIDWAN SIREGAR               =\n";
    cout<<" =                    IF-41-06                     =\n";
    cout<<" ===================================================\n";
    cout<<"\n";
    cotinu();
        do{
            header();
            cout<<" 1.  Tambah Dokumen\n";
            cout<<" 2.  Tambah Kategori\n";
            cout<<" 3.  Penentuan Relasi Dokumen&Kategori\n";
            cout<<" 4.  Hapus Data Dokumen\n";
            cout<<" 5.  Hapus Data Kategori\n";
            cout<<" 6.  Menampilkan Seluruh Dokumeh dan Kategori\n";
            cout<<" 7.  Menampilkan Dokumen berdasarkan Kategori\n";
            cout<<" 8.  Menampilkan Kategori berdasarkan Dokumen\n";
            cout<<" 9.  Menampilkan Dokumen yang memiliki Kategori Terbanyak\n";
            cout<<" 10. Menampilkan Dokumen yang memiliki Kategori Tersedikit\n";
            cout<<" 0.  Exit\n";
            cout<<" Masukkan Pilihan (Angka) : ";cin>>pil;
            if (pil=="1"){
                header();
                tambahdokumen(ld);
                cotinu();
            }
            else if (pil=="2"){
                    header();
                    tambahkategori(lk);
                    cotinu();
            }
            else if (pil=="3"){
                    header();
                    tambahrelasi(lr,ld,lk);
                    cotinu();
            }
            else if (pil=="4"){
                    header();
                    hapusdokumen(lr,ld);
                    cotinu();
            }
            else if (pil=="5"){
                    header();
                    hapuskategori(lr,lk);
                    cotinu();
            }
            else if (pil=="6"){
                    header();
                    tampilalldata(ld,lk);
                    cotinu();

            }
            else if (pil=="7"){
                    header();
                    tambildokumenbykategori(lr,lk,x);
                    cotinu();
            }
            else if(pil=="8"){
                    header();
                    tampilkategoribydokumen(lr,ld,x);
                    cotinu();
            }
            else if(pil=="9"){
                    header();
                    tampildokterbanyak(ld,lr,lk,y);
                    cotinu();
            }
            else if(pil=="10"){
                    header();
                    tampildoktersedikit(ld,lr,lk,y);
                    cotinu();
            }
    }while(pil!="0");
    system("CLS");
    cout<<"\n\n\n\n\n";
    cout<<"\n                   https://www.faisalridwan.com CopyRight 2018    \n";
    cout<<"\n               ===================================================\n";
    cout<<"\n               =                  Goodbye!                       =\n";
    cout<<"\n               ===================================================\n";
    void cotinu();
}
int main(){
    menuUtama();
    return 0;
}
