#include <iostream>
#include <string.h>
#include <fstream>
#include <list>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include "palabra.h"
#include <stack>
#include "diccionario.h"
#include "ArbolGeneral.h"

//g++ -std=c++11 main.cpp -o main
// ./main

using namespace std;
void leerArchivo (list <Palabra> &diccJuego, Diccionario &diccio, char *parametro);
void leerArchivoInv (list <Palabra> &diccInv, Diccionario &diccio, char parametro[23]);
void buscar_por_prefijo(int pos, NodoGeneral<char> *nodo, char palabra[], list<NodoGeneral<char>* > auxlis);
//ArbolGeneral<char> leerArchivoArbol(ArbolGeneral<char> arbol, Diccionario &diccio, char *parametro);
//ArbolGeneral<char> leerArchivoArbolInv(ArbolGeneral<char> arbolInv, Diccionario &diccio, char *parametro);
//void llenarArbol(ArbolGeneral<char> &arbol, char *lineaC);
char *strrev(char *str);

int main( int argc, char* argv[] ){
  char a = '-', b, a2 = 'a', a3 = 'A';
  ArbolGeneral<char> arbolPal(a), arbolInv(a);
	NodoGeneral<char> *nodoo = arbolPal.obtenerRaiz(), *nodo2 = arbolInv.obtenerRaiz();
	for (int i = 0; i < 26; i++){
		b = a2+i;
		nodoo->adicionarDesc(b);
	}
	for (int i = 0; i < 26; i++){
		b = a3+i;
		nodoo->adicionarDesc(b);
	}
	for (int i = 0; i < 26; i++){
		b = a2+i;
		nodo2->adicionarDesc(b);
	}
	for (int i = 0; i < 26; i++){
		b = a3+i;
		nodo2->adicionarDesc(b);
	}

    char *comando = new char [200], *parametro = new char [100], *instruccion;
    bool bandera = true;
    char palabra[23];
    int pos=0;
    // -- Almacenamientos de STL --   
    Diccionario diccio; //Para almacenar a información general 
    char* diccionario = new char [200], *diccionario2 = new char [200], *diccionario3 = new char [200], *diccionario4 = new char [200] ;//para guardar diccionarios iterados y comparar
    std::list<Palabra> diccJuego; //diccionario de juego con las palabras almacenadas
    std::list<Palabra> diccInv; //diccionario de juego con las palabras invertidas almacenadas
   

     

    while (bandera){
       
        cout<<"\n\n                 ----------SCRABBLE----------" << endl;
        cout << "Ingrese 'ayuda' para ver el listado de los comandos disponibles" << endl << endl;
        //lectura del comando
        cout << "Ingrese un comando: " << endl;
        cout<< "\n$: ";
        cin.getline(comando, 200);
        //cout << strlen(comando) << endl;
        
           instruccion = strtok(comando, " ");
           parametro = strtok(NULL, " ");
           
        //cout<<comando;
     
        
      
        std::vector<char*>::iterator it2;
        if (parametro != NULL || strcmp(instruccion, "grafo_de_palabras")== 0 || strcmp(instruccion, "salir")== 0 || strcmp(instruccion, "ayuda")== 0){
        
        //-----------comando 1 incializar diccionario
        if(strcmp(instruccion, "inicializar")== 0){
          bool valida, leido = false;
          char a = 'a', b, *aux = new char [200];
          strcpy(aux, parametro);
            if (diccionario != NULL){
            if(strcmp(diccionario, aux)==0){
              leido = true;
               cout<<"\n ERROR: Ya se inicializo el diccionario: "<< parametro;
            }
            }
            
             
           
        	if (!leido){   
            strcpy (diccionario, aux);
            diccio.fijarNombre(aux); 
          cout<<"\nSe entro al comando 1";
          ifstream archivo (parametro);
          
          string linea;
         
          if(!archivo.is_open()){
            cout<<"\n ¡Error al abrir el archivo!";
          }
          else{
            leerArchivo(diccJuego, diccio, parametro);
          }
          }

        }
        
        //-----------comando 2 incia inverso diccionario

       else if(strcmp(instruccion, "iniciar_inverso")== 0){
          bool valida, leido = false;
          char a = 'a', b, *aux = new char [200];
          strcpy(aux, parametro);
            if (diccionario2 != NULL){
            if(strcmp(diccionario2, aux)==0){
              leido = true;
               cout<<"\n ERROR: Ya se inicializo el diccionario: "<< parametro;
            }
            }
           
        	if (!leido){   
            strcpy (diccionario2, aux);
            diccio.fijarNombre(aux); 
          cout<<"\nSe entro al comando 2";
          ifstream archivo (parametro);
          
          string linea;
         
          if(!archivo.is_open()){
            cout<<"\n ¡Error al abrir el archivo!";
          }
          else{
            leerArchivoInv(diccInv, diccio, parametro);
          }
          }

        }
      

        //-----------comando 3 puntaje de palabra
        else if(strcmp(instruccion, "puntaje")== 0){
          
          list <Palabra>::iterator itpal, itpal2;
          bool valida, existe = false, existeInv = false;
          char a = 'a', b;
          for (int i = 0; i < strlen(parametro); i++){
                  valida = false;
                  a = 'a';
                  for (int j = 0; j < 26; j++){
                    b = a+j;
                    if (b == parametro[i]){
                      valida = true;
                    }
                  }
                  
                    a = 'A';
                    for (int k = 0; k < 26; k++){
                    b = a+k;
                    if (b == parametro[i]){
                      valida = true;
                    }
                  }
                  
                  if (!valida){
                    break;
                  }
                }
           
          list <Palabra> lisAux = diccJuego;
          char *inver = new char [200], *aux = new char [200], *aux2 = new char [200];
          strcpy(aux, parametro);
          strcpy(inver, aux);
            strcpy(aux2, strrev(inver));
          int l = 0;
          
          for (itpal = lisAux.begin(); itpal != lisAux.end(); itpal++){
            
            if (strcmp(aux, itpal->obtenerPalabra()) == 0){
              existe = true;
              break;
            }
          }
          if (!existe){
          lisAux = diccInv;
          for (itpal = lisAux.begin(); itpal != lisAux.end(); itpal++){
             if (strcmp(aux, itpal->obtenerPalabra()) == 0){

              existe = true;
              break;
            }
          }
          }
          if (!existe){
            lisAux = diccJuego;
          for (itpal = lisAux.begin(); itpal != lisAux.end(); itpal++){
            
            if (strcmp(aux2, itpal->obtenerPalabra()) == 0){
              existe = true;
              break;
            }
          }
          
          }
          if (!existe){
            lisAux = diccInv;
          for (itpal = lisAux.begin(); itpal != lisAux.end(); itpal++){
            
            if (strcmp(aux2, itpal->obtenerPalabra()) == 0){
              existe = true;
              break;
            }
          }
          }
        
          if(!valida){
            cout << "ERROR: La palabra contiene simbolos invalidos" << endl;
          }
          else if (!existe){
            
            cout << "ERROR: La palabra no esta registrada en el diccionario" << endl;
          }
          
          else{
            itpal->puntaje();
          }
        }

        //-----------comando 4 entrega 2 inciar arbol
        else if(strcmp(instruccion,"iniciar_arbol")== 0){
         cout<<"\nSe entro al comando 4";
bool valida, leido = false;
char a = 'a', b, *aux = new char [200];
strcpy(aux, parametro);
if (diccionario3 != NULL){
    if(strcmp(diccionario3, aux)==0){
        leido = true;
        cout<<"\n ERROR: Ya se inicializo el diccionario: "<< parametro;
    }
}

if (!leido){   
    strcpy (diccionario3, aux);
    diccio.fijarNombre(aux); 
    delete[](aux);
    ifstream archivo (parametro);
    
    string linea;
    
    if(!archivo.is_open()){
        cout<<"\n ¡Error al abrir el archivo!";
    }
    else{
        char a = 'a', b;
        int conta = 0;
        cout<<"\nLeyendo archivo "<<parametro<<"..." << endl << endl;  
        while(getline(archivo, linea)){
            char* lineaC = new char[100];
            strcpy(lineaC, linea.c_str());
            int largo = strlen(lineaC);
            NodoGeneral<char> *nodo;
            nodo = arbolPal.obtenerRaiz();
            for (int i = 0; i < largo; i++){
                valida = false;
                a = 'a';
                for (int j = 0; j < 26; j++){
                    b = a+j;
                    if (b == lineaC[i]){
                        valida = true;
                    }
                }
                if (i == 0){
                    a = 'A';
                    for (int k = 0; k < 26; k++){
                        b = a+k;
                        if (b == lineaC[i]){
                            valida = true;
                        }
                    }
                }
                if (!valida){
                    break;
                }
            }
            if (valida){
                char letra;
                for (int i = 0; i < largo; i++){
                    bool esta = false;
                    letra = lineaC[i];
                    list<NodoGeneral<char>* >::iterator it;
                    list<NodoGeneral<char>* > auxlis = nodo->obtenerDesc();
                    if (i == 0){
                        for (it = auxlis.begin(); it != auxlis.end(); it++){
                            if ((*it)->obtenerDato() == letra){
                                nodo = *it;
                                break;
                            }
                        }
                    }
                    else{
                        for (it = auxlis.begin(); it != auxlis.end(); it++){
                            if ((*it)->obtenerDato() == letra){
                                esta = true;
                                nodo = *it;
                                break;
                            }
                        }
                        if (!esta){
                            nodo->adicionarDesc(letra);
                            auxlis = nodo->obtenerDesc(); 
                            for (it = auxlis.begin(); it != auxlis.end(); it++){
                                if ((*it)->obtenerDato() == letra){
                                    nodo = *it;
                                    break;
                                }
                            } 
                        }
                    }
                    
                }
            }
            conta++;
        }
        cout << "Archivo leido" << endl << endl;
        cout << "Tamano del arbol almacenado: " << arbolPal.tamano() << endl;
        //arbolPal.nivelOrden();
    }
}
        }
        //-----------comando 5 entrega 2 arbol inverso
        else if(strcmp(instruccion, "iniciar_arbol_inverso")== 0){
            cout<<"\nSe entro al comando 5" << endl;
             bool valida, leido = false;
             char a = 'a', b, *aux = new char [200];
          strcpy(aux, parametro);
            if (diccionario4 != NULL){
            if(strcmp(diccionario4, aux)==0){
              leido = true;
               cout<<"\n ERROR: Ya se inicializo el diccionario: "<< parametro;
            }
            }
           
        	if (!leido){   
            strcpy (diccionario4, aux);
            diccio.fijarNombre(aux); 
            delete[](aux);
          ifstream archivo (parametro);
          
          string linea;
         
          if(!archivo.is_open()){
            cout<<"\n ¡Error al abrir el archivo!";
          }
          else{
            char a = 'a', b;
          cout<<"\nLeyendo archivo "<<parametro<<"..." << endl << endl;  
          while(getline(archivo, linea)){
  
              char* lineaC = new char[100], *aux = new char [100];
              strcpy(aux, linea.c_str());
              strcpy(lineaC, strrev(aux));
              //delete[](aux);
              int largo = strlen(lineaC);
               NodoGeneral<char> *nodo;
			        nodo = arbolInv.obtenerRaiz();
              for (int i = 0; i < largo; i++){
                valida = false;
                a = 'a';
                for (int j = 0; j < 26; j++){
                  b = a+j;
                  if (b == lineaC[i]){
                    valida = true;
                  }
                }
                if (i == 0){
                  a = 'A';
                   for (int k = 0; k < 26; k++){
                  b = a+k;
                  if (b == lineaC[i]){
                    valida = true;
                  }
                }
                }
                if (!valida){
                  break;
                }
              }
              
              
              if (valida){
               
                  
           
               
              char l = '.';
            
                for (int i = 0; i < largo; i++){
                     
                bool esta = false;
                    list<NodoGeneral<char>* >::iterator it;
                    list<NodoGeneral<char>* > auxlis = nodo->obtenerDesc();
                    if (i == 0){
                      for (it = auxlis.begin(); it != auxlis.end(); it++){
                    if ((*it)->obtenerDato() == lineaC[i]){
                      nodo = *it;
                      break;
                    }
                  }
                    }
                    else{
                      for (it = auxlis.begin(); it != auxlis.end(); it++){
                    if ((*it)->obtenerDato() == lineaC[i]){
                      esta = true;
                      nodo = *it;
                      break;
                    }
                    }
                     if (!esta){
                    nodo->adicionarDesc(lineaC[i]);
                    auxlis = nodo->obtenerDesc();
                    for (it = auxlis.begin(); it != auxlis.end(); it++){
                    if ((*it)->obtenerDato() == lineaC[i]){
                      nodo = *it;
                      break;
                    }
                  }
                 
                  
                  
                
                }
              }
            }
          }
         }
         cout << "Archivo leido" << endl << endl;
         cout << "Tamano del arbol inverso alamacenado: " << arbolInv.tamano() << endl;
         //arbolInv.nivelOrden();
          }
          }
        }
            
        //-----------comando 6 entrega 2 palabras prefijo
        else if(strcmp(instruccion,"palabras_por_prefijo")== 0){
        	  int conta = 0;
            bool encontro = false;
            cout<<"\nSe entro al comando 6"<<endl;
          char *aux = new char [100], *pal = new char [100], *auxpal = new char [100];
            strcpy (aux, parametro); 
            NodoGeneral<char> *nodo = arbolPal.obtenerRaiz();
            list<NodoGeneral<char>* >::iterator it;
            list<char *>::iterator it2;
            list<NodoGeneral<char>* > auxlis;
            list<char *> pals;
            for (int i = 0; i < strlen(aux); i++){
              encontro = false;
              auxlis = nodo->obtenerDesc();
              for (it = auxlis.begin(); it != auxlis.end(); it++){
                if ((*it)->obtenerDato() == aux[i]){
                  pal[i] = aux[i];
                  nodo = *it;
                  encontro = true;
                }
              }
              if (!encontro){
                cout << endl << "No hay palabras registradas que empiecen con este prefijo" << endl;
                break;
              }
            }
            strcpy(auxpal, pal);
            conta = strlen(aux);
            if (encontro){
              auxlis = nodo->obtenerDesc();
              for (it = auxlis.begin(); it != auxlis.end(); it++){
               char a =  (*it)->obtenerDato();
                pal[conta] = a;
                pals.push_back(pal);
                strcpy(pal, auxpal);
              }
            }

            cout << "Palabras que empiezan con el prefijo " << parametro << ": " << endl;
             for (it2 = pals.begin(); it2 != pals.end(); it2++){
               cout << *it2 << ", ";
             }
             cout << endl;
            //buscar_por_prefijo(pos,auxNodo,palabra);
            
            
            //fin del comando 6
        }
        

        //-----------comando 7 entrega 2 palabras sufijo
        else if(strcmp(instruccion, "palabras_por_sufijo")== 0){
            cout<<"\nSe entro al comando 7";
            int conta = 0;
            bool encontro = false;
          char *aux = new char [100], *pal = new char [100], *auxpal = new char [100];
            strcpy (aux, parametro); 
            NodoGeneral<char> *nodo = arbolInv.obtenerRaiz();
            list<NodoGeneral<char>* >::iterator it;
             list<char *>::iterator it2;
            list<NodoGeneral<char>* > auxlis;
            list<char *> pals;
            for (int i = 0; i < strlen(aux); i++){
              encontro = false;
              auxlis = nodo->obtenerDesc();
              for (it = auxlis.begin(); it != auxlis.end(); it++){
                if ((*it)->obtenerDato() == aux[i]){
                  pal[i] = aux[i];
                  nodo = *it;
                  encontro = true;
                }
              }
              if (!encontro){
                cout << endl << "No hay palabras registradas que terminen con este sufijo" << endl;
                break;
              }
              
            }
            strcpy(pal, strrev(pal));
            if (encontro){
              auxlis = nodo->obtenerDesc();
              for (it = auxlis.begin(); it != auxlis.end(); it++){
                /*char a =  (*it)->obtenerDato();
                pal[conta] = a;
                pals.push_back(pal);
                strcpy(pal, auxpal);*/
                pals.push_back(pal);
              }
            }

            cout << "Palabras que terminan con el sufijo " << pal << ": " << endl;
             for (it2 = pals.begin(); it2 != pals.end(); it2++){
               cout << *it2 << ", ";
             }
             cout << endl;
        }

        //-----------comando 8 entrega 3 grafo de palabras
        else if(strcmp(instruccion,"grafo_de_palabras")== 0){
            cout<<"\nSe entro al comando 8";
        }

        //-----------comando 9 entrega 3 posibles palabras letras
        else if(strcmp(instruccion, "posibles_palabras")== 0){
        	cout << "Parametro: " << parametro << endl;
          cout<<"\nSe entro al comando 9";
        }

        //-----------comando de ayuda
        else if(strcmp(instruccion, "ayuda")== 0){
          if(parametro == NULL){
             cout<<"\n\n----------SCRABBLE----------";
              cout<<"\n-----Lista de Comandos------";
              cout<<"\n1. inicializar ARCHIVO";
              cout<<"\n2. iniciar_inverso ARCHIVO";
              cout<<"\n3. puntaje PALABRA";
              cout<<"\n";
              cout<<"\n ---/---/---/---/---/---/---";
              cout<<"\n4. iniciar_arbol ARCHIVO";
              cout<<"\n5. iniciar_arbol_inverso ARCHIVO";
              cout<<"\n6. palabras_por_prefijo PREFIJO";
              cout<<"\n7. palabras_por_sufijo SUFIJO (invertido)";
              cout<<"\n";
              cout<<"\n ---/---/---/---/---/---/---";
              cout<<"\n8. grafo_de_palabras";
              cout<<"\n9. posibles_palabras LETRAS";
              cout<<"\n0. salir";
              cout<<"\n#. ayuda (COMANDO)";
              cout<<"\n-----------------------------\n";
          }
          else{
            cout << endl;
            if (strcmp(parametro, "inicializar")==0){
              cout << endl;
              cout << "Comando inicializar: " << endl << endl;
              cout << "Uso correcto: inicializar ARCHIVO.TXT" << endl;
              cout << "Descripcion: " << endl;
              cout << "Inicializa el sistema a partir de un archivo de texto, que contiene un diccionario de palabras aceptadas en el idioma inglés." << endl;
            }
            else if (strcmp(parametro, "iniciar_inverso")==0){
               cout << endl;
              cout << "Comando iniciar_inverso: " << endl << endl;
              cout << "Uso correcto: iniciar_inverso ARCHIVO.TXT" << endl << endl;
              cout << "Descripcion: " << endl;
              cout << "Inicializa el sistema con las palabras en sentido inverso a partir de un archivo de texto, que contiene un diccionario de palabras aceptadas en el idioma inglés." << endl;
                        
            }
            else if (strcmp(parametro, "puntaje")==0){
               cout << endl;
              cout << "Comando puntaje: " << endl << endl;
              cout << "Uso correcto: puntaje PALABRA" << endl << endl;
              cout << "Descripcion: " << endl;
              cout << "El comando permite conocer la puntuación que puede obtenerse con una palabra dada." << endl;
            }
            else if (strcmp(parametro, "iniciar_arbol")==0){
               cout << endl;
              cout << "Comando iniciar_arbol: " << endl << endl;
              cout << "Uso correcto: iniciar_arbol ARCHIVO.TXT" << endl << endl;
              cout << "Descripcion: " << endl;
              cout << "Inicializa el sistema a partir un archivo de texto, que contiene un diccionario de palabras aceptadas en el idioma inglés." << endl;
            }
            else if (strcmp(parametro, "iniciar_arbol_inverso")==0){
               cout << endl;

             cout << "Comando iniciar_arbol_inverso: " << endl << endl;
              cout << "Uso correcto: iniciar_arbol_inverso ARCHIVO.TXT" << endl << endl;
              cout << "Descripcion: " << endl;
              cout << "Inicializa el sistema con las palabras en sentido inverso a partir un archivo de texto, que contiene un diccionario de palabras aceptadas en el idioma inglés." << endl;
            }
            else if (strcmp(parametro, "palabras_por_prefijo")==0){
               cout << endl;

              cout << "Comando palabras_por_prefijo: " << endl << endl;
              cout << "Uso correcto: palabras_por_prefijo PREFIJO" << endl << endl;
              cout << "Descripcion: " << endl;
              cout << "Dado un prefijo de pocas letras, ubica todas las palabras posibles a construir a partir de ese prefijo" << endl;

            }
            else if (strcmp(parametro, "palabras_por_sufijo")==0){
               cout << endl;

              cout << "Comando palabras_por_sufijo: " << endl << endl;
              cout << "Uso correcto: palabras_por_sufijo SUFIJO (invertido)" << endl << endl;
              cout << "Descripcion: " << endl;
              cout << "Dado un sufijo de pocas letras, ubica todas las palabras posibles a construir que terminan con ese sufijo" << endl;
            }
            else if (strcmp(parametro, "grafo_de_palabras")==0){
               cout << endl;

              cout << "Comando grafo_de_palabras: " << endl << endl;
              cout << "Uso correcto: grafo_de_palabras" << endl << endl;
              cout << "Descripcion: " << endl;
              cout << "Con las palabras ya almacenadas en el diccionario, el comando construye un grafo de palabras, en donde cada palabra se conecta a las demás si y sólo sí difieren en un única letra" << endl;
            }
            else if (strcmp(parametro, "posibles_palabras")==0){
               cout << endl;

              cout << "Comando posibles_palabras: " << endl << endl;
              cout << "Uso correcto: posibles_palabras LETRAS" << endl << endl;
              cout << "Descripcion: " << endl;
              cout << "Dadas ciertas letras en una cadena de caracteres, presenta en pantalla todas las posibles palabras válidas a construir, indicando la longitud de cada una y la puntuación que se puede obtener con cada una" << endl;
            }
            else if (strcmp(parametro, "salir")==0){
               cout << endl;

              cout << "Uso correcto: salir" << endl << endl;
              cout << "Descripcion: " << endl;
              cout << "Termina la ejecucion de la aplicacion" << endl;
            }
            else if (strcmp(parametro, "ayuda")==0){
               cout << endl;

               cout << "Uso correcto: ayuda COMANDO (opcional)" << endl << endl;
              cout << "Descripcion: " << endl;
              cout << "Muestra la totalidad de los comandos disponibles o ayuda para un comando en especifico." << endl;
            }
            else{
              cout << "Ingrese un comando valido del cual desea ver la ayuda" << endl;
            }

          }
        }  
        //-----------Salir del ciclo
        else if(strcmp(instruccion, "salir") == 0){
            bandera = false;
        }
        else{
            cout<<"\nComando no identificado...";
        }
        cout<<"\n\n";
}
else{
  cout << "ERROR: Debe ingresar un comando valido o un parametro valido para este comando" << endl;
}
    }

}


void leerArchivo (list <Palabra> &diccJuego, Diccionario &diccio, char *parametro){
    char a = 'a', b;
    bool valida, leido = false;
    string linea;
    ifstream archivo(parametro);
    cout<<"\nLeyendo archivo "<<parametro<<"..." << endl << endl;
    diccJuego.clear();                        
    while(getline(archivo, linea)){
        char* lineaC = new char[100];
        int l = 0;
        strcpy(lineaC, linea.c_str());
        
        
        for (int i = 0; i < strlen(lineaC); i++){
            valida = false;
            a = 'a';
            for (int j = 0; j < 26; j++){
                b = a+j;
                if (b == lineaC[i]){
                    valida = true;
                }
            }
            if (i == 0){
                a = 'A';
                for (int k = 0; k < 26; k++){
                    b = a+k;
                    if (b == lineaC[i]){
                        valida = true;
                    }
                }
            }
            
            if (!valida){
                break;
            }
        }
        if (valida){
            
            
            Palabra p;
            p.fijarPalabra(lineaC);
            diccJuego.push_back(p);
            
            
            
        }
    }
    archivo.close();
    diccio.fijarPalabras(diccJuego);
    diccio.fijarTotal(diccJuego.size());
    
    
    if(diccJuego.empty()){
        cout<<"\nLa lista de palabras esta vacia";
    }
    else{
        cout << "Archivo leido" << endl;
        cout << "Palabras almacenadas: " << diccJuego.size() << endl;
    }
}

void leerArchivoInv (list <Palabra> &diccInv, Diccionario &diccio, char *parametro){
    char a = 'a', b;
    bool valida, leido = false;
    string linea;
    ifstream archivo(parametro);
    cout<<"\nLeyendo archivo "<<parametro<<"..." << endl << endl;
    diccInv.clear();                        
    while(getline(archivo, linea)){
        char* lineaC = new char[100];
        int l = 0;
        strcpy(lineaC, linea.c_str());
        
        
        for (int i = 0; i < strlen(lineaC); i++){
            valida = false;
            a = 'a';
            for (int j = 0; j < 26; j++){
                b = a+j;
                if (b == lineaC[i]){
                    valida = true;
                }
            }
            if (i == 0){
                a = 'A';
                for (int k = 0; k < 26; k++){
                    b = a+k;
                    if (b == lineaC[i]){
                        valida = true;
                    }
                }
            }
            
            if (!valida){
                break;
            }
        }
        if (valida){
            
            
            Palabra p;
            p.fijarPalabra(lineaC);
            diccInv.push_back(p);
            
            
            
        }
    }
    archivo.close();
    diccio.fijarPalabrasInv(diccInv);
    diccio.fijarTotal(diccInv.size());
    
    
    if(diccInv.empty()){
        cout<<"\nLa lista de palabras esta vacia";
    }
    else{
        cout << "Archivo leido" << endl;
        cout << "Palabras almacenadas: " << diccInv.size() << endl;

    }
}

/*ArbolGeneral<char>leerArchivoArbol(ArbolGeneral<char> arbol, Diccionario &diccio, char *parametro){

bool valida, leido = false;
  string linea;
  ArbolGeneral<char> aarbol = arbol;
  ifstream archivo2 (parametro);
  char a = 'a', b, *aux = new char [200];
          cout<<"\nLeyendo archivo "<<parametro<<"..." << endl << endl;  
while(getline(archivo2, linea)){
  
              char* lineaC = new char[100];
              strcpy(lineaC, linea.c_str());
              int largo = strlen(lineaC);
               NodoGeneral<char> *nodo = new NodoGeneral<char>();
			        nodo = aarbol.obtenerRaiz();
              for (int i = 0; i < largo; i++){
                valida = false;
                a = 'a';
                for (int j = 0; j < 26; j++){
                  b = a+j;
                  if (b == lineaC[i]){
                    valida = true;
                  }
                }
                if (i == 0){
                  a = 'A';
                   for (int k = 0; k < 26; k++){
                  b = a+k;
                  if (b == lineaC[i]){
                    valida = true;
                  }
                }
                }
              
                if (!valida){
                  break;
                }
               
                
              }
              
              
              if (valida){
               cout << "Hola" << " ";
                  
              
                bool esta = false;
                for (int i = 0; i < largo; i++){
                  
                  list<NodoGeneral<char>* >::iterator it;
                  
                  for (it = nodo->obtenerDesc().begin(); it != nodo->obtenerDesc().end(); it++){
                    if ((*it)->obtenerDato() == lineaC[i]){
                      esta = true;
                      nodo = *it;
                      break;
                    }
                  }
                  if (!esta){
                    nodo->adicionarDesc(lineaC[i]);
                    for (it = nodo->obtenerDesc().begin(); it != nodo->obtenerDesc().end(); it++){
                    if ((*it)->obtenerDato() == lineaC[i]){
                      nodo = *it;
                      break;
                    }
                  }
                  }
                
                
                }
              }
  }
           
                       
            
             cout << "Sale" << endl;
              diccio.fijarArbolPal(aarbol);
              return aarbol;
            }

ArbolGeneral<char> leerArchivoArbolInv(ArbolGeneral<char> arbolInv, Diccionario &diccio, char *parametro){
    bool valida, leido = false;
  string linea;
  NodoGeneral<char> *nodo;
  ifstream archivo (parametro);
          char a = 'a', b, *aux = new char [200];
          cout<<"\nLeyendo archivo "<<parametro<<"..." << endl << endl;                      
            while(getline(archivo, linea)){
              
              char* lineaC = new char[100], *aux = new char [100];
              strcpy(aux, linea.c_str());
              strcpy(lineaC, strrev(aux));
			        nodo = arbolInv.obtenerRaiz();
              for (int i = 0; i < strlen(lineaC); i++){
                valida = false;
                a = 'a';
                for (int j = 0; j < 26; j++){
                  b = a+j;
                  if (b == lineaC[i]){
                    valida = true;
                  }
                }
                if (i == 0){
                  a = 'A';
                   for (int k = 0; k < 26; k++){
                  b = a+k;
                  if (b == lineaC[i]){
                    valida = true;
                  }
                }
                }
              
                if (!valida){
                  break;
                }
                
              }
              
              if (valida){
                bool esta = false;
                for (int i = 0; i < strlen(lineaC); i++){
                  list<NodoGeneral<char>* >::iterator it;
                  if (!nodo->obtenerDesc().empty()){
                  for (it = nodo->obtenerDesc().begin(); it != nodo->obtenerDesc().end(); it++){
                    if ((*it)->obtenerDato() == lineaC[i]){
                      esta = true;
                      nodo = *it;
                      break;
                    }
                  }
                  if (!esta){
                    nodo->adicionarDesc(lineaC[i]);
                    for (it = nodo->obtenerDesc().begin(); it != nodo->obtenerDesc().end(); it++){
                    if ((*it)->obtenerDato() == lineaC[i]){
                      nodo = *it;
                      break;
                    }
                  }
                  }
                }
                else{
                  nodo->adicionarDesc(lineaC[i]);
                    for (it = nodo->obtenerDesc().begin(); it != nodo->obtenerDesc().end(); it++){
                    if ((*it)->obtenerDato() == lineaC[i]){
                      nodo = *it;
                      break;
                    }
                  }
                }
                }
              }
              
              }
              diccio.fijarArbolInv(arbolInv);
              return arbolInv;

  }

void llenarArbol(ArbolGeneral<char> &arbol, char *lineaC){
  NodoGeneral<char> *nodo = new NodoGeneral<char>();
			        nodo = arbol.obtenerRaiz();
              bool esta = false;
                for (int i = 0; i < strlen(lineaC); i++){
                  
                  list<NodoGeneral<char>* >::iterator it;
                  
                  for (it = nodo->obtenerDesc().begin(); it != nodo->obtenerDesc().end(); it++){
                    if ((*it)->obtenerDato() == lineaC[i]){
                      esta = true;
                      nodo = *it;
                      break;
                    }
                  }
                  if (!esta){
                    nodo->adicionarDesc(lineaC[i]);
                    for (it = nodo->obtenerDesc().begin(); it != nodo->obtenerDesc().end(); it++){
                    if ((*it)->obtenerDato() == lineaC[i]){
                      nodo = *it;
                      break;
                    }
                  }
                  }
                
                
                }
}*/

char *strrev(char *str){
      char *p1, *p2;

      if (! str || ! *str)
            return str;
      for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2)
      {
            *p1 ^= *p2;
            *p2 ^= *p1;
            *p1 ^= *p2;
      }
      return str;
     /* char *inv = new char [100];
      int j = 0;
      for (int i = strlen(str)-1; i >= 0; i--){
        inv[j] = str[i];
        j++;
      }
      return inv;*/
      
}

/*void buscar_por_prefijo(int pos, NodoGeneral<char> *nodo, char palabra[], list<NodoGeneral<char>* > auxlis)
{
  list<NodoGeneral<char>* >::iterator itp;
  for (int i = 0; i<nodo->obtenerDesc().size(); i++)
  {
    for(itp = nodo->obtenerDesc().begin(); itp != nodo->obtenerDesc().end(); itp++)
    {
      if(itp->obtenerDato() == palabra[pos])
      {
        if(itp->esHoja()==false)
        {
          auxlis.push_back(palabra);
          return;
        }
        else{
          buscar_por_prefijo(pos++, *nodo, palabra[palabra.sizeof()], auxlis);       
        }
      }
    }
  }
}*/
