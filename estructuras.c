#define MAX_OBJECTS 8
#define true 1
#define false 0
#define execFileName "execution.txt"
#define respFileName "results.txt"
#define latexFileName "knapsack.tex"
#define greedyFileName "greedy.txt"
#define greedyPropFileName "greedyProp.txt"
#define stadFileName "estadisticas.txt"

typedef int bool;

// Elemento usado para los algoritmos
struct element{
	int  identity;
	int  cost;
	int  value;
	int  number;
};

// Estructura para almacenar los datos de un espacio de la tabla.
struct space{
	int numb;
	bool state;
};

struct space** table;	         // Tabla de números y valores
struct element *objectsSelected; // Objetos seleccionados dinámicamente.
int lenSelected;                 // Cantidad de objetos seleccionados dinámicamente.


