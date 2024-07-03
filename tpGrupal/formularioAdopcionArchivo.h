#pragma once
#include "FormularioAdopcion.h"

class FormularioAdopcionArchivo {
public:
    bool guardar(FormularioAdopcion registro);
    bool guardar(int index, FormularioAdopcion registro);
    FormularioAdopcion leer(int index);
    void leerTodos(FormularioAdopcion registros[], int cantidad);
    int buscarByID(int id);
    int getCantidadRegistros();
    int getNuevoID();
};

