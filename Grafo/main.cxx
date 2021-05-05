#include <iostream>
#include "Grafo.h"
using namespace std;
int main(){
    cout<<"Bienvenido\n\n";
    Grafo<int,char> myGraph;
    myGraph.agregarArista(2,3);
    myGraph.agregarArista(2,3);
    myGraph.agregarArista(2,4,0,1);
    cout<<"Tratando de agregar 5(BIEN)"<<myGraph.agregarVertice(5)<<'\n';
    cout<<"Tratando de agregar 2(MAL)"<<myGraph.agregarVertice(2)<<'\n';
    cout<<"Tratando de buscar arista de 2 a 4 (BIEN): "<<myGraph.buscarArista(2, 4)<<'\n';
    cout<<"Tratando de buscar arista de 4 a 2 (BIEN): "<<myGraph.buscarArista(4, 2)<<'\n';
    cout<<"Tratando de buscar arista de 2 a 1 (MAL): "<<myGraph.buscarArista(2, 1)<<'\n';
    cout<<"Tratando de buscar vertice 2 (BIEN): "<<myGraph.buscarVertice(2)<<'\n';
    cout<<"Tratando de buscar vertice 10 (MAL): "<<myGraph.buscarVertice(10)<<'\n';
    cout<<myGraph.printGraph();
    cout<<"Aristas: "<<myGraph.cantidadAristas()<<'\n';
    cout<<"Vertices: "<<myGraph.cantidadVertices()<<'\n'<<'\n';
    cout<<"Tratando de eliminar arista de 2 a 4 (BIEN): "<<myGraph.eliminarArista(2, 4)<<'\n';
    cout<<"Tratando de eliminar arista de 10 a 2 (MAL): "<<myGraph.eliminarArista(10, 2)<<'\n';
    cout<<"Tratando de eliminar vertice 2 (BIEN): "<<myGraph.eliminarVertice(2)<<'\n';
    cout<<"Tratando de eliminar vertice 10 (MAL): "<<myGraph.eliminarVertice(10)<<'\n';
    cout<<myGraph.printGraph();
    return 0;
}