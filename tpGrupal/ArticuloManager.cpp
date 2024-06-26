#include <iostream>
#include "ArticuloManager.h"
using namespace std;

void cargarCadena(char *pal, int tam);

void ArticulosManager::agregarArticulo(){
    if(_articulosArchivo.guardar(crearArticulo())){
        cout << "El producto fue guardado con exito!" << endl;
    }
    else{
        cout << "No se pudo guardar el producto!" << endl;
    }
}

void ArticulosManager::listarArticulos(){
    int cantidad = _articulosArchivo.getCantidadRegistros();

    Articulo *articulos;

    articulos = new Articulo[cantidad];

    if(articulos == nullptr)
    {
        cout << "No se pudo pedir memoria... " << endl;
        return;
    }

    _articulosArchivo.leerTodos(articulos, cantidad);

    for(int i=0; i<cantidad; i++)
    {
        if(articulos[i].getEstado())
        {
            cout << "--------------------------" << endl;
            mostrarArticulo(articulos[i]);
            cout << "--------------------------" << endl;
        }
    }

    delete [] articulos;
}

Articulo ArticulosManager::crearArticulo(){
    /*
    int _codigo;
    char _descripcion[30];
    float _precio;
    int _stock;
    int _categoria;*/
    int codigo;
    char despcripcion[30];
    float precio;
    int stock;
    int categoria;

    codigo= _articulosArchivo.getNuevoID();

    cout << "ID: " << codigo<< endl;
    cout <<"Ingrese nombre: ";
    cargarCadena(despcripcion,29);
    cout<< "Ingrese precio: ";
    cin >> precio;
    cout<<"Ingrese stock: ";
    cin>>stock;
    cout<<"Ingrese la Categoria: ";
    cin>>categoria;

    return Articulo(codigo, despcripcion, precio, stock, categoria);
}

void ArticulosManager::volverCargarArticulo(Articulo &registro){
    char nombre[30];
    float precio;

    cout <<"Ingrese nombre: ";
    cargarCadena(nombre,29);
    cout<< "Ingrese precio: ";
    cin >> precio;

    registro.setDescripcion(nombre);
    registro.setPrecio(precio);
}

void ArticulosManager::mostrarArticulo(Articulo reg){
    cout << "ID: " << reg.getCodigo() << endl;
    cout << "Descripcion: " << reg.getDescripcion() << endl;
    cout << "Precio: " << reg.getPrecio() << endl;
    cout << "Stock: " << reg.getStock() << endl;
    cout << "Categoria: " << reg.getCategoria() << endl;
    cout << "Estado: " << (reg.getEstado() ? "Disponible": "Eliminado") << endl;
}

void ArticulosManager::modificarArticulo(){
    int codigoArticulo, index;
    Articulo articulo;

    cout << "Ingrese id del Articulo a modificar: ";
    cin >> codigoArticulo;

    index = _articulosArchivo.buscarByID(codigoArticulo);

    if(index != -1)
    {
        articulo = _articulosArchivo.leer(index);

        mostrarArticulo(articulo);

        volverCargarArticulo(articulo);

        if(_articulosArchivo.guardar(index, articulo))
        {
            cout << "Se modifico con exito!" << endl;
        }
        else
        {
            cout << "No se pudo modificar el articulo!" << endl;
        }
    }
    else
    {
        cout << "No se encuentra ese articulo!" << endl;
    }
}

void ArticulosManager::eliminarArticulo(){
    int codigoArticulo, index;
    Articulo articulo;
    bool eliminar;

    cout << "Ingrese id del producto a eliminar: ";
    cin >> codigoArticulo;

    index = _articulosArchivo.buscarByID(codigoArticulo);

    if(index != -1)
    {
        articulo = _articulosArchivo.leer(index);

        mostrarArticulo(articulo);

        cout << "Esta segudo de que quiere eliminarlo? 1-Si 0-No: ";
        cin >> eliminar;

        if(eliminar){
            articulo.setEstado(false);

            if(_articulosArchivo.guardar(index, articulo))
            {
                cout << "Se elimino con exito!" << endl;
            }
            else
            {
                cout << "No se pudo eliminar el producto!" << endl;
            }
        }
        else{
            cout << "El producto no fue eliminado!" << endl;

        }
    }
    else
    {
        cout << "No se encuentra ese producto!" << endl;
    }
}

void ArticulosManager::Menu(){
    int option;
    system("cls");
    do
    {
        system("cls");

        cout << "------ MENU ARTICULOS ------- " << endl;
        cout << "1- AGREGAR ARTICULO " << endl;
        cout << "2- LISTAR TODOS LOS ARTICULOS" << endl;
        cout << "3- MODIFICAR ARTICULO" << endl;
        cout << "4- ELIMINAR ARTICULO" << endl;
        cout << "-----------------------------" << endl;
        cout << "0- SALIR" << endl;
        cout << "Opcion: "<< endl;
        cin >> option;

        switch(option)
        {
        case 1:
            agregarArticulo();
            system("pause");
            break;

        case 2:
            listarArticulos();
            system("pause");
            break;

        case 3:
            modificarArticulo();
            system("pause");
            break;

        case 4:
            eliminarArticulo();
            system("pause");
            break;
        }



    }
    while(option != 0);
}

void cargarCadena(char *pal, int tam){
    int i;
    fflush (stdin);
    for(i=0; i<tam;i++){
        pal[i]=cin.get();
        if(pal[i]=='\n')break;
    }
    pal[i]='\0';
    fflush(stdin);
}
