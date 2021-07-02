#include "NodoGeneral.h"
#include <iostream>
#include <list>
#include <queue>

using namespace std;

    
template <class T>
NodoGeneral<T>::NodoGeneral()
{
    this->desc.clear();
}

template <class T>
NodoGeneral<T>::~NodoGeneral()
{
    typename list <NodoGeneral<T>*>::iterator it;
    for (it = desc.begin(); it != desc.end(); ++it)
        delete *it;
    this->desc.clear();
}
template <class T>
T &NodoGeneral<T>::obtenerDato()
{
    return this->dato;
}
template <class T>
void NodoGeneral<T>::fijarDato(T &val)
{
    this->dato = val;
}
template <class T>
void NodoGeneral<T>::limpiarLista()
{
    this->desc.clear();
}
template <class T>
void NodoGeneral<T>::adicionarDesc(T &nval)
{
    NodoGeneral<T> *nodo = new NodoGeneral<T>;
    nodo->fijarDato(nval);
    this->desc.push_back(nodo);
}
template <class T>
bool NodoGeneral<T>::eliminarDesc(T &val)
{
    //Buscar el nodo con el valor dado
    typename list<NodoGeneral<T> *>::iterator it;
    NodoGeneral<T> *aux;
    bool eliminado = false;
    for (it = desc.begin(); it != desc.end(); ++it)
    {
        aux = *it;
        if (aux->obtenerDato() == val)
            break;
    }
    //Si lo encontramos, lo eliminamos
    if (it != this->desc.end())
    {
        delete *it;
        this->desc.erase(it);
        eliminado = true;
    }
    return eliminado;
}
template <class T>
bool NodoGeneral<T>::esHoja()
{
    return this->desc.size() == 0;
}
template <class T>
bool NodoGeneral<T>::insertarNodo(T padre, T n)
{

    if (this->obtenerDato() == padre)
    {
        adicionarDesc(n);
        return true;
    }
    bool ins = false;
    typename list<NodoGeneral<T> *>::iterator it;
    for (it = desc.begin(); it != desc.end(); ++it)
    {
        ins = (*it)->insertarNodo(padre, n);
    }
    return ins;
}
template <class T>
bool NodoGeneral<T>::eliminarNdo(T n)
{
    bool del = false;
    del = this->eliminarDesc(n);
    if (!del)
    {
        typename list<NodoGeneral<T> *>::iterator it;
        for (it = desc.begin(); it != desc.end(); ++it)
        {
            del = (*it)->eliminarNdo(n);
        }
    }
    return del;
}
template <class T>
bool NodoGeneral<T>::buscar(T n)
{
    bool encontrado = false;
    if (this->obtenerDato() == n)
    {
        encontrado = true;
    }
    if (!encontrado)
    {
        typename list<NodoGeneral<T> *>::iterator it;
        for (it = desc.begin(); it != desc.end() && !encontrado; ++it)
        {
            encontrado = (*it)->buscar(n);
        }
    }
    return encontrado;
}
template <class T>
unsigned int NodoGeneral<T>::tamano()
{

    if (this->esHoja())
        return 0;
    typename list<NodoGeneral<T> *>::iterator it;
    unsigned int tama = this->desc.size();
    for (it = desc.begin(); it != desc.end(); ++it)
    {
        tama += (*it)->tamano();
    }
    return tama;
}
template <class T>
void NodoGeneral<T>::posOrden()
{
        typename list<NodoGeneral<T> *>::iterator it;
        for (it = desc.begin(); it != desc.end(); ++it)
        {
            (*it)->posOrden();
        }
        cout << this->obtenerDato() << ", ";
        return;
}
//Definir col
//Meter la raiz en la cola
//ciclo mientras la cola no este vacia
//saco el que este disponible en la cola y lo imprimo
//hacer un ciclo con un iterator par sus desc
//poner cada descendiente dentro de la cola
template <class T>
void NodoGeneral<T>::nivelOrden(int nivel,int lvActual)
{
    typename list<NodoGeneral<T> *>::iterator it;
    if (nivel > lvActual)  {
        for (it = desc.begin(); it != desc.end(); it++)
        {
            (*it)->nivelOrden(nivel, lvActual+1);
        }
    }
    else if (nivel == lvActual){
        cout<<this->dato<<", ";
    }

}
template <class T>
int NodoGeneral<T>::altura()
{
    int alt = -1;

    if (this->esHoja())
    {
        alt = 0;
    }
    else
    {
        typename list<NodoGeneral<T> *>::iterator it;
        for (it = desc.begin(); it != desc.end(); ++it)
        {
            int alth = (*it)->altura();
            if (alt < alth + 1)
                alt = alth + 1;
        }
    }

    return alt;
}
template <class T>
void NodoGeneral<T>::preOrder()
{
    cout << this->obtenerDato() << ", ";
    if (!this->esHoja())
    {
        typename list<NodoGeneral<T> *>::iterator it;
        for (it = desc.begin(); it != desc.end(); ++it)
        {
            (*it)->preOrder();
        }
    }
}