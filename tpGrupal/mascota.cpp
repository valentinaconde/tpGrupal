#include "Mascota.h"
#include <cstring>

Mascota::Mascota() {
    strcpy(_nombre, "S/N");
    strcpy(_especie, "S/N");
    strcpy(_raza, "S/N");
    _genero = 'X';
    _tamanio = 'X';
    strcpy(_comportamiento, "S/N");
    _idMascota = 0;
    _edad = 0;
    _estado = true;
}

Mascota::Mascota(int idMascota, const char* nombre, const char* especie, const char* raza, int edad, char genero, char tamanio, const char* comportamiento, bool estado){
    strcpy(_nombre, nombre);
    strcpy(_especie, especie);
    strcpy(_raza, raza);
    _genero = genero;
    _tamanio = tamanio;
    strcpy(_comportamiento, comportamiento);
    _edad = edad;
    _estado = estado;
    _idMascota = idMascota;
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

char Mascota::getGenero() {
    return _genero;
}

char Mascota::getTamanio() {
    return _tamanio;
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
    strcpy(_nombre, nombre);
}

void Mascota::setEspecie(const char especie[30]) {
    strcpy(_especie, especie);
}

void Mascota::setRaza(const char raza[30]) {
    strcpy(_raza, raza);
}

void Mascota::setEdad(int edad) {
    _edad = edad;
}

void Mascota::setGenero(char genero) {
    _genero = genero;
}

void Mascota::setTamanio(char tamanio) {
    _tamanio = tamanio;
}

void Mascota::setComportamiento(const char comportamiento[30]) {
    strcpy(_comportamiento, comportamiento);
}

void Mascota::setEstado(bool estado) {
    _estado = estado;
}
