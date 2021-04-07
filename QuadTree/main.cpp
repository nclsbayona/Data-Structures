#include "ArboLQUAD.h"
#include <iostream>
using namespace std;
int main(){
    typedef unsigned char T;
    ArbolQUAD<T>* arbol=new ArbolQUAD<T>((T)(85), (T)(80));
    NodoQUAD<T>* left=new NodoQUAD<T>((T)(80), (T)(80));
    NodoQUAD<T>* right1=new NodoQUAD<T>((T)(80), (T)(90));
    NodoQUAD<T>* right2=new NodoQUAD<T>((T)(82), (T)(85));
    arbol->insertNode(left);
    arbol->insertNode(right1);
    arbol->insertNode(right2);
    arbol->insertNode((T)(70), (T)(80));
    arbol->insertNode((T)(115), (T)(80));
    arbol->insertNode((T)(122), (T)(80));
    arbol->insertNode((T)(87), (T)(80));
    cout<<'\n'<<'\n'<<arbol->printTree();
    /*cout<<arbol->inOrder()<<'\n';
    arbol->removeNode(right1);
    cout<<'\n'<<'\n'<<arbol->printTree();
    cout<<arbol->inOrder()<<'\n'<<"Para eliminar: "<<left->getData();
    if(!arbol->removeNode(left))
        cout<<"\nBut nothing happened...\n";
    cout<<'\n'<<'\n'<<arbol->printTree();
    cout<<arbol->inOrder()<<'\n';
    if(!arbol->removeNode(left))
        cout<<"\nBut nothing happened...\n";
    cout<<'\n'<<'\n'<<arbol->printTree();
    cout<<arbol->inOrder()<<'\n';
    if(!arbol->removeNode(right1))
        cout<<"\nBut nothing happened...\n";
    cout<<'\n'<<'\n'<<arbol->printTree();
    if(!arbol->removeNode(left))
        cout<<"\nBut nothing happened...\n";
    cout<<'\n'<<'\n'<<arbol->printTree();
    cout<<arbol->inOrder()<<'\n';
    if(!arbol->removeNode(arbol->getHead()))
        cout<<"\nBut nothing happened...\n";
    cout<<'\n'<<'\n'<<arbol->printTree();
    cout<<arbol->inOrder()<<'\n';*/
    delete arbol;
    return 0;
}
