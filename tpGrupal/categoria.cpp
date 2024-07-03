#include <iostream>
#include <cstring>
#include "Categoria.h"

Categoria::Categoria(){
    _idCategoria = 0;
    strcpy(_nombre, "");
    _estado = false;
}

Categoria::Categoria(int idCategoria, const char nombre[30], bool estado){
    setIdCategoria(idCategoria);
    setNombre(nombre);
    setEstado(estado);
}

void Categoria::Mostrar(){
    std::cout << "ID CATEGORIA: " << _idCategoria << std::endl;
    std::cout << "NOMBRE: " << _nombre << std::endl;
    std::cout << "ESTADO: " << (_estado ? "Activo" : "Inactivo") << std::endl;
}

int Categoria::getIdCategoria(){
    return _idCategoria;
}

const char* Categoria::getNombre(){
    return _nombre;
}

bool Categoria::getEstado(){
    return _estado;
}

void Categoria::setIdCategoria(int idCategoria){
    if(idCategoria > 0){
        _idCategoria = idCategoria;
    }else{
        _idCategoria = 0;
    }
}

void Categoria::setNombre(const char n[30]){
    strcpy(_nombre, n);
}

void Categoria::setEstado(bool estado){
    _estado = estado;
}
