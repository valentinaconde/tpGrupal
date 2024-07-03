#pragma once
#include "RegistroAdopcion.h"

class RegistroAdopcionArchivo {
private:

public:
    RegistroAdopcion leer(int index);
    bool guardar(RegistroAdopcion registro);
    bool guardar(int index, RegistroAdopcion registro);
    void leerTodos(RegistroAdopcion registros[], int cantidad);
    int buscarByID(int id);
    int getCantidadRegistros();
    int getNuevoID();
};