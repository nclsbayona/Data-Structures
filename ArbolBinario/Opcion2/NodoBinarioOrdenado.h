#ifndef _NODOBINARIOORDENADO_H
#define _NODOBINARIOORDENADO_H
#include <string>
template <class T>
class NodoBinarioOrdenado{
    private:
        T data;
        NodoBinarioOrdenado<T>* left;
        NodoBinarioOrdenado<T>* right;
    public:
        NodoBinarioOrdenado(T data);
        ~NodoBinarioOrdenado();
        T getData();
        NodoBinarioOrdenado<T>* getLeft();
        NodoBinarioOrdenado<T>* getRight();
        NodoBinarioOrdenado<T>* subMinor();
        NodoBinarioOrdenado<T>* subGreater();
        NodoBinarioOrdenado<T>* removeSubMinor();
        NodoBinarioOrdenado<T>* removeSubGreater();
        void setData(T data);
        void setLeft(NodoBinarioOrdenado<T>*& left);
        void setRight(NodoBinarioOrdenado<T>*& right);
        int height(int acu=0);
        int compareTo(T data);
        int compareTo(NodoBinarioOrdenado<T>*& c);
        std::string toString(int level=0, std::string car="Head ");
        std::string toString(bool unique);
        std::string inOrder();
        std::string preOrder();
        std::string postOrder();
};
#include "NodoBinarioOrdenado.hxx"
#endif

