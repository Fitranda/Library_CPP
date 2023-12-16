#include <iostream>
#include "Modul.h"
#include "buku.cpp"
#include "anggota.cpp"
#include "transaksi.cpp"
using namespace std;
int main() {
    int pil;
    string namaFilebuku = "perpus.txt";
    CBuku db(namaFilebuku);
    string namaFileanggota = "anggota.txt";
    CAnggota dbanggota(namaFileanggota);
    string namaFilepeminjam = "peminjam.txt";
    string namaFiledetail = "detail.txt";
    CTransaksi dbtrans(namaFilepeminjam,namaFiledetail,namaFileanggota,namaFiledetail);
    cout <<"Aplikasi Management Perpus";
    do
    {
        cout <<"Pilih Menu : \n";
        cout << "1. Buku \n";
        cout << "2. Anggota \n";
        cout << "3. Peminjaman Buku \n";
        cout << "4. Pengembalian Buku \n";
        cout << "5. Keluar \n";
        cout <<"Pilih Menu : ";
        cin >> pil;

        switch (pil)
        {
        case 1:
            db.menuBuku();
            break;
        
        case 2:
            dbanggota.menuAnggota();
            break;
        case 3:
            dbtrans.trpeminjam();
            break;

        case 4:
            dbtrans.trpengembalian();
            break;

        case 5:
            cout << "Keluar \n";
            break;
        
        default:
            cout << "Pilihan tidak valid.\n";
        }
    } while (pil != 5);
    
    return 0;
}