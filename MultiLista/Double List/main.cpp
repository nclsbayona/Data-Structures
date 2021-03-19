#include <iostream>
#include <iomanip>
#include "MultiList.h"
int main(){
    typedef double W;
    typedef list<list<W>>::iterator Iterator;
    typedef list<W>::iterator Iterator2;
    W el=(W)(67);
    W el2=(W)(69);
    MultiList<W> ml;
    list <W> l;
    ml.addList(l);
    ml.addList();    
    Iterator it=ml.getIterator(), ite=ml.getIteratorEnd();
    ml.addElement(it, el);
    ml.addElement(++it, el2);
    Iterator2 it2;
    it=ml.getIterator();
    while (it!=ite){
        std::cout<<&it<<setw(5)<<' ';
        it2=it->begin();
        while (it2!=it->end())
            std::cout<<*it2++;
        advance (it, 1);
        printf("\n");
    }
    return 0;
}
