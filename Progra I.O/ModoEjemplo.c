void modoEjemplo(){
	// Llama al problema de mochila
	/*int knapsackSize = 15;
	int numObjects = 6;
	int maxHeight = 7;
	int maxValue = 20;
	knapsack(knapsackSize, numObjects, maxHeight, maxValue);
	freeTables(numObjects);*/
	


	// Datos de entrada del problema
	int numObjects = 14;
	int maxValue = 20;
	int maxCost = 7;
	int knapsackSize = 30;

	// Guarda la matriz del problema para todos los algoritmos
	struct element matriz[numObjects];

	// Crea el problema y lo deja en matriz
	createProblem(matriz, knapsackSize, numObjects, maxCost, maxValue);

	// Ejecuta el algoritmo Greedy
	clock_t begin = clock();
	BasicGreedy(knapsackSize, numObjects, matriz);
	printf("El algoritmo tarda: %fms\n", ((double)(clock()-begin)/CLOCKS_PER_SEC)*1000);

	printf("\n");

	// Ejecuta knapsack
	clock_t start = clock();
	knapsack(knapsackSize, numObjects, matriz);
	freeTables(numObjects);
	printf("El algoritmo tarda: %fms\n", ((double)(clock()-start)/CLOCKS_PER_SEC)*1000);
}