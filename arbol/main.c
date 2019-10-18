#include"arbol.h"

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
