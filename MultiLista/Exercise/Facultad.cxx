#include "Facultad.h"

Facultad::Facultad(std::string nombre){
    this->nombre=nombre;
}
    
std::string Facultad::getNombre(){
    return nombre;
}

void Facultad::setNombre(std::string nombre){
    this->nombre=nombre;
}

std::list<Carrera> Facultad::getListaCarreras(){
    return listaCarreras;
}
    
void Facultad::setListaCarreras(std::list<Carrera> listaCarreras){
    this->listaCarreras=listaCarreras;
}

void Facultad::addCarrera(std::string nombre, int cantidadEstudiantes){
    this->listaCarreras.push_back(*(new Carrera(nombre, cantidadEstudiantes)));
}

std::list<Carrera>::iterator Facultad::getIterator(){
    return this->listaCarreras.begin();
}
    
std::string Facultad::info(){
    std::string ret;
    std::list<Carrera>::iterator it=listaCarreras.begin();
    ret=nombre+"\n";
    while(it!=listaCarreras.end()){
        ret+="\t"+it->info()+"\n";
        it++;
    }
    return ret;
}
