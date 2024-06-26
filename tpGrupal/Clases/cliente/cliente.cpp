#include "Cliente.h"
#include <iostream>
#include <cstring>

Cliente::Cliente() {
    _fechaRegistro = {0, 0, 0};
    _aptoAdopcion = false;
}

Cliente::Cliente(int dni, const char nombre[30], const char apellido[30], int telefono, const char direccion[30], const char email[30], bool estado, Fecha fechaRegistro, bool aptoAdopcion)
: Persona(dni, nombre, apellido, telefono, direccion, email, estado), _fechaRegistro(fechaRegistro), _aptoAdopcion(aptoAdopcion) {}

Fecha Cliente::getFechaRegistro() {
    return _fechaRegistro;
}

bool Cliente::getAptoAdopcion() {
    return _aptoAdopcion;
}

void Cliente::setFechaRegistro(Fecha fechaRegistro) {
    _fechaRegistro = fechaRegistro;
}

void Cliente::setAptoAdopcion(bool aptoAdopcion) {
    _aptoAdopcion = aptoAdopcion;
}