#pragma once
#include "Fecha.h"
class RegistroAdopcion {
    private:
        int _idRegistro;
        int _idAdopcion;
        Fecha _fechaRegistro;
        bool _estado;
    public:
        RegistroAdopcion();
        RegistroAdopcion(int idRegistro, int idAdopcion, Fecha fechaRegistro, bool estado);
        //GETS
        int getIdRegistro();
        int getIdAdopcion();
        Fecha getFechaRegistro();
        bool getEstado();
        //SETS
        void setIdRegistro(int idRegistro);
        void setIdAdopcion(int idAdopcion);
        void setFechaRegistro(Fecha fechaRegistro);
        void setEstado(bool estado);
};
