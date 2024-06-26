#include <iostream>
#include "Compra.h"

void Compra::Mostrar(){
    std::cout << "NUMERO DE COMPRA: ";
    std::cout << _numerocompra << std::endl;
    std::cout << "FECHA: " ;
    std::cout << _fecha.toString() << std::endl;
    std::cout << "DNI PROVEEDOR: " ;
    std::cout << _dniproveedor << std::endl;
    std::cout << "METODO DE PAGO: " ;
    std::cout << _metodopago << std::endl;
    std::cout << "TOTAL: " ;
    std::cout << _total << std::endl;
    std::cout << "ESTADO: " ;
    if(_estado){
        std::cout << "Disponible " << std::endl;
    }else{
        std::cout << "Eliminado " << std::endl;
    }
}

Compra::Compra(){
    _numerocompra=0;
    _fecha = Fecha();
    _dniproveedor=0;
    _total=0;
    _metodopago=0;
    _estado=true;
}

Compra::Compra(int numerocompra,Fecha fecha,int dni,float total,int metodopago){
    setNumeroCompra(numerocompra);
    setFecha(fecha);
    setDNI(dni);
    setTotal(total);
    setMetodoPago(metodopago);
    setEstado(true);
}

int Compra::getNumeroCompra(){
    return _numerocompra;
}

Fecha Compra::getFecha(){
    return _fecha;
}

int Compra::getDNI(){
    return _dniproveedor;
}

float Compra::getTotal(){
    return _total;
}

int Compra::getMetodoPago(){
    return _metodopago;
}

bool Compra::getEstado(){
    return _estado;
}

void Compra::setNumeroCompra(int numerocompra){
    _numerocompra=numerocompra;
}

void Compra::setFecha(Fecha fecha){
    _fecha = fecha;
}

void Compra::setDNI(int dni){
    _dniproveedor=dni;
}

void Compra::setTotal(float total){
    _total=total;
}

void Compra::setMetodoPago(int metodopago){
    _metodopago=metodopago;
}

void Compra::setEstado(bool estado){
    _estado=estado;
}

