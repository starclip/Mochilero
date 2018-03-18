void modoExperimento(int iterations){
	// Guardan el tiempo de ejecucion de los algoritmos y el total de ejecucion
	double tiempoGreddyBasico[10][10];        fillMat(tiempoGreddyBasico);
	double tiempoGreddyProporcional[10][10];  fillMat(tiempoGreddyProporcional);
	double tiempoKnapsac[10][10];             fillMat(tiempoKnapsac);
	double executionTime = 0;
	double totalExecutionTime = 0;
	
	// Ejecuta las n iteraciones
	for (int i = 1; i <= iterations; i++){
		// Variables de configuracion
		int ciclos = 10;
		int total1, total2, total3  = 0;
		
		// Guardan los resultados de los algoritmos
		int resultadosGreddyBasico[ciclos][ciclos];
		int resultadosGreddyProporcional[ciclos][ciclos];
		int resultadosKnapsac[ciclos][ciclos];

		// Guarda la estadistica
		int estadisticKnapProporcional[ciclos][ciclos]; fillIntMat(estadisticKnapProporcional);
		int estadisticKnapBasico[ciclos][ciclos];       fillIntMat(estadisticKnapBasico);

		// Guarda el inicio del reloj
		clock_t beginExecutiontime;

		// mochila de 100 hasta 1000
		for (int j = 1; j <= ciclos; j++){
			// Objetos desde 10 hasta 100
			for (int k = 1; k <= ciclos; k++){
				// Se genera el problema
				int knapsackSize = j*100;
				int numObjects = k*10;
				int maxCost = findObjectsMaxCi(knapsackSize);
				int maxValue = 100;
				struct element problema1[numObjects];
				struct element problema2[numObjects];
				
				// Se crea el problema
				createProblem(problema1, problema2, knapsackSize, numObjects, maxCost, maxValue);

				// Greddy proporcional
				beginExecutiontime = clock();
				total2 = greedy(knapsackSize, numObjects, problema2, 0); 
				executionTime = getTime(beginExecutiontime);
				addTimeMatrix(tiempoGreddyProporcional, j-1, k-1, executionTime);
				addResultMatrix(resultadosGreddyProporcional, j-1, k-1, total2);
				totalExecutionTime += executionTime;

				// Greddy Basico //
				beginExecutiontime = clock(); 
				total1 = greedy(knapsackSize, numObjects, problema1, 1);
				executionTime = getTime(beginExecutiontime);
				addTimeMatrix(tiempoGreddyBasico, j-1, k-1, executionTime);
				addResultMatrix(resultadosGreddyBasico, j-1, k-1, total1);
				totalExecutionTime += executionTime;

				// Mochila
				beginExecutiontime = clock();
				total3 = knapsack(knapsackSize, numObjects, problema1);
				executionTime = getTime(beginExecutiontime);
				addTimeMatrix(tiempoKnapsac, j-1, k-1, executionTime);
				addResultMatrix(resultadosKnapsac, j-1, k-1, total3);
				totalExecutionTime += executionTime;	

				// Ejecuta las comparaciones de la estadistica
				if (total1 == total3)
					estadisticKnapBasico[j-1][k-1] = total3;
				if (total2 == total3)
					estadisticKnapProporcional[j-1][k-1] = total3;
			}	
		}
		
		// Generar latex en las funciones
		//printResultMatrix(resultadosGreddyBasico, resultadosGreddyProporcional, resultadosKnapsac);
		//printEstadisticMatrix(estadisticKnapBasico, estadisticKnapProporcional);
	}

	printTimeMatrix(tiempoGreddyBasico, tiempoGreddyProporcional, tiempoKnapsac);
	getTotalExecutionTime(totalExecutionTime);
}