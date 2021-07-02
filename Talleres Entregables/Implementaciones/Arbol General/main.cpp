#include <iostream>
#include "ArbolGeneral.h"

//g++ -std=c++11 main.cpp -o main.exe

int main()
{
    //iniciar el arbol
    int padre = 10;
    bool ok;
    ArbolGeneral<int> arbol(padre);
    //-------------ingresar datos-----------
    //segundo nivel
    int hijo = 5;
    ok = arbol.insertarNodo(padre, hijo);
    hijo = 15;
    ok = arbol.insertarNodo(padre, hijo);
    hijo = 30;
    ok = arbol.insertarNodo(padre, hijo);

    //hijos de nodo 5
    padre = 5;
    hijo = 2;
    ok = arbol.insertarNodo(padre, hijo);
    hijo = 3;
    ok = arbol.insertarNodo(padre, hijo);

    //hijos del 2
    padre = 2;
    hijo = 1;
    ok = arbol.insertarNodo(padre, hijo);

    //hijos de 15
    padre = 15;
    hijo = 25;
    ok = arbol.insertarNodo(padre, hijo);
    //hijo de 25
    padre = 25;
    hijo = 50;
    ok = arbol.insertarNodo(padre, hijo);

    //hijos de 30
    padre = 30;
    hijo = 35;
    ok = arbol.insertarNodo(padre, hijo);
    hijo = 40;
    ok = arbol.insertarNodo(padre, hijo);

    //hijos del 35
    padre = 35;
    hijo = 36;
    ok = arbol.insertarNodo(padre, hijo);
    hijo = 37;
    ok = arbol.insertarNodo(padre, hijo);

    //hijos del 40
    padre = 40;
    hijo = 42;
    ok = arbol.insertarNodo(padre, hijo);
    hijo = 43;
    ok = arbol.insertarNodo(padre, hijo);
     ok = arbol.insertarNodo(padre, hijo);
    hijo = 15;
    ok = arbol.insertarNodo(padre, hijo);
    hijo = 30;
    ok = arbol.insertarNodo(padre, hijo);

    //hijos de nodo 5
    padre = 5;
    hijo = 2;
    ok = arbol.insertarNodo(padre, hijo);
    hijo = 3;
    ok = arbol.insertarNodo(padre, hijo);

    //hijos del 2
    padre = 2;
    hijo = 1;
    ok = arbol.insertarNodo(padre, hijo);

    //hijos de 15
    padre = 15;
    hijo = 25;
    ok = arbol.insertarNodo(padre, hijo);
    //hijo de 25
    padre = 25;
    hijo = 50;
    ok = arbol.insertarNodo(padre, hijo);

    //hijos de 30
    padre = 30;
    hijo = 35;
    ok = arbol.insertarNodo(padre, hijo);
    hijo = 40;
    ok = arbol.insertarNodo(padre, hijo);

    //hijos del 35
    padre = 35;
    hijo = 36;
    ok = arbol.insertarNodo(padre, hijo);
    hijo = 37;
    ok = arbol.insertarNodo(padre, hijo);

    //hijos del 40
    padre = 40;
    hijo = 42;
    ok = arbol.insertarNodo(padre, hijo);
    hijo = 43;
    ok = arbol.insertarNodo(padre, hijo);
     ok = arbol.insertarNodo(padre, hijo);
    hijo = 15;
    ok = arbol.insertarNodo(padre, hijo);
    hijo = 30;
    ok = arbol.insertarNodo(padre, hijo);

    //hijos de nodo 5
    padre = 5;
    hijo = 2;
    ok = arbol.insertarNodo(padre, hijo);
    hijo = 3;
    ok = arbol.insertarNodo(padre, hijo);

    //hijos del 2
    padre = 2;
    hijo = 1;
    ok = arbol.insertarNodo(padre, hijo);

    //hijos de 15
    padre = 15;
    hijo = 25;
    ok = arbol.insertarNodo(padre, hijo);
    //hijo de 25
    padre = 25;
    hijo = 50;
    ok = arbol.insertarNodo(padre, hijo);

    //hijos de 30
    padre = 30;
    hijo = 35;
    ok = arbol.insertarNodo(padre, hijo);
    hijo = 40;
    ok = arbol.insertarNodo(padre, hijo);

    //hijos del 35
    padre = 35;
    hijo = 36;
    ok = arbol.insertarNodo(padre, hijo);
    hijo = 37;
    ok = arbol.insertarNodo(padre, hijo);

    //hijos del 40
    padre = 40;
    hijo = 42;
    ok = arbol.insertarNodo(padre, hijo);
    hijo = 43;
    ok = arbol.insertarNodo(padre, hijo);
     ok = arbol.insertarNodo(padre, hijo);
    hijo = 15;
    ok = arbol.insertarNodo(padre, hijo);
    hijo = 30;
    ok = arbol.insertarNodo(padre, hijo);

    //hijos de nodo 5
    padre = 5;
    hijo = 2;
    ok = arbol.insertarNodo(padre, hijo);
    hijo = 3;
    ok = arbol.insertarNodo(padre, hijo);

    //hijos del 2
    padre = 2;
    hijo = 1;
    ok = arbol.insertarNodo(padre, hijo);

    //hijos de 15
    padre = 15;
    hijo = 25;
    ok = arbol.insertarNodo(padre, hijo);
    //hijo de 25
    padre = 25;
    hijo = 50;
    ok = arbol.insertarNodo(padre, hijo);

    //hijos de 30
    padre = 30;
    hijo = 35;
    ok = arbol.insertarNodo(padre, hijo);
    hijo = 40;
    ok = arbol.insertarNodo(padre, hijo);

    //hijos del 35
    padre = 35;
    hijo = 36;
    ok = arbol.insertarNodo(padre, hijo);
    hijo = 37;
    ok = arbol.insertarNodo(padre, hijo);

    //hijos del 40
    padre = 40;
    hijo = 42;
    ok = arbol.insertarNodo(padre, hijo);
    hijo = 43;
    ok = arbol.insertarNodo(padre, hijo);
     ok = arbol.insertarNodo(padre, hijo);
    hijo = 15;
    ok = arbol.insertarNodo(padre, hijo);
    hijo = 30;
    ok = arbol.insertarNodo(padre, hijo);

    //hijos de nodo 5
    padre = 5;
    hijo = 2;
    ok = arbol.insertarNodo(padre, hijo);
    hijo = 3;
    ok = arbol.insertarNodo(padre, hijo);

    //hijos del 2
    padre = 2;
    hijo = 1;
    ok = arbol.insertarNodo(padre, hijo);

    //hijos de 15
    padre = 15;
    hijo = 25;
    ok = arbol.insertarNodo(padre, hijo);
    //hijo de 25
    padre = 25;
    hijo = 50;
    ok = arbol.insertarNodo(padre, hijo);

    //hijos de 30
    padre = 30;
    hijo = 35;
    ok = arbol.insertarNodo(padre, hijo);
    hijo = 40;
    ok = arbol.insertarNodo(padre, hijo);

    //hijos del 35
    padre = 35;
    hijo = 36;
    ok = arbol.insertarNodo(padre, hijo);
    hijo = 37;
    ok = arbol.insertarNodo(padre, hijo);

    //hijos del 40
    padre = 40;
    hijo = 42;
    ok = arbol.insertarNodo(padre, hijo);
    hijo = 43;
    ok = arbol.insertarNodo(padre, hijo);
     ok = arbol.insertarNodo(padre, hijo);
    hijo = 15;
    ok = arbol.insertarNodo(padre, hijo);
    hijo = 30;
    ok = arbol.insertarNodo(padre, hijo);

    //hijos de nodo 5
    padre = 5;
    hijo = 2;
    ok = arbol.insertarNodo(padre, hijo);
    hijo = 3;
    ok = arbol.insertarNodo(padre, hijo);

    //hijos del 2
    padre = 2;
    hijo = 1;
    ok = arbol.insertarNodo(padre, hijo);

    //hijos de 15
    padre = 15;
    hijo = 25;
    ok = arbol.insertarNodo(padre, hijo);
    //hijo de 25
    padre = 25;
    hijo = 50;
    ok = arbol.insertarNodo(padre, hijo);

    //hijos de 30
    padre = 30;
    hijo = 35;
    ok = arbol.insertarNodo(padre, hijo);
    hijo = 40;
    ok = arbol.insertarNodo(padre, hijo);

    //hijos del 35
    padre = 35;
    hijo = 36;
    ok = arbol.insertarNodo(padre, hijo);
    hijo = 37;
    ok = arbol.insertarNodo(padre, hijo);

    //hijos del 40
    padre = 40;
    hijo = 42;
    ok = arbol.insertarNodo(padre, hijo);
    hijo = 43;
    ok = arbol.insertarNodo(padre, hijo);
     ok = arbol.insertarNodo(padre, hijo);
    hijo = 15;
    ok = arbol.insertarNodo(padre, hijo);
    hijo = 30;
    ok = arbol.insertarNodo(padre, hijo);

    //hijos de nodo 5
    padre = 5;
    hijo = 2;
    ok = arbol.insertarNodo(padre, hijo);
    hijo = 3;
    ok = arbol.insertarNodo(padre, hijo);

    //hijos del 2
    padre = 2;
    hijo = 1;
    ok = arbol.insertarNodo(padre, hijo);

    //hijos de 15
    padre = 15;
    hijo = 25;
    ok = arbol.insertarNodo(padre, hijo);
    //hijo de 25
    padre = 25;
    hijo = 50;
    ok = arbol.insertarNodo(padre, hijo);

    //hijos de 30
    padre = 30;
    hijo = 35;
    ok = arbol.insertarNodo(padre, hijo);
    hijo = 40;
    ok = arbol.insertarNodo(padre, hijo);

    //hijos del 35
    padre = 35;
    hijo = 36;
    ok = arbol.insertarNodo(padre, hijo);
    hijo = 37;
    ok = arbol.insertarNodo(padre, hijo);

    //hijos del 40
    padre = 40;
    hijo = 42;
    ok = arbol.insertarNodo(padre, hijo);
    hijo = 43;
    ok = arbol.insertarNodo(padre, hijo);
     ok = arbol.insertarNodo(padre, hijo);
    hijo = 15;
    ok = arbol.insertarNodo(padre, hijo);
    hijo = 30;
    ok = arbol.insertarNodo(padre, hijo);

    //hijos de nodo 5
    padre = 5;
    hijo = 2;
    ok = arbol.insertarNodo(padre, hijo);
    hijo = 3;
    ok = arbol.insertarNodo(padre, hijo);

    //hijos del 2
    padre = 2;
    hijo = 1;
    ok = arbol.insertarNodo(padre, hijo);

    //hijos de 15
    padre = 15;
    hijo = 25;
    ok = arbol.insertarNodo(padre, hijo);
    //hijo de 25
    padre = 25;
    hijo = 50;
    ok = arbol.insertarNodo(padre, hijo);

    //hijos de 30
    padre = 30;
    hijo = 35;
    ok = arbol.insertarNodo(padre, hijo);
    hijo = 40;
    ok = arbol.insertarNodo(padre, hijo);

    //hijos del 35
    padre = 35;
    hijo = 36;
    ok = arbol.insertarNodo(padre, hijo);
    hijo = 37;
    ok = arbol.insertarNodo(padre, hijo);

    //hijos del 40
    padre = 40;
    hijo = 42;
    ok = arbol.insertarNodo(padre, hijo);
    hijo = 43;
    ok = arbol.insertarNodo(padre, hijo);
     ok = arbol.insertarNodo(padre, hijo);
    hijo = 15;
    ok = arbol.insertarNodo(padre, hijo);
    hijo = 30;
    ok = arbol.insertarNodo(padre, hijo);

    //hijos de nodo 5
    padre = 5;
    hijo = 2;
    ok = arbol.insertarNodo(padre, hijo);
    hijo = 3;
    ok = arbol.insertarNodo(padre, hijo);

    //hijos del 2
    padre = 2;
    hijo = 1;
    ok = arbol.insertarNodo(padre, hijo);

    //hijos de 15
    padre = 15;
    hijo = 25;
    ok = arbol.insertarNodo(padre, hijo);
    //hijo de 25
    padre = 25;
    hijo = 50;
    ok = arbol.insertarNodo(padre, hijo);

    //hijos de 30
    padre = 30;
    hijo = 35;
    ok = arbol.insertarNodo(padre, hijo);
    hijo = 40;
    ok = arbol.insertarNodo(padre, hijo);

    //hijos del 35
    padre = 35;
    hijo = 36;
    ok = arbol.insertarNodo(padre, hijo);
    hijo = 37;
    ok = arbol.insertarNodo(padre, hijo);

    //hijos del 40
    padre = 40;
    hijo = 42;
    ok = arbol.insertarNodo(padre, hijo);
    hijo = 43;
    ok = arbol.insertarNodo(padre, hijo);
    
     ok = arbol.insertarNodo(padre, hijo);
    hijo = 15;
    ok = arbol.insertarNodo(padre, hijo);
    hijo = 30;
    ok = arbol.insertarNodo(padre, hijo);

    //hijos de nodo 5
    padre = 5;
    hijo = 2;
    ok = arbol.insertarNodo(padre, hijo);
    hijo = 3;
    ok = arbol.insertarNodo(padre, hijo);

    //hijos del 2
    padre = 2;
    hijo = 1;
    ok = arbol.insertarNodo(padre, hijo);

    //hijos de 15
    padre = 15;
    hijo = 25;
    ok = arbol.insertarNodo(padre, hijo);
    //hijo de 25
    padre = 25;
    hijo = 50;
    ok = arbol.insertarNodo(padre, hijo);

    //hijos de 30
    padre = 30;
    hijo = 35;
    ok = arbol.insertarNodo(padre, hijo);
    hijo = 40;
    ok = arbol.insertarNodo(padre, hijo);

    //hijos del 35
    padre = 35;
    hijo = 36;
    ok = arbol.insertarNodo(padre, hijo);
    hijo = 37;
    ok = arbol.insertarNodo(padre, hijo);

    //hijos del 40
    padre = 40;
    hijo = 42;
    ok = arbol.insertarNodo(padre, hijo);
    hijo = 43;
    ok = arbol.insertarNodo(padre, hijo);
     ok = arbol.insertarNodo(padre, hijo);
    hijo = 15;
    ok = arbol.insertarNodo(padre, hijo);
    hijo = 30;
    ok = arbol.insertarNodo(padre, hijo);

    //hijos de nodo 5
    padre = 5;
    hijo = 2;
    ok = arbol.insertarNodo(padre, hijo);
    hijo = 3;
    ok = arbol.insertarNodo(padre, hijo);

    //hijos del 2
    padre = 2;
    hijo = 1;
    ok = arbol.insertarNodo(padre, hijo);

    //hijos de 15
    padre = 15;
    hijo = 25;
    ok = arbol.insertarNodo(padre, hijo);
    //hijo de 25
    padre = 25;
    hijo = 50;
    ok = arbol.insertarNodo(padre, hijo);

    //hijos de 30
    padre = 30;
    hijo = 35;
    ok = arbol.insertarNodo(padre, hijo);
    hijo = 40;
    ok = arbol.insertarNodo(padre, hijo);

    //hijos del 35
    padre = 35;
    hijo = 36;
    ok = arbol.insertarNodo(padre, hijo);
    hijo = 37;
    ok = arbol.insertarNodo(padre, hijo);

    //hijos del 40
    padre = 40;
    hijo = 42;
    ok = arbol.insertarNodo(padre, hijo);
    hijo = 43;
    ok = arbol.insertarNodo(padre, hijo);
     ok = arbol.insertarNodo(padre, hijo);
    hijo = 15;
    ok = arbol.insertarNodo(padre, hijo);
    hijo = 30;
    ok = arbol.insertarNodo(padre, hijo);

    //hijos de nodo 5
    padre = 5;
    hijo = 2;
    ok = arbol.insertarNodo(padre, hijo);
    hijo = 3;
    ok = arbol.insertarNodo(padre, hijo);

    //hijos del 2
    padre = 2;
    hijo = 1;
    ok = arbol.insertarNodo(padre, hijo);

    //hijos de 15
    padre = 15;
    hijo = 25;
    ok = arbol.insertarNodo(padre, hijo);
    //hijo de 25
    padre = 25;
    hijo = 50;
    ok = arbol.insertarNodo(padre, hijo);

    //hijos de 30
    padre = 30;
    hijo = 35;
    ok = arbol.insertarNodo(padre, hijo);
    hijo = 40;
    ok = arbol.insertarNodo(padre, hijo);

    //hijos del 35
    padre = 35;
    hijo = 36;
    ok = arbol.insertarNodo(padre, hijo);
    hijo = 37;
    ok = arbol.insertarNodo(padre, hijo);

    //hijos del 40
    padre = 40;
    hijo = 42;
    ok = arbol.insertarNodo(padre, hijo);
    hijo = 43;
    ok = arbol.insertarNodo(padre, hijo);
     ok = arbol.insertarNodo(padre, hijo);
    hijo = 15;
    ok = arbol.insertarNodo(padre, hijo);
    hijo = 30;
    ok = arbol.insertarNodo(padre, hijo);

    //hijos de nodo 5
    padre = 5;
    hijo = 2;
    ok = arbol.insertarNodo(padre, hijo);
    hijo = 3;
    ok = arbol.insertarNodo(padre, hijo);

    //hijos del 2
    padre = 2;
    hijo = 1;
    ok = arbol.insertarNodo(padre, hijo);

    //hijos de 15
    padre = 15;
    hijo = 25;
    ok = arbol.insertarNodo(padre, hijo);
    //hijo de 25
    padre = 25;
    hijo = 50;
    ok = arbol.insertarNodo(padre, hijo);

    //hijos de 30
    padre = 30;
    hijo = 35;
    ok = arbol.insertarNodo(padre, hijo);
    hijo = 40;
    ok = arbol.insertarNodo(padre, hijo);

    //hijos del 35
    padre = 35;
    hijo = 36;
    ok = arbol.insertarNodo(padre, hijo);
    hijo = 37;
    ok = arbol.insertarNodo(padre, hijo);

    //hijos del 40
    padre = 40;
    hijo = 42;
    ok = arbol.insertarNodo(padre, hijo);
    hijo = 43;
    ok = arbol.insertarNodo(padre, hijo);
    //---------------------recorridos---------------------

    //recorridos PreOrden
    std::cout << "\n Pre Orden: \n";
    cout << arbol.tamano() << endl;
    arbol.preOrder();

    //recorrido por niveles
    std::cout << "\n Por Niveles: \n";
    arbol.nivelOrden();
}