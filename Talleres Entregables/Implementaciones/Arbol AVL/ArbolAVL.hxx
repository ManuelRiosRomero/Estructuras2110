#include "ArbolAVL.h"
#include <queue>
using namespace std;
template <class T>
ArbolAVL<T>::ArbolAVL(){
  raiz = NULL;
}
template <class T>
ArbolAVL<T>::~ArbolAVL(){
  if (raiz != NULL){
delete raiz;
raiz = NULL;
}
}

template <class T>
void ArbolAVL<T>::fijarRaiz(NodoAVL <T>* nodo){
  this->raiz = nodo;
}

template <class T>
NodoAVL <T>* ArbolAVL<T>::obtenerRaiz(){
  return this->raiz;
}

template <class T>
  bool ArbolAVL<T>::esVacio(){
    return this->raiz == NULL;
  }
  template <class T>
  T ArbolAVL<T>::datoRaiz(){
    return (this->raiz)->obtenerDato();
  }
  template <class T>
  int ArbolAVL<T>::altura(){
    if (this->esVacio()){
      return -1;
    }
    else{
      return this->altura(this->raiz);
    }
  }

  template <class T>
  int ArbolAVL<T>::altura(NodoAVL<T>* nodo){
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
  int ArbolAVL<T>::tamano(){
    NodoAVL <T> *nodo;
 int tam = 0;
     if (this->esVacio()){
      return 0;
    }
    else{
      queue<NodoAVL<T> *> q;
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
  bool ArbolAVL<T>::insertar(T val){

  NodoAVL<T>* nodo = this->raiz;
   NodoAVL<T>* padre = this->raiz;
   
    bool insertado = false, duplicado = false;
if (this->esVacio()){
  NodoAVL<T>* ra = new NodoAVL(val);
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
      NodoAVL<T>* nuevo = new NodoAVL<T>(val);
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
  bool ArbolAVL<T>::eliminar(T val){
    NodoAVL<T>* nodo = this->raiz;
     NodoAVL<T>* padre = this->raiz;
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
          NodoAVL<T>* der = nodo->obtenerHijoDer(), *izq = nodo->obtenerHijoIzq();
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
         NodoAVL<T>* nodo2 = nodo->obtenerHijoIzq();
     NodoAVL<T>* maximo;
     NodoAVL<T>* padre2;
     NodoAVL<T>* aux;
     while (nodo2 != NULL){
       maximo = nodo2; 
       nodo2 = nodo2->obtenerHijoDer();
     }
     NodoAVL<T>* nodo3 = nodo->obtenerHijoIzq();
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
        NodoAVL<T>* nodo2 = nodo->obtenerHijoIzq();
     NodoAVL<T>* maximo;
     NodoAVL<T>* padre2;
     NodoAVL<T>* aux;
     while (nodo2 != NULL){
       maximo = nodo2; 
       nodo2 = nodo2->obtenerHijoDer();
     }
     NodoAVL<T>* nodo3 = nodo->obtenerHijoIzq();
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
  bool ArbolAVL<T>::buscar(T val){
    NodoAVL<T>* nodo = this->raiz;
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
  void ArbolAVL<T>::preOrden(){
    if (!this->esVacio()){
      preOrden(this->raiz);
    }
  }

  template <class T>
  void ArbolAVL<T>::preOrden(NodoAVL<T>* nodo){
    if (nodo != NULL){
      cout << nodo->obtenerDato() << ", ";
    preOrden(nodo->obtenerHijoIzq());
    preOrden(nodo->obtenerHijoDer());
    }
    
  }



  template <class T>
  void ArbolAVL<T>::inOrden(){
    if (!this->esVacio()){
      inOrden(this->raiz);
    }

  }

  template <class T>
  void ArbolAVL<T>::inOrden(NodoAVL<T>* nodo){
    if (nodo != NULL){
    inOrden(nodo->obtenerHijoIzq());
    cout << nodo->obtenerDato() << ", ";
    inOrden(nodo->obtenerHijoDer());
    }
    
  }

  template <class T>
  void ArbolAVL<T>::posOrden(){
    if (!this->esVacio()){
      posOrden(this->raiz);
    }
    
  }

   template <class T>
  void ArbolAVL<T>::posOrden(NodoAVL<T>* nodo){
    if (nodo != NULL){
    posOrden(nodo->obtenerHijoIzq());
    posOrden(nodo->obtenerHijoDer());
    cout << nodo->obtenerDato() << ", ";
    }
    
  }


  template <class T>
  void ArbolAVL<T>::nivelOrden(){
    if (this->esVacio()){
      cout << "VACIO" << endl;
    }
    else{
      queue<NodoAVL<T> *> q;
      q.push(this->raiz);
      NodoAVL<T> *nodo;
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
  template <class T>
  NodoAVL<T>* ArbolAVL<T>::rotacionDer(NodoAVL<T>* n1, NodoAVL<T>* n2){
    NodoAVL<T>* nPadre = n1->obtenerHijoIzq();
    n1->fijarHijoIzq(n2->obtenerHijoDer());
    n2->fijarHijoDer(n1);
    return nPadre;
  }

  template <class T>
  NodoAVL<T>* ArbolAVL<T>::rotacionIzq(NodoAVL<T>* n1, NodoAVL<T>* n2){
    NodoAVL<T>* nPadre = n1->obtenerHijoDer();
    n1->fijarHijoDer(n2->obtenerHijoIzq());
    n2->fijarHijoIzq(n1);
    return nPadre;
  }

  template <class T>
  NodoAVL<T>* ArbolAVL<T>::rotacionIzqDer(NodoAVL<T>* n1){
    NodoAVL<T>* aux = rotacionIzq(n1->obtenerHijoIzq(), n1->obtenerHijoIzq()->obtenerHijoDer());
    n1->fijarHijoIzq(aux);
    NodoAVL<T>* nPadre = rotacionDer(n1, n1->obtenerHijoIzq());
    return nPadre;
  }
  template <class T>
  NodoAVL<T>* ArbolAVL<T>::rotacionDerIzq(NodoAVL<T>* n1){
    NodoAVL<T>* aux = rotacionDer(n1->obtenerHijoDer(), n1->obtenerHijoDer()->obtenerHijoIzq());
    n1->fijarHijoDer(aux);
    NodoAVL<T>* nPadre = rotacionIzq(n1, n1->obtenerHijoDer());
    return nPadre;
  }

template <class T>
void ArbolAVL<T>::balanceo (NodoAVL<T>* nodo){
  NodoAVL<T> *auxx, *auxx2;
  ArbolAVL<T>*hiji = new ArbolAVL<T>();
  hiji->fijarRaiz(nodo->obtenerHijoIzq());
   ArbolAVL<T>*hijd = new ArbolAVL<T>();
  hijd->fijarRaiz(nodo->obtenerHijoDer());
  ArbolAVL<T>* hiji2 = new ArbolAVL<T>();
  ArbolAVL<T>* hijd2 = new ArbolAVL<T>();
  
  if (((hiji->altura())-(hijd->altura()))==2){
    
    auxx = hiji->obtenerRaiz()->obtenerHijoIzq();
    hiji2->fijarRaiz(auxx);
     auxx = hiji->obtenerRaiz()->obtenerHijoDer();
    hijd2->fijarRaiz(auxx);
    if ((hiji2->altura()-hijd2->altura()) > 0){
      nodo = rotacionDer(nodo, nodo->obtenerHijoIzq());
    }
    else if ((hiji2->altura()-hijd2->altura()) < 0){
      nodo = rotacionIzqDer(nodo);
    }
  }
  else if (((hiji->altura())-(hijd->altura()))==-2){
    
    ArbolAVL<T>* hiji2 = new ArbolAVL<T>();
  ArbolAVL<T>* hijd2 = new ArbolAVL<T>();
     auxx = hijd->obtenerRaiz()->obtenerHijoIzq();
    hiji2->fijarRaiz(auxx);
    
     auxx2 = hijd->obtenerRaiz()->obtenerHijoDer();
    hijd2->fijarRaiz(auxx2);
    if ((hiji2->altura()-hijd2->altura()) > 0){
      nodo = rotacionDerIzq(nodo);
      
    }
    else if ((hiji2->altura()-hijd2->altura()) < 0){
      
      nodo = rotacionIzq(nodo, nodo->obtenerHijoDer());
    }
  }
  else{
    
  }
}
 