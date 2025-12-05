#ifndef KURIR_H_INCLUDED
#define KURIR_H_INCLUDED

#include <iostream>
#include <string>
#include "paket.h"
using namespace std;
typedef struct elmKurir *addressKurir;

struct infotypeKurir {
    string namaKurir;
    string idKurir;
};

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

void createListKurir(listKurir &L);
addressKurir allocateKurir(infotypeKurir x);
void insertLastKurir(listKurir &L, addressKurir p);
addressKurir findKurir(listKurir L, string namaKurir);
void printKurir(listKurir L);
void tambahPaketKeKurir(addressKurir k, infotypePaket x);
void printPaketKurir(addressKurir k);
void deleteKurir(listKurir &L, string namaKurir);
void deleteKurirBesertaPaket(listKurir &L, string namaKurir);
#endif

