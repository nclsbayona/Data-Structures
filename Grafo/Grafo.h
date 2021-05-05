#ifndef GRAFO_H
#define GRAFO_H
#include <map>
#include <set>
#include <utility>
template <class T, class U=int>
class Grafo{
    private:
        bool dirigido;
        std::map<T,std::map<T, std::set<U>>> vertices_aristas;
    public:
        Grafo(bool dirigido=false);
        std::string printGraph();
        bool agregarArista(T start, T end, U value=0, bool directed=false);
        bool agregarVertice(T start);
        bool buscarVertice(T start);
        bool eliminarArista(T start, T end, U value=0);
        bool eliminarVertice(T start);
        bool buscarArista(T start, T end, U value=0);
        int cantidadVertices();
        int cantidadAristas();
};
#include "Grafo.hxx"
#endif