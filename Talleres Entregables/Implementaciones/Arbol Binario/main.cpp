#include <iostream>
#include "ArbolBinarioOrd.h"
#include "ArbolBinarioOrd.hxx"
#include "NodoBinario.h"
using namespace std;
int main() {
  ArbolBinarioOrd <int>*a = new ArbolBinarioOrd<int>();
a->insertar(6);
a->insertar(7);
a->insertar(2);
a->insertar(1);
a->insertar(4);
a->insertar(9);
a->insertar(8);
a->insertar(3);
a->insertar(5);
a->insertar(10);

cout<<"\n Pre orden:";
a->preOrden();
cout << endl;
cout<<"\n In orden:";
a->inOrden();
cout << endl;
cout<<"\n Pos orden:";
a->posOrden();
cout << endl;
cout<<"\n Nivel orden:";
a->nivelOrden();
cout << endl;
cout << a->altura() << endl;
if (a->eliminar(6)){
  cout << endl;
a->inOrden();
}
else{
  cout << "El numero a eliminar no existe" << endl;
}
cout << endl << a->tamano() << endl;


}