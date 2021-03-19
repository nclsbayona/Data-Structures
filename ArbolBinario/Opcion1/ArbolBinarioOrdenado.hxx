#include "ArbolBinarioOrdenado.h"

template <class T>
ArbolBinarioOrdenado<T>::ArbolBinarioOrdenado(T data){
    this->head=new NodoBinarioOrdenado<T>(data);
}

template <class T>
ArbolBinarioOrdenado<T>::~ArbolBinarioOrdenado(){
    delete this->head;
}
        
template <class T>
NodoBinarioOrdenado<T>* ArbolBinarioOrdenado<T>::getHead(){
    return this->head;
}

template <class T>
void ArbolBinarioOrdenado<T>::setHead(NodoBinarioOrdenado<T>* head){
    this->head=head;
}

template <class T>
NodoBinarioOrdenado<T>* ArbolBinarioOrdenado<T>::insertNode(NodoBinarioOrdenado<T>* node){
    if (this->insertNode(this->head, node))
        return node;
    else
        return NULL;
}

template <class T>
bool ArbolBinarioOrdenado<T>::insertNode(NodoBinarioOrdenado<T>* toCompare, NodoBinarioOrdenado<T>* node){
    if (!toCompare->compareTo(node))
        return false;
    else if (toCompare->getLeft()==NULL && toCompare->compareTo(node)>0){
        toCompare->setLeft(node);
        return true;
    }
    else if (toCompare->getRight()==NULL && toCompare->compareTo(node)<0){
        toCompare->setRight(node);
        return true;
    }
    else{
        if(toCompare->compareTo(node)>0)
            return this->insertNode(toCompare->getLeft(), node);
        else if(toCompare->compareTo(node)<0)
            return this->insertNode(toCompare->getRight(), node);
    }
    return false;
}

template <class T>
NodoBinarioOrdenado<T>* ArbolBinarioOrdenado<T>::insertNode(T node){
    NodoBinarioOrdenado<T>* c=new NodoBinarioOrdenado<T>(node);
    if (this->insertNode(this->head, c))
        return c;
    else
        return NULL;
}

template <class T>
NodoBinarioOrdenado<T>* ArbolBinarioOrdenado<T>::removeNodeMinor(NodoBinarioOrdenado<T>* node){
    return node->removeSubMinor();
}

template <class T>
NodoBinarioOrdenado<T>* ArbolBinarioOrdenado<T>::removeNodeGreater(NodoBinarioOrdenado<T>* node){
    return node->removeSubGreater();
}

template <class T>
NodoBinarioOrdenado<T>* ArbolBinarioOrdenado<T>::searchNode(NodoBinarioOrdenado<T>* searching){
    if (this->head==searching)
        return this->head;
    return this->searchNodeR(this->head, searching);
}

template <class T>
NodoBinarioOrdenado<T>* ArbolBinarioOrdenado<T>::searchNodeR(NodoBinarioOrdenado<T>* node, NodoBinarioOrdenado<T>* searching){
    if (node->getLeft()==searching||node->getRight()==searching)
        return node;
    if (!node->getLeft()&&!node->getRight())
        return NULL;
    if (!node->getLeft()&&node->getRight()!=searching)
        return this->searchNodeR(node->getRight(), searching);
    if (node->getLeft()!=searching&&!node->getRight())
        return this->searchNodeR(node->getLeft(), searching);
    NodoBinarioOrdenado<T>* nodo=NULL;
    nodo=this->searchNodeR(node->getLeft(), searching);
    if (!nodo)
        nodo=this->searchNodeR(node->getLeft(), searching);
    return nodo;
}

template <class T>
bool ArbolBinarioOrdenado<T>::removeNode(NodoBinarioOrdenado<T>* node){
    if (!(node->getRight()||node->getLeft())){
        NodoBinarioOrdenado<T>*padre=this->searchNode(node);
        if (padre->getRight()==node)
            padre->setRight(NULL);
        else
            padre->setLeft(NULL);
        delete node;
    }
    else if ((!node->getRight())&&(node->getLeft()))
        this->removeNodeGreater(node);
    else
        this->removeNodeMinor(node);
    return true;
}
template <class T>
std::string ArbolBinarioOrdenado<T>::printTree(){
    if (this->head)
        return "Tree\n"+this->head->toString()+"\n";
    else
        return " ";
}

template <class T>
std::string ArbolBinarioOrdenado<T>::inOrder(){
    return this->head->inOrder();        
}

template <class T>
std::string ArbolBinarioOrdenado<T>::preOrder(){
    return this->head->preOrder();        
}

template <class T>
std::string ArbolBinarioOrdenado<T>::postOrder(){
    return this->head->postOrder();        
}

template <class T>
std::string ArbolBinarioOrdenado<T>::levelOrder(){
    NodoBinarioOrdenado<T>* left;
    NodoBinarioOrdenado<T>* right;
    std::vector<NodoBinarioOrdenado<T>*> nextLevel;
    std::string levels="";
    if (!nextLevel.empty())
        nextLevel.clear();
    nextLevel.push_back(this->head);
    for (typename std::vector<NodoBinarioOrdenado<T>*>::iterator it=nextLevel.begin(); it!=nextLevel.end(); it++){
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
