#pragma once
#include "DetalleCompra.h"

class DetalleCompraArchivo{
    private:

    public:
        bool guardar(DetalleCompra registro);
        bool guardar(int index, DetalleCompra registro);
        DetalleCompra leer(int index);
        void leerTodos(DetalleCompra registros[], int cantidad);
        int buscarByID(int id);
        int getCantidadRegistros();
        int getNuevoID();
};
