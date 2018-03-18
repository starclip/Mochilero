

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
/*
	// Imprime la mochila final
	printf("############################################################\n");
	printf("La mochila mediante el 'algoritmo greedy' quedaria de la siguiente forma: \n\n");
	printf("	Objeto X | Costo | Valor\n");
	for (int i = 0; i < elementQuantity; ++i){
		if (inKnapsack[i].identity != 0){
			printf("	Objeto %d | %d     | %d\n", inKnapsack[i].identity, inKnapsack[i].cost, inKnapsack[i].value);
			total += inKnapsack[i].value;
		}
	}
	printf("############################################################\n");
*/
	return total;
}
