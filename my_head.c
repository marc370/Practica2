#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main(){
	char nom_arxiu[256];
	int num_linias;      	
	printf("Introdueix el nom del arxiu: ");
	scanf("%255s", nom_arxiu);
	printf("Introdueix el nombre de línias que vols llegir: ");
	scanf("%d", &num_linias);
	int identificador_arxiu = open(nom_arxiu, O_RDONLY);
	//printf("%d \n", identificador_arxiu);
	if (identificador_arxiu == -1){
		printf("Error: l'arxiu introduït no existeix \n");
	} else if (num_linias <= 0){
		printf("Error: el nombre de línias introduït no és vàlid \n");
		
	} else {
		char linia[1024];
		int contador = 0;
		ssize_t bytes;
		while ((bytes = read(identificador_arxiu, linia, 1024)) > 0 && contador < num_linias){		
			//printf("%s", linia);			
			for (int i = 0; i < sizeof(linia); i++){
					printf("%c", linia[i]);
				       	if (linia[i] == '\n'){
			       			contador ++;
				 		if (contador >= num_linias){
							break;
							}
					}
			}
			
		}
		close(identificador_arxiu);
	}
}


