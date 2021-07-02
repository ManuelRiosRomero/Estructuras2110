#include <iostream>
using namespace std;
#include "ArbolAVL.h"
int main() {
  ArbolAVL <int> *a = new ArbolAVL<int>();
  a->insertar(1);
  a->insertar(2);
  a->insertar(3);
 /* a->insertar(4);
  a->eliminar(1);*/
  //a->preOrden();
  a->balanceo (a->obtenerRaiz());
// cout << a->altura();
  cout << endl;
  a->inOrden();
}