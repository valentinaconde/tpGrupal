#pragma once
#include "Compra.h"

class CompraArchivo{
    private:

    public:
        bool guardar(Compra registro);
        bool guardar(int index, Compra registro);
        Compra leer(int index);
        void leerTodos(Compra registros[], int cantidad);
        int buscarByID(int id);
        int getCantidadRegistros();
        int getNuevoID();
};
