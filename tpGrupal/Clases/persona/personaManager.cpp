#include <iostream>
#include "PersonaManager.h" // Asegúrate de tener este archivo y que esté correctamente implementado
using namespace std;

class PersonaManager {
private:
    ArchivoPersona _personaArchivo; // Asumiendo que ArchivoPersona es una clase para manejar el archivo de personas

public:
    void agregarPersona();
    void listarPersonas();
    Persona crearPersona(); // Asumiendo que Persona es una clase ya definida
    void modificarPersona();
    void eliminarPersona();
    void mostrarPersona(Persona persona);
    void Menu();
};

void PersonaManager::agregarPersona() {
    if(_personaArchivo.guardar(crearPersona())) {
        cout << "La persona fue guardada con éxito!" << endl;
    } else {
        cout << "No se pudo guardar la persona!" << endl;
    }
}

void PersonaManager::listarPersonas() {
    int cantidad = _personaArchivo.getCantidadRegistros();

    Persona *personas = new Persona[cantidad];

    if(personas == nullptr) {
        cout << "No se pudo pedir memoria..." << endl;
        return;
    }

    _personaArchivo.leerTodos(personas, cantidad);

    for(int i = 0; i < cantidad; i++) {
        cout << "--------------------------" << endl;
        mostrarPersona(personas[i]);
        cout << "--------------------------" << endl;
    }

    delete[] personas;
}

Persona PersonaManager::crearPersona() {
    int dni, telefono;
    char nombre[30], apellido[30], direccion[30], email[30];
    Fecha fechaNacimiento;


    cout << "Ingrese DNI: ";
    cin >> dni;
    cout << "Ingrese Nombre: ";
    cin >> nombre;
    cout << "Ingrese Apellido: ";
    cin >> apellido;
    cout << "Ingrese Fecha de Nacimiento (dd mm aaaa): ";
    cin >> fechaNacimiento.dia >> fechaNacimiento.mes >> fechaNacimiento.anio;


    /*
           int _dni;
        char _nombre[30];
        char _apellido[30];
        int _telefono;
        char _direccion[30];
        char _email[30];
        bool _estado;
        
    cout << "Ingrese DNI: ";
    cin >> dni;
    cout << "Ingrese Nombre: ";
    cargarCadena(nombre,29);
    cout << "Ingrese Apellido: ";
    cargarCadena(apellido,29);
    cout << "Ingrese Fecha de Nacimiento (dd mm aaaa): ";
    fechaNacimiento.cargarFecha();
    cout << "Ingrese Telefono: ";
    cin >> telefono;
    cout << "Ingrese Direccion: ";
    cargarCadena(direccion,29);
    cout << "Ingrese Email: ";
    cargarCadena(email,29);

    
    */

    return Persona(dni, nombre, apellido, fechaNacimiento, telefono, direccion, email, true);
}

void PersonaManager::modificarPersona() {
    int dni;
    Persona persona;

    cout << "Ingrese DNI de la persona a modificar: ";
    cin >> dni;

    int index = _personaArchivo.buscarPorDNI(dni);

    if(index != -1) {
        persona = _personaArchivo.leer(index);

        mostrarPersona(persona);

        volverCargarPersona(persona);


        if(_personaArchivo.guardar(index, persona)) {
            cout << "La persona fue modificada con éxito!" << endl;
        } else {
            cout << "No se pudo modificar la persona!" << endl;
        }

    } else {
        cout << "No se encontró la persona con DNI: " << dni << endl;
    }

}

void PersonaManager::eliminarPersona() {
    int dni;

    cout << "Ingrese DNI de la persona a eliminar: ";
    cin >> dni;

    int index = _personaArchivo.buscarPorDNI(dni);

    if(index != -1) {
        if(_personaArchivo.eliminar(index)) {
            cout << "La persona fue eliminada con éxito!" << endl;
        } else {
            cout << "No se pudo eliminar la persona!" << endl;
        }
    } else {
        cout << "No se encontró la persona con DNI: " << dni << endl;
    }
}

void PersonaManager::mostrarPersona(Persona persona) {
    cout << "DNI: " << persona.getDni() << endl;
    cout << "Nombre: " << persona.getNombre() << endl;
    cout << "Apellido: " << persona.getApellido() << endl;
    cout << "Fecha de Nacimiento: " << persona.getFechaNacimiento().dia << "/" << persona.getFechaNacimiento().mes << "/" << persona.getFechaNacimiento().anio << endl;
}


void PersonaManager::Menu() {
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







