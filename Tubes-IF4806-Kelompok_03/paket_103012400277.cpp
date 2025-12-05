#include <iostream>
using namespace std;
#include "paket.h"

void createListPaket(listPaket &L) {
    L.first = NULL;
    L.last = NULL;
}

addressPaket allocatePaket(infotypePaket x) {
    addressPaket p = new elmPaket;
    p->info = x;
    p->next = NULL;
    p->prev = NULL;
    return p;
}

void insertFirstPaket(listPaket &L, addressPaket p) {
    if (L.first == NULL) {
        L.first = p;
        L.last = p;
    } else {
        p->next = L.first;
        L.first->prev = p;
        L.first = p;
    }
}

void insertLastPaket(listPaket &L, addressPaket p) {
    if (L.first == NULL) {
        L.first = p;
        L.last = p;
    } else {
        L.last->next = p;
        p->prev = L.last;
        L.last = p;
    }
}

