/**
 \file contigua.c
 \author Rafael Norman Saucedo Delgado
 \version 1.0
 \date 13 / 09 /2019
 \copyright GNU Public License v3.

 Implementación de las funciones básicas
 de una lista de memoria contigua: 
 + insertar
 + eliminar
 + mostrar 
*/
#include "contigua.h"

void
insertar (struct Contigua **lista, int dato)
{
  int *temporal = NULL;
  int i = 0;
  if (lista == NULL)
    {
      return;
    }
  if (*lista == NULL)
    {
      *lista = (struct Contigua *) malloc (sizeof (struct Contigua));
      if (*lista == NULL)
	{
	  return;
	}
      (*lista)->datos = (int *) malloc (sizeof (int) * 8);
      if ((*lista)->datos == NULL)
	{
	  free (*lista);
	  return;
	}
      (*lista)->cuantos = 8;	/*<- inicia con ocho lugares */
      (*lista)->actual = 0;	/*<- es el primer dato, posición cero */
      *((*lista)->datos) = dato;	/*<- se coloca el dato en la primera posición */
      return;
    }
  if ((*lista)->cuantos == (*lista)->actual + 1)
    {
      /* esta llena y hay que pasar los datos a un lugar más grande, del doble de tamaño */
      temporal = (int *) malloc (sizeof (int) * (*lista)->cuantos * 2);
      if (temporal == NULL)
	{
	  return;
	}
      for (i = 0; i < (*lista)->cuantos; i++)
	{
	  *(temporal + i) = *((*lista)->datos + i);
	}
      free ((*lista)->datos);
      (*lista)->datos = temporal;
      (*lista)->cuantos = (*lista)->cuantos * 2;
    }
  (*lista)->actual = (*lista)->actual + 1;
  *((*lista)->datos + (*lista)->actual) = dato;
}

/**
 Elimina la primera aparición de 'dato'
 en la lista.
*/
void
eliminar (struct Contigua **lista, int dato)
{
  int i = 0;
  int *temporal = NULL;
  if (lista == NULL)
    {
      return;
    }
  if ((*lista) == NULL)
    {
      return;
    }
  if ((*lista)->datos == NULL)
    {
      return;
    }
  for (i = 0; i <= (*lista)->actual; i++)
    {
      if (*((*lista)->datos + i) == dato)
	{
	  (*lista)->actual--;
	  break;
	}
    }

  for (; i <= (*lista)->actual; i++)
    {
      *((*lista)->datos + i) = *((*lista)->datos + i + 1);
    }

  if ((*lista)->actual < (*lista)->cuantos / 2)
    {
      temporal = (int *) malloc (sizeof (int) * (*lista)->cuantos / 2);
      if (temporal == NULL)
	{
	  return;
	}
      for (i = 0; i <= (*lista)->actual; i++)
	{
	  *(temporal + i) = *((*lista)->datos + i);
	}
      free ((*lista)->datos);
      (*lista)->datos = temporal;
      (*lista)->cuantos = (*lista)->cuantos / 2;
    }

}

void
mostrar (struct Contigua *lista)
{
  int i = 0;
  if (lista == NULL)
    {
      printf ("\n");
      return;
    }
  for (i = 0; i < lista->actual; i++)
    {
      printf ("%d,", *(lista->datos + i));
    }
  printf ("%d\n", *(lista->datos + lista->actual));
}
