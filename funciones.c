//#############################################################
//  Se encarga de concatenar un caracter a un string
//#############################################################
char *concatenar(char *destino, char caracter){
    char *cad;
	int i;
	cad = realloc(destino, strlen(destino) + 2);
	for (i = 0; cad[i] != '\0'; i++);           /* Encontrar el fin de destino */
		cad[i++] = caracter;                        /* Añadimos el caracter */
	cad[i] = '\0';                              /* Añadimos el caracter de fin de destino */
    return destino;
}


//#############################################################
//  Recibe el tiempo y retorna cuando ha pasado desde ese 
//  instante en segundos
//#############################################################
double getTime(double begin){
	return ((double)(clock()-begin)/CLOCKS_PER_SEC)*1000;
}


///#############################################################
//  Nos permite obtener un número totalmente random.
//#############################################################
int getRandom(int limit){
	return rand() % limit + 1;
}

void printTable(struct elemento matriz[], int numPos){
	printf("\n Imprimir tabla: \n");
	for(int i=0; i < numPos; i++){
		printf("%c | %d | %.2f \n", matriz[i].letra, matriz[i].peso, matriz[i].prob);
	}
}


//#############################################################
//  Se encarga de generar la tabla, e inicializarla con pesos y probabilidades.
//#############################################################
void crearProblema(struct elemento matriz[], int numPos){
	int total = 0;
	int randASC, randNum, n;
	for(int i=0; i < numPos; i++){
		randASC = getRandom(92);
		randASC += 35;
		randNum = getRandom(1000);

		matriz[i].letra = randASC;
		matriz[i].peso = randNum;
		total += randNum;
	}

	for(int i=0; i < numPos; i++){
		matriz[i].prob = (float) matriz[i].peso / total;
	}
	//SelectionSort(matriz, numPos);
}