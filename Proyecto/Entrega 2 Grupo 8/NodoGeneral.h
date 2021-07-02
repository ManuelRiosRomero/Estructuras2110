#ifndef NODOGENERAL__H__
#define NODOGENERAL__H__

#include <list>

template <class T>
class NodoGeneral
{
    protected:
         T dato;
         std::list<NodoGeneral<T>* > desc;
    public:
         NodoGeneral();
         ~NodoGeneral();
         T& obtenerDato();
         list<NodoGeneral<T>* > obtenerDesc();
         void fijarDato(T& val);
         void limpiarLista();
         void adicionarDesc(T& nval);
         bool eliminarDesc(T& val);
         bool esHoja();
         bool insertarNodo(T padre,T n);
         bool eliminarNodo(T n);
         bool buscar(T n);
         int  altura();
         unsigned int tamano();
         void preOrder();
         void posOrden();
         void nivelOrden(int nivel,int lvActual);
};

#include "NodoGeneral.hxx"
#endif