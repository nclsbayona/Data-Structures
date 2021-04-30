#ifndef _ARBOLQUAD_H
#define _ARBOLQUAD_H
#include "NodoQUAD.h"
#include <vector>
template <class T>
class ArbolQUAD{
    private:
        NodoQUAD<T>* head;
        bool insertNodeR(NodoQUAD<T>* toCompare, NodoQUAD<T>* node);
        NodoQUAD<T>* searchNodeR(NodoQUAD<T>* node, NodoQUAD<T>* searching);

    public:
        ArbolQUAD(T data1, T data2);
        ~ArbolQUAD();
        NodoQUAD<T>* getHead();
        void setHead(NodoQUAD<T>* head);
        NodoQUAD<T>* insertNode(NodoQUAD<T>* node);
        NodoQUAD<T>* insertNode(T data1, T data2);
        NodoQUAD<T>* removeNodeMinor(NodoQUAD<T>* node);
        NodoQUAD<T>* removeNodeGreater(NodoQUAD<T>* node);
        bool removeNode(NodoQUAD<T>* node);
        NodoQUAD<T>* searchNode(NodoQUAD<T>* node);
        std::string printTree();
        std::string inOrder();
        std::string preOrder();
        std::string postOrder();
        /*std::string levelOrder();*/
};

#include "ArbolQUAD.hxx"
#endif
