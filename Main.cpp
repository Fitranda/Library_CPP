#include <iostream>
#include "Modul.h"
#include "buku.cpp"
using namespace std;
int main() {
    int pil;
    string namaFile = "perpus.txt";
    CBuku db(namaFile);
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
        
        case 5:
            cout << "Keluar \n";
            break;
        
        default:
            cout << "Pilihan tidak valid.\n";
        }
    } while (pil != 5);
    
    return 0;
}