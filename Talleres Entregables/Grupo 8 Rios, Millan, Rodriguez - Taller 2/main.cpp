#include <iostream>
#include <fstream>
#include <string.h>
#include <string>
#include <cstring>
#include <list>
#include <vector>
#include <algorithm>
#include "cancion.h"
using namespace std;


void listarAutores();
void listarCancionesPorAutor(string nombreAutor);
void listarCancionesPorAlbum(string nombreAlbum);
void listarCancionesMasAlbum();
void listarAlbums();

bool mycomp(char *a, char *b);
bool mycomp2(Cancion a, Cancion b);

// Lista con canciones
list<Cancion> lista;
list<Cancion> :: iterator it;



int main() {
  int menu, conta = 0;
  string narchivo, linea;
  char *p;
  cout << "\nIngrese el nombre del archivo de texto: ";
      cin>>narchivo;
      ifstream archivo (narchivo);
      if (!archivo.is_open()){
        cout << "No fue posible abrir el archivo" << endl;
      }
      else{
        cout << "Archivo leido" << endl;
        while ( getline (archivo,linea) ) {
          Cancion can;
          char *aux = new char [1000];
          strcpy(aux, linea.c_str());
        if (conta > 0){
          p = strtok(aux, "|");
          strcpy(can.nombre, p);
           p = strtok(NULL, "|");
           strcpy(can.autor, p);
            p = strtok(NULL, "|");
           strcpy(can.genero, p);
            p = strtok(NULL, "|");
           strcpy(can.album, p);
            p = strtok(NULL, "|");
           strcpy(can.anho, p); 
           lista.push_back(can);
          }
          conta++;
        }
        archivo.close();
      }      
      
  
  do{
    cout<<"\n |------------------Menu------------------|";
    cout<<"\n 1. Leer nuevo archivo";
    cout<<"\n 2. Listar todos los autores presentes, ordenados alfabéticamente";
    cout<<"\n 3. Dado un autor, listar todas sus canciones ordenadas alfabéticamente.";
    cout<<"\n 4. Dado un álbum, listar todas las canciones que componen un álbum, ordenadas alfabéticamente por el nombrede la canción.";
    cout<<"\n 5. Listar todas las canciones y su álbum, ordenadas alfabéticamente primero por el álbum y después por elnombre de la canción.";
    cout<<"\n 6. Listar albums ordenados cronologicamente.";
    cout<<"\n 0. SALIR";
    cout << "\nIngrese una opcion (numero de la opcion): " << endl;
    cin >> menu;
    switch(menu){ 
      case 1:{
        lista.clear();
        conta = 0;
      cout << "\nIngrese el nombre del archivo de texto: ";
      cin>>narchivo;
      ifstream archivo2 (narchivo);
      if (!archivo2.is_open()){
        cout << "\nNo fue posible abrir el archivo" << endl;
      }
      else{
        cout << "Archivo leido" << endl;
        while ( getline (archivo2,linea) ) {
          Cancion can;
          char *aux = new char [1000];
          strcpy(aux, linea.c_str());
        if (conta > 0){
          p = strtok(aux, "|");
          strcpy(can.nombre, p);
           p = strtok(NULL, "|");
           strcpy(can.autor, p);
            p = strtok(NULL, "|");
           strcpy(can.genero, p);
            p = strtok(NULL, "|");
           strcpy(can.album, p);
            p = strtok(NULL, "|");
           strcpy(can.anho, p);

           
          lista.push_back(can);
        }
conta++;
}
archivo2.close();
      }
      
      }
      break;

      case 2:{
      cout<<"Autores:"<<endl << endl;
      listarAutores();
      }
      break;

      case 3:{
      string nombreAutor;
      cout<<"Ingrese el nombre del autor del cual desea conocer las canciones:"<<endl;
      cin>>nombreAutor;
      listarCancionesPorAutor(nombreAutor);
      }
      break;

      case 4:{
      string nombreAlbum;
      cout<<"Ingrese el nombre del album del cual desea conocer las canciones:"<<endl;
      cin>>nombreAlbum;
      listarCancionesPorAlbum(nombreAlbum);
      }
      break;

      case 5:{
      cout<<"Lista de Todas las Canciones Y su Album :"<<endl;
      listarCancionesMasAlbum();
      }
      break;

      case 6:{
        cout<<"Lista de Albums Ordenados Cronologicamente: " << endl;
        listarAlbums();
      }


      case 0:
      break;

      default:
        cout<<"\n Ingrese un comando valido...";
      
    }
    
  }while( menu != 0);
}



void listarAutores(){
  vector <char*> autores;
  vector <char*> :: iterator itaut, itaut2;
  for (it = lista.begin(); it != lista.end(); it++){
    autores.push_back(it->autor);
  }
  char *aux = new char [200];

  sort (autores.begin(), autores.end(), mycomp);
  for (itaut = autores.begin(); itaut != autores.end(); itaut++){
    cout << *itaut << endl;
  }
  delete[]aux;
};

void listarCancionesPorAutor(string nombreAutor){
  vector <char*> canciones;
  vector <char*> :: iterator itcan;
  char *aux = new char [200];
  strcpy(aux, nombreAutor.c_str());
  
  for (it = lista.begin(); it != lista.end(); it++){
    if (strcmp(aux, it->autor)==0){
      canciones.push_back(it->nombre);
    }
  }
  if (canciones.empty()){
    cout << endl << "No hay canciones registradas para este autor" << endl;
    return;
  }
  sort (canciones.begin(), canciones.end(), mycomp);
  cout << endl << "Canciones de " << nombreAutor << ": " << endl << endl;
  for (itcan = canciones.begin(); itcan != canciones.end(); itcan++){
    cout << *itcan << endl;
  }
  delete[]aux;
};

void listarCancionesPorAlbum(string nombreAlbum){
  vector<char*> canciones;
  vector<char*>::iterator itc;
  char* aux = new char [200];
  strcpy(aux,nombreAlbum.c_str());
    for (it = lista.begin(); it != lista.end(); it++){
      if(strcmp(aux, it->album)==0){
        canciones.push_back(it->nombre);
      }
    }
    if(canciones.empty()){
      cout << endl << "No hay canciones registradas para este Album" << endl;
      return;
    }

    sort (canciones.begin(), canciones.end(), mycomp);
    cout<<"\n Canciones del album "<<nombreAlbum<< ": \n";
    for(itc=canciones.begin(); itc!=canciones.end(); itc++){
      cout<<*itc<< endl;
    }
  delete[]aux; 
  
};

void listarCancionesMasAlbum(){
  vector<char*> nombres;
  vector<char*> albums;
  vector<char*>::iterator itn;
  vector<char*>::iterator ita;
    for (it = lista.begin(); it != lista.end(); it++){
        nombres.push_back(it->nombre);
    }
    for (it = lista.begin(); it != lista.end(); it++){
        albums.push_back(it->album);
    }
    sort (nombres.begin(), nombres.end(), mycomp);
    cout<<"Canciones:"<<endl;
    for(itn=nombres.begin(); itn!=nombres.end(); itn++){
      cout<<*itn<<endl;
    }
    cout<<endl<<endl;
    sort (albums.begin(), albums.end(), mycomp);
    cout<<"Albums:"<<endl;
    for(ita=albums.begin(); ita!=albums.end(); ita++){
      cout<<*ita<<endl;
    } 
};

void listarAlbums(){
  vector <Cancion> canciones;
  vector<Cancion>::iterator itcan;
for (it = lista.begin(); it != lista.end(); it++){
        canciones.push_back(*it);
    }
    sort (canciones.begin(), canciones.end(), mycomp2);
for (itcan = canciones.begin(); itcan != canciones.end(); itcan++){
  cout << itcan->album << " - " << itcan->anho << endl;
}

}

bool mycomp(char *a, char *b){
if (strcmp(a, b)<0){
  return true;
}
return false;
};

bool mycomp2(Cancion a, Cancion b){
if (strcmp(a.anho, b.anho) < 0){
  return true;
}
return false;
};
