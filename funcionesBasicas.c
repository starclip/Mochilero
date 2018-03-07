
// Esta funcion se encarga de concatenar un caracter a un string
char *concatenar(char *destino, char caracter){
   char *cad;
   int i;
   cad = realloc(destino, strlen(destino) + 2);
   for (i = 0; cad[i] != '\0'; i++);           /* Encontrar el fin de destino */
   cad[i++] = caracter;                        /* Añadimos el caracter */
   cad[i] = '\0';                              /* Añadimos el caracter de fin de destino */
   return destino;
}