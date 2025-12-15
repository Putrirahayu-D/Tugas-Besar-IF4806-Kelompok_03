//main.cpp
#include <iostream>
#include "header.h"
using namespace std;

int main() {

    listKurir LK;
    createListKurir(LK);

    int pilihan = -1;

    while (pilihan != 0) {
        cout << "\n----- MENU -----\n";
        cout << "1. Tambah Kurir (insertLast)\n";
        cout << "2. Tampilkan Semua Kurir\n";
        cout << "3. Tambah Paket ke Kurir (insertLast paket)\n";
        cout << "4. Tampilkan Paket milik Kurir\n";
        cout << "5. Hapus Kurir (tanpa paket)\n";
        cout << "6. Hapus Kurir beserta paketnya\n";
        cout << "7. Hapus Paket dari Kurir tertentu\n";
        cout << "8. Tambah Kurir (insertFirst)\n";
        cout << "9. Insert Kurir setelah Kurir tertentu\n";
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
            cout << "Kurir berhasil ditambahkan (insertLast).\n";
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
    if (k == nullptr) {
        cout << "Kurir tidak ditemukan!\n";
    }else {
        infotypePaket P;
        cout << "Masukkan nama paket (tanpa spasi): ";
        cin >> P.namaPaket;
        cout << "Masukkan ID paket (tanpa spasi): ";
        cin >> P.idPaket;
        cout << "Masukkan berat paket (kg): ";
        cin >> P.berat;

        P.harga = hitungHarga(P.berat);
        P.statusPaket = "Dalam Perjalanan";

        tambahPaketKeKurir(k, P);
        cout << "Paket berhasil ditambahkan.\n";
        cout << "Harga paket: " << P.harga << endl;
    }
}

        else if (pilihan == 4) {
            string nama;
            cout << "Masukkan nama kurir (tanpa spasi): ";
            cin >> nama;

            addressKurir k = findKurir(LK, nama);
            if (k == nullptr) {
                cout << "Kurir tidak ditemukan!\n";
            } else {
                cout << "\n--- Paket milik kurir " << k->info.namaKurir << " ---\n";
                printPaketKurir(k);
            }
        }
        else if (pilihan == 5) {
            string nama;
            cout << "Masukkan nama kurir: ";
            cin >> nama;
            deleteKurirByName(LK, nama);
        }
        else if (pilihan == 6) {
            string nama;
            cout << "Masukkan nama kurir: ";
            cin >> nama;
            deleteKurirBesertaPaket(LK, nama);
        }
        else if (pilihan == 7) {
            string nama;
            cout << "Masukkan nama kurir: ";
            cin >> nama;

            addressKurir k = findKurir(LK, nama);
            if (k == nullptr) {
                cout << "Kurir tidak ditemukan!\n";
            } else {
                string paket;
                cout << "Masukkan nama paket: ";
                cin >> paket;
                deletePaketByName(k, paket);
                cout << "Paket berhasil dihapus (jika ada).\n";
            }
        }else if (pilihan == 8) {
            infotypeKurir K;
            cout << "Masukkan nama kurir (tanpa spasi): ";
            cin >> K.namaKurir;
            cout << "Masukkan ID kurir (tanpa spasi): ";
            cin >> K.idKurir;
            addressKurir p = allocateKurir(K);
            insertFirstKurir(LK, p);
            cout << "Kurir berhasil ditambahkan (insertFirst).\n";
        }else if (pilihan == 9) {
            string target;
            cout << "Masukkan nama kurir yang ingin disisipi setelahnya: ";
            cin >> target;

            infotypeKurir K;
            cout << "Nama kurir baru: ";
            cin >> K.namaKurir;
            cout << "ID kurir baru: ";
            cin >> K.idKurir;

            addressKurir p = allocateKurir(K);
            addressKurir prec = findKurir(LK, target);

            if (prec != nullptr) {
            insertAfterKurir(LK, p, prec);
            } else {
                cout << "Kurir target tidak ditemukan!\n";
            }
            cout << "Insert setelah kurir " << target << " selesai (jika target ada).\n";
        }

    }

    cout << "Selamat Tinggal Terima Kasih!.\n";
    return 0;
}
