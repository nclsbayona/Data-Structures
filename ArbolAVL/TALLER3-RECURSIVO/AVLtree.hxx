#include "AVLtree.h"
#include <iostream>
#define COUNT 10
template <class T>
AVLtree<T>::AVLtree()
{
    this->root = nullptr;
}
template <class T>
AVLtree<T>::AVLtree(T val)
{
    AVLNode<T> aux(val);
    this->root = aux;
}
template <class T>
AVLNode<T> *AVLtree<T>::getRoot()
{
    return this->root;
}
template <class T>
void AVLtree<T>::setRight(AVLNode<T> *right)
{
    this->root->setRight(right);
}
template <class T>
void AVLtree<T>::setLeft(AVLNode<T> *left)
{
    this->root->setLeft(left);
}
template <class T>
bool AVLtree<T>::isEmpty()
{
    return true ? this->root == nullptr : false;
}
template <class T>
bool AVLtree<T>::insert(T val)
{
    bool rt = this->root->insert(&this->root, val);
    this->root = this->root->balance(this->root);
    return rt;
}
template <class T>
bool AVLtree<T>::search(T val)
{
    return this->root->search(this->root, val);
}
template <class T>
bool AVLtree<T>::deleteNode(T val)
{
    bool rt = false;
    if (this->root != nullptr)
    {
        rt = this->root->deleteNode(&this->root, val);
        this->root = this->root->balance(this->root);
    }
    return rt;
}
// Function to print binary tree in 2D
// It does reverse inorder traversal
template <class T>
void AVLtree<T>::print2DUtil(AVLNode<T> *root, int space)
{
    // Base case
    if (root == NULL)
        return;

    // Increase distance between levels
    space += COUNT;

    // Process right child first
    print2DUtil(root->getRight(), space);

    // Print current node after space
    // count
    std::cout << std::endl;
    for (int i = COUNT; i < space; i++)
        std::cout << " ";
    std::cout << root->getData() << "\n";

    // Process left child
    print2DUtil(root->getLeft(), space);
}
template <class T>
void AVLtree<T>::print2D()
{
    this->print2DUtil(this->root, COUNT);
}
template <class T>
void AVLtree<T>::preOrden()
{
    this->root->preOrden(this->root);
}
template <class T>
void AVLtree<T>::posOrden()
{
    this->root->posOrden(this->root);
}
template <class T>
void AVLtree<T>::inOrden(std::vector<T> &v)
{
    this->root->inOrden(this->root,v);
}
template <class T>
int AVLtree<T>::height()
{
    if (this->isEmpty())
        return -1;
    else
        return this->root->height(this->root);
}
