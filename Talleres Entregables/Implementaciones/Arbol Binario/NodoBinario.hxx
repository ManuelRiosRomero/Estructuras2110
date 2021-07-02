#include <cstddef>
#include "NodoBinario.h"
template <class T>
NodoBinario<T>::NodoBinario(T dat)
{
  dato = dat;
  Izq = NULL;
  Dere = NULL;
}

template <class T>
NodoBinario<T>::NodoBinario()
{
  Izq = NULL;
  Dere = NULL;
}

template <class T>
void NodoBinario<T>::fijarDato(T &val)
{
  dato = val;
}

template <class T>
NodoBinario<T> *NodoBinario<T>::obtenerHijoIzq()
{
  return Izq;
}

template <class T>
NodoBinario<T> *NodoBinario<T>::obtenerHijoDer()
{
  return Dere;
}

template <class T>
void NodoBinario<T>::fijarHijoIzq(NodoBinario<T> *izq){
  this->Izq = izq;
}

template <class T>
void NodoBinario<T>::fijarHijoDer(NodoBinario<T> *dere){
this->Dere= dere;
}

template <class T>
T NodoBinario<T>::obtenerDato(){
  return dato;
}

template <class T>
bool NodoBinario<T>::esHoja(){
return (this->Izq == NULL && this->Dere == NULL);
}