#include <iostream>
using namespace std;
#include "header.h"

void deleteFirstPaket(listPaket &L, addressPaket &p) {
    if (L.first == NULL) {
        p = NULL;
    } else if (L.first == L.last) {
        p = L.first;
        L.first = NULL;
        L.last = NULL;
    } else {
        p = L.first;
        L.first = p->next;
        L.first->prev = NULL;
        p->next = NULL;
    }
}

void deleteLastPaket(listPaket &L, addressPaket &p) {
    if (L.first == NULL) {
        p = NULL;
    } else if (L.first == L.last) {
        p = L.last;
        L.first = NULL;
        L.last = NULL;
    } else {
        p = L.last;
        L.last = p->prev;
        L.last->next = NULL;
        p->prev = NULL;
    }
}

void printPaket(listPaket L) {
    addressPaket p = L.first;
    while (p != NULL) {
        cout << "Nama Paket : " << p->info.namaPaket << endl;
        cout << "ID Paket   : " << p->info.idPaket << endl;
        cout << "---------------------------" << endl;
        p = p->next;
    }
}
addressPaket findPaket(listPaket L, string namaPaket) {
    addressPaket p = L.first;
    while (p != NULL) {
        if (p->info.namaPaket == namaPaket) {
            return p;
        }
        p = p->next;
    }
    return NULL;
}
