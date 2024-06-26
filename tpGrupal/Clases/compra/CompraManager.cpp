#include <iostream>
#include "CompraManager.h"
using namespace std;

void ComprasManager::agregarCompra(){
    if(_comprasarchivo.guardar(crearCompra())){
        cout << "La Factura fue guardado con exito!" << endl;
    }
    else{
        cout << "No se pudo guardar la Factura!" << endl;
    }
}

void ComprasManager::listarCompras(){
    int cantidad = _comprasarchivo.getCantidadRegistros();

    Compra *compras;

    compras = new Compra[cantidad];

    if(compras == nullptr)
    {
        cout << "No se pudo pedir memoria... " << endl;
        return;
    }

    _comprasarchivo.leerTodos(compras, cantidad);

    for(int i=0; i<cantidad; i++)
    {
        if(compras[i].getEstado()){
            cout << "--------------------------" << endl;
            mostrarCompra(compras[i]);
            cout << "--------------------------" << endl;
        }
    }

    delete [] compras;
}

Compra ComprasManager::crearCompra(){
    int numerocompra;
    Fecha fecha;
    int dni;
    int metodopago;
    float total;

    numerocompra = _comprasarchivo.getNuevoID();

    cout << "ID: " << numerocompra<< endl;
    cout <<"Fecha del dia "<< endl;
    cout<< "Ingrese DNI: ";
    cin >> dni;
    cout<<"Ingrese Metodo de pago: ";
    cin>>metodopago;
    cout<<"Ingrese el total: ";
    cin>>total;

    return Compra(numerocompra,fecha,dni,total,metodopago);
}

void ComprasManager::volverCargarCompra(Compra &registro){
    int metodopago;
    float total;

    cout <<"Ingrese el metodo de pago: ";
    cin>>metodopago;
    cout<< "Ingrese precio total: ";
    cin >> total;

    registro.setMetodoPago(metodopago);
    registro.setTotal(total);
}

void ComprasManager::mostrarCompra(Compra registro){
    std::cout << "NUMERO DE COMPRA: ";
    std::cout << registro.getNumeroCompra() << std::endl;
    std::cout << "FECHA: " ;
    std::cout << registro.getFecha().toString() << std::endl;
    std::cout << "DNI PROVEEDOR: " ;
    std::cout << registro.getDNI() << std::endl;
    std::cout << "METODO DE PAGO: " ;
    std::cout << registro.getMetodoPago() << std::endl;
    std::cout << "TOTAL: " ;
    std::cout << registro.getTotal() << std::endl;
    std::cout << "METODO DE ENVIO: " ;
    if(registro.getEstado()){
        std::cout << "Disponible " << std::endl;
    }else{
        std::cout << "Eliminado "<< std::endl;
    }
}

void ComprasManager::modificarCompra(){
    int numerocompra, index;
    Compra compra;

    cout << "Ingrese numero de factura a modificar: ";
    cin >> numerocompra;

    index = _comprasarchivo.buscarByID(numerocompra);

    if(index != -1)
    {
        compra = _comprasarchivo.leer(index);

        mostrarCompra(compra);

        volverCargarCompra(compra);

        if(_comprasarchivo.guardar(index, compra))
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

void ComprasManager::eliminarCompra(){
    int numerocompra, index;
    Compra compra;
    bool eliminar;

    cout << "Ingrese id del producto a eliminar: ";
    cin >> numerocompra;

    index = _comprasarchivo.buscarByID(numerocompra);

    if(index != -1)
    {
        compra = _comprasarchivo.leer(index);

        mostrarCompra(compra);

        cout << "Esta segudo de que quiere eliminarlo? 1-Si 0-No: ";
        cin >> eliminar;

        if(eliminar){
            compra.setEstado(false);

            if(_comprasarchivo.guardar(index, compra))
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

void ComprasManager::Menu(){
    int option;
    system("cls");
    do
    {
        system("cls");

        cout << "------ MENU COMPRAS ------- " << endl;
        cout << "1- AGREGAR COMPRA " << endl;
        cout << "2- LISTAR TODOS LAS COMPRAS" << endl;
        cout << "3- MODIFICAR COMPRA" << endl;
        cout << "4- ELIMINAR COMPRA" << endl;
        cout << "-----------------------------" << endl;
        cout << "0- SALIR" << endl;
        cout << "Opcion: "<< endl;
        cin >> option;

        switch(option)
        {
        case 1:
            agregarCompra();
            system("pause");
            break;

        case 2:
            listarCompras();
            system("pause");
            break;

        case 3:
            modificarCompra();
            system("pause");
            break;

        case 4:
            eliminarCompra();
            system("pause");
            break;
        }
    }
    while(option != 0);
}
