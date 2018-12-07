#include "kategori.h"

void creatlistkat( listkat &l)
{
    l.first =NULL;
    l.last=NULL;
}
adr_kat alokasikat( infotypekat x)
{
    adr_kat p=new elmkat;
    p->next=NULL;
    p->prev=NULL;
    p->info=x;
    return p;
}
void dealokasikat(adr_kat &p)
{
    p->next=NULL;
    p->prev=NULL;
    delete p;
    p=NULL;
}
void insertlastkat( listkat &l, adr_kat p)
{
    if(( l.first != NULL )&&(l.last != NULL)){
        p->prev = l.last;
        l.last->next = p;
        l.last = p;
    }
    else{
        l.last =p;
        l.first=p;
    }

}
adr_kat findelmkat(listkat l, infotypekat x)
{
    if ((l.first!=NULL)){
        adr_kat temp = l.first;
        while((temp!=NULL)&&(temp->info.namakat!=x.namakat)){
            temp=temp->next;
        }
            return temp;
    }
}
void deletefirstkat(listkat &l, adr_kat &pk)
{
    if ((l.first==NULL)&&(l.last==NULL))  {
        pk = NULL;
        cout<<" List Masih Kosong"<<endl;
    }
    else if (l.first->next == NULL){
            pk = l.first;
            l.first = NULL;
            l.last = NULL;
    }
    else{
        pk = l.first;
        l.first = pk->next ;
        pk->prev = NULL;
        l.first->prev = NULL;
        pk->next = NULL;
    }
}

void deletelastkat(listkat &l, adr_kat &pk)
{
     if ((l.first==NULL)&&(l.last==NULL)){
        deletefirstkat(l,pk);
    }
    else if (l.first->next == NULL){
            deletefirstkat(l,pk);
    }
    else{
        pk = l.last;
        l.last = pk->prev;
        l.last->next=NULL;
    }
}

void deleteat(listkat &l, adr_kat prec, adr_kat &pk)
{
    if((l.first==NULL)&&(l.last==NULL)){
        deletefirstkat(l,pk);
    }
    else if(l.first == l.last){
        delat(l,pk);
    }
    else{
        if (l.last ==pk){
            deletelastkat(l,pk);
        }
        else if (l.first==pk){
                deletefirstkat(l,pk);
        }
        else{
            pk=prec->next;
            prec->next=pk->next;
            pk->next->prev=prec;
        }
    }
}

void deleteelmkat(listkat &l, infotypekat x)
{
    adr_kat p =findelmkat(l,x);
    if ( p != NULL){
        if ((p == l.first)&&(p==l.last)){
            deletefirstkat(l,p);
            dealokasikat(p);
        }
        else if (p == l.first){
            deletefirstkat(l,p);
            dealokasikat(p);
        }
        else if ( p== l.last){
            deletelastkat(l,p);
            dealokasikat(p);
        }
        else{
            adr_kat q= p->prev;
            deleteafterkat(l,q,p);
            dealokasikat(p);
        }
    }
    else {
        cout << " Data Dokumen Tidak Tersedia";
    }
}

void tampilkat(listkat l)
{

    cout<<" | List Kategori |\n";
    cout<<" =================\n";
    if(l.first==NULL){
        cout<<" Belum Ada Data Kategori \n";
    }
    else{
        adr_kat p = l.first;
        int i=1;
        do{
            cout<<" " <<i<<". "<<p->info.namakat<<endl;
            //cout<<" " <<i<<". "<<p->info.counter<<endl;
            p=p->next;
            ++i;
        }while(p!=NULL);
    }
}
