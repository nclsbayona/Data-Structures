#ifndef _MULTILIST_H_
#define _MULTILIST_H_
#include <list>
#include <iostream>
using namespace std;
template <class T>
class MultiList{
    public:
        void exit(){std::exit(0);};
        bool addList(list<T> l);
        bool addList();
        bool addElement(typename list<list<T>>::iterator it, T value);
        typename list<list<T>>::iterator getIterator(){return this->multilist.begin();};
        typename list<list<T>>::iterator getIteratorEnd(){return this->multilist.end();};
        private:
        list <list<T>> multilist;
};
#include "MultiList.hxx"
#endif
