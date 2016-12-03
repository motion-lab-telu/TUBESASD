#include <iostream>
#include "parent.h"
#include "child.h"

using namespace std;

int main()
{
    char pilihan;
    List_p Lp;
    List_c Lc;
    createList(Lp);
    createList_c(Lc);
    address_p P;
    address_c C;
    int menures,menumen;
    infotype_p restaurant;
    infotype_c menu;
    //variable untuk mencari
    address_p Search;
    address_c SearchChild;
    infotype_p searchid;
    infotype_c searchidc;
    /** Restaurant yang sudah terdaftar**/
        restaurant.id = "1";
        restaurant.nama = "Yans";
        restaurant.alamat = "Pangandaran";
        restaurant.nope = "08219047424";
        restaurant.tglberdiri = "2013";
        restaurant.kategoriR = "Seafood";
        P = alokasi(restaurant);
        insertAscending(Lp, P);

        restaurant.id = "3";
        restaurant.nama = "Mujigae";
        restaurant.alamat = "Ciwalk";
        restaurant.nope = "082219077023";
        restaurant.tglberdiri = "2010";
        restaurant.kategoriR = "Korean";
        P = alokasi(restaurant);
        insertAscending(Lp, P);

        restaurant.id = "2";
        restaurant.nama = "Bu Imas";
        restaurant.alamat = "Kebon Kalapa";
        restaurant.nope = "082329042637";
        restaurant.tglberdiri = "1997";
        restaurant.kategoriR = "Warung Nasi";
        P = alokasi(restaurant);
        insertAscending(Lp, P);
    while (pilihan != 'd')
    {
        cout<<"==================================="<<endl;
        cout << "Main Menu" <<endl;
        cout<<"a. Restaurant "<<endl;
        cout<<"b. Menu Restaurant "<<endl;
        cout<<"c. Reporting"<<endl;
        cout<<"d. Exit"<<endl;
        cout<<"==================================="<<endl;
        cout<<"Pilih : ";cin>>pilihan;
        menures = -1;
        switch (pilihan)
        {
        case 'a' :
        {
            //Menu untuk retaurant
            while (menures != 0)
            {
                cout<<"==================================="<<endl;
                cout<<"1. Insert restaurant"<<endl;
                cout<<"2. Search & View Restaurant"<<endl;
                cout<<"3. Search & Delete Restaurant"<<endl;
                cout<<"4. View All Restaurant"<<endl;
                cout<<"5. Search & Edit Restaurant"<<endl;
                cout<<"6. Sorting Restaurant Berdasarkan Nama"<<endl;
                cout<<"0. Back to Main Menu"<<endl;
                cout<<"==================================="<<endl;
                cout<<"Pilih : ";cin>>menures;
                switch (menures)
                {
                case 1 :
                {
                    cout<<"-----------------------------------"<<endl;
                    cout<<"ID              : ";
                    cin>>restaurant.id;
                    Search = findElm(Lp, restaurant);
                    if (Search == NULL){
                        cout<<"Nama Restaurant : ";
                        cin>>restaurant.nama;
                        cout<<"Alamat          : ";
                        cin>>restaurant.alamat;
                        cout<<"Telp            : ";
                        cin>>restaurant.nope;
                        cout<<"Tanggal Berdiri : ";
                        cin>>restaurant.tglberdiri;
                        cout<<"Kategori        : ";
                        cin>>restaurant.kategoriR;
                        P = alokasi (restaurant);
                        address_p Q;
                        insertAscending(Lp, P);
                    }
                    else
                        cout<<"ID sudah ada"<<endl;
                    break;
                }
                case 2 :
                    {
                    cout<<"ID Restaurant   : ";
                    cin>>searchid.id;
                    Search = findElm(Lp, searchid);
                    if (Search != NULL){
                        cout<<"-----------------------------------"<<endl;
                        cout<<"ID              : "<<info(Search).id<<endl;
                        cout<<"Nama Restaurant : "<<info(Search).nama<<endl;
                        cout<<"Alamat          : "<<info(Search).alamat<<endl;
                        cout<<"Telp.           : "<<info(Search).nope<<endl;
                        cout<<"Tanggal Berdiri : "<<info(Search).tglberdiri<<endl;
                        cout<<"Kategori        : "<<info(Search).kategoriR<<endl;
                    }else{
                        cout<<"Ups!!! ID tidak ditemukan"<<endl;
                        }
                    break;
                    }
                case 3 :
                    {
                    //sarchanddelete
                        cout<<"ID Restaurant   : ";
                        cin>>searchid.id;
                        Search = findElm(Lp, searchid);
                        if (Search != NULL){
                            if (Search == first(Lp)){
                                deleteFirst(Lp, Search);
                                cout<<"Yeay! Delete Berhasil"<<endl;
                            }
                            else if (Search == last(Lp)){
                                deleteLast(Lp, Search);
                                cout<<"Yeay! Delete Berhasil"<<endl;
                            }else{
                               deleteAfter(Lp, Search, prev(Search));
                               cout<<"Yeay! Delete Berhasil"<<endl;
                            }
                        }else{
                            cout<<"Ups!!! ID tidak ditemukan"<<endl;
                            }
                        break;
                    }
                case 4 :
                    {
                    printInfo(Lp);
                    break;
                    }
                case 5 :
                    {
                        cout<<"ID Restaurant   : ";
                        cin>>searchid.id;
                        Search = findElm(Lp, searchid);
                        if (Search != NULL){
                            cout<<"-----------------------------------"<<endl;
                            cout<<"ID              : "<<info(Search).id<<endl;
                            cout<<"Nama Restaurant : "<<info(Search).nama<<endl;
                            cout<<"Alamat          : "<<info(Search).alamat<<endl;
                            cout<<"Telp.           : "<<info(Search).nope<<endl;
                            cout<<"Tanggal Berdiri : "<<info(Search).tglberdiri<<endl;
                            cout<<"Kategori        : "<<info(Search).kategoriR<<endl;
                            cout<<"=============\ edit /=============="<<endl;
                            cout<<"ID              : ";cin>>info(Search).id;
                            cout<<"Nama Restaurant : ";cin>>info(Search).nama;
                            cout<<"Alamat          : ";cin>>info(Search).alamat;
                            cout<<"Telp.           : ";cin>>info(Search).nope;
                            cout<<"Tanggal Berdiri : ";cin>>info(Search).tglberdiri;
                            cout<<"Kategori        : ";cin>>info(Search).kategoriR;
                        }else{
                            cout<<"Ups!!! ID tidak ditemukan"<<endl;
                        }
                    break;
                    }
                case 6 :
                    {
                        sortingparent(Lp);
                        cout<<"Yeay, Sorting Berhasil!"<<endl;
                    break;
                    }
                }
            }
         break;

        }    //Menu untuk menu
        case 'b' :
        {
            menumen = -1;
            while ((menumen) != 0)
            {
                cout<<"==================================="<<endl;
                cout<<"1. Insert Menu"<<endl;
                cout<<"2. Search & View Menu"<<endl;
                cout<<"3. Search & Delete Menu"<<endl;
                cout<<"4. View All Restaurant & Menu"<<endl;
                cout<<"5. Search & Edit Menu"<<endl;
                cout<<"6. Sorting Menu Berdasarkan Nama"<<endl;
                cout<<"0. Back"<<endl;
                cout<<"==================================="<<endl;
                cout<<"Pilih : ";cin>>menumen;
                switch (menumen)
                {
                    case 1 :
                    {
                        cout<<"ID Restaurant   : ";
                        cin>>searchid.id;
                        Search = findElm(Lp, searchid);
                        if (Search != NULL){
                            Lc = child(Search);
                            cout<<"ID Menu         : ";getline(cin,menu.id);getline(cin,menu.id);
                            cout<<"Nama Menu       : ";getline(cin,menu.namamenu);
                            cout<<"Tipe Menu       : ";getline(cin,menu.tipe);
                            cout<<"Harga           : Rp ";cin>>menu.harga;
                            cout<<"Kategori        : ";getline(cin,menu.kategoriM);getline(cin,menu.kategoriM);
                            cout<<"Rate            : ";getline(cin,menu.rateM);
                            C = alokasi_c(menu);
                            if (findElm_c(child(Search),menu) == NULL){
                                insertAscending_c(child(Search), C);
                            }
                            else {
                                cout<<"Menu ini sudah ada!"<<endl;
                            }

                        }else{
                            cout<<"Ups!!! ID tidak ditemukan"<<endl;
                        }
                        break;
                    }
                    case 2 :
                    {
                        cout<<"ID Restaurant : ";
                        cin>>searchid.id;
                        address_p K;
                        K = findElm(Lp,searchid);
                        if(K != NULL){
                            cout<<"ID Menu       : ";
                            cin>>searchidc.id;
                            address_c S;
                            S = findElm_c(K->child, searchidc);
                            if (S != NULL){
                                cout<<"-----------------------------------"<<endl;
                                cout<<"ID Menu      : "<<info(S).id<<endl;
                                cout<<"Nama Menu    : "<<info(S).namamenu<<endl;
                                cout<<"Tipe Menu    : "<<info(S).tipe<<endl;
                                cout<<"Harga Menu   : "<<info(S).harga<<endl;
                                cout<<"Kategori Menu: "<<info(S).kategoriM<<endl;
                                cout<<"Rate Menu    : "<<info(S).rateM<<endl;

                            }else {
                                cout<<"Ups!!! ID Menu tidak ditemukan"<<endl;
                            }
                        }
                        else
                        {
                            cout<<"Ups!!! ID Retaurant tidak ditemukan"<<endl;
                        }

                    break;
                    }
                    case 3 :
                    {
                        cout<<"ID Restaurant : ";
                        cin>>searchid.id;
                        address_p K;
                        K = findElm(Lp,searchid);
                        if(K != NULL){
                            cout<<"ID Menu       : ";
                            cin>>searchidc.id;
                            address_c S;
                            S = findElm_c(K->child, searchidc);
                            if (S != NULL){
                                if ( S == first(K->child)){
                                    deleteFirst_c(K->child, S);
                                    cout<<"Yeay! Delete Berhasil"<<endl;
                                }else if ( next(S) == NULL){
                                    deleteLast_c(K->child, S);
                                    cout<<"Yeay! Delete Berhasil"<<endl;
                                }else{
                                    address_c R = first(K->child);
                                    while (next(R) != S){
                                        R = next(R);
                                    }
                                    deleteAfter_c(K->child, S, R);
                                    cout<<"Yeay! Delete Berhasil"<<endl;
                                }
                            }else {
                                cout<<"Ups!!! ID Menu tidak ditemukan"<<endl;
                            }
                        }
                        else
                        {
                            cout<<"Ups!!! ID Retaurant tidak ditemukan"<<endl;
                        }
                        break;
                    }
                    case 4 :
                    {
                        cout<<"==================================="<<endl;
                        printAll(Lp);
                        break;
                    }
                    case 5 :
                    {
                        cout<<"ID Restaurant   : ";
                        cin>>searchid.id;
                        Search = findElm(Lp, searchid);

                        if (Search != NULL)
                        {
                            cout<<"ID Menu Restaurant : ";
                            cin>>searchidc.id;
                            SearchChild = findElm_c(Lc, searchidc);
                            if (SearchChild == NULL)
                            {
                                cout<<"Aduh!!! Menu tidak ditemukan euy"<<endl;
                            }
                            else
                            {
                                cout<<"-----------------------------------"<<endl;
                                cout<<"ID Menu         : "<<info(SearchChild).id<<endl;
                                cout<<"Nama Menu       : "<<info(SearchChild).namamenu<<endl;
                                cout<<"Tipe            : "<<info(SearchChild).tipe<<endl;
                                cout<<"Harga           : "<<info(SearchChild).harga<<endl;
                                cout<<"Kategori        : "<<info(SearchChild).kategoriM<<endl;
                                cout<<"Rate            : "<<info(SearchChild).rateM<<endl;
                                cout<<"=============\ edit /=============="<<endl;
                                cout<<"Masukkan nama menu : ";
                                cin>>info(SearchChild).namamenu;
                                cout<<"Masukkan tipe menu : ";
                                cin>>info(SearchChild).tipe;
                                cout<<"Masukkan harga menu : Rp ";
                                cin>>info(SearchChild).harga;
                                cout<<"Masukkan kategori menu : ";
                                cin>>info(SearchChild).kategoriM;
                                cout<<"Masukkan rate menu : ";
                                cin>>info(SearchChild).rateM;
                            }
                        }
                        else
                        {
                            cout<<"Ups!!! Restaurant tidak ditemukan"<<endl;
                        }
                        break;
                    }
                    case 6 :
                    {
                        sortingchild(Lc);
                        cout<<"Yeay, Sorting Berhasil!"<<endl;
                    }
                }
            }
            break;
        }
        case 'c' :
            {
            cout<<"ID Restaurant     : ";
            cin>>searchid.id;
            Search = findElm(Lp, searchid);
            if (Search != NULL){
                Lc = child(Search);
                jumlahmenu(Lc);
                RataHarga(Lc);
                MaxHarga(Lc);
                MinHarga(Lc);
            }else{
                cout<<"Ups!!! ID tidak ditemukan"<<endl;
                }
            }
            break;
        }
    }
    return 0;
}
