#ifndef MOBIL_H_INCLUDED
#define MOBIL_H_INCLUDED
#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;
#include "multi.h"

#define first(L) (L).first
#define info(P) (P)->info
#define next(P) (P)->next

struct mobil
{
    string merek;
    string nama;
    string warna;
    int tahun;
    int cc;
    long harga;
};//1301144380

typedef struct mobil infomobil;//1301144380
typedef struct ElmListMobil *address;//1301144380

struct ElmListMobil
{
    infomobil info;
    listfitur Lfitur;
    address next;
};//1301144380

struct listmobil
{
    address first;
};//1301144380


void createList(listmobil &L);
address alokasi(infomobil x);
void dealokasi(address &P);
address findElm(listmobil L, infomobil x);
void insertFirst(listmobil &L, address P);
void insertLast(listmobil &L, address P);
void insertAfter(listmobil &L, address Prec, address P);
void insertMobil(listmobil &L);
void insertFitur(listmobil &L);
void deleteFirst(listmobil &L, address &P);
void deleteLast(listmobil &L, address &P);
void deletelangsung(listmobil &L, address Prec, address &P);
void deleteMobil(listmobil &L);
void deleteFitur(listmobil &L);
void printInfo(listmobil L);
void reporting(listmobil &L);
void sorting(listmobil &L);
#endif // MOBIL_H_INCLUDED
