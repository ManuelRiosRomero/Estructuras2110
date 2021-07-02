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
  bool insertado = false;
  if (this->esVacio()){
    NodoQuad *nodo = new NodoQuad (val);
    this->raiz = nodo;
    insertado = true;
  }
  else{
    if (this->raiz->obtenerDato() != 2){
      return false;
    }
    else{
      insertado = this->raiz->insertar(val);
    }
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
    preOrden(nodo->obtenerHijoInfDer());
    preOrden(nodo->obtenerHijoInfIzq());
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

  void ArbolQuad::generarPBM(int matriz [][1500], int tam, int conta){
    conta++;
    this->raiz->generarPBM(matriz, 0, 0, tam, conta);
  }

