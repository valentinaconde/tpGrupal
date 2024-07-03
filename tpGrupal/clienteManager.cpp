#include <iostream>
#include <cstring>
#include "ClienteManager.h"
using namespace std;

void cargarCadena(char *pal, int tam);

void ClientesManager::mostrarCliente(Cliente cliente)
{

    if (cliente.getEstado())
    {
        cout << "DNI: " << cliente.getDni() << endl;
        cout << "Nombre: " << cliente.getNombre() << endl;
        cout << "Apellido: " << cliente.getApellido() << endl;
        cout << "Telefono: " << cliente.getTelefono() << endl;
        cout << "Direccion: " << cliente.getDireccion() << endl;
        cout << "Email: " << cliente.getEmail() << endl;
        cout << "Apto adopcion: " << (cliente.getAptoAdopcion() ? "Si" : "No") << endl;
        cout << "Fecha de registro: ";
        cliente.getFechaRegistro().mostrarFecha();
    }
}

void ClientesManager::agregarCliente()
{
    Cliente cliente;
    cliente = crearCliente();
    if (_clientesarchivo.guardar(cliente)  && cliente.getEstado())
    {
        cout << "El cliente fue guardado con exito!" << endl;
    }
    else if(_clientesarchivo.guardar(cliente) && !cliente.getEstado()){
        cout << "Saliendo" << endl;
    }
    else
    {
        cout << "No se pudo guardar el cliente!" << endl;
    }
}

void ClientesManager::listarClientes()
{
    system("cls");
    int cantidad = _clientesarchivo.getCantidadRegistros();

    Cliente *clientes = new Cliente[cantidad];

    if (clientes == nullptr)
    {
        cout << "No se pudo pedir memoria..." << endl;
        return;
    }

    _clientesarchivo.leerTodos(clientes, cantidad);

    cout << "--------------------- CLIENTES --------------------- " << endl;
    bool hayRegistros = false;
    for (int i = 0; i < cantidad; i++)
    {
        if (clientes[i].getEstado())
        {
            hayRegistros = true;
            cout << "--------------------------" << endl;
            mostrarCliente(clientes[i]);
            cout << "--------------------------" << endl;
        }
    }

    if (!hayRegistros)
    {
        cout << "----- NO HAY CLIENTES DISPONIBLES PARA MOSTRAR -----" << endl
             << endl;
    }

    delete[] clientes;
}

Cliente ClientesManager::crearCliente()
{
    cout << "--------- ALTA DE CLIENTE ----------" << endl;
    int dni;
    char nombre[30], apellido[30], direccion[30], email[30];
    int telefono;
    bool estado, aptoAdopcion;
    Fecha fechaRegistro;

    Cliente cliente;

    cout << "Ingrese DNI: ";
    cin >> dni;
    int pos = _clientesarchivo.buscarPorDni(dni);
    if (pos >= 0) cliente = _clientesarchivo.leer(pos);
    while (pos >= 0 && cliente.getEstado() && dni > 0)
    {
        cout << "CLIENTE YA EXISTENTE, INTENTE NUEVAMENTE " << endl;
        system("pause");
        system("cls");
         cout << "--------- ALTA DE CLIENTE ----------" << endl;
        cout << "Ingrese DNI o 0 para salir: ";
        cin >> dni;
        pos = _clientesarchivo.buscarPorDni(dni);
    }
    if (dni > 0)
    {
        cout << "Ingrese Nombre: ";
        cargarCadena(nombre, 29);
        cout << "Ingrese Apellido: ";
        cargarCadena(apellido, 29);
        cout << "Ingrese Telefono: ";
        cin >> telefono;
        cout << "Ingrese Direccion: ";
        cargarCadena(direccion, 29);
        cout << "Ingrese Email: ";
        cargarCadena(email, 29);
        cout << "Ingrese Fecha de Registro : " << endl;
        fechaRegistro.cargarFecha();

        return Cliente(dni, nombre, apellido, telefono, direccion, email, true, fechaRegistro, true);
    }
    else return Cliente(0, "", "", 0, "", "", false, fechaRegistro, false);
}

void ClientesManager::volverCargarCliente(Cliente &registro)
{

    int dni, telefono, apto;
    char nombre[30], apellido[30], direccion[30], email[30];
    ClienteArchivo aux;

    cout << endl;
    cout << "----- MODIFICANDO -----" << endl;
    cout << "DNI: " << registro.getDni() << endl;
    cout << "Ingrese Nombre: ";
    cin >> nombre;
    cout << "Ingrese Apellido: ";
    cin >> apellido;
    cout << "Ingrese Telefono: ";
    cin >> telefono;
    cout << "Ingrese Direccion: ";
    cin >> direccion;
    cout << "Ingrese Email: ";
    cin >> email;
    cout << "Ingrese Apto adopcion: ";
    cin >> apto;

    registro.setNombre(nombre);
    registro.setApellido(apellido);
    registro.setTelefono(telefono);
    registro.setDireccion(direccion);
    registro.setEmail(email);
    registro.setEstado(true);
    registro.setAptoAdopcion(apto);
}

void ClientesManager::modificarCliente()
{
    int dni;
    Cliente cliente;

    cout << "Ingrese DNI del cliente a modificar: ";
    cin >> dni;

    int index = _clientesarchivo.buscarPorDni(dni);

    if (index != -1)
    {
        cliente = _clientesarchivo.leer(index);

        mostrarCliente(cliente);

        volverCargarCliente(cliente);

        if (_clientesarchivo.guardar(index, cliente))
        {
            cout << "Se modifico con exito!" << endl;
        }
        else
        {
            cout << "No se pudo modificar el cliente!" << endl;
        }
    }
    else
    {
        cout << "No se encuentra el cliente!" << endl;
    }
}

void ClientesManager::eliminarCliente()
{
    int dni;
    Cliente cliente;
    bool eliminar;

    cout << "Ingrese DNI del cliente a eliminar: ";
    cin >> dni;

    int index = _clientesarchivo.buscarPorDni(dni);

    if (index != -1)
    {
        cliente = _clientesarchivo.leer(index);

        mostrarCliente(cliente);

        cout << "Esta seguro de que quiere eliminarlo? 1-SI, 0-NO: ";
        cin >> eliminar;

        if (eliminar)
        {
            cliente.setEstado(false);
            if (_clientesarchivo.guardar(index, cliente))
            {
                cout << "Se elimino con exito!" << endl;
            }
            else
            {
                cout << "No se pudo eliminar el cliente!" << endl;
            }
        }
        else
        {
            cout << "El cliente no fue eliminado!" << endl;
        }
    }
    else
    {
        cout << "No se encuentra ese cliente!" << endl;
    }
}

void ClientesManager::listadoClientesOrdenadosPorDni()
{

    Cliente reg;

    int cantRegistros = 0;

    cantRegistros = _clientesarchivo.getCantidadRegistros();

    Cliente *vec = new Cliente[cantRegistros];

    for (int i = 0; i < cantRegistros; i++)
    {
        reg = _clientesarchivo.leer(i);
        vec[i] = reg;
    }

    for (int i = 0; i < cantRegistros - 1; i++)
    {
        for (int j = 0; j < cantRegistros - 1; j++)
        {
            if (vec[j].getDni() > vec[j + 1].getDni())
            {
                Cliente aux = vec[j];
                vec[j] = vec[j + 1];
                vec[j + 1] = aux;
            }
        }
    }

    bool hayClientes = false;
    cout << "------------ CLIENTES ORDENADOS POR DNI ------------ " << endl;
    for (int i = 0; i < cantRegistros; i++)
    {
        if (vec[i].getEstado())
        {
            hayClientes = true;
            cout << "----------------------------------------------------" << endl;
            mostrarCliente(vec[i]);
            cout << "----------------------------------------------------" << endl;
        }
    }
    if (!hayClientes)
    {
        cout << "----- NO HAY CLIENTES DISPONIBLES PARA MOSTRAR -----" << endl
             << endl;
    }
    delete[] vec;
}

void ClientesManager::listadoClientesOrdenadosPorApellido()
{
    Cliente reg;
    int cantRegistros = 0;
    ClienteArchivo clienteArchivo;
    cantRegistros = clienteArchivo.getCantidadRegistros();
    Cliente *vec = new Cliente[cantRegistros];

    for (int i = 0; i < cantRegistros; i++)
    {
        reg = clienteArchivo.leer(i);
        vec[i] = reg;
    }

    for (int i = 0; i < cantRegistros - 1; i++)
    {
        for (int j = 0; j < cantRegistros - 1 - i; j++)
        {
            if (strcmp(vec[j].getApellido(), vec[j + 1].getApellido()) > 0)
            {
                Cliente aux = vec[j];
                vec[j] = vec[j + 1];
                vec[j + 1] = aux;
            }
        }
    }

    bool hayClientes = false;
    cout << "---------- CLIENTES ORDENADOS POR APELLIDO --------- " << endl;
    for (int i = 0; i < cantRegistros; i++)
    {
        if (vec[i].getEstado())
        {
            hayClientes = true;
            cout << "----------------------------------------------------" << endl;
            mostrarCliente(vec[i]);
            cout << "----------------------------------------------------" << endl;
        }
    }
    if (!hayClientes)
    {
        cout << "----- NO HAY CLIENTES DISPONIBLES PARA MOSTRAR -----" << endl
             << endl;
    }
    delete[] vec;
}

void ClientesManager::listadoClientesOrdenadosPorFechaRegistro()
{
    Cliente reg;
    int cantRegistros = 0;
    ClienteArchivo clienteArchivo;
    cantRegistros = clienteArchivo.getCantidadRegistros();
    Cliente *vec = new Cliente[cantRegistros];

    for (int i = 0; i < cantRegistros; i++)
    {
        reg = clienteArchivo.leer(i);
        vec[i] = reg;
    }

    for (int i = 0; i < cantRegistros - 1; i++)
    {
        for (int j = 0; j < cantRegistros - 1; j++)
        {
            if (vec[j].getFechaRegistro().getAnio() < vec[j + 1].getFechaRegistro().getAnio())
            {
                Cliente aux = vec[j];
                vec[j] = vec[j + 1];
                vec[j + 1] = aux;
            }
            else if (vec[j].getFechaRegistro().getAnio() == vec[j + 1].getFechaRegistro().getAnio())
            {
                if (vec[j].getFechaRegistro().getMes() < vec[j + 1].getFechaRegistro().getMes())
                {
                    Cliente aux = vec[j];
                    vec[j] = vec[j + 1];
                    vec[j + 1] = aux;
                }
                else if (vec[j].getFechaRegistro().getMes() == vec[j + 1].getFechaRegistro().getMes())
                {
                    if (vec[j].getFechaRegistro().getDia() < vec[j + 1].getFechaRegistro().getDia())
                    {
                        Cliente aux = vec[j];
                        vec[j] = vec[j + 1];
                        vec[j + 1] = aux;
                    }
                }
            }
        }
    }

    bool hayClientes = false;
    cout << "----------- CLIENTES ORDENADOS POR FECHA ----------- " << endl;
    for (int i = 0; i < cantRegistros; i++)
    {
        if (vec[i].getEstado())
        {
            hayClientes = true;
            cout << "----------------------------------------------------" << endl;
            mostrarCliente(vec[i]);
            cout << "----------------------------------------------------" << endl;
        }
    }
    if (!hayClientes)
    {
        cout << "----- NO HAY CLIENTES DISPONIBLES PARA MOSTRAR -----" << endl
             << endl;
    }

    delete[] vec;
}

void ClientesManager::volverClienteNoAptoAdopcion(Cliente registro)
{

    int pos = _clientesarchivo.buscarPorDni(registro.getDni());
    registro.setAptoAdopcion(false);
    bool guardo = _clientesarchivo.guardar(pos, registro);
    if (guardo)
    {
        cout << "Se cambio el estado a NO apto con exito!" << endl;
    }
}

void ClientesManager::Menu()
{
    int option;
    system("cls");
    do
    {
        system("cls");

        cout << "------ MENU CLIENTES ------- " << endl;
        cout << "1- AGREGAR CLIENTE " << endl;
        cout << "2- LISTAR TODOS LOS CLIENTES" << endl;
        cout << "3- MODIFICAR CLIENTE" << endl;
        cout << "4- ELIMINAR CLIENTE" << endl;
        cout << "-----------------------------" << endl;
        cout << "0- SALIR" << endl;
        cout << "Opcion: ";
        cin >> option;

        switch (option)
        {
        case 1:
            system("cls");
            agregarCliente();
            system("pause");
            break;
        case 2:
            system("cls");
            listarClientes();
            system("pause");
            break;
        case 3:
            system("cls");
            modificarCliente();
            system("pause");
            break;
        case 4:
            system("cls");
            eliminarCliente();
            system("pause");
            break;
        case 5:
            system("cls");
            listadoClientesOrdenadosPorDni();
            system("pause");
            break;
        }
    } while (option != 0);
}
