#include "Graph.h"
#include <iostream>
template <class T, class U>
Graph<T, U>::Graph(bool dirigido)
{
    this->dirigido = dirigido;
}

template <class T, class U>
std::string Graph<T, U>::printGraph()
{
    std::string printing = "\nPeso 0 implica que no tiene peso, una lista vacía significa que es un nodo isla o un nodo sumidero\n\n";
    typedef std::map<int, std::set<U>> W;
    typename std::map<int, W>::iterator it_vertices = this->vertices_aristas.begin();
    typename W::iterator it_aristas;
    typename std::set<U>::iterator it_pesos;
    printing += "{\n\t[";
    for (; it_vertices != this->vertices_aristas.end(); it_vertices++)
    {
        printing += "\n\t\t{\n\t\t\t" + std::to_string(this->values[it_vertices->first]) + ":\n";
        printing += "\t\t\t[\n";
        for (it_aristas = it_vertices->second.begin(); it_aristas != it_vertices->second.end(); it_aristas++)
        {
            printing += "\t\t\t\t" + std::to_string(this->values[it_aristas->first]) + ": [";
            for (it_pesos = it_aristas->second.begin(); it_pesos != it_aristas->second.end(); it_pesos++)
                printing += " " + std::to_string(*it_pesos);
            printing += " ]\n";
        }
        printing += "\t\t\t]\n\t\t}\n";
    }
    printing += "\t]\n}\n\n";
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
        this->values.push_back(start);

        this->vertices_aristas[this->indexOf(start)];
        done = true;
    }
    return done;
}

template <class T, class U>
bool Graph<T, U>::buscarVertice(T start)
{
    return std::find(this->values.begin(), this->values.end(), start) != this->values.end();
}

template <class T, class U>
int Graph<T, U>::indexOf(T start)
{
    int val = -1;
    if (this->buscarVertice(start))
        val = std::find(this->values.begin(), this->values.end(), start) - this->values.begin();
    return val;
}

template <class T, class U>
bool Graph<T, U>::eliminarVertice(T start)
{
    bool total = 0;
    int index;
    try
    {
        if (this->buscarVertice(start))
        {
            typename std::map<int, std::map<int, std::set<U>>>::iterator it, it2;
            typename std::map<int, std::set<U>>::iterator it3;
            index = this->indexOf(start);
            for (it = this->vertices_aristas.begin(); it != this->vertices_aristas.end(); ++it)
            {
                it3 = it->second.find(index);
                if (this->values[it->first] == start)
                    it2 = it;
                if (it3 != it->second.end())
                    it->second.erase(it3);
            }
            this->vertices_aristas.erase(it2);
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
            this->vertices_aristas[this->indexOf(end)][this->indexOf(start)].insert(value);
        this->vertices_aristas[this->indexOf(start)][this->indexOf(end)].insert(value);
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
            typedef std::map<int, std::set<U>> W;
            typename W::iterator it_vertices = this->vertices_aristas[this->indexOf(start)].find(this->indexOf(end));
            if (it_vertices != this->vertices_aristas[this->indexOf(start)].end())
                exists = (this->vertices_aristas[this->indexOf(start)][this->indexOf(end)].count(value));
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
    typedef std::map<int, std::set<U>> W;
    typename std::map<int, W>::iterator it_vertices = this->vertices_aristas.begin();
    typename W::iterator it_aristas;
    for (; it_vertices != this->vertices_aristas.end(); ++it_vertices)
    {

        if (it_vertices->second.size() > 0)
        {
            it_aristas = (it_vertices)->second.begin();
            for (; it_aristas != (it_vertices)->second.end(); ++it_aristas)
                total += it_aristas->second.size();
        }
    }
    return total;
}

template <class T, class U>
bool Graph<T, U>::eliminarArista(T start, T end, U value)
{
    bool total = 0;
    if (this->buscarVertice(start) && this->buscarVertice(end) && this->buscarArista(start, end, value))
    {
        typedef std::map<int, std::set<U>> W;
        if (this->vertices_aristas[this->indexOf(start)].find(this->indexOf(end)) != this->vertices_aristas[this->indexOf(start)].end())
        {
            this->vertices_aristas[this->indexOf(start)][this->indexOf(end)].erase(value);
            if (this->vertices_aristas[this->indexOf(start)][this->indexOf(end)].size() == 0)
                this->vertices_aristas[this->indexOf(start)].erase(this->indexOf(end));
            total = 1;
        }
    }
    return total;
}

//Recorridos
template <class T, class U>
void Graph<T, U>::impresionA(std::queue<int> queueDFS)
{
    while (!queueDFS.empty())
    {
        std::cout << " " << std::to_string(this->values[queueDFS.front()]) << " ";
        queueDFS.pop();
    }
}

template <class T, class U>
std::queue<int> Graph<T, U>::DFS(T start)
{
    typename std::map<int, std::set<U>>::iterator it_aristas;
    int index = this->indexOf(start);
    std::queue<int> queueDFS;
    std::stack<int> stackVisited;
    int top;
    T *min_obj = NULL;
    int min_index;
    std::set<int> setVisited;
    std::set<int, std::greater<T>> indexesTMP;
    stackVisited.push(index);
    if (this->buscarVertice(start))
        while (!stackVisited.empty())
        {
            top = stackVisited.top();
            stackVisited.pop();
            if (setVisited.count(top) == 0)
            {
                queueDFS.push(top);
                setVisited.insert(top);
                it_aristas = this->vertices_aristas[top].begin();
                for (; it_aristas != this->vertices_aristas[top].end(); it_aristas++)
                    indexesTMP.insert(this->values[it_aristas->first]);
                while (!indexesTMP.empty())
                {
                    if (setVisited.count(this->indexOf(*(indexesTMP.begin()))) == 0)
                        stackVisited.push(this->indexOf(*(indexesTMP.begin())));
                    indexesTMP.erase(indexesTMP.begin());
                }
            }
        }
    return queueDFS;
}

//BFS
template <class T, class U>
std::queue<int> Graph<T, U>::BFS(T start)
{

    typename std::map<int, std::set<U>>::iterator it_aristas;
    int index = this->indexOf(start);
    std::queue<int> queueDFS;
    std::queue<int> stackVisited;
    int top;
    T *min_obj = NULL;
    int min_index;
    std::set<int> setVisited;
    std::set<int> indexesTMP;
    stackVisited.push(index);
    if (this->buscarVertice(start))
        while (!stackVisited.empty())
        {
            top = stackVisited.front();
            stackVisited.pop();
            if (setVisited.count(top) == 0)
            {
                queueDFS.push(top);
                setVisited.insert(top);
                it_aristas = this->vertices_aristas[top].begin();
                for (; it_aristas != this->vertices_aristas[top].end(); it_aristas++)
                    indexesTMP.insert(this->values[it_aristas->first]);
                while (!indexesTMP.empty())
                {
                    if (setVisited.count(this->indexOf(*(indexesTMP.begin()))) == 0)
                        stackVisited.push(this->indexOf(*(indexesTMP.begin())));
                    indexesTMP.erase(indexesTMP.begin());
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
        printing += std::to_string(this->values[queueDFS.front()]);
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
    std::queue<T> queueDFS = this->BFS(start);
    while (!queueDFS.empty())
    {
        printing += " ";
        printing += std::to_string(this->values[queueDFS.front()]);
        printing += " ";
        queueDFS.pop();
    }
    printing += "\n\n";
    return printing;
}

// Descendientes - Ascendientes
template <class T, class U>
std::set<T> Graph<T, U>::descendientes(T vertice)
{
    bool visitedNode = false;
    std::set<T> set;
    if (this->buscarVertice(vertice))
    {
        set.insert(vertice);
        for (typename std::map<int, std::set<U>>::iterator it_aristas = this->vertices_aristas[this->indexOf(vertice)].begin(); it_aristas != this->vertices_aristas[this->indexOf(vertice)].end(); ++it_aristas)
        {
            if (set.count(this->values[it_aristas->first]) == 0)
            {
                this->descendientesRecursivo(this->values[it_aristas->first], set);
                set.insert(this->values[it_aristas->first]);
            }
        }
    }
    return set;
}

template <class T, class U>
void Graph<T, U>::descendientesRecursivo(T vertice, std::set<T> &set)
{
    if (set.count(vertice) == 0)
    {
        set.insert(vertice);
        for (typename std::map<int, std::set<U>>::iterator it = this->vertices_aristas[this->indexOf(vertice)].begin(); it != this->vertices_aristas[this->indexOf(vertice)].end(); ++it)
        {
            if (set.count(this->values[it->first]) == 0)
            {
                this->descendientesRecursivo(this->values[it->first], set);
                set.insert(this->values[it->first]);
            }
        }
    }
}

template <class T, class U>
std::set<T> Graph<T, U>::ascendientes(T vertice)
{
    std::set<T> set;
    if (this->buscarVertice(vertice))
    {
        set.insert(vertice);
        for (typename std::map<int, std::map<int, std::set<U>>>::iterator it_vertices = this->vertices_aristas.begin(); it_vertices != this->vertices_aristas.end(); ++it_vertices)
        {
            if (set.count(this->values[it_vertices->first]) == 0)
            {
                if (this->descendientes(this->values[it_vertices->first]).count(vertice) != 0)
                    set.insert(this->values[it_vertices->first]);
            }
        }
    }
    return set;
}

template <class T, class U>
bool Graph<T, U>::grafoConectado()
{
    bool connected = true;
    typename std::map<int, std::map<int, std::set<U>>>::iterator it_vertices2;
    typename std::set<T> ascendientes;
    typename std::set<T> descendientes;
    for (typename std::map<int, std::map<int, std::set<U>>>::iterator it_vertices = this->vertices_aristas.begin(); connected && it_vertices != this->vertices_aristas.end(); ++it_vertices)
    {
        it_vertices2 = this->vertices_aristas.begin();
        ascendientes = this->ascendientes(this->values[it_vertices->first]);
        descendientes = this->descendientes(this->values[it_vertices->first]);
        for (; connected && it_vertices2 != this->vertices_aristas.end(); ++it_vertices2)
        {
            if (ascendientes.count(this->values[it_vertices2->first]) != 1 || descendientes.count(this->values[it_vertices2->first]) != 1)
                connected = false;
        }
    }
    return connected;
}

template <class T, class U>
int Graph<T, U>::cantidadCamposConectados()
{
    int connected = 0;
    if (this->grafoConectado())
        connected += 1;
    else
    {

        typedef typename std::set<T> mySet;
        typename std::map<int, std::map<int, std::set<U>>>::iterator it_vertices;
        mySet ascendientes, missing, descendientes;
        typedef typename std::vector<T> vector;
        vector campo;
        typename vector::iterator campo_iterator;
        T node;
        for (it_vertices = this->vertices_aristas.begin(); it_vertices != this->vertices_aristas.end(); ++it_vertices)
            missing.insert(it_vertices->first);
        while (!missing.empty())
        {
            campo.clear();
            node = this->values[*(missing.begin())];
            ascendientes = this->ascendientes(node);
            descendientes = this->descendientes(node);
            std::set_intersection(ascendientes.begin(), ascendientes.end(), descendientes.begin(), descendientes.end(), std::back_inserter(campo));
            for (campo_iterator = campo.begin(); campo_iterator != campo.end(); campo_iterator++)
                missing.erase(this->indexOf(*campo_iterator));
            connected += 1;
        }
    }
    return connected;
}

template <class T, class U>
bool Graph<T, U>::aristaPuente(T start, T end, U valor)
{
    bool connected = false;
    bool dirc = this->buscarArista(end, start, valor);
    int camposC = this->cantidadCamposConectados();
    this->eliminarArista(start, end, valor);
    if (dirc)
        this->eliminarArista(end, start, valor);
    if (this->cantidadCamposConectados() > camposC)
        connected = true;
    if (!dirc)
        this->agregarArista(start, end, valor, 1);
    else
        this->agregarArista(start, end, valor, 0);
    return connected;
}

template <class T, class U>
int Graph<T, U>::gradoSalida(T vertice)
{
    int grado = 0;
    typename std::map<int, std::set<U>>::iterator it = this->vertices_aristas[this->indexOf(vertice)].begin();
    for (; it != this->vertices_aristas[this->indexOf(vertice)].end(); ++it)
        grado += it->second.size();
    return grado;
}

template <class T, class U>
int Graph<T, U>::gradoEntrada(T vertice)
{
    int grado = 0;
    typename std::map<int, std::map<int, std::set<U>>>::iterator it = this->vertices_aristas.begin();
    typename std::map<int, std::set<U>>::iterator it2;
    for (; it != this->vertices_aristas.end(); ++it)
    {
        it2 = it->second.find(this->indexOf(vertice));
        if (it2 != it->second.end())
            grado += it->second[this->indexOf(vertice)].size();
    }
    return grado;
}

template <class T, class U>
int Graph<T, U>::grado(T vertice)
{
    int gradoE = this->gradoEntrada(vertice);
    int gradoS = this->gradoSalida(vertice);
    int grado = gradoE + gradoS;
    if (gradoE == gradoS)
        grado /= 2;
    return grado;
}

template <class T, class U>
std::vector<T> Graph<T, U>::prim(T start)
{
    //Las aristas (pesos) deben estar ordenados
    std::set<T> vnew;
    std::vector<T> enew;
    typename std::map<int, std::map<int, std::set<U>>>::iterator it_vertices;
    typename std::map<int, std::set<U>>::iterator it_aristas;
    std::pair<T, U> weight;
    U actual_weight;
    vnew.insert(start);
    enew.push_back(start);
    while (this->vertices_aristas.size() != vnew.size())
    {
        //Hallar el menor (u,v) que tenga u visitado y v no
        //Buscar U:
        //ABSOLUTE ZERO -273.15K
        weight.second = -273;
        it_vertices = this->vertices_aristas.begin();
        for (; it_vertices != this->vertices_aristas.end(); ++it_vertices)
        {
            //U en vnew
            if (vnew.count(this->values[it_vertices->first]) != 0)
            {
                it_aristas = this->vertices_aristas[it_vertices->first].begin();
                for (; it_aristas != this->vertices_aristas[it_vertices->first].end(); ++it_aristas)
                {
                    //V no en vnew
                    if (vnew.count(this->values[it_vertices->first]) == 0)
                    {
                        actual_weight = *(it_aristas->second.begin());
                        if (((actual_weight < weight.second || weight.second == -273)) || (((weight.second != -273) && (actual_weight == weight.second)) && (weight.first > it_aristas->first)))
                        {
                            //La última condición es para orden ascendente
                            weight.first = this->values[it_aristas->first];
                            weight.second = actual_weight;
                        }
                    }
                }
            }
        }
        enew.push_back(weight.first);
        vnew.insert(weight.first);
    }
    return enew;
}

template <class T, class U>
std::map<int, std::pair<int, U>> Graph<T, U>::dijkstra2(int start)
{
    typedef std::map<int, std::pair<int, U>> myMap;
    myMap dist;
    std::set<int> visited;
    std::pair<int, U> pair;
    U actual_weight;
    const int MIN = 999999, MAX = 20;
    typename std::map<int, std::set<U>>::iterator it_arista;
    for (typename std::map<int, std::map<int, std::set<U>>>::iterator it = this->vertices_aristas.begin(); it != this->vertices_aristas.end(); ++it)
    {
        pair.first = it->first;
        pair.second = MIN;
        if (it->first == start)
            pair.second = 0;
        dist[it->first] = pair;
    }

    while (dist.size() != visited.size() && visited.count(start) == 0)
    {
        for (it_arista = this->vertices_aristas[start].begin(); it_arista != this->vertices_aristas[start].end(); ++it_arista)
        {
            actual_weight = *(it_arista->second.begin()) + dist[start].second;
            if (actual_weight < dist[it_arista->first].second)
            {
                dist[it_arista->first].first = start;
                dist[it_arista->first].second = actual_weight;
            }
        }
        visited.insert(start);
        actual_weight = MIN;
        for (typename myMap::iterator it = dist.begin(); it != dist.end(); ++it)
        {
            if (visited.count(it->first) == 0)
            {
                if (actual_weight > it->second.second)
                {
                    actual_weight = it->second.second;
                    start = it->first;
                }
            }
        }

        /* std::cout<<"Visited\n";
        for (auto line:visited)
            std::cout<<this->values[line]<<'\n';
        std::cout<<"Dist\n";
        for (auto line:dist)
            std::cout<<this->values[line.first]<<": "<<this->values[line.second.first]<<", "<<line.second.second<<'\n';
        std::cin>>actual_weight; */
    }
    return dist;
}

template <class T, class U>
std::pair<U, std::vector<T>> Graph<T, U>::dijkstra(T start, T end)
{
    typename std::map<int, std::pair<int, U>> dist = this->dijkstra2(this->indexOf(start));
    typename std::pair<U, std::vector<T>> route;
    T new_end;
    if (dist.find(this->indexOf(end)) != dist.end() && dist[this->indexOf(end)].second != 999999)
    {
        route.first = dist[this->indexOf(end)].second;
        route.second.push_back(start);
        while (std::find(route.second.begin(), route.second.end(), end) == route.second.end())
        {
            new_end = this->values[dist[this->indexOf(end)].first];
            if (std::find(route.second.begin(), route.second.end(), new_end) == route.second.end())
            {
                while (std::find(route.second.begin(), route.second.end(), this->values[dist[this->indexOf(new_end)].first]) == route.second.end())
                    new_end=this->values[dist[this->indexOf(new_end)].first];
                route.second.push_back(new_end);
            }
            else
                route.second.push_back(end);
        }
    }
    return route;
}