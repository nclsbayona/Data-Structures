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
    Graph<int, char> myGraph2(1);
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
    cout << "DFS desde 14:" << myGraph2.printDFS(14) << '\n';
    cout << "BFS desde 4:" << myGraph2.printBFS(4) << '\n';
    cout << "BFS desde 14:" << myGraph2.printBFS(14) << '\n';
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    //New 2
    Graph<int, char> myGraph3;
    myGraph3.agregarArista(2, 3, 0);
    myGraph3.agregarArista(3, 4, 0);
    myGraph3.agregarArista(4, 5, 0);
    myGraph3.agregarArista(4, 13, 0, 1);
    myGraph3.agregarArista(4, 15, 0);
    myGraph3.agregarArista(4, 12, 0);
    myGraph3.agregarArista(5, 6, 0);
    myGraph3.agregarArista(6, 7, 0, 1);
    cout << myGraph3.printGraph();
    set<int> set = myGraph3.descendientes(7);
    cout << "Descendientes de 7\n";
    for (std::set<int>::iterator it = set.begin(); it != set.end(); ++it)
        cout << (*it) << ' ';
    set = myGraph3.ascendientes(7);
    cout << "\nAscendientes de 7\n";
    for (std::set<int>::iterator it = set.begin(); it != set.end(); ++it)
        cout << (*it) << ' ';
    cout << "\nGrafo conectado: " << myGraph3.grafoConectado() << endl;
    cout << myGraph3.printGraph();
    cout << "Cantidad campos conectados " << myGraph3.cantidadCamposConectados() << endl;
    cout << "Arista puente 4 a 5, valor 0 (SI): " << myGraph3.aristaPuente(4, 5) << endl;
    cout << "Arista puente 6 a 7, valor 0 (NO): " << myGraph3.aristaPuente(6, 7) << endl;
    cout << myGraph3.printGraph();
    return 0;
}