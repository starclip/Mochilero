// 0 Spanglish. Todo en español.

void modoEjemplo(FILE *salida){

	// Datos de entrada del problema.
	int objetos = MAX_EJEMPLO_OBJ;
	int largoTabla = objetos + 1;
	double dynamicTime = 0, greedyTime = 0;
	clock_t newBegin;

	/* Abrir los archivos */
	salida = fopen(archivoLatex, "w");

	/* Inicializan las estructuras. */
	struct elemento matriz[objetos]; // Tabla de objetos.
	float A[objetos + 1][objetos + 1]; // Tabla A, que posee los porcentajes.
	int R[objetos + 1][objetos + 1]; // Tabla R, que posee la ubicación del árbol.

	// Crea el problema (faltan detalles)
	crearProblema(matriz, objetos);
	printTable(matriz, objetos); // Se imprime la tabla de los objetos.

	// Ejecuta el algoritmo de árbol dinámico.
	ceroLlenado(largoTabla, A, R); // Se llena la tabla de -1. (A y R)
	newBegin = clock();
	primerLlenado(largoTabla, A, R, matriz, objetos); // Se llena la tabla de las diagonales iniciales.
	llenado(largoTabla, A, R, matriz); // Se llena la tabla por medio del Pum Pum Pum.
	dynamicTime = getTime(newBegin);
	printf("El algoritmo tarda: %fms\n", dynamicTime);

	printA(largoTabla, A);
	printR(largoTabla, R);

	/* Genera el latex */
    createLatex(salida);
    cover(salida);
    informationExample(salida);
    createObjectTable(salida, objetos, matriz);
    introductionDynamicExample(salida, objetos, matriz);
    createExampleTableA(salida, largoTabla, A);
    createExampleTableR(salida, largoTabla, R);
    executionTime(salida, dynamicTime);
    closeLatex(salida);

	fclose(salida);
}