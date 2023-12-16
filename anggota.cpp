#include <iostream>
#include <fstream>
#include <vector>
#include "Modul.h"

// std::vector<Anggota> AnggotaDatabase;
// std::string namaFile;
using namespace std;


void CAnggota::tambahAnggota() {
    Anggota anggota;
    cout << "Masukkan ID anggota: ";
    cin >> anggota.id;
    cin.ignore(); 
    cout << "Masukkan nama anggota: ";
    getline(cin, anggota.nama);

    anggotaDatabase.push_back(anggota);

    cout << "Anggota berhasil ditambahkan.\n";

    // Menyimpan data ke dalam file setelah menambah Anggota
    simpanKeFileAnggota();
}

void CAnggota::tampilkanAnggota() {
    if (anggotaDatabase.empty()) {
        cout << "Database Anggota kosong.\n";
    } else {
        cout << "Daftar Anggota:\n";
        for (size_t i = 0; i < anggotaDatabase.size(); ++i) {
            const Anggota& Anggota = anggotaDatabase[i];
            cout << "ID: " << Anggota.id << " | Nama: " << Anggota.nama << "\n";
        }
    }

    // Menampilkan data dari file pada saat membuka program
    bacaDariFileAnggota();
}

void CAnggota::ubahAnggota() {
    if (anggotaDatabase.empty()) {
        cout << "Database Anggota kosong. Tidak ada yang bisa diubah.\n";
        return;
    }

    cout << "Masukkan ID Anggota yang ingin diubah: ";
    int idAnggota;
    cin >> idAnggota;

    size_t i;
    for (i = 0; i < anggotaDatabase.size(); ++i) {
        if (anggotaDatabase[i].id == idAnggota) {
            break;
        }
    }

    if (i < anggotaDatabase.size()) {
        cout << "Pilih bagian yang ingin diubah (id/nama): ";
        string bagian;
        cin >> bagian;

        if (bagian == "id") {
            cout << "Masukkan ID baru: ";
            cin >> anggotaDatabase[i].id;
        } else if (bagian == "nama") {
            cout << "Masukkan nama baru: ";
            cin.ignore();
            getline(cin, anggotaDatabase[i].nama);
        } else {
            cout << "Bagian tidak valid.\n";
        }

        cout << "Anggota berhasil diubah.\n";
    } else {
        cout << "Anggota dengan ID tersebut tidak ditemukan.\n";
    }
    // Menyimpan data ke dalam file setelah mengubah Anggota
    simpanKeFileAnggota();
}

void CAnggota::hapusAnggota() {
    if (anggotaDatabase.empty()) {
        cout << "Database Anggota kosong. Tidak ada yang bisa dihapus.\n";
        return;
    }

    cout << "Masukkan ID Anggota yang ingin dihapus: ";
    int idAnggota;
    cin >> idAnggota;

    size_t i;
    for (i = 0; i < anggotaDatabase.size(); ++i) {
        if (anggotaDatabase[i].id == idAnggota) {
            break;
        }
    }

    if (i < anggotaDatabase.size()) {
        anggotaDatabase.erase(anggotaDatabase.begin() + i);
        cout << "Anggota berhasil dihapus.\n";
    } else {
        cout << "Anggota dengan ID tersebut tidak ditemukan.\n";
    }

    // Menyimpan data ke dalam file setelah menghapus Anggota
    simpanKeFileAnggota();
}

void CAnggota::simpanKeFileAnggota() {
    ofstream file(namaFile);
    if (file.is_open()) {
        for (const Anggota& Anggota : anggotaDatabase) {
            file << Anggota.id << ',' << Anggota.nama << '\n';
        }
        file.close();
    } else {
        cout << "Gagal membuka file untuk penyimpanan.\n";
    }
}

void CAnggota::bacaDariFileAnggota() {
    ifstream file(namaFile);
    if (file.is_open()) {

        Anggota Anggota;
        while (file >> Anggota.id) {
            file.ignore();
            getline(file,Anggota.nama,',');
            anggotaDatabase.push_back(Anggota);
        }

        file.close();
    } else {
        cout << "Gagal membuka file untuk membaca data.\n";
    }
}

CAnggota::CAnggota(const std::string& filename) : namaFile(filename) {
    // Membaca data dari file saat program dibuka
    // simpanKeFileAnggota();
    bacaDariFileAnggota();
}

void CAnggota::menuAnggota(){
    // string namaFile = "perpus.txt";
    // CAnggota db(namaFile);

    int pilihan;
    do {
        cout << "\nMenu :\n";
        cout << "1. Tambah Anggota\n";
        cout << "2. Tampilkan Anggota\n";
        cout << "3. Ubah Anggota\n";
        cout << "4. Hapus Anggota\n";
        cout << "5. Kembali\n";
        cout << "Pilih menu (1-5): ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                tambahAnggota();
                break;
            case 2:
                tampilkanAnggota();
                break;
            case 3:
                ubahAnggota();
                break;
            case 4:
                hapusAnggota();
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