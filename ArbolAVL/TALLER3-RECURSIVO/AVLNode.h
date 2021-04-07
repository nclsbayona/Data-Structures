#ifndef _AVLNodeH_
#define _AVLNodeH_
#include <vector>
template <class T>
class AVLNode
{
private:
    T data;
    AVLNode<T> *left;
    AVLNode<T> *right;

public:
    ~AVLNode();
    AVLNode(T val);
    T getData();
    void setData(T val);
    AVLNode<T> *getRight();
    AVLNode<T> *getLeft();
    void setRight(AVLNode<T> *);
    void setLeft(AVLNode<T> *);
    bool isLeafNode();
    AVLNode<T> *search(AVLNode<T> *, T val);
    bool insert(AVLNode<T> **current, T val);
    bool deleteNode(AVLNode<T> **current, T val);
    AVLNode<T> *findMax(AVLNode<T> *);
    AVLNode<T> *findMin(AVLNode<T> *);
    void preOrden(AVLNode<T> *);
    void posOrden(AVLNode<T> *);
    void inOrden(AVLNode<T> *, std::vector<T> &v);
    int height(AVLNode<T> *);
    int difference(AVLNode<T> *);
    AVLNode<T> *balance(AVLNode<T> *);
    AVLNode<T> *leftRotation(AVLNode<T> *ct);
    AVLNode<T> *rightRotation(AVLNode<T> *ct);
    AVLNode<T> *LRRotation(AVLNode<T> *ct);
    AVLNode<T> *RLRotation(AVLNode<T> *ct);
    AVLNode<T> *LLRotation(AVLNode<T> *ct);
    AVLNode<T> *RRRotation(AVLNode<T> *ct);
};
#include "AVLNode.hxx"
#endif // _AVLNodeH_
