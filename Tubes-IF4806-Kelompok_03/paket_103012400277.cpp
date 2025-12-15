#include <iostream>
using namespace std;
#include "header.h"

addressPaket createElmPaket(infotypePaket x) {
    addressPaket p = new elmPaket;
    p->info = x;
    p->next = nullptr;
    p->prev = nullptr;
    return p;
}

void insertFirstPaket(addressKurir &K, addressPaket p) {
    if (isEmptyPaket(K)) {
        K->firstPaket = p;
    } else {
        p->next = K->firstPaket;
        K->firstPaket->prev = p;
        K->firstPaket = p;
    }
}

void insertLastPaket(addressKurir &K, addressPaket p) {
   if (isEmptyPaket(K)){
        K->firstPaket = p;
    } else {
        addressPaket q = K->firstPaket;

        while (q->next != nullptr) {
            q = q->next;
        }

        q->next = p;
        p->prev = q;
    }
}

void deletePaketByName(addressKurir &K, string namaPaket) {
    if (K == nullptr || K -> firstPaket == nullptr) {
        cout << "Kurir tidak ditemukan atau list paket kosong." << endl;
        return;
    }
    addressPaket p = findPaket(K, namaPaket);
    if (p == nullptr) {
        cout << "Paket '" << namaPaket << "' tidak ditemukan pada kurir " << K->info.namaKurir << "." << endl;
        return;
    }
    if (p -> prev == nullptr) {
        K -> firstPaket = p -> next;
        if (K -> firstPaket != nullptr) {
            K -> firstPaket -> prev = nullptr;
        }
    }
    else if (p -> next == nullptr) {
        p -> prev -> next = nullptr;
    }
    else {
        p -> prev -> next = p -> next;
        p -> next -> prev = p -> prev;
    }
    p -> next = nullptr;
    p -> prev = nullptr;
    delete(p);

    cout << "Paket berhasil dihapus." << endl;
}

float hitungHarga(float berat) {
    if (berat <= 1) {
        return 10000;
    }else if (berat <= 3){
        return 25000;
    }else if (berat <= 5){
        return 40000;
    }
    return 50000 + (berat - 5) * 5000;
}
void updateStatusPaket(addressKurir K, string namaPaket, string statusBaru) {
    if (K == nullptr) {
        cout << "Kurir tidak valid.\n";
        return;
    }

    addressPaket p = findPaket(K, namaPaket);
    if (p != nullptr) {
        p->info.statusPaket = statusBaru;
        cout << "Status paket berhasil diperbarui.\n";
    } else {
        cout << "Paket '" << namaPaket << "' tidak ditemukan pada kurir "
             << K->info.namaKurir << ".\n";
    }
}
addressPaket findPaketByResi(listKurir L, string resi) {
    addressKurir k = L.first;
    while (k != nullptr) {
        addressPaket p = k->firstPaket;
        while (p != nullptr) {
            if (p->info.nomorResi == resi) {
                return p;
            }
            p = p->next;
        }
        k = k->next;
    }
    return nullptr;
}

