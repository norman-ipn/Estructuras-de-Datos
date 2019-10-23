/*RNSD 2019*/
#include"arbol.h"

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
  printf ("%d, ", raiz->dato);
  mostrar (raiz->derecho);
}
