#include <iostream>
#include "kurir.h"
#include "paket.h"
using namespace std;

int main() {

    listKurir LK;
    createListKurir(LK);

    int pilihan;

    while (pilihan != 0) {
        cout << "\n----- MENU -----\n";
        cout << "1. Tambah Kurir\n";
        cout << "2. Tampilkan Semua Kurir\n";
        cout << "3. Tambah Paket ke Kurir\n";
        cout << "4. Tampilkan Paket milik Kurir\n";
        cout << "0. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        if (pilihan == 1) {

            infotypeKurir K;

            cout << "Masukkan nama kurir (tanpa spasi): ";
            cin >> K.namaKurir;

            cout << "Masukkan ID kurir (tanpa spasi): ";
            cin >> K.idKurir;

            addressKurir p = allocateKurir(K);
            insertLastKurir(LK, p);

            cout << "Kurir berhasil ditambahkan.\n";
        }

        else if (pilihan == 2) {
            cout << "\n--- Daftar Kurir ---\n";
            printKurir(LK);
        }

        else if (pilihan == 3) {
            string nama;
            cout << "Masukkan nama kurir (tanpa spasi): ";
            cin >> nama;

            addressKurir k = findKurir(LK, nama);
            if (k == NULL) {
                cout << "Kurir tidak ditemukan!\n";
            } else {
                infotypePaket P;

                cout << "Masukkan nama paket (tanpa spasi): ";
                cin >> P.namaPaket;

                cout << "Masukkan ID paket (tanpa spasi): ";
                cin >> P.idPaket;

                tambahPaketKeKurir(k, P);
                cout << "Paket berhasil ditambahkan.\n";
            }
        }

        else if (pilihan == 4) {
            string nama;
            cout << "Masukkan nama kurir (tanpa spasi): ";
            cin >> nama;

            addressKurir k = findKurir(LK, nama);
            if (k == NULL) {
                cout << "Kurir tidak ditemukan!\n";
            } else {
                cout << "\n--- Paket milik kurir " << k->info.namaKurir << " ---\n";
                printPaketKurir(k);
            }
        }

    };

    cout << "Selamat Tinggal Terima Kasih!.\n";
    return 0;
}
