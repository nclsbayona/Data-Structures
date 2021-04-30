#include "NodoQUAD.h"
//#include <iostream>

template <class T>
OrderedQUADPair<T> *NodoQUAD<T>::getData()
{
    return this->data;
}

template <class T>
NodoQUAD<T>::NodoQUAD(T data1, T data2)
{
    this->data = new OrderedQUADPair<T>(data1, data2);
}

template <class T>
NodoQUAD<T>::~NodoQUAD()
{
    //std::cout<<"Deleting node: "<<this->data<<'\n';
    if (this->upLeft)
        delete this->upLeft;
    if (this->upRight)
        delete this->upRight;
    if (this->downLeft)
        delete this->downLeft;
    if (this->downRight)
        delete this->downRight;
}

template <class T>
NodoQUAD<T> *NodoQUAD<T>::getUpLeft()
{
    return this->upLeft;
}

template <class T>
NodoQUAD<T> *NodoQUAD<T>::getUpRight()
{
    return this->upRight;
}

template <class T>
NodoQUAD<T> *NodoQUAD<T>::getDownLeft()
{
    return this->downLeft;
}

template <class T>
NodoQUAD<T> *NodoQUAD<T>::getDownRight()
{
    return this->downRight;
}

template <class T>
void NodoQUAD<T>::setData(OrderedQUADPair<T> *data)
{
    this->data = data;
}

template <class T>
void NodoQUAD<T>::setUpLeft(NodoQUAD<T> *upLeft)
{
    this->upLeft = upLeft;
}

template <class T>
void NodoQUAD<T>::setUpRight(NodoQUAD<T> *upRight)
{
    this->upRight = upRight;
}

template <class T>
void NodoQUAD<T>::setDownLeft(NodoQUAD<T> *downLeft)
{
    this->downLeft = downLeft;
}

template <class T>
void NodoQUAD<T>::setDownRight(NodoQUAD<T> *downRight)
{
    this->downRight = downRight;
}

template <class T>
int NodoQUAD<T>::compareTo(OrderedQUADPair<T> *data)
{
    // -2 si es menor, menor
    // -1 si es menor mayor
    // 0 si son iguales
    // 1 si es mayor menor
    // 2 si es mayor mayor

    if (this->data->getData1() > data->getData1() && this->data->getData2() > data->getData2())
        return -1;
    else if (this->data->getData1() > data->getData1() && this->data->getData2() < data->getData2())
        return 1;
    else if (this->data->getData1() < data->getData1() && this->data->getData2() > data->getData2())
        return -2;
    else if (this->data->getData2() < data->getData2())
        return 2;
    return 0;
}

template <class T>
int NodoQUAD<T>::compareTo(T data1, T data2)
{
    OrderedQUADPair<T> *l = new OrderedQUADPair<T>(data1, data2);
    return this->compareTo(l);
}

template <class T>
int NodoQUAD<T>::compareTo(NodoQUAD<T> *c)
{
    return this->compareTo(c->getData());
}

template <class T>
std::string NodoQUAD<T>::toString(int level, std::string car)
{
    std::string ret = "";
    for (int i = 0; i < level; i++)
        ret += "\t\t";
    ret += car;
    ret += this->toString(true);
    ret += "\n";
    if (this->upLeft != NULL)
        ret += this->upLeft->toString(level + 1, "UpLeft: ");
    if (this->upRight != NULL)
        ret += this->upRight->toString(level + 1, "UpRight: ");
    if (this->downLeft != NULL)
        ret += this->downLeft->toString(level + 1, "DownLeft: ");
    if (this->downRight != NULL)
        ret += this->downRight->toString(level + 1, "DownRight: ");
    ret += '\n';
    return ret;
}

template <class T>
std::string NodoQUAD<T>::toString(bool unique)
{
    std::string ret = "- ";
    ret += this->data->print();
    ret += " ";
    return ret;
}

template <class T>
std::string NodoQUAD<T>::inOrder()
{
    std::string ret = "";
    if (this->upLeft != NULL)
        ret += this->upLeft->inOrder();
    if (this->upRight != NULL)
        ret += this->upRight->inOrder();
    ret += this->toString(true);
    if (this->downLeft != NULL)
        ret += this->downLeft->inOrder();
    if (this->downRight != NULL)
        ret += this->downRight->inOrder();

    return ret;
}


template <class T>
std::string NodoQUAD<T>::preOrder()
{
    std::string ret = "";
    ret += this->toString(true);
    if (this->upLeft != NULL)
        ret += this->upLeft->preOrder();
    if (this->upRight != NULL)
        ret += this->upRight->preOrder();
    if (this->downLeft != NULL)
        ret += this->downLeft->preOrder();
    if (this->downRight != NULL)
        ret += this->downRight->preOrder();
    return ret;
}

template <class T>
std::string NodoQUAD<T>::postOrder()
{
    std::string ret = "";
    if (this->upLeft != NULL)
        ret += this->upLeft->preOrder();
    if (this->upRight != NULL)
        ret += this->upRight->preOrder();
    if (this->downLeft != NULL)
        ret += this->downLeft->preOrder();
    if (this->downRight != NULL)
        ret += this->downRight->preOrder();
    ret += this->toString(true);
    return ret;
}

template <class T>
NodoQUAD<T> *NodoQUAD<T>::subMinor()
{
    NodoQUAD<T> *ret = this;
    if (!this->right)
        return ret;
    ret = this->right;
    while (ret->left)
        ret = ret->left;
    return ret;
}

template <class T>
NodoQUAD<T> *NodoQUAD<T>::subGreater()
{
    NodoQUAD<T> *ret = this;
    if (!this->left)
        return ret;
    ret = this->left;
    while (ret->right)
        ret = ret->right;
    return ret;
}

template <class T>
NodoQUAD<T> *NodoQUAD<T>::removeSubMinor()
{
    NodoQUAD<T> *ret = this;
    NodoQUAD<T> *ret2 = NULL;
    if (!this->right)
        return ret2;
    ret = this->right;
    if (!ret->left)
    {
        this->right = ret->right;
        this->data = ret->data;
        return ret;
    }
    while (ret->left->left)
        ret = ret->left;
    ret2 = ret->left;
    ret->left = NULL;
    this->data = ret2->getData();
    return ret2;
}

template <class T>
NodoQUAD<T> *NodoQUAD<T>::removeSubGreater()
{
    NodoQUAD<T> *ret = this;
    NodoQUAD<T> *ret2 = NULL;
    if (!this->left)
        return ret2;
    ret = this->left;
    if (!ret->right)
    {
        this->left = ret->left;
        this->data = ret->data;
        return ret;
    }
    while (ret->right->right)
        ret = ret->right;
    ret2 = ret->right;
    ret->right = NULL;
    this->data = ret2->getData();
    return ret2;
}
