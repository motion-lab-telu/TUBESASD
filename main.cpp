#include <iostream>

using namespace std;

int main()
{
    char pilihan;
    int menures,menumen;
    cout << "Main Menu" << endl;
    cout<<"a. Restaurant ";
    cout<<"b. Menu Restaurant ";
    cout<<"c. Reporting";
    cin>>pilihan;
    switch (pilihan){
    case 'a' :
        //Menu untuk retaurant
        cout<<"1. Insert restaurant";
        cout<<"2. Search & View Restaurant";
        cout<<"3. Search & Delete Restaurant";
        cout<<"4. View All Restaurant";
        cout<<"6. Search & Edit Restaurant";
        cout<<"7. Sorting Restaurant";
        cin>>menumen;
    //Menu untuk menu
    cout<<"1. Insert Menu";
    cout<<"2. Search & View Menu";
    cout<<"3. Search & Delete Menu";
    cout<<"4. View All Restaurant";
    cout<<"6. Search & Edit Menu";
    cout<<"7. Sorting Menu";
    return 0;
}
