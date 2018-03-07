// Programa del knapsack 0/1.

#include "ModoEjemplo.h"

// Función que crea la tabla tomando datos de las filas y columnas.
void createTable(int rows, int columns){
	table = (struct space**)malloc(rows * sizeof(struct space*)); // Creo las filas.
	int i;
	if(table){
		for(i=0; i<rows; ++i){
			table[i] = (struct space*)malloc(columns * sizeof(struct space)); // Creo las columnas.
			if (!table) break;
		}
		// Si las filas no están completas... elimine la tabla.
		if (i != rows){
			while(i-- > 0){
				free(table[i]);
			}
			free(table);
			table = NULL;
		}
	}
}


// Llenar la tabla de ceros. Puede ser una operación omitida.
void fillTable(int maxRow, int maxColumn){
	
	int tempValue, totalValue, height, value; // Variables a utilizar.
	for(int j=0; j < maxColumn; j++){
		height = objects[j].height; // Peso del objeto.
		value = objects[j].value;   // Valor del objeto.

		for(int i=0; i < maxRow; i++){
			if (height <= i){
				tempValue = i - height;
				totalValue = value + table[tempValue][j-1].numb;
				// Si la columna es 0. No debo elegir valor del lado izquierdo.
				if (j == 0){
					table[i][j].numb = value;
					table[i][j].state = true;
				}else{
					// Comparo si el nuevo valor es mayor al anterior evaluado.
					if (totalValue > table[i][j-1].numb){
						table[i][j].numb = totalValue; // Es un nuevo valor
						table[i][j].state = true;
					}else{
						table[i][j].numb = table[i][j-1].numb; // Se elige al valor previo.
						table[i][j].state = false;
					}
				}
			}else{
				// Si la columna es 0. Ponga un 0.
				if (j == 0){
					table[i][j].numb = 0; 
					table[i][j].state = false;
				}else{
					table[i][j].numb = table[i][j-1].numb; // Se elige al valor previo.
					table[i][j].state = false;
				}
			}
		}
	}
}

// Imprimir todos los valores de la tabla.
void printTable(int maxRow, int maxColumn){
	printf("\n Objects \n");
	for(int i=0; i < maxColumn; i++){
		printf("- %s - Height: %d - Value: %d ", objects[i].name, objects[i].height, objects[i].value);
		printf("\n");
	}

	printf("\n Table \n");
	for(int i=0; i < maxRow; i++){
		printf("%d | ", i);
		for(int j=0; j < maxColumn; j++){
			printf(" - %d (%d)",table[i][j].numb, table[i][j].state);
		}
		printf("\n");
	}

	printf("\n Results \n");
	printf("(");
	for(int i=0; i < lenSelected; i++){
		printf("( %s )", objectsSelected[i].name);
	}
	printf(")\n");
}

// Liberar toda la tabla.
void freeTables(int maxColumn){
	for(int i=0; i < maxColumn; i++){
		free(table[i]); // Liberar columnas de la tabla principal
	}
	free(table); // Libere la tabla principal
	free(objects); // Libere los objetos
	free(objectsSelected); // Libere los objetos seleccionados.
	table = NULL;
}


// Choose the objects
int chooseObjects(int maxRow, int maxColumn){
	int *positions; // Arreglo que almacena las posiciones de los objetos seleccionados.
	int i, j, pos, len;
	i = maxRow;
	j = maxColumn-1;
	len = 0;

	positions = (int*)malloc(maxColumn * sizeof(int)); // Reservo memoria del total de objetos.
	// Recorra de derecha a izquierda, seleccionando los valores dinámicos.
	while(j >= 0){
		// Si es un valor nuevo o de color azul en la tabla, almaceno su posición y reduzco la fila.
		if (table[i][j].state){
			i = i - objects[j].height;
			positions[len] = j; // Almaceno su columna respectiva.
			len++;
		}
		j--; // Columna de la izquierda.
	}
	// Almaceno en un arreglo los objetos seleccionados por óptimos.
	objectsSelected = (struct element*)malloc(len * sizeof(struct element)); 
	for(int i=0; i < len; i++){
		pos = positions[i];
		objectsSelected[i] = objects[pos]; // Obtengo la posición del objeto.
	}
	free(positions); // Libero las posiciones porque ya no son necesarias.
	lenSelected = len;
	return len;
}

void knapsack(int knapsackSize, int numObjects, int maxHeight, int maxValue){

	char *randomName = malloc(20); // Usado para escribir los datos.
	srand ( (unsigned int) time(NULL) ); // Evita que los números randoms se repitan.
	objects = (struct element*)malloc(numObjects*sizeof(struct element)); // Arreglo dinámico
	int numberOfElementSelected;

	// Inicializo el arreglo de Struct con valores.
	for (int i=0; i < numObjects; i++){
		objects[i].height = rand() % maxHeight + 1;
		objects[i].value = rand() % maxValue + 1;
		sprintf(randomName, "Object %d", i);
		strcpy(objects[i].name, randomName);
	}
	free(randomName);

	createTable(knapsackSize + 1, numObjects); // Creo la estructura de la tabla.
	fillTable(knapsackSize + 1, numObjects); // Lleno la tabla.
	chooseObjects(knapsackSize, numObjects); // Selecciono los objetos óptimos.
	printTable(knapsackSize + 1, numObjects); // Imprimo la tabla.
}

void modoEjemplo(){
	printf("%s\n", "Modo ejemplo");
	int knapsackSize = 15;
	int numObjects = 6;
	int maxHeight = 7;
	int maxValue = 20;
	knapsack(knapsackSize, numObjects, maxHeight, maxValue);
	// Liberar memoria...
	freeTables(numObjects);
}