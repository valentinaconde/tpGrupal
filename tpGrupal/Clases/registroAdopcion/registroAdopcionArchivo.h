#pragma once
#include "RegistroAdopcion.h"

class RegistroAdopcionArchivo {
private:

public:
    bool guardar(RegistroAdopcion registro);
    bool guardar(int index, RegistroAdopcion registro);
    RegistroAdopcion leer(int index);

    void leerTodos(RegistroAdopcion registros[], int cantidad);

    /// Devuelve el índice del registro buscado por ID
    int buscarByID(int id);

    /// Obtiene la cantidad de registros almacenados
    int getCantidadRegistros();

    /// Genera un nuevo ID único para un nuevo registro
    int getNuevoID();
};