//////////////////////
// Programa Greedy ///
//////////////////////


// Retorna el objeto con el mejor valor y coloca el identificador en 0.
struct element getMostValueble(struct element mat[], int quantity){
	struct element ejem;
	ejem.value = 0;
	for (int i = 0; i < quantity; ++i){
		if (mat[i].identity != 0 && mat[i].value >= ejem.value){
			if (mat[i].value == ejem.value){
				if (mat[i].cost <= ejem.cost)
					ejem = mat[i];
			}
			else
				ejem = mat[i];
		}
	}
	for (int i = 0; i < quantity; ++i){
		if (ejem.identity == mat[i].identity){
			mat[i].identity = 0;
			break;
		}
	}
	return ejem;
}


// Ejecuta el algoritmo Greddy basico
void BasicGreedy(int knapsack, int elementQuantity, struct element matriz[]){ 
	// Llena la mochila
	struct element inKnapsack[elementQuantity];
	struct element actualObj; 
	struct element nullObj = {0,0,0};
	for (int i = 0; i < elementQuantity; ++i){
		//printf("Mochila: %d\n", knapsack);
		actualObj = getMostValueble(matriz, elementQuantity);
		if (actualObj.cost <= knapsack){
			//printf("	Aguegue %d a la mochila\n", actualObj.cost);
			inKnapsack[i] = actualObj;
			knapsack -= actualObj.cost;
		}
		else{
			inKnapsack[i] = nullObj;
		}
	}
	
	// Imprime la mochila final
	printf("La mochila mediante el 'algoritmo greedy' quedaria de la siguiente forma: \n\n");
	int total = 0;
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


