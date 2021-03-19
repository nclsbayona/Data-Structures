#include "ArbolBinarioOrdenado.h"
#include <iostream>
using namespace std;
int main(){
    typedef unsigned char T;
    ArbolBinarioOrdenado<T>* arbol=new ArbolBinarioOrdenado<T>((T)(85));
    NodoBinarioOrdenado<T>* left=new NodoBinarioOrdenado<T>((T)(80));
    NodoBinarioOrdenado<T>* right1=new NodoBinarioOrdenado<T>((T)(90));
    NodoBinarioOrdenado<T>* right2=new NodoBinarioOrdenado<T>((T)(82));
    arbol->insertNode(left);
    arbol->insertNode(right1);
    arbol->insertNode(right2);
    arbol->insertNode((T)(70));
    arbol->insertNode((T)(115));
    arbol->insertNode((T)(122));
    arbol->insertNode((T)(87));
    cout<<'\n'<<'\n'<<arbol->printTree();
    cout<<arbol->inOrder()<<'\n';
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
    cout<<arbol->inOrder()<<'\n';
    delete arbol;
    return 0;
}
