#ifndef CHILD_H_INCLUDED
#define CHILD_H_INCLUDED
#include <iostream>
using namespace std;

#define first(L) L.first
#define next(P) P->next
#define info(P) P->info

//#include "parent.h"

struct menu{
    string id;
    string namamenu;
    string tipe; // food, drink etc
    int harga;
    string kategoriM; // Main course etc
    string rateM; // BEST SELLER etc


};

typedef string infotype_c;
typedef struct elmlist_c *address_c;

struct elmlist_c{
    infotype_c info;
    address_c next;

};

struct List_c{
    address_c first;

};

/** TIDAK PERLU MODIFIKASI */
void createList(List_c &L);
void insertFirst(List_c &L, address_c P);
void insertAfter(List_c &L, address_c Prec, address_c P);
void insertLast(List_c &L, address_c P);
void deleteFirst(List_c &L, address_c &P);
void deleteLast(List_c &L, address_c &P);
void deleteAfter(List_c &L, address_c Prec, address_c &P);


/** PERLU MODIFIKASI */
address_c alokasi(infotype_c x);
void dealokasi(address_c &P);
address_c findElm(List_c L, infotype_c x);
void printInfo(List_c L);

#endif // CHILD_H_INCLUDED
