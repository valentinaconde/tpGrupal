#include <iostream>
#include <cstring>
#include"DetalleCompra.h"

void DetalleCompra::Mostrar(){
    std::cout << "ID DETALLE COMPRA: ";
    std::cout << _id << std::endl;
    std::cout << "NRO COMPRA: " ;
    std::cout << _numerocompra << std::endl;
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

DetalleCompra::DetalleCompra(){
    _id=0;
    _numerocompra=0;
    _codigoarticulo=0;
    _cantidad=0;
    _estado=true;
}

DetalleCompra::DetalleCompra(int id, int numerocompra, int codigoarticulo, int cantidad){
    setID(id);
    setNumeroCompra(numerocompra);
    setCodigoArticulo(codigoarticulo);
    setCantidad(cantidad);
    setEstado(true);
}

int DetalleCompra::getID(){
    return _id;
}

int DetalleCompra::getNumeroCompra(){
    return _numerocompra;
}

int DetalleCompra::getCodigoArticulo(){
    return _codigoarticulo;
}

int DetalleCompra::getCantidad(){
    return _cantidad;
}

int DetalleCompra::getEstado(){
    return _estado;
}

void DetalleCompra::setID(int id){
    if(id>0){
        _id=id;
    }else{
        _id=0;
    }
}

void DetalleCompra::setNumeroCompra(int numerocompra){
    if(numerocompra>0){
        _numerocompra=numerocompra;
    }else{
        _numerocompra=0;
    }
}

void DetalleCompra::setCodigoArticulo(int codigo){
    if(codigo>0){
        _codigoarticulo=codigo;
    }else{
        _codigoarticulo=0;
    }
}

void DetalleCompra::setCantidad(int cantidad){
     if(cantidad>0){
        _cantidad=cantidad;
    }else{
        _cantidad=0;
    }
}

void DetalleCompra::setEstado(bool estado){
    _estado=estado;
}
