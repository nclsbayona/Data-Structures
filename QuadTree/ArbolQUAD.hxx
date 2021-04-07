#include "ArboLQUAD.h"
#include <iostream>

template <class T>
ArbolQUAD<T>::ArbolQUAD(T data1, T data2)
{
    this->head = new NodoQUAD<T>(data1, data2);
}

template <class T>
ArbolQUAD<T>::~ArbolQUAD()
{
    delete this->head;
}

template <class T>
NodoQUAD<T> *ArbolQUAD<T>::getHead()
{
    return this->head;
}

template <class T>
void ArbolQUAD<T>::setHead(NodoQUAD<T> *head)
{
    this->head = head;
}

template <class T>
bool ArbolQUAD<T>::insertNodeR(NodoQUAD<T> *toCompare, NodoQUAD<T> *node)
{
    NodoQUAD<T> *ft;
    std::cout<<node->toString(true)<<' '<<toCompare->toString(true);
    int cmp = toCompare->compareTo(node);
    std::cout<<cmp<<'\n';
    if (cmp == -2)
    {
        ft = toCompare->getDownLeft();
        if (!ft)
        {
            toCompare->setDownLeft(node);
            return true;
        }
        else
            return this->insertNodeR(ft, node);
    }
    else if (cmp == -1)
    {
        ft = toCompare->getDownRight();
        if (!ft)
        {
            toCompare->setDownRight(node);
            return true;
        }
        else
            return this->insertNodeR(ft, node);
    }

    else if (cmp == 1)
    {
        ft = toCompare->getUpLeft();
        if (!ft)
        {
            toCompare->setUpLeft(node);
            return true;
        }
        else
            return this->insertNodeR(ft, node);
    }

    else if (cmp == 2)
    {
        ft = toCompare->getUpRight();
        if (!ft)
        {
            toCompare->setUpRight(node);
            return true;
        }
        else
            return this->insertNodeR(ft, node);
    }
    return false;
}

template <class T>
NodoQUAD<T> *ArbolQUAD<T>::insertNode(NodoQUAD<T> *node)
{
    if (this->insertNodeR(this->head, node))
        return node;
    else
        return NULL;
}

template <class T>
NodoQUAD<T> *ArbolQUAD<T>::insertNode(T data1, T data2)
{
    NodoQUAD<T> *c = new NodoQUAD<T>(data1, data2);
    std::cout<<this->insertNodeR(this->head, c)<<'\n';
    if (this->insertNodeR(this->head, c))
        return c;
    else
        return NULL;
}

template <class T>
NodoQUAD<T> *ArbolQUAD<T>::removeNodeMinor(NodoQUAD<T> *node)
{
    return node->removeSubMinor();
}

template <class T>
NodoQUAD<T> *ArbolQUAD<T>::removeNodeGreater(NodoQUAD<T> *node)
{
    return node->removeSubGreater();
}

template <class T>
NodoQUAD<T> *ArbolQUAD<T>::searchNode(NodoQUAD<T> *searching)
{
    if (this->head == searching)
        return this->head;
    return this->searchNodeR(this->head, searching);
}

template <class T>
NodoQUAD<T> *ArbolQUAD<T>::searchNodeR(NodoQUAD<T> *node, NodoQUAD<T> *searching)
{
    NodoQUAD<T> *ft = NULL;
    int cmp = node->compareTo(searching);
    if (cmp == -2)
    {
        ft = node->getDownLeft();
        if (!ft)
            return ft;
        else
            return this->searchNodeR(ft, searching);
    }
    else if (cmp == -1)
    {
        ft = node->getDownRight();
        if (!ft)
            return ft;
        else
            return this->searchNodeR(ft, searching);
    }

    else if (cmp == 1)
    {
        ft = node->getUpLeft();
        if (!ft)
            return ft;
        else
            return this->searchNodeR(ft, searching);
    }

    else if (cmp == 2)
    {
        ft = node->getUpRight();
        if (!ft)
            return ft;
        else
            return this->searchNodeR(ft, searching);
    }

    return ft;
}

template <class T>
bool ArbolQUAD<T>::removeNode(NodoQUAD<T> *node)
{
    if (!(node->getRight() || node->getLeft()))
    {
        NodoQUAD<T> *padre = this->searchNode(node);
        if (padre->getRight() == node)
            padre->setRight(NULL);
        else
            padre->setLeft(NULL);
        delete node;
    }
    else if ((!node->getRight()) && (node->getLeft()))
        this->removeNodeGreater(node);
    else
        this->removeNodeMinor(node);
    return true;
}

template <class T>
std::string ArbolQUAD<T>::printTree()
{
    if (this->head)
        return "Tree\n" + this->head->toString() + "\n";
    else
        return " ";
}
/*
template <class T>
std::string ArbolQUAD<T>::inOrder(){
    return this->head->inOrder();        
}

template <class T>
std::string ArbolQUAD<T>::preOrder(){
    return this->head->preOrder();        
}

template <class T>
std::string ArbolQUAD<T>::postOrder(){
    return this->head->postOrder();        
}

template <class T>
std::string ArbolQUAD<T>::levelOrder(){
    NodoQUAD<T>* left;
    NodoQUAD<T>* right;
    std::vector<NodoQUAD<T>*> nextLevel;
    std::string levels="";
    if (!nextLevel.empty())
        nextLevel.clear();
    nextLevel.push_back(this->head);
    for (typename std::vector<NodoQUAD<T>*>::iterator it=nextLevel.begin(); it!=nextLevel.end(); it++){
        if (*it!=NULL){
            levels+=(*it)->toString(true);
            left=(*it)->getLeft();
            right=(*it)->getRight();
            if (left){
                nextLevel.push_back(left);
            }
            if (right){
                nextLevel.push_back(right);
            }
        }
    }
    return levels;
}
*/
