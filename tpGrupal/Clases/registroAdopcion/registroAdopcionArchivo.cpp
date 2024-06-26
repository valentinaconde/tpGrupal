#include <iostream>
#include <cstdio> // For file operations
#include "RegistroAdopcion.h" // Include the RegistroAdopcion class header

class RegistroAdopcionArchivo {
public:
    bool guardar(RegistroAdopcion registro) {
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

    bool guardar(int index, RegistroAdopcion registro) {
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

    RegistroAdopcion leer(int index) {
        RegistroAdopcion reg;
        FILE *pFile;

        pFile = fopen("registrosAdopcion.dat", "rb");

        if (pFile == nullptr) {
            return reg; // Return an empty RegistroAdopcion object
        }

        fseek(pFile, index * sizeof(RegistroAdopcion), SEEK_SET);

        fread(&reg, sizeof(RegistroAdopcion), 1, pFile);

        fclose(pFile);

        return reg;
    }

    void leerTodos(RegistroAdopcion registros[], int cantidad) {
        FILE *pFile;

        pFile = fopen("registrosAdopcion.dat", "rb");

        if (pFile == nullptr) {
            return;
        }

        fread(registros, sizeof(RegistroAdopcion), cantidad, pFile);

        fclose(pFile);
    }

    int buscarByID(int id) {
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

    int getCantidadRegistros() {
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

    int getNuevoID() {
        int cantidad = getCantidadRegistros();

        if (cantidad > 0) {
            return leer(cantidad - 1).getIdRegistro() + 1;
        } else {
            return 1;
        }
    }
};