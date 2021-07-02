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
#include "grafo.h"

//g++ -std=c++11 main.cpp -o main
// ./main

using namespace std;
void leerArchivo (list <Palabra> &diccJuego, Diccionario &diccio, char *parametro);
void leerArchivoInv (list <Palabra> &diccInv, Diccionario &diccio, char parametro[23]);
void buscarPals(list <string> &pals, int pos, char *pal,  NodoGeneral<char> *nodo);

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
    Diccionario diccio; //Para almacenar a informaciÃ³n general 
    char* diccionario = new char [200], *diccionario2 = new char [200], *diccionario3 = new char [200], *diccionario4 = new char [200] ;//para guardar diccionarios iterados y comparar
    std::list<Palabra> diccJuego; //diccionario de juego con las palabras almacenadas
    std::list<Palabra> diccInv; //diccionario de juego con las palabras invertidas almacenadas
   Grafo<Palabra> *grafo = new Grafo<Palabra>();

     

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
            cout<<"\n Â¡Error al abrir el archivo!";
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
            cout<<"\n Â¡Error al abrir el archivo!";
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
                    if (b == parametro[i] || i == (strlen(parametro)-1)){
                      valida = true;
                    }
                  }
                  
                    a = 'A';
                    for (int k = 0; k < 26; k++){
                    b = a+k;
                    if (b == parametro[i] || i == (strlen(parametro)-1)){
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
        cout<<"\n Â¡Error al abrir el archivo!";
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
              //if(i < (largo-1)){
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
                //}
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
            cout<<"\n Â¡Error al abrir el archivo!";
          }
          else{
            char a = 'a', b;
          cout<<"\nLeyendo archivo "<<parametro<<"..." << endl << endl;  
          while(getline(archivo, linea)){
  
              char* lineaC = new char[100], *aux = new char [100];
              strcpy(aux, linea.c_str());
              strcpy(lineaC, strrev(aux));
              linea = lineaC;
              delete[](aux);
              int largo = strlen(linea.c_str());
               NodoGeneral<char> *nodo;
			        nodo = arbolInv.obtenerRaiz();
              for (int i = 0; i < largo; i++){
                //if(i < (largo-3)){
                valida = false;
                a = 'a';
                for (int j = 0; j < 26; j++){
                  b = a+j;
                  if (b == linea[i] || linea[i] == ' '){
                    valida = true;
                  }
                }
                if (i == 0){
                  a = 'A';
                   for (int k = 0; k < 26; k++){
                  b = a+k;
                  if (b == linea[i]){
                    valida = true;
                  }
                }
                }
                if (!valida){
                  break;
                }
                //}
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
        	  int pos = 0;
            bool encontro = false;
            cout<<"\nSe entro al comando 6"<<endl;
          char *aux = new char [100], *pal = new char [100], *auxpal = new char [100];
            strcpy (aux, parametro); 
            NodoGeneral<char> *nodo = arbolPal.obtenerRaiz();
            list<NodoGeneral<char>* >::iterator it;
            list<string>::iterator it2;
            list<NodoGeneral<char>* > auxlis;
            list<string> pals;
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
            pos = strlen(aux);
            if (encontro){
            auxlis = nodo->obtenerDesc();
            for (it = auxlis.begin(); it != auxlis.end(); it++){
              pal[pos] = (*it)->obtenerDato();
               string c;
                c = pal;
              if ((*it)->esHoja()){
                pals.push_back(c);
              }
              else{
                pal = new char[strlen(c.c_str())];
              strcpy(pal, c.c_str());
              buscarPals(pals, pos+1, pal, *it);
               pal = new char[strlen(c.c_str())];
               strcpy(pal, c.c_str());
              }
              }
            


            
            Palabra p;
            cout << "Palabras que empiezan con el prefijo " << parametro << ": " << endl;
             for (it2 = pals.begin(); it2 != pals.end(); it2++){
               auxpal = new char [strlen(it2->c_str())-1];
               strcpy(auxpal, it2->c_str());
               p.fijarPalabra(auxpal);
               p.puntaje();
               cout << "Longitud: " << strlen(auxpal) << endl;

               
             }
             cout << endl;
             }
            //buscar_por_prefijo(pos,auxNodo,palabra);
            
            
            //fin del comando 6
        }
        

        //-----------comando 7 entrega 2 palabras sufijo
        else if(strcmp(instruccion, "palabras_por_sufijo")== 0){
      	  int pos = 0;
            bool encontro = false;
            cout<<"\nSe entro al comando 7"<<endl;
          char *aux = new char [100], *pal = new char [100], *auxpal = new char [100];
            strcpy (aux, parametro); 
            NodoGeneral<char> *nodo = arbolInv.obtenerRaiz();
            list<NodoGeneral<char>* >::iterator it;
            list<string>::iterator it2;
            list<NodoGeneral<char>* > auxlis;
            list<string> pals;
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
                nodo = arbolInv.obtenerRaiz();
                strcpy(aux, strrev(aux));
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

                break;
              }
            }
            pos = strlen(aux);
            if (encontro){
            auxlis = nodo->obtenerDesc();
            for (it = auxlis.begin(); it != auxlis.end(); it++){
              pal[pos] = (*it)->obtenerDato();
               string c;
                c = pal;
              if ((*it)->esHoja()){
                char *auxinv = new char [strlen(c.c_str())];
                strcpy(auxinv, c.c_str());
                pals.push_back(strrev(auxinv));
              }
              else{
                pal = new char[strlen(c.c_str())];
              strcpy(pal, c.c_str());
              buscarPals(pals, pos+1, pal, *it);
               pal = new char[strlen(c.c_str())];
               strcpy(pal, c.c_str());
              }
              }
            


            
            Palabra p;
            cout << "Palabras que terminan con el sufijo " << strrev(parametro) << ": " << endl;
             for (it2 = pals.begin(); it2 != pals.end(); it2++){
               auxpal = new char [strlen(it2->c_str())-1];
               strcpy(auxpal, it2->c_str());
               p.fijarPalabra(strrev(auxpal));
               p.puntaje();
               cout << "Longitud: " << strlen(auxpal) << endl;

               
             }
             cout << endl;
             }
        }

        //-----------comando 8 entrega 3 grafo de palabras
        else if(strcmp(instruccion,"grafo_de_palabras")== 0){
            cout<<"\nSe entro al comando 8" << endl;

            if (diccJuego.empty()){
              cout << "No hay palabras almacenadas en el diccionario" << endl;
            }
            else{
              int conta = 0, l1, l2, k = 0;
              Palabra p, pp;
              list<Palabra>::iterator it = diccJuego.begin();
              char *p1 = new char[100], *p2 = new char [100];
              cout << "Insertando vertices..." << endl;
              for(; it != diccJuego.end(); it++){
                grafo->insertarVertices(*it);
              }
              list<Vertice<Palabra>> v = grafo->getVertices();
               cout << "Vertices insertados correctamente" << endl << endl;
               list<Vertice<Palabra>>::iterator it2 = v.begin();
               list <Vertice<Palabra>>::iterator it3 = v.begin();
               cout << "Insertando conexiones..." << endl;
              for (; it2 != v.end(); it2++){
                k = 0;
                p =  *it2->getDato(); 
                strcpy(p1, p.obtenerPalabra());
                 l1 = strlen(p1);
                for (it3 = v.begin(); it3 != v.end(); it3++){
                  pp = *it3->getDato();
                  strcpy(p2, pp.obtenerPalabra());
                  l2 = strlen(p2);
                conta = 0;
                if (strcmp(p1, p2) != 0){
                  if(l1 < l2){
                    for (int i = 0; i < l2; i++){
                      if (p1[i] != p2[i]){
                        conta++;
                        if(conta > 1){
                          break;
                        }
                      }
                    }
                    if (conta == 1){
                     grafo->insertarAristas(p, pp, 0);
                    
                  }
                  }
                  else if(l2 < l1){
                    for (int i = 0; i < l1; i++){
                      if (p1[i] != p2[i]){
                        conta++;
                        if(conta > 1){
                          break;
                        }
                      }
                    }
                    if (conta == 1){
                      grafo->insertarAristas(p, pp, 0);
                    }
                  
                  }
                  else if(l2 == l1){
                    for (int i = 0; i < l1; i++){
                      if (p1[i] != p2[i]){
                        conta++;
                        if(conta > 1){
                          break;
                        }
                      }
                    }
                    if (conta == 1){
                      grafo->insertarAristas(p, pp, 0);
                    }
                  }

                
              }
              k++;
              if(k >= 10){
                break;
              }
              }
             

              
            }
              cout << "Conexiones insertadas correctamente" << endl << endl;
            
            }

        }

        //-----------comando 9 entrega 3 posibles palabras letras
        else if(strcmp(instruccion, "posibles_palabras")== 0){
          
          cout<<"\nSe entro al comando 9" << endl;
          char *aux = new char [100], a, b, *dat = new char [100];
          Palabra dato;
          bool valida = false, encontro = false, esta = false;
           int ind, conta = 0, reps[100];
           strcpy(aux, parametro);
          int largo = strlen(aux);
          for (int i = 0; i < largo; i++){
                valida = false;
                a = 'a';
                for (int j = 0; j < 26; j++){
                    b = a+j;
                    if (b == aux[i] || aux[i] == '?'){
                        valida = true;
                    }
                }
                if (i == 0){
                    a = 'A';
                    for (int k = 0; k < 26; k++){
                        b = a+k;
                        if (b == aux[i] || aux[i] == '?'){
                            valida = true;
                        }
                    }
                }
                if (!valida){
                    break;
                }
            }
            if(!valida){
              cout << "ERROR: Las letras ingresadas contienen caracteres invalidos" << endl;
            }
            else{
           
           list<Vertice<Palabra>> v = grafo->getVertices();
            list<Vertice<Palabra>>::iterator it = v.begin();
            list<Arista<Palabra>>*ar;
            list <Palabra> palas;
             list <Palabra>::iterator it2;
             list<Arista<Palabra>>::iterator it3;
            if(v.empty()){
              cout << "ERROR: No se ha construido el grafo de palabras" << endl;
            }
            else{
              for (; it != v.end(); it++){
                encontro = false;
                conta = 0;
                int conta2 = 0;
                dato = *it->getDato();
                dat = dato.obtenerPalabra();
                 int l = strlen(dat);
                 for (int i = 0; i < l; i++){
                   conta2 = 0;
                   for (int j = 0; j < largo; j++){
                   if(dat[i] == aux[j]){
                     conta2++;
                   }
                 }
                 reps[i] = conta2;
                 }
                for (it2 = palas.begin(); it2 != palas.end(); it2++){
                  if (strcmp(dat, it2->obtenerPalabra()) == 0){
                    encontro = true;
                    break;
                  }
                }
                if (!encontro){
                  for (int i = 0; i < l; i++){
                    esta = false;
                     for (int k = 0; k < largo; k++){
                       if(dat[i] == aux[k]){
                         esta = true;
                         break;
                       }
                     }
                    if(esta){
                     if(reps[i] > 0){
                      conta++;
                      for (int j = 0; j < l; j++){
                        if(dat[j] == dat[i]){
                          reps[j]--;
                        }
                        }
                     }
                    }
                  }
                     
                    
                       if(conta == l){
                         palas.push_back(dato);
                       }
                       else if (conta == (l-1)){
                         esta = false;
                     for (int k = 0; k < largo; k++){
                       if('?' == aux[k]){
                         esta = true;
                         break;
                       }
                     }
                     if(esta){
                       palas.push_back(dato);
                     }
                       }
                     
                    
                }

              }
            
            if(palas.empty()){
              cout << "No se puede construir ninguna palabra con las letras dadas" << endl;
            }
            else{
            cout << "Palabras que se pueden construir con las letras: " << aux << ": " << endl << endl;
            for (it2 = palas.begin(); it2 != palas.end(); it2++){ 
              it2->puntaje();
              cout << "Longitud: " << strlen(it2->obtenerPalabra()) << endl << endl;
            }
            }
            palas.clear();
            }
            }




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
              cout << "Inicializa el sistema a partir de un archivo de texto, que contiene un diccionario de palabras aceptadas en el idioma inglÃ©s." << endl;
            }
            else if (strcmp(parametro, "iniciar_inverso")==0){
               cout << endl;
              cout << "Comando iniciar_inverso: " << endl << endl;
              cout << "Uso correcto: iniciar_inverso ARCHIVO.TXT" << endl << endl;
              cout << "Descripcion: " << endl;
              cout << "Inicializa el sistema con las palabras en sentido inverso a partir de un archivo de texto, que contiene un diccionario de palabras aceptadas en el idioma inglÃ©s." << endl;
                        
            }
            else if (strcmp(parametro, "puntaje")==0){
               cout << endl;
              cout << "Comando puntaje: " << endl << endl;
              cout << "Uso correcto: puntaje PALABRA" << endl << endl;
              cout << "Descripcion: " << endl;
              cout << "El comando permite conocer la puntuaciÃ³n que puede obtenerse con una palabra dada." << endl;
            }
            else if (strcmp(parametro, "iniciar_arbol")==0){
               cout << endl;
              cout << "Comando iniciar_arbol: " << endl << endl;
              cout << "Uso correcto: iniciar_arbol ARCHIVO.TXT" << endl << endl;
              cout << "Descripcion: " << endl;
              cout << "Inicializa el sistema a partir un archivo de texto, que contiene un diccionario de palabras aceptadas en el idioma inglÃ©s." << endl;
            }
            else if (strcmp(parametro, "iniciar_arbol_inverso")==0){
               cout << endl;

             cout << "Comando iniciar_arbol_inverso: " << endl << endl;
              cout << "Uso correcto: iniciar_arbol_inverso ARCHIVO.TXT" << endl << endl;
              cout << "Descripcion: " << endl;
              cout << "Inicializa el sistema con las palabras en sentido inverso a partir un archivo de texto, que contiene un diccionario de palabras aceptadas en el idioma inglÃ©s." << endl;
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
              cout << "Con las palabras ya almacenadas en el diccionario, el comando construye un grafo de palabras, en donde cada palabra se conecta a las demÃ¡s si y sÃ³lo sÃ­ difieren en un Ãºnica letra" << endl;
            }
            else if (strcmp(parametro, "posibles_palabras")==0){
               cout << endl;

              cout << "Comando posibles_palabras: " << endl << endl;
              cout << "Uso correcto: posibles_palabras LETRAS" << endl << endl;
              cout << "Descripcion: " << endl;
              cout << "Dadas ciertas letras en una cadena de caracteres, presenta en pantalla todas las posibles palabras vÃ¡lidas a construir, indicando la longitud de cada una y la puntuaciÃ³n que se puede obtener con cada una" << endl;
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
    char a, b;
    int c = 0;
    bool valid = false, leido = false;
    string linea;
    ifstream archivo(parametro);
    cout<<"\nLeyendo archivo "<<parametro<<"..." << endl << endl;
    diccJuego.clear();                        
    while(getline(archivo, linea)){
        char* lineaC = new char[strlen(linea.c_str())+1];
        int l = 0;
        strcpy(lineaC, linea.c_str());

        for (int i = 0; i < strlen(linea.c_str()); i++){
            valid = false;
            
            a = 'a';
           
            for (int j = 0; j < 26; j++){
                b = a+j;
                if (b == linea[i] || i == (strlen(linea.c_str())-1)){
                    valid = true;
                }
            }
            if (i == 0){
                a = 'A';
                for (int k = 0; k < 26; k++){
                    b = a+k;
                    if (b == linea[i]){
                        valid = true;
                    }
                }
            }
            
            if (!valid){

                break;
            }
        }
        if (valid == true){
         
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
        cout << "Palabras almacenadas correctamente" << endl;
    }
}

void leerArchivoInv (list <Palabra> &diccInv, Diccionario &diccio, char *parametro){
    char a = 'a', b;
    bool validd, leido = false;
    string linea;
    ifstream archivo(parametro);
    cout<<"\nLeyendo archivo "<<parametro<<"..." << endl << endl;
    diccInv.clear();                        
    while(getline(archivo, linea)){
        char* lineaC = new char[strlen(linea.c_str())+1];
        int l = 0;
        strcpy(lineaC, linea.c_str());
        
        
        for (int i = 0; i < strlen(linea.c_str()-1); i++){
           //if(i < ( strlen(linea.c_str())-1)){
            validd = false;
            a = 'a';
            for (int j = 0; j < 26; j++){
                b = a+j;
                if (b == linea[i] || i == (strlen(linea.c_str())-1)){
                    validd = true;
                }
            }
            if (i == 0){
                a = 'A';
                for (int k = 0; k < 26; k++){
                    b = a+k;
                    if (b == linea[i]){
                        validd = true;
                    }
                }
            }
            
            if (!validd){
                break;
            }
            //}
        }
        if (validd){
            
            
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
        cout << "Palabras almacenadas correctamente" << endl;

    }
}


void buscarPals(list <string> &pals, int pos, char *pal, NodoGeneral<char> *nodo){
   list<NodoGeneral<char>* > auxlis;
   list<NodoGeneral<char>* >::iterator it;
   auxlis = nodo->obtenerDesc();
            for (it = auxlis.begin(); it != auxlis.end(); it++){
              pal[pos] = (*it)->obtenerDato();
              string c;
                c = pal;
              if ((*it)->esHoja()){
                pals.push_back(c);
              }
              else{
                pal = new char[strlen(c.c_str())];
              strcpy(pal, c.c_str());
              buscarPals(pals, pos+1, pal, *it);
              pal = new char[strlen(c.c_str())];
               strcpy(pal, c.c_str());
              }
              }
}


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
     
      
}

