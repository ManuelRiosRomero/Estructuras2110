#include "NodoQuad.h"
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