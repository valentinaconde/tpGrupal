#include "Cliente.h"
#include <iostream>
#include <cstring>

Cliente::Cliente() {
    _fechaRegistro = {0, 0, 0};
    _aptoAdopcion = false;
}

Cliente::Cliente(int dni, const char nombre[30], const char apellido[30], int telefono, const char direccion[30], const char email[30], bool estado, Fecha fechaRegistro, bool aptoAdopcion){
    setDni(dni);
    setNombre(nombre);
    setApellido(apellido);
    setTelefono(telefono);
    setDireccion(direccion);
    setEmail(email);
    setEstado(estado);
    _aptoAdopcion = aptoAdopcion;
    _fechaRegistro = fechaRegistro;
}


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
