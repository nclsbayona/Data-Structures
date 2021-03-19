#ifndef _ARBOLBINARIO_H
#define _ARBOLBINARIO_H
#include "NodoBinarioOrdenado.h"
#include <vector>
template <class T>
class ArbolBinarioOrdenado{
    private:
        NodoBinarioOrdenado<T>* head;
        bool insertNode(NodoBinarioOrdenado<T>* toCompare, NodoBinarioOrdenado<T>* node);
        NodoBinarioOrdenado<T>* searchNodeR(NodoBinarioOrdenado<T>* node, NodoBinarioOrdenado<T>* searching);
    public:
        ArbolBinarioOrdenado(T data);
        ~ArbolBinarioOrdenado();
        NodoBinarioOrdenado<T>* getHead();
        void setHead(NodoBinarioOrdenado<T>* head);
        NodoBinarioOrdenado<T>* insertNode(NodoBinarioOrdenado<T>* node);
        NodoBinarioOrdenado<T>* insertNode(T node);
        NodoBinarioOrdenado<T>* removeNodeMinor(NodoBinarioOrdenado<T>* node);
        NodoBinarioOrdenado<T>* removeNodeGreater(NodoBinarioOrdenado<T>* node);
        bool removeNode(NodoBinarioOrdenado<T>* node);
        NodoBinarioOrdenado<T>* searchNode(NodoBinarioOrdenado<T>* node);
        std::string printTree();
        std::string inOrder();
        std::string preOrder();
        std::string postOrder();
        std::string levelOrder();
};
#include "ArbolBinarioOrdenado.hxx"
#endif

