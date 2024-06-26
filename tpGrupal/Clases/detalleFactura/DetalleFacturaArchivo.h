#pragma once
#include "DetalleFactura.h"

class DetalleFacturaArchivo{
    private:

    public:
        bool guardar(DetalleFactura registro);
        bool guardar(int index, DetalleFactura registro);
        DetalleFactura leer(int index);
        void leerTodos(DetalleFactura registros[], int cantidad);
        int buscarByID(int id);
        int getCantidadRegistros();
        int getNuevoID();
};
