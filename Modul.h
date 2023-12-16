#ifndef MODUL_H
#define MODUL_H
#include <string>
#include <vector>


// struct
struct Buku{
    int id;
    std::string nama;
    int jumlah;
};
struct Anggota{
    int id;
    std::string nama;
};
struct Peminjam{
    std::string nofaktur;
    std::string tglpinjam;
    std::string tglkembali;
    std::string tglkembalireal;
    int denda;
    std::string anggota;
};
struct Detail{
    std::string nofaktur;
    std::string buku;
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

class CAnggota
{
private:
    std::vector<Anggota> anggotaDatabase;
    std::string namaFile;
public:
    CAnggota(const std::string& filename);
    void tambahAnggota(); 
    void tampilkanAnggota();
    void ubahAnggota(); 
    void hapusAnggota(); 
    void simpanKeFileAnggota();
    void bacaDariFileAnggota();
    void menuAnggota();
};

class CTransaksi
{
private:
    std::vector<Peminjam> peminjamDatabase;
    std::vector<Detail> detailDatabase;
    std::vector<Anggota> anggotaDatabase;
    std::vector<Buku> bukuDatabase;
    std::string filenamePeminjam;
    std::string filenameDetail;
    std::string filenameAnggota;
    std::string filenameBuku;
public:
    CTransaksi(const std::string& filenamepeminjam,const std::string& filenamedetail,const std::string& filenameanggota,const std::string& filenamebuku);
    void trpeminjam();
    void trpengembalian();
    void bacaDariFileAnggota();
    void bacaDariFileBuku();
    void bacaDariFilePeminjam();
    void bacaDariFileDetail();
    void tampilkanAnggota();
    void tampilkanBuku();
    void tampilkanPeminjam();
    void simpanKeFilePeminjam();
    void simpanKeFileDetail();
};

#endif
