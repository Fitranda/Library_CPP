#ifndef MODUL_H
#define MODUL_H
#include <string>
#include <vector>


void menuAnggota();
void menuPeminjaman();
void menuPengembalian();
// struct
struct Buku{
    int id;
    std::string nama;
    int jumlah;
};
struct anggota{
    int id;
    std::string nama;
};
struct peminjam{
    int id;
    std::string tglpinjam;
    std::string tglkembali;
    std::string tglkembalireal;
    int denda;
    int idanggota;
};
struct detail{
    int id;
    int iddetail;
    int idbuku;
    int jumlah;
};

class CBuku
{
private:
    std::vector<Buku> bukuDatabase;
    std::string namaFile;
public:
    CBuku(const std::string& filename);
    // ~CBuku();
    // buku
    void tambahBuku(); 
    void tampilkanBuku();
    void ubahBuku(); 
    void hapusBuku(); 
    void simpanKeFileBuku();
    void bacaDariFileBuku();
    void menuBuku();
};



#endif
