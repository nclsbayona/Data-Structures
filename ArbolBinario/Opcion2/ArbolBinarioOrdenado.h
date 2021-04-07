#ifndef _ARBOLBINARIOORDENADO_H
#define _ARBOLBINARIOORDENADO_H
#include "NodoBinarioOrdenado.h"
#include <list>
template <class T>
class ArbolBinarioOrdenado{
    private:
        NodoBinarioOrdenado<T>* head;
        bool insertNode(NodoBinarioOrdenado<T>* toCompare, NodoBinarioOrdenado<T>*& node);
        NodoBinarioOrdenado<T>* searchNodeR(NodoBinarioOrdenado<T>* node, NodoBinarioOrdenado<T>*& searching);
        bool nodeBalanced(NodoBinarioOrdenado<T>* node);
        NodoBinarioOrdenado<T>* composedRotation1(NodoBinarioOrdenado<T>*&node, bool update=false);
        NodoBinarioOrdenado<T>* composedRotation2(NodoBinarioOrdenado<T>*&node, bool update=false);
        NodoBinarioOrdenado<T>* rightRotation(NodoBinarioOrdenado<T>*&node, bool update=false);
        NodoBinarioOrdenado<T>* leftRotation(NodoBinarioOrdenado<T>*&node, bool update=false);
    public:
        bool balanced();
        ArbolBinarioOrdenado(T data);
        ArbolBinarioOrdenado(NodoBinarioOrdenado<T>*& head);
        ~ArbolBinarioOrdenado();
        NodoBinarioOrdenado<T>* getHead();
        void setHead(NodoBinarioOrdenado<T>*& head);
        NodoBinarioOrdenado<T>* insertNode(NodoBinarioOrdenado<T>*& node);
        NodoBinarioOrdenado<T>* insertNode(T node);
        NodoBinarioOrdenado<T>* removeNodeMinor(NodoBinarioOrdenado<T>*& node);
        NodoBinarioOrdenado<T>* removeNodeGreater(NodoBinarioOrdenado<T>*& node);
        bool removeNode(NodoBinarioOrdenado<T>*& node);
        bool removeNode(T node);
        NodoBinarioOrdenado<T>* searchNodeFather(NodoBinarioOrdenado<T>* node);
        NodoBinarioOrdenado<T>* searchNodeFather(T node);
        std::string printTree();
        std::string inOrder();
        std::string preOrder();
        std::string postOrder();
        std::string levelOrder();
        int height();
};
#include "ArbolBinarioOrdenado.hxx"
#endif

