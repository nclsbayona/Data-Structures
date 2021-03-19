#include "Universidad.h"

Universidad::Universidad(std::string nombre){
    this->nombre=nombre;
}
    
std::string Universidad::getNombre(){
    return nombre;
}

void Universidad::setNombre(std::string nombre){
    this->nombre=nombre;
}

std::list<Facultad> Universidad::getListaFacultades(){
    return listaFacultades;
}
    
void Universidad::setListaFacultades(std::list<Facultad> listaFacultades){
    this->listaFacultades=listaFacultades;
}

int Universidad::addFacultad(std::string nombre){
    try{
        bool done=false;
        std::list<Carrera>::iterator it2;
        std::list<Facultad>::iterator it=this->listaFacultades.begin();
        for (; it!=this->listaFacultades.end()&&!done; advance(it,1)){
            if (it->getNombre()==nombre){
                done=true;
                it2=it->getIterator();
            }
        }
        if (!done){
            this->listaFacultades.push_back(*(new Facultad(nombre)));
            return 0;
        }
    }catch(...){
    }
    return -1;
}

void Universidad::addFacultad(Facultad facultad){
    this->listaFacultades.push_back(facultad);
}

std::list<Facultad>::iterator Universidad::getIterator(){
    return listaFacultades.begin();
}

std::string Universidad::info(){
    std::string ret;
    std::list<Facultad>::iterator it=listaFacultades.begin();
    ret=nombre+"\n";
    while(it!=listaFacultades.end()){        
        ret+="\t"+(it)->info()+"\n"; 
        advance(it,1);
    }
    return ret;
}
