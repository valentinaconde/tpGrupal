#pragma once
#include "Cliente.h"

class ClienteArchivo {
private:

public:
    bool guardar(Cliente registro);
    bool guardar(int index, Cliente registro);
    Cliente leer(int index);
    void leerTodos(Cliente registros[], int cantidad);
    int buscarByID(int id);
    int getCantidadRegistros();
    int getNuevoID();
};