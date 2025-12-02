#include <iostream>
#include "paket.h"
#include "kurir.h"
using namespace std;

void createListPaket(listPaket &L);
adressPaket allocatePaket(infotypePaket x);
void insertFirstPaket(listPaket &L, adressPaket p);
void insertLastPaket(listPaket &L, adressPaket p);
void deleteFirstPaket(listPaket &L, adressPaket &p);
void deleteLastPaket(listPaket &L, adressPaket &p);
void printPaket(listPaket L);
adressPaket findPaket(listPaket L, string namaPaket);
