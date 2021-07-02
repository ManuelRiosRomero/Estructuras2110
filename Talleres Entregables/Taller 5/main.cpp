#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stack>
#include "grafo.h"
using namespace std;

// -------------------------------------------------------------------------
struct Point
{
  float X, Y, Z;
  float distanceTo( const Point& b ) const
    {
      float x = X - b.X;
      float y = Y - b.Y;
      float z = Z - b.Z;
      return( std::sqrt( ( x * x ) + ( y * y ) + ( z * z ) ) );
    }
    bool operator ==(Point& p) const{
      return ((X == p.X) && (Y == p.Y) && (Z == p.Z));
    }
    bool operator !=(Point& p) const{
      return ((X != p.X) || (Y != p.Y) || (Z != p.Z));
    }
    bool operator <(Point& p) const{
      return ((X < p.X) && (Y < p.Y) && (Z < p.Z));
    }
};

// -------------------------------------------------------------------------

// TODO 1: 
typedef Grafo<Point> *grafo; 

// -------------------------------------------------------------------------
int main( int argc, char* argv[] )
{
  if( argc < 4 )
  {
    std::cerr
      << "Usage: " << argv[ 0 ] << " input_mesh start end"
      << std::endl;
    return( 1 );

  } // fi
  long start_id = std::atoi( argv[ 2 ] );
  long end_id = std::atoi( argv[ 3 ] );

  // TODO 2: 
  grafo g = new Grafo<Point>();

  // Load file in a buffer
  std::ifstream in_mesh_stream( argv[ 1 ], std::ifstream::binary );
  if( !in_mesh_stream )
  {
    std::cerr << "Error reading \"" << argv[ 1 ] << "\"" << std::endl;
    return( 1 );

  } // fi
  in_mesh_stream.seekg( 0, in_mesh_stream.end );
  unsigned long in_mesh_file_length = in_mesh_stream.tellg( );
  in_mesh_stream.seekg( 0, in_mesh_stream.beg );
  char* in_mesh_file_buffer = new char[ in_mesh_file_length ];
  in_mesh_stream.read( in_mesh_file_buffer, in_mesh_file_length );
  in_mesh_stream.close( );
  std::istringstream in_mesh( in_mesh_file_buffer );

  // Read vertices
  long nPoints;
  in_mesh >> nPoints;
  for( long pId = 0; pId < nPoints; pId++ )
  {
    Point pnt;
    in_mesh >> pnt.X >> pnt.Y >> pnt.Z;

    // TODO 3: 
    g->insertarVertice(pnt);

  } // rof

  // Read edges
  long nEdges;
  in_mesh >> nEdges;
   list<Vertice<Point>>::iterator it, it2;
  for( long eId = 0; eId < nEdges; eId++ )
  {
    long start, end;
    in_mesh >> start >> end;

    /*
      TODO 4:
    */
     list<Vertice<Point>> l = g->getVertices();
     it = l.begin();
     it2 = l.begin();
     advance(it, start);
      advance(it2, end);
     float costo = it->getDato()->distanceTo(*it2->getDato());
    
     g->insertarArista(*it->getDato(), *it2->getDato(), costo);
     g->insertarArista(*it2->getDato(), *it->getDato(), costo);
  } // rof
  delete [] in_mesh_file_buffer;
list<Vertice<Point>> vertices = g->getVertices();
  if(
    start_id < 0 || start_id >= vertices.size( ) ||
    end_id < 0 || end_id >= vertices.size( )
    )
  {
    std::cerr << "Invalid path endpoints." << std::endl;
    return( 1 );

  } // fi

  /*
    TODO 5:
  */
  
it = vertices.begin();
  advance(it, start_id);
it2 = vertices.begin();
  advance(it2, end_id);
  vector<int>* distancias;
  vector<Vertice<Point>>* prede;
  int tamanoGrafo=g->getConexiones().size();
  distancias=new vector<int>(tamanoGrafo, 999999);
  prede=new vector<Vertice<Point> >(tamanoGrafo);
  g->recorridoDijkstra(distancias, prede, *it->getDato());
  vector<Vertice<Point> >::iterator it3 = prede->begin();
  int conta = 0, ind = -1;
  advance(it3, end_id);

  stack<Point> pila;
  pila.push(*it2->getDato());
  while ( *it3->getDato() != *it->getDato()){
    ind = g->obtenerIndice(*it3->getDato());
    pila.push(*it3->getDato());
    it3 = prede->begin();
    advance(it3, ind);
    conta++;
  }
  conta+=2;
  pila.push(*it->getDato());
  cout << "Cantidad de puntos ruta costo minimo: " << conta << endl << endl;
  cout << "Puntos ruta costo minimo: " << endl << endl;
  Point aux;
  while (!pila.empty()){
    aux = pila.top();
    cout << "(" << aux.X << ", " << aux.Y << ", " << aux.Z << ")" << endl;
    pila.pop();
  }


  return( 0 );
}

// eof -