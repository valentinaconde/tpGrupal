#include "Mascota.h"
#include <cstring> // Para usar strcpy y strcpy

Mascota::Mascota() : _idMascota(0), _edad(0), _estado(false) {
    _nombre[0] = '\0';
    _especie[0] = '\0';
    _raza[0] = '\0';
    _genero[0] = '\0';
    _tamaño[0] = '\0';
    _comportamiento[0] = '\0';
}

Mascota::Mascota(int idMascota, const char nombre[30], const char especie[30], const char raza[30], int edad, const char genero[30], const char tamaño[30], const char comportamiento[30], bool estado)
: _idMascota(idMascota), _edad(edad), _estado(estado) {
    strcpy(_nombre, nombre, 29);
    _nombre[29] = '\0';
    strcpy(_especie, especie, 29);
    _especie[29] = '\0';
    strcpy(_raza, raza, 29);
    _raza[29] = '\0';
    strcpy(_genero, genero, 29);
    _genero[29] = '\0';
    strcpy(_tamaño, tamaño, 29);
    _tamaño[29] = '\0';
    strcpy(_comportamiento, comportamiento, 29);
    _comportamiento[29] = '\0';
}

int Mascota::getIdMascota() {
    return _idMascota;
}

const char* Mascota::getNombre() {
    return _nombre;
}

const char* Mascota::getEspecie() {
    return _especie;
}

const char* Mascota::getRaza() {
    return _raza;
}

int Mascota::getEdad() {
    return _edad;
}

const char* Mascota::getGenero() {
    return _genero;
}

const char* Mascota::getTamaño() {
    return _tamaño;
}

const char* Mascota::getComportamiento() {
    return _comportamiento;
}

bool Mascota::getEstado() {
    return _estado;
}

void Mascota::setIdMascota(int idMascota) {
    _idMascota = idMascota;
}

void Mascota::setNombre(const char nombre[30]) {
    strcpy(_nombre, nombre, 29);
    _nombre[29] = '\0';
}

void Mascota::setEspecie(const char especie[30]) {
    strcpy(_especie, especie, 29);
    _especie[29] = '\0';
}

void Mascota::setRaza(const char raza[30]) {
    strcpy(_raza, raza, 29);
    _raza[29] = '\0';
}

void Mascota::setEdad(int edad) {
    _edad = edad;
}

void Mascota::setGenero(const char genero[30]) {
    strcpy(_genero, genero, 29);
    _genero[29] = '\0';
}

void Mascota::setTamaño(const char tamaño[30]) {
    strcpy(_tamaño, tamaño, 29);
    _tamaño[29] = '\0';
}

void Mascota::setComportamiento(const char comportamiento[30]) {
    strcpy(_comportamiento, comportamiento, 29);
    _comportamiento[29] = '\0';
}

void Mascota::setEstado(bool estado) {
    _estado = estado;
}