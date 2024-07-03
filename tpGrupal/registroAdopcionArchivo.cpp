#include <iostream>
#include <cstdio>
#include "RegistroAdopcion.h"
#include "RegistroAdopcionArchivo.h"

bool RegistroAdopcionArchivo::guardar(RegistroAdopcion registro) {
    bool result;
    FILE *pFile;

    pFile = fopen("registrosAdopcion.dat", "ab");

    if (pFile == nullptr) {
        return false;
    }

    result = fwrite(&registro, sizeof(RegistroAdopcion), 1, pFile);

    fclose(pFile);

    return result;
}

bool RegistroAdopcionArchivo::guardar(int index, RegistroAdopcion registro) {
    bool result;
    FILE *pFile;

    pFile = fopen("registrosAdopcion.dat", "rb+");

    if (pFile == nullptr) {
        return false;
    }

    fseek(pFile, sizeof(RegistroAdopcion) * index, SEEK_SET);

    result = fwrite(&registro, sizeof(RegistroAdopcion), 1, pFile);

    fclose(pFile);

    return result;
}

RegistroAdopcion RegistroAdopcionArchivo::leer(int index) {
    RegistroAdopcion reg;
    FILE *pFile;

    pFile = fopen("registrosAdopcion.dat", "rb");

    if (pFile == nullptr) {
        return reg;
    }

    fseek(pFile, index * sizeof(RegistroAdopcion), SEEK_SET);

    fread(&reg, sizeof(RegistroAdopcion), 1, pFile);

    fclose(pFile);

    return reg;
}

void RegistroAdopcionArchivo::leerTodos(RegistroAdopcion registros[], int cantidad) {
    FILE *pFile;

    pFile = fopen("registrosAdopcion.dat", "rb");

    if (pFile == nullptr) {
        return;
    }

    fread(registros, sizeof(RegistroAdopcion), cantidad, pFile);

    fclose(pFile);
}

int RegistroAdopcionArchivo::buscarByID(int id) {
    RegistroAdopcion reg;
    int pos = 0;
    FILE *pFile;

    pFile = fopen("registrosAdopcion.dat", "rb");
    if (pFile == nullptr) {
        return -1;
    }

    while (fread(&reg, sizeof(RegistroAdopcion), 1, pFile)) {
        if (reg.getIdRegistro() == id) {
            fclose(pFile);
            return pos;
        }
        pos++;
    }

    fclose(pFile);
    return -1;
}

int RegistroAdopcionArchivo::getCantidadRegistros() {
    FILE *pFile;
    int tam;

    pFile = fopen("registrosAdopcion.dat", "rb");

    if (pFile == nullptr) {
        return 0;
    }

    fseek(pFile, 0, SEEK_END);

    tam = ftell(pFile) / sizeof(RegistroAdopcion);

    fclose(pFile);

    return tam;
}

int RegistroAdopcionArchivo::getNuevoID() {
    int cantidad = getCantidadRegistros();

    if (cantidad > 0) {
        return leer(cantidad - 1).getIdRegistro() + 1;
    } else {
        return 1;
    }
}

