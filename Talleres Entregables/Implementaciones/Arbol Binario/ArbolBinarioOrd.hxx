
#include "ArbolBinarioOrd.h"
#include <queue>
using namespace std;
template <class T>
ArbolBinarioOrd<T>::ArbolBinarioOrd(){
  raiz = NULL;
}
template <class T>
ArbolBinarioOrd<T>::~ArbolBinarioOrd(){
  if (raiz != NULL){
delete raiz;
raiz = NULL;
}
}
template <class T>
  bool ArbolBinarioOrd<T>::esVacio(){
    return this->raiz == NULL;
  }
  template <class T>
  T ArbolBinarioOrd<T>::datoRaiz(){
    return (this->raiz)->obtenerDato();
  }
  template <class T>
  int ArbolBinarioOrd<T>::altura(){
    if (this->esVacio()){
      return -1;
    }
    else{
      return this->altura(this->raiz);
    }
  }

  template <class T>
  int ArbolBinarioOrd<T>::altura(NodoBinario<T>* nodo){
    int valt;
    if (nodo->esHoja()){
      valt = 0;
    }
    else{
      int valtIzq = -1;
      int valtDer = -1;
      if (nodo->obtenerHijoIzq() != NULL){
        valtIzq = this->altura(nodo->obtenerHijoIzq());
      }
      if (nodo->obtenerHijoDer() != NULL){
        valtDer = this->altura(nodo->obtenerHijoDer());
      }
      if (valtIzq > valtDer){
        valt = valtIzq+1;
      }
      else{
        valt = valtDer+1;
      }
    }

    return valt;
    }

  template <class T>
  int ArbolBinarioOrd<T>::tamano(){
    NodoBinario <T> *nodo;
 int tam = 0;
     if (this->esVacio()){
      return 0;
    }
    else{
      queue<NodoBinario<T> *> q;
      q.push(this->raiz);
      while (!q.empty())
      {
        nodo = q.front();
        q.pop();
        if (nodo->obtenerHijoIzq() != NULL){ 
          q.push(nodo->obtenerHijoIzq()); 
        }
        if (nodo->obtenerHijoDer() != NULL){
          q.push(nodo->obtenerHijoDer());
        }
        tam++;
      }
    }
    return tam;
  }
template <class T>
bool ArbolBinarioOrd<T>::insertar(T val){

  NodoBinario<T>* nodo = this->raiz;
   NodoBinario<T>* padre = this->raiz;
   
    bool insertado = false, duplicado = false;
  if (this->esVacio()){
    NodoBinario<T>* ra = new NodoBinario(val);
    this->raiz = ra;
    insertado = true;
  }
  else{
      while (nodo != NULL){
        padre = nodo;
        if (val < nodo->obtenerDato()){
          nodo = nodo->obtenerHijoIzq();
        }
        else if (val > nodo->obtenerDato()){
          nodo = nodo->obtenerHijoDer();
        }
        else{
          duplicado = true;
          break;
        }
      }
      
      if (!duplicado){
        NodoBinario<T>* nuevo = new NodoBinario<T>(val);
        if (nuevo != NULL){
          if (val < padre->obtenerDato()){
            padre->fijarHijoIzq(nuevo);
          }
          else{
            padre->fijarHijoDer(nuevo);
          }
        }
        insertado = true;
      }
  }
  return insertado;
}


  template <class T>
  bool ArbolBinarioOrd<T>::eliminar(T val){
    NodoBinario<T>* nodo = this->raiz;
     NodoBinario<T>* padre = this->raiz;
    bool encontrado = false, derecha = false, izquierda = false;
    while (nodo != NULL && !encontrado){
       padre = nodo;
      if (val < nodo->obtenerDato()){
        nodo = nodo->obtenerHijoIzq();
        if (nodo != NULL){
        if (val == nodo->obtenerDato()){
          encontrado = true;
          izquierda = true;
          break;
        }
        }
      }
      else if (val > nodo->obtenerDato()){
        nodo = nodo->obtenerHijoDer();
        if (nodo != NULL){
        if (val == nodo->obtenerDato()){
          encontrado = true;
          derecha = true;
          break;
        }
        }
      }
      else if (val == nodo->obtenerDato()){
        encontrado = true;
      }
    
    }
  
    if (encontrado){
      if (nodo == this->raiz){
          NodoBinario<T>* der = nodo->obtenerHijoDer(), *izq = nodo->obtenerHijoIzq();
        if (nodo->obtenerHijoDer() == NULL && nodo->obtenerHijoIzq() == NULL){
       this->raiz = NULL;
       delete nodo;
      }
      else if (nodo->obtenerHijoDer() != NULL && nodo->obtenerHijoIzq() == NULL){
        this->raiz = der;
        delete nodo;
      }
      else if (nodo->obtenerHijoDer() == NULL && nodo->obtenerHijoIzq() != NULL){
         
        this->raiz = izq;
        delete nodo;
      }
       else if (nodo->obtenerHijoDer() != NULL && nodo->obtenerHijoIzq() != NULL){
         NodoBinario<T>* nodo2 = nodo->obtenerHijoIzq();
     NodoBinario<T>* maximo;
     NodoBinario<T>* padre2;
     NodoBinario<T>* aux;
     while (nodo2 != NULL){
       maximo = nodo2; 
       nodo2 = nodo2->obtenerHijoDer();
     }
     NodoBinario<T>* nodo3 = nodo->obtenerHijoIzq();
     if (nodo3->obtenerHijoDer() != NULL){
     while (nodo3 != NULL){
       if (nodo3->obtenerHijoDer() == maximo){
         padre2 = nodo3;
       }
       nodo3 = nodo3->obtenerHijoDer();
     }
     T dat = maximo->obtenerDato();
       nodo->fijarDato(dat);
     padre2->fijarHijoDer(NULL);
     delete maximo;
     }
     else{
       T dat = maximo->obtenerDato();
       nodo->fijarDato(dat);
       nodo->fijarHijoIzq(NULL);
     }
       }

      }
      else{
      if (nodo->obtenerHijoDer() == NULL && nodo->obtenerHijoIzq() == NULL){
        if (izquierda){
        padre->fijarHijoIzq(NULL);
        }
        else if (derecha){
        padre->fijarHijoDer(NULL);
        }
        delete nodo;
      }
      else if (nodo->obtenerHijoDer() != NULL && nodo->obtenerHijoIzq() == NULL){
        if (izquierda){
        padre->fijarHijoIzq(nodo->obtenerHijoDer());
        }
        else if (derecha){
        padre->fijarHijoDer(nodo->obtenerHijoDer());
        }
      }
      else if (nodo->obtenerHijoDer() == NULL && nodo->obtenerHijoIzq() != NULL){
         if (izquierda){
        padre->fijarHijoIzq(nodo->obtenerHijoIzq());
        }
        else if (derecha){
        padre->fijarHijoDer(nodo->obtenerHijoIzq());
        }
      }
      else if (nodo->obtenerHijoDer() != NULL && nodo->obtenerHijoIzq() != NULL){
        NodoBinario<T>* nodo2 = nodo->obtenerHijoIzq();
     NodoBinario<T>* maximo;
     NodoBinario<T>* padre2;
     NodoBinario<T>* aux;
     while (nodo2 != NULL){
       maximo = nodo2; 
       nodo2 = nodo2->obtenerHijoDer();
     }
     NodoBinario<T>* nodo3 = nodo->obtenerHijoIzq();
     if (nodo3->obtenerHijoDer() != NULL){
     while (nodo3 != NULL){
       if (nodo3->obtenerHijoDer() == maximo){
         padre2 = nodo3;
       }
       nodo3 = nodo3->obtenerHijoDer();
     }
     T dat = maximo->obtenerDato();
       nodo->fijarDato(dat);
     padre2->fijarHijoDer(NULL);
     delete maximo;
     }
     else{
       T dat = maximo->obtenerDato();
       nodo->fijarDato(dat);
       nodo->fijarHijoIzq(NULL);
     }
    
     
     
      }
      }

    }
    return encontrado;
  }


  template <class T>
  bool ArbolBinarioOrd<T>::buscar(T val){
    NodoBinario<T>* nodo = this->raiz;
    bool encontrado = false;

    while (nodo != NULL && !encontrado){
      if (val < nodo->obtenerDato()){
        nodo = nodo->obtenerHijoIzq();
      }
      else if (val > nodo->obtenerDato()){
        nodo = nodo->obtenerHijoDer();
      }
      else{
        encontrado = true;
      }
    }
    return encontrado;
  }
  template <class T>
  void ArbolBinarioOrd<T>::preOrden(){
    if (!this->esVacio()){
      preOrden(this->raiz);
    }
  }

  template <class T>
  void ArbolBinarioOrd<T>::preOrden(NodoBinario<T>* nodo){
    if (nodo != NULL){
      cout << nodo->obtenerDato() << ", ";
    preOrden(nodo->obtenerHijoIzq());
    preOrden(nodo->obtenerHijoDer());
    }
    
  }



  template <class T>
  void ArbolBinarioOrd<T>::inOrden(){
    if (!this->esVacio()){
      inOrden(this->raiz);
    }

  }

  template <class T>
  void ArbolBinarioOrd<T>::inOrden(NodoBinario<T>* nodo){
    if (nodo != NULL){
    inOrden(nodo->obtenerHijoIzq());
    cout << nodo->obtenerDato() << ", ";
    inOrden(nodo->obtenerHijoDer());
    }
    
  }

  template <class T>
  void ArbolBinarioOrd<T>::posOrden(){
    if (!this->esVacio()){
      posOrden(this->raiz);
    }
    
  }

   template <class T>
  void ArbolBinarioOrd<T>::posOrden(NodoBinario<T>* nodo){
    if (nodo != NULL){
    posOrden(nodo->obtenerHijoIzq());
    posOrden(nodo->obtenerHijoDer());
    cout << nodo->obtenerDato() << ", ";
    }
    
  }


  template <class T>
  void ArbolBinarioOrd<T>::nivelOrden(){
    if (this->esVacio()){
      cout << "VACIO" << endl;
    }
    else{
      queue<NodoBinario<T> *> q;
      q.push(this->raiz);
      NodoBinario<T> *nodo;
      while (!q.empty())
      {
        nodo = q.front();
        q.pop();
        cout << nodo->obtenerDato() << ", ";
        if (nodo->obtenerHijoIzq() != NULL){
          q.push(nodo->obtenerHijoIzq());
        }
        if (nodo->obtenerHijoDer() != NULL){
          q.push(nodo->obtenerHijoDer());
        }
      }
    }
  }
 