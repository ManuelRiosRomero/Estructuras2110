#include "ArbolQuad.h" 
#include <queue>
using namespace std;
bool bloq1 = false, bloq2 = false, bloq3 = false, bloq4 = false;
ArbolQuad::ArbolQuad(){
  this->raiz = NULL;
}

/*ArbolQuad::~ArbolQuad(){
  if (raiz != NULL){
delete raiz;
this->raiz = NULL;
}
}*/
ArbolQuad::ArbolQuad(int val){
  NodoQuad *ra = new NodoQuad(val);
  this->raiz = ra;
}

bool ArbolQuad::esVacio(){
    return this->raiz == NULL;
  }

bool ArbolQuad::insertar(int val){
  /*if ((((this->tamano())-1) % 4) == 0){
    return false;
  }*/
  bool insertado = false, supder = false, supizq = false, infder = false, infizq = false;
  int conta = 0, actual, actualgen;
  NodoQuad *padre = this->raiz, *nodo = this->raiz, *ins = new NodoQuad(val);
  if (val == 0 || val == 1 || val == 2){
  if (this->esVacio()){
    NodoQuad *ra = new NodoQuad(val);
    this->raiz = ra;
    insertado = true;
  }
  else{
    if (nodo->obtenerDato() != 2){
      return false;
    }
  while (nodo != NULL){
    padre = nodo;
    if (nodo->esHoja()){
      nodo = nodo->obtenerHijoSupIzq();
      supizq = true;
    }
    else if (nodo->obtenerHijoSupIzq()->obtenerDato()==2 && !nodo->obtenerHijoSupIzq()->estaLleno() && !(conta == 0 && bloq1)){
      nodo = nodo->obtenerHijoSupIzq();
      if (conta == 0){
        actualgen = 1;
      }
      actual = 1;
    }
    else if (nodo->obtenerHijoSupDer() == NULL){
       nodo = nodo->obtenerHijoSupDer();
       supder = true;
    }
    else if (nodo->obtenerHijoSupDer()->obtenerDato()==2  && !nodo->obtenerHijoSupDer()->estaLleno() && !(conta == 0 && bloq2)){
      nodo = nodo->obtenerHijoSupDer();
      if (conta == 0){
        actualgen = 2;
      }
      actual = 2;
    }
    else if (nodo->obtenerHijoInfIzq() == NULL){
      nodo = nodo->obtenerHijoInfIzq();
      infizq = true;
    }
    else if (nodo->obtenerHijoInfIzq()->obtenerDato() == 2  && !nodo->obtenerHijoInfIzq()->estaLleno() && !(conta == 0 && bloq3)){
      nodo = nodo->obtenerHijoInfIzq();
      if (conta == 0){
        actualgen = 3;
      }
      actual = 3;
    }
    else if (nodo->obtenerHijoInfDer() == NULL){
      nodo = nodo->obtenerHijoInfDer();
      infder = true;
    }
    else if (nodo->obtenerHijoInfDer()->obtenerDato() == 2  && !nodo->obtenerHijoInfDer()->estaLleno() && !(conta == 0 && bloq4)){
      nodo = nodo->obtenerHijoInfDer();
      if (conta == 0){
        actualgen = 4;
      }
      actual = 4;
    }
    else{
      ArbolQuad *aux = new ArbolQuad ();
      if (actualgen == 1){
        aux->fijarRaiz(this->raiz->obtenerHijoSupIzq());
        if ((((aux->tamano())-1) % 4) == 0){
          bloq1 = true;
          nodo = this->raiz;
          conta = -1;
          actual = 0;
        }
      }
      else if (actualgen == 2){
         aux->fijarRaiz(this->raiz->obtenerHijoSupDer());
        if ((((aux->tamano())-1) % 4) == 0){
          bloq2 = true;
          nodo = this->raiz;
          conta = -1;
          actual = 0;
        }
      }
      else if (actualgen == 3){
         aux->fijarRaiz(this->raiz->obtenerHijoInfIzq());
        if ((((aux->tamano())-1) % 4) == 0){
          bloq3 = true;
          nodo = this->raiz;
          conta = -1;
          actual = 0;
        }
      }
      else if (actualgen == 4){
         aux->fijarRaiz(this->raiz->obtenerHijoInfDer());
        if ((((aux->tamano())-1) % 4) == 0){
          bloq4 = true;
          nodo = this->raiz;
          conta = -1;
          actual = 0;
        }
      }
      padre = nodo->obtenerPadre();
      if (padre == this->raiz){
        
      }
      if (actual == 1){
        
        supder = true;
        break;
       
      }
      else if (actual == 2){
        infizq = true;
        break;
      }
       else if (actual == 3){
        infder = true;
        break;
      }
      else{
        
      }

      
    }
 
      
    
    conta++;
  }
  if (supizq){
    padre->fijarHijoSupIzq(ins);
    padre->obtenerHijoSupIzq()->fijarPadre(padre);
    insertado = true;
  }
  else if (supder){
     padre->fijarHijoSupDer(ins);
     padre->obtenerHijoSupDer()->fijarPadre(padre);
    insertado = true;
  }
  else if (infizq){
     padre->fijarHijoInfIzq(ins);
     padre->obtenerHijoInfIzq()->fijarPadre(padre);
    insertado = true;
  }
  else if (infder){
     padre->fijarHijoInfDer(ins);
     padre->obtenerHijoInfDer()->fijarPadre(padre);
    insertado = true;
  }
  else{
    insertado = false;
  }

  }
  }
  else{
    insertado = false;
    cout << "hola" << endl;
  }
  return insertado;
}

void ArbolQuad::preOrden(){
   if (!this->esVacio()){
      preOrden(this->raiz);
    }
}

void ArbolQuad::preOrden(NodoQuad *nodo){
  if (nodo != NULL){
      cout << nodo->obtenerDato() << ", ";
    preOrden(nodo->obtenerHijoSupIzq());
    preOrden(nodo->obtenerHijoSupDer());
    preOrden(nodo->obtenerHijoInfIzq());
    preOrden(nodo->obtenerHijoInfDer());
    }
}

int ArbolQuad::tamano(){
    NodoQuad *nodo;
 int tam = 0;
     if (this->esVacio()){
      return 0;
    }
    else{
      queue<NodoQuad *> q;
      q.push(this->raiz);
      while (!q.empty())
      {
        nodo = q.front();
        q.pop();
        if (nodo->obtenerHijoSupIzq() != NULL){ 
          q.push(nodo->obtenerHijoSupIzq()); 
        }
        if (nodo->obtenerHijoSupDer() != NULL){
          q.push(nodo->obtenerHijoSupDer());
        }
        if (nodo->obtenerHijoInfIzq() != NULL){ 
          q.push(nodo->obtenerHijoInfIzq()); 
        }
        if (nodo->obtenerHijoInfDer() != NULL){
          q.push(nodo->obtenerHijoInfDer());
        }
        tam++;
      }
    }
    return tam;
  }
  void ArbolQuad::fijarRaiz(NodoQuad* n_raiz){
    this->raiz = n_raiz;
  }

  NodoQuad* ArbolQuad::obtenerRaiz(){
    return this->raiz;
  }

