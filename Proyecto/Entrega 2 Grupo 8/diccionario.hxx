#include "diccionario.h"
#include <string.h>
using namespace std;
Diccionario::Diccionario(){
  totalPalabras = 0;
}
 Diccionario::Diccionario (char *nombre, list <Palabra> pala, list <Palabra> palInv, int total){
    strcpy(nombreUlt, nombre);
    palabras = pala;
     palabrasInv = palInv;
     totalPalabras = total;
 }
char* Diccionario::obtenerNombre(){
  return this->nombreUlt;
}
list <Palabra> Diccionario::obtenerPalabras(){
  return this->palabras;
}
 int Diccionario::obtenerTotal(){
   return this->totalPalabras;
 }
 void Diccionario::fijarNombre(char *nombre){
   strcpy(this->nombreUlt, nombre);
 }
 void Diccionario::fijarPalabras(list <Palabra> pala){
   this->palabras = pala;
 }
 void Diccionario::fijarTotal(int total){
   this->totalPalabras = total;
 }
 list <Palabra> Diccionario::obtenerPalabrasInv(){
   return this->palabrasInv;
 }
 void Diccionario::fijarPalabrasInv (list <Palabra> palInv){
   this->palabrasInv = palInv;
 }

ArbolGeneral<char> Diccionario::obtenerArbolPal(){
  return this->arbolPal;
}

void Diccionario::fijarArbolPal(ArbolGeneral<char> arbol){
  this->arbolPal = arbol;
}
ArbolGeneral<char> Diccionario::obtenerArbolInv(){
  return this->arbolInv;
}

void Diccionario::fijarArbolInv(ArbolGeneral<char> arbol){
  this->arbolInv = arbol;
}