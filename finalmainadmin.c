//admin.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "ranova2.h"

void tampilanadmin() {
    printf("\n");
    printf("===============================================================\n");
    printf("||                                                           ||\n");
    printf("||                      ADMIN RANOVA                         ||\n");
    printf("||                                                           ||\n");
    printf("===============================================================\n");
    printf("\n");
}

void hapus_akun(){
	char lines[200][200];
    int line_count = 0;
    int line_to_delete;
	int i = 0;
	FILE *file;
	
	file = fopen("userranova.txt", "r");
    if (file == NULL) {
        perror("Gagal membuka file untuk membaca user");
    }
   
    while (fgets(lines[line_count], 200, file) != NULL) {
        printf("%d.\t%s", line_count + 1, lines[line_count]);
        line_count++;
    }
    fclose(file);
	printf("\nMasukkan nomor baris yang ingin dihapus (1 - %d): ", line_count);
		scanf("%d", &line_to_delete);
    	if (line_to_delete < 1 || line_to_delete > line_count) {
        	printf("Nomor baris tidak valid.\n");
        	hapus_akun();
    	}
		file = fopen("userranova.txt", "w");
		
    	if (file == NULL) {
        	printf("Error: Tidak dapat membuka file\n");
    	}

    	while(i<line_count) {
        	if (i != line_to_delete - 1) { 
            	fputs(lines[i], file);
        	}
        	i++;
    	}
    	fclose(file);	
}

int hapus_bis(){
	tampilanadmin();
	printf("\nDaftar Bis:\n");
    printf("No. \tKode Bis\t\t   Kapasitas\t\tHarga (juta))\n");
    printf("===============================================================\n");
	char lines[200][200];
    int line_count = 0;
    int line_to_delete;
	int i = 0;
	FILE *file;
	int userDecision;
	
	file = fopen("databaseranova.txt", "r");
    if (file == NULL) {
        perror("Gagal membuka file untuk membaca user");
    }
   
    while (fgets(lines[line_count], 200, file) != NULL) {
        
        printf("%d.\t%s", line_count + 1, lines[line_count]);
        line_count++;
    }
    fclose(file);
	printf("\nMasukkan nomor baris yang ingin dihapus (1 - %d): ", line_count);
		scanf("%d", &line_to_delete);
    	if (line_to_delete < 1 || line_to_delete > line_count) {
        	printf("Nomor baris tidak valid.\n");
        	hapus_akun();
    	}
		file = fopen("databaseranova.txt", "w");
		
    	if (file == NULL) {
        	printf("Error: Tidak dapat membuka file\n");
    	}

    	while(i<line_count) {
        	if (i != line_to_delete - 1) { 
            	fputs(lines[i], file);
        	}
        	i++;
    	}
    	fclose(file);
		
		sleep(3);
		printf("Data bis sudah dihapus.\n");
		system("cls");
		printf("1.Kembali\n");
		printf("masukkan pilihan anda : ");
		scanf("%d", &userDecision);
		if(userDecision == 1){
			return 0;
		}
}

int tampilkan_User(){
	int userDecisionBack;
	struct User user;
	
	FILE *file = fopen("userranova.txt", "r");
    if (file == NULL) {
        perror("Gagal membuka file untuk membaca user");
        return;
    }

    printf("\nDaftar User:\n");
    printf("Username\tPassword\n");
    printf("=============================\n");
	
    while (fscanf(file, "%49s %49s", user.username, user.password) != EOF) {
    	printf("%-15s %-15s\n", user.username, user.password);
	}
    
    fclose(file);
    
	printf("\n1.Hapus Akun\n2.Kembali\n");
	printf("Masukkan pilihan anda :");
	scanf("%d", &userDecisionBack);
	if(userDecisionBack == 1){
		hapus_akun();
		printf("Akun sudah dihapus.");
		printf(" Ketik 1 untuk kembali ke menu admin: ");
		scanf("%d", &userDecisionBack);
		if(userDecisionBack = 1){
			system("cls");
			tampilkan_User();
		}
	}else if(userDecisionBack == 2){
		system("cls");
		return 0;
	}else{
		printf("\n - pilihan tidak valid -");
		return 1;
	}	
}

int tambah_bis(){
		tampilanadmin();
		struct Bis bis;
		int jenis_bis;
		int kapasitas;
		int kode_bis;
		int decisionAdmin;
		int harga;
		
		FILE *file;
		file = fopen("databaseranova.txt", "a");
		if(file == NULL){
			printf("File tidak ada");
		}
		printf("masukkan kode bis : ");
		scanf("%d", &kode_bis);
		bis.kode = kode_bis;
		system("cls");
		tampilanadmin();
		printf("\nJenis Bis : \n1.Big Bus\n2.Medium\n3.Elf\n");
		printf("Masukkan jenis Bis : ");
		scanf("%d", &jenis_bis);
		if(jenis_bis == 1){
			kapasitas = 60;
			harga = 15;
		}else if(jenis_bis == 2){
			kapasitas = 40;
			harga = 10;
		}else if(jenis_bis == 3){
			kapasitas = 20;
			harga = 7;
		}
		
		bis.kapasitas = kapasitas;
		bis.harga = harga;
		fprintf(file,"\n    %d\t\t\t\t%d\t\t %d", bis.kode , bis.kapasitas, bis.harga);
		sleep(1);
		printf("Bis telah ditambahkan.");
		fclose(file);
		sleep(1);
		printf("\n\nKetik 1 untuk kembali : ");
		scanf("%d", &decisionAdmin);
		if(decisionAdmin == 1){
			system("cls");
			return 0;
		}
	return 0;				
}

int tampilkan_bis(){
	printf("\nDaftar Bis:\n");
    printf("Kode Bis\tKapasitas\t\tHarga (juta))\n");
    printf("====================================================\n");	

	FILE *b=fopen("databaseranova.txt", "r");
	char line[250];
	int decisionAdmin;
	
	while (fgets(line, sizeof(line), b)){
		struct Bis bis;
		sscanf(line, "%d%d%d", &bis.kode, &bis.kapasitas, &bis.harga);
		printf("%d\t\t%d\t\t\t%d\n", bis.kode, bis.kapasitas, bis.harga);
	}
	fclose(b);
	printf("\n1.Tambah Bis\n2.Hapus Bis\n3.keluar");
	printf("\nMasukkan keinginan : ");
	scanf("%d", &decisionAdmin);
	 if(decisionAdmin == 1){
	 	system("cls");
	 	tambah_bis();
	 }else if(decisionAdmin == 2){
	 	system("cls");
		hapus_bis();
	 }else if(decisionAdmin == 3){
	 	system("cls");
	 	return 0;
	 }
}

int adminPage(){
	while(1){
	int decisionUserAdmin;
	tampilanadmin();
	printf("Apa yang ingin anda lakukan\n");
	printf("1.Daftar Bis\n2.List Pemesanan\n3.List akun User\n4.Keluar\n");
	printf("Masukkan piihan anda: ");
	scanf("%d", &decisionUserAdmin);
	if(decisionUserAdmin == 1){
		system("cls");
		tampilanadmin();
		tampilkan_bis();
	}else if(decisionUserAdmin == 2){
		system("cls");
		tampilanadmin();
		pemesanan_bis();
	}else if(decisionUserAdmin == 3){
		system("cls");
		tampilanadmin();
		tampilkan_User();
	}else if(decisionUserAdmin == 4){
		printf("\nAnda telah keluar");
		sleep(2);
		system("cls");
		printf("Sampai Jumpa Admin....\n");
	}
	}
}

int mainadmin(){
	for (;;){
        system("cls");		
		loginpage();
    	if (loginadmin()) {
        printf("\nLogin berhasil! Selamat datang, Admin.\n");
        sleep (2);
       	system("cls");
    	} else {
        printf("\nAnda telah gagal login 3 kali. Akses ditolak.\n");
        break;
    	}
    	adminPage();
    	break;	
	}
}

int pemesanan_bis(){
	struct Datadiri data;
	int returning;
	FILE *file;
	
	file = fopen("datadiripemesan.txt", "r");
	if(file == NULL){
		printf("Tidak ada file");
		return -1;
	}
	
	printf("DAFTAR PEMESANAN\n");
    printf("===================================================\n");
    printf("Nama\t\tNo.Telepon\t\tBus\tHari\n");
    printf("===================================================\n");
	
	while(fscanf(file, "%49s %49s %d %d", data.nama,data.nomortelp, &data.jumlahbis, &data.jumlahhari) != EOF){
		printf("%-15s %-15s \t%d \t%d\n", data.nama,data.nomortelp, data.jumlahbis, data.jumlahhari);
	};
	fclose(file);
	
	printf("\nKetik 1 untuk kembali ke menu admin: ");
	scanf("%d", &returning);
	if (returning == 1){
		system("cls");
		return 0;	
	}
}
