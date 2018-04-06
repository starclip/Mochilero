//#############################################################
//  Llena la tabla de -1.
//#############################################################
void ceroLlenado(int largoTabla, float A[][largoTabla], int R[][largoTabla]){
	for(int i=0; i < largoTabla; i++){
		for(int j=0; j < largoTabla; j++){
			A[i][j] = -1.0;
			R[i][j] = -1;
		}
	}
}

//#############################################################
// Llena la tabla con cero en la diagonal.
//#############################################################
void primerLlenado(int largoTabla, float A[][largoTabla], int R[][largoTabla], struct elemento matriz[], int numObjects){
	for(int i=0; i < largoTabla; i++){
		A[i][i] = 0.0;
		R[i][i] = 0;

		// Se compara el i es menor al largo de la tabla.
		if (i < largoTabla){
			A[i][i+1] = matriz[i].prob;
			R[i][i+1] = i + 1 ;
		}
	}
}

//#############################################################
//  Imprima la tabla A.
//#############################################################
void printA(int largoTabla, float A[][largoTabla]){
	printf("Tabla A: \n");
	for(int i=0; i < largoTabla; i++){
		printf(" | ");
		for (int j = 0; j < largoTabla; j++){
			if (A[i][j] < 0){
				printf(" ---- |");
			}else{
				printf(" %.2f |" , A[i][j]);
			}
		}
		printf("\n");
	}
	printf("\n");
}


//#############################################################
//  Imprima la tabla R
//#############################################################
void printR(int largoTabla, int R[][largoTabla]){
	printf("Tabla R: \n");
	for(int i=0; i < largoTabla; i++){
		printf(" | ");
		for (int j = 0; j < largoTabla; j++){
			if (R[i][j] < 0){
				printf(" - |");
			}else{
				printf(" %d |" , R[i][j]);
			}
		}
		printf("\n");
	}
	printf("\n");
}

//#############################################################
//  Pum Pum Pum
//#############################################################
float PumPumPum(int largoTabla, float A[][largoTabla], int R[][largoTabla], struct elemento matriz[], int fila, int columna){
	float num;
	int tot, kfila, kcol, pos;
	pos = num = 0;
	kfila = fila + 1;
	kcol = fila;
	tot = columna - fila;

	while(tot > 0){
		float pum = A[fila][kcol] + A[kfila][columna]; // Sumo las posiciones.
		if (num == 0){
			num = pum;
			pos = kfila;
		}else{
			// Elijo el menor.
			if (num > pum){
				// Se agrega a la lista de posibles empates.
				num = pum;
				pos = kfila;
			}
		}
		tot--;
		kcol++;
		kfila++;
	}
	// Sumo todas las probabilidades pendientes.
	for(int i=fila; i < columna; i++){
		num += matriz[i].prob;
	}
	R[fila][columna] = pos;
	return num;
}


//#############################################################
//  Llena la tabla
//#############################################################
void llenado(int largoTabla, float A[][largoTabla], int R[][largoTabla], struct elemento matriz[]){

	int fila, columna;
	columna = 2;
	fila = 0;

	while(columna < largoTabla){
		for(int i=fila; i >= 0; i--){
			float num = PumPumPum(largoTabla, A, R, matriz, i, columna);
			A[i][columna] = num; // Lleno la tabla con el óptimo.
		}
		fila++;
		columna++;
	}
}