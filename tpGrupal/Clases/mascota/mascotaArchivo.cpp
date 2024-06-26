#include <iostream>
#include <cstdio> // For file operations
#include "Mascota.h" // Include the Mascota class header

class MascotaArchivo {
public:
    bool guardar(Mascota registro) {
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

    bool guardar(int index, Mascota registro) {
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

    Mascota leer(int index) {
        Mascota reg;
        FILE *pFile;

        pFile = fopen("mascotas.dat", "rb");

        if (pFile == nullptr) {
            return reg; // Return an empty Mascota object
        }

        fseek(pFile, index * sizeof(Mascota), SEEK_SET);

        fread(&reg, sizeof(Mascota), 1, pFile);

        fclose(pFile);

        return reg;
    }

    void leerTodos(Mascota registros[], int cantidad) {
        FILE *pFile;

        pFile = fopen("mascotas.dat", "rb");

        if (pFile == nullptr) {
            return;
        }

        fread(registros, sizeof(Mascota), cantidad, pFile);

        fclose(pFile);
    }

    int buscarByID(int id) {
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

    int getCantidadRegistros() {
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

    int getNuevoID() {
        int cantidad = getCantidadRegistros();

        if (cantidad > 0) {
            return leer(cantidad - 1).getIdMascota() + 1;
        } else {
            return 1;
        }
    }
};