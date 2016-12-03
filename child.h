#ifndef CHILD_H_INCLUDED
#define CHILD_H_INCLUDED
#include <iostream>

using namespace std;

#define first(L) L.first
#define next(P) P->next
#define info(P) P->info

struct menu{
    string id;
    string namamenu;
    string tipe; // food, drink etc
    int harga;
    string kategoriM; // dessert, main, course, appetizer etc
    string rateM; // best seller etc
};

typedef menu infotype_c;
typedef struct elmlist_c *address_c;

struct elmlist_c{
    infotype_c info;
    address_c next;

};

struct List_c{
    address_c first;

};

/** TIDAK PERLU MODIFIKASI */
void createList_c(List_c &L);
void insertFirst_c(List_c &L, address_c P);
void insertAfter_c(List_c &L, address_c Prec, address_c P);
void insertLast_c(List_c &L, address_c P);
void deleteFirst_c(List_c &L, address_c &P);
void deleteLast_c(List_c &L, address_c &P);
void deleteAfter_c(List_c &L,  address_c &P, address_c Prec);
void insertAscending_c(List_c &L,address_c C);
void sortingchild(List_c &L);


/** PERLU MODIFIKASI */
address_c alokasi_c(infotype_c x);
void dealokasi_c(address_c &P);
address_c findElm_c(List_c L, infotype_c x);
void printInfo_c(List_c L);
//void jumlahmenu(List_c L);
void jumlahmenu(List_c L);
void RataHarga(List_c L);
void MaxHarga(List_c L);
void MinHarga(List_c L);
#endif // CHILD_H_INCLUDED
