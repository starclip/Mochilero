

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

void greedyTable(FILE *output){
    char c;
    FILE *greedyFile;
    greedyFile = fopen("greedy.txt", "r");
    fseek(greedyFile, 0, SEEK_SET);
    while((c=fgetc(greedyFile)) != EOF){
        fprintf(output, "%c", c);
    }
    fclose(greedyFile);
}

void propGreedyTable(FILE *output){
    char c;
    FILE *greedyFile;
    greedyFile = fopen("greedyProp.txt", "r");
    fseek(greedyFile, 0, SEEK_SET);
    while((c=fgetc(greedyFile)) != EOF){
        fprintf(output, "%c", c);
    }
    fclose(greedyFile);
}


void executionTime(FILE *output, double time){
    fprintf(output, "%s", "\\newline El algoritmo tarda aproximadamente: ");
    fprintf(output, "%f", time);
    fprintf(output, "%s\n", " segundos en ejecutarse");
}


void closeLatex(FILE *output){
    fprintf(output, "%s\n", "\\end{document}");
    fclose(output);
    system("pdflatex knapsack.tex && evince -s knapsack.pdf &");        
}
