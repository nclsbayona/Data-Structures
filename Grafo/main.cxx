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
    set<int> mySet = myGraph3.descendientes(7);
    cout << "Descendientes de 7\n";
    for (std::set<int>::iterator it = mySet.begin(); it != mySet.end(); ++it)
        cout << (*it) << ' ';
    mySet = myGraph3.ascendientes(7);
    cout << "\nAscendientes de 7\n";
    for (std::set<int>::iterator it = mySet.begin(); it != mySet.end(); ++it)
        cout << (*it) << ' ';
    cout << "\nGrafo conectado: " << myGraph3.grafoConectado() << endl;
    cout << myGraph3.printGraph();
    cout << "Cantidad campos conectados " << myGraph3.cantidadCamposConectados() << endl;
    cout << "Arista puente 4 a 5, valor 0 (SI): " << myGraph3.aristaPuente(4, 5) << endl;
    cout << "Arista puente 6 a 7, valor 0 (NO): " << myGraph3.aristaPuente(6, 7) << endl;
    cout << myGraph3.printGraph();
    cout << "Grado de entrada nodo 7 (1): " << myGraph3.gradoEntrada(7) << endl;
    cout << "Grado de salida nodo 7 (0): " << myGraph3.gradoSalida(7) << endl;
    cout << "Grado de nodo 7 (1): " << myGraph3.grado(7) << endl;
    cout << "Grado de entrada nodo 6 (1): " << myGraph3.gradoEntrada(6) << endl;
    cout << "Grado de salida nodo 6 (2): " << myGraph3.gradoSalida(6) << endl;
    cout << "Grado de nodo 6 (3): " << myGraph3.grado(6) << endl;
    //New 3 PG 42 - Presentación 19
    Graph<char, int> myGraph4;
    myGraph4.agregarArista('A', 'B', 4);
    myGraph4.agregarArista('A', 'H', 8);
    myGraph4.agregarArista('B', 'C', 8);
    myGraph4.agregarArista('B', 'H', 11);
    myGraph4.agregarArista('C', 'D', 7);
    myGraph4.agregarArista('C', 'I', 2);
    myGraph4.agregarArista('C', 'F', 4);
    myGraph4.agregarArista('D', 'E', 9);
    myGraph4.agregarArista('D', 'F', 14);
    myGraph4.agregarArista('E', 'F', 10);
    myGraph4.agregarArista('G', 'F', 2);
    myGraph4.agregarArista('G', 'H', 1);
    myGraph4.agregarArista('I', 'H', 7);
    myGraph4.agregarArista('G', 'I', 6);
    cout << myGraph4.printGraph();
    vector<char> new_set = myGraph4.prim('A');
    cout << "Prim de A\n";
    for (vector<char>::iterator it = new_set.begin(); it != new_set.end(); ++it)
        cout << *it<<" ";
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    //New 4 PG 45 - Presentación 19 && PG  - Presentacion 20
    Graph<int, int> myGraph5(1);
    myGraph5.agregarArista(0, 1, 5);
    myGraph5.agregarArista(0, 4, 9);
    myGraph5.agregarArista(0, 7, 8);
    myGraph5.agregarArista(1, 7, 4);
    myGraph5.agregarArista(1, 2, 12);
    myGraph5.agregarArista(1, 3, 15);
    myGraph5.agregarArista(3, 6, 9);
    myGraph5.agregarArista(2, 3, 3);
    myGraph5.agregarArista(2, 6, 11);
    myGraph5.agregarArista(5, 2, 1);
    myGraph5.agregarArista(5, 6, 13);
    myGraph5.agregarArista(7, 2, 7);
    myGraph5.agregarArista(7, 5, 6);
    myGraph5.agregarArista(4, 7, 5);
    myGraph5.agregarArista(4, 5, 4);
    myGraph5.agregarArista(4, 6, 20);
    vector <int> prim0=myGraph5.prim(0);
    cout << "Prim de 0\n";
    for (vector<int>::iterator it = prim0.begin(); it != prim0.end(); ++it)
        cout << *it<<" ";
    return 0;
}