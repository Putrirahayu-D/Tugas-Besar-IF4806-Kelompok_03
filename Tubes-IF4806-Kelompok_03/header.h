#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <iostream>
#include <string>
using namespace std;


struct infotypePaket {
    string namaPaket;
    string idPaket;
};

struct elmPaket;
typedef elmPaket* addressPaket;

struct elmPaket {
    infotypePaket info;
    addressPaket next;
    addressPaket prev;
};

struct listPaket {
    addressPaket first;
    addressPaket last;
};

struct infotypeKurir {
    string namaKurir;
    string idKurir;
};

struct elmKurir;
typedef elmKurir* addressKurir;

struct elmKurir {
    infotypeKurir info;
    addressKurir next;
    addressKurir prev;
    listPaket paketList;
};

struct listKurir {
    addressKurir first;
    addressKurir last;
};


void createListPaket(listPaket &L);
addressPaket allocatePaket(infotypePaket x);
void insertFirstPaket(listPaket &L, addressPaket p);
void insertLastPaket(listPaket &L, addressPaket p);
void deleteFirstPaket(listPaket &L, addressPaket &p);
void deleteLastPaket(listPaket &L, addressPaket &p);
void deletePaketByName(listPaket &L, string namaPaket);
addressPaket findPaket(listPaket L, string namaPaket);
void printPaket(listPaket L);

// =======================
//  PROTOTYPE FUNGSI KURIR
// =======================
void createListKurir(listKurir &L);
addressKurir allocateKurir(infotypeKurir x);
void insertLastKurir(listKurir &L, addressKurir p);
addressKurir findKurir(listKurir L, string namaKurir);
void printKurir(listKurir L);
void tambahPaketKeKurir(addressKurir k, infotypePaket x);
void printPaketKurir(addressKurir k);
void deleteKurir(listKurir &L, string namaKurir);
void deleteKurirBesertaPaket(listKurir &L, string namaKurir);



#endif // HEADER_H_INCLUDED
