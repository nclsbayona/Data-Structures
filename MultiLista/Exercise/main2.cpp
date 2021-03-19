#include "Universidad.h"
#include <iostream>
using namespace std;
int main(){
    list<Facultad>::iterator it;
    string nombre, n_facultad, n_carrera;
    char opc='s', opc2;
    int cant_estudiantes, a=0;
    Universidad *u;
    cout<<"Nombre U: ";
    getline(cin, nombre, '\n');
    u=new Universidad(nombre);
    while (opc=='s'){
        cin.ignore();
        cout<<"Nombre facultad ";
        getline(cin, n_facultad, '\n');
        a+=u->addFacultad(n_facultad);
        opc2='s';
        it=u->getIterator();
        advance(it, a++);
        while(opc2=='s'){
            cin.ignore();
            cout<<"Nombre carrera ";
            getline(cin, n_carrera, '\n');
            cout<<"Numero estudiantes ";
            cin>>cant_estudiantes;
            it->addCarrera(n_carrera, cant_estudiantes);
            cout<<"Otra carrera (s/n) ";
            cin>>opc2;
        }
        cout<<"Otra facultad (s/n) ";
        cin>>opc;
    }    
    cout<<u->info();
    return 0;
}
