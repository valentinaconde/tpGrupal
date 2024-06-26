#include <iostream>
#include <cstring>
#include "Factura.h"

Factura::Factura(){
    _numerofactura=0;
    _fecha = Fecha();
    _dnicliente=0;
    _metodopago=0;
    _total=0;
    _envio=0;
}

Factura::Factura(int numero, Fecha fecha, int dni, int pago, int total, bool envio){
    setNumeroFactura(numero);
    setFecha(fecha);
    setDNI(dni);
    setPago(pago);
    setTotal(total);
    setEnvio(envio);
}

void Factura::Mostrar(){
    std::cout << "NUMERO DE FACTURA: ";
    std::cout << _numerofactura << std::endl;
    std::cout << "FECHA: " ;
    std::cout << _fecha.toString() << std::endl;
    std::cout << "DNI CLIENTE: " ;
    std::cout << _dnicliente << std::endl;
    std::cout << "METODO DE PAGO: " ;
    std::cout << _metodopago << std::endl;
    std::cout << "TOTAL: " ;
    std::cout << _total << std::endl;
    std::cout << "METODO DE ENVIO: " ;
    if(_envio){
        std::cout << "Envio a domicilio " << std::endl;
    }else{
        std::cout << "Retiro en Tienda " << std::endl;
    }
}
int Factura::getNumeroFactura(){
    return _numerofactura;
}

Fecha Factura::getFecha(){
    return _fecha;
}

int Factura::getDNI(){
    return _dnicliente;
}

int Factura::getPago(){
    return _metodopago;
}

float Factura::getTotal(){
    return _total;
}

bool Factura::getEnvio(){
    return _envio;
}

void Factura::setNumeroFactura(int numero){
    if(numero>0){
        _numerofactura=numero;
    }else{
        _numerofactura=0;
    }
}

void Factura::setFecha(Fecha fecha){
    _fecha=fecha;
}

void Factura::setDNI(int dni){
    if(dni>0){
        _dnicliente=dni;
    }else{
        _dnicliente=0;
    }
}

void Factura::setPago(int pago){
    if(pago>0){
        _metodopago=pago;
    }else{
        _metodopago=0;
    }
}

void Factura::setTotal(float total){
    if(total>0){
        _total=total;
    }else{
        _total=0;
    }
}

void Factura::setEnvio(bool envio){
    _envio=envio;
}

