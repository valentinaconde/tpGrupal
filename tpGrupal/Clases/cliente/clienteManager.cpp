#include <iostream>
#include "ClienteManager.h" // Asegúrate de tener este archivo y que esté correctamente implementado
using namespace std;

void ClienteManager::agregarCliente() {
    if(_clienteArchivo.guardar(crearCliente())) {
        cout << "El cliente fue guardado con éxito!" << endl;
    } else {
        cout << "No se pudo guardar el cliente!" << endl;
    }
}

void ClienteManager::listarClientes() {
    int cantidad = _clienteArchivo.getCantidadRegistros();

    Cliente *clientes = new Cliente[cantidad];

    if(clientes == nullptr) {
        cout << "No se pudo pedir memoria..." << endl;
        return;
    }

    _clienteArchivo.leerTodos(clientes, cantidad);

    for(int i = 0; i < cantidad; i++) {
        if(clientes[i].getEstado()) { // Asumiendo que Cliente tiene un método getEstado()
            cout << "--------------------------" << endl;
            mostrarCliente(clientes[i]);
            cout << "--------------------------" << endl;
        }
    }

    delete[] clientes;
}

Cliente ClienteManager::crearCliente() {
    int dni;
    char nombre[30], apellido[30], direccion[30], email[30];
    int telefono;
    bool estado, aptoAdopcion;
    Fecha fechaRegistro; // Asumiendo que Fecha es una estructura o clase ya definida

    cout << "Ingrese DNI: ";
    cin >> dni;
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
    cout << "Ingrese Estado (1 para activo, 0 para inactivo): ";
    cin >> estado;
    cout << "Ingrese Fecha de Registro (dd mm aaaa): ";
    cin >> fechaRegistro.dia >> fechaRegistro.mes >> fechaRegistro.anio;
    cout << "¿Apto para adopción? (1 para sí, 0 para no): ";
    cin >> aptoAdopcion;

    return Cliente(dni, nombre, apellido, telefono, direccion, email, estado, fechaRegistro, aptoAdopcion);
}

void ClienteManager::modificarCliente() {
    int dni;
    Cliente cliente;

    cout << "Ingrese DNI del cliente a modificar: ";
    cin >> dni;

    int index = _clienteArchivo.buscarPorDNI(dni);

    if(index != -1) {
        cliente = _clienteArchivo.leer(index);

        mostrarCliente(cliente);

        // Aquí deberías tener una función para recargar los datos del cliente, similar a volverCargarDetalleCompra()
        // Por simplicidad, se omite esa implementación.

        if(_clienteArchivo.guardar(index, cliente)) {
            cout << "Se modificó con éxito!" << endl;
        } else {
            cout << "No se pudo modificar el cliente!" << endl;
        }
    } else {
        cout << "No se encuentra el cliente!" << endl;
    }
}

void ClienteManager::eliminarCliente() {
    int dni;
    Cliente cliente;
    bool eliminar;

    cout << "Ingrese DNI del cliente a eliminar: ";
    cin >> dni;

    int index = _clienteArchivo.buscarPorDNI(dni);

    if(index != -1) {
        cliente = _clienteArchivo.leer(index);

        mostrarCliente(cliente);

        cout << "¿Está seguro de que quiere eliminarlo? 1-Si 0-No: ";
        cin >> eliminar;

        if(eliminar) {
            cliente.setEstado(false); // Asumiendo que Cliente tiene un método setEstado()

            if(_clienteArchivo.guardar(index, cliente)) {
                cout << "Se eliminó con éxito!" << endl;
            } else {
                cout << "No se pudo eliminar el cliente!" << endl;
            }
        } else {
            cout << "El cliente no fue eliminado!" << endl;
        }
    } else {
        cout << "No se encuentra ese cliente!" << endl;
    }
}

void ClienteManager::mostrarCliente(Cliente cliente) {
    cout << "DNI: " << cliente.getDNI() << endl; // Asumiendo que Cliente tiene un método getDNI()
    cout << "Nombre: " << cliente.getNombre() << endl; // Asumiendo que Cliente tiene un método getNombre()
    cout << "Apellido: " << cliente.getApellido() << endl; // Asumiendo que Cliente tiene un método getApellido()
    // Continúa mostrando el resto de los atributos de la misma manera
}

void ClienteManager::Menu() {
    int option;
    system("cls");
    do {
        system("cls");

        cout << "------ MENU CLIENTES ------- " << endl;
        cout << "1- AGREGAR CLIENTE " << endl;
        cout << "2- LISTAR TODOS LOS CLIENTES" << endl;
        cout << "3- MODIFICAR CLIENTE" << endl;
        cout << "4- ELIMINAR CLIENTE" << endl;
        cout << "-----------------------------" << endl;
        cout << "0- SALIR" << endl;
        cout << "Opción: ";
        cin >> option;

        switch(option) {
            case 1:
                agregarCliente();
                system("pause");
                break;
            case 2:
                listarClientes();
                system("pause");
                break;
            case 3:
                modificarCliente();
                system("pause");
                break;
            case 4:
                eliminarCliente();
                system("pause");
                break;
        }
    } while(option != 0);
}