#include "header.h"
using namespace std;

void createListKurir(listKurir &L){
    L.first = nullptr;
}

addressKurir allocateKurir(infotypeKurir x){
    addressKurir p = new elmKurir;
    p -> info = x;
    p -> next = nullptr;
    return p;
}

void insertFirstKurir(listKurir &L, addressKurir p){
    if (L.first == nullptr){
        L.first = p;
    } else {
        p -> next = L.first;
        L.first = p;
    }
}

void insertLastKurir(listKurir &L, addressKurir p){
    if (L.first == nullptr){
        insertFirstKurir(L, p);
    } else {
        addressKurir q;
        q = L.first;
        while (q -> next != nullptr){
            q = q -> next;
        }
        q -> next = p;
    }
}

void insertAfterKurir(listKurir &L, addressKurir p, addressKurir prec){
    p -> next = prec -> next;
    prec -> next = p;
}

void deleteFirstKurir(listKurir &L, addressKurir &p) {
    if (L.first != nullptr) {
        p = L.first;
        L.first = p -> next;
        p -> next = nullptr;
    } else {
        p = nullptr;
    }
}

void deleteLastKurir(listKurir &L, addressKurir &p) {
    if (L.first == nullptr) {
        p = nullptr;
    } else if (L.first -> next == nullptr) {
        deleteFirstKurir(L, p);
    } else {
        addressKurir q;
        q = L.first;
        while (q -> next -> next != nullptr) {
            q = q -> next;
        }
        p = q -> next;
        q -> next = nullptr;
    }
}

void deleteAfterKurir(listKurir &L, addressKurir prec, addressKurir &p) {
    p = nullptr;
    if (L.first == nullptr) return;
    if (prec == nullptr) {
        deleteFirstKurir(L, p);
    } else {
        if (prec -> next == nullptr) {
            p = nullptr;
            return;
        }
        p = prec -> next;
        prec -> next = p -> next;
        p -> next = nullptr;
    }
}

addressKurir findKurir(listKurir L, string namaKurir){
    addressKurir p;
    p = L.first;
    while (p != nullptr) {
        if (p -> info.namaKurir == namaKurir) {
            return p;
        }
        p = p -> next;
    }
    return nullptr;
}
