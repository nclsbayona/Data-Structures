#include "AVLNode.h"
#include <iostream>
template <class T>
AVLNode<T>::~AVLNode()
{
    delete left;
    delete right;
}
template <class T>
AVLNode<T>::AVLNode(T val)
{
    this->data = val;
    this->left = nullptr;
    this->right = nullptr;
}
template <class T>
T AVLNode<T>::getData()
{
    return this->data;
}
template <class T>
void AVLNode<T>::setData(T val)
{
    this->data = val;
}
template <class T>
AVLNode<T> *AVLNode<T>::getLeft()
{
    return this->left;
}
template <class T>
void AVLNode<T>::setRight(AVLNode<T> *right)
{
    this->right = right;
}
template <class T>
AVLNode<T> *AVLNode<T>::getRight()
{
    return this->right;
}
template <class T>
void AVLNode<T>::setLeft(AVLNode<T> *left)
{
    this->left = left;
}
template <class T>
bool AVLNode<T>::isLeafNode()
{
    return true ? (this->left == nullptr && this->right == nullptr) : false;
}
template <class T>
AVLNode<T> *AVLNode<T>::search(AVLNode<T> *node, T val)
{
    AVLNode<T> *rt = nullptr;
    AVLNode<T> *pnt = node;
    if (pnt != nullptr && rt == nullptr)
    {
        if (pnt->data == val)
            rt = pnt;
        else if (pnt->data < val)
            rt = this->search(pnt->right, val);
        else
            rt = this->search(pnt->left, val);
    }
    return rt;
}
template <class T>
bool AVLNode<T>::insert(AVLNode<T> **current, T val)
{
    bool rt = false;
    AVLNode<T> *ct = *current;
    if (*current == nullptr)
    {
        *current = new AVLNode<T>(val);
        rt = true;
    }
    else if (!rt)
    {
        if (ct->data == val)
            return false;
        else if (ct->data < val)
            rt = ct->insert(&ct->right, val);
        else
            rt = ct->insert(&ct->left, val);
    }
    return rt;
}
template <class T>
bool AVLNode<T>::deleteNode(AVLNode<T> **current, T val)
{
    bool rt = false;
    AVLNode<T> *ct = *current;
    if (ct != nullptr)
    {
        if (ct->data == val)
        {
            if (ct->left == nullptr && ct->right == nullptr)
            {

                rt = true;
                *current = nullptr;
            }
            else if (ct->left != nullptr && ct->right != nullptr)
            {
                AVLNode<T> *max = ct->left->findMax(ct->left);
                ct->data = max->data;
                if (ct->left->deleteNode(&ct->left, max->data))
                {
                    *current = ct;
                    rt = true;
                }
            }
            else
            {
                AVLNode<T> *pnt;
                if (ct->left != nullptr)
                    pnt = ct->left;
                else
                    pnt = ct->right;
                *current = pnt;
            }
        }
        else
        {
            if (ct->data < val)
                rt = this->deleteNode(&ct->right, val);
            else
                rt = this->deleteNode(&ct->left, val);
        }
    }
    return rt;
}
template <class T>
AVLNode<T> *AVLNode<T>::findMax(AVLNode<T> *ct)
{
    AVLNode<T> *pt = nullptr;
    while (ct != nullptr)
    {
        pt = ct;
        ct = ct->right;
    }
    return pt;
}
template <class T>
AVLNode<T> *AVLNode<T>::findMin(AVLNode<T> *ct)
{
    AVLNode<T> *pt = nullptr;
    while (ct != nullptr)
    {
        pt = ct;
        ct = ct->left;
    }
    return pt;
}
template <class T>
void AVLNode<T>::preOrden(AVLNode<T> *ct)
{
    if (ct != nullptr)
    {
        std::cout << ct->data << " - ";
        this->preOrden(ct->left);
        this->preOrden(ct->right);
    }
}
template <class T>
void AVLNode<T>::posOrden(AVLNode<T> *ct)
{
    if (ct != nullptr)
    {
        this->posOrden(ct->left);
        this->posOrden(ct->right);
        std::cout << ct->data << " - ";
    }
}
template <class T>
void AVLNode<T>::inOrden(AVLNode<T> *ct, std::vector<T> &v)
{
    if (ct != nullptr)
    {
        this->inOrden(ct->left, v);
        v.push_back(ct->data);
        this->inOrden(ct->right,v);
    }
}
template <class T>
int AVLNode<T>::height(AVLNode<T> *current)
{
    AVLNode<T> *ct = current;
    if (ct == nullptr)
        return -1;
    else
    {
        int leftH = this->height(ct->left);
        int rightH = this->height(ct->right);

        if (leftH < rightH)
            return rightH + 1;
        else
            return leftH + 1;
    }
}
template <class T>
int AVLNode<T>::difference(AVLNode<T> *ct)
{
    return ct->left->height(ct->left) - ct->right->height(ct->right);
}
template <class T>
AVLNode<T> *AVLNode<T>::balance(AVLNode<T> *ct)
{
    if (ct != nullptr)
    {
        int dif = this->difference(ct);
        if (dif > 1)
        {

            if (this->difference(ct->left) > 0)
                ct = LLRotation(ct);
            else
                ct = LRRotation(ct);
        }
        else if (dif < -1)
        {
            if (this->difference(ct->right) > 0)
                ct = RLRotation(ct);
            else
                ct = RRRotation(ct);
        }
    }
    return ct;
}
template <class T>
AVLNode<T> *AVLNode<T>::leftRotation(AVLNode<T> *ct)
{
    AVLNode<T> *tmp;
    tmp = ct->right;
    ct->right = tmp->left;
    tmp->left = ct;
    return tmp;
}
template <class T>
AVLNode<T> *AVLNode<T>::rightRotation(AVLNode<T> *ct)
{
    AVLNode<T> *tmp;
    tmp = ct->left;
    ct->left = tmp->right;
    tmp->right = ct;
    return tmp;
}
template <class T>
AVLNode<T> *AVLNode<T>::LRRotation(AVLNode<T> *ct)
{
    AVLNode<T> *aux;
    aux = ct->left;
    ct->left = this->RRRotation(aux);
    return this->LLRotation(ct);
}
template <class T>
AVLNode<T> *AVLNode<T>::RLRotation(AVLNode<T> *ct)
{
    AVLNode<T> *aux;
    aux = ct->right;
    ct->right = this->LLRotation(aux);
    return this->RRRotation(ct);
}
template <class T>
AVLNode<T> *AVLNode<T>::LLRotation(AVLNode<T> *ct)
{
    AVLNode<T> *aux;
    aux = ct->left;
    ct->left = aux->right;
    aux->right = ct;
    return aux;
}
template <class T>
AVLNode<T> *AVLNode<T>::RRRotation(AVLNode<T> *ct)
{

    AVLNode<T> *aux;
    aux = ct->right;
    ct->right = aux->left;
    aux->left = ct;
    return aux;
}