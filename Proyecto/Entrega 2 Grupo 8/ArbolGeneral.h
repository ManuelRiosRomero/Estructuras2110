#ifndef ARBOLGENERAL__H__
#define ARBOLGENERAL__H__
#include "NodoGeneral.h"
#include <vector>

template <class T >
class ArbolGeneral
{
    protected:
        NodoGeneral<T>* raiz;
    public:
        ArbolGeneral();
        ArbolGeneral(T val);
        ~ArbolGeneral();
        bool esVacio();
        NodoGeneral<T>* obtenerRaiz();
        void fijarRaiz(NodoGeneral<T>* nraiz);
        bool insertarNodo (T padre, T n);
        bool eliminarNodo (T n);
        bool buscar(T n);
        int altura();
        unsigned int tamano();
        void preOrder();
        void posOrden();
        void nivelOrden();
        
};




#include "ArbolGeneral.hxx"
#endif