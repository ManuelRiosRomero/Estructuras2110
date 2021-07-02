#ifndef PALABRA_H
#define PALABRA_H
struct Palabra{
  char pal [100];
  Palabra();
  Palabra (char *pala);
  void puntaje ();

  char* obtenerPalabra();
  void fijarPalabra (char *pala);
};
#include "palabra.hxx"
#endif