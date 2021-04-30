#include <iostream>
#include "ArbolQUAD.h"
using namespace std;
int main(int argc, char **argv)
{
    if (argc>=3){
        typedef std::list<NodoQUAD*> lista;
        lista c;
        ArbolQUAD* arbol = new ArbolQUAD(argv[1], argv[2]);
        cout<<arbol->getSize()<<" VS "<<arbol->realSize()<<'\n';
        if(arbol->equals()){
            cout<<arbol->printTree();
            cout<<"'\n";
            arbol->convertToPBM();
        }
        else
            cout<<"Not equals\n";
        delete arbol;
    }
    else
        cout<<"Missing arguments\n";
    cout<<"Fin\n";
    return 0;
}