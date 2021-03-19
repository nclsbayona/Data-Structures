#include "NodoBinarioOrdenado.h"
//#include <iostream>

template <class T>
T NodoBinarioOrdenado<T>::getData(){
    return this->data;
}

template <class T>
NodoBinarioOrdenado<T>::NodoBinarioOrdenado(T data){
    this->data=data;
}

template <class T>
NodoBinarioOrdenado<T>::~NodoBinarioOrdenado(){
    //std::cout<<"Deleting node: "<<this->data<<'\n';
    if (this->left)
        delete this->left;
    if (this->right)
        delete this->right;
}

template<class T>
NodoBinarioOrdenado<T>* NodoBinarioOrdenado<T>::getLeft(){
    return this->left;
}

template <class T>
NodoBinarioOrdenado<T>* NodoBinarioOrdenado<T>::getRight(){
    return this->right;
}

template <class T>
void NodoBinarioOrdenado<T>::setData(T data){
    this->data=data;
}

template <class T>
void NodoBinarioOrdenado<T>::setLeft(NodoBinarioOrdenado<T>* left){
    this->left=left;
}

template <class T>
void NodoBinarioOrdenado<T>::setRight(NodoBinarioOrdenado<T>* right){
    this->right=right;
}

template <class T>
int NodoBinarioOrdenado<T>::compareTo(T data){
    if(this->data>data)
        return 1;
    else if(this->data<data) 
        return-1;
    else
        return 0;
}

template <class T>
int NodoBinarioOrdenado<T>::compareTo(NodoBinarioOrdenado<T>* c){
    if(this->data>c->getData())
        return 1;
    else if(this->data<c->getData()) 
        return-1;
    else
        return 0;
}

template <class T>
std::string NodoBinarioOrdenado<T>::toString(int level, std::string car){
    std::string ret="";
    for (int i=0; i<level; i++)
        ret+="\t\t";
    ret+=car;
    ret+=this->toString(true);
    ret+="\n";
    if (this->right!=NULL)
        ret+=this->right->toString(level+1, "Right: ");
    if (this->left!=NULL)
        ret+=this->left->toString(level+1, "Left: ");
    ret+='\n';
    return ret;
}

template <class T>
std::string NodoBinarioOrdenado<T>::toString(bool unique){
    std::string ret="- ";
    ret+=this->data;
    ret+=" ";
    return ret;
}

template <class T>
std::string NodoBinarioOrdenado<T>::inOrder(){
    std::string ret="";
    if (this->left!=NULL)
        ret+=this->left->inOrder();
    ret+=this->toString(true);
    if (this->right!=NULL)
        ret+=this->right->inOrder();
    return ret;        
}

template <class T>
std::string NodoBinarioOrdenado<T>::preOrder(){
    std::string ret="";    
    ret+=this->toString(true);
    if (this->left!=NULL)
        ret+=this->left->preOrder();
    if (this->right!=NULL)
        ret+=this->right->preOrder();
    return ret;        
}

template <class T>
std::string NodoBinarioOrdenado<T>::postOrder(){
    std::string ret="";
    if (this->left!=NULL)
        ret+=this->left->postOrder();
    if (this->right!=NULL)
        ret+=this->right->postOrder();
    ret+=this->toString(true);
    return ret;        
}

template <class T>
NodoBinarioOrdenado<T>* NodoBinarioOrdenado<T>::subMinor(){
    NodoBinarioOrdenado<T>* ret=this;
    if (!this->right)
        return ret;
    ret=this->right;
    while (ret->left)
        ret=ret->left;
    return ret;        
}

template <class T>
NodoBinarioOrdenado<T>* NodoBinarioOrdenado<T>::subGreater(){
    NodoBinarioOrdenado<T>* ret=this;
    if (!this->left)
        return ret;
    ret=this->left;
    while (ret->right)
        ret=ret->right;
    return ret; 
}

template <class T>
NodoBinarioOrdenado<T>* NodoBinarioOrdenado<T>::removeSubMinor(){
    NodoBinarioOrdenado<T>* ret=this;
    NodoBinarioOrdenado<T>* ret2=NULL;
    if (!this->right)
        return ret2;
    ret=this->right;
    if (!ret->left){
        this->right=ret->right;
        this->data=ret->data;
        return ret;
    }
    while (ret->left->left)
        ret=ret->left;
    ret2=ret->left;
    ret->left=NULL;
    this->data=ret2->getData();
    return ret2;     
}

template <class T>
NodoBinarioOrdenado<T>* NodoBinarioOrdenado<T>::removeSubGreater(){
    NodoBinarioOrdenado<T>* ret=this;
    NodoBinarioOrdenado<T>* ret2=NULL;
    if (!this->left)
        return ret2;
    ret=this->left;
    if (!ret->right){
        this->left=ret->left;
        this->data=ret->data;
        return ret;
    }
    while (ret->right->right)
        ret=ret->right;
    ret2=ret->right;
    ret->right=NULL;
    this->data=ret2->getData();
    return ret2;
}
