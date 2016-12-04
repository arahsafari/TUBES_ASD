#include "multi.h"
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;


void createListFitur(listfitur &Lfitur)
{
    first(Lfitur) = Nil;
    last(Lfitur) = Nil;
}//1301140165



addressF alokasiFitur(infofitur x)
{
    addressF P = new ElmListFitur;
    info(P).namafitur = x.namafitur;
    info(P).keterangan = x.keterangan;
    next(P) = Nil;
    prev(P) = Nil;
}//1301140165



void dealokasiFitur(addressF &P)
{
    delete P;
}//1301140165


addressF findElmFitur(listfitur Lfitur, infofitur x)
{
    addressF P = first(Lfitur);
    if ( first(Lfitur) == Nil )
    {
        return Nil;
    }
    else
    {
        while ( P != Nil )
        {
            if ( info(P).namafitur == x.namafitur )
            {
                return P;
            }
            else
            {
                P = next(P);
            }
        }
        return Nil;
    }
}//1301140165


void insertFirstFitur(listfitur &Lfitur, addressF P)
{
    if ( first(Lfitur) == Nil )
    {
        first(Lfitur) = P;
        last(Lfitur) = P;
    }
    else
    {
        next(P) = first(Lfitur);
        prev(first(Lfitur)) = P;
        first(Lfitur) = P;
    }
    cout<<"Succeed"<<endl;
}//1301140165

void insertLastFitur(listfitur &Lfitur, addressF P)
{
    if ( first(Lfitur) == Nil )
    {
        first(Lfitur) = P;
        last(Lfitur) = P;
    }
    else
    {
        prev(P) = last(Lfitur);
        next(last(Lfitur)) = P;
        last(Lfitur) = P;
    }
    cout<<"Succeed"<<endl;
}//1301140165

void insertAfterFitur(listfitur &Lfitur, addressF Prec, addressF P)
{
    if ( first(Lfitur) == Nil )
    {
        first(Lfitur) = P;
        last(Lfitur) = P;
    }
    else if ( Prec == last(Lfitur) )
    {
        insertLastFitur(Lfitur,P);
    }
    else
    {
        next(P) = next(Prec);
        prev(P) = Prec;
        next(Prec) = P;
        prev(next(Prec)) = P;
    }
    cout<<"Succeed"<<endl;
}//1301140165



void deleteFirstFitur(listfitur &Lfitur, addressF &P)
{
    if ( first(Lfitur) == Nil )
    {
        cout<<"List Kosong"<<endl;
    }
    else if ( first(Lfitur) == last(Lfitur) )
    {
        P = first(Lfitur);
        first(Lfitur) = Nil;
        last(Lfitur) = Nil;
        dealokasiFitur(P);
        cout<<"Succeed"<<endl;
    }
    else
    {
        P = first(Lfitur);
        first(Lfitur) = next(first(Lfitur));
        prev(first(Lfitur)) = first(Lfitur);
        next(P) = Nil;
        prev(P) = Nil;
        dealokasiFitur(P);
        cout<<"Succeed"<<endl;
    }
}//1301144380

void deleteLastFitur(listfitur &Lfitur, addressF &P)
{
    if ( first(Lfitur) == Nil )
    {
        cout<<"List Kosong"<<endl;
    }
    else
    {
        P = last(Lfitur);
        last(Lfitur) = prev(P);
        next(prev(P)) = last(Lfitur);
        next(P) = Nil;
        prev(P) = Nil;
        dealokasiFitur(P);
        cout<<"Succeed"<<endl;
    }
}//1301144380

void deleteLangsungFitur(listfitur &Lfitur, addressF Prec, addressF &P)
{
    P=first(Lfitur);
    if ( first(Lfitur) == Nil )
    {
        cout<<"List Kosong"<<endl;
    }
    else if ( P == Prec )
    {
        deleteFirstFitur(Lfitur,P);
    }
    else
    {
        while(next(P)!=Prec)
        {
            P=next(P);
        }
        next(P) = next(Prec);
        prev(next(Prec)) = P;
        prev(Prec) = Nil;
        next(Prec) = Nil;
        cout<<"Succeed"<<endl;
    }
}//1301144380

void deleteAfterFitur(listfitur &Lfitur, addressF Prec, addressF &P)
{
    if ( first(Lfitur) == Nil )
    {
        cout<<"List Kosong"<<endl;
    }
    else if ( next(Prec) == first(Lfitur) )
    {
        deleteFirstFitur(Lfitur,P);
    }
    else
    {
        P = next(Prec);
        next(Prec) = next(P);
        prev(next(P)) = Prec;
        prev(P) = Nil;
        next(P) = Nil;
        cout<<"Succeed"<<endl;
    }
}//1301144380


void printInfoFitur(listfitur Lfitur)
{
    if ( first(Lfitur) == Nil )
    {
        cout<<"List Kosong"<<endl;
    }
    else
    {
        addressF P = first(Lfitur);
        int a=1;
        do
        {
            cout<<a<<". "<<info(P).namafitur<<endl;
            cout<<"Keterangan : "<<info(P).keterangan<<endl;
            a++;
            P = next(P);
        } while ( P != Nil );
    }
    cout<<endl;
}//1301144380

