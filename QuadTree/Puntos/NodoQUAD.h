#ifndef _NODOQUAD_H
#define _NODOQUAD_H
#include "OrderedQUADPair.h"
template <class T>
class NodoQUAD
{
    private:
        OrderedQUADPair<T>* data;
        NodoQUAD<T> *upLeft;
        NodoQUAD<T> *upRight;
        NodoQUAD<T> *downRight;
        NodoQUAD<T> *downLeft;

    public:
        NodoQUAD(T data1, T data2);
        ~NodoQUAD();
        OrderedQUADPair<T>* getData();
        NodoQUAD<T> *getUpLeft();
        NodoQUAD<T> *getUpRight();
        NodoQUAD<T> *getDownLeft();
        NodoQUAD<T> *getDownRight();
        NodoQUAD<T> *subMinor();
        NodoQUAD<T> *subGreater();
        NodoQUAD<T> *removeSubMinor();
        NodoQUAD<T> *removeSubGreater();
        void setData(OrderedQUADPair<T>* data);
        void setUpLeft(NodoQUAD<T> *upLeft);
        void setUpRight(NodoQUAD<T> *upRight);
        void setDownLeft(NodoQUAD<T> *downLeft);
        void setDownRight(NodoQUAD<T> *downRight);
        int compareTo(OrderedQUADPair<T>* data);
        int compareTo(T data1, T data2);
        int compareTo(NodoQUAD<T> *c);
        std::string toString(int level = 0, std::string car = "Head ");
        std::string toString(bool unique);
        std::string inOrder();
        std::string preOrder();
        std::string postOrder();
};
#include "NodoQUAD.hxx"
#endif
