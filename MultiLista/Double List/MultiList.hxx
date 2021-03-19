#include <iostream>
#include <list>
#include <iostream>
#include "MultiList.h"
template <class T>
bool MultiList<T>::addList(list<T> l){
    bool added=true;
    try{
        multilist.push_back(l);
    }catch(...){
        added=false;
    }
    return added;
}
template <class T>
bool MultiList<T>::addList(){
    bool added=true;
    try{
        list <T> l;
        multilist.push_back(l);
    }catch(...){
        added=false;
    }
    return added;
}
template <class T>
bool MultiList<T>::addElement(typename list<list<T>>::iterator it, T value){
    it->push_back(value);
    return true;
}
