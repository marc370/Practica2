#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
	char nom_arxiu[256];
	char arxiu_canviar[256];
	//char linia[256];
	char linia;
	int contingut;
	int identificador_arxiu, desc;


	printf("Introdueix l'arxiu que es vol modificar el nom: ");
	scanf("%s", arxiu_canviar);
	printf("Introdueix el nou nom del arxiu: ");
	scanf("%s", nom_arxiu);
	
	identificador_arxiu = open(arxiu_canviar, O_RDONLY);
      	if (identificador_arxiu == -1){
		printf("ERROR: L'arxiu introduït no existeix \n");
	} else {
		desc = open(nom_arxiu, O_CREAT|O_WRONLY|O_TRUNC, S_IRWXU);
		if (desc == -1){
			printf("S'ha produït un error en la creació del nou arxiu \n");
		} else{
			while (contingut = read(identificador_arxiu, &linia, 1) > 0){
				//printf("%d", contingut);
				//write(desc, linia, 256-1);
				write(desc, &linia, 1);
			}	
		}
	}
	unlink(arxiu_canviar);
	return 0;
}
			
	

