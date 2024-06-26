#pragma once
#include "Factura.h"

class FacturaArchivo{
    private:

    public:
        bool guardar(Factura registro);
        bool guardar(int index, Factura registro);
        Factura leer(int index);
        void leerTodos(Factura registros[], int cantidad);
        int buscarByID(int id);
        int getCantidadRegistros();
        int getNuevoID();
};
