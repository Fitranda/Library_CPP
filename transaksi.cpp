#include <iostream>
#include <fstream>
#include <vector>
#include "Modul.h"

// std::vector<Anggota> AnggotaDatabase;
// std::string namaFile;
using namespace std;

void CTransaksi::tampilkanAnggota() {
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

void CTransaksi::tampilkanPeminjam() {
    if (peminjamDatabase.empty()) {
        cout << "Database Peminjam kosong.\n";
    } else {
        cout << "Daftar Peminjam:\n";
        for (size_t i = 0; i < peminjamDatabase.size(); ++i) {
            const Peminjam& peminjam = peminjamDatabase[i];
            cout << "No faktur: " << peminjam.nofaktur << " | Anggota: " << peminjam.anggota << "\n";
        }
    }

    // Menampilkan data dari file pada saat membuka program
    bacaDariFilePeminjam();
}

void CTransaksi::tampilkanBuku() {
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

void CTransaksi::bacaDariFileBuku() {
    ifstream file(filenameBuku);
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

void CTransaksi::bacaDariFileAnggota() {
    ifstream file(filenameAnggota);
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

void CTransaksi::bacaDariFilePeminjam() {
    ifstream file(filenamePeminjam);
    if (file.is_open()) {

        Peminjam peminjam;
        while (file  >> peminjam.nofaktur >> peminjam.tglpinjam >> peminjam.tglkembali >> peminjam.tglkembalireal >> peminjam.denda >> peminjam.anggota) {
            file.ignore();
            getline(file,peminjam.nofaktur,',');
            peminjamDatabase.push_back(peminjam);
        }

        file.close();
    } else {
        cout << "Gagal membuka file untuk membaca data.\n";
    }
}

void CTransaksi::bacaDariFileDetail() {
    ifstream file(filenameDetail);
    if (file.is_open()) {

        Peminjam peminjam;
        while (file >> peminjam.nofaktur >> peminjam.tglpinjam >> peminjam.tglkembali >> peminjam.tglkembalireal >> peminjam.denda >> peminjam.anggota) {
            file.ignore();
            getline(file,peminjam.nofaktur,',');
            peminjamDatabase.push_back(peminjam);
        }

        file.close();
    } else {
        cout << "Gagal membuka file untuk membaca data.\n";
    }
}

CTransaksi::CTransaksi(const std::string& filePeminjam, const std::string& fileDetail, const std::string& fileAnggota, const std::string& fileBuku)
    : filenamePeminjam(filePeminjam), filenameDetail(fileDetail), filenameAnggota(fileAnggota), filenameBuku(fileBuku) {
    // Panggil fungsi-fungsi bacaDariFile sesuai kebutuhan
    bacaDariFilePeminjam();
    bacaDariFileDetail();
    bacaDariFileAnggota();
    bacaDariFileBuku();
}

void CTransaksi::trpeminjam(){
    
    // cout <<"Buku \n";
    // tampilkanBuku();
    Peminjam peminjam;
    Detail detail;
    cout<<endl<<"Anggota \n";
    tampilkanAnggota();
    cin.ignore();
    cout <<"Masukkan nama yang dipilih :";
    getline(cin,peminjam.anggota);

    cout << "Masukkan faktur : ";
    cin >> peminjam.nofaktur;
    detail.nofaktur = peminjam.nofaktur;
    cout << "Masukkan tanggal sekarang : ";
    cin >> peminjam.tglpinjam;
    cout << "Masukkan tanggal kembali : ";
    cin >> peminjam.tglkembali;
    peminjam.denda = 0;
    peminjam.tglkembalireal = "";

    peminjamDatabase.push_back(peminjam);
    simpanKeFilePeminjam();
    
    int pilihan = 1;
    do
    {
        cout<<endl<<endl;
        cout <<"Buku";
        tampilkanBuku();
        cin.ignore();
        cout <<"Masukkan nama buku yang dipilih :";
        getline(cin,detail.buku);
        cout <<"Masukkan jumlah buku :";
        cin >> detail.jumlah;

        cout <<"apakah anda mau menambah lagi?(1.ya/2.tidak)";
        cin >> pilihan;
        detailDatabase.push_back(detail);
        simpanKeFileDetail();
    } while (pilihan == 1);
    
}

void CTransaksi::trpengembalian(){
    if (peminjamDatabase.empty()) {
        cout << "Database peminjam kosong. Tidak ada yang bisa diubah.\n";
        return;
    }

    cout << "Masukkan no faktur: ";
    string faktur;
    cin >> faktur;

    size_t i;
    for (i = 0; i < peminjamDatabase.size(); ++i) {
        if (peminjamDatabase[i].nofaktur == faktur) {
            break;
        }
    }

    if (i < peminjamDatabase.size()) {
            cout << "Masukkan tanggal kembali sebenarnya: ";
            cin >> peminjamDatabase[i].tglkembalireal;

        cout << "Anggota berhasil diubah.\n";
    } else {
        cout << "Anggota dengan ID tersebut tidak ditemukan.\n";
    }
    // Menyimpan data ke dalam file setelah mengubah Anggota
    simpanKeFilePeminjam();
}

void CTransaksi::simpanKeFilePeminjam() {
    ofstream file(filenamePeminjam);
    if (file.is_open()) {
        for (const Peminjam& peminjam : peminjamDatabase) {
            file << peminjam.nofaktur << ',' << peminjam.tglpinjam << ',' << peminjam.tglkembali<< ',' << peminjam.tglkembalireal<< ',' << peminjam.denda << ',' << peminjam.anggota << '\n';
        }
        file.close();
    } else {
        cout << "Gagal membuka file untuk penyimpanan.\n";
    }
}

void CTransaksi::simpanKeFileDetail() {
    ofstream file(filenameDetail);
    if (file.is_open()) {
        for (const Detail& detail : detailDatabase) {
            file << detail.nofaktur << ',' << detail.buku << ',' << detail.jumlah<< '\n';
        }
        file.close();
    } else {
        cout << "Gagal membuka file untuk penyimpanan.\n";
    }
}