#ifndef FORMULARIOADOPCIONARCHIVO_H
#define FORMULARIOADOPCIONARCHIVO_H

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

#endif // FORMULARIOADOPCIONARCHIVO_H