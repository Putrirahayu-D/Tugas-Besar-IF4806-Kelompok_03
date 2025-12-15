#ifndef PAKET_H_INCLUDED
#define PAKET_H_INCLUDED
#include <iostream>
using namespace std;

struct infotypePaket{
    string namaPaket;
    string idPaket;
};

typedef struct elmPaket *addressPaket;

struct elmPaket{
    infotypePaket info;
    addressPaket next;
    addressPaket prev;
};

struct listPaket{
    addressPaket first;
    addressPaket last;
};
void deletePaketByName(listPaket &L, string namaPaket);
void createListPaket(listPaket &L);
addressPaket allocatePaket(infotypePaket x);
void insertFirstPaket(listPaket &L, addressPaket p);
void insertLastPaket(listPaket &L, addressPaket p);
void deleteFirstPaket(listPaket &L, addressPaket &p);
void deleteLastPaket(listPaket &L, addressPaket &p);
void printPaket(listPaket L);
addressPaket findPaket(listPaket L, string namaPaket);
#endif // PAKET_H_INCLUDED
