using namespace std;
#ifndef _NODOQUAD_H_
#define _NODOQUAD_H_
class NodoQuad {
  protected:
    int dato;
    NodoQuad* padre;
    NodoQuad* hijoSupIzq;
    NodoQuad* hijoSupDer;
    NodoQuad* hijoInfIzq;
    NodoQuad* hijoInfDer;
  public:
    NodoQuad();
    NodoQuad(int val);
    int obtenerDato();
    void fijarDato(int val);
    NodoQuad* obtenerHijoSupIzq();
    NodoQuad* obtenerHijoSupDer();
    NodoQuad* obtenerHijoInfIzq();
    NodoQuad* obtenerHijoInfDer();
    NodoQuad* obtenerPadre();
    void fijarHijoSupIzq(NodoQuad* sizq);
    void fijarHijoSupDer(NodoQuad* sder);
    void fijarHijoInfIzq(NodoQuad* iizq);
    void fijarHijoInfDer(NodoQuad* ider);
    void fijarPadre(NodoQuad* pad);
    bool esHoja();
    bool estaLleno();
    bool sinDos();
    bool estaLleno2();
    };
#include "NodoQuad.hxx"

#endif  