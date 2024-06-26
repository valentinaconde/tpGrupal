#pragma once
#include "Articulo.h"

class ArticuloArchivo{
    private:

    public:
        bool guardar(Articulo registro);
        bool guardar(int index, Articulo registro);
        Articulo leer(int index);

        void leerTodos(Articulo registros[], int cantidad);

        /// devuelva el indice
        int buscarByID(int id);

        // int modificar(int id, Producto reg);
        // int modificar(int idex, Producto reg);

        int getCantidadRegistros();

        int getNuevoID();

};
