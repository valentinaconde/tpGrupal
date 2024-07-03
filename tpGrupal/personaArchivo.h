#pragma once
#include "Persona.h"

class PersonaArchivo {
private:

public:
    bool guardar(Persona registro);
    bool guardar(int index, Persona registro);
    Persona leer(int index);
    void leerTodos(Persona registros[], int cantidad);
    int buscarPorDni(int dni);
    int getCantidadRegistros();
};
