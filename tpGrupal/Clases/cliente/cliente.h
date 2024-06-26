#pragma once
#include <string>

class Cliente : public Persona {
    private:
        Fecha _fechaRegistro;
        bool _aptoAdopcion;
    public:
        Cliente();
        Cliente(int dni, const char nombre[30], const char apellido[30], int telefono, const char direccion[30], const char email[30], bool estado, Fecha fechaRegistro, bool aptoAdopcion);
        //GETS
        Fecha getFechaRegistro();
        bool getAptoAdopcion();
        //SETS
        void setFechaRegistro(Fecha fechaRegistro);
        void setAptoAdopcion(bool aptoAdopcion);
};