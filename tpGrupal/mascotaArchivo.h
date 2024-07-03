#pragma once
#include "Mascota.h"

class MascotaArchivo {
public:
    bool guardar(Mascota registro);
    bool guardar(int index, Mascota registro);
    Mascota leer(int index);
    void leerTodos(Mascota registros[], int cantidad);
    int buscarByID(int id);
    int getCantidadRegistros();
    int getNuevoID();
};