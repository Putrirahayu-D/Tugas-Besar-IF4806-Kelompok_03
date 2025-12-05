#include "kurir.h"
using namespace std;

void createListKurir(listKurir &L) {
    L.first = NULL;
    L.last = NULL;
}

addressKurir allocateKurir(infotypeKurir x) {
    addressKurir p = new elmKurir;
    p->info = x;
    p->next = NULL;
    p->prev = NULL;
    createListPaket(p->paketList);
    return p;
}

void insertLastKurir(listKurir &L, addressKurir p) {
    if (L.first == nullptr) {
        L.first = L.last = p;
    } else {
        L.last->next = p;
        p->prev = L.last;
        L.last = p;
    }
}

addressKurir findKurir(listKurir L, string namaKurir) {
    addressKurir p = L.first;
    while (p != NULL) {
        if (p->info.namaKurir == namaKurir) return p;
        p = p->next;
    }
    return NULL;
}
