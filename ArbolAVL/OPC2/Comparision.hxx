#include "Comparision.h"
//#include <iostream>
template <class T>
bool Comparision<T>::insertToRB(T value){
    return this->RB.insert(value).second;
}

template <class T>
bool Comparision<T>::deleteFromRB(T value){
    return this->RB.erase(value).second;
}

template <class T>
bool Comparision<T>::deleteFromAVL(T value){
    return this->AVL.removeNode(value);
}

template <class T>
bool Comparision<T>::insertToAVL(T value){
    return this->insertNode(value);
}

template <class T>
bool Comparision<T>::insertToBoth(T value){
    return this->insertToAVL(value)==this->insertToRB(value);
}

template <class T>
bool Comparision<T>::deleteFromBoth(T value){
    return this->deleteFromAVL(value)==this->deleteFromRB(value);
}

template <class T>
double Comparision<T>::insertFileDataToRB(char* file_name){
    std::clock_t t0=std::clock();
    std::ifstream in(file_name);
    const int MAX=100;
    std::string operation;
    T value;
    char* line=new char[MAX];
    char*ptr;
    if (in.is_open()){
            while (!in.eof()){
                in.getline(line, MAX, '\n');
                if (!strlen(line))
                    continue;
                else{
                    ptr=strtok(line, " ");
                    operation=ptr;
                    ptr=strtok(NULL, "\n");
                    value=ptr;
                    if (operation=="A")
                        RB.insert(value);
                    
                    else if (operation=="E")
                        RB.erase(value);
                }
            }
            in.close();
    }
    std::clock_t t1=std::clock();
    return (double(t1-t0)/CLOCKS_PER_SEC);
}

template <class T>
std::pair<double,double> Comparision<T>::insertFileDataToBoth(char* file_name){
    std::pair<double, double> times;
    times.first=this->insertFileDataToRB(file_name);
    times.second=this->insertFileDataToAVL(file_name);
    if (!this->compare())
        times.first=times.second=0;
    return times;
}    
    
template <class T>
double Comparision<T>::insertFileDataToAVL(char* file_name){
    std::clock_t t0=std::clock();
    std::ifstream in(file_name);
    const int MAX=100;
    std::string operation;
    T value;
    char* line=new char[MAX];
    char*ptr;
    if (in.is_open()){
            while (!in.eof()){
                in.getline(line, MAX, '\n');
                if (!strlen(line))
                    continue;
                else{
                    std::cout<<line<<'\n';
                    ptr=strtok(line, " ");
                    operation=ptr;
                    ptr=strtok(NULL, "\n");
                    value=ptr;
                    if (operation=="A")
                        AVL.insertNode(value);
                    
                    else if (operation=="E")
                        AVL.removeNode(value);
                }
            }
            in.close();
    }
    std::clock_t t1=std::clock();
    return (double(t1-t0)/CLOCKS_PER_SEC);
}


template <class T>
bool Comparision<T>::compare(){
    std::list<NodoAVL<T>*> lsta=this->AVL.inOrder();
    typename std::list<NodoAVL<T>*>::iterator it=lsta.begin();
    typename std::set<T>::iterator it2=this->RB.begin();
    while (it2!=RB.end() && it!=lsta.end()){
        if (*it2!=(*it)->getData())
          return 0;
        advance (it,1);
        advance (it2,1);
    }
    if (it2!=RB.end() || it!=lsta.end() || !this->AVL.balanced())
      return 0;
    return 1;
}

template <class T>
int Comparision<T>::size(){
    return this->RB.size();
}
