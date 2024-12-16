//ranova.h untuk registrasi//
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
void loginpage();
int registrasiuser();
int tambah_user(char *userranova);
int tampilkan_user(char *userranova);
int mainregistrasi();

#endif
