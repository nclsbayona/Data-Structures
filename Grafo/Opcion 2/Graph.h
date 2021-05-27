#ifndef Graph_H
#define Graph_H
#include <map>
#include <set>
#include <unordered_set>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <utility>
#include <algorithm>
template <class T, class U=int>
class Graph{
    private:
        bool dirigido;
        std::vector<T> values;
        std::map<int,std::map<int, std::set<U>>> vertices_aristas;
    public:
        Graph(bool dirigido=false);
        std::string printGraph();
        bool getDirigido();
        //Vertices
        bool agregarVertice(T start);
        bool buscarVertice(T start);
        int indexOf(T start);
        bool eliminarVertice(T start);
        int cantidadVertices();
        //Aristas
        bool agregarArista(T start, T end, U value=0, int directed=2);
        bool buscarArista(T start, T end, U value=0);
        bool eliminarArista(T start, T end, U value=0);
        int cantidadAristas();
        //Recorridos
        std::queue<int> DFS(T start);
        void impresionA(std::queue<int> queueDFS);
        std::queue<int> BFS(T start);
        std::string printDFS(T start); 
        std::string printBFS(T start);
        //Descendientes / Ascendientes
        std::set<T> descendientes(T vertice);
        void descendientesRecursivo(T vertice, std::set<T>& queue);
        std::set<T> ascendientes(T vertice);
        //Campos conectados
        bool grafoConectado();
        int cantidadCamposConectados();
        bool aristaPuente(T start, T end, U valor=0);
        int gradoSalida(T vertice);
        int gradoEntrada(T vertice);
        int grado(T vertice);
        //Recorridos
        std::vector<T> prim(T start);
        std::vector<T> kruskal();
        std::map<int, std::pair<int, U>> dijkstra2(int start);
        std::pair<U, std::vector<T>> dijkstra(T start, T end);
        //Falta KRUSKAL; EULER; PREGUNTAR BIPARTITO
};
#include "Graph.hxx"
#endif