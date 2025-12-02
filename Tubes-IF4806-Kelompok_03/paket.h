#ifndef PAKET_H_INCLUDED
#define PAKET_H_INCLUDED
#include <iostream>
using namespace std;

struct infotypePaket{
    string namaPaket;
    string idPaket;
};

typedef struct elmPaket *adressPaket;

struct elmPaket{
    infoPaket info;
    adressPaket next;
    adressPaket prev;
};

struct listPaket{
    adressPaket first;
    adressPaket last
};

void createListPaket(listPaket &L);
adressPaket allocatePaket(infotypePaket x);
void insertFirstPaket(listPaket &L, adressPaket p);
void insertLastPaket(listPaket &L, adressPaket p);
void deleteFirstPaket(listPaket &L, adressPaket &p);
void deleteLastPaket(listPaket &L, adressPaket &p);
void printPaket(listPaket L);
adressPaket findPaket(listPaket L, string namaPaket);
#endif // PAKET_H_INCLUDED
