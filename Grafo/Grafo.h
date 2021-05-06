#ifndef GRAFO_H
#define GRAFO_H
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <utility>
template <class T, class U=int>
class Grafo{
    private:
        bool dirigido;
        std::map<T,std::map<T, std::set<U>>> vertices_aristas;
    public:
        Grafo(bool dirigido=false);
        std::string printGraph();
        bool agregarArista(T start, T end, bool directed=false, U value=2);
        bool buscarArista(T start, T end, U value=0);
        bool eliminarArista(T start, T end, U value=0);
        int cantidadAristas();
        bool agregarVertice(T start);
        bool buscarVertice(T start);
        bool eliminarVertice(T start);
        int cantidadVertices();
        //Recorridos
        std::queue<T> DFS(T start);
        std::queue<T> BFS(T start);
        std::string printDFS(T start);
        std::string printBFS(T start);
};
#include "Grafo.hxx"
#endif