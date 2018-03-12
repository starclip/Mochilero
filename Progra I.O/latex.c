

void createLatex(FILE *output){
    fprintf(output, "%s\n", "\\documentclass[10pt]{beamer}");
    fprintf(output, "%s\n", "\\usepackage{appendixnumberbeamer}");
    fprintf(output, "%s\n", "\\usetheme[progressbar=frametitle]{metropolis}");
    fprintf(output, "%s\n", "\\usepackage[utf8]{inputenc}");
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
    fprintf(output, "%s\n", "\\usecolortheme{albatross}");
    fprintf(output, "%s\n", "\\usepackage{amsfonts} ");
    fprintf(output, "%s\n", "\\setbeamercolor{normal text}{bg=black, fg=white}");
    fprintf(output, "%s\n", "\\setbeamerfont{normal text}{size=3pt}");
}

void cover(FILE *output){
    fprintf(output, "%s\n", "\\begin{document} \n\
    \\begin{titlepage} \n\
    \\center   \n\
    \\textsc{\\normalsize Instituto Tecnológico de Costa Rica}\\\\[0.5cm] \n\
    \\textsc{\\normalsize PROYECTO DE INVESTIGACIÓN DE OPERACIONES}\\\\[0.1cm] \n\
    \\textsc{\\normalsize PROYECTO 1}\\\\[0.5cm] \n\
    {\\huge\\bfseries \\vspace{1cm} KNAPSACK PROBLEM}\\\\[0.4cm] \n\
    \\vspace{1cm} \n\
        \\begin{minipage}{0.4\\textwidth} \n\
        \\begin{flushleft} \n\
            \\footnotesize \n\
            \\textit{Estudiantes} \\ \n\
            Jason Barrantes Arce \n\
            \\textsc{2015048456} \n\
        \\end{flushleft} \n\
    \\end{minipage} \n\
    ~ \n\
    \\begin{minipage}{0.4\\textwidth} \n\
        \\begin{flushright} \n\
            \\footnotesize \n\
            \\textit{Profesor}\\ \n\
            Dr. Francisco Torres Rojas \n\
            \\textsc{ } \n\
        \\end{flushright} \n\
    \\end{minipage} \n\
    ~ \n\
        \\begin{minipage}{0.4\\textwidth} \n\
        \\begin{flushleft} \n\
            \\footnotesize \n\
            Steven Bonilla Zúñiga \n\
            \\textsc{2015} \n\
        \\end{flushleft} \n\
    \\end{minipage} \n\
    \\end{titlepage} \n\
    ");
}

void createObjectTable(FILE *output, int numObjects, struct element matriz[]){
    char *line = malloc(100);
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


void closeLatex(FILE *output){
    fprintf(output, "%s\n", "\\end{document}");
    fclose(output);
    system("pdflatex knapsack.tex && evince -s knapsack.pdf &");        
}
