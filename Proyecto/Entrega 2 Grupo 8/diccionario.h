#include <list>
#include "palabra.h"
#include "ArbolGeneral.h"
#ifndef DICCIONARIO_H
#define DICCIONARIO_H
struct Diccionario{
 char nombreUlt [200];
 list <Palabra> palabras;
 list <Palabra> palabrasInv;
 int totalPalabras;
ArbolGeneral<char> arbolPal;
ArbolGeneral<char> arbolInv;
 
 Diccionario();
 Diccionario (char *nombre, list <Palabra> pala, list <Palabra> palInv, int total);
 char* obtenerNombre();
 list <Palabra> obtenerPalabras();
 list <Palabra> obtenerPalabrasInv();
 int obtenerTotal();
 ArbolGeneral<char> obtenerArbolPal();
 ArbolGeneral<char> obtenerArbolInv();
 void fijarArbolPal(ArbolGeneral<char> arbol);
 void fijarArbolInv(ArbolGeneral<char> arbol);
 void fijarNombre(char *nombre);
 void fijarPalabras(list <Palabra> pala);
 void fijarPalabrasInv (list <Palabra> palInv);
 void fijarTotal(int total);
};
#include "diccionario.hxx"
#endif