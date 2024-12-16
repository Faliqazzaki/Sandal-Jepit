//regisranova.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ranova.h"

int registrasiuser() {
    system("cls");
    loginpage();
    printf("=== REGISTRASI ===\n");        
    int pilihan;
	printf("Menu:\n");
    printf("1. Tambah User\n");
    printf("0. Keluar\n");
    printf("Pilihan: ");
    scanf("%d", &pilihan);
    switch (pilihan) {
            case 1:
                tambah_user("userranova.txt");
                break;
            case 0:
                system("cls");
                return 0;
            default:
                printf("Pilihan tidak valid.\n");
    }

    return 0;
}

int tambah_user(char *userranova) {	
    struct User user;

    FILE *file = fopen("userranova.txt", "a");
    if (file == NULL) {
        perror("Gagal membuka file untuk menambah user");
        return;
    }

    printf("Masukkan username: ");
    scanf("%s", user.username);
    printf("Masukkan password: ");
    scanf("%s", user.password);

    fprintf(file, "%s %s\n", user.username, user.password);
    printf("User berhasil ditambahkan.\n");

    fclose(file);
    sleep(2);
	printf("\033[2J");
	printf("\033[H");    
	return registrasiuser();	    
}
