//login.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

void loginpage() {
	printf("\n");
	printf("===============================================================\n");
    printf("||       RRRR   AAAAA   N   N   OOOOO   V   V   AAAAA        ||\n");
    printf("||       R   R  A   A   NN  N   O   O   V   V   A   A        ||\n");
    printf("||       RRRR   AAAAA   N N N   O   O   V   V   AAAAA        ||\n");
    printf("||       R  R   A   A   N  NN   O   O    V V    A   A        ||\n");
    printf("||       R   R  A   A   N   N   OOOOO     V     A   A        ||\n");
    printf("===============================================================\n");
    printf("||                                                           ||\n");
    printf("||           Alamat: Jl. Kampus Polban No. 12, Bandung       ||\n");
    printf("||                 Bus Pariwisata terpercaya?                ||\n");
    printf("||                     Ranova solusinya                      ||\n");
    printf("||                                                           ||\n");
    printf("===============================================================\n");
	printf("\n");
}

int loginadmin() {
    char username[50];
    char password[50];

    const char validUsername[] = "adminranova";
    const char validPassword[] = "admin#1234";

    int attempts = 3;
    int currentAttempt = 0; 


    while (currentAttempt < attempts) {
		printf("=== LOGIN ===\n");
		printf("\nPercobaan %d dari %d\n", currentAttempt + 1, attempts);
        printf("Username: ");
        scanf("%49s", username);
        printf("Password: ");
        scanf("%49s", password);

        
        if (strcmp(username, validUsername) == 0 && strcmp(password, validPassword) == 0) {
            return 1;
        } else {
            printf("Login gagal. Username atau password salah.\n");
        }
        printf("\033[2J");
	    printf("\033[H");

        currentAttempt++;
    }
    return 0; 
}

int loginuser(char *userranova, char *loggedInUser) {
    char username[50];
    char password[50];
    char fileUsername[50];
    char filePassword[50];

    FILE *file = fopen("userranova.txt", "r");
    if (file == NULL) {
        perror("Gagal membuka file");
        return 0;
    }

    int attempts = 3;
    int currentAttempt = 0;

    while (currentAttempt < attempts) {
        system("cls");
		loginpage();  
        printf("=== LOGIN ===\n");
        printf("\nPercobaan %d dari %d\n", currentAttempt + 1, attempts);

        printf("Username: ");
        scanf("%49s", username);
        printf("Password: ");
        scanf("%49s", password);

        
        rewind(file);

        int isValid = 0;
        while (fscanf(file, "%s %s", fileUsername, filePassword) != EOF) {
            if (strcmp(username, fileUsername) == 0 && strcmp(password, filePassword) == 0) {
                isValid = 1;
                strcpy(loggedInUser, username);
                break;
            }
        }

        if (isValid) {
            fclose(file);
            return 1;
        } else {
            printf("Login gagal. Username atau password salah.\n");
            currentAttempt++;
        }
    }
    fclose(file);
    return 0;
}
