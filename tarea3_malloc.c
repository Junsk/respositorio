#include <stdio.h>
#include <stdlib.h>
int main ()
{
int *arreglo,*arreglo2,num=7, cont;

	arreglo = (int *)malloc (num * sizeof(int));
	
	arreglo2 = (int *)malloc (num * sizeof(int));

	if (arreglo!=NULL) {
		for (cont=0 ; cont<num ; cont++){
		printf("\t%p %d \n",(arreglo+cont),*(arreglo+cont));
		}
	}

	printf("Aumentando el tamaño del conjunto al triple.\n");
	num *= 3;
		arreglo = (int *)realloc (arreglo,num*sizeof(int));
	if (arreglo != NULL) {
		for (cont=0 ; cont < num ; cont++){
		printf("\t%p %d \n",(arreglo+cont),*(arreglo+cont));
		}
	printf("Se libero el espacio reservado.\n");
	free (arreglo);
	}
return 0;
}
