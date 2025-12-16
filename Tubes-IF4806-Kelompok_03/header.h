#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <iostream>
#include <string>
using namespace std;

// ADT Parent
struct elmPaket;
typedef struct elmPaket *addressPaket;

struct infotypeKurir {
    string namaKurir;
    string idKurir;
};

typedef struct elmKurir *addressKurir;

struct elmKurir {
    infotypeKurir info;
    addressKurir next;
    addressPaket firstPaket ;
};

struct listKurir {
    addressKurir first;
};

// ADT Child
struct infotypePaket {
    string namaPaket;
    string idPaket;
    string nomorResi;
    float berat;
    float harga;
    string statusPaket;

};

struct elmPaket {
    infotypePaket info;
    addressPaket next;
    addressPaket prev;
};

struct User {
    string username;
    string password;
    string role;

};

struct listPaket {
    addressPaket first;
    addressPaket last;
};

// Fungsi dan Prosedur Parent
void createListKurir(listKurir &L);
addressKurir allocateKurir(infotypeKurir x);
void insertFirstKurir(listKurir &L, addressKurir p);
void insertLastKurir(listKurir &L, addressKurir p);
void insertAfterKurir(listKurir &L, addressKurir p, addressKurir prec);
addressKurir findKurir(listKurir L, string namaKurir);
void tambahPaketKeKurir(addressKurir k, infotypePaket x);
void deleteFirstKurir(listKurir &L, addressKurir &p);
void deleteLastKurir(listKurir &L, addressKurir &p);
void deleteAfterKurir(listKurir &L, addressKurir prec, addressKurir &p);
void deleteKurirByName(listKurir &L, string namaKurir);
void deleteKurirBesertaPaket(listKurir &L, string namaKurir);
void printKurir(listKurir L);
void printPaketKurir(addressKurir k);

// Fungsi dan Prosedur Child
void createListPaket(addressKurir &K);
bool isEmptyPaket(addressKurir K);
addressPaket allocatePaket(infotypePaket x);
void insertFirstPaket(addressKurir&K, addressPaket p);
void insertLastPaket(addressKurir &K, addressPaket p);
void insertAfterPaket(addressKurir &K, addressPaket p, addressPaket prec);
void deleteFirstPaket(addressKurir &K, addressPaket &p);
void deleteLastPaket(addressKurir &K, addressPaket &p);
void deleteAfterPaket(addressKurir &K, addressPaket &p, addressPaket prec);
void deletePaketByName(addressKurir &K, string namaPaket);
void printPaket(addressKurir K);
void printTotalPaket(listKurir L);
addressPaket findPaket(addressKurir K, string namaPaket);
void updateStatusPaket(addressKurir K, string namaPaket, string statusBaru);
addressPaket findPaketByResi(listKurir L, string resi);
float hitungHarga(float berat);

#endif // HEADER_H_INCLUDED
