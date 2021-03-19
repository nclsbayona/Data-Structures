#ifndef CARRERA
#define CARRERA
#include <string>
class Carrera{
    private:
        std::string nombre;
        int cantidad_estudiantes;
    public:
        Carrera(std::string nombre, int cantidadEstudiantes);
        std::string getNombre();
        void setNombre(std::string nombre);
        int getCantidadEstudiantes();
        void setCantidadEstudiantes(int cantidadEstudiantes);
        std::string info();
};
#endif
