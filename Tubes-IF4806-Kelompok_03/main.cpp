#include <iostream>
#include "header.h"
using namespace std;

int main() {

    listKurir LK;
    createListKurir(LK);

    int menu = -1;
    while (menu != 0){
        cout << "===== LOGIN =====\n";
        cout << "1. Masuk sebagai Admin\n";
        cout << "2. Masuk sebagai User\n";
        cout << "0. Keluar Program\n";
        cout << "Pilih: ";
        cin >> menu;

    if (menu == 1) {
        int pilihan = -1;
        while (pilihan != 0) {
            cout << "\n----- MENU ADMIN -----\n";
           cout << "1. Tambah Kurir (insertLast)\n";
            cout << "2. Tampilkan Semua Kurir\n";
            cout << "3. Tambah Paket ke Kurir (insertLast paket)\n";
            cout << "4. Tampilkan Paket milik Kurir\n";
            cout << "5. Tampilkan Semua Paket\n";
            cout << "6. Hapus Kurir (tanpa paket)\n";
            cout << "7. Hapus Kurir beserta paketnya\n";
            cout << "8. Hapus Paket dari Kurir tertentu\n";
            cout << "9. Tambah Kurir (insertFirst)\n";
            cout << "10. Insert Kurir setelah Kurir tertentu\n";
            cout << "11.Update status paket\n";
            cout << "0. kembali ke halaman utama\n";

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
            }else if (pilihan == 2) {
                if (LK.first == nullptr){
                    cout << "Belum ada kurir yang terdaftarkan.\n";
                }else{
                    cout << "\n--- Daftar Kurir ---\n";
                    printKurir(LK);
                }
            }else if (pilihan == 3) {
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
                    cout << "Nomor Resi: ";
                    cin >> P.nomorResi;

                    P.harga = hitungHarga(P.berat);
                    P.statusPaket = "Dikemas";

                    tambahPaketKeKurir(k, P);
                    cout << "Paket berhasil ditambahkan.\n";
                    cout << "Harga paket: " << P.harga << endl;
                }
            }else if (pilihan == 4) {
                string nama;
                cout << "Masukkan nama kurir (tanpa spasi): ";
                cin >> nama;

                addressKurir k = findKurir(LK, nama);
                if (k == nullptr) {
                    cout << "Kurir tidak ditemukan!\n";
                }else {
                    cout << "\n--- Paket milik kurir " << k->info.namaKurir << " ---\n";
                    printPaketKurir(k);
                }
            }else if (pilihan == 5){
                if (LK.first == nullptr){
                    cout << "Belum ada paket yang terdaftar.\n";
                } else {
                    cout << "\n--- Daftar Paket ---\n";
                    printTotalPaket(LK);
                }
            }else if (pilihan == 6) {
                string nama;
                cout << "Masukkan nama kurir: ";
                cin >> nama;
                deleteKurirByName(LK, nama);
            }else if (pilihan == 7) {
                string nama;
                cout << "Masukkan nama kurir: ";
                cin >> nama;
                deleteKurirBesertaPaket(LK, nama);
            }else if (pilihan == 8) {
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
            }else if (pilihan == 9) {
                infotypeKurir K;
                cout << "Masukkan nama kurir (tanpa spasi): ";
                cin >> K.namaKurir;
                cout << "Masukkan ID kurir (tanpa spasi): ";
                cin >> K.idKurir;
                addressKurir p = allocateKurir(K);
                insertFirstKurir(LK, p);
                cout << "Kurir berhasil ditambahkan (insertFirst).\n";
            }else if (pilihan == 10) {
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
             }else if (pilihan == 11) {
                string kurir, paket, status;
                int x;
                cout << "Nama Kurir: ";
                cin >> kurir;
                cout << "Nama Paket: ";
                cin >> paket;

                cout << "Pilih Status Baru:\n";
                cout << "1. Dikemas\n";
                cout << "2. Dikirim\n";
                cout << "3. Sampai\n";
                cout << "Pilih: ";
                cin >> x;

                if (x == 1) {
                    status = "Dikemas";
                } else if (x == 2) {
                    status = "Dikirim";
                } else if (x == 3) {
                    status = "Sampai";
                } else {
                    cout << "Pilihan status tidak valid.\n";
                    status = "";
                }

                if (status != "") {
                    addressKurir k = findKurir(LK, kurir);
                    if (k != nullptr) {
                        updateStatusPaket(k, paket, status);
                    } else {
                        cout << "Kurir tidak ditemukan.\n";
                    }
                }
            }
        }

    }else if (menu == 2) {
        int pilihUser = -1;
        while (pilihUser != 0) {
            cout << "\n--- MENU USER ---\n";
            cout << "1. Cek Paket\n";
            cout << "0. Keluar\n";
            cout << "pilih : ";
            cin >> pilihUser;

            if (pilihUser == 1) {
                string resi;
                cout << "Masukkan Nomor Resi: ";
                cin >> resi;

                addressPaket p = findPaketByResi(LK, resi);
                if (p != nullptr) {
                    cout << "Nama Paket : " << p->info.namaPaket << endl;
                    cout << "Status     : " << p->info.statusPaket << endl;
                    cout << "Harga      : " << p->info.harga << endl;
                    cout << "Resi       : " << p->info.nomorResi << endl;
                }else {
                    cout << "Resi tidak ditemukan.\n";
                }
            }

        }
        cout << "Selamat Tinggal Terima Kasih!.\n";
    }
    }
     return 0;

}
