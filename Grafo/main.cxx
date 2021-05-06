#include <iostream>
#include "Graph.h"
using namespace std;
int main()
{
    cout << "Bienvenido\n\n";
    Graph<int> myGraph;
    myGraph.agregarArista(2, 3);
    myGraph.agregarArista(2, 3);
    myGraph.agregarArista(2, 4, 0, 1);
    myGraph.agregarArista(2, 4, 3);
    cout << myGraph.printGraph();
    cout << "Tratando de agregar 5(BIEN)" << myGraph.agregarVertice(5) << '\n';
    cout << "Tratando de agregar 2(MAL)" << myGraph.agregarVertice(2) << '\n';
    cout << "Tratando de buscar arista de 2 a 4 (BIEN): " << myGraph.buscarArista(2, 4) << '\n';
    cout << "Tratando de buscar arista de 2 a 1 (MAL): " << myGraph.buscarArista(2, 1) << '\n';
    cout << "Tratando de buscar vertice 2 (BIEN): " << myGraph.buscarVertice(2) << '\n';
    cout << "Tratando de buscar vertice 10 (MAL): " << myGraph.buscarVertice(10) << '\n';
    cout << myGraph.printGraph();
    cout << "Aristas: " << myGraph.cantidadAristas() << '\n';
    cout << "Vertices: " << myGraph.cantidadVertices() << '\n'
         << '\n';
    cout << "Tratando de eliminar arista de 2 a 4 (BIEN): " << myGraph.eliminarArista(2, 4) << '\n';
    cout << myGraph.printGraph();
    cout << "Tratando de eliminar arista de 10 a 2 (MAL): " << myGraph.eliminarArista(10, 2) << '\n';
    cout << "Tratando de eliminar vertice 2 (BIEN): " << myGraph.eliminarVertice(2) << '\n';
    cout << "Tratando de eliminar vertice 10 (MAL): " << myGraph.eliminarVertice(10) << '\n';
    cout << myGraph.printGraph() << '\n';
    //New
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    Graph<int, char> myGraph2;
    myGraph2.agregarArista(1, 5, 0);
    myGraph2.agregarArista(1, 9, 0);
    myGraph2.agregarArista(2, 4, 0);
    myGraph2.agregarArista(2, 7, 0);
    myGraph2.agregarArista(3, 1, 0);
    myGraph2.agregarArista(3, 9, 0);
    myGraph2.agregarArista(4, 8, 0);
    myGraph2.agregarArista(4, 5, 0);
    myGraph2.agregarArista(4, 7, 0);
    myGraph2.agregarArista(5, 6, 0);
    myGraph2.agregarArista(5, 9, 0);
    myGraph2.agregarArista(6, 2, 0);
    myGraph2.agregarArista(6, 3, 0);
    myGraph2.agregarArista(7, 5, 0);
    myGraph2.agregarArista(7, 6, 0);
    myGraph2.agregarArista(8, 2, 0);
    myGraph2.agregarArista(9, 6, 0);
    cout << myGraph2.printGraph() << '\n';
    cout << "DFS desde 8:" << myGraph2.printDFS(8) << '\n';
    cout << "BFS desde 4:" << myGraph2.printBFS(4) << '\n';
    return 0;
}