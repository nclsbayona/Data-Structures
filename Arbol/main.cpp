#include <iostream>
#include <ctime> //Medir tiempo
#include "ArbolGeneral.h"
using namespace std;
int main(){
    char carac="Hola"[4];
    cout<<carac<<" ";
    cout<<(carac>0)<<'\n';
    unsigned t0, t1;
    t0=clock();
    typedef int T;
    NodoGeneral <T> *nodo1=new NodoGeneral<T>((T)100);
    NodoGeneral <T> *nodo2=new NodoGeneral<T>((T)69);
    ArbolGeneral<T> *tree=new ArbolGeneral<T>(nodo1);
    //ArbolGeneral<T> *tree=new ArbolGeneral<T>();
    list<NodoGeneral<T>*> c;
    list<NodoGeneral<T>*>::iterator it;
    NodoGeneral <T> *nodo3;
    nodo2->addChild((T)109);
    nodo2->addChild((T)110)->addChild((T)200);
    nodo1->addChild(nodo2);
    nodo1->addChild((T)159);
    nodo3=nodo2->addChild((T)190);
    NodoGeneral <T> *nodo4=nodo3->addChild((T)20);
    nodo4->addChild((T)154);
    //nodo4->addChild(nodo2);
    cout<<tree->printTree();
    cout<<"Look level node "<<nodo1->getData()<<' '<<tree->level(nodo1)<<endl;
    cout<<"Look level node 2 "<<nodo2->getData()<<' '<<tree->level(nodo2)<<endl;
    cout<<"Look level node 3 "<<nodo3->getData()<<' '<<tree->level(nodo3)<<endl;
    cout<<"Look level node X "<<tree->level(new NodoGeneral<T>((T)(200)))<<endl;
    cout<<"Path length node 3 - node 4: "<<tree->pathLength(nodo3, nodo4)<<'\n';
    cout<<"Path length node 4 - node 1: "<<tree->pathLength(nodo4, nodo1)<<'\n';
    cout<<"Path length node 1 - node 1: "<<tree->pathLength(nodo1, nodo1)<<'\n';
    cout<<"Data exists: node 2 data, node 4: "<<tree->dataExists(nodo4, nodo2->getData())<<'\n';
    cout<<"Search node data node4 data: "<<tree->searchNode(nodo4->getData())<<'\n';
    cout<<"Search node data not exists: "<<tree->searchNode(nodo4->getData()+(1))<<'\n';
    cout<<"Path node 1 - node 1 \t";
    c=tree->path(nodo1, nodo1);
    cout<<"\nHeight: "<<tree->highness()<<"\n\n";
    //nodo2->recursiveDelete();
    cout<<tree->printTree();
     cout<<"\nHeight: "<<tree->highness()<<"\n\n";
    nodo1->childRecursiveDelete(nodo2);
    cout<<tree->printTree();
    it=c.begin();
    while (it!=c.end())
        cout<<"--> "<<(*it++)->getData()<<' ';
    cout<<"\nHeight: "<<tree->highness()<<"\n\n";
    cout<<"Node 2 level "<<tree->level(tree->searchNode((T)154))<<'\n';
    list<string> lista2=tree->postOrder();
    list<string>::iterator it2=lista2.begin();
    while (it2!=lista2.end())
        cout<<"--> "<<(*it2++)<<' ';
    tree->insertNode((T)159, (T)101);
    cout<<'\n'<<tree->printTree();
    delete tree;
    cout<<"\nDeleted...";
    t1=clock();
    cout<<"\nExecution time: "<<double(t1-t0)/CLOCKS_PER_SEC<<" seconds"<<endl;
    return 0;
}
