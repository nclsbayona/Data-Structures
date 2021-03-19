#include "ArbolAVL.h"
#include <iostream>
using namespace std;
int main(){
    typedef unsigned char T;
    NodoAVL<T>* head=new NodoAVL<T>((T)(85));
    ArbolAVL<T>* arbol=new ArbolAVL<T>(head);
    NodoAVL<T>* left=new NodoAVL<T>((T)(80));
    NodoAVL<T>* right1=new NodoAVL<T>((T)(90));
    NodoAVL<T>* right2=new NodoAVL<T>((T)(82));
    NodoAVL<T>* right3=new NodoAVL<T>((T)(15));
    //arbol->insertNode(left);
    arbol->insertNode((T)(110));
    arbol->insertNode((T)(105));
    arbol->insertNode((T)(107));
    arbol->insertNode((T)(114));
    arbol->insertNode((T)(116));
    arbol->insertNode((T)(100));
    arbol->insertNode((T)(122));
    //arbol->insertNode((T)(120));
    arbol->insertNode(right2);
    //arbol->insertNode(right1);
    //arbol->insertNode(right3);
    NodoAVL<T>* ft=arbol->searchNodeFather((T)(15));
    cout<<"\nBusqueda en arbol padre "<<head->getData()<<": "<<(arbol->searchNodeFather(arbol->getHead()))->getData();
    cout<<"\nEliminando nodo \'"<<((T)(15))<<"\': "<<arbol->removeNode((T)(15))<<'\n'<<arbol->printTree();
    cout<<"\nEliminando nodo "<<right2->toString(true)<<": "<<arbol->removeNode(right2)<<'\n'<<arbol->printTree();
    head=arbol->getHead();
    cout<<"\nBalanceado"<<": "<<(arbol->balanced());
    cout<<"\nHead "<<arbol->getHead()->toString(true)<<"\n";
    cout<<"\nBalanceado"<<": "<<(arbol->balanced());
    cout<<'\n'<<"Impresion\n"<<arbol->printTree()<<"\nIn order: "<<arbol->inOrder();
    cout<<"\nPre order: "<<arbol->preOrder();
    cout<<"\nPost order: "<<arbol->postOrder();
    cout<<"\nLevel order: "<<arbol->levelOrder();
    cout<<'\n'<<arbol->printTree();
    cout<<"\nAltura "<<left->getData()<<": "<<left->height();
    cout<<"\nAltura arbol: "<<arbol->height();
    return 0;
}
