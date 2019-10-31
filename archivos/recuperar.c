#include<stdio.h>

int
main ()
{
  FILE *fp = NULL;
  int entero;
  float promedio;
  char cadena[300];

  fp = fopen ("nuevo.datos", "r");

  if (fp == NULL)
    {
      printf ("No se puede abrir\n");
      return 0;
    }
  fgets (cadena, 300, fp);
  fscanf (fp, "%d", &entero);
  fscanf (fp, "%f", &promedio);

  printf ("Datos leido del archivo: %s, %d, %f", cadena, entero, promedio);

  fclose (fp);

  return 0;
}
