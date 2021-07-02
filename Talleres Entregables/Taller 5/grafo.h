#ifndef GRAFO_H_INCLUDED
#define GRAFO_H_INCLUDED
#include <iostream>
#include <list>

#include <vector>
using namespace std;



///-------------------------------------VERTICE------------------------------------
template<class T>
class Vertice
{
private:
    T dato;
public:
    Vertice()
    {

    }
    Vertice(T dato)
    {
        this->dato=dato;
    }
    T* getDato()
    {
        return &dato;
    }
    void setDato(T dato)
    {
        this->dato=dato;
    }
    bool operator <(Vertice<T>& ver)
    {
        if(dato<ver.dato)
            return true;
        return false;
    }

};
///------------------------------------ARISTA---------------------------------------

template<class T>
class Arista
{
private:
    int peso;
    Vertice<T>* sucesor;
public:
    Arista()
    {

    }
    Arista(Vertice<T>* verDes, int peso)
    {
        this->peso=peso;
        sucesor=verDes;
    }
    void setPeso(int peso)
    {
        this->peso=peso;
    }
    int getPeso()
    {
        return this->peso;
    }
    void setSucesor(Vertice<T>* sucesor)
    {
        this->sucesor=sucesor;
    }
    Vertice<T>* getSucesor()
    {
        return sucesor;
    }
    bool operator <(Arista<T>& ar)
    {
        if(*sucesor<*ar.getSucesor())
            return true;
        return false;
    }
};
///----------------------------------------GRAFO-----------------------------------
template<class T>
class Grafo
{
private:
    list<Vertice<T> > vertices;
    list<list<Arista<T> > > conexiones;
public:
    Grafo()
    {

    }

    list < Vertice<T> > getVertices()
    {
        return this->vertices;
    }
    void setVertices(list<Vertice<T> >vertices)
    {
        this->vertices=vertices;
    }
    void setConexiones (list<list<Arista<T> > > conexiones)
    {
        this->conexiones=conexiones;
    }
    list<list<Arista<T> > > getConexiones()
    {
        return this->conexiones;
    }
    bool esVacio()///VALIDAR SI EL GRAFO ES VACIO
    {
        if(this->vertices.size()==0 && this->conexiones.size()==0)
            return true;
        return false;
    }
    int cantidadVertices()///RETORNA LA CANTIDAD DE VERTICES
    {
        return this->vertices.size();
    }
    int cantidadAristas()///RETORNA LA CANTIDAD DE ARISTAS
    {
        int contador=0;
        typename list<list<Arista<T> > >::iterator it=conexiones.begin();
        for(; it!=conexiones.end(); it++)
        {
            contador+=it->size();
        }
        return contador;
    }
    bool insertarVertice(Vertice<T> vertice)///inserta un vertice dado EL VERTICE
    {
        if(!estaVertice(vertice))
        {
            vertices.push_back(vertice);
            list<Arista<T> > aux;
            conexiones.push_back(aux);
            return true;
        }
        return false;
    }

    bool insertarVertice(T dato)///inserta un vertice dado EL DATO DEL VERTICE
    {
        Vertice<T>* ver=new Vertice<T>(dato);
        if(insertarVertice(*ver))
            return true;
        return false;
    }

    bool estaVertice(Vertice<T> vertice)///valida si existe el vertice DADO EL VERTICE
    {
        typename list<Vertice<T> >::iterator it=vertices.begin();
        for(; it!=vertices.end(); it++)
        {

            if(*vertice.getDato()==*it->getDato())
            {
                return true;
            }
        }
        return false;
    }
    bool estaVertice(T dato)///valida si existe el vertice DADO EL DATO DEL VERTICE
    {
        typename list<Vertice<T> >::iterator it=vertices.begin();
        for(; it!=vertices.end(); it++)
        {
            if(dato==*it->getDato())
            {
                return true;
            }
        }
        return false;
    }
    /*int insertarArista(Vertice<T> ver_o, Vertice<T> ver_d, int peso)///inserta una nueva arista DADOS LOS VERTICES Y EL PESO
    {
        T ver_org=*ver_o.getDato();
        T ver_des=*ver_d.getDato();
        if(!estaVertice(ver_org))
        {
            return 1;
        }
        else if(!estaVertice(ver_des))
        {
            return 2;

        }
        else
        {
            int indice=obtenerIndice(ver_org);
            list<Arista<T> >* conex=obtenerConexionesVertice(indice);
            Vertice<T>* verDes=obtenerApuntadorVertice(ver_des);
            if(!insertarConexion(conex, verDes, peso))
            {
                return 3;
            }
            else
            {
                return 4;
            }
        }
    }*/

    int insertarArista(T ver_org, T ver_des, int peso)///inserta una nueva arista DADOS LOS DATOS DE LOS  VERTICES Y EL PESO
    {
        if(!estaVertice(ver_org))
        {
            return 1;
        }
        else if(!estaVertice(ver_des))
        {
            return 2;
        }
        else
        {
            int indice=obtenerIndice(ver_org);
            list<Arista<T> >* conex=obtenerConexionesVertice(indice);
            Vertice<T>* verDes=buscarVertice(ver_des);
            if(!insertarConexion(conex, verDes, peso))
            {
                return 3;
            }
            else
            {
                return 4;
            }
        }
    }
    list<Arista<T> >* obtenerConexionesVertice(int indice)///RETORNA EL APUNTADOR DE LA LISTA DE ARISTAS(CONEXIONES) DE LA MULTILISTA DE CONEXIONES DADO EL INDICE
    {
        int cont=0;
        typename list<list<Arista<T> > >::iterator it=conexiones.begin();
        for(; it!=conexiones.end(); it++)
        {
            if(cont==indice)
            {
                return &(*it);
            }
            cont++;
        }
        return NULL;
    }
    int obtenerIndice(T ver_org)///RETORNA LA POSICION DEL VERTICE EN LA LISTA DE VERTICES
    {
        typename list<Vertice<T> >::iterator it=vertices.begin();
        int cont=0;
        for(; it!=vertices.end(); it++)
        {
            if(*it->getDato()==ver_org)
            {
                return cont;
            }
            cont++;
        }
        return 0;
    }

    Vertice<T>* buscarVertice(T ver_des)///RETORNA EL APUNTADOR DEL VERTICE DE LA LISTA DE VERTICES DADO EL PARAMETRO
    {
        typename list<Vertice<T> >::iterator it=vertices.begin();
        for(; it!=vertices.end(); it++)
        {
            if(*it->getDato()==ver_des)
            {
                return &(*it);
            }
        }
        return NULL;
    }

    bool insertarConexion(list<Arista<T> >* conex, Vertice<T>* verDes, int peso)///INSERTA LA NUEVA ARISTA(CONEXION) EN LA LISTA PASADA COMO PARAMETRO
    {
        typename list<Arista<T> >::iterator it=conex->begin();
        for(; it!=conex->end(); it++)
        {
            if(it->getSucesor()==verDes)
            {
                return false;
            }
        }
        Arista<T>* aris=new Arista<T>(verDes, peso);
        conex->push_back(*aris);
        conex->sort();
        //------------------------------------------------------------

        return true;
    }

    int eliminarConexionesEnEliminarVertice(list<Arista<T> >* c,T  dato)
    {

        typename list<Arista<T> >::iterator it=c->begin();
        typename list<Arista<T> >::iterator itAux;
        bool encontrado=false;
        for(; it!=c->end(); it++)
        {
            if(*it->getSucesor()->getDato()==dato)
            {
                itAux=it;
                encontrado=true;

            }
        }
        if(encontrado)
        {
            c->erase(itAux);
            return 1;
        }
        else
        {
            return 0;
        }

    }
    
    bool eliminarVertice(T dato)
    {
        cout<<"ban 1"<<endl;
        if(estaVertice(dato))
        {
            int indice=obtenerIndice(dato);
            int cont=0;
            int contAristas=0;
            typename list<list<Arista<T> > >::iterator it2=conexiones.begin();
            typename list<list<Arista<T> > >::iterator itAux;
            for(; it2!=conexiones.end(); it2++)
            {
                if(cont==indice)
                {
                    itAux=it2;
                }
                contAristas+=eliminarConexionesEnEliminarVertice(&(*it2), dato);
                cont++;
            }
            cout<<"Se han eliminado "<<contAristas<<" conexiones con ("<<dato<<") como destino"<<endl;
            conexiones.erase(itAux);
            typename list<Vertice<T> >::iterator it=vertices.begin();
            typename list<Vertice<T> >::iterator itAux2;
            for(; it!=vertices.end(); it++)
            {
                if(*it->getDato()==dato)
                {
                    itAux2=it;

                }
            }
            vertices.erase(itAux2);
            return true;
        }
        else
        {
            return false;
        }



    }
    void imprimiAristas()
    {

        typename list<Vertice<T> >::iterator itVertices=vertices.begin();
        int cont=0;
        for(; itVertices!=vertices.end(); itVertices++)
        {

            list<Arista<T> >* aristasDelVertice=obtenerConexionesVertice(cont);
            typename list<Arista<T> >::iterator itConexiones=aristasDelVertice->begin();
            for(; itConexiones!=aristasDelVertice->end(); itConexiones++)
            {
                cout<<"ver_org: "<<*itVertices->getDato()<<" --  ver_des: "<<*itConexiones->getSucesor()->getDato()<<endl;
            }
            cout<<endl;


            cont++;
        }

    }
    void imprimirVertices()
    {
        typename list< Vertice<T> >:: iterator it = vertices.begin();

        for(; it != vertices.end(); ++it)
        {
            cout<< *it->getDato()<<" - ";
        }
    }

    bool eliminarConexion(list<Arista<T> >* conex, Vertice<T>* verDes)
    {
        typename list<Arista<T> >::iterator it=conex->begin();
        for(; it!=conex->end(); it++)
        {
            if(it->getSucesor()==verDes)
            {
                conex->erase(it);
                return true;
            }
        }
        return false;
    }
    int eliminarArista(T ver_org, T ver_des)
    {
        if(!estaVertice(ver_org))
        {
            return 1;
        }
        else if(!estaVertice(ver_des))
        {
            return 2;
        }
        else
        {
            int indice=obtenerIndice(ver_org);
            list<Arista<T> >* conex=obtenerConexionesVertice(indice);
            Vertice<T>* verDes=buscarVertice(ver_des);
            if(!eliminarConexion(conex, verDes))
            {
                return 3;
            }
            else
            {
                return 4;
            }
        }
    }
    Arista<T>* buscarArista(T ver_org, T ver_des)
    {
        int indice=obtenerIndice(ver_org);
        list<Arista<T> >* conex=obtenerConexionesVertice(indice);
        typename list<Arista<T> >::iterator it=conex->begin();
        for(; it!=conex->end(); it++)
        {
            if(*it->getSucesor()->getDato()==ver_des)
            {
                return &(*it);
            }
        }
        return NULL;
    }
    bool verticeVisitado(list<Vertice<T>* > lista, T dato)
    {
        typename list<Vertice<T>* >::iterator it=lista.begin();
        for(; it!=lista.end(); it++)
        {
            if(*(*it)->getDato()==dato)
            {
                return true;
            }
        }
        return false;
    }
    void busquedaEnProfundidad(T ver_org, list<Vertice<T>* >* lista)
    {
        lista->push_back(buscarVertice(ver_org));
        int indice=obtenerIndice(ver_org);
        list<Arista<T> >* aristas=obtenerConexionesVertice(indice);
        typename list<Arista<T> >::iterator it=aristas->begin();
        for(; it!=aristas->end(); it++)
        {
            if(!verticeVisitado(*lista, *it->getSucesor()->getDato()))
            {
                busquedaEnProfundidad(*it->getSucesor()->getDato(), lista);
            }
        }

    }
    void busquedaEnAnchura(T ver_org, list<Vertice<T>* >* lista)
    {
        /*lista->push_back(buscarVertice(ver_org));
        int indice=obtenerIndice(ver_org);
            list<Arista<T> >* aristas=obtenerConexionesVertice(indice);

        deque<Vertice<T> > cola;
        cola.push(*buscarVertice())*/

    }
    Vertice<T> mindistance(list<Vertice<T> >* todosLosVertices, vector<int> distancias)
    {
        typename list<Vertice<T> >::iterator it=todosLosVertices->begin();
        typename list<Vertice<T> >::iterator itAux=todosLosVertices->begin();
        int menor=999999;
        for(; it!=todosLosVertices->end(); it++)
        {

            int indice=obtenerIndice(*it->getDato());
            if(distancias.at(indice)<menor)
            {

                itAux=it;
                menor=distancias.at(indice);
            }
        }
        todosLosVertices->erase(itAux);
        return (*itAux);
    }
    void recorridoDijkstra(vector<int>* distancias, vector<Vertice<T> >* prede, T dato)
    {
        ///----Inicializar los vectores


        int indice=obtenerIndice(dato);
        distancias->at(indice)=0;
        prede->at(indice)=dato;
        ///----------------------------------
        ///----------S=conjunto de vertices visitados ES LA LISTA QUE SE PASA COMO PAREMETRO(Prede)
        list<Vertice<T> > todosLosVertices(vertices.begin(), vertices.end());///Copia de la lista de vertices para llevar el recuento de los vertices que falta por visitar (Q)

        while(!todosLosVertices.empty())
        {
            Vertice<T> minino=mindistance(&todosLosVertices, *distancias);///Dado Q y dist se obtiene el vertice que tiene la menor distancia

            int indice=obtenerIndice(*minino.getDato());
            list<Arista<T> >* aristas=obtenerConexionesVertice(indice);
            typename list<Arista<T> >::iterator it=aristas->begin();
            for(; it!=aristas->end(); it++)
            {
                int indice2=obtenerIndice(*it->getSucesor()->getDato());
                int posibleMinimo=(distancias->at(indice)+it->getPeso());
                if(distancias->at(indice2)>posibleMinimo)
                {
                    distancias->at(indice2)=posibleMinimo;
                    prede->at(indice2)=minino;
                   // cout << *prede->at(indice2).getDato()<< "es el dato"<<endl;
                    //cout<<"el predecesor "<<*minino.getDato()<<" con ubicacion "<<indice2<<endl;

                }

            }
            //cout<<"tamano de prede "<<prede->size()<<endl;


        }
    }

};

void imprimirPredecesores(vector<Vertice<int> > lista)
{
    typename vector<Vertice<int> >::iterator it=lista.begin();
    for(; it!=lista.end(); it++)
    {
        cout<<*it->getDato()<<" - ";
    }
    cout<<endl<<endl;
}


#endif // GRAFO_H_INCLUDED
