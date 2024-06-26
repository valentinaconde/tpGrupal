#include <iostream>
#include <cstdio> // For file operations
#include "FormularioAdopcion.h" // Include the FormularioAdopcion class header

class FormularioAdopcionArchivo {
public:
    bool guardar(FormularioAdopcion registro) {
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

    bool guardar(int index, FormularioAdopcion registro) {
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

    FormularioAdopcion leer(int index) {
        FormularioAdopcion reg;
        FILE *pFile;

        pFile = fopen("formulariosAdopcion.dat", "rb");

        if (pFile == nullptr) {
            return reg; // Return an empty FormularioAdopcion object
        }

        fseek(pFile, index * sizeof(FormularioAdopcion), SEEK_SET);

        fread(&reg, sizeof(FormularioAdopcion), 1, pFile);

        fclose(pFile);

        return reg;
    }

    void leerTodos(FormularioAdopcion registros[], int cantidad) {
        FILE *pFile;

        pFile = fopen("formulariosAdopcion.dat", "rb");

        if (pFile == nullptr) {
            return;
        }

        fread(registros, sizeof(FormularioAdopcion), cantidad, pFile);

        fclose(pFile);
    }

    int buscarByID(int id) {
        FormularioAdopcion reg;
        int pos = 0;
        FILE *pFile;

        pFile = fopen("formulariosAdopcion.dat", "rb");
        if (pFile == nullptr) {
            return -1;
        }

        while (fread(&reg, sizeof(FormularioAdopcion), 1, pFile)) {
            if (reg.getIdFormulario() == id) {
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

        pFile = fopen("formulariosAdopcion.dat", "rb");

        if (pFile == nullptr) {
            return 0;
        }

        fseek(pFile, 0, SEEK_END);

        tam = ftell(pFile) / sizeof(FormularioAdopcion);

        fclose(pFile);

        return tam;
    }

    int getNuevoID() {
        int cantidad = getCantidadRegistros();

        if (cantidad > 0) {
            return leer(cantidad - 1).getIdFormulario() + 1;
        } else {
            return 1;
        }
    }
};