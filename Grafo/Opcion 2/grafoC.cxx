#include <iostream>
#include "Graph.h"
using namespace std;
int main()
{
    Graph<int> grafo(1);
    grafo.agregarArista(1, 2);
    grafo.agregarArista(1, 6);
    grafo.agregarArista(2, 3);
    grafo.agregarArista(2, 4);
    grafo.agregarArista(3, 4);
    grafo.agregarArista(5, 4);
    grafo.agregarArista(6, 5);
    cout<<grafo.cantidadCamposConectados();
}