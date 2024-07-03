#include <iostream>
#include <cstring>
#include "Persona.h"

using namespace std;

Persona::Persona() {
    strcpy(_nombre, "S/N");
    strcpy(_apellido, "S/N");
    _dni = 0;
    _telefono = 0;
    strcpy(_direccion, "S/N");
    strcpy(_email, "S/N");
    _estado = false;
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
        cout << "DNI: ";
        cout << _dni << endl;
        cout << "NOMBRE: ";
        cout << _nombre << endl;
        cout << "APELLIDO: ";
        cout << _apellido << endl;
        cout << "TELEFONO: ";
        cout << _telefono << endl;
        cout << "DIRECCION: ";
        cout << _direccion << endl;
        cout << "EMAIL: ";
        cout << _email << endl;
        cout << "--------------------------" << endl;
    }
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
