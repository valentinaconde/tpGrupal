#include <iostream>
#include "CategoriasManager.h"
using namespace std;

void CategoriasManager::agregarCategoria(){
    if(_categoriasArchivo.guardar(crearCategoria())){
        cout << "La categoría fue guardada con éxito!" << endl;
    }
    else{
        cout << "No se pudo guardar la categoría!" << endl;
    }
}

void CategoriasManager::listarCategorias(){
    int cantidad = _categoriasArchivo.getCantidadRegistros();

    Categoria *categorias;

    categorias = new Categoria[cantidad];

    if(categorias == nullptr)
    {
        cout << "No se pudo pedir memoria... " << endl;
        return;
    }

    _categoriasArchivo.leerTodos(categorias, cantidad);

    for(int i=0; i<cantidad; i++)
    {
            cout << "--------------------------" << endl;
            mostrarCategoria(categorias[i]);
            cout << "--------------------------" << endl;
    }

    delete [] categorias;
}

Categoria CategoriasManager::crearCategoria(){
    int idCategoria;
    char nombre[30];
    bool estado;

    idCategoria = _categoriasArchivo.getNuevoID();

    cout << "ID: " << idCategoria << endl;
    cout << "Ingrese nombre de la categoría: ";
    cin >> nombre;
    cout << "Ingrese estado de la categoría (1-Activo/0-Inactivo): ";
    cin >> estado;

    return Categoria(idCategoria, nombre, estado);
}

void CategoriasManager::volverCargarCategoria(Categoria &registro){
    char nombre[30];
    bool estado;

    cout << "Ingrese nuevo nombre de la categoría: ";
    cin >> nombre;
    cout << "Ingrese nuevo estado de la categoría (1-Activo/0-Inactivo): ";
    cin >> estado;

    registro.setNombre(nombre);
    registro.setEstado(estado);
}

void CategoriasManager::mostrarCategoria(Categoria registro){
    std::cout << "ID CATEGORÍA: ";
    std::cout << registro.getIdCategoria() << std::endl;
    std::cout << "NOMBRE: ";
    std::cout << registro.getNombre() << std::endl;
    std::cout << "ESTADO: ";
    std::cout << (registro.getEstado() ? "Activo" : "Inactivo") << std::endl;
}

void CategoriasManager::modificarCategoria(){
    int idCategoria, index;
    Categoria categoria;

    cout << "Ingrese ID de la categoría a modificar: ";
    cin >> idCategoria;

    index = _categoriasArchivo.buscarByID(idCategoria);

    if(index != -1)
    {
        categoria = _categoriasArchivo.leer(index);

        mostrarCategoria(categoria);

        volverCargarCategoria(categoria);

        if(_categoriasArchivo.guardar(index, categoria))
        {
            cout << "Se modificó con éxito!" << endl;
        }
        else
        {
            cout << "No se pudo modificar la categoría!" << endl;
        }
    }
    else
    {
        cout << "No se encuentra la categoría!" << endl;
    }
}

void CategoriasManager::eliminarCategoria(){
    //QUEDA PENDIENTE
}

void CategoriasManager::Menu(){
    int option;
    system("cls");
    do
    {
        system("cls");

        cout << "------ MENU CATEGORÍAS ------- " << endl;
        cout << "1- AGREGAR CATEGORÍA " << endl;
        cout << "2- LISTAR TODAS LAS CATEGORÍAS" << endl;
        cout << "3- MODIFICAR CATEGORÍA" << endl;
        cout << "4- ELIMINAR CATEGORÍA" << endl;
        cout << "-----------------------------" << endl;
        cout << "0- SALIR" << endl;
        cout << "Opción: ";
        cin >> option;

        switch(option)
        {
        case 1:
            agregarCategoria();
            system("pause");
            break;

        case 2:
            listarCategorias();
            system("pause");
            break;

        case 3:
            modificarCategoria();
            system("pause");
            break;

        case 4:
            eliminarCategoria();
            system("pause");
            break;
        }
    }
    while(option != 0);
}
