#include "parent.h"

void createList(List_p &L) {
    first(L) = NULL;
    last(L) = NULL;
}

address_p alokasi(infotype_p x) {
    address_p P = new elmlist_p;
    info(P) = x;
    next(P) = NULL;
    prev(P) = NULL;
    child(P) = NULL;
    return P;
}
void dealokasi(address_p &P){
    delete P;
}

void insertFirst(List_p &L, address_p P) {
    if(first(L) == NULL) {
        last(L) = P;
        first(L) = P;
    } else {
        next(P) = first(L);
        prev(first(L)) = P;
        first(L) = P;
    }
}

void insertAfter(List_p &L, address_p P, address_p prec)
{
   if(first(L) != NULL)
   {
       if(prec != last(L)){
           next(P)=next(prec);
           prev(P)=prec;
           next(prec)=P;
           prev(next(P))=P;
       }else{
            insertLast(L,P);
       }
   }
}

void insertLast(List_p &L, address_p P) {
    if(last(L) == NULL) {
        last(L) = P;
        //first(L) = P;
    } else {
        prev(P) = last(L);
        next(last(L)) = P;
        last(L) = P;
    }
}


//void insertAfter(address_p &Prec, address_p P) {
//    prev(next(Prec)) = P;
//    next(P) = next(Prec);
//    prev(P) = Prec;
//    next(Prec) = P;
//}

void printInfo(List_p L) {
    address_p P = first(L);
    while(P !=NULL) {
        cout<<info(P).id<<endl;
        cout<<info(P).nama<<endl;
//        cout<<info(P).alamat<<endl;
//        cout<<info(P).nope<<endl;
//        cout<<info(P).tglberdiri<<endl;
//        cout<<info(P).kategoriR<<endl;
//        cout<<info(P)<<", parent : ";
//        if(child(P)!=NULL)
//            cout<<info(child(P))<<endl;
//        else
//            cout<<"NULL"<<endl;
       P = next(P);
    }
}

void deleteFirst(List_p &L, address_p &P){
    if (first(L) != NULL){
        P = first(L);
        if (next(P) = NULL){
            first(L) = NULL;
        }
        else if(next(P) != NULL){
            first(L) = next(P);
            prev(next(P)) = NULL;
            next(P) = NULL;
            //dealokasi(P);
        }
    }
}
void deleteLast(List_p &L, address_p &P){
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
//address_p findElm(List_p L, infotype_p x) {
//    address_p P = first(L);
//    while(P != NULL) {
//        if(info(P) == x) {
//            return P;
//        }
//        P = next(P);
//    }
//    return NULL;
//}
