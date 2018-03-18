/*
##############################################
### Algoritmo Greedy basico y proporcional ###
##############################################
*/


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
			return 1; // Si el rendimiento es 0 se retorna 1 para que el algoritmo lo tome en cuenta 
		return res;
	}
}


/*#############################################################
 Da el mejor objeto en la matriz, recibe los siguientes parametos:
 - matriz[] es donde estan los objetos
 - elementQuantity es la cantidad de elementos en la matriz
 - type es el tipo de algoritmo
 		1 = Greddy Basico
		0 = Greddy Proporcional
Retorna el objeto con el mejor valor en caso del Greddy basico o 
el mejor rendimiento en caso del Greddy proporcional y coloca el 
identificador del objeto en 0.
###############################################################*/
struct element getMostValueble(struct element matriz[], int elementQuantity, int type){
	struct element ejem;
	ejem.value = 0;
	int actualValue, ejemValue;
	for (int i = 0; i < elementQuantity; ++i){
		if (type == 1){
			actualValue = matriz[i].value;
			ejemValue = ejem.value;
		}
		else{
			actualValue = getPerformance(matriz[i]); 
			ejemValue   = getPerformance(ejem);
		}
		// Verifica si entra o no el objeto seleccionado
		if (matriz[i].identity != 0 && actualValue >= ejemValue){
			if (actualValue == ejem.value){
				if (matriz[i].cost <= ejemValue)
					ejem = matriz[i];
			}
			else
				ejem = matriz[i];
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


/*#############################################################
 Ejecuta el algoritmo Greddy, recibe los siguientes parametos:
 - knapsack es el tamano de la mochila
 - elementQuantity es la cantidad de elementos en la matriz
 - matriz[] es donde estan los objetos
 - type es el tipo de algoritmo
 		1 = Greddy Basico
		0 = Greddy Proporcional
###############################################################*/
void BasicGreedy(FILE *greedyFile, int knapsack, int elementQuantity, struct element matriz[], int type){ 
	// Llena la mochila 

	printf("Mochila: %d, elementos: %d\n", knapsack, elementQuantity);
	
	
	struct element inKnapsack[elementQuantity];
	struct element actualObj; 
	char *line = malloc(100);
	int total;
	struct element nullObj = {0,0,0};
	
	for (int i = 0; i < elementQuantity; ++i){
		actualObj = getMostValueble(matriz, elementQuantity, type);
		if (actualObj.cost <= knapsack){
			inKnapsack[i] = actualObj;
			knapsack -= actualObj.cost;
		}
		else{inKnapsack[i] = nullObj;}
	}

	// Imprime la mochila final del Greddy basico
	if (type == 0){
		total = 0;
		fprintf(greedyFile, "%s\n", "Se muestra a continuación la tabla greedy con los resultados: ");
		fprintf(greedyFile, "%s\n", "\\definecolor{Gray}{gray}{0.9}");
		fprintf(greedyFile, "%s\n", "\\definecolor{LightCyan}{rgb}{0.88,1,1}");
		fprintf(greedyFile, "%s\n", "\\begin{center}");
		fprintf(greedyFile, "%s\n", "\\begin{tabu} to 0.6\\textwidth { | X[l] | X[l] | X[l] | } ");
		fprintf(greedyFile, "%s\n", "\\hline");
		fprintf(greedyFile, "%s\n", "\\rowcolor{Gray}");
		fprintf(greedyFile, "%s\n", "\\textbf{Objeto} & \\textbf{Peso} & \\textbf{Valor}\\\\");
		fprintf(greedyFile, "%s\n", "\\hline");

		for (int i = 0; i < elementQuantity; ++i){
			if (inKnapsack[i].identity != 0){
				sprintf(line, "Object %d & %d & %d \\\\", inKnapsack[i].identity, inKnapsack[i].cost, inKnapsack[i].value);
			    fprintf(greedyFile, "%s\n", line);
			    fprintf(greedyFile, "%s\n", "\\hline");
				total += inKnapsack[i].value;
			}
		}
		fprintf(greedyFile, "%s\n", "\\end{tabu} \\\\");
		fprintf(greedyFile, "%s\n", "\\end{center}");
		fprintf(greedyFile, "\\[ \\textsc{\\normalsize Z}\\\\[0.5cm] = %d \\] \n", total);
		free(line);

	}
	else{
		total = 0;
		fprintf(greedyFile, "%s\n", "Se muestra a continuación la tabla greedy proporcional con los resultados: ");
		fprintf(greedyFile, "%s\n", "\\definecolor{Gray}{gray}{0.9}");
		fprintf(greedyFile, "%s\n", "\\definecolor{LightCyan}{rgb}{0.88,1,1}");
		fprintf(greedyFile, "%s\n", "\\begin{center}");
		fprintf(greedyFile, "%s\n", "\\begin{tabu} to 0.6\\textwidth { | X[l] | X[l] | X[l] | X[l] |} ");
		fprintf(greedyFile, "%s\n", "\\hline");
		fprintf(greedyFile, "%s\n", "\\rowcolor{Gray}");
		fprintf(greedyFile, "%s\n", "\\textbf{Objeto} & \\textbf{Peso} & \\textbf{Valor} & \\textbf{Rend}\\\\");
		fprintf(greedyFile, "%s\n", "\\hline");

		for (int i = 0; i < elementQuantity; ++i){
			if (inKnapsack[i].identity != 0){
				sprintf(line, "Object %d & %d & %d & %d \\\\", inKnapsack[i].identity, inKnapsack[i].cost, inKnapsack[i].value, getPerformance(inKnapsack[i]));
			    fprintf(greedyFile, "%s\n", line);
			    fprintf(greedyFile, "%s\n", "\\hline");
				total += inKnapsack[i].value;
			}
		}
		fprintf(greedyFile, "%s\n", "\\end{tabu} \\\\");
		fprintf(greedyFile, "%s\n", "\\end{center}");
		fprintf(greedyFile, "\\[ \\textsc{\\normalsize Z}\\\\[0.5cm] = %d \\] \n", total);
		free(line);
	}
	printf("@@@@@\n");
	//total = 0;
	// Imprime la mochila final
	
	printf("La mochila mediante el 'algoritmo greedy' quedaria de la siguiente forma: \n\n");
	printf("	Objeto X | Costo | Valor\n");
	for (int i = 0; i < elementQuantity; ++i){
		if (inKnapsack[i].identity != 0){
			printf("	Objeto %d | %d     | %d\n", inKnapsack[i].identity, inKnapsack[i].cost, inKnapsack[i].value);
			total += inKnapsack[i].value;
		}
	}
	printf("	       Total : %d\n", total);
	printf("\n");
}


int greedy(int knapsack, int elementQuantity, struct element matriz[], int type){ 
	// Llena la mochila 
	printf("Mochila: %d, objetos: %d\n", knapsack, elementQuantity);
	struct element inKnapsack[elementQuantity];
	struct element actualObj; 
	int total;
	struct element nullObj = {0,0,0};
	
	for (int i = 0; i < elementQuantity; ++i){
		actualObj = getMostValueble(matriz, elementQuantity, type);
		if (actualObj.cost <= knapsack){
			inKnapsack[i] = actualObj;
			knapsack -= actualObj.cost;
		}
		else{inKnapsack[i] = nullObj;}
	}

	// Imprime la mochila final del Greddy basico
	if (type == 0){
		total = 0;
		for (int i = 0; i < elementQuantity; ++i){
			if (inKnapsack[i].identity != 0){
				total += inKnapsack[i].value;
			}
		}
	}
	else{
		total = 0;
		for (int i = 0; i < elementQuantity; ++i){
			if (inKnapsack[i].identity != 0){
				total += inKnapsack[i].value;
			}
		}
	}
	



	// Imprime la mochila final
	total = 0;
	printf("############################################################\n");
	printf("############################################################\n");
	printf("############################################################\n");
	printf("La mochila mediante el 'algoritmo greedy' quedaria de la siguiente forma: \n\n");
	printf("	Objeto X | Costo | Valor\n");
	for (int i = 0; i < elementQuantity; ++i){
		if (inKnapsack[i].identity != 0){
			printf("	Objeto %d | %d     | %d\n", inKnapsack[i].identity, inKnapsack[i].cost, inKnapsack[i].value);
			total += inKnapsack[i].value;
		}
	}
	return total;
	printf("############################################################\n");
	printf("############################################################\n");
	printf("############################################################\n");
	
}
