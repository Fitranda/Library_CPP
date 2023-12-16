#include <iostream>
#include <fstream>
#include <vector>
#include "Modul.h"

// std::vector<Buku> bukuDatabase;
// std::string namaFile;
using namespace std;


void CBuku::tambahBuku() {
    Buku buku;
    cout << "Masukkan ID buku: ";
    cin >> buku.id;
    cin.ignore(); 
    cout << "Masukkan nama buku: ";
    getline(cin, buku.nama);
    cout << "Masukkan jumlah buku yang ditambahkan: ";
    cin >> buku.jumlah;

    bukuDatabase.push_back(buku);

    cout << "Buku berhasil ditambahkan.\n";

    // Menyimpan data ke dalam file setelah menambah buku
    simpanKeFileBuku();
}

void CBuku::tampilkanBuku() {
    if (bukuDatabase.empty()) {
        cout << "Database buku kosong.\n";
    } else {
        cout << "Daftar Buku:\n";
        for (size_t i = 0; i < bukuDatabase.size(); ++i) {
            const Buku& buku = bukuDatabase[i];
            cout << "ID: " << buku.id << " | Nama: " << buku.nama << " | Jumlah: " << buku.jumlah << "\n";
        }
    }

    // Menampilkan data dari file pada saat membuka program
    bacaDariFileBuku();
}

void CBuku::ubahBuku() {
    if (bukuDatabase.empty()) {
        cout << "Database buku kosong. Tidak ada yang bisa diubah.\n";
        return;
    }

    cout << "Masukkan ID buku yang ingin diubah: ";
    int idBuku;
    cin >> idBuku;

    size_t i;
    for (i = 0; i < bukuDatabase.size(); ++i) {
        if (bukuDatabase[i].id == idBuku) {
            break;
        }
    }

    if (i < bukuDatabase.size()) {
        cout << "Pilih bagian yang ingin diubah (id/nama/jumlah): ";
        string bagian;
        cin >> bagian;

        if (bagian == "id") {
            cout << "Masukkan ID baru: ";
            cin >> bukuDatabase[i].id;
        } else if (bagian == "nama") {
            cout << "Masukkan nama baru: ";
            cin.ignore();
            getline(cin, bukuDatabase[i].nama);
        } else if (bagian == "jumlah") {
            cout << "Masukkan jumlah baru: ";
            cin >> bukuDatabase[i].jumlah;
        } else {
            cout << "Bagian tidak valid.\n";
        }

        cout << "Buku berhasil diubah.\n";
    } else {
        cout << "Buku dengan ID tersebut tidak ditemukan.\n";
    }
    // Menyimpan data ke dalam file setelah mengubah buku
    simpanKeFileBuku();
}

void CBuku::hapusBuku() {
    if (bukuDatabase.empty()) {
        cout << "Database buku kosong. Tidak ada yang bisa dihapus.\n";
        return;
    }

    cout << "Masukkan ID buku yang ingin dihapus: ";
    int idBuku;
    cin >> idBuku;

    size_t i;
    for (i = 0; i < bukuDatabase.size(); ++i) {
        if (bukuDatabase[i].id == idBuku) {
            break;
        }
    }

    if (i < bukuDatabase.size()) {
        bukuDatabase.erase(bukuDatabase.begin() + i);
        cout << "Buku berhasil dihapus.\n";
    } else {
        cout << "Buku dengan ID tersebut tidak ditemukan.\n";
    }

    // Menyimpan data ke dalam file setelah menghapus buku
    simpanKeFileBuku();
}

void CBuku::simpanKeFileBuku() {
    ofstream file(namaFile);
    if (file.is_open()) {
        for (const Buku& buku : bukuDatabase) {
            file << buku.id << ',' << buku.nama << ',' << buku.jumlah << '\n';
        }
        file.close();
    } else {
        cout << "Gagal membuka file untuk penyimpanan.\n";
    }
}

void CBuku::bacaDariFileBuku() {
    ifstream file(namaFile);
    if (file.is_open()) {

        Buku buku;
        while (file >> buku.id) {
            file.ignore();
            getline(file,buku.nama,',');
            file >> buku.jumlah;
            bukuDatabase.push_back(buku);
        }

        file.close();
    } else {
        cout << "Gagal membuka file untuk membaca data.\n";
    }
}

CBuku::CBuku(const std::string& filename) : namaFile(filename) {
    // Membaca data dari file saat program dibuka
    // simpanKeFileBuku();
    bacaDariFileBuku();
}

void CBuku::menuBuku(){
    // string namaFile = "perpus.txt";
    // CBuku db(namaFile);

    int pilihan;
    do {
        cout << "\nMenu :\n";
        cout << "1. Tambah Buku\n";
        cout << "2. Tampilkan Buku\n";
        cout << "3. Ubah Buku\n";
        cout << "4. Hapus Buku\n";
        cout << "5. Kembali\n";
        cout << "Pilih menu (1-5): ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                tambahBuku();
                break;
            case 2:
                tampilkanBuku();
                break;
            case 3:
                ubahBuku();
                break;
            case 4:
                hapusBuku();
                break;
            case 5:
                cout << "Kembali.\n";
                break;
            default:
                cout << "Pilihan tidak valid. Masukkan pilihan 1-5.\n";
                break;
        }

    } while (pilihan != 5);
}