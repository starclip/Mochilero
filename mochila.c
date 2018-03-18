/////////////////////////////////
// Programa del knapsack 0/1. ///
/////////////////////////////////

struct space** table;	         // Tabla de números y valores
struct element *objectsSelected; // Objetos seleccionados dinámicamente.
int lenSelected;                 // Cantidad de objetos seleccionados dinámicamente.

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


void createDynamicTable(FILE *output, int maxRow, int maxColumn, struct element matriz[]){
    char *line = malloc(100);
    fprintf(output, "%s\n", "\\definecolor{Gray}{gray}{0.5}");
    fprintf(output, "%s\n", "\\definecolor{GreenBlack}{RGB}{2,80,0}");
    fprintf(output, "%s\n", "\\begin{center}");
    fprintf(output, "%s", "\\begin{tabu} to 1.0\\textwidth { |");
    for(int i=0; i < (maxColumn + 1); i++){
        fprintf(output, "%s", " c |");
    }
    fprintf(output, "%s\n", " }");
    fprintf(output, "%s\n", "\\hline");
    fprintf(output, "%s", "\\cellcolor{Gray}\\color{black}\\textbf{X} & ");
    for(int i=0; i < maxColumn; i++){
        sprintf(line, "\\cellcolor{Gray}\\color{black}\\textbf{%d}", matriz[i].number);
        fprintf(output, "%s", line);
        if (i+1 < maxColumn){
            fprintf(output, "%s", " & ");
        }else{
            fprintf(output, "%s\n", " \\\\ ");
        }
    }
    fprintf(output, "%s\n", "\\hline");
    for(int i=0; i < maxRow; i++){
        fprintf(output, "\\cellcolor{Gray}\\color{black}%d & ", i);
        for(int j=0; j < maxColumn; j++){
            if(table[i][j].state){
                fprintf(output, "%s", "\\textcolor{GreenBlack}{ ");
            }else{
                fprintf(output, "%s", "\\textcolor{red}{ ");
            }
            
            fprintf(output, "%d}", table[i][j].numb);
            if (j+1 < maxColumn){
                fprintf(output, "%s", " & ");
            }else{
                fprintf(output, "%s\n", " \\\\ ");
            }
        }
        fprintf(output, "%s\n", "\\hline");
    }
    fprintf(output, "%s\n", "\\end{tabu} \\\\");
    fprintf(output, "%s\n", "\\end{center}");
    free(line);
}


void results(FILE *output, int numObjects, int knapsacksize, struct element matriz[]){
	FILE *temp, *temp2;
	char c;
	temp = fopen("temp.txt", "w");
	temp2 = fopen("temp2.txt", "w");
	int count = 0, sum = 0;
	char *letters = "ABCDEF";
	char *line = malloc(100);
	fprintf(output, "%s\n", "El resultado es el siguiente: ");
	fprintf(output, "%s\n", "Las soluciones de X son las siguientes: ");
	fprintf(output, "%s", "\\[ \\textsc{\\normalsize Z}\\\\[0.5cm] = ");
	fprintf(temp, "%s", "\\[ " );
	fprintf(temp2, "%s", "\\[ ");
	for(int i = lenSelected - 1; i >= 0; i--){
		while(count < (objectsSelected[i].number - 1)){
			fprintf(temp, "X_{%d} = 0, ", matriz[count].number);
			fprintf(temp2, "(%d * 0) +", matriz[count].cost);
			sprintf(line, "(%d * 0) + ", matriz[count].value);
			fprintf(output, "%s", line);
			count++;
		}
		fprintf(temp, "X_{%d} = 1", matriz[count].number);
		fprintf(temp2, "(%d * 1)", matriz[count].cost);
		sprintf(line, "(%d * 1)", matriz[count].value);
		fprintf(output, "%s", line);
		printf("Count: %d\n", count);
		if (objectsSelected[i].number != numObjects){
			fprintf(output, "%s", "+");
			fprintf(temp, "%s", ", ");
			fprintf(temp2, "%s", "+");
		}
		sum += matriz[count].value;
		count++;
	}
	// Si quedan objetos que no se han representado.
	while(count < (numObjects)){
		fprintf(temp, "X_{%d} = 0", matriz[count].number);
		fprintf(temp2, "(%d * 0)", matriz[count].cost);
		sprintf(line, "(%d * 0)", matriz[count].value);
		fprintf(output, "%s", line);
		count++;
		if (count < (numObjects)){
			fprintf(output, "%s", "+");
			fprintf(temp, "%s", ", ");
			fprintf(temp2, "%s", "+");
		}
	}
	fprintf(temp, "%s", " \\]");
	fprintf(temp2, "\\leq %d", knapsacksize);
	fprintf(temp2, "%s", " \\]");
	fprintf(output, "%s\n", " \\]");
	fprintf(output, "\\[ \\textsc{\\normalsize Z}\\\\[0.5cm] = %d \\] \n", sum);
	fclose(temp);
	fclose(temp2);
	temp = fopen("temp.txt", "r");
	fseek(temp, 0, SEEK_SET);
	while((c=fgetc(temp)) != EOF){
		fprintf(output, "%c", c);
	}
	fclose(temp);
	fprintf(output, "%s\n", "\\newline Esta sujeto a: ");
	temp2 = fopen("temp2.txt", "r");
	fseek(temp2, 0, SEEK_SET);
	while((c=fgetc(temp2)) != EOF){
		fprintf(output, "%c", c);
	}
	fclose(temp2);
	remove("temp.txt");
	remove("temp2.txt");
}

// Llenar la tabla de ceros. Puede ser una operación omitida.
void fillTable(int maxRow, int maxColumn, struct element matriz[]){
	
	int tempValue, totalValue, cost, value; // Variables a utilizar.
	for(int j=0; j < maxColumn; j++){
		cost = matriz[j].cost; // Peso del objeto.
		value = matriz[j].value;   // Valor del objeto.

		for(int i=0; i < maxRow; i++){
			if (cost <= i){
				tempValue = i - cost;
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

	int total = 0;
	// Imprime la mochila final
	printf("La mochila mediante el 'algoritmo dinámico' quedaria de la siguiente forma: \n\n");
	printf("	Objeto X | Costo | Valor\n");
	for (int i = 0; i < lenSelected; ++i){
		printf("	Objeto %d | %d     | %d\n", objectsSelected[i].number, objectsSelected[i].cost,
			 objectsSelected[i].value);
		total += objectsSelected[i].value;
	}
	printf("	       Total : %d\n", total);
	printf("\n");
}


// Liberar toda la tabla.
void freeTables(int maxColumn){
	for(int i=0; i < maxColumn; i++){
		free(table[i]); // Liberar columnas de la tabla principal
	}
	free(table); // Libere la tabla principal
	free(objectsSelected); // Libere los objetos seleccionados.
	table = NULL;
}


// Choose the objects
int chooseObjects(int maxRow, int maxColumn, struct element matriz[]){
	int *positions; // Arreglo que almacena las posiciones de los objetos seleccionados.
	int i, j, pos, len;
	int total = 0;
	i = maxRow;
	j = maxColumn-1;
	len = 0;

	positions = (int*)malloc(maxColumn * sizeof(int)); // Reservo memoria del total de objetos.
	// Recorra de derecha a izquierda, seleccionando los valores dinámicos.
	while(j >= 0){
		// Si es un valor nuevo o de color azul en la tabla, almaceno su posición y reduzco la fila.
		if (table[i][j].state){
			i = i - matriz[j].cost;
			positions[len] = j; // Almaceno su columna respectiva.
			len++;
		}
		j--; // Columna de la izquierda.
	}
	// Almaceno en un arreglo los objetos seleccionados por óptimos.
	objectsSelected = (struct element*)malloc(len * sizeof(struct element)); 
	for(int i=0; i < len; i++){
		pos = positions[i];
		objectsSelected[i] = matriz[pos]; // Obtengo la posición del objeto.
		total += objectsSelected[i].value;
	}
	free(positions); // Libero las posiciones porque ya no son necesarias.
	lenSelected = len;
	return total;
}


int knapsack(int knapsackSize, int numObjects, struct element matriz[]){
	createTable(knapsackSize + 1, numObjects); // Creo la estructura de la tabla.
	fillTable(knapsackSize + 1, numObjects, matriz); // Lleno la tabla.
	int total =  chooseObjects(knapsackSize, numObjects, matriz); // Selecciono los objetos óptimos.
	printTable(knapsackSize + 1, numObjects); // Imprimo la tabla.
	return total;
}