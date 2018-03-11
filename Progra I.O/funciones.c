// Esta funcion se encarga de concatenar un caracter a un string
char *concatenar(char *destino, char caracter){
    char *cad;
	int i;
	cad = realloc(destino, strlen(destino) + 2);
	for (i = 0; cad[i] != '\0'; i++);           /* Encontrar el fin de destino */
		cad[i++] = caracter;                        /* Añadimos el caracter */
	cad[i] = '\0';                              /* Añadimos el caracter de fin de destino */
    return destino;
}


// Genera numeros aleatorios con un limite
int getRandom(int limit){
	return rand() % limit + 1;
}


// Retorna el object con todos los valores
struct element generateObject(int identity, int maxCost, int maxValue){
	struct element obj;                 // Objeto a retornar
	obj.identity = identity;            // Numero de 1 a 6
	obj.cost     = getRandom(maxCost);  // Numero entre 1 y 7
	obj.value    = getRandom(maxValue); // Numero entre 1 y 20
	obj.number = identity;
	return obj;
}


// Llena la matriz de objetos
void createProblem(struct element matriz[], int knapsackSize, int numObjects, int maxCost, int maxValue){
	printf("El problema es el siguiente:\n\n");
	printf("	Objeto X | Costo | Valor \n");
	for (int i = 0; i < numObjects; ++i){
		matriz[i] = generateObject(i+1, maxCost, maxValue);
		printf("	Objeto %d | %d     | %d\n", matriz[i].identity, matriz[i].cost, matriz[i].value);
	}
	printf("\n");
}