//user.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "ranova2.h"

void descriptionItem(char *datadiripemesan) {
    struct Datadiri data;
    FILE *file = fopen("datadiripemesan.txt", "r");
    if (file == NULL) {
        printf("Gagal membuka file: %s\n", datadiripemesan);
        return;
    }

    while (fscanf(file, "%49s %14s %d %d", data.nama, data.nomortelp, &data.jumlahbis, &data.jumlahhari) == 4) {
    }
    fclose(file);

    system("cls");

    printf("======= KONFIRMASI PEMESANAN =======\n");
    printf("Nama Pemesan: %s\n", data.nama);
    printf("Nomor Telepon: %s\n", data.nomortelp);
    printf("Total Bis: %d buah\n", data.jumlahbis);
    printf("Hari: %d hari\n", data.jumlahhari);
}

int pertanyaan() {
    char responpertanyaan;
    printf("\nApakah ada hal lain yang bisa Ranova bantu? (y/t): ");
    scanf(" %c", &responpertanyaan);   
    if (responpertanyaan == 'y') {
        system("cls");
        return 1;
    } else if (responpertanyaan == 't') {
    	system("cls");
        loginpage();
        printf("Terimakasih telah menggunakan layanan Ranova\n");
        exit(0);
    } else {
        printf("Pilihan tidak valid. Silakan coba lagi.\n");
    }
    return 0;
}


int sewa(const char *datadiripemesan) {	
    struct Datadiri data;

    FILE *file = fopen("datadiripemesan.txt", "a");
    if (file == NULL) {
        perror("Gagal membuka file untuk menambah user");
        return;
    }
    system("cls");
	printf("=======PENYEWAAN=======\n");
    printf("Masukkan Nama Pemesan: ");
    scanf("%s", data.nama);
    printf("Masukkan Nomor Telepon: ");
    scanf("%s", data.nomortelp);
	int bis, harga, hari, totalbis, totalharga;
	char respon;		
	printf("Bis apa yang ingin kamu pesan?\n");
	printf("Kode Bus\tKapasitas Bus\tHarga Bus (dalam juta)\n");
	FILE *b=fopen("databaseranova.txt", "r");
	char line[250];
	while (fgets(line, sizeof(line), b)){
		struct Bis bis;
		sscanf(line, "%d%d%d", &bis.kode, &bis.kapasitas, &bis.harga);
		printf("%d\t\t%d\t\t\t%d\n", bis.kode, bis.kapasitas, bis.harga);
	}
	fclose(b);
	printf("\n1. Big Bus\n2. Medium Bus\n3. Elf\n");
	printf("Catatan: size bis tergantung kapasitasnya\n");
	printf("Big Bus=60, Medium Bus=40, Elf=20\n");		
	printf("Masukkan kebutuhan: ");
	scanf("%d", &bis);
	if (bis==1){
		printf("Harga = Rp 15.000.000/hari");
		harga=15000000;
	} else if(bis==2){
		printf("Harga = Rp 10.000.000/hari");
		harga=10000000;
	} else if(bis==3){
		printf("Harga = Rp 7.000.000/hari");
		harga=7000000;
	}
	system("cls");
	printf("=======PENYEWAAN=======\n");		
	printf("Butuh berapa bis?\n");
	printf("Masukkan kebutuhan: ");		
	scanf("%d", &totalbis);
	data.jumlahbis=totalbis;
	harga=harga*totalbis;
	printf("Mau sekalian dengan supir, solar, dan lain-lain?(y/t)\n");
	printf("Masukkan keinginan: ");	
	scanf(" %c", &respon);
	if (respon == 'y'){
		harga=harga+(harga*0.15);
	} else {
		harga=harga;
	}
	printf("Mau berapa hari?\n");
	printf("Masukkan kebutuhan: ");			
	scanf(" %d", &hari);
	data.jumlahhari=hari;
	totalharga=harga*hari;
    
    fprintf(file, "%s %s %d %d\n", data.nama, data.nomortelp, data.jumlahbis, data.jumlahhari);
    fclose(file);
    
	descriptionItem("datadiripemesan.txt");
	printf("Total harga: Rp %d", totalharga);
    sleep(2);
	
	return 0;   	    
}

void kembalikanbus() {
    char lines[100][100]; 
    int line_count = 0;
    char nama_yang_dicari[100];
    int i = 0;
    int ditemukan = 0; 
    FILE *file;

    file = fopen("datadiripemesan.txt", "r");
    if (file == NULL) {
        perror("Gagal membuka file untuk membaca data");
        return;
    }

    while (fgets(lines[line_count], sizeof(lines[line_count]), file) != NULL) {
        line_count++;
    }
    fclose(file);

    system("cls");
    printf("======= KONFIRMASI PENGEMBALIAN =======\n");
    printf("\nMasukkan nama pemesan bis yang ingin dikembalikan: ");
    scanf(" %[^\n]", nama_yang_dicari);

    file = fopen("datadiripemesan.txt", "w");
    if (file == NULL) {
        perror("Error: Tidak dapat membuka file");
        return;
    }

    for (i = 0; i < line_count; i++) {
        if (strstr(lines[i], nama_yang_dicari) == NULL) {
            fputs(lines[i], file);  
        } else {
            ditemukan = 1; 
        }
    }
    fclose(file);

    if (ditemukan) {
        printf("Terimakasih %s telah menggunakan jasa Bis Ranova.\n", nama_yang_dicari);
    } else {
        printf("Data pemesanan atas nama %s tidak ditemukan.\n", nama_yang_dicari);
    }
}

int mainuser() {
    for (;;) {
        system("cls");
        char loggedInUser[50];        
        int pilihanmainuser, pilihanuser;

        loginpage();
        printf("Selamat datang di penyewaan bis Ranova!!\n");
        printf("1. Register\n2. Login\n3. Keluar\n");
        printf("Masukkan pilihanmu: ");
        scanf("%d", &pilihanmainuser);

        switch (pilihanmainuser) {
            case 1:
                registrasiuser(); 
                break;
            case 2:
                if (loginuser("userranova.txt", loggedInUser)) {
                    printf("\nLogin berhasil! Halo, %s!\n", loggedInUser);
                    sleep(2);
                    system("cls");
                    do {
                        loginpage();
                        printf("Apa yang bisa Ranova bantu?\n");
                        printf("1. Menyewa Bus\n2. Mengembalikan Bus\n");
                        printf("Masukkan pilihan: ");
                        scanf("%d", &pilihanuser);
                        if (pilihanuser == 1) {
                            sewa("datadiripemesan.txt");
                            pertanyaan();
                        } else if (pilihanuser == 2) {
                            kembalikanbus();
                            pertanyaan();
                        } else {
                            printf("Pilihan tidak valid. Silakan coba lagi.\n");
                        }
                    } while (pilihanuser != 1 && pilihanuser != 2);
                } else {
                    printf("Anda telah gagal login sebanyak 3 kali. Akses ditolak.\n");
                    return 0;
                }
                break;
            case 3:
                system("cls");
                loginpage();
                printf("Terimakasih telah menggunakan layanan Ranova\n");
                exit(0);
            default:
                printf("Pilihan tidak valid. Silakan coba lagi.\n");
        }
    }
}
