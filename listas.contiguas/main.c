#include "contigua.h"

int
main (void)
{
  struct Contigua *lista = NULL;

  insertar (&lista, 1);
  insertar (&lista, 2);
  insertar (&lista, 3);
  insertar (&lista, 4);
  insertar (&lista, 5);
  insertar (&lista, 6);
  insertar (&lista, 7);
  insertar (&lista, 8);
  insertar (&lista, 9);
  mostrar (lista);
  eliminar (&lista, 1);
  eliminar (&lista, 3);
  eliminar (&lista, 5);
  eliminar (&lista, 7);
  eliminar (&lista, 8);
  eliminar (&lista, 9);
  mostrar (lista);
  return 0;
}
