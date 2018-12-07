#include "relasi.h"

void garis(){
    cout<<" ==================================================="<<endl;
}

void tambahdokumen(listdok &ld)
{
    infotypedok idok;
    adr_dok p;
    cout<<"   [HARAP PERHATIKAN KAPITALISASI PENULISAN !!!]\n";
    garis();
    cout<<" Masukkan Nama Dokumen            : ";
    cin>>idok.namadok;
    cout<<" Masukkan Jumlah Halaman Dokumen  : ";
    cin>>idok.hlmdok;
    cout<<" Masukkan Tahun Pembuatan Dokumen : ";
    cin>>idok.tahundok;
    idok.counter=0;
    if (findelmdok(ld,idok)==NULL){
        p = alokasidok(idok);
        insertterurutdok(ld,p);
        garis();
        cout<<" Menambahkan Dokumen : -"<<idok.namadok<<"- Telah Berhasil\n"<<endl;
    }
    else{
        garis();
        cout<<" Dokumen Sudah Ada\n"<<endl;
    }
}
void tambahkategori(listkat &lk)
{
    infotypekat ikat;
    adr_kat p;
    cout<<"   [HARAP PERHATIKAN KAPITALISASI PENULISAN !!!]\n";
    garis();
    cout<<" Masukkan Nama Kategori : ";
    cin>>ikat.namakat;
    ikat.counter=0;
    if (findelmkat(lk,ikat)==NULL){
        p = alokaat(ikat);
        insertlastkat(lk,p);
        garis();
        cout<<" Menambahkan Kategori : -"<<ikat.namakat<<"- Telah Berhasil\n"<<endl;
    }
    else{
        garis();
        cout<<" Kategori Sudah Ada\n"<<endl;
    }
}
void tambahrelasi(listrel &lr,listdok ld,listkat lk)
{

    adr_dok pd;
    infotypedok idok;
    adr_kat pk;
    infotypekat ikat;
    adr_rel pr;
    cout<<"   [-HARAP PERHATIKAN KAPITALISASI PENULISAN !!!-]\n";
    garis();
    tampildok(ld);
    if (ld.first != NULL){
        cout<<" Masukkan Nama Dokumen Yang ingin Direlasikan : ";
        cin>>idok.namadok;
        pd = findelmdok(ld,idok);
        if ( pd != NULL){
            tampilkat(lk);
    if(lk.first != NULL){
        cout<<" Masukkan Kategori Yang Ingin Direlasikan : ";
        cin>>ikat.namakat;
        pk = findelmkat(lk,ikat);
        if (pk != NULL){
            if (findelmrel(lr,pd,pk)==NULL){
                insertfirstrel(lr,pd,pk);
                garis();
                cout<<" Data Dokumen : -"<<idok.namadok<<"- & Kategori : -"<<ikat.namakat<<"- Sudah Di-Relasikan\n"<<endl;
            }
            else{
                garis();
                cout<<"\n Relasi Data Sudah Ada\n"<<endl;
            }
        }
        else{
            garis();
            cout<<"\n Kategori Tidak Ditemukan\n"<<endl;
        }
    }
    else{
        garis();
        cout << "\n Harap Masukkan Kategori Dahulu....\n";
    }
        }
        else{
            garis();
            cout<<"\n Dokumen Tidak Ditemukan\n"<<endl;
        }
    }
    else{
        garis();
        cout << "\n Harap Masukkan Dokumen Dahulu....\n";
    }
}
void hapusdokumen(listrel &lr,listdok &ld)
{
    infotypedok idok;
    adr_dok pd;
    adr_rel pr;
    cout<<"   [-HARAP PERHATIKAN KAPITALISASI PENULISAN !!!-]\n";
    garis();
    tampildok(ld);
    if ( ld.first != NULL){
        cout<<" Masukkan Nama Dokumen Yang Ingin Dihapus : ";
        cin>>idok.namadok;
        pd = findelmdok(ld,idok);
        if (pd!=NULL){
            deleterelasibydok(lr,pd);
            deleteelmdok(ld,idok);
            garis();
            cout<<"\n Penghapusan Dokumen : -"<<idok.namadok<<"- Berhasil! \n";
        }
        else{
            garis();
            cout<<" Dokumen Tidak Ditemukan\n"<<endl;
        }
    }
    else{
        garis();
        cout << "\n Harap Masukkan Data Dokumen Dahulu....\n";
    }
}
void hapuskategori(listrel &lr, listkat &lk)
{
    infotypekat ikat;
    adr_kat pk;
    adr_rel pr;
    garis();
    cout<<"   [-HARAP PERHATIKAN KAPITALISASI PENULISAN !!!-]\n";
    garis();
    tampilkat(lk);
    if (lk.first != NULL){
        cout<<" Masukkan Nama Kategori Yang Ingin Dihapus : ";
        cin>>ikat.namakat;
        pk = findelmkat(lk,ikat);
        if (pk!=NULL){
            deleterelasibykat(lr,pk);
            deleteelmkat(lk,ikat);
            cout<<" Penghapusan Kategori : -"<<ikat.namakat<<"- Berhasil! \n";
        }
        else{
            garis();
            cout<<" Kategori Tidak Ditemukan\n"<<endl;
        }
    }
    else{
        garis();
        cout << "\n Harap Masukkan Kategori Dahulu ......\n";
    }
}
void tampilalldata(listdok ld, listkat lk){
    tampildok(ld);
    tampilkat(lk);

}
void tambildokumenbykategori(listrel lr, listkat lk, string x) {
    tampilkat(lk);
    if( lk.first != NULL){
        cout<<" Masukan Nama Kategori    : ";
        cin>>x;
        cout<<"\n Memiliki Dokumen : "<<endl;
        printDokKat(lr,lk,x);
    }else{
        cout<<"\n Harap Masukkan Kategori Dahulu !!!\n";
    }
}
void tampilkategoribydokumen(listrel lr, listdok ld, string x){
    tampildok(ld);
    if(ld.first != NULL){
    cout<<" Masukan Nama Dokumen : ";
    cin>>x;
    cout<<"\n Memiliki Kategori    : "<<endl;
    printKatDok(lr,ld,x);
    }else{
        cout<<"\n Harap Masukkan Dokumen Dahulu !!!\n";
    }
}

void tampildokterbanyak(listdok ld,listrel lr,listkat lk, string y){
    cout<<"       |-DOKUMEN DENGAN KATEGORI TERBANYAK-|"<<endl;
    garis();
    if(ld.first == NULL){
        cout<<" Dokumen Belum Ada\n"<<endl;
        cout << "\n Harap Masukkan Dokumen Dahulu ......\n";
    }else{
        adr_dok p=ld.first;
        adr_dok q=p->next;
        adr_dok maks=p;
        do{
            if(p->info.counter<q->info.counter){
                maks=q;
            }
            q=q->next;
            p=p->next;
        }while(q != ld.first);
        cout<<endl<<" Nama Dokumen : -"<<maks->info.namadok<<"-"<<endl<<endl;
        y=maks->info.namadok;
        cout<<endl<<" Memiliki Kategori  :"<<endl;
        printKatDok(lr,ld,y);

    }
}

void tampildoktersedikit(listdok ld, listrel lr, listkat lk, string r){
    cout<<"       |-DOKUMEN DENGAN KATEGORI TERSEDIKIT-|"<<endl;
    garis();
    if(ld.first == NULL){
        cout<<" Dokumen Belum Ada\n"<<endl;
        cout << "\n Harap Masukkan Dokumen Dahulu ......\n";
    }else{
        adr_dok p=ld.first;
        adr_dok q=p->next;
        adr_dok minim=p;
        do{
            if(p->info.counter>q->info.counter){
                minim=q;
            }
            q=q->next;
            p=p->next;
        }while(q->next != ld.last);
        cout<<endl<<" Nama Dokumen : -"<<minim->info.namadok<<"-"<<endl<<endl;
        r=minim->info.namadok;
        cout<<endl<<" Memiliki Kategori  :"<<endl;
        printKatDok(lr,ld,r);

    }
}
