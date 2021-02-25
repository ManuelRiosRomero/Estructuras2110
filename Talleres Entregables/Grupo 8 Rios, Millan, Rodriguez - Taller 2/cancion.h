#ifndef CANCION_H
#define CANCION_H
struct Cancion{
  char *nombre = new char [100];
  char *autor = new char [200];
  char *genero = new char [100];
  char *album = new char [200];
  char *anho = new char [4];
};
#endif