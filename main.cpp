#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include "mobil.h"

using namespace std;

int main()//1301144380
{
    int pil;
    address P;
    infomobil x;
    listmobil L;
    createList(L);
    bool exit = false;
    while (exit == false)
    {
        system("cls");
        cout<<"1. Insert Data Mobil"<<endl;
        cout<<"2. Insert Data Fitur"<<endl;
        cout<<"3. Delete Data Mobil"<<endl;
        cout<<"4. Delete Data Fitur"<<endl;
        cout<<"5. Lihat Data Keseluruhan"<<endl;
        cout<<"6. Cari Data Mobil"<<endl;
        cout<<"7. Reporting"<<endl;
        cout<<"8. Sorting Berdasarkan Kapasitas Mesin Mobil"<<endl;
        cout<<"9. Exit"<<endl;
        cout<<"Masukkan Pilihan : ";
        cin>>pil;
        if (pil==1)
        {
            insertMobil(L);
        }
        else if (pil==2)
        {
           insertFitur(L);
        }
        else if (pil==3)
        {
            deleteMobil(L);
        }
        else if (pil==4)
        {
            deleteFitur(L);
        }
        else if (pil==5)
        {
            system("CLS");
            printInfo(L);
        }
        else if (pil==6)
        {
            system("CLS");
            cout<<"Masukkan Nama Mobil : ";
            cin>>x.nama;
            P = findElm(L,x);
            if (P==Nil)
            {
                cout<<"Data Mobil Tidak Ditemukan";
            }
            else
            {
                cout<<"Merk   : "<<info(P).merek<<endl;
                cout<<"nama  : "<<info(P).nama<<endl;
                cout<<"Tahun  : "<<info(P).tahun<<endl;
                cout<<"Warna  : "<<info(P).warna<<endl;
                cout<<"CC     : "<<info(P).cc<<endl;
                cout<<"Harga  : "<<info(P).harga<<endl;
                cout<<"Fitur  : "<<endl;
                printInfoFitur(Lfitur(P));
            }
        }
        else if (pil==7)
        {
            reporting(L);
        }
        else if (pil==8)
        {
            system("CLS");
            sorting(L);
            printInfo(L);
        }
        else if (pil==9)
        {
            exit =true;
        }
        else
        {
            cout<<"Pilihan Salah";
        }
        getch();
    }
    return 0;
}
