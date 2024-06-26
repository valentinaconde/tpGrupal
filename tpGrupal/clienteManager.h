#pragma once
#include "Cliente.h"
#include "ClienteArchivo.h"

class ClientesManager {
private:
    ClienteArchivo _clientesarchivo;
public:
    void agregarCliente();
    void listarClientes();
    Cliente crearCliente();
    void volverCargarCliente(Cliente &registro);
    void mostrarCliente(Cliente registro);
    void modificarCliente();
    void eliminarCliente();
    void Menu();
};
