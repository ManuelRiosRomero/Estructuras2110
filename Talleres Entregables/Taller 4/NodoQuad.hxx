#include "NodoQuad.h"
#include <iostream>
using namespace std;
NodoQuad::NodoQuad(){
  this->hijoSupIzq = NULL;
   this->hijoSupDer = NULL;
   this->hijoInfIzq = NULL;
   this->hijoInfDer = NULL;
}


NodoQuad::NodoQuad(int val){
  this->dato = val;
   this->hijoSupIzq = NULL;
   this->hijoSupDer = NULL;
   this->hijoInfIzq = NULL;
   this->hijoInfDer = NULL;
}

int NodoQuad::obtenerDato(){
  return this->dato;
}

NodoQuad* NodoQuad::obtenerHijoSupIzq(){
  return this->hijoSupIzq;
}
NodoQuad* NodoQuad::obtenerHijoSupDer(){
  return this->hijoSupDer;
}
NodoQuad* NodoQuad::obtenerHijoInfIzq(){
  return this->hijoInfIzq;
}
NodoQuad* NodoQuad::obtenerHijoInfDer(){
  return this->hijoInfDer;
}
 NodoQuad* NodoQuad::obtenerPadre(){
   return this->padre;
 }
void NodoQuad::fijarHijoSupIzq(NodoQuad* sizq){
  this->hijoSupIzq = sizq;
}
void NodoQuad::fijarHijoSupDer(NodoQuad* sder){
  this->hijoSupDer = sder;
}
void NodoQuad::fijarHijoInfIzq(NodoQuad* iizq){
  this->hijoInfIzq = iizq;
}
void NodoQuad::fijarHijoInfDer(NodoQuad* ider){
  this->hijoInfDer = ider;
}

void NodoQuad::fijarPadre(NodoQuad* pad){
  this->padre = pad;
}

bool NodoQuad::esHoja(){
  return (this->hijoSupIzq == NULL && this->hijoSupDer == NULL && this->hijoInfIzq == NULL &&this->hijoInfDer == NULL);
}

bool NodoQuad::estaLleno(){
  /*bool termino = false;
  NodoQuad *nodo = this->raiz;
  while (!termino){
    if (nodo->obtenerHijoSupIzq->obtenerDato()==2){
      if (nodo->obtenerHijoSupIzq->sinDos()){
        termino = true;
      }
      else{
        nod
      }
    }
  }*/
  return ((this->hijoSupIzq != NULL && this->hijoSupDer != NULL && this->hijoInfIzq != NULL &&this->hijoInfDer != NULL)&&(this->hijoSupIzq->obtenerDato()!=2 && this->hijoSupDer->obtenerDato()!=2 && this->hijoInfIzq->obtenerDato()!=2 && this->hijoInfDer->obtenerDato()!=2));
}

/*bool NodoQuad::sinDos(){
  return ((this->hijoSupIzq != NULL && this->hijoSupDer != NULL && this->hijoInfIzq != NULL &&this->hijoInfDer != NULL)&&(this->hijoSupIzq->obtenerDato()!=2 && this->hijoSupDer->obtenerDato()!=2 && this->hijoInfIzq->obtenerDato()!=2 && this->hijoInfDer->obtenerDato()!=2));
}*/

bool NodoQuad::estaLleno2(){
  return (this->hijoSupIzq != NULL && this->hijoSupDer != NULL && this->hijoInfIzq != NULL &&this->hijoInfDer != NULL);
}

bool NodoQuad::insertar(int val){
  bool insertado = false;
  if(this->hijoSupIzq == NULL){
     NodoQuad *nodo = new NodoQuad (val);
    this->hijoSupIzq = nodo;
    return true;
  }
 if (this->hijoSupIzq->obtenerDato() == 2 && !this->hijoSupIzq->estaLleno()){
   insertado = this->hijoSupIzq->insertar(val);
   if (insertado){
     return insertado;
   }
 }
 if (this->hijoSupDer == NULL){
   NodoQuad *nodo = new NodoQuad (val);
    this->hijoSupDer = nodo;
    return true;
 }
 if (this->hijoSupDer->obtenerDato() == 2 && !this->hijoSupDer->estaLleno()){
   insertado = this->hijoSupDer->insertar(val);
   if (insertado){
     return insertado;
   }
 }
  if (this->hijoInfDer == NULL){
   NodoQuad *nodo = new NodoQuad (val);
    this->hijoInfDer = nodo;
    return true;
 }
 if (this->hijoInfDer->obtenerDato() == 2 && !this->hijoInfDer->estaLleno()){
   insertado = this->hijoInfDer->insertar(val);
   if (insertado){
     return insertado;
   }
 }
 if (this->hijoInfIzq == NULL){
   NodoQuad *nodo = new NodoQuad (val);
    this->hijoInfIzq = nodo;
    return true;
 }
 if (this->hijoInfIzq->obtenerDato() == 2 && !this->hijoInfIzq->estaLleno()){
   insertado = this->hijoInfIzq->insertar(val);
   if (insertado){
     return insertado;
   }
 }

 return insertado;
}

void NodoQuad::generarPBM(int matriz [][1500], int fil, int col, int tam, int conta){
  int auxTam, f = fil, c = col, faux, caux, faux2, caux2;
   auxTam = tam / 2;
  for (int k = 0; k < conta-1; k++){
    auxTam /= 2;
  }
  
 
  conta++;
  if (this->hijoSupIzq->obtenerDato() == 2){
    this->hijoSupIzq->generarPBM(matriz, f, c, tam, conta);
 }
 else{
   if (this->hijoSupIzq->obtenerDato() == 1){
     faux2 = fil + (auxTam-1);
      caux2 = col + auxTam-1;
     for (int i = fil; i <= faux2; i++){
       for (int j = col; j <= caux2; j++){
         matriz [i][j] = 1;
     }
     }
   }
   else if (this->hijoSupIzq->obtenerDato() == 0){
     faux2 = fil + (auxTam-1);
      caux2 = col + auxTam-1;
     for (int i = fil; i <= faux2; i++){
       for (int j = col; j <= caux2; j++){
         matriz [i][j] = 0;
     }
     }
   }
 }

 if (this->hijoSupDer->obtenerDato() == 2){
   caux = col + auxTam;
    this->hijoSupDer->generarPBM(matriz, f, caux, tam, conta);
 }
 else{
   if (this->hijoSupDer->obtenerDato() == 1){
     faux2 = fil + (auxTam-1);
      caux2 = (col + auxTam) + (auxTam-1);
     for (int i = fil; i <= faux2; i++){
       for (int j = col + auxTam; j <= caux2; j++){
         matriz [i][j] = 1;
     }
     }
   }
   else if (this->hijoSupDer->obtenerDato() == 0){
     faux2 = fil + (auxTam-1);
      caux2 = (col + auxTam) + (auxTam-1);
     for (int i = fil; i <= faux2; i++){
       for (int j = col + auxTam; j <= caux2; j++){
         matriz [i][j] = 0;
     }
     }
   }
 }

 if (this->hijoInfDer->obtenerDato() == 2){
   caux = col + auxTam;
   faux = fil + auxTam;
    this->hijoInfDer->generarPBM(matriz, faux, caux, tam, conta);
 }
 else{
   if (this->hijoInfDer->obtenerDato() == 1){
     faux2 = (fil + auxTam)+ (auxTam-1);
      caux2 = (col + auxTam) + (auxTam-1);
     for (int i = fil + auxTam; i <= faux2; i++){
       for (int j = col + auxTam; j <= caux2; j++){
         matriz [i][j] = 1;
     }
     }
   }
   else if (this->hijoInfDer->obtenerDato() == 0){
     faux2 = (fil + auxTam)+ (auxTam-1);
      caux2 = (col + auxTam) + (auxTam-1);
     for (int i = fil + auxTam; i <= faux2; i++){
       for (int j = col + auxTam; j <= caux2; j++){
         matriz [i][j] = 0;
     }
     }
   }
 }

  if (this->hijoInfIzq->obtenerDato() == 2){
   faux = fil + auxTam;
    this->hijoInfIzq->generarPBM(matriz, faux, c, tam, conta);
 }
 else{
   if (this->hijoInfIzq->obtenerDato() == 1){
     faux2 = (fil + auxTam)+ (auxTam-1);
      caux2 = col + (auxTam-1);
     for (int i = fil + auxTam; i <= faux2; i++){
       for (int j = col; j <= caux2; j++){
         matriz [i][j] = 1;
     }
     }
   }
   else if (this->hijoInfIzq->obtenerDato() == 0){
     faux2 = (fil + auxTam)+ (auxTam-1);
      caux2 = col + (auxTam-1);
     for (int i = fil + auxTam; i <= faux2; i++){
       for (int j = col; j <= caux2; j++){
         matriz [i][j] = 0;
     }
     }
   }
 }

}