#pragma once
#include "Articulo.h"
#include "ArticuloArchivo.h"

class ArticulosManager{
    private:
        void agregarArticulo();
        void listarArticulos();
        Articulo crearArticulo();
        void volverCargarArticulo(Articulo &registro);
        void mostrarArticulo(Articulo registro);
        void modificarArticulo();
        void eliminarArticulo();
        ArticuloArchivo _articulosArchivo;
    public:
        void Menu();
};
