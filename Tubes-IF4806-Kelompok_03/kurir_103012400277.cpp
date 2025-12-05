#include "kurir.h"
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
