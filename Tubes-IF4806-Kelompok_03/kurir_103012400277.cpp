#include "header.h"
#include <iostream>
using namespace std;

void printKurir(listKurir L) {
    addressKurir p = L.first;
    while (p != nullptr) {
        cout << p->info.idKurir << " - " << p->info.namaKurir << endl;
        p = p->next;
    }
}
addressPaket allocatePaket(infotypePaket x) {
    addressPaket p = new elmPaket;
    p->info = x;
    p->next = nullptr;
    p->prev = nullptr;
    return p;
}

void tambahPaketKeKurir(addressKurir k, infotypePaket x) {
    x.harga = hitungHarga(x.berat);
    if (x.statusPaket == " "){
        x.statusPaket = "Dikemas";
    }
    addressPaket p = allocatePaket(x);
    insertLastPaket(k, p);
}

void printPaketKurir(addressKurir k) {
    cout << "Paket milik kurir " << k->info.namaKurir << ":\n";
    printPaket(k);
}
void deleteKurirByName(listKurir &L, string namaKurir) {
    addressKurir p = L.first;
    addressKurir prec = nullptr;

    while (p != nullptr && p->info.namaKurir != namaKurir) {
        prec = p;
        p = p->next;
    }

    if (p == nullptr) {
        cout << "Kurir tidak ditemukan!\n";
        return;
    }

    if (prec == nullptr) {
        L.first = p->next;
    }
    else {
        prec->next = p->next;
    }

    p->next = nullptr;
    cout << "Kurir berhasil dihapus.\n";
}


void deleteKurirBesertaPaket(listKurir &L, string namaKurir) {
    addressKurir p = L.first;
    addressKurir prec = nullptr;
    while (p != nullptr && p->info.namaKurir != namaKurir) {
        prec = p;
        p = p->next;
    }

    if (p == nullptr) {
        cout << "Kurir tidak ditemukan!\n";
        return;
    }

    addressPaket q = p->firstPaket;
    while (q != nullptr) {
        addressPaket next = q->next;
        q->next = nullptr;
        q = next;
    }
    p->firstPaket = nullptr;

    if (prec == nullptr) {
        L.first = p->next;
    }
    else {
        prec->next = p->next;
    }

    p->next = nullptr;

    cout << "Kurir dan seluruh paketnya berhasil dihapus.\n";
}
