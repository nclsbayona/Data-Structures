#ifndef FACULTAD
#define FACULTAD
#include <list>
#include "Carrera.h"
class Facultad{
    private:
        std::string nombre;
        std::list<Carrera> listaCarreras;
    public:
        Facultad(std::string nombre);
        std::string getNombre();
        void setNombre(std::string nombre);
        std::list<Carrera> getListaCarreras();
        void setListaCarreras(std::list<Carrera> listaCarreras);
        void addCarrera(std::string nombre, int cantidadEstudiantes);
        std::list<Carrera>::iterator getIterator();
        std::string info();
};
#endif
