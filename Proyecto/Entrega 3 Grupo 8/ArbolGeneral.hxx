#include "ArbolGeneral.h"
#include "NodoGeneral.h"

using namespace std;

template <class T>
ArbolGeneral<T>::ArbolGeneral()
{
    this->raiz = NULL;
}
template <class T>
ArbolGeneral<T>::ArbolGeneral(T val)
{
    NodoGeneral<T> *nodo = new NodoGeneral<T>;
    nodo->fijarDato(val);
    this->raiz = nodo;
}
template <class T>
ArbolGeneral<T>::~ArbolGeneral()
{
    delete this->raiz;
    this->raiz = NULL;
}
template <class T>
bool ArbolGeneral<T>::esVacio()
{
    return this->raiz == NULL;
}
template <class T>
NodoGeneral<T> *ArbolGeneral<T>::obtenerRaiz()
{
    return this->raiz;
}
template <class T>
void ArbolGeneral<T>::fijarRaiz(NodoGeneral<T> *nraiz)
{
    this->raiz = nraiz;
}

template <class T>
bool ArbolGeneral<T>::insertarNodo(T padre, T n)
{
    bool ins = false;

    if (this->esVacio())
    {
        NodoGeneral<T> *nodo = new NodoGeneral<T>;
        nodo->fijarDato(n);
        this->raiz = nodo;
        ins = true;
    }
    else
    {
        ins = this->raiz->insertarNodo(padre, n);
    }
    return ins;
}

template <class T>
bool ArbolGeneral<T>::eliminarNodo(T n)
{
    bool del = false;
    if (!this->esVacio())
    {
        if (n == raiz->obtenerDato())
        {
            delete raiz;
            raiz = NULL;
            del = true;
        }
        else
            del = this->raiz->eliminarNodo(n);
    }

    return del;
}

template <class T>
bool ArbolGeneral<T>::buscar(T n)
{
    bool encontrado = false;
    if (!this->esVacio())
    {
        encontrado = this->raiz->buscar(n);
    }
    return encontrado;
}
template <class T>
int ArbolGeneral<T>::altura()
{
    if (this->esVacio())
        return -1;
    else
    {
        return this->raiz->altura();
    }
}

template <class T>
unsigned int ArbolGeneral<T>::tamano()
{
    unsigned int tama = 0;
    if (!this->esVacio())
    {
        tama = this->raiz->tamano() + 1;
    }
    return tama;
}

template <class T>
void ArbolGeneral<T>::preOrder()
{
    if (!this->esVacio())
        this->raiz->preOrder();
    else
        cout << "El arbol esta vacio" << endl;
    cout << endl;
}

template <class T>
void ArbolGeneral<T>::posOrden()
{
    if (!this->esVacio())
        this->raiz->posOrden();
    else
        cout << "El arbol esta vacio" << endl;
    cout << endl;
}

template <class T>
void ArbolGeneral<T>::nivelOrden()
{
    if (!this->esVacio())
    {
        for (int i = 0; i <= this->altura(); i++)
            this->raiz->nivelOrden(i, 0);
        std::cout << std::endl;
    }
    else
        std::cout << "Vacío \n";
}