#include <iostream>
#include <string.h>

//g++ -std=c++11 main.cpp -o main
// ./main

using namespace std;
int main( int argc, char* argv[] ){
    char *comando = new char[40], *parametro, *instruccion;
    bool bandera = true;

    while (bandera){
       
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
        cout<<"\n7. palabras_por_sufijo SUFIJO";
        cout<<"\n";
        cout<<"\n ---/---/---/---/---/---/---";
        cout<<"\n8. grafo_de_palabras";
        cout<<"\n9. posibles_palabras LETRAS";
        cout<<"\n0. salir";
        cout<<"\n#. ayuda";
        cout<<"\n-----------------------------\n";
        //lectura del comando
        cout<< "\n$: ";
        cin.getline(comando, 40);
        
           instruccion = strtok(comando, " ");
           
        //cout<<comando;
     
        //-----------comando 1 incializar diccionario
        if(strcmp(instruccion, "inicializar")== 0){
        	parametro = strtok(NULL, " ");
        	cout << "Parametro: " << parametro << endl;
            cout<<"\nSe entro al comando 1";
        }
        
        //-----------comando 2 incia inverso diccionario
        else if(strcmp(instruccion,"iniciar_inverso")== 0){
        	parametro = strtok(NULL, " ");
        	cout << "Parametro: " << parametro << endl;
            cout<<"\nSe entro al comando 2";
        }

        //-----------comando 3 puntaje de palabra
        else if(strcmp(instruccion, "puntaje")== 0){
        	parametro = strtok(NULL, " ");
        	cout << "Parametro: " << parametro << endl;
            cout<<"\nSe entro al comando 3";
        }

        //-----------comando 4 entrega 2 inciiar arbol
        else if(strcmp(instruccion,"iniciar_arbol")== 0){
        	parametro = strtok(NULL, " ");
        	cout << "Parametro: " << parametro << endl;
            cout<<"\nSe entro al comando 4";
        }

        //-----------comando 5 entrega 2 arbol inverso
        else if(strcmp(instruccion, "iniciar_arbol_inverso")== 0){
        	parametro = strtok(NULL, " ");
        	cout << "Parametro: " << parametro << endl;
            cout<<"\nSe entro al comando 5";
        }

        //-----------comando 6 entrega 2 palabras prefijo
        else if(strcmp(instruccion,"palabras_por_prefijo")== 0){
        	parametro = strtok(NULL, " ");
        	cout << "Parametro: " << parametro << endl;
            cout<<"\nSe entro al comando 6";
        }

        //-----------comando 7 entrega 2 palabras sufijo
        else if(strcmp(instruccion, "palabras_por_sufijo")== 0){
        	parametro = strtok(NULL, " ");
        	cout << "Parametro: " << parametro << endl;
            cout<<"\nSe entro al comando 7";
        }

        //-----------comando 8 entrega 3 grafo de palabras
        else if(strcmp(instruccion,"grafo_de_palabras")== 0){
            cout<<"\nSe entro al comando 8";
        }

        //-----------comando 9 entrega 3 posibles palabras letras
        else if(strcmp(instruccion, "posibles_palabras")== 0){
        	parametro = strtok(NULL, " ");
        	cout << "Parametro: " << parametro << endl;
            cout<<"\nSe entro al comando 9";
        }

        //-----------comando de ayuda
        else if(strcmp(instruccion, "ayuda")== 0){
            cout<<"\nSe entro al comando de ayuda";
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

}
