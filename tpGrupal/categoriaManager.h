#pragma once
#include "CategoriaArchivo.h"

class CategoriasManager {
    private:
        void agregarCategoria();
        void listarCategorias();
        Categoria crearCategoria();
        void volverCargarCategoria(Categoria &registro);
        void mostrarCategoria(Categoria registro);
        void modificarCategoria();
        void eliminarCategoria();
        CategoriaArchivo _categoriasArchivo;
    public:
        void Menu();
};
