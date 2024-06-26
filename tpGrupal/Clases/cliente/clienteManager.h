#pragma once
#include "Cliente.h"
#include "ClienteArchivo.h"

class ClientesManager {
private:
    void agregarCliente();
    void listarClientes();
    Cliente crearCliente();
    void volverCargarCliente(Cliente &registro);
    void mostrarCliente(Cliente registro);
    void modificarCliente();
    void eliminarCliente();
    ClienteArchivo _clientesarchivo;
public:
    void Menu();
};