#include <iostream>
/*
    Por Manuel Alejandro Rios Romero
*/

//--librerias necesarias para usar los contenedores--
#include <vector>
#include <deque>
#include <list>

//--generar numeros aleatorios
#include <ctime>
#include <cstdlib>

//g++ -std=c++11 main.cpp -o main
// ./main

// -------------------------------------------------------------------------
int main( int argc, char* argv[] )
{
    // numeros aleatorios
    int  max=50;
        srand(time(0));
        
        

    /*
    1. Declarar un Vector, Deque y List
    2. rellenar cada uno con:
        Vector, 25 datos aleatorios insertados por el final
        deque y list, 30 datos aleatorios (cada uno) insertados por ambos extremos
            15 al inicio y 15 al final intercalados
    3. Recorrer e Imprimir cada contenedor en orden (con iterador normal) y en orden
        inverso (con iterador reverso)
    4. En cada contenedor insertar un nuevo valor aleatorio en la posicion 18, eliminar
        los valores ubicados en las posiciones 5 y 10, y re imprimir en orden normal
    */
      

    
   //-------Declaraciones
   std::vector <int> miVector;
   std::deque<int> miDeque;
   std::list<int> miLista;


   //-------Llenar cada contenedor
    //vector
   for(int i=0 ; i<25 ; i++){
       miVector.push_back((rand () % max) +1);
   }
    //deque
   for(int i=0; i<15; i++){
       miDeque.push_front((rand () % max) +1);
       miDeque.push_back((rand () % max) +1);
   }
    //list
    for(int i=0; i<15; i++){
        miLista.push_front((rand () % max) +1);
        miLista.push_back((rand () % max) +1);
    }


    //-------Imprimir los contenedores
    //iteradores normales
    std::vector<int>::iterator vIt;
    std::deque<int>::iterator dIt;
    std::list<int>::iterator lIt;

    //iteradores inversos
    std::vector<int>::reverse_iterator rvit;
    std::deque<int>::reverse_iterator rdit;
    std::list<int>::reverse_iterator rlit;
    
    //Impresion normal
    std::cout<<"\n ----Impresion con iterador normal: ";
    std::cout<<"\n Vector: ";
    for(vIt = miVector.begin(); vIt!= miVector.end(); vIt++){
        std::cout<< *vIt <<", ";
    }
    std::cout<<"\n";

    std::cout<<"\n Deque: ";
    for(dIt=miDeque.begin(); dIt!=miDeque.end(); dIt++){
        std::cout<< *dIt <<", ";
    }
    std::cout<<"\n";

    std::cout<<"\n Lista: ";
    for(lIt=miLista.begin(); lIt!=miLista.end(); lIt++){
        std::cout<< *lIt << ", ";
    }
    
    //impresion inversa
    std::cout<<"\n";
    std::cout<<"\n ----Impresion con iterador inverso: ";
    std::cout<<"\n Vector: ";
    for(rvit=miVector.rbegin(); rvit!=miVector.rend(); rvit++){
        std::cout<< *rvit<<", ";
    }
    std::cout<<"\n";

    std::cout<<"\n Deque: ";
    for(rdit=miDeque.rbegin(); rdit!=miDeque.rend(); rdit++){
        std::cout<< *rdit <<", ";
    }
    std::cout<<"\n";

    std::cout<<"\n Lista:";
    for(rlit=miLista.rbegin(); rlit!=miLista.rend(); rlit++){
        std::cout<< *rlit <<", ";
    }
    std::cout<<"\n";

    //----insertar nuevos valores, borrar e re imprimir
    
    //modificar posicion 18
    miVector.erase(miVector.begin()+17);
    miVector.insert(miVector.begin()+17, (rand () % max) +1);

    miDeque.erase(miDeque.begin()+17);
    miDeque.insert(miDeque.begin()+17, (rand () % max) +1);
    
    std::list<int>::iterator it2;
    it2 = miLista.begin();
    advance(it2,17);
    miLista.erase(it2);
    it2 = miLista.begin();
    advance(it2,17);
    miLista.insert(it2, (rand () % max) +1);

    //vector eliminar 5 y 10
    miVector.erase(miVector.begin()+4);
    miVector.erase(miVector.begin()+9);
    //deque eliminar 5 y 10
    miDeque.erase(miDeque.begin()+4);
    miDeque.erase(miDeque.begin()+9);
    //list eliminar 5 y 10
    it2 = miLista.begin();
    advance(it2,4);
    miLista.erase(it2);
    it2 = miLista.begin();
    advance(it2,9);
    miLista.erase(it2);
    

    //Re imprimir
    std::cout<<"\n ----Re Impresion Normal despues de Borrar e Insertar: ";
    std::cout<<"\n Vector Re Impresion: ";
    for(vIt = miVector.begin(); vIt!= miVector.end(); vIt++){
        std::cout<< *vIt <<", ";
    }
    std::cout<<"\n";

    std::cout<<"\n Deque Re Impresion: ";
    for(dIt=miDeque.begin(); dIt!=miDeque.end(); dIt++){
        std::cout<< *dIt <<", ";
    }
    std::cout<<"\n";

    std::cout<<"\n Lista Re Impresion: ";
    for(lIt=miLista.begin(); lIt!=miLista.end(); lIt++){
        std::cout<< *lIt << ", ";
    }
    std::cout<<"\n";
    
  return( 0 );
}