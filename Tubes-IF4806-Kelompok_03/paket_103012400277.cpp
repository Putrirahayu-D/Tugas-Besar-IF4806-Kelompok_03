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
void deletePaketByName(listPaket &L, string namaPaket) {
    addressPaket p = L.first;

    while (p != NULL) {
        if (p->info.namaPaket == namaPaket) {

            if (p == L.first && p == L.last) {
                L.first = NULL;
                L.last = NULL;
            }
            else if (p == L.first) {
                L.first = p->next;
                L.first->prev = NULL;
                p->next = NULL;
            }
            else if (p == L.last) {
                L.last = p->prev;
                L.last->next = NULL;
                p->prev = NULL;
            }
            else {
                p->prev->next = p->next;
                p->next->prev = p->prev;
                p->next = NULL;
                p->prev = NULL;
            }

            return;
        }
        p = p->next;
    }
}



