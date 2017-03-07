#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main()
{
  char banner[]={"ejemplo banner..."};
  unsigned short longitud, indice, espacio, repite, resto;

  longitud=strlen(banner);
  for (repite=1; repite<=3; repite++) /* repite el proceso 3 veces */
  {
/* ******** IMPRIME EN ORDEN DE IZQUIERDA A DERECHA Y LUEGO DESPLAZA ******** */
     for(resto=0; resto<=longitud; resto++) /* para caracteres restantes a imprimir */
     {   for (indice=0; indice<=longitud-1-resto; indice++) /* seleccion de indices evitando restantes */
        {
           printf("%c", banner[indice]); /* imprime indice */
           if (!resto) usleep(100000); /* demora el proceso */
        }
        for(espacio=1; espacio<=longitud-resto-1; espacio++)
           printf("\b"); /* retrocede */

        if (resto) usleep(100000); /* demora el proceso */
        printf("\b "); /* borra el caracter actual */
     }

     for(espacio=1; espacio<=longitud; espacio++) /* borra todos los caracteres presentados */
        printf("\b\b ");
     printf("\b"); /* se coloca al inicio del desplegado */

/* ************************************************************************** */
  }

  return 0;
}

