#include <iostream>
#include <string.h>

//g++ -std=c++11 main.cpp -o main
// ./main

using namespace std;
int main( int argc, char* argv[] ){
    char *comando = new char[40];
    bool bandera = true;

    while (bandera){
       
        cout<<"\n\n----------SCRABBLE----------";
        cout<<"\n-----Lista de Comandos------";
        cout<<"\n1. inicializar diccionario.txt";
        cout<<"\n2. inciar_inverso diccionario.txt";
        cout<<"\n3. puntaje palabra";
        cout<<"\n";
        cout<<"\n ---/---/---/---/---/---/---";
        cout<<"\n4. inciar_arbol diccionario.txt";
        cout<<"\n5. inciar_arbol_inverso diccionario.txt";
        cout<<"\n6. palabras_por_prefijo prefijo";
        cout<<"\n7. palabras_por_sufijo sufijo";
        cout<<"\n";
        cout<<"\n ---/---/---/---/---/---/---";
        cout<<"\n8. grafo_de_palabras";
        cout<<"\n9. posibles_palabras letras";
        cout<<"\n0. salir";
        cout<<"\n#. ayuda";
        cout<<"\n-----------------------------\n";
        //lectura del comando
        cout<< "\n$: ";
        cin.getline(comando, 40);
        
        //cout<<comando;
        
        //-----------comando 1 incializar diccionario
        if(strcmp(comando, "inicializar diccionario.txt")== 0){
            cout<<"\nSe entro al comando 1";
        }
        
        //-----------comando 2 incia inverso diccionario
        else if(strcmp(comando,"inciar_inverso diccionario.txt")== 0){
            cout<<"\nSe entro al comando 2";
        }

        //-----------comando 3 puntaje de palabra
        else if(strcmp(comando, "puntaje palabra")== 0){
            cout<<"\nSe entro al comando 3";
        }

        //-----------comando 4 entrega 2 inciiar arbol
        else if(strcmp(comando,"inciar_arbol diccionario.txt")== 0){
            cout<<"\nSe entro al comando 4";
        }

        //-----------comando 5 entrega 2 arbol inverso
        else if(strcmp(comando, "inciar_arbol_inverso diccionario.txt")== 0){
            cout<<"\nSe entro al comando 5";
        }

        //-----------comando 6 entrega 2 palabras prefijo
        else if(strcmp(comando,"palabras_por_prefijo prefijo")== 0){
            cout<<"\nSe entro al comando 6";
        }

        //-----------comando 7 entrega 2 palabras sufijo
        else if(strcmp(comando, "palabras_por_sufijo sufijo")== 0){
            cout<<"\nSe entro al comando 7";
        }

        //-----------comando 8 entrega 3 grafo de palabras
        else if(strcmp(comando,"grafo_de_palabras")== 0){
            cout<<"\nSe entro al comando 8";
        }

        //-----------comando 9 entrega 3 posibles palabras letras
        else if(strcmp(comando, "posibles_palabras letras")== 0){
            cout<<"\nSe entro al comando 9";
        }

        //-----------comando de ayuda
        else if(strcmp(comando, "ayuda")== 0){
            cout<<"\nSe entro al comando de ayuda";
        }

        //-----------Salir del ciclo
        else if(strcmp(comando, "salir") == 0){
            bandera = false;
        }
        else{
            cout<<"\nComando no identificado...";
        }
        cout<<"\n\n";
        cin.get();
    }

}