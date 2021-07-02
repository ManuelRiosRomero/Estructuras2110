using namespace std;
#ifndef _ARBOLQUAD_H_
#define _ARBOLQUAD_H_

#include "NodoQuad.h"

class ArbolQuad {
  protected:
    NodoQuad* raiz;
  public:
    ArbolQuad();
    ArbolQuad(int val);
    ~ArbolQuad();
    int datoRaiz();
    int tamano();
    NodoQuad* obtenerRaiz();
    void fijarRaiz(NodoQuad* n_raiz);
    bool esVacio();
    bool insertar(int val);
    void preOrden();
    void preOrden(NodoQuad* nodo);
    void inOrden();
    void posOrden();
    void nivelOrden();
};

#include "ArbolQuad.hxx"

#endif