#include <iostream>
#include "PersonaManager.h"

using namespace std;

void cargarCadena(char *pal, int tam);

void PersonasManager::agregarPersona() {
    if(_personasarchivo.guardar(crearPersona())) {
        cout << "La persona fue guardada con éxito!" << endl;
    } else {
        cout << "No se pudo guardar la persona!" << endl;
    }
}

void PersonasManager::listarPersonas() {
    int cantidad = _personasarchivo.getCantidadRegistros();

    Persona *personas = new Persona[cantidad];

    if(personas == nullptr) {
        cout << "No se pudo pedir memoria..." << endl;
        return;
    }

    _personasarchivo.leerTodos(personas, cantidad);

    for(int i = 0; i < cantidad; i++) {
        cout << "--------------------------" << endl;
        mostrarPersona(personas[i]);
        cout << "--------------------------" << endl;
    }

    delete[] personas;
}

Persona PersonasManager::crearPersona() {
    int dni, telefono;
    char nombre[30], apellido[30], direccion[30], email[30];
    bool estado;

    cout << "Ingrese DNI: ";
    cin >> dni;
    cout << "Ingrese Nombre: ";
    cargarCadena(nombre,29);
    cout << "Ingrese Apellido: ";
    cargarCadena(apellido,29);
    cout << "Ingrese Telefono: ";
    cin >> telefono;
    cout << "Ingrese Direccion: ";
    cargarCadena(direccion,29);
    cout << "Ingrese Email: ";
    cargarCadena(email,29);
    estado = true;

    return Persona(dni, nombre, apellido, telefono, direccion, email, estado);

}

void PersonasManager::modificarPersona() {
    int dni;
    Persona persona;

    cout << "Ingrese DNI de la persona a modificar: ";
    cin >> dni;

    int index = _personasarchivo.buscarPorDni(dni);

    if(index != -1) {
        persona = _personasarchivo.leer(index);

        mostrarPersona(persona);

        //volverCargarPersona(persona);


        if(_personasarchivo.guardar(index, persona)) {
            cout << "La persona fue modificada con éxito!" << endl;
        } else {
            cout << "No se pudo modificar la persona!" << endl;
        }

    } else {
        cout << "No se encontró la persona con DNI: " << dni << endl;
    }

}

void PersonasManager::eliminarPersona() {
  /*  int dni;

    cout << "Ingrese DNI de la persona a eliminar: ";
    cin >> dni;

    int index = _personasarchivo.buscarPorDni(dni);

    if(index != -1) {
        if(_personasarchivo.eliminar(index)) {
            cout << "La persona fue eliminada con éxito!" << endl;
        } else {
            cout << "No se pudo eliminar la persona!" << endl;
        }
    } else {
        cout << "No se encontró la persona con DNI: " << dni << endl;
    }

    */
}

void PersonasManager::mostrarPersona(Persona persona) {
    cout << "DNI: " << persona.getDni() << endl;
    cout << "Nombre: " << persona.getNombre() << endl;
    cout << "Apellido: " << persona.getApellido() << endl;
    cout << "Telefono: " << persona.getTelefono() << endl;
    cout << "Direccion: " << persona.getDireccion() << endl;
    cout << "Email: " << persona.getEmail() << endl;
    cout << "Estado: " << (persona.getEstado() ? "Activo" : "Inactivo") << endl;
}


void PersonasManager::Menu() {
    int opcion;

    do {
        cout << "1. Agregar Persona" << endl;
        cout << "2. Listar Personas" << endl;
        cout << "3. Modificar Persona" << endl;
        cout << "4. Eliminar Persona" << endl;
        cout << "0. Salir" << endl;
        cout << "Ingrese una opción: ";
        cin >> opcion;

        switch(opcion) {
            case 1:
                agregarPersona();
                break;
            case 2:
                listarPersonas();
                break;
            case 3:
                modificarPersona();
                break;
            case 4:
                eliminarPersona();
                break;
            case 0:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opción inválida!" << endl;
        }

    } while(opcion != 0);
}







