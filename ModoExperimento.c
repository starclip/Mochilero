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
	
	// Ejecuta las n iteraciones
	for (int i = 1; i <= iterations; i++){
		int ciclos = 10;
		int total;
		int resultadosGreddyBasico[10][10];
		int resultadosGreddyProporcional[10][10];
		int resultadosKnapsac[10][10];
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
				
				// Se ejecuta con los 3 algoritmos

				// Greddy Basico
				printf("############################################################\n");
				printf("Basico\n");
				total = greedy(knapsackSize, numObjects, problema1, 1); 
				resultadosGreddyBasico[j-1][k-1] = total;
				printf("\nTotal: %d\n", total);
				printf("############################################################\n\n\n\n\n");
				
				// Greddy proporcional
				printf("############################################################\n");
				printf("Proporcional\n");
				total = greedy(knapsackSize, numObjects, problema2, 0); 
				resultadosGreddyProporcional[j-1][k-1] = total;
				printf("\nTotal: %d\n", total);
				printf("############################################################\n\n\n\n\n");

				// Mochila
				printf("############################################################\n");
				printf("Mochila\n");
				total = knapsack(knapsackSize, numObjects, problema1);
				resultadosKnapsac[j-1][k-1] = total;
				printf("\nTotal: %d\n", total);
				printf("############################################################\n\n\n\n\n");
			}	
		}


		// Generar latex
		printf("\nTable Greddy\n");
		for (int i = 0; i < 10; i++){
			for (int j = 0; j < 10; j++){
				printf("%d |", resultadosGreddyBasico[i][j] );
			}
			printf("\n\n");
		}
		printf("\nTable Greddy\n");
		for (int i = 0; i < 10; i++){
			for (int j = 0; j < 10; j++){
				printf("%d |", resultadosGreddyProporcional[i][j] );
			}
			printf("\n\n");
		}
		printf("\nTable Greddy\n");
		for (int i = 0; i < 10; i++){
			for (int j = 0; j < 10; j++){
				printf("%d |", resultadosKnapsac[i][j] );
			}
			printf("\n\n");
		}
	}
}



//  formula para verificar los Ci's al 40% de la mochila coo maximo
