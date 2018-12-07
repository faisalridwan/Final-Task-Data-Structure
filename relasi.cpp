#include "relasi.h"

void creatlistrel(listrel &l){
    l.first=NULL;
}

void dealokasirel(adr_rel &p){
    p->p_dok=NULL;
    p->p_kat=NULL;
    delete p;
    p=NULL;
}

adr_rel findelmrel(listrel l,adr_dok p,adr_kat q){
    if (l.first!=NULL){
        adr_rel temp = l.first;
        while((temp->&&((temp->p_dok!=p)||(temp->p_kat!=q))){
            temp=temp->next;
        }
        if((temp->p_dok==p)and(temp->p_kat==q)){
            return temp;
        }
        else{
            return NULL;
        }
    }
    else{
        return NULL;
    }
}

adr_rel alokasirel(adr_dok p,adr_kat q){
    adr_rel r=new elmrel;
    r->next=NULL;
    r->p_kat=q;
    r->p_dok=p;
    return r;
}

void insertfirstrel(listrel &l, adr_dok p, adr_kat q){
    adr_rel al= alokasirel(p,q);
    if ( l.first == NULL){
        l.first = al;
        p->info.counter=p->info.counter+1;
        q->info.counter= q->info.counter+1;
    }
    else {
        al->next = l.first;
        l.first = al;
        p->info.counter=p->info.counter+1;
        q->info.counter= q->info.counter+1;
    }
}

void deleterelasi(listrel &l, adr_rel &p){
    if (p != NULL){
        if (l.first==p){
            l.first= p->next;
            p->next=NULL;
            dealokasirel(p);
        }else{
            adr_rel o=l.first;
            while ((o!=NULL)&&(o->next != p)){
                o=o->next;
            }
            o->next=NULL;
            dealokasirel(p);
        }
    }else{
        cout << "Relasi Tidak Ditemukan";
    }
}

void deleterelasibydok(listrel &l, adr_dok p){
    adr_rel r;
    adr_rel q=l.first;
    r=q;
    if (l.first !=NULL){
        while ((r!=NULL)){
            q=r;
            r=r->next;
            if (q->p_dok==p)
                deleterelasi(l,q);
        }
    }
}

void deleterelasibykat(listrel &l, adr_kat p){
    adr_rel r;
    adr_rel q=l.first;
    r=q;
    if (l.first!=NULL){
        while (r!=NULL){
            q=r;
            r=r->next;
            if (q->p_kat==p)
                deleterelasi(l,q);
        }
    }
}

adr_kat findDokKat(listkat l, string x)
{
    if (l.first!=NULL){
        adr_kat temp = l.first;
        while((temp!=NULL)&&(temp->info.namakat!=x)){
            temp=temp->next;
        }
            return temp;
    }
}

adr_dok findKatDok(listdok ld, string x){
    if ( ld.first != NULL){
        adr_dok temp rst;
        while ((temp !=NULL)&&(temp->info.namadok != x)){
            temp = temp->next;
        }
            return temp;
    }
}

adr_rel findKattt(adr_rel q, adr_kat p){
    if(q->p_kat==p){
        return q;
    }
    else{
        return NULL;
    }
}

adr_rel findDokkk(adr_rel q, adr_dok p){
    if (q -> p_dok == p){
        return q;
    }
    else{
        return NULL;
    }
}

void printDokKat ( listrel l, listkat lk, string x){
    if ( l.first == NULL ){
        cout<<" Data Dokumen Belum Tersedia / Belum Di-Relasikan ! "<<endl;
    }else{
        adr_kat p;
        p = findDokKat(lk, x);
        if ( p == NULL){
            cout<<" Dokumen Tidak Ada ";
        }else{
            adr_rel q;
            adst;
            adr_dok d;
            int i=1;
            do{
                q=findKattt(r,p);
                if (q!=NULL){
                    d=q->p_dok;
                    cout<<" "<<i<<". "<<d->info.namadok<<endl;
                    i++;
                }
                r=r->next;
            }while(r!=NULL);
        }
    }
}

void printKatDok (listrel l, listdok ld, string x){
    if (l.first == NULL){
        cout<<" Data Kategori Belum Tersedia / Belum Di-Relasikan  !"<<endl;
    }else{
        adr_dok p;
        p = findKatDok(ld,x);
        if ( p == NULL){
            cout<<" Kategori Tidak Ada";
        }else{
            adr_rel q;
            adirst;
            adr_kat k;
            int i=1;
            do{
                q=findDokkk(r,p);
                if (q!=NULL){
                    k=q->p_kat;
                    cout<<" "<<i<<". "<<k->info.namakat<<endl;
                    i++;
                }
                r = r->next;
            }while(r != NULL);
        }
    }
}
