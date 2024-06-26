#include <iostream>
#include <cstring>
#include "DetalleFactura.h"

void DetalleFactura::Mostrar(){
    std::cout << "ID DETALLE FACTURA: ";
    std::cout << _id << std::endl;
    std::cout << "N° FACTURA: " ;
    std::cout << _numerofactura << std::endl;
    std::cout << "CODIGO ARTICULO: " ;
    std::cout << _codigoarticulo << std::endl;
    std::cout << "CANTIDAD: " ;
    std::cout << _cantidad << std::endl;
    if(_estado){
        std::cout << "ESTADO: Disponible" <<std::endl;
    }
    else{
        std::cout << "ESTADO: Eliminado" <<std::endl;
    std::cout << "--------------------------"<<std::endl;
    }
}

DetalleFactura::DetalleFactura(){
    _id=0;
    _numerofactura=0;
    _codigoarticulo=0;
    _cantidad=0;
    _cantidad=0;
    _estado=true;
}

DetalleFactura::DetalleFactura(int id, int factura, int codigoarticulo, int cantidad){
    setID(id);
    setNumeroFactura(factura);
    setCodigoArticulo(codigoarticulo);
    setCantidad(cantidad);
    setEstado(true);
}

int DetalleFactura::getID(){
    return _id;
}

int DetalleFactura::getNumeroFactura(){
    return _numerofactura;
}

int DetalleFactura::getCodigoArticulo(){
    return _codigoarticulo;
}

int DetalleFactura::getCantidad(){
    return _cantidad;
}

int DetalleFactura::getEstado(){
    return _estado;
}

void DetalleFactura::setID(int id){
    if(id>0){
        _id=id;
    }else{
        _id=0;
    }
}

void DetalleFactura::setNumeroFactura(int factura){
    if(factura>0){
        _numerofactura=factura;
    }else{
        _numerofactura=0;
    }
}

void DetalleFactura::setCodigoArticulo(int codigo){
    if(codigo>0){
        _codigoarticulo=codigo;
    }else{
        _codigoarticulo=0;
    }
}

void DetalleFactura::setCantidad(int cantidad){
    if(cantidad>0){
        _cantidad=cantidad;
    }else{
        _cantidad=0;
    }
}

void DetalleFactura::setEstado(bool estado){
    _estado=estado;
}
