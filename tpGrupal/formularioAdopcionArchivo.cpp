#include <iostream>
#include <cstdio>
#include "FormularioAdopcion.h"
#include "FormularioAdopcionArchivo.h"

bool FormularioAdopcionArchivo::guardar(FormularioAdopcion registro) {
    bool result;
    FILE *pFile;

    pFile = fopen("formulariosAdopcion.dat", "ab");

    if (pFile == nullptr) {
        return false;
    }

    result = fwrite(&registro, sizeof(FormularioAdopcion), 1, pFile);

    fclose(pFile);

    return result;
}

bool FormularioAdopcionArchivo::guardar(int index, FormularioAdopcion registro) {
    bool result;
    FILE *pFile;

    pFile = fopen("formulariosAdopcion.dat", "rb+");

    if (pFile == nullptr) {
        return false;
    }

    fseek(pFile, sizeof(FormularioAdopcion) * index, SEEK_SET);

    result = fwrite(&registro, sizeof(FormularioAdopcion), 1, pFile);

    fclose(pFile);

    return result;
}

FormularioAdopcion FormularioAdopcionArchivo::leer(int index) {
    FormularioAdopcion reg;
    FILE *pFile;

    pFile = fopen("formulariosAdopcion.dat", "rb");

    if (pFile == nullptr) {
        return reg;
    }

    fseek(pFile, index * sizeof(FormularioAdopcion), SEEK_SET);

    fread(&reg, sizeof(FormularioAdopcion), 1, pFile);

    fclose(pFile);

    return reg;
}

void FormularioAdopcionArchivo::leerTodos(FormularioAdopcion registros[], int cantidad) {
    FILE *pFile;

    pFile = fopen("formulariosAdopcion.dat", "rb");

    if (pFile == nullptr) {
        return;
    }

    fread(registros, sizeof(FormularioAdopcion), cantidad, pFile);

    fclose(pFile);
}

int FormularioAdopcionArchivo::buscarByID(int id) {
    FormularioAdopcion reg;
    int pos = 0;
    FILE *pFile;

    pFile = fopen("formulariosAdopcion.dat", "rb");
    if (pFile == nullptr) {
        return -1;
    }

    while (fread(&reg, sizeof(FormularioAdopcion), 1, pFile)) {
        if (reg.getIdAdopcion() == id ) {
            fclose(pFile);
            return pos;
        }
        pos++;
    }

    fclose(pFile);
    return -1;
}

int FormularioAdopcionArchivo::getCantidadRegistros() {
    FILE *pFile;
    int tam;

    pFile = fopen("formulariosAdopcion.dat", "rb");

    if (pFile == nullptr) {
        return 0;
    }

    fseek(pFile, 0, SEEK_END);

    tam = ftell(pFile) / sizeof(FormularioAdopcion);

    fclose(pFile);

    return tam;
}

int FormularioAdopcionArchivo::getNuevoID() {
    int cantidad = getCantidadRegistros();

    if (cantidad > 0) {
        return leer(cantidad - 1).getIdAdopcion() + 1;
    } else {
        return 1;
    }
}

