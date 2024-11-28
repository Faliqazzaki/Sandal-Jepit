#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>	

int loginpage() {
    printf("====================================\n");
    printf("RRRR    AAAAA   N   N   OOOOO   V   V   AAAAA\n");
    printf("R   R   A   A   NN  N   O   O   V   V   A   A\n");
    printf("RRRR    AAAAA   N N N   O   O   V   V   AAAAA\n");
    printf("R  R    A   A   N  NN   O   O    V V    A   A\n");
    printf("R   R   A   A   N   N   OOOOO     V     A   A\n");
    printf("====================================\n");
    printf("Alamat: Jl. Kampus POLBAN No. 69, Bandung\n");
    printf("      Bus Pariwisata terpercaya?\n");
    printf("          Ranova solusinya\n");
    printf("====================================\n");

    return 0;
}

int login() {
    char username[50];
    char password[50];

    // Username dan password yang valid
    const char validUsername[] = "p";
    const char validPassword[] = "p";

    int attempts = 5; // Maksimal 5 kali percobaan
    int currentAttempt = 0; // Hitung jumlah percobaan



    while (currentAttempt < attempts) {
		printf("=== LOGIN ===\n");
		printf("\nPercobaan %d dari %d\n", currentAttempt + 1, attempts);
        // Input username
        printf("Username: ");
        scanf("%49s", username);
        

        // Input password
        printf("Password: ");
        scanf("%49s", password);

        // Validasi
        if (strcmp(username, validUsername) == 0 && strcmp(password, validPassword) == 0) {
            return 1; // Login berhasil
        } else {
            printf("Login gagal. Username atau password salah.\n");
        }
        
        printf("\033[2J"); // Membersihkan layar
	    printf("\033[H");


        currentAttempt++; // Tambah jumlah percobaan
    }

    return 0; // Login gagal setelah 3 kali percobaan
}
int registrasi(){
	char username[50];
	char password[50];
	printf("==REGISTRASI==\n");
	printf("Silahkan Buat akun anda!!\n");
	printf("\n");
	printf("Username : ");
	scanf("%49s", username);
	printf("Password : ");
	scanf("%49s", password);
	printf("Selamat Datang %s \n", username);
	sleep(2);
	
}
int menuOne(){
		int bis, harga, hari, totalbis, totalharga, decision;
		char respon;
		char jenisBis[50];		
		printf("Bis apa yang ingin kamu pesan?\n");
		printf("1. Big Bus\n2. Medium Bus\n3. Elf\n");
		printf("Masukkan kebutuhan:");
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
		printf("Butuh berapa bis?\n");
		printf("Masukkan kebutuhan:");		
		scanf("%d", &totalbis);
		printf("Mau sekalian dengan supir, solar, dan lain-lain?(y/t)\n");
		printf("Masukkan keinginan:");	
		scanf(" %c", &respon);
		if (respon=='y'){
			harga=harga+(harga*(15/100));
		}
		printf("Mau berapa hari?\n");
		printf("Masukkan kebutuhan:");			
		scanf(" %d", &hari);
		harga=harga*hari;
		totalharga=harga*totalbis;
		printf("\n");
		printf("pesanan sedang di proses.....\n");
		sleep(3);
		printf("=======DESKRIPSI PEMESANAN=======\n");
		printf("Total Bis : %d buah\n", totalbis);
		printf("Hari : %d hari\n", hari);
		printf("Total Harga : Rp %d \n", totalharga);
		printf("\n");
		sleep(2);
		printf("Apakah pesanan sudah sesuai ? (y/t) \n");
		printf("Masukkan keinginan : ");
		scanf(" %c", &respon);
		if(respon == 'y'){
			printf("Pesanan selesai.");
			printf("==Senang Berbisnis dengan anda==\n\n");
			sleep(2);
			printf("1. Kembali Ke Halaman Utama\n");
			printf("2. Pesan Kembali\n");
			printf("Masukkan Pilihan : ");
			scanf("%d", &decision);
			if(decision == 1){
				aplikasi();
			}else if(decision == 2){
				menuOne();
			}
		}else if(respon == 't'){
			printf("\n");
			printf("Silahkan Pesan Ulang.\n\n");
			aplikasi();
		}
}
int aplikasi(){
	int menu;
	printf("==Selamat datang di sewa bus ranova==\n");
	printf("Apa yang bisa kami bantu?\n");
	printf("1. Sewa Bis\n");
	printf("2. Lihat Pemesanan\n");
	printf("0. Keluar\n");
	printf("Masukkan keinginan:");
	scanf("%d", &menu);
	if (menu==1){
		menuOne();
	} else if(menu==2){
		printf("Kamu tidak mempunyai pesanan tiket");
	}else if(menu == 0){
		printf("Terimakasih telah menggunakan aplikasi ranova :)\n");
		sleep (2);
		system("clr");
	}
}

int main() {
		loginpage();
		int userDecision;
		printf("1. Login\n");
		printf("2. Registrasi\n");
		printf("Masukkan pilihan anda : ");
		scanf("%d", &userDecision);
		if(userDecision == 1){
			if (login()) {
        	printf("\nLogin berhasil! Selamat datang, Admin.\n");
        	sleep (2);
       		aplikasi();
    		} else {
        	printf("\nAnda telah gagal login 5 kali. Akses ditolak.\n");
    		}
		}else if(userDecision == 2){
			registrasi();
			aplikasi();
		}else{
			printf("Tidak ada Pilihan !!\n\n");
		}
    return 0;
}

