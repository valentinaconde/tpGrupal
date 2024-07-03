#include <iostream>
#include <cstdio>
#include "Mascota.h"
#include "mascotaArchivo.h"


bool MascotaArchivo::guardar(Mascota registro) {
        bool result;
        FILE *pFile;

        pFile = fopen("mascotas.dat", "ab");

        if (pFile == nullptr) {
            return false;
        }

        result = fwrite(&registro, sizeof(Mascota), 1, pFile);

        fclose(pFile);

        return result;
    }


bool MascotaArchivo::guardar(int index, Mascota registro) {
        bool result;
        FILE *pFile;

        pFile = fopen("mascotas.dat", "rb+");

        if (pFile == nullptr) {
            return false;
        }

        fseek(pFile, sizeof(Mascota) * index, SEEK_SET);

        result = fwrite(&registro, sizeof(Mascota), 1, pFile);

        fclose(pFile);

        return result;
    }

Mascota MascotaArchivo::leer(int index) {
        Mascota reg;
        FILE *pFile;

        pFile = fopen("mascotas.dat", "rb");

        if (pFile == nullptr) {
            return reg; 
        }

        fseek(pFile, index * sizeof(Mascota), SEEK_SET);

        fread(&reg, sizeof(Mascota), 1, pFile);

        fclose(pFile);

        return reg;
    }

void MascotaArchivo::leerTodos(Mascota registros[], int cantidad) {
        FILE *pFile;

        pFile = fopen("mascotas.dat", "rb");

        if (pFile == nullptr) {
            return;
        }

        fread(registros, sizeof(Mascota), cantidad, pFile);

        fclose(pFile);
    }

int MascotaArchivo::buscarByID(int id) {
        Mascota reg;
        int pos = 0;
        FILE *pFile;

        pFile = fopen("mascotas.dat", "rb");
        if (pFile == nullptr) {
            return -1;
        }

        while (fread(&reg, sizeof(Mascota), 1, pFile)) {
            if (reg.getIdMascota() == id) {
                fclose(pFile);
                return pos;
            }
            pos++;
        }

        fclose(pFile);
        return -1;
    }

int MascotaArchivo::getCantidadRegistros() {
        FILE *pFile;
        int tam;

        pFile = fopen("mascotas.dat", "rb");

        if (pFile == nullptr) {
            return 0;
        }

        fseek(pFile, 0, SEEK_END);

        tam = ftell(pFile) / sizeof(Mascota);

        fclose(pFile);

        return tam;
    }

int MascotaArchivo::getNuevoID() {
        int cantidad = getCantidadRegistros();

        if (cantidad > 0) {
            return leer(cantidad - 1).getIdMascota() + 1;
        } else {
            return 1;
        }
    }
