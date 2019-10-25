#ifndef __ARBOL_H__
#define __ARBOL_H__

#include<stdlib.h>
#include<stdio.h>
struct Arbol
{
  int factor;			/*< factor de balance: 
				   altura izquierda - altura derecha */
  int dato;
  struct Arbol *izquierdo;
  struct Arbol *derecho;
};

int calcular_altura (struct Arbol *);
int calcular_factor (struct Arbol *);

int buscar (struct Arbol *, int);

struct Arbol *insertar (struct Arbol *, int);

void mostrar (struct Arbol *);

#endif
