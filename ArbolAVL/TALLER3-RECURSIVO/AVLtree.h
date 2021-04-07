#ifndef _AVLtreeH_
#define _AVLtreeH_
#include "AVLNode.h"
template <class T>
class AVLtree
{
private:
    AVLNode<T> *root;

public:
    AVLtree();
    AVLtree(T val);
    AVLNode<T> *getRoot();
    void setRight(AVLNode<T> *);
    void setLeft(AVLNode<T> *);
    bool isEmpty();
    bool insert(T val);
    bool search(T val);
    bool deleteNode(T val);
    void print2DUtil(AVLNode<T> *root, int space);
    void print2D();
    void preOrden();
    void posOrden();
    void inOrden(std::vector<T> &l);
    int height();
};
#include "AVLtree.hxx"
#endif // _AVLtreeH_
