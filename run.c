#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "funcionesBasicas.c"
#include "ModoEjemplo.c"
#include "ModoExperimento.c"

int main(int argc, char *argv[]){
	// Verifica los valores que vienen de la terminal
    if (argc != 2){
       printf("\nColoque los dos argumentos de entrada\n\n");
       return 1;
   	}
   	
   	// Ejecuta el modo ejemplo
   	if(!strcmp(argv[1], "-X")) 
   		modoEjemplo();
   		
   	// Verifica los datos para el modo experimento 
   	else{
   		char chain[strlen(argv[1])];
   		strcpy(chain, argv[1]);

   		// Comparaciones iniciales
   		int len = strlen(chain);
   		if (len > 6 || len < 4){
   			printf("\nDatos invalidos\n\n");
  			return 1;
 		}
   			
   		// Verifica el -E
   		char *indication = malloc(2);
   		concatenar(indication, chain[0]);
   		concatenar(indication, chain[1]);
   		if (strcmp(indication, "-E") ){
   			printf("\nEl comando %s es invalido\nEl comando correcto es -E\n\n", indication);
   			return 1;
   		}

   		// verifica el = 
   		char *equalSimbol = malloc(1);
   		concatenar(equalSimbol, chain[2]);
   		if (strcmp(equalSimbol, "=") ){
   			printf("\nDebe colocar el simbolo de '=' correctamente\n\n");
   			return 1;
		}

   		// Verifica el numero final
   		char *finalNum = malloc(3);
   		char *actualValue = malloc(1);
   		for (int i = 3; i < strlen(chain); ++i){
   			concatenar(actualValue, chain[i]);
   			if (atoi(actualValue) == 0 && strcmp(actualValue, "0")){
   				printf("\nEl parametro no es un numero entero\n\n");
   				return 1;
   			}
   			strcpy(actualValue, "");
   			concatenar(finalNum, chain[i]);
   		}

   		// Pasa el string a entero, si no se puede queda en 0
   		int value = atoi(finalNum);
   		if ((value == 0) || (value > 100)){
   			printf("\nDigite un numero que se encuentre en el rango de 0 a 100\n\n");
   			return 1;
   		}	
   		printf("%d  ###\n", value);	
   	}
   	
    return 0;
}