#include "header.h"
#include <iostream>
using namespace std;

bool isEmptyPaket(addressKurir K){
    return (K -> firstPaket == nullptr);
}

void insertAfterPaket(addressKurir &K, addressPaket p, addressPaket prec){
    if (prec == nullptr || p == nullptr) {
        cout << "Paket tidak ditemukan." << endl;
        return;
    }else {
        p -> next = prec -> next;
        p -> prev = prec;
        if (prec -> next != nullptr) {
            prec -> next -> prev = p;
        }
        prec -> next = p;
    }
}

void deleteFirstPaket(addressKurir &K, addressPaket &p){
    if (K != nullptr && K -> firstPaket != nullptr) {
        p = K -> firstPaket;
        if (K -> firstPaket -> next == nullptr) {
            K -> firstPaket = nullptr;
        } else {
            K -> firstPaket = p -> next;
            K -> firstPaket -> prev = nullptr;
        }
        p -> next = nullptr;
        p -> prev = nullptr;
        delete p;
        p = nullptr;

    } else {
        p = nullptr;
    }
}

void deleteLastPaket(addressKurir &K, addressPaket &p){
    if (K != nullptr && K -> firstPaket != nullptr) {
        if (K -> firstPaket -> next == nullptr) {
            deleteFirstPaket(K, p);
        } else {
            addressPaket temp;
            temp = K -> firstPaket;
            while (temp -> next != nullptr) {
                temp = temp -> next;
            }
            p = temp;
            temp -> prev -> next = nullptr;
            p -> prev = nullptr;
            delete p;
            p = nullptr;
        }
    } else {
        p = nullptr;
    }
}

void deleteAfterPaket(addressKurir &K, addressPaket &p, addressPaket prec){
    if (K != nullptr && prec != nullptr && prec -> next != nullptr) {
        p = prec -> next;
        prec -> next = p -> next;
        if (p -> next != nullptr) {
            p -> next -> prev = prec;
        }
        p -> next = nullptr;
        p -> prev = nullptr;
        delete p;
        p = nullptr;
    } else {
        p = nullptr;
    }
}

addressPaket findPaket(addressKurir K, string namaPaket){
    addressPaket p;
    p = K -> firstPaket;
    while (p != nullptr) {
        if (p -> info.namaPaket == namaPaket) {
            return p;
        }
        p = p -> next;
    }
    return nullptr;
}

void printPaket(addressKurir K){
    addressPaket p;
    p = K -> firstPaket;
    while (p != NULL) {
        cout << p -> info.idPaket << " - " << p -> info.namaPaket << endl;
        p = p -> next;
    }
}

void printTotalPaket(listKurir L) {
    addressKurir k = L.first;
    int jumlahPaket = 0;
    while (k != nullptr) {
        addressPaket p = k -> firstPaket;
        while (p != nullptr) {
            jumlahPaket++;
            cout << "Paket ke-" << jumlahPaket << endl;
            cout << "Kurir        : " << k->info.namaKurir << endl;
            cout << "ID Paket     : " << p->info.idPaket << endl;
            cout << "Nama Paket   : " << p->info.namaPaket << endl;
            cout << "Nomor Resi   : " << p->info.nomorResi << endl;
            cout << "Berat (kg)   : " << p->info.berat << endl;
            cout << "Harga        : " << p->info.harga << endl;
            cout << "Status       : " << p->info.statusPaket << endl;
            cout << "-------------------------------\n";
            p = p->next;
        }
        k = k -> next;
    }
    cout << "Total Paket Terdaftar: " << jumlahPaket << endl;
}
