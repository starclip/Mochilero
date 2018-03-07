#define MAX_OBJECTS 8
#define true 1
#define false 0

typedef int bool;

// Estructura para almacenar los datos de un elemento.
struct element{
	int height;
	int value;
	char name[20];
};

// Estructura para almacenar los datos de un espacio de la tabla.
struct space{
	int numb;
	bool state;
};

struct element *objects; // Total de objetos.
struct space** table;	 // Tabla de números y valores
struct element *objectsSelected; // Objetos seleccionados dinámicamente.
int lenSelected; // Cantidad de objetos seleccionados dinámicamente.

void createTable(int rows, int columns);

void fillTable(int maxRow, int maxColumn);

void printTable(int maxRow, int maxColumn);

void freeTables(int maxColumn);

void knapsack(int knapsackSize, int numObjects, int maxHeight, int maxValue);

void modoEjemplo();