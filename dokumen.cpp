#include "dokumen.h"

void creatlistdok(listdok &l)
{
    l.first =NULL;
    l.last = NULL;
}

adr_dok alokasidok( infotypedok x)
{
    adr_dok p=new elmdok;
    p->info=x;
    p->next=NULL;
    p->prev=NULL;
    return p;
}

void dealokasidok( adr_dok &p)
{
    p->next=NULL;
    p->prev=NULL;
    delete p;
    p=NULL;
}

void insertfirstdok(listdok &l, adr_dok p)
{
    if ((l.first==NULL)&&(l.last==NULL)){
        l.first=p;
        l.last=p;
        p->next=l.first;
        p->prev=l.last;
    }
    else{
        p->next=l.first;
        l.first->prev=p;
        l.first=p;
        l.last->next=l.first;
        l.first->prev=l.last;
    }
}
void insertlastdok(listdok &l, adr_dok p)
{
    if((l.first==NULL)&&(l.last==NULL)){
        l.first=p;
        l.last=p;
        p->next=l.first;
        p->prev=l.last;
    }
    else{
        l.last->next=p;
        p->prev=lt;
        l.last=p;
        l.first->prev=l.last;
        l.last->next=l.first;
    }
}
void insertterurutdok( listdok &l, adr_dok p)
{
    if ((l.first==NULL)&&(l.last==NULL)){
        l.first= p;
        l.last =p;
        p->next = l.first;
        p->prev = l.last;
    }
    else if(l.first==l.last){
            if ( p->info.tahundok < l.first->info.tahundok){
                insertfirstdok(l,p);
            }
            else{
                insertlastdok(l,p);
            }
    }
    else{
        adr_dok o=l.first;
        bool cek=true;
        while ( cek && o->next != l.first){
            if (p->info.tahundok <= o->info.tahundok){
                cek = false;
            }
            else{
                o=o->next;
            }
        }
        if ((cek = true) && (p->info.tahundok >= o->info.tahundok)){
            insertlastdok(l,p);
        }
        else{
            p- = o->prev;
            p->next= o;
            p->prev->next= p;
            o->prev=p;
        }
        if ( cek=false){
          p->prev = o->prev;
          p->next= o;
          p->prev->next= p;
          o->prev=p;
        }
    }
}
adr_dok findelmdok(listdok &l, infotypedok x)
{
    if ((l.first!=NULL)){
        adr_dok temp = l.first;
        while((temp->next!=l.first)&&(temp->info.namadok!=x.namadok)){
            temp=temp->next;
        }
        if(temp->info.namadok==x.namadok){
            return temp;
        }
        else{
            return NULL;
        }
    }
}

void deletefirstdok(listdok &l, adr_dok &pd)
{
    if((l.first==NULL)&&(l.last==NULL)) {
        cout<<" List Masih Kosong"<<endl;
    }
    else if(((l.first->next)==l.first)&&(l.last->prev==l.last)){
        pd=l.first;
        l.first=NULL;
        l.last=NULL;
    }
    else{
        pd=l.first;
        l.first=pd->next;
        lt->prev=l.last;
        l.last->next=l.first;
    }
}
void deletelastdok(listdok &l, adr_dok &pd)
{
    if((l.first==NULL)&&(l.last==NULL)){
        deletefirstdok(l,pd);
    }
    else if((l.first->next==l.first) &&(l.last->prev==l.last)){
        deletefirstdok(l,pd);
    }
    else{
        pd=l.last;
        l.last=pd->prev;
        l.last->next=l.first;
        l.first->prev=l.last;
    }
}
void deleteafterdok(listdok &l, adr_dok prec, adr_dok &pd)
{
    if((l.first==NULL)&&(l.last==NULL)){
        deletefirstdok(l,pd);
    }
    else if((l.first->next==l.first)&&(l.last->prev==l.last)){
        deletefirstdok(l,pd);
    }
    else{
        if(prec->next==l.first){
            deletefirstdok(l,pd);
        }
        else if(prec->next->next==l.first){
            deletelastdok(l,pd);
        }
        else{
            pd=prec->next;
            prec->next=pd->next;
            pd->next->prev=prec;
        }
    }
}

void deleteelmdok(listdok &l, infotypedok x)
{
    adr_dok p = findelmdok(l,x);
    if ( p != NULL){
        if ((p == l.first)&&(p==l.last)){
            deletefirstdok(l,p);
            dealokasidok(p);
        }
        else if(p == l.first){
            deletefirstdok(l,p);
            dealokasidok(p);
        }
        else if ( p== l.last){
            deletelastdok(l,p);
            dealokasidok(p);
        }
        else{
            adr_dok q= p->prev;
            deleteafterdok(l,q,p);
            dealokasidok(p);
        }
    }
    else {
        cout << " Data Tidak Tersedia";
    }
}

void tampildok(listdok l)
{
    cout<<" |  List Dokumen |\n";
    cout<<" =================\n";
    if(l.first==NULL){
        cout<<" Belum Ada Data Dokumen \n";
    }
    else{
        adr_dok p = l.first;
        int i=1;
        do{
            cout<<" " <<i<<". "<<p->info.namadok<<endl;
            p=p->next;
            ++i;
        }while(p->next!=l.first);
        if (p!=l.first)
            cout<<" " <<i<<". "<<p->info.namadok<<endl;
    }
}
