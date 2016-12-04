#include "mobil.h"


void createList(listmobil &L)
{
    first(L) = Nil;
}//1301140165

address alokasi(infomobil x)
{
    address P = new ElmListMobil;
    info(P).merek = x.merek;
    info(P).nama = x.nama;
    info(P).warna = x.warna;
    info(P).tahun = x.tahun;
    info(P).cc = x.cc;
    info(P).harga = x.harga;
    next(P) = Nil;
}//1301140165

void dealokasi(address &P)
{
    delete P;
}//1301140165

address findElm(listmobil L, infomobil x)
{
    address P = first(L);
    if ( first(L) == Nil )
    {
        return Nil;
    }
    else
    {
        do
        {
            if ( info(P).nama == x.nama )
            {
                return P;
            }
            else
            {
                P = next(P);
            }
        }
        while ( P != NULL );
        return Nil;
    }
}//1301140165

void insertFirst(listmobil &L, address P)
{
    if ( first(L) == Nil )
    {
        first(L) = P;
    }
    else
    {
        next(P) = first(L);
        first(L) = P;
    }
    cout<<"Succeed"<<endl;
}//1301140165

void insertLast(listmobil &L, address P)
{
    address r;
    r=first(L);
    if ( first(L) == Nil )
    {
        first(L) = P;
    }
    else
    {
        while (r->next != NULL)
        {
            r= r->next;
        }
        r->next = P;
    }
    cout<<"Succeed"<<endl;
}//1301140165

void insertAfter(listmobil &L, address Prec, address P)
{
    if ( first(L) == Nil )
    {
        first(L) = P;
    }
    else
    {
        next(P) = next(Prec);
        next(Prec) = P;
    }
    cout<<"Succeed"<<endl;
}//1301140165

void insertMobil(listmobil &L)
{
    system("CLS");
    int pil;
    infomobil x;
    address P,Q;
    cout<<"Masukkan Merek      : ";
    cin>>x.merek;
    while (x.merek != "stop")
    {
        cout<<"Masukkan Nama Mobil : ";
        cin>>x.nama;
        cout<<"Masukkan Warna      : ";
        cin>>x.warna;
        cout<<"Masukkan Tahun      : ";
        cin>>x.tahun;
        cout<<"Masukkan CC         : ";
        cin>>x.cc;
         cout<<"Masukkan Harga      : ";
         cin>>x.harga;
        P = alokasi(x);
        cout<<endl<<"1. Insert First"<<endl;
        cout<<"2. Insert Last"<<endl;
        cout<<"3. Insert After"<<endl;
        cout <<"masukkan pilihan anda : ";
        cin>>pil;
        if (pil == 1)
        {
            insertFirst(L,P);
        }
        else if (pil==2)
        {
            insertLast(L,P);
        }
        else if (pil==3)
        {
            cout<<"Masukkan Nama Mobil : ";
            cin>>x.nama;
            Q = findElm(L,x);
            if (Q==Nil)
            {
                cout<<"Mobil Tidak Ditemukan";
            }
            else
            {
                insertAfter(L,Q,P);
            }
        }


        createListFitur(Lfitur(P));
        cout<<"Masukkan Merek      : ";
        cin>>x.merek;
    }
}//1301140165


void insertFitur(listmobil &L)
{
    system("CLS");
    int pil;
    address P;
    addressF Q,F;
    infomobil x;
    infofitur y;
    cout<<"Masukkan Nama Mobil : ";
    cin>>x.nama;
    P = findElm(L,x);
    if ( P == Nil )
    {
        cout<<"Mobil Tidak Ditemukan";
    }
    else
    {
        cout<<"Masukkan Nama Fitur : ";
        cin>>y.namafitur;
        while (y.namafitur != "stop")
        {
            cout<<"Masukkan Keterangan : ";
            cin>>y.keterangan;
            Q = alokasiFitur(y);
            cout<<endl<<"1. Insert First"<<endl;
            cout<<"2. Insert Last"<<endl;
            cout<<"3. Insert After"<<endl;
            cin>>pil;
            if (pil==1)
            {
                insertFirstFitur(Lfitur(P),Q);
            }
            else if (pil==2)
            {
                insertLastFitur(Lfitur(P),Q);
            }
            else if (pil==3)
            {
                cout<<"Masukkan Nama fitur : ";
                cin>>y.namafitur;
                F = findElmFitur(Lfitur(P),y);
                if (F==Nil)
                {
                    cout<<"Fitur Tidak Ditemukan";
                }
                else
                {
                    insertAfterFitur(Lfitur(P),F,Q);
                }
            }
            cout<<"Masukkan Nama Fitur : ";
            cin>>y.namafitur;
        }
    }
}//1301144380

void reporting(listmobil &L)
{
    system("CLS");
    address P;
    addressF Q,F;
    infomobil x;
    int i;
    i=0;
    cout<<"Masukkan Nama Mobil : ";
    cin>>x.nama;
    P = findElm(L,x);
    if ( P == Nil )
    {
        cout<<"Mobil Tidak Ditemukan";
    }
    else
    {
        P=first(L);
        while(P!=NULL)
        {
            if(x.nama==info(P).nama)
            {
                i++;
            }
            P=next(P);
        }
        cout << "Mobil Tersebut Sudah Disewa Sebanyak : " << i;
    }
}//1301144380



void deleteFirst(listmobil &L, address &P)
{
    if ( first(L) == Nil )
    {
        cout<<"List Kosong"<<endl;
    }
    else
    {
        P = first(L);
        first(L) = next(first(L));
        next(P) = Nil;
        dealokasi(P);
        cout<<"Succeed"<<endl;
    }
}//1301144380

void deleteLast(listmobil &L, address &P)
{
    address prec;
    P = first(L);
    if ( first(L) == Nil )
    {
        cout<<"List Kosong"<<endl;
    }
    else if (next(P)==NULL)
    {

        deleteFirst(L,P);

    }
    else
    {
        prec=P;
        P=next(prec);
        while(next(P)!=NULL)
        {
            prec=P;
            P=next(prec);
        }
        next(prec) = NULL;
        dealokasi(P);
        cout<<"Succeed"<<endl;
    }

}//1301144380

void deletelangsung(listmobil &L, address Prec, address &P)
{
    P = first(L);
    if ( first(L) == Nil )
    {
        cout<<"List Kosong"<<endl;
    }
    else if (P==Prec)
    {

        deleteFirst(L,P);

    }
    else
    {
        while(next(P)!=Prec)
        {
            P=next(P);
        }
        next(P) = next(Prec);
        next(Prec) = Nil;
        dealokasi(Prec);
        cout<<"Succeed"<<endl;
    }
}//1301144380


void deleteMobil(listmobil &L)
{
    system("CLS");
    address P,Q;
    infomobil x;
    int pil;
    cout<<endl<<"1. Delete data paling awal"<<endl;
    cout<<"2. Delete data paling terakhir"<<endl;
    cout<<"3. Delete berdasarkan search"<<endl;
    cout <<"masukkan pilihan anda : ";
    cin>>pil;
    if (pil == 1)
    {
        deleteFirst(L,P);
    }
    else if (pil==2)
    {
        deleteLast(L,P);
    }
    else if (pil==3)
    {
        cout<<"Masukkan Nama Mobil yang Akan Dihapus : ";
        cin>>x.nama;
        P = findElm(L,x);
        if ( P == Nil )
        {
            cout<<"Mobil Tidak Ditemukan";
        }
        else
        {
            deletelangsung(L,P,Q);
        }
    }
}//1301144380

void deleteFitur(listmobil &L)
{
    system("CLS");
    address P;
    addressF Q,R;
    infomobil x;
    infofitur y;
    cout<<"Masukkan Nama Mobil : ";
    cin>>x.nama;
    P = findElm(L,x);
    if ( P == Nil )
    {
        cout<<"Mobil Tidak Ditemukan";
    }
    else
    {
        int pil;
        cout<<endl<<"1. Delete data paling awal"<<endl;
        cout<<"2. Delete data paling terakhir"<<endl;
        cout<<"3. Delete berdasarkan search"<<endl;
        cout <<"masukkan pilihan anda : ";
        cin>>pil;
        if (pil == 1)
        {
            deleteFirstFitur(Lfitur(P),R);
        }
        else if (pil==2)
        {
            deleteLastFitur(Lfitur(P),R);
        }
        else if (pil==3)
        {
            cout<<"Masukkan Nama Fitur : ";
            cin>>y.namafitur;
            Q = findElmFitur(Lfitur(P),y);
            if ( Q == Nil )
            {
                cout<<"Fitur Tidak Ditemukan";
            }
            else
            {
                deleteLangsungFitur(Lfitur(P),Q,R);
            }

        }
    }
}//1301144380

void printInfo(listmobil L)
{
    if ( first(L) == Nil )
    {
        cout<<"List Kosong"<<endl;
    }
    else
    {
        address P = first(L);
        do
        {
            cout<<"Merk   : "<<info(P).merek<<endl;
            cout<<"nama  : "<<info(P).nama<<endl;
                  cout<<"Tahun  : "<<info(P).tahun<<endl;
             cout<<"Warna  : "<<info(P).warna<<endl;
            cout<<"CC     : "<<info(P).cc<<endl;
                cout<<"Harga  : "<<info(P).harga<<endl;
            cout<<"Fitur  : "<<endl;
           printInfoFitur(Lfitur(P));
            cout<<"=====================================================";
            cout<<endl;
            P = next(P);
        }
        while ( P != NULL );
    }
}//1301144380




void sorting(listmobil &L)
{

    address q=q;
    address p=q;

    q = next(q);

    while(q!= NULL)
    {

        p = q;

        while (next(p) != q)
        {
            if (info(p).cc > info(q).cc)
            {
                string temp1 = info(q).merek;
                info(q).merek = info(p).merek;
                info(p).merek = temp1;

                temp1 = info(q).nama;
                info(q).nama = info(p).nama;
                info(p).nama = temp1;

                temp1 = info(q).warna;
                info(q).warna = info(p).warna;
                info(p).warna = temp1;

                int temp = info(q).tahun;
                info(q).tahun = info(p).tahun;
                info(p).tahun = temp;

                temp = info(q).cc;
                info(q).cc = info(p).cc;
                info(p).cc = temp;

                int temp2 = info(q).harga;
                info(q).harga = info(p).harga;
                info(p).harga = temp2;

            }
            else
            {
                p=next(p);
            }
        }
        q = next(q);
    }
}//1301144380

