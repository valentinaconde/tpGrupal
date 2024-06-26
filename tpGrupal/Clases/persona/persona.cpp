#include <iostream>
#include <cstring>
#include "Persona.h"

Persona::Persona() {
    _edad = 0;
    strcpy(_nombre, "S/N");
    strcpy(_apellido, "S/N");
    strcpy(_dni, "S/N");
    _estado = true;
}

Persona::Persona(const char *nombre, const char *apellido, int edad, const char *dni) {
    setNombre(nombre);
    setApellido(apellido);
    setEdad(edad);
    setDNI(dni);
    setEstado(true);
}

void Persona::Mostrar() {
    if (_estado) {
        std::cout << "NOMBRE: ";
        std::cout << _nombre << std::endl;
        std::cout << "APELLIDO: ";
        std::cout << _apellido << std::endl;
        std::cout << "EDAD: ";
        std::cout << _edad << std::endl;
        std::cout << "DNI: ";
        std::cout << _dni << std::endl;
        std::cout << "ESTADO: Activo" << std::endl;
    } else {
        std::cout << "ESTADO: Inactivo" << std::endl;
    }
    std::cout << "--------------------------" << std::endl;
}

int Persona::getEdad() {
    return _edad;
}

const char* Persona::getNombre() {
    return _nombre;
}

const char* Persona::getApellido() {
    return _apellido;
}

const char* Persona::getDNI() {
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

void Persona::setEdad(int edad) {
    if (edad > 0) {
        _edad = edad;
    } else {
        _edad = 0;
    }
}

void Persona::setDNI(const char *dni) {
    strcpy(_dni, dni);
}

void Persona::setEstado(bool estado) {
    _estado = estado;
}