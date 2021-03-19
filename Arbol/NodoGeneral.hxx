#include "NodoGeneral.h"
//#include <iostream>
template <class T>
NodoGeneral<T>::NodoGeneral(T data){
    this->setData(data);
}

template <class T>
NodoGeneral<T>::~NodoGeneral(){
    //std::cout<<"Nodo: "<<this->getData()<<'\n';
}

template <class T>
void NodoGeneral<T>::recursiveDelete(){
    if (!this->children.size())
        delete this;
    else{
        typename std::list<NodoGeneral<T>*>::iterator it=this->children.begin();
        typename std::list<NodoGeneral<T>*>::iterator it2=this->children.end();
        NodoGeneral<T>* ptr;
        for (; it!=it2; it++){
            ptr=(*it);
            if(ptr->children.size()){
                ptr->recursiveDelete();
            }
            delete ptr;
        }
        this->children.clear();
    }
}

template <class T>
void NodoGeneral<T>::childRecursiveDelete(NodoGeneral<T>* node){
    if (!this->children.size())
        delete this;
    else{
        bool del=false;
        typename std::list<NodoGeneral<T>*>::iterator it=this->children.begin();
        typename std::list<NodoGeneral<T>*>::iterator it2=this->children.end();
        NodoGeneral<T>* ptr;
        for (; it!=it2 && !del; it++){
            ptr=(*it);
            if (ptr!=node)
                continue;
            del=true;
            if(ptr->children.size()){
                ptr->recursiveDelete();
            }
        }
        if (del){
            delete ptr;
            advance (it, -1);
            this->children.erase(it);
        }
    }
}

template <typename T>
T NodoGeneral<T>::getData(){
    return this->data;
}

template <typename T>
void NodoGeneral<T>::setData(T data){
    this->data=data;
}

template <typename T>
std::list<NodoGeneral<T>*> NodoGeneral<T>::getChildren(){
    return this->children;
}

template <typename T>
void NodoGeneral<T>::setChildren (std::list<NodoGeneral<T>*> children){
    this->children=children;
}

template <typename T>
NodoGeneral<T>* NodoGeneral<T>::addChild(NodoGeneral<T>* child){
    try{
        this->children.push_back(child);
    }catch(...){
        child=NULL;
    }
    return child;
}

template <typename T>
NodoGeneral<T>* NodoGeneral<T>::addChild(T data){
    NodoGeneral<T>* child;
    try{
        child=new NodoGeneral<T> (data);
        this->children.push_back(child);
    }catch(...){
        child=NULL;
    }
    return child;
}

template <class T>
std::string NodoGeneral<T>::print(int level){
    std::string ch="";
    std::list<NodoGeneral<T>*> c=this->getChildren();
    std::string tab="";
    for( int i=0; i<level; ++i )
        tab+="\t";
    ch+=tab+" --> "+std::to_string(this->getData())+"\n";
/*
    typedef (typename T) tipe;
    if (tipe == (int|double|float))
        ch+=tab+"Nodo: "+std::to_string(this->getData())+"\n";
    else
        ch+=tab+"Nodo: "+this->getData()+"\n";
*/
    if (!c.size())
        return ch;
    typename std::list<NodoGeneral<T>*>::iterator it;
    for (it=c.begin(); it!=c.end(); it++){
        ch+=((*it)->print(level+1));
    }
    return ch;
}

template <class T>
bool NodoGeneral<T>::leaf(){
    return !this->children.empty();
}
