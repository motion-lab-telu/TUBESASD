#include <iostream>
#include <string>
#include "child.h"
using namespace std;

void createList_c(List_c &L) {
    /**
    * NIM: 1301154566
    * FS : first(L) diset Nil
    */
    first(L) = NULL;
}

address_c alokasi_c(infotype_c x) {
    /**
    * NIM: 1301154566
    * FS : mengembalikan elemen list baru dengan info = x, next elemen = Nil
    */
    address_c P = new elmlist_c;
    info(P) = x;
    next(P) = NULL;
    return P;
}

void dealokasi_c(address_c &P)
{
    /**
    * NIM: 1301154566
    * FS : menghapus elemen yang ditunjuk oleh P (delete)
    */
    delete P;
}

void insertFirst_c(List_c &L, address_c P) {
    /**
    * NIM: 1301154566
    * IS : List L mungkin kosong
    * FS : elemen yang ditunjuk P menjadi elemen pertama pada List L
    */
    if(first(L) == NULL) {
            first(L) = P;
    } else {
        if(first(L) != NULL)
            next(P) = first(L);
            first(L) = P;
    }
}

void insertAfter_c(List_c &L, address_c P, address_c Prec)
{
    /**
    * NIM: 1301154566
    * IS : Prec dan P tidak NULL
    * FS : elemen yang ditunjuk P menjadi elemen di belakang elemen yang
    *      ditunjuk pointer Prec
    */
    next(P)=next(Prec);
    next(Prec)=P;
}

void insertLast_c(List_c &L, address_c P)
{
    /**
    * NIM: 1301154566
    * IS : List L mungkin kosong
    * FS : elemen yang ditunjuk P menjadi elemen terakhir pada List L
    */

    if (first(L) == NULL )
    {
        first(L) = P;
            }
    else
    {
        address_c Q = first(L);
        while (next(Q) != NULL)
        {
            Q=next(Q);
        }
        next(Q)=P;
    }
}

void deleteFirst_c(List_c &L, address_c &P)
{
    /**
    * NIM: 1301154566
    * IS : List L mungkin kosong
    * FS : elemen pertama di dalam List L dilepas dan disimpan/ditunjuk oleh P
    */
    if (first(L) != NULL)
    {
        P = first(L);
        if (next(P) == NULL)
        {
            first(L) = NULL;
        }
        else
        {
            first(L) = next(P);
            next(P) = NULL;
        }
    }
}

void deleteAfter_c(List_c &L, address_c &P, address_c Prec)
{
    /**
    * NIM: 1301154566
    * IS : Prec tidak NULL
    * FS : elemen yang berada di belakang elemen Prec dilepas
    *      dan disimpan/ditunjuk oleh P
    */
    P=next(Prec);
    next(Prec)=next(P);
    next(P)=NULL;
}

void deleteLast_c(List_c &L, address_c &P)
{
    /**
    * NIM: 1301154566
    * IS : List L mungkin kosong
    * FS : elemen tarakhir di dalam List L dilepas dan disimpan/ditunjuk oleh P
    */
    if (first(L) != NULL)
    {
        address_c q = first(L);
        if (next(q) == NULL)
    {
        first(L) = NULL;
    }
    else
    {
        while (next(next(q)) != NULL)
            {
                q = next(q);
            }
            P = next(q);
            next(q) = NULL;
        }
    }
    else
    {
        /**
        cout<<" "<<endl;
        **/
    }
}

void printInfo_c(List_c L) {
    /**
    * NIM: 1301154566
    * FS : menampilkan info seluruh elemen list L
    */
    address_c P;
    P = first(L);
    if (first(L)== NULL)
    {
        cout<< "List Kosong!"<<endl;
    }
    else
    {
        while (P!=NULL)
        {
            cout<<"ID Menu       : "<<info(P).id<<endl;
            cout<<"Nama Menu     : "<<info(P).namamenu<<endl;
            cout<<"Tipe Menu     : "<<info(P).tipe<<endl;
            cout<<"Harga Menu    : Rp "<<info(P).harga<<endl;
            cout<<"Kategori Menu : "<<info(P).kategoriM<<endl;
            cout<<"Rate Menu     : "<<info(P).rateM<<endl;
            P = next(P);
        }
    }
}

address_c findElm_c(List_c L, infotype_c x) {
    /**
    * NIM: 1301154566
    * IS : List L mungkin kosong
    * FS : mengembalikan elemen dengan info.ID = x.ID,
    */
    address_c P = first(L);
    while(P != NULL) {
        if(info(P).id==x.id) {
            return P;
        }
        P = next(P);
    }
    return NULL;
}

//sorting_c
/* if(nama > nama)*/

void insertAscending_c(List_c &L,address_c C)
{
    /**
    * NIM: 1301154566
    * IS : List L mungkin kosong
    * FS : - jika List L masih kosong maka lakukan insert first
    *      - Jika List L tidak kosang maka :
    *           - Jika info yang ditunjuk oleh elemen Q lebih besar dari info yang ditunjuk oleh elemen C,
                  maka lakukan insert first
                - Jika info yang ditunjuk oleh elemen Q sama dengan info yang ditunjuk oleh elemen C,
                  maka tidak dapat diinputkan
                - Jika next elemen ditunjuk oleh elemen Q = NULL,
                  maka lakukan insert last
                //kondisi insert after
    */
    if (first(L) == NULL)
    {
        insertFirst_c(L,C);
    }
    else
    {
        address_c Q = first(L);
        bool ketemu = false;
        if (info(Q).id > info(C).id)
        {
            insertFirst_c(L,C);
        }
        else
        {

            while (next(Q) != NULL && !ketemu)
            {
                if (info(C).id > info(Q).id)
                {
                    Q = next(Q);
                }
                else if (info(C).id == info(Q).id)
                {
                    cout << "ID sudah ada" << endl;
                    break;
                }
                else if (info(C).id < info(Q).id)
                {
                    ketemu = true;
                }
            }
            if (!ketemu && next(Q) == NULL)
            {
                insertLast_c(L,C);
            }
            else if (ketemu)
            {
                address_c x = first(L);
                while(next(x) != Q){
                    x = next(x);
                }
                insertAfter_c(L,C,x);
            }
        }
    }
}

void sortingchild(List_c &L){
    /**
    * NIM: 1301154566
    * IS :
    * FS :
    *
    */
    address_c P, Q, R, S;
    Q = next(first(L));
    while (Q != NULL){
        P = first(L);
        while (info(P).namamenu < info(Q).namamenu && (next(P) != Q)){
            R = P;
            P = next(P);
        }
        if (info(Q).namamenu < info(P).namamenu){
            S= Q;
            infotype_c temp = info(Q);
            info(Q) = info(P);
            info(P) = temp;
        }
        Q = (next(Q));
    }
}

void jumlahmenu(List_c L)
{
    /**
    * NIM: 1301154552
    * IS : List L mungkin kosong
    * FS : elemen yang ditunjuk P menjadi elemen pertama pada List L
    */
    int tambah=0;
    address_c Q = first(L);
    if (Q != NULL){
        while(Q != NULL){
            tambah++;
            Q = next(Q);
        }
        cout<<"Jumlah Menu        : "<<tambah<<endl;
    } else {
        cout<<"Menu Tidak Ada"<<endl;
    }
}

void RataHarga(List_c L)
{
    /**
    * NIM: 1301154552
    * IS : List L mungkin kosong
    * FS : elemen yang ditunjuk P menjadi elemen pertama pada List L
    */
    float rata = 0;
    int i = 0 , totalharga = 0;
    address_c Q = first(L);
    if (Q != NULL){
        while(Q != NULL){
            totalharga = totalharga + Q->info.harga;
            i++;
            Q = next(Q);
        }
        rata = (totalharga)/i;
        cout<<"Rata-rata Harga    : "<<rata<<endl;
    } else {
        cout<<"Menu Tidak Ada"<<endl;
    }
}

void MaxHarga(List_c L){
    /**
    * NIM: 1301154552
    * IS : List L mungkin kosong
    * FS : elemen yang ditunjuk P menjadi elemen pertama pada List L
    */
    address_c Q = first(L);
    int tmp = -1;
    if (Q != NULL){
        while(Q != NULL){
            if(info(Q).harga > tmp){
                tmp = info(Q).harga;
            }
            Q = next(Q);
        }
        cout<<"Maksimum Harga Menu: "<<tmp<<endl;
    } else {
        cout<<"Menu Tidak Ada"<<endl;
    }
}
void MinHarga(List_c L){
    /**
    * NIM: 1301154552
    * IS : List L mungkin kosong
    * FS : elemen yang ditunjuk P menjadi elemen pertama pada List L
    */
    address_c Q = first(L);
    int tmp = 1000000;
    if (Q != NULL){
        while(Q != NULL){
            if(info(Q).harga < tmp){
                tmp = info(Q).harga;
            }
            Q = next(Q);
        }
        cout<<"Maksimum Harga Menu: "<<tmp<<endl;
    } else {
        cout<<"Menu Tidak Ada"<<endl;
    }
}
