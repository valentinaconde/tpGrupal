#include <iostream>
#include "FacturasManager.h"
using namespace std;

void FacturasManager::agregarFactura(){
    if(_facturasArchivo.guardar(crearFactura())){
        cout << "El producto fue guardado con exito!" << endl;
    }
    else{
        cout << "No se pudo guardar el producto!" << endl;
    }
}

void FacturasManager::listarFacturas(){
    int cantidad = _facturasArchivo.getCantidadRegistros();

    Factura *facturas;

    facturas = new Factura[cantidad];

    if(facturas == nullptr)
    {
        cout << "No se pudo pedir memoria... " << endl;
        return;
    }

    _facturasArchivo.leerTodos(facturas, cantidad);

    for(int i=0; i<cantidad; i++)
    {
            cout << "--------------------------" << endl;
            mostrarFactura(facturas[i]);
            cout << "--------------------------" << endl;
    }

    delete [] facturas;
}

Factura FacturasManager::crearFactura(){
    /*_numerofactura=0;
    _fecha = Fecha();
    _dnicliente=0;
    _metodopago=0;
    _total=0;
    _envio=0;*/
    int numerofactura;
    Fecha f1;
    int dni;
    int metodopago;
    float total;
    bool envio;

    numerofactura = _facturasArchivo.getNuevoID();

    cout << "ID: " << numerofactura<< endl;
    cout <<"Fecha del dia "<< endl;
    cout<< "Ingrese DNI: ";
    cin >> dni;
    cout<<"Ingrese Metodo de pago: ";
    cin>>metodopago;
    cout<<"Ingrese el total: ";
    cin>>total;
    cout<<"Ingrese el metodo de envio (1-Envio a domicilio/ 2-Retiro en local): ";
    cin>>envio;

    return Factura(numerofactura,f1,dni,metodopago,total,envio);
}

void FacturasManager::volverCargarFactura(Factura &registro){
    bool envio;
    float total;

    cout <<"Ingrese el metodo de envio (1-Envio a domicilio/ 0-Retiro en local): ";
    cin>>envio;
    cout<< "Ingrese precio total: ";
    cin >> total;

    registro.setEnvio(envio);
    registro.setTotal(total);
}

void FacturasManager::mostrarFactura(Factura registro){
    std::cout << "NUMERO DE FACTURA: ";
    std::cout << registro.getNumeroFactura() << std::endl;
    std::cout << "FECHA: " ;
    std::cout << registro.getFecha().toString() << std::endl;
    std::cout << "DNI CLIENTE: " ;
    std::cout << registro.getDNI() << std::endl;
    std::cout << "METODO DE PAGO: " ;
    std::cout << registro.getPago() << std::endl;
    std::cout << "TOTAL: " ;
    std::cout << registro.getTotal() << std::endl;
    std::cout << "METODO DE ENVIO: " ;
    if(registro.getEnvio()){
        std::cout << "Envio a domicilio " << std::endl;
    }else{
        std::cout << "Retiro en Tienda " << std::endl;
    }
}

void FacturasManager::modificarFactura(){
    int numeroFactura, index;
    Factura factura;

    cout << "Ingrese numero de factura a modificar: ";
    cin >> numeroFactura;

    index = _facturasArchivo.buscarByID(numeroFactura);

    if(index != -1)
    {
        factura = _facturasArchivo.leer(index);

        mostrarFactura(factura);

        volverCargarFactura(factura);

        if(_facturasArchivo.guardar(index, factura))
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

void FacturasManager::eliminarFactura(){
    //QUEDA PENDIENTE
}

void FacturasManager::Menu(){
    int option;
    system("cls");
    do
    {
        system("cls");

        cout << "------ MENU FACTURAS ------- " << endl;
        cout << "1- AGREGAR FACTURA " << endl;
        cout << "2- LISTAR TODOS LAS FACTURAS" << endl;
        cout << "3- MODIFICAR FACTURA" << endl;
        cout << "4- ELIMINAR FACTURA" << endl;
        cout << "-----------------------------" << endl;
        cout << "0- SALIR" << endl;
        cout << "Opcion: "<< endl;
        cin >> option;

        switch(option)
        {
        case 1:
            agregarFactura();
            system("pause");
            break;

        case 2:
            listarFacturas();
            system("pause");
            break;

        case 3:
            modificarFactura();
            system("pause");
            break;

        case 4:
            eliminarFactura();
            system("pause");
            break;
        }
    }
    while(option != 0);
}
