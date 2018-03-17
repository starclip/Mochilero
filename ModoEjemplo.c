void modoEjemplo(FILE *output){


	FILE *greedyFile;
	FILE *proportionaGreedyFile;
	// Datos de entrada del problema
	int numObjects = 6;
	int maxValue = 20;
	int maxCost = 7;
	int knapsackSize = 15;
	double dynamicTime = 0, greedyTime = 0, propGreedyTime = 0;

	// Guarda la matriz del problema para todos los algoritmos
	struct element matriz[numObjects];
	struct element mat2[numObjects];

	// Crea el problema y lo deja en matriz
	createProblem(matriz, mat2, knapsackSize, numObjects, maxCost, maxValue);

	greedyFile = fopen("greedy.txt", "w");
	proportionaGreedyFile = fopen("greedyProp.txt", "w");

	// Ejecuta el algoritmo Greedy
	clock_t begin = clock();
	BasicGreedy(greedyFile, knapsackSize, numObjects, matriz, 0);
	greedyTime = ((double)(clock()-begin)/CLOCKS_PER_SEC)*1000;
	printf("El algoritmo tarda: %fms\n", greedyTime);

	fclose(greedyFile);
	printf("\n");

	// Ejecuta el algoritmo Greedy proporcional
	clock_t newBegin = clock();
	BasicGreedy(proportionaGreedyFile, knapsackSize, numObjects, mat2, 1);
	propGreedyTime = ((double)(clock()-newBegin)/CLOCKS_PER_SEC)*1000;
	printf("El algoritmo tarda: %fms\n", propGreedyTime);
	
	fclose(proportionaGreedyFile);
	printf("\n");

	// Ejecuta knapsack
	clock_t start = clock();
	knapsack(knapsackSize, numObjects, matriz);
	dynamicTime = ((double)(clock()-start)/CLOCKS_PER_SEC)*1000;
	printf("El algoritmo tarda: %fms\n", dynamicTime);

	/* Generar latex */
    output = fopen("knapsack.tex", "w");
    createLatex(output);
    cover(output);
    informationExample(output);
    createObjectTable(output, numObjects, matriz);

    // Creamos el latex para el algoritmo dinámico.
    introductionDynamicExample(output, numObjects, matriz);
    createDynamicTable(output, knapsackSize + 1, numObjects, matriz); 
    results(output, numObjects, knapsackSize, matriz);
    executionTime(output, dynamicTime);

    // Creamos el latex para el algoritmo greedy.
    introductionGreedyExample(output, numObjects, matriz);
    greedyTable(output);
    executionTime(output, greedyTime);

    // Creamos el latex para el algoritmo greedy proporcional.
    introductionGreedyPropExample(output, numObjects, matriz);
    propGreedyTable(output);
    executionTime(output, propGreedyTime);

    // Creamos el latex para el algoritmo greedy.

    closeLatex(output);

    freeTables(numObjects);

}