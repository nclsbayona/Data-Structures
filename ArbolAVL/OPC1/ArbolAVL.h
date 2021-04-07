#ifndef _ARBOLAVL_H
#define _ARBOLAVL_H
#include "NodoAVL.h"
#include <list>
template <class T>
class ArbolAVL{
    private:
        NodoAVL<T>* head;
        bool insertNode(NodoAVL<T>* toCompare, NodoAVL<T>*& node);
        NodoAVL<T>* searchNodeR(NodoAVL<T>* node, NodoAVL<T>*& searching);
        bool nodeBalanced(NodoAVL<T>* node);
        NodoAVL<T>* composedRotation1(NodoAVL<T>*&node, bool update=false);
        NodoAVL<T>* composedRotation2(NodoAVL<T>*&node, bool update=false);
        NodoAVL<T>* rightRotation(NodoAVL<T>*&node, bool update=false);
        NodoAVL<T>* leftRotation(NodoAVL<T>*&node, bool update=false);
    public:
        bool balanced();
        bool balance(NodoAVL<T>*& node);
        ArbolAVL(T data);
        ArbolAVL(NodoAVL<T>*& head);
        ~ArbolAVL();
        NodoAVL<T>* getHead();
        void setHead(NodoAVL<T>*& head);
        NodoAVL<T>* insertNode(NodoAVL<T>*& node);
        NodoAVL<T>* insertNode(T node);
        NodoAVL<T>* removeNodeMinor(NodoAVL<T>*& node);
        NodoAVL<T>* removeNodeGreater(NodoAVL<T>*& node);
        bool removeNode(NodoAVL<T>*& node);
        bool removeNode(T node);
        NodoAVL<T>* searchNodeFather(NodoAVL<T>* node);
        NodoAVL<T>* searchNodeFather(T node);
        std::string printTree();
        std::string inOrder();
        std::string preOrder();
        std::string postOrder();
        std::string levelOrder();
        int height();
};
#include "ArbolAVL.hxx"
#endif

