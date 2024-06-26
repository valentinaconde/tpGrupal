#include <iostream>
#include "DetalleFacturasManager.h"
using namespace std;

void DetalleFacturasManager::agregarDetalleFactura(){
    if(_detallefacturasArchivo.guardar(crearDetalleFactura())){
        cout << "El detalle de Factura fue guardado con exito!" << endl;
    }
    else{
        cout << "No se pudo guardar el detalle de Factura!" << endl;
    }
}

void DetalleFacturasManager::listarDetallesFacturas(){
    int cantidad = _detallefacturasArchivo.getCantidadRegistros();

    DetalleFactura *detallefacturas;

    detallefacturas = new DetalleFactura[cantidad];

    if(detallefacturas == nullptr)
    {
        cout << "No se pudo pedir memoria... " << endl;
        return;
    }

    _detallefacturasArchivo.leerTodos(detallefacturas, cantidad);

    for(int i=0; i<cantidad; i++)
    {
        if(detallefacturas[i].getEstado())
        {
            cout << "--------------------------" << endl;
            mostrarDetalleFactura(detallefacturas[i]);
            cout << "--------------------------" << endl;
        }
    }

    delete [] detallefacturas;
}

DetalleFactura DetalleFacturasManager::crearDetalleFactura(){
    /*int _id;
        int _numerofactura;
        int _codigoarticulo;
        int _cantidad;
        bool _estado;*/
    int id;
    int numerofactura;
    int codigoarticulo;
    int cantidad;

    id = _detallefacturasArchivo.getNuevoID();

    cout << "ID: " << id<< endl;
    cout<< "Ingrese Numero de Factura: ";
    cin >> numerofactura;
    cout<<"Ingrese Codigo de Articulo: ";
    cin>>codigoarticulo;
    cout<<"Ingrese la cantidad: ";
    cin>>cantidad;

    return DetalleFactura(id,numerofactura,codigoarticulo,cantidad);
}

void DetalleFacturasManager::volverCargarDetalleFactura(DetalleFactura &registro){
    int codigoarticulo;
    int cantidad;

    cout <<"Ingrese el codigo de articulo: ";
    cin>> codigoarticulo;
    cout<< "Ingrese la cantidad: ";
    cin >> cantidad;

    registro.setCodigoArticulo(codigoarticulo);
    registro.setCantidad(cantidad);
}

void DetalleFacturasManager::mostrarDetalleFactura(DetalleFactura registro){
    std::cout << "ID DETALLE FACTURA: ";
    std::cout << registro.getID() << std::endl;
    std::cout << "NUMERO DE FACTURA: " ;
    std::cout << registro.getNumeroFactura() << std::endl;
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

void DetalleFacturasManager::modificarDetalleFactura(){
    int id, index;
    DetalleFactura detallefactura;

    cout << "Ingrese ID del detalle factura a modificar: ";
    cin >> id;

    index = _detallefacturasArchivo.buscarByID(id);

    if(index != -1)
    {
        detallefactura = _detallefacturasArchivo.leer(index);

        mostrarDetalleFactura(detallefactura);

        volverCargarDetalleFactura(detallefactura);

        if(_detallefacturasArchivo.guardar(index, detallefactura))
        {
            cout << "Se modifico con exito!" << endl;
        }
        else
        {
            cout << "No se pudo modificar la factura!" << endl;
        }
    }
    else
    {
        cout << "No se encuentra la factura!" << endl;
    }
}

void DetalleFacturasManager::eliminarDetalleFactura(){
    int id, index;
    DetalleFactura detallefactura;
    bool eliminar;

    cout << "Ingrese id del detalle de factura a eliminar: ";
    cin >> id;

    index = _detallefacturasArchivo.buscarByID(id);

    if(index != -1)
    {
        detallefactura = _detallefacturasArchivo.leer(index);

        mostrarDetalleFactura(detallefactura);

        cout << "Esta segudo de que quiere eliminarlo? 1-Si 0-No: ";
        cin >> eliminar;

        if(eliminar){
            detallefactura.setEstado(false);

            if(_detallefacturasArchivo.guardar(index, detallefactura))
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

void DetalleFacturasManager::Menu(){
    int option;
    system("cls");
    do
    {
        system("cls");

        cout << "------ MENU DETALLE FACTURAS ------- " << endl;
        cout << "1- AGREGAR DETALLE FACTURA " << endl;
        cout << "2- LISTAR TODOS DETALLES FACTURAS" << endl;
        cout << "3- MODIFICAR DETALLE FACTURA" << endl;
        cout << "4- ELIMINAR DETALLE FACTURA" << endl;
        cout << "-----------------------------" << endl;
        cout << "0- SALIR" << endl;
        cout << "Opcion: "<< endl;
        cin >> option;

        switch(option)
        {
        case 1:
            agregarDetalleFactura();
            system("pause");
            break;

        case 2:
            listarDetallesFacturas();
            system("pause");
            break;

        case 3:
            modificarDetalleFactura();
            system("pause");
            break;

        case 4:
            eliminarDetalleFactura();
            system("pause");
            break;
        }



    }
    while(option != 0);
}
