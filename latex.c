//#############################################################
// Inicializo los datos fijos que va a tener el documento.
//#############################################################
void createLatex(FILE *output){
    fprintf(output, "%s\n", "\\documentclass[10pt,letterpaper]{article}");
    fprintf(output, "%s\n", "\\usepackage[utf8]{inputenc}");
    fprintf(output, "%s\n", "\\usepackage[spanish]{babel}");
    fprintf(output, "%s\n", "\\usepackage{graphicx}");
    fprintf(output, "%s\n", "\\usepackage{booktabs}");
    fprintf(output, "%s\n", "\\usepackage{multicol}");
    fprintf(output, "%s\n", "\\usepackage{multirow}");
    fprintf(output, "%s\n", "\\usepackage{xspace}");
    fprintf(output, "%s\n", "\\usepackage{color, colortbl}");
    fprintf(output, "%s\n", "\\usepackage{underscore}");
    fprintf(output, "%s\n", "\\usepackage{tabu}");
    fprintf(output, "%s\n", "\\usepackage{url}");
    fprintf(output, "%s\n", "\\usepackage{ragged2e}");
    fprintf(output, "%s\n", "\\usepackage{verbatim}");
    fprintf(output, "%s\n", "\\usepackage{mathdots} ");
    fprintf(output, "%s\n", "\\usepackage{amsmath, amssymb, amsbsy, amsfonts} ");
    fprintf(output, "%s\n", "\\usepackage[left=3.5cm,right=3.5cm,top=3.5cm,bottom=3.5cm]{geometry}");
    fprintf(output, "%s\n", "\\setlength{\\parskip}{\\baselineskip}");
}


//#############################################################
// Genero la portada.
//#############################################################
void cover(FILE *output){
    fprintf(output, "%s\n", "\\begin{document} \n\
    \\begin{titlepage} \n\
    \\newcommand{\\HRule}{\\rule{\\linewidth}{0.5mm}} \n\
    \\center   \n\
    \\textsc{\\Huge Instituto Tecnológico de Costa Rica}\\\\[1.5cm] \n\
    \\textsc{\\normalsize PROYECTO DE INVESTIGACIÓN DE OPERACIONES}\\\\[0.5cm] \n\
    \\textsc{\\normalsize PROYECTO 1}\\\\[0.5cm] \n\
    \\HRule\\\\[0.4cm] \n\
    {\\huge\\bfseries \\vspace{1cm} KNAPSACK PROBLEM}\\\\[0.4cm] \n\
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

//#############################################################
// Imprimo la información que aparece por defecto en el modo Ejemplo.
//#############################################################
void informationExample(FILE *output){
    fprintf(output, "%s\n", "\\titlepage{\\textbf{Modo Ejemplo:}} \\newline \\newline \n\
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
void informationExperiment(FILE *output, int n){

    fprintf(output, "%s\n", "\\titlepage{\\textbf{Modo Experimento:}} \\newline \\newline ");
    fprintf(output, "Se resolverán %d ", n);
    fprintf(output, "%s\n", "problemas de mochila por medio de diversos algoritmos que nos \n\
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
void createObjectTable(FILE *output, int numObjects, struct element matriz[]){
    char *line = malloc(100);
    fprintf(output, "%s\n", "Se muestra a continuación la tabla de objetos con su respectivo costo (peso) y valor \n\
        que fueron asignados aleatoriamente cumpliendo con las restricciones: ");
    fprintf(output, "%s\n", "\\definecolor{Gray}{gray}{0.9}");
    fprintf(output, "%s\n", "\\definecolor{LightCyan}{rgb}{0.88,1,1}");
    fprintf(output, "%s\n", "\\begin{center}");
    fprintf(output, "%s\n", "\\begin{tabu} to 0.6\\textwidth { | X[l] | X[l] | X[l] | } ");
    fprintf(output, "%s\n", "\\hline");
    fprintf(output, "%s\n", "\\rowcolor{Gray}");
    fprintf(output, "%s\n", "\\textbf{Nombre} & \\textbf{Costo} & \\textbf{Valor}\\\\");
    fprintf(output, "%s\n", "\\hline");

    for(int i=0; i < numObjects; i++){
        sprintf(line, "Object %d & %d & %d \\\\", matriz[i].number, matriz[i].cost, matriz[i].value);
        fprintf(output, "%s\n", line);
        fprintf(output, "%s\n", "\\hline");
    }
    fprintf(output, "%s\n", "\\end{tabu} \\\\");
    fprintf(output, "%s\n", "\\end{center}");
    free(line);
}

//#############################################################
// Creo la tabla dinámica. Se usa solamente en el modo Ejemplo.
//#######################################################

void createDynamicTable(FILE *output, int maxRow, int maxColumn, struct element matriz[]){
    char *line = malloc(100);
    fprintf(output, "%s\n", "\\definecolor{Gray}{gray}{0.5}");
    fprintf(output, "%s\n", "\\definecolor{GreenBlack}{RGB}{2,80,0}");
    fprintf(output, "%s\n", "\\begin{center}");
    fprintf(output, "%s", "\\begin{tabu} to 1.0\\textwidth { |");
    for(int i=0; i < (maxColumn + 1); i++){
        fprintf(output, "%s", " c |");
    }
    fprintf(output, "%s\n", " }");
    fprintf(output, "%s\n", "\\hline");
    fprintf(output, "%s", "\\cellcolor{Gray}\\color{black}\\textbf{X} & ");
    for(int i=0; i < maxColumn; i++){
        sprintf(line, "\\cellcolor{Gray}\\color{black}\\textbf{%d}", matriz[i].number);
        fprintf(output, "%s", line);
        if (i+1 < maxColumn){
            fprintf(output, "%s", " & ");
        }else{
            fprintf(output, "%s\n", " \\\\ ");
        }
    }
    fprintf(output, "%s\n", "\\hline");
    for(int i=0; i < maxRow; i++){
        fprintf(output, "\\cellcolor{Gray}\\color{black}%d & ", i);
        for(int j=0; j < maxColumn; j++){
            if(table[i][j].state){
                fprintf(output, "%s", "\\textcolor{GreenBlack}{ ");
            }else{
                fprintf(output, "%s", "\\textcolor{red}{ ");
            }
            
            fprintf(output, "%d}", table[i][j].numb);
            if (j+1 < maxColumn){
                fprintf(output, "%s", " & ");
            }else{
                fprintf(output, "%s\n", " \\\\ ");
            }
        }
        fprintf(output, "%s\n", "\\hline");
    }
    fprintf(output, "%s\n", "\\end{tabu} \\\\");
    fprintf(output, "%s\n", "\\end{center}");
    free(line);
}


//#############################################################
// Imprimo los resultados
//#######################################################
void results(FILE *output, int numObjects, int knapsacksize, struct element matriz[]){
    FILE *temp, *temp2;
    char c;
    temp = fopen("temp.txt", "w");
    temp2 = fopen("temp2.txt", "w");
    int count = 0, sum = 0;
    char *letters = "ABCDEF";
    char *line = malloc(100);
    fprintf(output, "%s\n", "El resultado es el siguiente: ");
    fprintf(output, "%s\n", "Las soluciones de X son las siguientes: ");
    fprintf(output, "%s", "\\[ \\textsc{\\normalsize Z}\\\\[0.5cm] = ");
    fprintf(temp, "%s", "\\[ " );
    fprintf(temp2, "%s", "\\[ ");
    for(int i = lenSelected - 1; i >= 0; i--){
        while(count < (objectsSelected[i].number - 1)){
            fprintf(temp, "X_{%d} = 0, ", matriz[count].number);
            fprintf(temp2, "(%d * 0) +", matriz[count].cost);
            sprintf(line, "(%d * 0) + ", matriz[count].value);
            fprintf(output, "%s", line);
            count++;
        }
        fprintf(temp, "X_{%d} = 1", matriz[count].number);
        fprintf(temp2, "(%d * 1)", matriz[count].cost);
        sprintf(line, "(%d * 1)", matriz[count].value);
        fprintf(output, "%s", line);
        printf("Count: %d\n", count);
        if (objectsSelected[i].number != numObjects){
            fprintf(output, "%s", "+");
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
        fprintf(output, "%s", line);
        count++;
        if (count < (numObjects)){
            fprintf(output, "%s", "+");
            fprintf(temp, "%s", ", ");
            fprintf(temp2, "%s", "+");
        }
    }
    fprintf(temp, "%s", " \\]");
    fprintf(temp2, "\\leq %d", knapsacksize);
    fprintf(temp2, "%s", " \\]");
    fprintf(output, "%s\n", " \\]");
    fprintf(output, "\\[ \\textsc{\\normalsize Z}\\\\[0.5cm] = %d \\] \n", sum);
    fclose(temp);
    fclose(temp2);
    temp = fopen("temp.txt", "r");
    fseek(temp, 0, SEEK_SET);
    while((c=fgetc(temp)) != EOF){
        fprintf(output, "%c", c);
    }
    fclose(temp);
    fprintf(output, "%s\n", "\\newline Esta sujeto a: ");
    temp2 = fopen("temp2.txt", "r");
    fseek(temp2, 0, SEEK_SET);
    while((c=fgetc(temp2)) != EOF){
        fprintf(output, "%c", c);
    }
    fclose(temp2);
    remove("temp.txt");
    remove("temp2.txt");
}


//#############################################################
// Imprimo la explicación del algoritmo dinámico, con los objetos, los respectivos Z y X.
//#######################################################
void introductionDynamicExample(FILE *output, int numObjects, struct element matriz[]){
    char *line = malloc(100);
    fprintf(output, "%s\n", "\\section{Algoritmo Dinámico $0/1$} \n\
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
    fprintf(output, "%s", "\\[ \\textsc{\\normalsize Z}\\\\[0.5cm] = ");
    for (int i = 0; i < numObjects; ++i){
        sprintf(line, "%dx_{%d}", matriz[i].value, matriz[i].number);
        fprintf(output, "%s", line);
        if (i < (numObjects - 1)){
            fprintf(output, "%s", "+");
        }
    }
    fprintf(output, "%s\n", " \\]");
    fprintf(output, "%s\n", "Sujeto a: ");
    fprintf(output, "%s", "\\[ ");
    for (int i = 0; i < numObjects; ++i){
        sprintf(line, "%dx_{%d}", matriz[i].cost, matriz[i].number);
        fprintf(output, "%s", line);
        if (i < (numObjects - 1)){
            fprintf(output, "%s", "+");
        }
    }
    fprintf(output, "%s\n", " \\leq 15 \\]");
    fprintf(output, "%s\n", "\\newline Ahora proseguimos realizando la tabla dinámica.");
}


//#############################################################
// Imprimo la explicación del algoritmo greedy básico. La información básica.
//#######################################################
void introductionGreedyExample(FILE *output, int numObjects, struct element matriz[]){
    char *line = malloc(100);
    int count = 0;
    fprintf(output, "%s\n", "\\section{Algoritmo Greedy Básico} \n\
        Es un algoritmo que soluciona problemas que a primera vista parece ser \n\
        óptimo. Es característico porque es muy sencillo de entender y explicar. \n\
        Se escogen los objetos más valiosos que entren en lo que sobra de la mochila. \n\
        \\[ Obj_{i} = (Costo, Valor), i = 0...n \\]");
    fprintf(output, "%s", "\\[ ");
    for (int i = 0; i < numObjects; ++i){
        sprintf(line, "Obj_{%d} = (%d, %d)", matriz[i].number, matriz[i].cost, matriz[i].value);
        fprintf(output, "%s", line);
        if (i < (numObjects - 1)){
            fprintf(output, "%s", ", ");
        }
    }
    fprintf(output, "%s\n", " \\]");
    fprintf(output, "%s\n", "\\newline Ahora proseguimos realizando la tabla greedy básico.");
}


//#############################################################
// Imprimo la explicación del algoritmo greedy proporcional, la información básica.
//#######################################################
void introductionGreedyPropExample(FILE *output, int numObjects, struct element matriz[]){
    char *line = malloc(100);
    int count = 0;
    fprintf(output, "%s\n", "\\section{Algoritmo Greedy Proporcional} \n\
        Es un algoritmo que soluciona problemas que a primera vista parece ser \n\
        óptimo. Es característico porque es muy sencillo de entender y explicar. \n\
        Se escogen los objetos más valiosos que entren en lo que sobra de la mochila, ya sea por su rendimiento. \n\
        \\[ Obj_{i} = (Costo, Valor), i = 0...n \\]");
    fprintf(output, "%s", "\\[ ");
    for (int i = 0; i < numObjects; ++i){
        sprintf(line, "Obj_{%d} = (%d, %d)", matriz[i].number, matriz[i].cost, matriz[i].value);
        fprintf(output, "%s", line);
        if (i < (numObjects - 1)){
            fprintf(output, "%s", ", ");
        }
    }
    fprintf(output, "%s\n", " \\]");
    fprintf(output, "%s\n", "\\newline Ahora proseguimos realizando la tabla greedy proporcional.");
}


//#############################################################
// Imprimo en una página el título Ejecuciones.
//#######################################################
void writeExecCase(FILE *output){
    fprintf(output, "%s\n", "\\newpage ");
    fprintf(output, "%s\n", "\\begin{center}");
    fprintf(output, "%s\n", "\\newcommand{\\HRule}{\\rule{\\linewidth}{0.5mm}}");
    fprintf(output, "%s\n", "\\center");
    fprintf(output, "%s\n", "\\HRule\\\\[6cm]");
    fprintf(output, "%s\n", "\\HRule\\\\[0.4cm]");
    fprintf(output, "%s\n", "\\HRule\\\\[0.4cm]");
    fprintf(output, "%s\n", "\\HRule\\\\[0.4cm]");
    fprintf(output, "%s\n", "\\HRule\\\\[0.4cm]");
    fprintf(output, "{\\centering \\Huge\\bfseries Tiempo de ejecuciones}\\\\[0.4cm]\n");
    fprintf(output, "%s\n", "\\HRule\\\\[0.4cm]");
    fprintf(output, "%s\n", "\\HRule\\\\[0.4cm]");
    fprintf(output, "%s\n", "\\HRule\\\\[0.4cm]");
    fprintf(output, "%s\n", "\\HRule\\\\[6cm]");
    fprintf(output, "%s\n", "\\HRule");
    fprintf(output, "%s\n", "\\end{center}");
    fprintf(output, "%s\n", "\\newpage ");
}


//#############################################################
// Imprimo en una página el título Estadísticas.
//#######################################################
void writeStadCase(FILE *output){
    fprintf(output, "%s\n", "\\newpage ");
    fprintf(output, "%s\n", "\\begin{center}");
    fprintf(output, "%s\n", "\\newcommand{\\HRule}{\\rule{\\linewidth}{0.5mm}}");
    fprintf(output, "%s\n", "\\center");
    fprintf(output, "%s\n", "\\HRule\\\\[6cm]");
    fprintf(output, "%s\n", "\\HRule\\\\[0.4cm]");
    fprintf(output, "%s\n", "\\HRule\\\\[0.4cm]");
    fprintf(output, "%s\n", "\\HRule\\\\[0.4cm]");
    fprintf(output, "%s\n", "\\HRule\\\\[0.4cm]");
    fprintf(output, "{\\centering \\Huge\\bfseries Estadísticas}\\\\[0.4cm]\n");
    fprintf(output, "%s\n", "\\HRule\\\\[0.4cm]");
    fprintf(output, "%s\n", "\\HRule\\\\[0.4cm]");
    fprintf(output, "%s\n", "\\HRule\\\\[0.4cm]");
    fprintf(output, "%s\n", "\\HRule\\\\[6cm]");
    fprintf(output, "%s\n", "\\HRule");
    fprintf(output, "%s\n", "\\end{center}");
    fprintf(output, "%s\n", "\\newpage ");
}

//#############################################################
// Imprimo en una página el título de la iteración.
//#######################################################
void writeCase(FILE *output, int iteration){
    fprintf(output, "%s\n", "\\begin{center}");
    fprintf(output, "%s\n", "\\newcommand{\\HRule}{\\rule{\\linewidth}{0.5mm}}");
    fprintf(output, "%s\n", "\\center");
    fprintf(output, "%s\n", "\\HRule\\\\[6cm]");
    fprintf(output, "%s\n", "\\HRule\\\\[0.4cm]");
    fprintf(output, "%s\n", "\\HRule\\\\[0.4cm]");
    fprintf(output, "%s\n", "\\HRule\\\\[0.4cm]");
    fprintf(output, "%s\n", "\\HRule\\\\[0.4cm]");
    fprintf(output, "{\\centering \\Huge\\bfseries Iteración %d}\\\\[0.4cm]\n", iteration);
    fprintf(output, "%s\n", "\\HRule\\\\[0.4cm]");
    fprintf(output, "%s\n", "\\HRule\\\\[0.4cm]");
    fprintf(output, "%s\n", "\\HRule\\\\[0.4cm]");
    fprintf(output, "%s\n", "\\HRule\\\\[6cm]");
    fprintf(output, "%s\n", "\\HRule");
    fprintf(output, "%s\n", "\\end{center}");
    fprintf(output, "%s\n", "\\newpage ");
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
void changeGeometry(FILE *output, int change){
    if (change){
        fprintf(output, "%s\n", "\\newgeometry{left=1.5cm,right=1.5cm,top=3.5cm,bottom=3.5cm}");
    }else{
        fprintf(output, "%s\n", "\\newgeometry{left=3.5cm,right=3.5cm,top=3.5cm,bottom=3.5cm}");
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
void executionTime(FILE *output, double time){
    fprintf(output, "%s", "\\newline El algoritmo tarda aproximadamente: ");
    fprintf(output, "%f", time);
    fprintf(output, "%s\n", " segundos en ejecutarse");
}


//#############################################################
// Cierre el documento de latex y ejecutelo.
//#######################################################
void closeLatex(FILE *output){
    fprintf(output, "%s\n", "\\end{document}");
    fclose(output);
    system("pdflatex knapsack.tex && evince -s knapsack.pdf &");        
}
