//main

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

int main() {
	for (;;){
		int pilihan;		
		loginpage();			
		printf("Kamu disini sebagai apa?\n");	
		printf("1. Admin\n2. User\n");
		printf("Masukkan pilihan: ");
		scanf("%d", &pilihan);
		if (pilihan==1){
			mainadmin();
		} else if (pilihan==2){
			mainuser();
		} 	
		break;	
	}
}
