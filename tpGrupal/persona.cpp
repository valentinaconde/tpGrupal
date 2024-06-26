#include <iostream>
#include <cstring>
#include "Persona.h"

Persona::Persona() {
    strcpy(_nombre, "S/N");
    strcpy(_apellido, "S/N");
    _dni = 0;
    _telefono = 0;
    strcpy(_direccion, "S/N");
    strcpy(_email, "S/N");
    _estado = true;
}

Persona::Persona(int dni, const char *nombre, const char *apellido, int telefono, const char *direccion, const char* email, bool estado) {
    strcpy(_nombre, nombre);
    strcpy(_apellido, apellido);
    _dni = dni;
    _telefono = telefono;
    strcpy(_direccion, direccion);
    strcpy(_email, email);
    _estado = estado;
}


void Persona::Mostrar() {
    if (_estado) {
        std::cout << "NOMBRE: ";
        std::cout << _nombre << std::endl;
        std::cout << "APELLIDO: ";
        std::cout << _apellido << std::endl;
        std::cout << "EDAD: ";
        std::cout << "DNI: ";
        std::cout << _dni << std::endl;
        std::cout << "ESTADO: Activo" << std::endl;
    } else {
        std::cout << "ESTADO: Inactivo" << std::endl;
    }
    std::cout << "--------------------------" << std::endl;
}


const char* Persona::getNombre() {
    return _nombre;
}

const char* Persona::getApellido() {
    return _apellido;
}

int Persona::getDni() {
    return _dni;
}

bool Persona::getEstado() {
    return _estado;
}

void Persona::setNombre(const char *nombre) {
    strcpy(_nombre, nombre);
}

void Persona::setApellido(const char *apellido) {
    strcpy(_apellido, apellido);
}

void Persona::setDni(int dni) {
    _dni = dni;
}

void Persona::setEstado(bool estado) {
    _estado = estado;
}

int Persona::getTelefono() {
    return _telefono;
}

void Persona::setTelefono(int telefono) {
    _telefono = telefono;
}

const char* Persona::getDireccion() {
    return _direccion;
}

void Persona::setDireccion(const char *direccion) {
    strcpy(_direccion, direccion);
}

const char* Persona::getEmail() {
    return _email;
}

void Persona::setEmail(const char *email) {
    strcpy(_email, email);
}
