#include "RegistroAdopcion.h"

RegistroAdopcion::RegistroAdopcion(){
    _idRegistro = 0;
    _idAdopcion = 0;
    _fechaRegistro = Fecha();
    _estado = false;
}

RegistroAdopcion::RegistroAdopcion(int idRegistro, int idAdopcion, Fecha fechaRegistro, bool estado){
    _idRegistro = idRegistro;
    _idAdopcion = idAdopcion;
    _fechaRegistro = fechaRegistro;
    _estado = estado;
}

int RegistroAdopcion::getIdRegistro() {
    return _idRegistro;
}

int RegistroAdopcion::getIdAdopcion() {
    return _idAdopcion;
}

Fecha RegistroAdopcion::getFechaRegistro() {
    return _fechaRegistro;
}

bool RegistroAdopcion::getEstado() {
    return _estado;
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

void RegistroAdopcion::setEstado(bool estado) {
    _estado = estado;
}
