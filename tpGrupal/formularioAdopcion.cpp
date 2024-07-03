#include "FormularioAdopcion.h"

FormularioAdopcion::FormularioAdopcion() : _idAdopcion(0), _idMascota(0), _estado(false) {}

FormularioAdopcion::FormularioAdopcion(int idAdopcion, Cliente cliente, int idMascota, bool estado)
: _idAdopcion(idAdopcion), _cliente(cliente), _idMascota(idMascota), _estado(estado) {}

int FormularioAdopcion::getIdAdopcion() {
    return _idAdopcion;
}

Cliente FormularioAdopcion::getCliente() {
    return _cliente;
}

int FormularioAdopcion::getIdMascota() {
    return _idMascota;
}

bool FormularioAdopcion::getEstado() {
    return _estado;
}

void FormularioAdopcion::setIdAdopcion(int idAdopcion) {
    _idAdopcion = idAdopcion;
}

void FormularioAdopcion::setCliente(Cliente cliente) {
    _cliente = cliente;
}

void FormularioAdopcion::setIdMascota(int idMascota) {
    _idMascota = idMascota;
}

void FormularioAdopcion::setEstado(bool estado) {
    _estado = estado;
}