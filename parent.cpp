#include "parent.h"

void createList(List_p &L)
{
    /**
    * NIM: 1301154552
    * FS : first(L) dan last(L) diset Nil
    */
    first(L) = NULL;
    last(L) = NULL;
}

address_p alokasi(infotype_p x)
{
    /**
    * NIM: 1301154552
    * FS : mengembalikan elemen list baru dengan info = x, next elemen = Nil
    */
    address_p P = new elmlist_p;
    info(P) = x;
    next(P) = NULL;
    prev(P) = NULL;
    createList_c(child(P));
    return P;
}

void dealokasi(address_p &P)
{
    /**
    * NIM: 1301154552
    * FS : menghapus elemen yang ditunjuk oleh P (delete)
    */
    delete P;
}

void insertFirst(List_p &L, address_p P)
{
    /**
    * NIM: 1301154552
    * IS : List L mungkin kosong
    * FS : elemen yang ditunjuk P menjadi elemen pertama pada List L
    */
    if(first(L) == NULL)
    {
        last(L) = P;
        first(L) = P;
    }
    else
    {
        next(P) = first(L);
        prev(first(L)) = P;
        first(L) = P;
    }
}

void insertAfter(List_p &L, address_p P, address_p prec)
{
    /**
    * NIM: 1301154552
    * IS : Prec dan P tidak NULL
    * FS : elemen yang ditunjuk P menjadi elemen di belakang elemen yang
    *      ditunjuk pointer Prec
    */
    if(first(L) != NULL)
    {
        if(prec != last(L))
        {
            next(P)=next(prec);
            prev(P)=prec;
            next(prec)=P;
            prev(next(P))=P;
        }
        else
        {
            insertLast(L,P);
        }
    }
}

void insertLast(List_p &L, address_p P)
{
    /**
    * NIM: 1301154552
    * IS : List L mungkin kosong
    * FS : elemen yang ditunjuk P menjadi elemen terakhir pada List L
    */
    if(last(L) == NULL)
    {
        last(L) = P;
        first(L) = P;
    }
    else
    {
        prev(P) = last(L);
        next(last(L)) = P;
        last(L) = P;
    }
}

void printInfo(List_p L)
{
    /**
    * NIM: 1301154552
    * FS : menampilkan info seluruh elemen list L
    */
    address_p P = first(L);
    while(P !=NULL)
    {
        cout<<"-----------------------------------"<<endl;
        cout<<"ID              : "<<info(P).id<<endl;
        cout<<"Nama Restaurant : "<<info(P).nama<<endl;
        cout<<"Alamat          : "<<info(P).alamat<<endl;
        cout<<"Telp.           : "<<info(P).nope<<endl;
        cout<<"Tanggal Berdiri : "<<info(P).tglberdiri<<endl;
        cout<<"Kategori        : "<<info(P).kategoriR<<endl;
        P = next(P);
    }
}

void deleteFirst(List_p &L, address_p &P)
{
    /**
    * NIM: 1301154552
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
            prev(next(P)) = NULL;
            next(P) = NULL;
        }
    }
}

void deleteLast(List_p &L, address_p &P)
{
    /**
    * NIM: 1301154552
    * IS : List L mungkin kosong
    * FS : elemen tarakhir di dalam List L dilepas dan disimpan/ditunjuk oleh P
    */
    if(next(first(L)) == NULL)
    {
        deleteFirst(L,P);
    }
    else
    {
        address_p temp = first(L);
        while(next(next(temp)) != NULL)
        {
            temp = next(temp);
        }
        P = next(temp);
        next(temp) = NULL;
    }
}

void deleteAfter(List_p &L, address_p &P, address_p Prec)
{
    /**
    * NIM: 1301154552
    * IS : Prec tidak NULL
    * FS : elemen yang berada di belakang elemen Prec dilepas
    *      dan disimpan/ditunjuk oleh P
    */
    next(Prec) = next(P);
    prev(next(P)) = Prec;
    prev(P) = NULL;
    next(P) = NULL;
}
address_p findElm(List_p L, infotype_p x)
{
    address_p P = first(L);
    while(P != NULL)
    {
        if(info(P).id == x.id)
        {
            return P;
        }
        P = next(P);
    }
    return NULL;
}

void sortingparent(List_p &L)
{
    /**
    * NIM: 1301154552
    * IS : List L mungkin kosong
    * FS : elemen yang ditunjuk P menjadi elemen pertama pada List L
    */
    address_p P, Q, R, S;
    Q = next(first(L));
    while (Q != NULL)
    {
        P = first(L);
        while (info(P).nama < info(Q).nama && (next(P) != Q))
        {
            R = P;
            P =  next(P);
        }
        if (info(Q).nama < info(P).nama)
        {
            S= Q;
            infotype_p temp = info(Q);
            info(Q) = info(P);
            info(P) = temp;
        }
        Q = (next(Q));
    }

}

void insertAscending(List_p &L,address_p P)
{
    /**
    * NIM: 1301154552
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
        insertFirst(L,P);
    }
    else
    {
        address_p Q = first(L);
        bool ketemu = false;
        if (info(Q).id > info(P).id)
        {
            insertFirst(L,P);
        }
        else
        {
            while (next(Q) != NULL && !ketemu)
            {
                Q = next(Q);
                if (info(P).id < info(Q).id)
                {
                    insertAfter(L,P,prev(Q));
                    ketemu = true;
                }
                else if (info(P).id == info(Q).id)
                {
                    cout << "ID sudah ada" << endl;
                    ketemu = true;
                }
            }
            if (!ketemu && next(Q) == NULL)
            {
                insertLast(L,P);
            }
        }
    }

}

void printAll(List_p L)
{
    /**
    * NIM: 1301154552
    * FS : menampilkan info seluruh elemen list L, parent dan child
    */
    address_p P = first(L);
    while(P != NULL)
    {
        cout<<"=====Data Restaurant "<<info(P).id<<"====="<<endl;
        cout<<"ID Restaurant       : "<<info(P).id<<endl;
        cout<<"Nama Restaurant     : "<<info(P).nama<<endl;
        if(first(child(P))!= NULL)
        {
            cout<<"===Daftar Menu "<<info(P).id<<"==="<<endl;
            printInfo_c(child(P));
            cout<<endl;
        }
        P = next(P);
        cout<<endl;
    }
}
