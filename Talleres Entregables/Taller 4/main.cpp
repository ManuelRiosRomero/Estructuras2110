#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <ctime>
#include <fstream>
#include <string.h>
#include "ArbolQuad.h"
#include "NodoQuad.h"
using namespace std;
int main(int argc, char *argv[]) {
  if (argc != 3){
    cout << "Ingrese los parametros correctamente" << endl;
    exit(0);
  }
  ifstream archivo (argv[1]);
  string linea;
  int conta = 0, alt = 0, tam;
  char *p;
  ArbolQuad *a = new ArbolQuad ();
  if(!archivo.is_open()){
            cout<<"\n ¡Error al abrir el archivo!" << endl;
            exit(0);
          }
          else{
  while (getline(archivo, linea)){
    char *lineaC = new char [100000];
    strcpy(lineaC, linea.c_str());
    if (conta > 0){
      for (int i = 0; i < strlen(lineaC); i++){
        int num = lineaC[i]-'0';
        a->insertar(num);
      }
    }
    else{
      p = strtok (lineaC, " ");
      tam = atoi(p);

      
    }
    conta++;
  }
  archivo.close();
  }
  int matriz [tam][1500], conta2 = 0;
  a->generarPBM(matriz, tam, conta2);

    ofstream archivo2 (argv[2]);
  for (int i = 0; i < tam; i++){
    for (int j = 0; j < tam; j++){
    archivo2 << matriz[i][j];
  }
  archivo2 << endl;
  }
  
  cout << "Tamano del arbol almacenado: " << a->tamano() << endl;
  //a->preOrden();


  }
  