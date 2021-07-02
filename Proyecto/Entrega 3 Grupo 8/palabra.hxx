#include "palabra.h"
#include <string.h>
#include <list>
#include <algorithm>
using namespace std;

void Palabra::puntaje(){
  list <char> l1{'e', 'a', 'i', 'o', 'n', 'r', 't', 'l', 's', 'u','E', 'A', 'I', 'O', 'N', 'R', 'T', 'L', 'S', 'U'}, l2 {'d', 'g', 'D', 'G'}, l3{'b', 'c', 'm', 'p', 'B', 'C', 'M', 'P'}, l4{'f', 'h', 'v', 'w', 'y', 'F', 'H', 'V', 'W', 'Y'}, l5{'k', 'K'}, l8{'j', 'x', 'J', 'X'}, l10{'q', 'z', 'Q', 'Z'};
  int puntaje = 0;
  list <char>::iterator it1, it2, it3, it4, it5, it8, it10;

  char *aux = new char [100];
    strcpy(aux, this->pal);
    for (int i = 0; i < strlen(aux); i++){
      it1 = find (l1.begin(), l1.end(), aux[i]);
      it2 = find (l2.begin(), l2.end(), aux[i]);
      it3 = find (l3.begin(), l3.end(), aux[i]);
      it4 = find (l4.begin(), l4.end(), aux[i]);
      it5 = find (l5.begin(), l5.end(), aux[i]);
      it8 = find (l8.begin(), l8.end(), aux[i]);
      it10 = find (l10.begin(), l10.end(), aux[i]);
    if (it1 != l1.end()){
      puntaje++;
    }
    else if (it2 != l2.end()){
      puntaje += 2;
    }
    else if (it3 != l3.end()){
      puntaje += 3;
    }
    else if (it4 != l4.end()){
      puntaje += 4;
    }
    else if (it5 != l5.end()){
      puntaje += 5;
    }
    else if (it8 != l8.end()){
      puntaje += 8;
    }
    else if (it10 != l10.end()){
      puntaje += 10;
    }
  }
  cout << endl << "Palabra: " << this->pal << endl;
  cout << "Puntaje: " << puntaje << endl;

}
Palabra::Palabra(){

}
Palabra::Palabra (char *pala){
  strcpy(this->pal, pala);
}
char* Palabra::obtenerPalabra(){
  return this->pal;
}
void Palabra::fijarPalabra (char *pala){
  strcpy(this->pal, pala);
}