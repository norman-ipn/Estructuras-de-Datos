/*RNSD 2019*/
#include"arbol.h"
int
calcular_factor (struct Arbol *raiz)
{
  int altura_derecho = 0;
  int altura_izquierdo = 0;

  if (raiz == NULL)
    return 0;

  altura_izquierdo = calcular_altura (raiz->izquierdo);
  altura_derecho = calcular_altura (raiz->derecho);
  return altura_izquierdo - altura_derecho;
}

int
calcular_altura (struct Arbol *raiz)
{
  int altura_derecho = 0;
  int altura_izquierdo = 0;


  if (raiz == NULL)
    {
      return -1;
    }

  altura_izquierdo = calcular_altura (raiz->izquierdo);
  altura_derecho = calcular_altura (raiz->derecho);
  if (altura_izquierdo > altura_derecho)
    {
      return altura_izquierdo + 1;
    }
  return altura_derecho + 1;
}

/*
 0  no está
 1  si está
*/
int
buscar (struct Arbol *raiz, int dato)
{
  if (raiz == NULL)
    {
      return 0;
    }
  if (raiz->dato == dato)
    {
      return 1;
    }
  if (dato < raiz->dato)
    {
      return buscar (raiz->izquierdo, dato);
    }
  return buscar (raiz->derecho, dato);
}

struct Arbol *
insertar (struct Arbol *raiz, int dato)
{
  struct Arbol *nuevo = NULL;
  /* caso base */
  if (raiz == NULL)
    {
      nuevo = (struct Arbol *) malloc (sizeof (struct Arbol));
      if (nuevo == NULL)
	return NULL;
      nuevo->dato = dato;
      nuevo->izquierdo = NULL;
      nuevo->derecho = NULL;
      return nuevo;
    }
  if (dato == raiz->dato)
    {
      return raiz;
    }
  if (dato < raiz->dato)
    {
      raiz->izquierdo = insertar (raiz->izquierdo, dato);
    }
  else
    {
      raiz->derecho = insertar (raiz->derecho, dato);
    }
  return raiz;
}

void
mostrar (struct Arbol *raiz)
{
  if (raiz == NULL)
    {
      return;
    }

  mostrar (raiz->izquierdo);
  printf ("%d (%d), ", raiz->dato, calcular_factor (raiz));
  mostrar (raiz->derecho);
}
