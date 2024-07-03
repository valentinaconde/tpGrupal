#include <iostream>
#include "CategoriaManager.h"


using namespace std;

void CategoriasManager::agregarCategoria(){
    if(_categoriasArchivo.guardar(crearCategoria())){
        cout << "LA CATEGORIA FUE GUARDADA CON EXITO!" << endl;
    }
    else{
        cout << "NO SE PUDO GUARDAR LA CATEGORIA!" << endl;
    }
}

void CategoriasManager::listarCategorias(){
    int cantidad = _categoriasArchivo.getCantidadRegistros();

    Categoria *categorias;

    categorias = new Categoria[cantidad];

    if(categorias == nullptr)
    {
        cout << "NO SE PUDO PEDIR MEMORIA... " << endl;
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
    cout << "INGRESE NOMBRE DE LA CATEGORIA: ";
    cin >> nombre;
    estado = true;

    return Categoria(idCategoria, nombre, estado);
}

void CategoriasManager::volverCargarCategoria(Categoria &registro){
    char nombre[30];
    bool estado;

    cout << "INGRESE NUEVO NOMBRE DE LA CATEGORIA: ";
    cin >> nombre;
    cout << "INGRESE NUEVO ESTADO DE LA CATEGORIA (1-Activo/0-Inactivo): ";
    cin >> estado;

    registro.setNombre(nombre);
    registro.setEstado(estado);
}

void CategoriasManager::mostrarCategoria(Categoria registro){
    cout << "ID CATEGORIA: ";
    cout << registro.getIdCategoria() << endl;
    cout << "NOMBRE: ";
    cout << registro.getNombre() << endl;
    cout << "ESTADO: ";
    cout << (registro.getEstado() ? "Activo" : "Inactivo") << endl;
}

void CategoriasManager::modificarCategoria(){
    int idCategoria, index;
    Categoria categoria;

    cout << "INGRESE ID DE CATEGORIA A MODIFICAR: ";
    cin >> idCategoria;

    index = _categoriasArchivo.buscarByID(idCategoria);

    if(index != -1)
    {
        categoria = _categoriasArchivo.leer(index);

        mostrarCategoria(categoria);

        volverCargarCategoria(categoria);

        if(_categoriasArchivo.guardar(index, categoria))
        {
            cout << "SE MODIFICO CON EXITO!" << endl;
        }
        else
        {
            cout << "NO SE PUDO MODIFICAR LA CATEGORIA!" << endl;
        }
    }
    else
    {
        cout << "NO SE ENCUENTRA LA CATEGORIA!" << endl;
    }
}


void CategoriasManager::eliminarCategoria(){
    int codigoCategoria, index;
    Categoria categoria;
    bool eliminar;

    cout << "Ingrese ID de la categoria a eliminar: ";
    cin >> codigoCategoria;

    index = _categoriasArchivo.buscarByID(codigoCategoria);

    if(index != -1)
    {
        categoria = _categoriasArchivo.leer(index);

        mostrarCategoria(categoria);

        cout << "Esta seguro de que quiere eliminarlo? 1-Si 0-No: ";
        cin >> eliminar;

        if(eliminar){
            categoria.setEstado(false);

            if(_categoriasArchivo.guardar(index, categoria))
            {
                cout << "Se elimino con exito!" << endl;
            }
            else
            {
                cout << "No se pudo eliminar la categoria!" << endl;
            }
        }
        else{
            cout << "La categoria no fue eliminada!" << endl;

        }
    }
    else
    {
        cout << "No se encuentra esa categoria!" << endl;
    }
}



void CategoriasManager::Menu(){
    int option;
    system("cls");
    do
    {
        system("cls");

        cout << "------ MENU CATEGORIAS ------- " << endl;
        cout << "1- AGREGAR CATEGORIA " << endl;
        cout << "2- LISTAR TODAS LAS CATEGORIAS" << endl;
        cout << "3- MODIFICAR CATEGORIA" << endl;
        cout << "4- ELIMINAR CATEGORIA" << endl;
        cout << "-----------------------------" << endl;
        cout << "0- SALIR" << endl;
        cout << "Opcion: ";
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
