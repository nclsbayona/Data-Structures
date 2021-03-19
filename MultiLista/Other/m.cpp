#include <iostream>
#include <list>
using namespace std;
template <class T>
struct sMultiL{
    list<list<T>> multilista;
};
int main(){
    typedef list<list<int>>::iterator Hola;
    typedef list<int>::iterator H;
    sMultiL<int> ml;
    list<int>l;
    ml.multilista.push_back(l);
    Hola it=ml.multilista.begin();
    it->push_back(5);
    H it2=it->begin();
    cout<<*it2;
}
