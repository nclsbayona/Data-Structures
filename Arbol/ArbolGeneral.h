#ifndef __ARBOL_H__
#define __ARBOL_H__
#include "NodoGeneral.h"
template <class T>
class ArbolGeneral{
    private:
        NodoGeneral<T> *head;
        int maxHighness(NodoGeneral<T> *node, int level);
        int lookLevel(NodoGeneral<T>* looking, NodoGeneral<T> *node, int level=0);
    public:
        ~ArbolGeneral();
        ArbolGeneral(T head_data);
        ArbolGeneral();
        ArbolGeneral(NodoGeneral<T>* head);
        NodoGeneral<T>* getHead();
        NodoGeneral<T>* searchNode(T data);
        NodoGeneral<T> * insertNode(T father, T son);
        bool dataExists(NodoGeneral<T>* node, T data);
        bool pathExists (NodoGeneral<T> *actual, NodoGeneral<T> *destination);
        void setHead(NodoGeneral<T> *head);
        int highness();
        int level (NodoGeneral<T> *node);
        int pathLength(NodoGeneral<T> *source, NodoGeneral<T> *destination);
        std::list<NodoGeneral<T>*> path(NodoGeneral<T> *source, NodoGeneral<T> *destination);
        std::string printTree();
        std::list<std::string> preOrder(NodoGeneral<T> *node);
        std::list<std::string> preOrder();
        std::list<std::string> postOrder();
        std::list<std::string> postOrder(NodoGeneral<T> *node);
};
#include "ArbolGeneral.hxx"
#endif
