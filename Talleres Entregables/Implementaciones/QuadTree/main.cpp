#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <ctime>
#include <fstream>
#include <string.h>
#include "ArbolQuad.h"
#include "NodoQuad.h"
using namespace std;
int main() {
  ifstream archivo ("image_04.txt");
  string linea;
  int conta = 0;
  ArbolQuad *a = new ArbolQuad ();
  while (getline(archivo, linea)){
    char *lineaC = new char [100000];
    strcpy(lineaC, linea.c_str());
    if (conta > 0){
      for (int i = 0; i < strlen(lineaC); i++){
        int num = lineaC[i]-'0';
        a->insertar(num);
      }
    }
    conta++;
  }
  archivo.close();
  if (((a->tamano()-1)%4)==0){
    cout << a->tamano()-1 << ": Completo" << endl;
  }
  else{
    cout << "Incompleto" << endl;
  }
  
  /*if (a->insertar(2)){
    cout << "inserto" << endl;
  }
  else{
    cout << "No inserto" << endl;
  }
  for (int i = 0; i < 100; i++){
    cout << i;
    a->insertar(rand()%2);
  }*/
 /* a->insertar(0);
  a->insertar(1);
  a->insertar(0);
  a->insertar(1);*/

//a->insertar(1);
 /* a->insertar(1);
  a->insertar(0);
  a->insertar(0);
  a->insertar(0);
  a->insertar(1);
 a->insertar(2);
  a->insertar(1);
  a->insertar(0);
    
          a->insertar(2);
            a->insertar(0);
              a->insertar(0);
                a->insertar(1);
                  a->insertar(0);
                    a->insertar(0);
                      a->insertar(1);*/
 a->preOrden();
 /*nc::QuadTree <int, 100> *a = new nc::QuadTree <int, 100> ();
 nc::QuadTreeObject<int> *b = new nc::QuadTreeObject<int> ();
 a->insert(b);*/
}