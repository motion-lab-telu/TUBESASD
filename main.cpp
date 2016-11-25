#include <iostream>
#include "parent.h"
#include "child.h"

using namespace std;

int main()
{ /*
    char pilihan;
    int menures,menumen;
    cout << "Main Menu" << endl;
    cout<<"a. Restaurant ";
    cout<<"b. Menu Restaurant ";
    cout<<"c. Reporting";
    cin>>pilihan;
    switch (pilihan)
    {
    case 'a' :
        //Menu untuk retaurant
        cout<<"1. Insert restaurant";
        cout<<"2. Search & View Restaurant";
        cout<<"3. Search & Delete Restaurant";
        cout<<"4. View All Restaurant";
        cout<<"5. Search & Edit Restaurant";
        cout<<"6. Sorting Restaurant";
        cin>>menures;
        switch (menures)
        {
        case 1 :
            createList()
            alokasi()
            insertFirst()
        case 2 :
        //searchandview
        case 3 :
        //sarchanddelete
        case 4 :
        //viewallrestaurant
        case 5 :
        //searchandeditrestaurant
        case 6 :
        //sortingrestaurant

        }
        //Menu untuk menu
        break;
        case 'b' :
        cout<<"1. Insert Menu";
        cout<<"2. Search & View Menu";
        cout<<"3. Search & Delete Menu";
        cout<<"4. View All Restaurant";
        cout<<"5. Search & Edit Menu";
        cout<<"6. Sorting Menu";
        switch (menumen){
        case 1 :
            //insertmenu
        case 2 :
            //searchandviewmenu
        case 3 :
            //searchanddeletemenu
        case 4 :
            //viewallrestaurant
        case 5 :
            //searchandeditmenu
        case 6 :
            //sortingmenu
        }
    case 'c' :
        //Reporting
    }*/
    List_p A;
    address_p P, Prec;
    restaurant R1, R2, R3;
    createList(A);

    R1.id = "12P";
    R1.nama = "Chingu";
    R2.id = "13P";
    R2.nama = "Yans";
    R3.id = "14p";
    R3.nama = "Suka";

    P = alokasi(R1);
    insertFirst(A, P);

    P = alokasi(R2);
    insertFirst(A, P);

    P = alokasi(R3);
    insertLast(A, P);

    deleteFirst(A, P);
    printInfo(A);



    return 0;
}
