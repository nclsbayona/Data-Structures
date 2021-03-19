#ifndef UNIVERSIDAD
#define UNIVERSIDAD
#include <list>
#include "Facultad.h"
class Universidad{
    private:
        std::string nombre;
        std::list<Facultad> listaFacultades;
    public:
        Universidad(std::string nombre);
        std::string getNombre();
        void setNombre(std::string nombre);
        std::list<Facultad> getListaFacultades();
        void setListaFacultades(std::list<Facultad> listaFacultades);
        int addFacultad(std::string nombre);
        void addFacultad(Facultad facultad);
        std::list<Facultad>::iterator getIterator();
        std::string info();
};
#endif
