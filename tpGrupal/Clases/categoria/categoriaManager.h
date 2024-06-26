#pragma once
#include "CategoriaArchivo.h"

class CategoriasManager {
private:
    CategoriaArchivo _categoriasArchivo;

public:
    void agregarCategoria();
    void listarCategorias();
    Categoria crearCategoria();
    void volverCargarCategoria(Categoria &registro);
    void mostrarCategoria(Categoria registro);
    void modificarCategoria();
    void eliminarCategoria();
    void Menu();
};