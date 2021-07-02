#include <string.h>
#ifndef PALABRA_H
#define PALABRA_H
struct Palabra{
  char pal [100];
  Palabra();
  Palabra (char *pala);
  void puntaje ();

  char* obtenerPalabra();
  void fijarPalabra (char *pala);
  bool operator ==(Palabra& p) const{
    return (strcmp(pal, p.pal) == 0);
  }
  bool operator <(Palabra& p) const{
    return (strcmp(pal, p.pal) < 0);
  }
};
#include "palabra.hxx"
#endif