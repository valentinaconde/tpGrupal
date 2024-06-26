#include <iostream>
#include "ClienteManager.h" // Asegúrate de tener este archivo y que esté correctamente implementado
using namespace std;

void ClientesManager::agregarCliente() {
    if(_clientesarchivo.guardar(crearCliente())) {
        cout << "El cliente fue guardado con éxito!" << endl;
    } else {
        cout << "No se pudo guardar el cliente!" << endl;
    }
}

void ClientesManager::listarClientes() {
    int cantidad = _clientesarchivo.getCantidadRegistros();

    Cliente *clientes = new Cliente[cantidad];

    if(clientes == nullptr) {
        cout << "No se pudo pedir memoria..." << endl;
        return;
    }

    _clientesarchivo.leerTodos(clientes, cantidad);

    for(int i = 0; i < cantidad; i++) {
        if(clientes[i].getEstado()) { // Asumiendo que Cliente tiene un método getEstado()
            cout << "--------------------------" << endl;
            mostrarCliente(clientes[i]);
            cout << "--------------------------" << endl;
        }
    }

    delete[] clientes;
}

Cliente ClientesManager::crearCliente() {
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
    fechaRegistro.cargarFecha();
    cout << "¿Apto para adopción? (1 para sí, 0 para no): ";
    cin >> aptoAdopcion;

    return Cliente(dni, nombre, apellido, telefono, direccion, email, estado, fechaRegistro, aptoAdopcion);
}

void ClientesManager::modificarCliente() {
    int dni;
    Cliente cliente;

    cout << "Ingrese DNI del cliente a modificar: ";
    cin >> dni;

    int index = _clientesarchivo.buscarByID(dni);

    if(index != -1) {
        cliente = _clientesarchivo.leer(index);

        mostrarCliente(cliente);

        // Aquí deberías tener una función para recargar los datos del cliente, similar a volverCargarDetalleCompra()
        // Por simplicidad, se omite esa implementación.

        if(_clientesarchivo.guardar(index, cliente)) {
            cout << "Se modificó con éxito!" << endl;
        } else {
            cout << "No se pudo modificar el cliente!" << endl;
        }
    } else {
        cout << "No se encuentra el cliente!" << endl;
    }
}

void ClientesManager::eliminarCliente() {
    int dni;
    Cliente cliente;
    bool eliminar;

    cout << "Ingrese DNI del cliente a eliminar: ";
    cin >> dni;

    int index = _clientesarchivo.buscarByID(dni);

    if(index != -1) {
        cliente = _clientesarchivo.leer(index);

        mostrarCliente(cliente);

        cout << "¿Está seguro de que quiere eliminarlo? 1-Si 0-No: ";
        cin >> eliminar;

        if(eliminar) {
            cliente.setEstado(false); // Asumiendo que Cliente tiene un método setEstado()

            if(_clientesarchivo.guardar(index, cliente)) {
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

void ClientesManager::mostrarCliente(Cliente cliente) {
    cout << "DNI: " << cliente.getDni() << endl; // Asumiendo que Cliente tiene un método getDNI()
    cout << "Nombre: " << cliente.getNombre() << endl; // Asumiendo que Cliente tiene un método getNombre()
    cout << "Apellido: " << cliente.getApellido() << endl; // Asumiendo que Cliente tiene un método getApellido()
    // Continúa mostrando el resto de los atributos de la misma manera
}

void ClientesManager::Menu() {
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
