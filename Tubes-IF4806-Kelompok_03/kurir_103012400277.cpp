#include "header.h"
using namespace std;

void printKurir(listKurir L) {
    addressKurir p = L.first;
    while (p != NULL) {
        cout << p->info.idKurir << " - " << p->info.namaKurir << endl;
        p = p->next;
    }
}

void tambahPaketKeKurir(addressKurir k, infotypePaket x) {
    addressPaket p = allocatePaket(x);
    insertLastPaket(k->paketList, p);
}

void printPaketKurir(addressKurir k) {
    cout << "Paket milik kurir " << k->info.namaKurir << ":\n";
    printPaket(k->paketList);
}
void deleteKurir(listKurir &L, string namaKurir) {
    addressKurir p = findKurir(L, namaKurir);

    if (p == NULL) {
        cout << "Kurir tidak ditemukan!\n";
        return;
    }

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

    cout << "nama kurir berhasil dihapus.\n";
}
void deleteKurirBesertaPaket(listKurir &L, string namaKurir) {
    addressKurir p = findKurir(L, namaKurir);

    if (p == NULL) {
        cout << "Kurir tidak ditemukan!\n";
        return;
    }

    addressPaket q = p->paketList.first;
    while (q != NULL) {
        addressPaket next = q->next;

        q->next = NULL;
        q->prev = NULL;

        q = next;
    }

    p->paketList.first = NULL;
    p->paketList.last = NULL;

    deleteKurir(L, namaKurir);

    cout << "Kurir dan paketnya berhasil dihapus.\n";
}


