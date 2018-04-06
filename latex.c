




//     hay que eliminar lo que no se use     ///



//#############################################################
// Inicializo los datos fijos que va a tener el documento.
//#############################################################
void createLatex(FILE *salida){
    fprintf(salida, "%s\n", "\\documentclass[10pt,letterpaper]{article}");
    fprintf(salida, "%s\n", "\\usepackage[utf8]{inputenc}");
    fprintf(salida, "%s\n", "\\usepackage[spanish]{babel}");
    fprintf(salida, "%s\n", "\\usepackage{graphicx}");
    fprintf(salida, "%s\n", "\\usepackage{booktabs}");
    fprintf(salida, "%s\n", "\\usepackage{multicol}");
    fprintf(salida, "%s\n", "\\usepackage{multirow}");
    fprintf(salida, "%s\n", "\\usepackage{xspace}");
    fprintf(salida, "%s\n", "\\usepackage{color, colortbl}");
    fprintf(salida, "%s\n", "\\usepackage{underscore}");
    fprintf(salida, "%s\n", "\\usepackage{tabu}");
    fprintf(salida, "%s\n", "\\usepackage{url}");
    fprintf(salida, "%s\n", "\\usepackage{ragged2e}");
    fprintf(salida, "%s\n", "\\usepackage{verbatim}");
    fprintf(salida, "%s\n", "\\usepackage{mathdots} ");
    fprintf(salida, "%s\n", "\\usepackage{amsmath, amssymb, amsbsy, amsfonts} ");
    fprintf(salida, "%s\n", "\\usepackage[left=3.5cm,right=3.5cm,top=3.5cm,bottom=3.5cm]{geometry}");
    fprintf(salida, "%s\n", "\\setlength{\\parskip}{\\baselineskip}");
}


//#############################################################
// Genero la portada.
//#############################################################
void cover(FILE *salida){
    fprintf(salida, "%s\n", "\\begin{document} \n\
    \\begin{titlepage} \n\
    \\newcommand{\\HRule}{\\rule{\\linewidth}{0.5mm}} \n\
    \\center   \n\
    \\textsc{\\Huge Instituto Tecnológico de Costa Rica}\\\\[1.5cm] \n\
    \\textsc{\\normalsize PROYECTO DE INVESTIGACIÓN DE OPERACIONES}\\\\[0.5cm] \n\
    \\textsc{\\normalsize PROYECTO 2}\\\\[0.5cm] \n\
    \\HRule\\\\[0.4cm] \n\
    {\\huge\\bfseries \\vspace{1cm} Árboles Binarios}\\\\[0.4cm] \n\
    \\HRule\\\\[2cm] \n\
    \\textbf{\\Large Estudiantes}\\\\[0.5cm] \n\
        \\begin{minipage}{0.4\\textwidth} \n\
        \\begin{flushleft} \n\
            \\large \n\
            Jason Barrantes Arce \n\
            \\textsc{2015048456} \n\
        \\end{flushleft} \n\
    \\end{minipage} \n\
    ~ \n\
    \\begin{minipage}{0.4\\textwidth} \n\
        \\begin{flushright} \n\
           	\\large \n\
            Steven Bonilla Zúñiga \n\
            \\textsc{2015056296} \n\
        \\end{flushright} \n\
    \\end{minipage} \n\
   \\newline \\newline \n\
   \\newline  \n\
   \\textbf{\\Large Profesor}\\\\[0.5cm] \n\
    \\textsc{\\normalsize Francisco Torres Rojas}\\\\[0.5cm] \n\
    \\end{titlepage} \n\
    ");
}


char *caracterLatex(char *line, char c){

    if (c == 33 || c == 63){
        sprintf(line, "%c`", c);
    }else if((c > 34 && c < 39) || (c > 93 && c < 97) || (c > 122 && c < 127 && c != 124)){
        sprintf(line, "\\%c", c);
    }else if(c == 40){
        sprintf(line, "\\%s(", "left");
    }else if(c == 41){
        sprintf(line, "\\%s)", "right");
    }else if ((c > 41 && c < 45) || (c > 46 && c < 58)){
        sprintf(line, "$%c$", c);
    }else if (c > 59 && c < 63){
        sprintf(line, "$%c$", c);
    }else if (c == 64){
        sprintf(line, "\\%c", c);
    }else if(c == 91){
        sprintf(line, "\\%s[", "left");
    }else if((c == 92) || (c == 124)){
        sprintf(line, "\\%s", "textbackslash");
    }else if(c == 41){
        sprintf(line, "\\%s]", "right");
    }else{
        sprintf(line, "%c", c);
    } 

    return line;
}



//#############################################################
// Creo la tabla de objetos. Se usa solamente en el modo Ejemplo.
//#######################################################
void createObjectTable(FILE *salida, int numObjects, struct elemento matriz[]){
    char *line = malloc(100);
    char *temp = malloc(100);
    fprintf(salida, "%s\n", "Se muestra a continuación la tabla de objetos con su respectivo costo (peso) y probabilidad \n\
        que fueron asignados aleatoriamente cumpliendo con las restricciones: ");
    fprintf(salida, "%s\n", "\\definecolor{Gray}{gray}{0.9}");
    fprintf(salida, "%s\n", "\\definecolor{LightCyan}{rgb}{0.88,1,1}");
    fprintf(salida, "%s\n", "\\begin{center}");
    fprintf(salida, "%s\n", "\\begin{tabu} to 0.6\\textwidth { | X[l] | X[l] | X[l] | } ");
    fprintf(salida, "%s\n", "\\hline");
    fprintf(salida, "%s\n", "\\rowcolor{Gray}");
    fprintf(salida, "%s\n", "\\textbf{Letra} & \\textbf{Peso} & \\textbf{Probabilidad}\\\\");
    fprintf(salida, "%s\n", "\\hline");

    for(int i=0; i < numObjects; i++){
        char c = matriz[i].letra;
        temp = caracterLatex(temp, c);
        sprintf(line, "Object %s & %d & %.2f \\\\", temp, matriz[i].peso, matriz[i].prob);
        fprintf(salida, "%s\n", line);
        fprintf(salida, "%s\n", "\\hline");
    }
    fprintf(salida, "%s\n", "\\end{tabu} \\\\");
    fprintf(salida, "%s\n", "\\end{center}");
    free(line);
    free(temp);
}


//#############################################################
// Imprimo la información que aparece por defecto en el modo Ejemplo.
//#############################################################
void informationExample(FILE *salida){
    fprintf(salida, "%s\n", "\\titlepage{\\textbf{Modo Ejemplo:}} \\newline \\newline \n\
        Se resolverá un problema general por medio de diversos algoritmos que nos \n\
        permitan encontrar una solución a ese problema. \n\
        El problema que se nos plantea es sobre árboles de búsqueda binarios. \\\\ \n\
        Hay que ordenar una serie de valores o llaves en forma de árbol binario, de manera que \n\
        el nivel de búsqueda promedio sea el más óptimo. \n\
        Tenemos una serie de llaves que quieren acomodarse en una estructura de árbol, \n\
        pero esas llaves deben tener un respectivo peso \n\
        y un cáracter único que será asignado de manera aleatoria. \\ \\ \\newline \\newline \n\
        Restricciones: \n\
        \\begin{itemize} \n\
        \\item \\textbf{Estructura:} Se formará un árbol binario óptimo. \n\
        \\item \\textbf{Llaves:} Se generarán 6 llaves de forma aleatoria. \n\
        \\item \\textbf{Peso:} Varía entre $1 \\leq C{i} \\leq 1000$. \n\
        \\item Los caracteres ASCII varían. \n\
        \\end{itemize} \n\
        Los dos algoritmos que vamos a implementar son: \n\
        \\begin{itemize} \n\
        \\item \\textbf{Algoritmo de Búsqueda Dinámica:} Algoritmo para el ABB óptimo. \n\
        \\item \\textbf{Algoritmo Greedy Básico:} Cada vez se escoge la llave de máxima probabilidad \n\
         para que sea la raíz del árbol. \n\
        \\end{itemize} \n\
        \\ En el caso de programación dinámica ya que nuestro objetivo es minimizar el costo promedio de la búsqueda, usamos la fórmula: \n\
        \\[ \\textsc{\\normalsize MIN(Z)}\\\\[0.5cm] = \\sum_{i=1}^{n}c_{i}p_{i} \\] \n\
        \\ Que está sujeto a:  \n\
        \\[ \\sum p_{i} \\equiv 1 \\] \n\
        \\ Con cada $c_{i}$ = 1, 2, ... n  \n\
        \\ \\ \\newline \\newline \n\
        ");
}


//#############################################################
// Imprimo la explicación del algoritmo dinámico, con los objetos, los respectivos Z y X.
//#######################################################
void introductionDynamicExample(FILE *salida, int numObjects, struct elemento matriz[]){
    char *line = malloc(100);
    fprintf(salida, "%s\n", "\\section{Algoritmo AAB Óptimo} \n\
        Es un problema de solución de búsqueda óptima:  \n\
        En nuestro caso, queremos minimizar el costo de la búsqueda promedio. \n\
        Para solucionar el problema vamos a hacer uso de una tabla (n+1) x (n+1), donde n es la cantidad \n\
        de objetos o llaves disponibles. \n\
        Como se menciona en las restricciones del problema $n = 6$ por lo que tendremos \n\
        dos tablas (7x7). La tabla A donde estará el costo promedio y la tabla R donde estará \n\
        los índices de búsqueda más rápidos. \\newline \\newline \\newline \n\
        \\textbf{\\Large Fórmula Matemática} \n\
        \\[ \\textsc{\\normalsize MIN(Z)}\\\\[0.5cm] = \\sum_{i=1}^{6}c_{i}p_{i} \\] \n\
        \\ Sujeto a:  \n\
        \\[ \\sum p_{i} \\leq 1 \\] \n\
        \\ En otras palabras tendremos ");
    fprintf(salida, "%s", "\\[ ");
    for (int i = 0; i < numObjects; ++i){
        sprintf(line, "(p_{%d} \\approx %.4f)", i+1, matriz[i].prob);
        fprintf(salida, "%s", line);
        if (i < (numObjects - 1)){
            fprintf(salida, "%s", "+");
        }
    }
    fprintf(salida, "%s\n", " = 1 \\]");
    fprintf(salida, "%s\n", "\\newline Ahora proseguimos realizando la tabla dinámica.");
}

//#############################################################
// Genere la tabla A
//#######################################################
void createExampleTableA(FILE *salida, int largo, float A[][largo]){
    char *line = malloc(100);
    fprintf(salida, "%s\n", "\\newline \\newline \\newline \\textbf{Tabla A: }");
    fprintf(salida, "%s\n", "\\definecolor{Gray}{gray}{0.5}");
    fprintf(salida, "%s\n", "\\definecolor{GreenBlack}{RGB}{2,80,0}");
    fprintf(salida, "%s\n", "\\begin{center}");
    fprintf(salida, "%s", "\\begin{tabu} to 1.0\\textwidth { |");
    for(int i=0; i < (largo + 1); i++){
        fprintf(salida, "%s", " c |");
    }
    fprintf(salida, "%s\n", " }");
    fprintf(salida, "%s\n", "\\hline");
    fprintf(salida, "%s", "\\cellcolor{Gray}\\color{black}\\textbf{X} & ");
    for(int i=0; i < largo; i++){
        sprintf(line, "\\cellcolor{Gray}\\color{black}\\textbf{%d}", i);
        fprintf(salida, "%s", line);
        if (i+1 < largo){
            fprintf(salida, "%s", " & ");
        }else{
            fprintf(salida, "%s\n", " \\\\ ");
        }
    }
    fprintf(salida, "%s\n", "\\hline");
    for(int i=0; i < largo; i++){
        fprintf(salida, "\\cellcolor{Gray}\\color{black}%d & ", i+1);
        for(int j=0; j < largo; j++){
            if(A[i][j] < 0){
                fprintf(salida, "%s", " -- ");
            }else{
                fprintf(salida, "%.2f", A[i][j]);
            }
        
            if (j+1 < largo){
                fprintf(salida, "%s", " & ");
            }else{
                fprintf(salida, "%s\n", " \\\\ ");
            }
        }
        fprintf(salida, "%s\n", "\\hline");
    }
    fprintf(salida, "%s\n", "\\end{tabu} \\\\");
    fprintf(salida, "%s\n", "\\end{center}");
    free(line);
}

//#############################################################
// Genere la tabla R
//#######################################################
void createExampleTableR(FILE *salida, int largo, int R[][largo]){
    char *line = malloc(100);
    fprintf(salida, "%s\n", "\\textbf{Tabla R: }");
    fprintf(salida, "%s\n", "\\begin{center}");
    fprintf(salida, "%s", "\\begin{tabu} to 1.0\\textwidth { |");
    for(int i=0; i < (largo + 1); i++){
        fprintf(salida, "%s", " l |");
    }
    fprintf(salida, "%s\n", " }");
    fprintf(salida, "%s\n", "\\hline");
    fprintf(salida, "%s", "\\cellcolor{Gray}\\color{black}\\textbf{X} & ");
    for(int i=0; i < largo; i++){
        sprintf(line, "\\cellcolor{Gray}\\color{black}\\textbf{%d}", i);
        fprintf(salida, "%s", line);
        if (i+1 < largo){
            fprintf(salida, "%s", " & ");
        }else{
            fprintf(salida, "%s\n", " \\\\ ");
        }
    }
    fprintf(salida, "%s\n", "\\hline");
    for(int i=0; i < largo; i++){
        fprintf(salida, "\\cellcolor{Gray}\\color{black}%d & ", i+1);
        for(int j=0; j < largo; j++){
            if(R[i][j] < 0){
                fprintf(salida, "%s", " - ");
            }else{
                fprintf(salida, " %d ", R[i][j]);
            }
        
            if (j+1 < largo){
                fprintf(salida, "%s", " & ");
            }else{
                fprintf(salida, "%s\n", " \\\\ ");
            }
        }
        fprintf(salida, "%s\n", "\\hline");
    }
    fprintf(salida, "%s\n", "\\end{tabu} \\\\");
    fprintf(salida, "%s\n", "\\end{center}");
    free(line);
}


//#############################################################
// Almacene en latex el tiempo de ejecución.
//#######################################################
void executionTime(FILE *salida, double time){
    fprintf(salida, "%s", "El algoritmo tarda aproximadamente: ");
    fprintf(salida, "%f", time);
    fprintf(salida, "%s\n", " segundos en ejecutarse");
}

//#############################################################
// Cierre el documento de latex y ejecutelo.
//#######################################################
void closeLatex(FILE *salida){
    fprintf(salida, "%s\n", "\\end{document}");
    fclose(salida);
    system("pdflatex arbol.tex && evince -s arbol.pdf &");       
}

/*

//#############################################################
// Imprimo la información que aparece por defecto en el modo Ejemplo.
//#############################################################
void informationExample(FILE *salida){
    fprintf(salida, "%s\n", "\\titlepage{\\textbf{Modo Ejemplo:}} \\newline \\newline \n\
        Se resolverá un problema general por medio de diversos algoritmos que nos \n\
        permitan encontrar una solución a ese problema. \n\
        El problema que se nos plantea es sobre mochila. \\\\ \n\
        Hay que llevar una mochila con capacidad de 15 (kilos, gramos) para un viaje. \n\
        Tenemos una serie de objetos que podemos llevar, pero esos objetos tienen un respectivo peso \n\
        y valor que será producido de manera aleatoria. \\ \\ \\newline \\newline \n\
        Restricciones: \n\
        \\begin{itemize} \n\
        \\item \\textbf{Capacidad:} La mochila tendrá una capacidad de 15 \n\
        \\item \\textbf{Objetos:} Se generarán aleatoriamente 6 objetos. \n\
        \\item \\textbf{C{i}:} Varía entre $0 < C{i} \\leq 7$. \n\
        \\item \\textbf{V{i}:} Varía entre $0 < V{i} \\leq 20$. \n\
        \\end{itemize} \n\
        Los tres algoritmos que vamos a implementar son: \n\
        \\begin{itemize} \n\
        \\item \\textbf{Algoritmo de Programación Dinámica:} Algoritmo para el caso 0/1. \n\
        \\item \\textbf{Algoritmo Greedy Básico:} Cada vez se escoge el objeto más \n\
         valioso que quepa en lo que sobre de la mochila. \n\
        \\item \\textbf{Algoritmo Greedy Proporcional:} En este se calcula el rendimiento definido \n\
        como el valor del objeto dividido entre la capacidad que consume. Se escoge el de mayor rendimiento \n\
        \\end{itemize} \n\
        \\ En el caso de programación dinámica ya que nuestro objetivo es maximizar el valor que obtenemos, usamos la fórmula: \n\
        \\[ \\textsc{\\normalsize MAX(Z)}\\\\[0.5cm] = \\sum_{i=1}^{n}x_{i}v_{i} \\] \n\
        \\ Que está sujeto a:  \n\
        \\[ \\sum x_{i}c_{i} \\leq C \\] \n\
        \\ Con cada $x_{i}$ = 0 o 1.  \n\
        \\ \\ \\newline \\newline \n\
        ");
}


//#############################################################
// Imprimo la información que aparece por defecto en el modo Experimento con el número de iteraciones.
//#######################################################
void informationExperiment(FILE *salida, int n){

    fprintf(salida, "%s\n", "\\titlepage{\\textbf{Modo Experimento:}} \\newline \\newline ");
    fprintf(salida, "Se resolverán %d ", n);
    fprintf(salida, "%s\n", "problemas de mochila por medio de diversos algoritmos que nos \n\
        permitan encontrar varias soluciones a ese problema. \n\
        \\ \\ \\newline \\newline \n\
        Restricciones: \n\
        \\begin{itemize} \n\
        \\item \\textbf{Capacidad:} La mochila tendrá una capacidad que varía de 100 hasta 1000. \n\
        \\item \\textbf{Objetos:} Se generarán aleatoriamente de 10 a 100 objetos. \n\
        \\item \\textbf{C{i}:} Varía entre $0 < C{i} \\leq 40\\%$ de la capacidad de la mochila. \n\
        \\item \\textbf{V{i}:} Varía entre $0 < V{i} \\leq 100$. \n\
        \\end{itemize} \n\
        Los tres algoritmos que vamos a implementar son: \n\
        \\begin{itemize} \n\
        \\item \\textbf{Algoritmo de Programación Dinámica:} Algoritmo para el caso 0/1. \n\
        \\item \\textbf{Algoritmo Greedy Básico:} Cada vez se escoge el objeto más \n\
         valioso que quepa en lo que sobre de la mochila. \n\
        \\item \\textbf{Algoritmo Greedy Proporcional:} En este se calcula el rendimiento definido \n\
        como el valor del objeto dividido entre la capacidad que consume. Se escoge el de mayor rendimiento \n\
        \\end{itemize} \n\
        \\ En el caso de programación dinámica ya que nuestro objetivo es maximizar el valor que obtenemos, usamos la fórmula: \n\
        \\[ \\textsc{\\normalsize MAX(Z)}\\\\[0.5cm] = \\sum_{i=1}^{n}x_{i}v_{i} \\] \n\
        \\ Que está sujeto a:  \n\
        \\[ \\sum x_{i}c_{i} \\leq C \\] \n\
        \\ Con cada $x_{i}$ = 0 o 1.  \n\
        \\ \\ \\newline \\newline \n\
        ");
}


//#############################################################
// Creo la tabla de objetos. Se usa solamente en el modo Ejemplo.
//#######################################################
void createObjectTable(FILE *salida, int numObjects, struct element matriz[]){
    char *line = malloc(100);
    fprintf(salida, "%s\n", "Se muestra a continuación la tabla de objetos con su respectivo costo (peso) y valor \n\
        que fueron asignados aleatoriamente cumpliendo con las restricciones: ");
    fprintf(salida, "%s\n", "\\definecolor{Gray}{gray}{0.9}");
    fprintf(salida, "%s\n", "\\definecolor{LightCyan}{rgb}{0.88,1,1}");
    fprintf(salida, "%s\n", "\\begin{center}");
    fprintf(salida, "%s\n", "\\begin{tabu} to 0.6\\textwidth { | X[l] | X[l] | X[l] | } ");
    fprintf(salida, "%s\n", "\\hline");
    fprintf(salida, "%s\n", "\\rowcolor{Gray}");
    fprintf(salida, "%s\n", "\\textbf{Nombre} & \\textbf{Costo} & \\textbf{Valor}\\\\");
    fprintf(salida, "%s\n", "\\hline");

    for(int i=0; i < numObjects; i++){
        sprintf(line, "Object %d & %d & %d \\\\", matriz[i].number, matriz[i].cost, matriz[i].value);
        fprintf(salida, "%s\n", line);
        fprintf(salida, "%s\n", "\\hline");
    }
    fprintf(salida, "%s\n", "\\end{tabu} \\\\");
    fprintf(salida, "%s\n", "\\end{center}");
    free(line);
}

//#############################################################
// Creo la tabla dinámica. Se usa solamente en el modo Ejemplo.
//#######################################################

void createDynamicTable(FILE *salida, int maxRow, int maxColumn, struct element matriz[]){
    char *line = malloc(100);
    fprintf(salida, "%s\n", "\\definecolor{Gray}{gray}{0.5}");
    fprintf(salida, "%s\n", "\\definecolor{GreenBlack}{RGB}{2,80,0}");
    fprintf(salida, "%s\n", "\\begin{center}");
    fprintf(salida, "%s", "\\begin{tabu} to 1.0\\textwidth { |");
    for(int i=0; i < (maxColumn + 1); i++){
        fprintf(salida, "%s", " c |");
    }
    fprintf(salida, "%s\n", " }");
    fprintf(salida, "%s\n", "\\hline");
    fprintf(salida, "%s", "\\cellcolor{Gray}\\color{black}\\textbf{X} & ");
    for(int i=0; i < maxColumn; i++){
        sprintf(line, "\\cellcolor{Gray}\\color{black}\\textbf{%d}", matriz[i].number);
        fprintf(salida, "%s", line);
        if (i+1 < maxColumn){
            fprintf(salida, "%s", " & ");
        }else{
            fprintf(salida, "%s\n", " \\\\ ");
        }
    }
    fprintf(salida, "%s\n", "\\hline");
    for(int i=0; i < maxRow; i++){
        fprintf(salida, "\\cellcolor{Gray}\\color{black}%d & ", i);
        for(int j=0; j < maxColumn; j++){
            if(table[i][j].state){
                fprintf(salida, "%s", "\\textcolor{GreenBlack}{ ");
            }else{
                fprintf(salida, "%s", "\\textcolor{red}{ ");
            }
            
            fprintf(salida, "%d}", table[i][j].numb);
            if (j+1 < maxColumn){
                fprintf(salida, "%s", " & ");
            }else{
                fprintf(salida, "%s\n", " \\\\ ");
            }
        }
        fprintf(salida, "%s\n", "\\hline");
    }
    fprintf(salida, "%s\n", "\\end{tabu} \\\\");
    fprintf(salida, "%s\n", "\\end{center}");
    free(line);
}


//#############################################################
// Imprimo los resultados
//#######################################################
void results(FILE *salida, int numObjects, int knapsacksize, struct element matriz[]){
    FILE *temp, *temp2;
    char c;
    temp = fopen("temp.txt", "w");
    temp2 = fopen("temp2.txt", "w");
    int count = 0, sum = 0;
    char *letters = "ABCDEF";
    char *line = malloc(100);
    fprintf(salida, "%s\n", "El resultado es el siguiente: ");
    fprintf(salida, "%s\n", "Las soluciones de X son las siguientes: ");
    fprintf(salida, "%s", "\\[ \\textsc{\\normalsize Z}\\\\[0.5cm] = ");
    fprintf(temp, "%s", "\\[ " );
    fprintf(temp2, "%s", "\\[ ");
    for(int i = lenSelected - 1; i >= 0; i--){
        while(count < (objectsSelected[i].number - 1)){
            fprintf(temp, "X_{%d} = 0, ", matriz[count].number);
            fprintf(temp2, "(%d * 0) +", matriz[count].cost);
            sprintf(line, "(%d * 0) + ", matriz[count].value);
            fprintf(salida, "%s", line);
            count++;
        }
        fprintf(temp, "X_{%d} = 1", matriz[count].number);
        fprintf(temp2, "(%d * 1)", matriz[count].cost);
        sprintf(line, "(%d * 1)", matriz[count].value);
        fprintf(salida, "%s", line);
        printf("Count: %d\n", count);
        if (objectsSelected[i].number != numObjects){
            fprintf(salida, "%s", "+");
            fprintf(temp, "%s", ", ");
            fprintf(temp2, "%s", "+");
        }
        sum += matriz[count].value;
        count++;
    }
    // Si quedan objetos que no se han representado.
    while(count < (numObjects)){
        fprintf(temp, "X_{%d} = 0", matriz[count].number);
        fprintf(temp2, "(%d * 0)", matriz[count].cost);
        sprintf(line, "(%d * 0)", matriz[count].value);
        fprintf(salida, "%s", line);
        count++;
        if (count < (numObjects)){
            fprintf(salida, "%s", "+");
            fprintf(temp, "%s", ", ");
            fprintf(temp2, "%s", "+");
        }
    }
    fprintf(temp, "%s", " \\]");
    fprintf(temp2, "\\leq %d", knapsacksize);
    fprintf(temp2, "%s", " \\]");
    fprintf(salida, "%s\n", " \\]");
    fprintf(salida, "\\[ \\textsc{\\normalsize Z}\\\\[0.5cm] = %d \\] \n", sum);
    fclose(temp);
    fclose(temp2);
    temp = fopen("temp.txt", "r");
    fseek(temp, 0, SEEK_SET);
    while((c=fgetc(temp)) != EOF){
        fprintf(salida, "%c", c);
    }
    fclose(temp);
    fprintf(salida, "%s\n", "\\newline Esta sujeto a: ");
    temp2 = fopen("temp2.txt", "r");
    fseek(temp2, 0, SEEK_SET);
    while((c=fgetc(temp2)) != EOF){
        fprintf(salida, "%c", c);
    }
    fclose(temp2);
    remove("temp.txt");
    remove("temp2.txt");
}


//#############################################################
// Imprimo la explicación del algoritmo dinámico, con los objetos, los respectivos Z y X.
//#######################################################
void introductionDynamicExample(FILE *salida, int numObjects, struct element matriz[]){
    char *line = malloc(100);
    fprintf(salida, "%s\n", "\\section{Algoritmo Dinámico $0/1$} \n\
        Es un problema bidimensional, cuyo objetivo es maximizar la ganancia. \n\
        En nuestro caso, queremos maximizar la cantidad de valores obtenidos por los objetos. \n\
        Para solucionar el problema vamos a hacer uso de una tabla (m+1) x n, donde n es la cantidad \n\
        de objetos disponibles y m es la cantidad de espacio disponible de la mochila. \n\
        Como se menciona en las restricciones del problema $n = 6$ y $m = 15$, por lo que tendremos \n\
        una tabla (16x6). \\newline \\newline \\newline \n\
        \\textbf{\\Large Fórmula Matemática} \n\
        \\[ \\textsc{\\normalsize MAX(Z)}\\\\[0.5cm] = \\sum_{i=1}^{6}x_{i}v_{i} \\] \n\
        \\ Sujeto a:  \n\
        \\[ \\sum x_{i}c_{i} \\leq 15 \\] \n\
        \\ En otras palabras tendremos:  \n\
        ");
    fprintf(salida, "%s", "\\[ \\textsc{\\normalsize Z}\\\\[0.5cm] = ");
    for (int i = 0; i < numObjects; ++i){
        sprintf(line, "%dx_{%d}", matriz[i].value, matriz[i].number);
        fprintf(salida, "%s", line);
        if (i < (numObjects - 1)){
            fprintf(salida, "%s", "+");
        }
    }
    fprintf(salida, "%s\n", " \\]");
    fprintf(salida, "%s\n", "Sujeto a: ");
    fprintf(salida, "%s", "\\[ ");
    for (int i = 0; i < numObjects; ++i){
        sprintf(line, "%dx_{%d}", matriz[i].cost, matriz[i].number);
        fprintf(salida, "%s", line);
        if (i < (numObjects - 1)){
            fprintf(salida, "%s", "+");
        }
    }
    fprintf(salida, "%s\n", " \\leq 15 \\]");
    fprintf(salida, "%s\n", "\\newline Ahora proseguimos realizando la tabla dinámica.");
}


//#############################################################
// Imprimo la explicación del algoritmo greedy básico. La información básica.
//#######################################################
void introductionGreedyExample(FILE *salida, int numObjects, struct element matriz[]){
    char *line = malloc(100);
    int count = 0;
    fprintf(salida, "%s\n", "\\section{Algoritmo Greedy Básico} \n\
        Es un algoritmo que soluciona problemas que a primera vista parece ser \n\
        óptimo. Es característico porque es muy sencillo de entender y explicar. \n\
        Se escogen los objetos más valiosos que entren en lo que sobra de la mochila. \n\
        \\[ Obj_{i} = (Costo, Valor), i = 0...n \\]");
    fprintf(salida, "%s", "\\[ ");
    for (int i = 0; i < numObjects; ++i){
        sprintf(line, "Obj_{%d} = (%d, %d)", matriz[i].number, matriz[i].cost, matriz[i].value);
        fprintf(salida, "%s", line);
        if (i < (numObjects - 1)){
            fprintf(salida, "%s", ", ");
        }
    }
    fprintf(salida, "%s\n", " \\]");
    fprintf(salida, "%s\n", "\\newline Ahora proseguimos realizando la tabla greedy básico.");
}


//#############################################################
// Imprimo la explicación del algoritmo greedy proporcional, la información básica.
//#######################################################
void introductionGreedyPropExample(FILE *salida, int numObjects, struct element matriz[]){
    char *line = malloc(100);
    int count = 0;
    fprintf(salida, "%s\n", "\\section{Algoritmo Greedy Proporcional} \n\
        Es un algoritmo que soluciona problemas que a primera vista parece ser \n\
        óptimo. Es característico porque es muy sencillo de entender y explicar. \n\
        Se escogen los objetos más valiosos que entren en lo que sobra de la mochila, ya sea por su rendimiento. \n\
        \\[ Obj_{i} = (Costo, Valor), i = 0...n \\]");
    fprintf(salida, "%s", "\\[ ");
    for (int i = 0; i < numObjects; ++i){
        sprintf(line, "Obj_{%d} = (%d, %d)", matriz[i].number, matriz[i].cost, matriz[i].value);
        fprintf(salida, "%s", line);
        if (i < (numObjects - 1)){
            fprintf(salida, "%s", ", ");
        }
    }
    fprintf(salida, "%s\n", " \\]");
    fprintf(salida, "%s\n", "\\newline Ahora proseguimos realizando la tabla greedy proporcional.");
}


//#############################################################
// Imprimo en una página el título Ejecuciones.
//#######################################################
void writeExecCase(FILE *salida){
    fprintf(salida, "%s\n", "\\newpage ");
    fprintf(salida, "%s\n", "\\begin{center}");
    fprintf(salida, "%s\n", "\\newcommand{\\HRule}{\\rule{\\linewidth}{0.5mm}}");
    fprintf(salida, "%s\n", "\\center");
    fprintf(salida, "%s\n", "\\HRule\\\\[6cm]");
    fprintf(salida, "%s\n", "\\HRule\\\\[0.4cm]");
    fprintf(salida, "%s\n", "\\HRule\\\\[0.4cm]");
    fprintf(salida, "%s\n", "\\HRule\\\\[0.4cm]");
    fprintf(salida, "%s\n", "\\HRule\\\\[0.4cm]");
    fprintf(salida, "{\\centering \\Huge\\bfseries Tiempo de ejecuciones}\\\\[0.4cm]\n");
    fprintf(salida, "%s\n", "\\HRule\\\\[0.4cm]");
    fprintf(salida, "%s\n", "\\HRule\\\\[0.4cm]");
    fprintf(salida, "%s\n", "\\HRule\\\\[0.4cm]");
    fprintf(salida, "%s\n", "\\HRule\\\\[6cm]");
    fprintf(salida, "%s\n", "\\HRule");
    fprintf(salida, "%s\n", "\\end{center}");
    fprintf(salida, "%s\n", "\\newpage ");
}


//#############################################################
// Imprimo en una página el título Estadísticas.
//#######################################################
void writeStadCase(FILE *salida){
    fprintf(salida, "%s\n", "\\newpage ");
    fprintf(salida, "%s\n", "\\begin{center}");
    fprintf(salida, "%s\n", "\\newcommand{\\HRule}{\\rule{\\linewidth}{0.5mm}}");
    fprintf(salida, "%s\n", "\\center");
    fprintf(salida, "%s\n", "\\HRule\\\\[6cm]");
    fprintf(salida, "%s\n", "\\HRule\\\\[0.4cm]");
    fprintf(salida, "%s\n", "\\HRule\\\\[0.4cm]");
    fprintf(salida, "%s\n", "\\HRule\\\\[0.4cm]");
    fprintf(salida, "%s\n", "\\HRule\\\\[0.4cm]");
    fprintf(salida, "{\\centering \\Huge\\bfseries Estadísticas}\\\\[0.4cm]\n");
    fprintf(salida, "%s\n", "\\HRule\\\\[0.4cm]");
    fprintf(salida, "%s\n", "\\HRule\\\\[0.4cm]");
    fprintf(salida, "%s\n", "\\HRule\\\\[0.4cm]");
    fprintf(salida, "%s\n", "\\HRule\\\\[6cm]");
    fprintf(salida, "%s\n", "\\HRule");
    fprintf(salida, "%s\n", "\\end{center}");
    fprintf(salida, "%s\n", "\\newpage ");
}

//#############################################################
// Imprimo en una página el título de la iteración.
//#######################################################
void writeCase(FILE *salida, int iteration){
    fprintf(salida, "%s\n", "\\begin{center}");
    fprintf(salida, "%s\n", "\\newcommand{\\HRule}{\\rule{\\linewidth}{0.5mm}}");
    fprintf(salida, "%s\n", "\\center");
    fprintf(salida, "%s\n", "\\HRule\\\\[6cm]");
    fprintf(salida, "%s\n", "\\HRule\\\\[0.4cm]");
    fprintf(salida, "%s\n", "\\HRule\\\\[0.4cm]");
    fprintf(salida, "%s\n", "\\HRule\\\\[0.4cm]");
    fprintf(salida, "%s\n", "\\HRule\\\\[0.4cm]");
    fprintf(salida, "{\\centering \\Huge\\bfseries Iteración %d}\\\\[0.4cm]\n", iteration);
    fprintf(salida, "%s\n", "\\HRule\\\\[0.4cm]");
    fprintf(salida, "%s\n", "\\HRule\\\\[0.4cm]");
    fprintf(salida, "%s\n", "\\HRule\\\\[0.4cm]");
    fprintf(salida, "%s\n", "\\HRule\\\\[6cm]");
    fprintf(salida, "%s\n", "\\HRule");
    fprintf(salida, "%s\n", "\\end{center}");
    fprintf(salida, "%s\n", "\\newpage ");
}


//#############################################################
// Almaceno en el archivo target lo que tenga escrito el archivo source
//#######################################################
void saveLatex(FILE *target, FILE *source, char *name){
    char c;
    source = fopen(name, "r");
    fseek(source, 0, SEEK_SET);
    while((c=fgetc(source)) != EOF){
        fprintf(target, "%c", c); // Escriba caracter a caracter en el target.
    }
    fclose(source);
}


//#############################################################
// Cambie las coordenadas del documento. (Almacenar las tablas requiere todo el espacio de la pantalla)
//#######################################################
void changeGeometry(FILE *salida, int change){
    if (change){
        fprintf(salida, "%s\n", "\\newgeometry{left=1.5cm,right=1.5cm,top=3.5cm,bottom=3.5cm}");
    }else{
        fprintf(salida, "%s\n", "\\newgeometry{left=3.5cm,right=3.5cm,top=3.5cm,bottom=3.5cm}");
    }
}


//#############################################################
// Genere una tabla de ejecución. 
//#######################################################
void generateExecutionTable(FILE *temp, double mat[][10], char* name){

    fprintf(temp, "%s\n", "\\definecolor{Gray}{gray}{0.9}");
    fprintf(temp, "%s\n", "\\definecolor{LightCyan}{rgb}{0.88,1,1}");
    fprintf(temp, "%s\n", "\\begin{center}");
    fprintf(temp, "%s\n", "\\begin{table}\\renewcommand{\\arraystretch}{2.5}");
    fprintf(temp, "%s", "\\caption{\\large \\textbf{");
    fprintf(temp, "%s}}\n", name);
    fprintf(temp, "%s\n", "\\centering");
    fprintf(temp, "%s", "\\begin{tabular} { |m{0.5cm}|m{1.3cm}|m{1.3cm}|m{1.3cm}|m{1.3cm}|");
    fprintf(temp, "%s\n", "m{1.3cm}|m{1.3cm}|m{1.3cm}|m{1.3cm}|m{1.3cm}|m{1.3cm}|} ");
    fprintf(temp, "%s\n", "\\hline");
    fprintf(temp, "%s\n", "\\rowcolor{Gray}");
    fprintf(temp, "%s", "\\centering \\textbf{X} & ");
    fprintf(temp, "%s", "\\centering \\textbf{10} & \\centering \\textbf{20} & \\centering \\textbf{30}\\ & ");
    fprintf(temp, "%s", "\\centering \\textbf{40} & \\centering \\textbf{50} & \\centering \\textbf{60}\\ & ");
    fprintf(temp, "%s", "\\centering \\textbf{70} & \\centering \\textbf{80} & \\centering \\textbf{90}\\ & ");
    fprintf(temp, "%s", "\\textbf{100} \\\\");
    fprintf(temp, "%s\n", "\\hline");


    for(int i=0; i < 10; i++){

        int pos = (i + 1) * 100;
        fprintf(temp, "\\cellcolor{Gray}%d", pos);
        for(int j=0; j < 10; j++){
            fprintf(temp, " & %.3f", mat[i][j]);
            fprintf(temp, "%s", "$ms$");
        }
        fprintf(temp, "%s\n", " \\\\");
        fprintf(temp, "%s\n", "\\hline");
    }
    fprintf(temp, "%s\n", "\\end{tabular} \\\\");
    fprintf(temp, "%s\n", "\\end{table}");
    fprintf(temp, "%s\n", "\\end{center}");
    fprintf(temp, "%s\n", "\\newpage ");
}


//#############################################################
// Genere una tabla de estadísticas. 
//#######################################################
void generateStadisticTable(FILE *temp, float mat[][10], char* name){

    fprintf(temp, "%s\n", "\\definecolor{Gray}{gray}{0.9}");
    fprintf(temp, "%s\n", "\\definecolor{LightCyan}{rgb}{0.88,1,1}");
    fprintf(temp, "%s\n", "\\begin{center}");
    fprintf(temp, "%s\n", "\\begin{table}\\renewcommand{\\arraystretch}{2.5}");
    fprintf(temp, "%s", "\\caption{\\large \\textbf{");
    fprintf(temp, "%s}}\n", name);
    fprintf(temp, "%s\n", "\\centering");
    fprintf(temp, "%s", "\\begin{tabular} { |m{0.5cm}|m{1.3cm}|m{1.3cm}|m{1.3cm}|m{1.3cm}|");
    fprintf(temp, "%s\n", "m{1.3cm}|m{1.3cm}|m{1.3cm}|m{1.3cm}|m{1.3cm}|m{1.3cm}|} ");
    fprintf(temp, "%s\n", "\\hline");
    fprintf(temp, "%s\n", "\\rowcolor{Gray}");
    fprintf(temp, "%s", "\\centering \\textbf{X} & ");
    fprintf(temp, "%s", "\\centering \\textbf{10} & \\centering \\textbf{20} & \\centering \\textbf{30}\\ & ");
    fprintf(temp, "%s", "\\centering \\textbf{40} & \\centering \\textbf{50} & \\centering \\textbf{60}\\ & ");
    fprintf(temp, "%s", "\\centering \\textbf{70} & \\centering \\textbf{80} & \\centering \\textbf{90}\\ & ");
    fprintf(temp, "%s", "\\textbf{100} \\\\");
    fprintf(temp, "%s\n", "\\hline");


    for(int i=0; i < 10; i++){

        int pos = (i + 1) * 100;
        fprintf(temp, "\\cellcolor{Gray}%d", pos);
        for(int j=0; j < 10; j++){
            fprintf(temp, " & %.2f", mat[i][j]);
            fprintf(temp, "%s", "\\%");
        }
        fprintf(temp, "%s\n", " \\\\");
        fprintf(temp, "%s\n", "\\hline");
    }
    fprintf(temp, "%s\n", "\\end{tabular} \\\\");
    fprintf(temp, "%s\n", "\\end{table}");
    fprintf(temp, "%s\n", "\\end{center}");
    fprintf(temp, "%s\n", "\\newpage ");
}

//#############################################################
// Genere una tabla de resultados.
//#######################################################
void generateResultsTable(FILE *temp, int mat[][10], char* name){

    fprintf(temp, "%s\n", "\\definecolor{Gray}{gray}{0.9}");
    fprintf(temp, "%s\n", "\\definecolor{LightCyan}{rgb}{0.88,1,1}");
    fprintf(temp, "%s\n", "\\begin{center}");
    fprintf(temp, "%s\n", "\\begin{table}\\renewcommand{\\arraystretch}{2.5}");
    fprintf(temp, "%s", "\\caption{\\large \\textbf{");
    fprintf(temp, "%s}}\n", name);
    fprintf(temp, "%s\n", "\\centering");
    fprintf(temp, "%s", "\\begin{tabular} { |m{0.5cm}|m{1.3cm}|m{1.3cm}|m{1.3cm}|m{1.3cm}|");
    fprintf(temp, "%s\n", "m{1.3cm}|m{1.3cm}|m{1.3cm}|m{1.3cm}|m{1.3cm}|m{1.3cm}|} ");
    fprintf(temp, "%s\n", "\\hline");
    fprintf(temp, "%s\n", "\\rowcolor{Gray}");
    fprintf(temp, "%s", "\\centering \\textbf{X} & ");
    fprintf(temp, "%s", "\\centering \\textbf{10} & \\centering \\textbf{20} & \\centering \\textbf{30}\\ & ");
    fprintf(temp, "%s", "\\centering \\textbf{40} & \\centering \\textbf{50} & \\centering \\textbf{60}\\ & ");
    fprintf(temp, "%s", "\\centering \\textbf{70} & \\centering \\textbf{80} & \\centering \\textbf{90}\\ & ");
    fprintf(temp, "%s", "\\textbf{100} \\\\");
    fprintf(temp, "%s\n", "\\hline");


    for(int i=0; i < 10; i++){

        int pos = (i + 1) * 100;
        fprintf(temp, "\\cellcolor{Gray}%d", pos);
        for(int j=0; j < 10; j++){
            fprintf(temp, " & \\Large %d", mat[i][j]);
        }
        fprintf(temp, "%s\n", " \\\\");
        fprintf(temp, "%s\n", "\\hline");
    }
    fprintf(temp, "%s\n", "\\end{tabular} \\\\");
    fprintf(temp, "%s\n", "\\end{table}");
    fprintf(temp, "%s\n", "\\end{center}");
    fprintf(temp, "%s\n", "\\newpage ");
}


//#############################################################
// Almacene en latex el tiempo de ejecución.
//#######################################################
void executionTime(FILE *salida, double time){
    fprintf(salida, "%s", "\\newline El algoritmo tarda aproximadamente: ");
    fprintf(salida, "%f", time);
    fprintf(salida, "%s\n", " segundos en ejecutarse");
}

*/