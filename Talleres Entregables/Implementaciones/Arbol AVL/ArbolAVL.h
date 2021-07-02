 #ifndef _ARBOLAVL_H_
 #define _ARBOLAVL_H_

 #include  "NodoAVL.h"

template <class T>
class ArbolAVL{
  protected:
    NodoAVL <T>* raiz;
  public:
    ArbolAVL();
    ~ArbolAVL();
    void fijarRaiz(NodoAVL <T>* nodo);
    NodoAVL <T>* obtenerRaiz();
    bool esVacio();
    T datoRaiz();
    int altura();
    int altura(NodoAVL<T>* nodo);
    int tamano();
    bool insertar(T val);
    bool eliminar(T val);
    bool buscar(T val);
    void preOrden();
     void preOrden(NodoAVL<T>* nodo);
    void inOrden();
      void inOrden(NodoAVL<T>* nodo);
    void posOrden();
    void posOrden(NodoAVL<T>* nodo);
    void nivelOrden();
    NodoAVL<T>* rotacionDer(NodoAVL<T>* n1, NodoAVL<T>* n2);
    NodoAVL<T>* rotacionIzq(NodoAVL<T>* n1, NodoAVL<T>* n2);
    NodoAVL<T>* rotacionIzqDer(NodoAVL<T>* n1);
    NodoAVL<T>* rotacionDerIzq(NodoAVL<T>* n1);
    void balanceo (NodoAVL<T>* nodo);
  };
  
#include "ArbolAVL.hxx"
   
#endif