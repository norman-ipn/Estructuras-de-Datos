#include<stdlib.h>
#include<stdio.h>
struct Arbol
{
  int dato;
  struct Arbol *izquierdo;
  struct Arbol *derecho;
};

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

int
main (void)
{
  struct Arbol *raiz = NULL;
  raiz = insertar (raiz, 10);
  raiz = insertar (raiz, 1);
  raiz = insertar (raiz, 140);
  raiz = insertar (raiz, 510);
  raiz = insertar (raiz, 160);
  raiz = insertar (raiz, 180);
  mostrar (raiz);
  return 0;
}
