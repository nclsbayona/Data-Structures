#ifndef _NODOAVL_H
#define _NODOAVL_H
#include <string>
template <class T>
class NodoAVL{
    private:
        T data;
        NodoAVL<T>* left;
        NodoAVL<T>* right;
    public:
        NodoAVL(T data);
        ~NodoAVL();
        T getData();
        NodoAVL<T>* getLeft();
        NodoAVL<T>* getRight();
        NodoAVL<T>* subMinor();
        NodoAVL<T>* subGreater();
        NodoAVL<T>* removeSubMinor();
        NodoAVL<T>* removeSubGreater();
        void setData(T data);
        void setLeft(NodoAVL<T>*& left);
        void setRight(NodoAVL<T>*& right);
        int height(int acu=0);
        int compareTo(T data);
        int compareTo(NodoAVL<T>*& c);
        std::string toString(int level=0, std::string car="Head ");
        std::string toString(bool unique);
        std::string inOrder();
        std::string preOrder();
        std::string postOrder();
};
#include "NodoAVL.hxx"
#endif

