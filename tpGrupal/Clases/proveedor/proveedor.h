#pragma once
#include "Persona.h"

class Proveedor : public Persona {
    private:
        int _dniProveedor;
    public:
        Proveedor();
        Proveedor(int dni, const char nombre[30], const char apellido[30], int telefono, const char direccion[30], const char email[30], bool estado, int dniProveedor);
        //GET
        int getDniProveedor();
        //SET
        void setDniProveedor(int dniProveedor);
};