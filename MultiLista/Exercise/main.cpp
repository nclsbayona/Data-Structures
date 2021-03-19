#include "Universidad.h"
#include <iostream>
using namespace std;
int main(){
    string nombre, n_facultad, n_carrera;
    char opc='s', opc2;
    int cant_estudiantes;
    Facultad *facultad;
    Universidad *u;
    cout<<"Nombre U: ";
    getline(cin, nombre, '\n');
    u=new Universidad(nombre);
    while (opc=='s'){
        cin.ignore();
        cout<<"Nombre facultad ";
        getline(cin, n_facultad, '\n');
        facultad=new Facultad(n_facultad);
        opc2='s';
        while(opc2=='s'){
            cin.ignore();
            cout<<"Nombre carrera ";
            getline(cin, n_carrera, '\n');
            cout<<"Numero estudiantes ";
            cin>>cant_estudiantes;
            facultad->addCarrera(n_carrera, cant_estudiantes);
            cout<<"Otra carrera (s/n) ";
            cin>>opc2;
        }
        u->addFacultad(*facultad);
        cout<<"Otra facultad (s/n) ";
        cin>>opc;
    }    
    cout<<u->info();
    return 0;
}
