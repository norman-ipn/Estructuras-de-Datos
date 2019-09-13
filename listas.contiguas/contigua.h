/**
 \file contigua.h
 
 Definición del tipo de dato struct Contigua,
 así como las funciones.

 Contigua es una lista donde la memoria
 se reserva con malloc para que se puedan
 tener los datos de forma contigua,
 como un arreglos.

 El tamaño crece al doble cada que se llena 
 y se reduce a la mitad cuando está desocupado
 la mitad del espacio.

*/

#ifndef __CONTIGUA_H__
#define __CONTIGUA_H__

#include<stdio.h>
#include<stdlib.h>
struct Contigua
{
  int *datos;
  int actual;
  int cuantos;
};

void insertar (struct Contigua **, int);
void eliminar (struct Contigua **, int);
void mostrar (struct Contigua *);
#endif
