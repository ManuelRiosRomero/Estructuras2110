#include <iostream>
#include <ctime>
#include <cmath>
#include "ArbolAVL.h"
#include <set>
#include <string.h>
#include <fstream>
using namespace std;

//g++ -std=c++11 main.cpp -o main.exe
struct ltprueba{
  bool operator () (const char *p1, char *p2)const{
    return strcmp(p1, p2) < 0;
  }
};

void inOrdenLista(ArbolAVL <string> *arbol, list <string> &lista, NodoAVL<string> *raiz);

int main(int argc, char* argv[])
{

  char  *nombre;
  ArbolAVL<string> *arbol = new ArbolAVL <string>(); 
  string val;

  if (argc < 2){
    cout << "Se debe ingresar el nombre del archivo de texto como parametro" << endl;
    exit (1);
  }
  else if (argc > 2){
    cout << "Se debe ingresar unicamente el nombre del archivo de texto como parametro" << endl;
    exit (1);
  }
  

  // -------------Lectura de Archivo-------------

          ifstream archivo (argv[1]);
          
          string linea;
         clock_t init_time = clock();
          if(!archivo.is_open()){
            cout<<"\n ¡Error al abrir el archivo!";
          }
          else{
            while(getline(archivo, linea)){
              char* lineaC = new char[100], *accion, *codigo;
              strcpy(lineaC, linea.c_str());
              accion = strtok (lineaC, " ");
              codigo = strtok (NULL, " ");
              if (strcmp (accion, "A")==0){
                arbol->insertar(codigo);
              }
              else if (strcmp (accion, "E")==0){
                arbol->eliminar(codigo);
              }
              }
              archivo.close();
          }
          clock_t end_time = clock( );
          double calc_time = ( end_time - init_time ) / double( CLOCKS_PER_SEC );
      cout << "Tiempo de carga arbol AVL: " << calc_time << endl;
      cout << "Datos Cargados: " << arbol->tamano() << endl;
     // arbol->inOrden();
          set <char*, ltprueba> arbol2;

        ifstream archivo2 (argv[1]);
        
         init_time = clock();
          if(!archivo2.is_open()){
            cout<<"\n ¡Error al abrir el archivo!";
          }
          else{
            while(getline(archivo2, linea)){
              bool encontrado = false;
              char* lineaC = new char[100], *accion, *codigo;
              strcpy(lineaC, linea.c_str());
              accion = strtok (lineaC, " ");
              codigo = strtok (NULL, " ");
              if (strcmp (accion, "A")==0){
                arbol2.insert(codigo);
              }
              else if (strcmp (accion, "E")==0){
                 set <char*, ltprueba>::iterator it;
                 it = arbol2.find(codigo);
                 if (it != arbol2.end()){
                arbol2.erase(it);
                }
                
              }
              }
              archivo.close();
          }
          end_time = clock( );
          calc_time = ( end_time - init_time ) / double( CLOCKS_PER_SEC );
      cout << "Tiempo de carga arbol RN: " << calc_time << endl;
      cout << "Datos Cargados: " << arbol2.size() << endl;

      bool iguales = true;
      list <string> lis;
      inOrdenLista(arbol, lis, arbol->getRaiz());
      list <string>::iterator it2;
      set <char*, ltprueba>::iterator it = arbol2.begin();
      for (it2 = lis.begin(); it2 != lis.end(); it2++){
        if (it != arbol2.end()){
          
        if (*it2 != *it){
          iguales = false;
        }
        }
        it++;
      }
      if (iguales){
        cout << "Los arboles almacenan la misma informacion" << endl;
      }
      else{
        cout << "Los arboles no almacenan la misma informacion" << endl;
      }
      
}
void inOrdenLista(ArbolAVL <string> *arbol, list <string> &lista, NodoAVL<string> *inicio){
 if (inicio != NULL)
    {
        inOrdenLista(arbol, lista, inicio->obtenerHijoIzq());
        lista.push_back(inicio->obtenerDato());
        inOrdenLista(arbol, lista, inicio->obtenerHijoDer());
    }



}