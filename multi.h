#ifndef MULTI_H_INCLUDED
#define MULTI_H_INCLUDED

#include <iostream>

using namespace std;

#define Nil NULL
#define Lfitur(P) (P)->Lfitur
#define first(Lfitur) ((Lfitur).first)
#define last(Lfitur) ((Lfitur).last)
#define first(L) (L).first
#define prev(P) (P)->prev
#define info(P) (P)->info
#define next(P) (P)->next


struct fitur
{
    string namafitur;
    string keterangan;
};//1301144380

typedef struct fitur infofitur;//1301144380
typedef struct ElmListFitur *addressF;//1301144380

struct ElmListFitur
{
    infofitur info;
    addressF next;
    addressF prev;
};//1301144380

struct listfitur
{
    addressF first;
    addressF last;
};//1301144380


void createListFitur(listfitur &Lfitur);
addressF alokasiFitur(infofitur x);
void dealokasiFitur(addressF &P);
addressF findElmFitur(listfitur Lfitur, infofitur x);
void insertFirstFitur(listfitur &Lfitur, addressF P);
void insertLastFitur(listfitur &Lfitur, addressF P);
void insertAfterFitur(listfitur &Lfitur, addressF Prec, addressF P);
void deleteFirstFitur(listfitur &Lfitur, addressF &P);
void deleteLastFitur(listfitur &Lfitur, addressF &P);
void deleteLangsungFitur(listfitur &Lfitur, addressF Prec, addressF &P);
void deleteAfterFitur(listfitur &Lfitur, addressF Prec, addressF &P);
void printInfoFitur(listfitur Lfitur);
//void sorting(listmobil L,listfitur Lfitur,temp z);

#endif // MULTI_H_INCLUDED
