#include <iostream>
#include <cstring>
#include "Articulo.h"

Articulo::Articulo(){
    _codigo=0;
    strcpy(_descripcion,"S/N");
    _precio=0;
    _stock=0;
    _categoria=0;
    _estado=true;
}

Articulo::Articulo(int codigo, const char *descripcion, float precio, int stock, int categoria){
    setCodigo(codigo);
    setDescripcion(descripcion);
    setPrecio(precio);
    setStock(stock);
    setCategoria(categoria);
    setEstado(true);
}

void Articulo::Mostrar(){
    if(_estado){
    std::cout << "CODIGO: ";
    std::cout << _codigo << std::endl;
    std::cout << "DESCRIPCION: ";
    std::cout << _descripcion << std::endl;
    std::cout << "PRECIO: ";
    std::cout << _precio << std::endl;
    std::cout << "STOCK: ";
    std::cout << _stock << std::endl;
    std::cout << "CATEGORIA: ";
    std::cout << _categoria << std::endl;
    if(_estado){
        std::cout << "ESTADO: Disponible" <<std::endl;
    }
    else{
        std::cout << "ESTADO: Eliminado" <<std::endl;
    }
    std::cout << "--------------------------"<<std::endl;
    }
}

int Articulo::getCodigo(){
    return _codigo;
}

const char* Articulo::getDescripcion(){
    return _descripcion;
}

float Articulo::getPrecio(){
    return _precio;
}

int Articulo::getStock(){
    return _stock;
}

int Articulo::getCategoria(){
    return _categoria;
}

int Articulo::getEstado(){
    return _estado;
}

void Articulo::setCodigo(int codigo){
   _codigo=codigo;
}

void Articulo::setDescripcion(const char *descripcion){
    strcpy(_descripcion,descripcion);
}

void Articulo::setPrecio(float precio){
    if(precio>0){
        _precio=precio;
    }else{
        _precio=0;
    }
}

void Articulo::setStock(int stock){
    if(stock>0){
        _stock=stock;
    }else{
        _stock=0;
    }
}

void Articulo::setCategoria(int categoria){
    if(categoria>0){
        _categoria=categoria;
    }else{
        _categoria=0;
    }
}

void Articulo::setEstado(bool estado){
    _estado=estado;
}
