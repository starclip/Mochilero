// Recibe el tamano de la mochila y retorna la cantdad 
// maxima de valor que puede tener un objeto
int findObjectsMaxCi(int knapsackSize){
	return knapsackSize * 0.4;
}


void modoExperimento(int iterations){
	// Datos de entrada del problema
	//int numObjects = 6;    // Va de  10 en  10 hasta  100
	//int knapsackSize = 15; // Va de 100 en 100 hasta 1000
	//int maxValue = 20;     // Debe cumplir que: 0 < maxValue < 100
	//int maxCost = 7;       // Esta dado por la funcion findObjectsMaxCi(knapsackSize)
	
	double tiempoGreddyBasico[10][10];        fillMat(tiempoGreddyBasico);
	double tiempoGreddyProporcional[10][10];  fillMat(tiempoGreddyProporcional);
	double tiempoKnapsac[10][10];             fillMat(tiempoKnapsac);
	double executionTime = 0;
	double totalExecutionTime = 0;
	// Ejecuta las n iteraciones
	for (int i = 1; i <= iterations; i++){
		int ciclos = 10;
		int total  = 0;
		// Guardan los resultados de los algoritmos
		int resultadosGreddyBasico[10][10];
		int resultadosGreddyProporcional[10][10];
		int resultadosKnapsac[10][10];

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

				// Greddy Basico //
				beginExecutiontime = clock(); 
				total = greedy(knapsackSize, numObjects, problema1, 1);
				executionTime = ((double)(clock()-beginExecutiontime)/CLOCKS_PER_SEC);
				tiempoGreddyBasico[j-1][k-1] += executionTime;
				resultadosGreddyBasico[j-1][k-1] = total;
				totalExecutionTime += executionTime;

				// Greddy proporcional
				beginExecutiontime = clock();
				total = greedy(knapsackSize, numObjects, problema2, 0); 
				executionTime = ((double)(clock()-beginExecutiontime)/CLOCKS_PER_SEC);
				tiempoGreddyProporcional[j-1][k-1] += executionTime;
				resultadosGreddyProporcional[j-1][k-1] = total;
				totalExecutionTime += executionTime;

				// Mochila
				beginExecutiontime = clock();
				total = knapsack(knapsackSize, numObjects, problema1);
				executionTime = ((double)(clock()-beginExecutiontime)/CLOCKS_PER_SEC);
				tiempoKnapsac[j-1][k-1] += executionTime;
				resultadosKnapsac[j-1][k-1] = total;
				totalExecutionTime += executionTime;				
			}	
		}
		

		// Generar latex

		// Valores
		printf("\nTable Greddy basico\n");
		for (int i = 0; i < 10; i++){
			for (int j = 0; j < 10; j++){
				printf("%d |", resultadosGreddyBasico[i][j] );
			}
			printf("\n\n");
		}
		
		printf("\nTable Greddy proporcional\n");
		for (int i = 0; i < 10; i++){
			for (int j = 0; j < 10; j++){
				printf("%d |", resultadosGreddyProporcional[i][j] );
			}
			printf("\n\n");
		}
		printf("\nTable mochila\n");
		for (int i = 0; i < 10; i++){
			for (int j = 0; j < 10; j++){
				printf("%d |", resultadosKnapsac[i][j] );
			}
			printf("\n\n");
		}
	}

	// Tiempos
	printf("Greddy\n");
	for (int i = 0; i < 10; i++){
		for (int j = 0; j < 10; j++){
			printf("%f |", tiempoGreddyBasico[i][j]);
		}
		printf("\n\n");
	}

	printf("Greddy prop\n");
	for (int i = 0; i < 10; i++){
		for (int j = 0; j < 10; j++){
			printf("%f |", tiempoGreddyProporcional[i][j]);
		}
		printf("\n\n");
	}

	printf("Mochila\n");
	for (int i = 0; i < 10; i++){
		for (int j = 0; j < 10; j++){
			printf("%f |", tiempoKnapsac[i][j]);
		}
		printf("\n\n");
	}

	printf("El tiempo total de ejecucion es: %f segundos\n", totalExecutionTime);
}
