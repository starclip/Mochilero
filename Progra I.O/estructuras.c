#define MAX_OBJECTS 8
#define true 1
#define false 0

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


