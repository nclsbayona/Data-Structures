#include "Graph.h"
#include <iostream>
template <class T, class U>
Graph<T, U>::Graph(bool dirigido)
{
    //Default is 0
    this->dirigido = dirigido;
}

template <class T, class U>
std::string Graph<T, U>::printGraph()
{
    std::string printing = "\nPeso 0 implica que no tiene peso, una lista vacía significa que es un nodo isla o un nodo sumidero\n\n";
    typedef std::map<T, std::set<U>> W;
    typename std::map<T, W>::iterator it_vertices = this->vertices_aristas.begin();
    typename W::iterator it_aristas;
    typename std::set<U>::iterator it_pesos;
    printing += "{  ";
    for (; it_vertices != this->vertices_aristas.end(); ++it_vertices)
    {
        printing += std::to_string((*it_vertices).first);
        printing += ":  { ";
        it_aristas = (*it_vertices).second.begin();
        for (; it_aristas != (*it_vertices).second.end(); ++it_aristas++)
        {
            printing += std::to_string((*it_aristas).first);
            printing += ": [";
            for (it_pesos = (*it_aristas).second.begin(); it_pesos != (*it_aristas).second.end(); ++it_pesos)
            {
                printing += " ";
                printing += std::to_string((*it_pesos));
            }
            printing += " ] ";
        }
        printing += "}  ";
    }
    printing += "}\n\n\n";
    return printing;
}

template <class T, class U>
bool Graph<T, U>::getDirigido()
{
    return this->dirigido;
}

//Vertice
template <class T, class U>
bool Graph<T, U>::agregarVertice(T start)
{
    bool done = false;
    if (!this->buscarVertice(start))
    {
        this->vertices_aristas[start];
        done = true;
    }
    return done;
}

template <class T, class U>
bool Graph<T, U>::buscarVertice(T start)
{
    typedef std::map<T, std::set<U>> W;
    typename std::map<T, W>::iterator it_vertices = this->vertices_aristas.find(start);
    return it_vertices != this->vertices_aristas.end();
}

template <class T, class U>
bool Graph<T, U>::eliminarVertice(T start)
{
    bool total = 0;
    try
    {
        if (this->buscarVertice(start))
        {
            this->vertices_aristas.erase(start);
            typedef std::map<T, std::set<U>> W;
            typedef typename std::map<T, W>::iterator it_vertices;
            it_vertices it = this->vertices_aristas.begin();
            typename W::iterator it_aristas;
            for (; it != this->vertices_aristas.end(); ++it)
            {
                it_aristas = it->second.find(start);
                if (it_aristas != it->second.end())
                    it->second.erase(start);
            }
            total = 1;
        }
    }
    catch (...)
    {
        total = 0;
    }
    return total;
}

template <class T, class U>
int Graph<T, U>::cantidadVertices()
{
    typedef std::map<T, std::set<U>> W;
    typename std::map<T, W>::iterator it_vertices = this->vertices_aristas.begin();
    int total = 0;
    for (; it_vertices != this->vertices_aristas.end(); ++it_vertices)
        total++;
    return total;
}

//Aristas
template <class T, class U>
bool Graph<T, U>::agregarArista(T start, T end, U value, int directed)
{
    bool valid = 0;
    //IDK (2 -> Default, 1 -> Dirigido, 0 -> No dirigido)
    if (directed == 2 && this->dirigido)
        directed = 1;
    else if (directed == 2 && !this->dirigido)
        directed = 0;
    //
    try
    {
        if (!this->buscarVertice(start))
            this->agregarVertice(start);
        if (!this->buscarVertice(end))
            this->agregarVertice(end);
        if (!directed)
            this->vertices_aristas[end][start].insert(value);
        this->vertices_aristas[start][end].insert(value);
        valid = 1;
    }
    catch (...)
    {
        valid = 0;
    }
    return valid;
}

template <class T, class U>
bool Graph<T, U>::buscarArista(T start, T end, U value)
{
    bool exists = this->buscarVertice(start);
    try
    {
        if (exists && !this->buscarVertice(end))
            exists = 0;
        else
        {
            typedef std::map<T, std::set<U>> W;
            typename W::iterator it_vertices = this->vertices_aristas[start].find(end);
            if (it_vertices != this->vertices_aristas[start].end())
                exists = (this->vertices_aristas[start][end].count(value));
            else
                exists = 0;
        }
    }
    catch (...)
    {
        exists = 0;
    }
    return exists;
}

template <class T, class U>
int Graph<T, U>::cantidadAristas()
{
    int total = 0;
    typedef std::map<T, std::set<U>> W;
    typename std::map<T, W>::iterator it_vertices = this->vertices_aristas.begin();
    typename W::iterator it_aristas;
    for (; it_vertices != this->vertices_aristas.end(); ++it_vertices)
    {
        it_aristas = (it_vertices)->second.begin();
        if ((it_vertices)->second.size() > 0)
            for (; it_aristas != (it_vertices)->second.end(); ++it_aristas)
                total++;
    }
    return total;
}

template <class T, class U>
bool Graph<T, U>::eliminarArista(T start, T end, U value)
{
    bool total = 0;
    if (this->buscarVertice(start) && this->buscarVertice(end) && this->buscarArista(start, end, value))
    {
        typedef std::map<T, std::set<U>> W;
        typename std::set<U>::iterator it_set;
        it_set = this->vertices_aristas[start][end].find(value);
        this->vertices_aristas[start][end].erase(it_set);
        if (this->vertices_aristas[start][end].size() == 0)
            this->vertices_aristas[start].erase(end);
        total = 1;
    }
    return total;
}

//Recorridos
template <class T, class U>
std::queue<T> Graph<T, U>::DFS(T start)
{
    typedef typename std::map<T, std::set<U>>::reverse_iterator it;
    it it_aristas;
    std::queue<T> queueDFS;
    std::stack<T> stackVisited;
    int w = 0, i;
    T top;
    bool visited;
    T arrayVisited[this->vertices_aristas.size()];
    for (int i = 0; i < this->vertices_aristas.size(); ++i)
        arrayVisited[i] = -100;
    if (this->buscarVertice(start))
    {
        stackVisited.push(start);
        while (!stackVisited.empty())
        {
            top = stackVisited.top();
            stackVisited.pop();
            visited = false;
            for (i = 0; i < w && !visited; ++i)
                if (arrayVisited[i] == top)
                    visited = true;
            if (!visited)
            {
                queueDFS.push(top);
                arrayVisited[w++] = top;
                it_aristas = this->vertices_aristas[top].rbegin();
                for (; it_aristas != this->vertices_aristas[top].rend(); it_aristas++)
                {
                    visited = false;
                    for (i = 0; i < w && !visited; ++i)
                        if (arrayVisited[i] == (it_aristas->first))
                            visited = true;
                    if (!visited)
                        stackVisited.push(it_aristas->first);
                }
            }
        }
    }
    return queueDFS;
}

//BFS
template <class T, class U>
std::queue<T> Graph<T, U>::BFS(T start)
{
    typedef typename std::map<T, std::set<U>>::iterator it;
    it it_aristas;
    std::queue<T> queueDFS;
    std::queue<T> queueVisited;
    int w = 0, i;
    T top, last;
    bool visited;
    T arrayVisited[this->vertices_aristas.size()];
    for (int i = 0; i < this->vertices_aristas.size(); ++i)
        arrayVisited[i] = -100;

    if (this->buscarVertice(start))
    {
        queueVisited.push(start);
        while (!queueVisited.empty())
        {
            top = queueVisited.front();
            queueVisited.pop();
            visited = false;
            for (i = 0; i < w && !visited; ++i)
                if (arrayVisited[i] == top)
                    visited = true;
            if (!visited)
            {
                queueDFS.push(top);
                arrayVisited[w++] = top;
                it_aristas = this->vertices_aristas[top].begin();
                for (; it_aristas != this->vertices_aristas[top].end(); it_aristas++)
                {
                    visited = false;
                    for (i = 0; i < w && !visited; ++i)
                        if (arrayVisited[i] == (it_aristas->first))
                            visited = true;
                    last = it_aristas->first;
                    if (!visited)
                        queueVisited.push(it_aristas->first);
                }
            }
        }
    }
    return queueDFS;
}

template <class T, class U>
std::string Graph<T, U>::printDFS(T start)
{
    std::string printing = "";
    std::queue<T> queueDFS = this->DFS(start);
    while (!queueDFS.empty())
    {
        printing += " ";
        printing += std::to_string(queueDFS.front());
        printing += " ";
        queueDFS.pop();
    }
    printing += "\n\n";
    return printing;
}

template <class T, class U>
std::string Graph<T, U>::printBFS(T start)
{
    std::string printing = "";
    std::queue<T> queueBFS = this->BFS(start);
    while (!queueBFS.empty())
    {
        printing += " ";
        printing += std::to_string(queueBFS.front());
        printing += " ";
        queueBFS.pop();
    }
    printing += "\n\n";
    return printing;
}