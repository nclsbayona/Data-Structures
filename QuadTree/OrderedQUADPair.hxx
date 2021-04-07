#include "OrderedQUADPair.h"

template <class T>
OrderedQUADPair<T>::OrderedQUADPair(T data1, T data2){
    this->data1=data1;
    this->data2=data2;
}

template <class T>
OrderedQUADPair<T>::~OrderedQUADPair(){
    delete this;
}

template <class T>
T OrderedQUADPair<T>::getData1(){
    return this->data1;
}

template <class T>
T OrderedQUADPair<T>::getData2(){
    return this->data2;
}

template <class T>
void OrderedQUADPair<T>::setData1 (T data){
    this->data1=data;
}

template <class T>
void OrderedQUADPair<T>::setData2 (T data){
    this->data2=data;
}

template <class T>
std::pair<T, T> OrderedQUADPair<T>::getData(){
    return (*(new std::pair<T,T>* (this->data1, this->data2)));
}

template <class T>
std::string OrderedQUADPair<T>::print(){
    std::string ret="(";
    ret+=std::to_string(this->data1);
    ret+=", ";
    ret+=std::to_string(this->data2);
    ret+=")";
    return ret;
}