#include <iostream>
#include "DetalleComprasManager.h"
using namespace std;

void DetalleComprasManager::agregarDetalleCompra(){
    if(_detallecomprasarchivo.guardar(crearDetalleCompra())){
        cout << "El detalle de Compra fue guardado con exito!" << endl;
    }
    else{
        cout << "No se pudo guardar el detalle de Compra!" << endl;
    }
}


void DetalleComprasManager::listarDetallesCompras(){
    int cantidad = _detallecomprasarchivo.getCantidadRegistros();

    DetalleCompra *detallecompras;

    detallecompras = new DetalleCompra[cantidad];

    if(detallecompras == nullptr)
    {
        cout << "No se pudo pedir memoria... " << endl;
        return;
    }

    _detallecomprasarchivo.leerTodos(detallecompras, cantidad);

    for(int i=0; i<cantidad; i++)
    {
        if(detallecompras[i].getEstado())
        {
            cout << "--------------------------" << endl;
            mostrarDetalleCompra(detallecompras[i]);
            cout << "--------------------------" << endl;
        }
    }

    delete [] detallecompras;
}


DetalleCompra DetalleComprasManager::crearDetalleCompra(){
    int id;
    int numerocompra;
    int codigoarticulo;
    int cantidad;

    id = _detallecomprasarchivo.getNuevoID();

    cout << "ID: " << id<< endl;
    cout<< "Ingrese Numero de Factura: ";
    cin >> numerocompra;
    cout<<"Ingrese Codigo de Articulo: ";
    cin>>codigoarticulo;
    cout<<"Ingrese la cantidad: ";
    cin>>cantidad;

    return DetalleCompra(id,numerocompra,codigoarticulo,cantidad);
}


void DetalleComprasManager::volverCargarDetalleCompra(DetalleCompra &registro){
    int codigoarticulo;
    int cantidad;

    cout <<"Ingrese el codigo de articulo: ";
    cin>> codigoarticulo;
    cout<< "Ingrese la cantidad: ";
    cin >> cantidad;

    registro.setCodigoArticulo(codigoarticulo);
    registro.setCantidad(cantidad);
}


void DetalleComprasManager::mostrarDetalleCompra(DetalleCompra registro){
    std::cout << "ID DETALLE COMPRA: ";
    std::cout << registro.getID() << std::endl;
    std::cout << "NUMERO DE COMPRA: " ;
    std::cout << registro.getNumeroCompra() << std::endl;
    std::cout << "CODIGO DE ARTICULO: " ;
    std::cout << registro.getCodigoArticulo() << std::endl;
    std::cout << "CANTIDAD: " ;
    std::cout << registro.getCantidad() << std::endl;
    std::cout << "ESTADO: " ;
    if(registro.getEstado()){
        std::cout << "Disponible " << std::endl;
    }else{
        std::cout << "Eliminado " << std::endl;
    }
}


void DetalleComprasManager::modificarDetalleCompra(){
    int id, index;
    DetalleCompra detallecompra;

    cout << "Ingrese ID del detalle compra a modificar: ";
    cin >> id;

    index = _detallecomprasarchivo.buscarByID(id);

    if(index != -1)
    {
        detallecompra = _detallecomprasarchivo.leer(index);

        mostrarDetalleCompra(detallecompra);

        volverCargarDetalleCompra(detallecompra);

        if(_detallecomprasarchivo.guardar(index, detallecompra))
        {
            cout << "Se modifico con exito!" << endl;
        }
        else
        {
            cout << "No se pudo modificar el detalle de compra!" << endl;
        }
    }
    else
    {
        cout << "No se encuentra el detalle de compra!" << endl;
    }
}


void DetalleComprasManager::eliminarDetalleCompra(){
    int id, index;
    DetalleCompra detallecompra;
    bool eliminar;

    cout << "Ingrese id del detalle de compra a eliminar: ";
    cin >> id;

    index = _detallecomprasarchivo.buscarByID(id);

    if(index != -1)
    {
        detallecompra = _detallecomprasarchivo.leer(index);

        mostrarDetalleCompra(detallecompra);

        cout << "Esta segudo de que quiere eliminarlo? 1-Si 0-No: ";
        cin >> eliminar;

        if(eliminar){
            detallecompra.setEstado(false);

            if(_detallecomprasarchivo.guardar(index, detallecompra))
            {
                cout << "Se elimino con exito!" << endl;
            }
            else
            {
                cout << "No se pudo eliminar el detalle de compra!" << endl;
            }
        }
        else{
            cout << "El detalle no fue eliminado!" << endl;

        }
    }
    else
    {
        cout << "No se encuentra ese detalle!" << endl;
    }
}


void DetalleComprasManager::Menu(){
    int option;
    system("cls");
    do
    {
        system("cls");

        cout << "------ MENU DETALLE COMPRAS ------- " << endl;
        cout << "1- AGREGAR DETALLE COMPRA " << endl;
        cout << "2- LISTAR TODOS DETALLES COMPRAS" << endl;
        cout << "3- MODIFICAR DETALLE COMPRA" << endl;
        cout << "4- ELIMINAR DETALLE COMPRA" << endl;
        cout << "-----------------------------" << endl;
        cout << "0- SALIR" << endl;
        cout << "Opcion: "<< endl;
        cin >> option;

        switch(option)
        {
        case 1:
            agregarDetalleCompra();
            system("pause");
            break;

        case 2:
            listarDetallesCompras();
            system("pause");
            break;

        case 3:
            modificarDetalleCompra();
            system("pause");
            break;

        case 4:
            eliminarDetalleCompra();
            system("pause");
            break;
        }



    }
    while(option != 0);
}

