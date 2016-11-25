#ifndef PARENT_H_INCLUDED
#define PARENT_H_INCLUDED
#include <iostream>
#include "child.h"

using namespace std;

#define next(P) P->next
#define prev(P) P->prev
#define first(L) L.first
#define last(L) L.last
#define child(P) P->child


struct restaurant{
    string id;
    string nama;
    string alamat;
    string nope;
    string tglberdiri;
    string kategoriR; //
};
typedef restaurant infotype_p;
typedef struct elmlist_p *address_p;

struct elmlist_p {
    address_p prev;
    infotype_p info;
    address_p next;
    address_c child;
};

struct List_p {
    address_p first;
    address_p last;
};


/** TIDAK PERLU MODIFIKASI */
void createList(List_p &L);
void insertFirst(List_p &L, address_p P);
void insertLast(List_p &L, address_p P);
void insertAfter(address_p Prec, address_p P);
void deleteFirst(List_p &L, address_p &P);
void deleteLast(List_p &L, address_p &P);
void deleteAfter(address_p Prec, address_p &P);


/** PERLU MODIFIKASI */
address_p alokasi(infotype_p x);
void dealokasi(address_p &P);
address_p findElm(List_p L, infotype_p x);
void printInfo(List_p L);

#endif // PARENT_H_INCLUDED
