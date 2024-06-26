#include "RegistroAdopcion.h"

RegistroAdopcion::RegistroAdopcion() : _idRegistro(0), _idAdopcion(0), _fechaRegistro(Fecha()) {}

RegistroAdopcion::RegistroAdopcion(int idRegistro, int idAdopcion, Fecha fechaRegistro) : _idRegistro(idRegistro), _idAdopcion(idAdopcion), _fechaRegistro(fechaRegistro) {}

int RegistroAdopcion::getIdRegistro() {
    return _idRegistro;
}

int RegistroAdopcion::getIdAdopcion() {
    return _idAdopcion;
}

Fecha RegistroAdopcion::getFechaRegistro() {
    return _fechaRegistro;
}

void RegistroAdopcion::setIdRegistro(int idRegistro) {
    _idRegistro = idRegistro;
}

void RegistroAdopcion::setIdAdopcion(int idAdopcion) {
    _idAdopcion = idAdopcion;
}

void RegistroAdopcion::setFechaRegistro(Fecha fechaRegistro) {
    _fechaRegistro = fechaRegistro;
}