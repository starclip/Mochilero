//#############################################################
//  Imprime la matriz de tiempos
//#############################################################
void printTimeMatrix(double greddyB[10][10], double greddyP[10][10], double Mochila[10][10]){
	printf("\nTabla de tiempos de ejecucion Greddy Basico\n");
	for (int i = 0; i < 10; i++){
		for (int j = 0; j < 10; j++){
			printf("%fms |", greddyB[i][j] );
		}
		printf("\n\n");
	}
	printf("\nTabla de tiempos de ejecucion Greddy Proporcional\n");
	for (int i = 0; i < 10; i++){
		for (int j = 0; j < 10; j++){
			printf("%fms |", greddyP[i][j] );
		}
		printf("\n\n");
	}
	printf("\nTabla de tiempos de ejecucion Mochila\n");
	for (int i = 0; i < 10; i++){
		for (int j = 0; j < 10; j++){
			printf("%fms |", Mochila[i][j] );
		}
		printf("\n\n");
	}
}

//#############################################################
//  Imprime la matriz de resultados
//#############################################################
void printResultMatrix(int greddyB[10][10], int greddyP[10][10], int Mochila[10][10]){
	printf("\nTable Greddy basico\n");
	for (int i = 0; i < 10; i++){
		for (int j = 0; j < 10; j++){
			printf("%d |", greddyB[i][j] );
		}
		printf("\n\n");
	}
	printf("\nTable Greddy basico\n");
	for (int i = 0; i < 10; i++){
		for (int j = 0; j < 10; j++){
			printf("%d |", greddyP[i][j] );
		}
		printf("\n\n");
	}
	printf("\nTable Greddy basico\n");
	for (int i = 0; i < 10; i++){
		for (int j = 0; j < 10; j++){
			printf("%d |", Mochila[i][j] );
		}
		printf("\n\n");
	}
}

//#############################################################
//  Imprime la matriz de estadisticas
//#############################################################
void printEstadisticMatrix(float mat1[10][10], float mat2[10][10]){
	int counter1 = 0;
	int counter2 = 0;

	printf("\nEstadistica Greddy basico - Mochila\n");
	for (int i = 0; i < 10; i++){
		for (int j = 0; j < 10; j++){
			printf("%f |", mat1[i][j] );
			if (mat1[i][j] != 0)
				counter1 += 1;
			
		}
		printf("\n\n");
	}
	printf("\nEstadistica Greddy proporcional - Mochila\n");
	for (int i = 0; i < 10; i++){
		for (int j = 0; j < 10; j++){
			printf("%f |", mat2[i][j] );
			if (mat2[i][j] != 0)
				counter2 += 1;
		}
		printf("\n\n");
	}

	printf("#######\n");
	printf("El promedio de Greddy Basico       con Mochila es: %d%c \n", counter1, '%');
	printf("El promedio de Greddy Proporcional con Mochila es: %d%c \n", counter2, '%');
}

//#############################################################
//  Imprime la matriz de tiempos
//#############################################################
void getTotalExecutionTime(double totalExecutionTime){
	printf("El tiempo total de ejecucion es: %f segundos\n", totalExecutionTime);
}



//#############################################################
//  Llena una matriz de doubles de 0's
//#############################################################
void fillFloatMat(float mat[10][10]){
	for (int i = 0; i < 10; i++){
		for (int j = 0; j < 10; j++){
			mat[i][j] = 0.0;
		}
	}
}


//#############################################################
//  Llena una matriz de doubles de 0's
//#############################################################
void fillMat(double mat[10][10]){
	for (int i = 0; i < 10; i++){
		for (int j = 0; j < 10; j++){
			mat[i][j] = 0;
		}
	}
}


//#############################################################
//  Llena una matriz de enteros de 0's
//#############################################################
void fillIntMat(int mat[10][10]){
	for (int i = 0; i < 10; i++){
		for (int j = 0; j < 10; j++){
			mat[i][j] = 0;
		}
	}
}


//#############################################################
//  Retorna el 40% de la capacidad de la mochila
//#############################################################
int findObjectsMaxCi(int knapsackSize){
	return knapsackSize * 0.4;
}


//#############################################################
//  Recibe el tiempo y retorna cuando ha pasado desde ese 
//  instante en segundos
//#############################################################
double getTime(double begin){
	return ((double)(clock()-begin)/CLOCKS_PER_SEC)*1000;
}


//#############################################################
//  Suma el valor de la matriz con el valor que le envian
//#############################################################
void addTimeMatrix(double mat[10][10], int i, int j, double value){
	mat[i][j] += value;
}


//#############################################################
//  Cambia el valor de la matriz por el valor que le envian
//#############################################################
void addResultMatrix(int mat[10][10], int i, int j, int value){
	mat[i][j] = value;
}


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
// Genera numeros aleatorios con un limite
//#############################################################
int getRandom(int limit){
	return rand() % limit + 1;
}

//#############################################################
// Retorna el object con todos los valores
//#############################################################
struct element generateObject(int identity, int maxCost, int maxValue){
	struct element obj;                 // Objeto a retornar
	obj.identity = identity;            // Numero de 1 a 6
	obj.cost     = getRandom(maxCost);  // Numero entre 1 y 7
	obj.value    = getRandom(maxValue); // Numero entre 1 y 20
	obj.number = identity;
	return obj;
}


//#############################################################
// Llena la matriz de objetos
//#############################################################
void createProblem(struct element matriz[], struct element mat2[], int knapsackSize, int numObjects, int maxCost, int maxValue){
	struct element elem;
	
	//printf("El problema es el siguiente:\n\n");
	//printf("	Objeto X | Costo | Valor \n");
	
	for (int i = 0; i < numObjects; ++i){
		elem = generateObject(i+1, maxCost, maxValue);
		matriz[i] = elem;
		mat2[i] = elem;
		
		//printf("	Objeto %d | %d     | %d\n", matriz[i].identity, matriz[i].cost, matriz[i].value);
	
	}
	
	//printf("\n");
}


//#############################################################
// Cierra los archivos
//#############################################################
void closeFiles(FILE *file1, FILE *file2){
	fclose(file1);
	fclose(file2);
}


// ############################################################
// Llena el latex knapsack.tex en modo experimento
// ############################################################
void generateExpLatex(FILE *output, FILE *execFile, FILE *respFile, int iterations){
	createLatex(output);                       // Inicializo las declaraciones de Latex
	cover(output);                             // Genero la portada
	informationExperiment(output, iterations); // Se declara la información inicial
	changeGeometry(output, 1);                 // Se hace más grande el tamaño (coordenadas)
	saveLatex(output, execFile, execFileName); // Se dibujan las tablas de ejecución
	saveLatex(output, respFile, respFileName); // Se dibujan las tablas de resultados
	changeGeometry(output, 0);                 // Se restablecen las coordenadas del tamaño
	closeLatex(output);                        // Se cierra el archivo y se ejecuta.
}


/*#############################################################
 Obtiene el rendimiento del objeto, recibe los siguientes parametos:
 - elem es el elemento de tipo struct element
 Retorna el rendimiento del objeto
 #############################################################*/
int getPerformance(struct element elem){
	if (elem.cost == 0 || elem.value == 0)
		return 0;
	else{
		int res = elem.value / elem.cost;
		if (res == 0)
			return 1; 
		return res;
	}
}


/*#############################################################
 Da el mejor objeto en la matriz, recibe los siguientes parametos:
 - matriz[] es donde estan los objetos
 - elementQuantity es la cantidad de elementos en la matriz
 - type es el tipo de algoritmo
 		0 = Greddy Basico
		1 = Greddy Proporcional
Retorna el objeto con el mejor valor en caso del Greddy basico o 
el mejor rendimiento en caso del Greddy proporcional y coloca el 
identificador del objeto en 0.
###############################################################*/
struct element getMostValueble(struct element matriz[], int elementQuantity, int type){
	struct element ejem;
	ejem.value = 0;
	ejem.cost = 0;
	int actualValue, ejemValue;
	for (int i = 0; i < elementQuantity; ++i){
		if (type == 0){
			actualValue = matriz[i].value;
			ejemValue = ejem.value;
		}
		else{
			actualValue = getPerformance(matriz[i]); 
			ejemValue   = getPerformance(ejem);
		}

		// Verifica si entra o no el objeto seleccionado
		if (matriz[i].identity != 0){	
			if (actualValue > ejemValue)
				ejem = matriz[i];
			if (actualValue == ejemValue){
				if (matriz[i].cost < ejem.cost)
					ejem = matriz[i];
			}
		}
		
	}

	// Coloca la identidad del objeto en 0 para que ya no sea consultado
	for (int i = 0; i < elementQuantity; ++i){
		if (ejem.identity == matriz[i].identity){
			matriz[i].identity = 0;
			break;
		}
	}
	return ejem;
}
