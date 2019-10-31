#include<stdio.h>

int
main ()
{
  FILE *fp = NULL;
  int entero = 2019;
  float promedio = 7.6f;

  fp = fopen ("nuevo.datos", "w");

  if (fp == NULL)
    {
      printf ("No se puede abrir\n");
      return 0;
    }

  fprintf (fp, "Hola mundo!\n");
  fprintf (fp, "%d\n", entero);
  fprintf (fp, "%f\n", promedio);

  fclose (fp);

  return 0;
}
