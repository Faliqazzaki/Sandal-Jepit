//ranova2.h untuk user dan admin//
#ifndef date_h
#define date_h

//kamus data//
struct User {
    char username[50];
    char password[50];
};
struct Datadiri {
    char nama[50];
    char nomortelp[50];
    int jumlahbis;
    int jumlahhari;
};
struct Bis{
	int kode, kapasitas, harga;
};

//modul//
int mainuser();
void kembalikanbus();
int sewa(const char *datadiripemesan);
int pertanyaan();
void descriptionItem(char *datadiripemesan);
int pemesanan_bis();
void tampilanadmin();
void hapus_akun();
int hapus_bis();
int tampilkan_User();
int tambah_bis();
int tampilkan_bis();
int adminPage();
int mainadmin();






#endif
