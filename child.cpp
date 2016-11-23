#include "child.h"

void createList(List_c &L) {
    first(L) = NULL;
}

address_c alokasi(infotype_c x) {
    address_c P = new elmlist_c;
    info(P) = x;
    next(P) = NULL;
    return P;
}

void insertFirst(List_c &L, address_c P) {
    if(first(L) == NULL) {
        first(L) = P;
    } else {
        next(P) = first(L);
        first(L) = P;
    }
}

void printInfo(List_c L) {
    address_c P = first(L);
    while(P !=NULL) {
        cout<<"->"<<info(P)<<endl;
        P = next(P);
    }
}

address_c findElm(List_c L, infotype_c x) {
    address_c P = first(L);
    while(P != NULL) {
        if(info(P)==x) {
            return P;
        }
        P = next(P);
    }
    return NULL;
}

void insertAfter(address_c Prec, address_c P, address_c prec) {
    prev(next(Prec)) = P;
    next(P) = next(Prec);
    prev(P) = Prec;
    next(Prec) = P;
}
