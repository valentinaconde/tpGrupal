#pragma once
#include "Persona.h"

class PersonaArchivo {
private:

public:
    bool guardar(Persona registro);
    bool guardar(int index, Persona registro);
    Persona leer(int index);
    void leerTodos(Persona registros[], int cantidad);
    int buscarByDNI(const char* dni);
    int getCantidadRegistros();
    int getNuevoID(); // Asumiendo que las personas también tienen un ID único
};