#include <iostream>
#include "PersonaManager.h"

using namespace std;

void cargarCadena(char *pal, int tam);

void PersonasManager::mostrarPersona(Persona persona) {
    if(persona.getEstado()){
        cout << "DNI: " << persona.getDni() << endl;
        cout << "Nombre: " << persona.getNombre() << endl;
        cout << "Apellido: " << persona.getApellido() << endl;
        cout << "Telefono: " << persona.getTelefono() << endl;
        cout << "Direccion: " << persona.getDireccion() << endl;
        cout << "Email: " << persona.getEmail() << endl;
    }

}


void PersonasManager::agregarPersona() {
    Persona persona;
    persona = crearPersona();
    if (_personasarchivo.guardar(persona)  && persona.getEstado())
    {
        cout << "La persona fue guardado con exito!" << endl;
    }
    else if(_personasarchivo.guardar(persona) && !persona.getEstado()){
        cout << "Saliendo" << endl;
    }
    else
    {
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

    int leyo = 0;
    cout << "--------------------- PERSONAS --------------------- " << endl;
    for(int i = 0; i < cantidad; i++) {
        if(personas[i].getEstado()){
            leyo++;
            cout << "----------------------------------------------------" << endl;
            mostrarPersona(personas[i]);
            cout << "----------------------------------------------------" << endl;
        }

    }

    if(leyo == 0){
        cout << "----- NO HAY PERSONAS DISPONIBLES PARA MOSTRAR -----" << endl << endl;
    }

    delete[] personas;
}

Persona PersonasManager::crearPersona() {
    int dni, telefono;
    char nombre[30], apellido[30], direccion[30], email[30];
    bool estado;
    Persona persona;

    cout << "Ingrese DNI: ";
    cin >> dni;
    int pos = _personasarchivo.buscarPorDni(dni);
    if (pos >= 0) persona = _personasarchivo.leer(pos);




    while(pos >= 0 && persona.getEstado() && dni > 0){
        cout << "PERSONA YA EXISTENTE, INTENTE NUEVAMENTE " << endl;
        system("pause");
        system("cls");
        cout << "Ingrese DNI o 0 para salir: ";
        cin >> dni;
        pos = _personasarchivo.buscarPorDni(dni);
    }
    if (dni > 0)
    {
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

    else return Persona();


}

void PersonasManager::volverCargarPersona(Persona &registro){

    int dni, telefono;
    char nombre[30], apellido[30], direccion[30], email[30];


    cout << endl;
    cout << "----------- MODIFICANDO ------------" << endl;
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

    registro.setNombre(nombre);
    registro.setApellido(apellido);
    registro.setTelefono(telefono);
    registro.setDireccion(direccion);
    registro.setEmail(email);
    registro.setEstado(true);
}

void PersonasManager::modificarPersona() {
    int dni;
    Persona persona;

    cout << "Ingrese DNI de la persona a modificar: ";
    cin >> dni;

    int index = _personasarchivo.buscarPorDni(dni);

    if(index != -1) {
        persona = _personasarchivo.leer(index);

        system("cls");
        cout << "--- DATOS ACTUALES DE LA PERSONA ---" << endl;
        mostrarPersona(persona);

        volverCargarPersona(persona);


        if(_personasarchivo.guardar(index, persona)) {
            cout << "La persona fue modificada con exito!" << endl;
        } else {
            cout << "No se pudo modificar la persona!" << endl;
        }

    } else {
        cout << "No se encontro la persona con DNI: " << dni << endl;
    }

}

void PersonasManager::eliminarPersona(){
    int codigoPersona, index;
    Persona persona;
    bool eliminar;

    cout << "Ingrese DNI de la persona a eliminar: ";
    cin >> codigoPersona;

    index = _personasarchivo.buscarPorDni(codigoPersona);
    if (index >= 0) persona = _personasarchivo.leer(index);

    if(index != -1 && persona.getEstado())
    {
        persona = _personasarchivo.leer(index);
        system("cls");
        cout << "--- DATOS DE PERSONA A ELIMINAR ---" << endl;
        mostrarPersona(persona);

        cout << endl;
        cout << "Esta seguro de que quiere eliminarlo? 1-SI 0-NO: ";
        cin >> eliminar;

        if(eliminar){
            persona.setEstado(false);

            if(_personasarchivo.guardar(index, persona))
            {
                cout << "Se elimino con exito!" << endl;
            }
            else
            {
                cout << "No se pudo eliminar la persona!" << endl;
            }
        }
        else{
            cout << "La persona no fue eliminada!" << endl;

        }
    }
    else
    {
        cout << "No se encuentra esa persona!" << endl;
    }
}



void PersonasManager::Menu() {
    int opcion;

    do {
        system("cls");
        cout << "------ MENU PERSONAS ------- " << endl;
        cout << "1- AGREGAR PERSONA " << endl;
        cout << "2- LISTAR TODAS LAS PERSONAS" << endl;
        cout << "3- MODIFICAR PERSONAS" << endl;
        cout << "4- ELIMINAR PERSONA" << endl;
        cout << "0. SALIR" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;

        switch(opcion) {
            case 1:
                system("cls");
                agregarPersona();
                system("pause");
                break;
            case 2:
                system("cls");
                listarPersonas();
                system("pause");
                break;
            case 3:
                system("cls");
                modificarPersona();
                system("pause");
                break;
            case 4:
                system("cls");
                eliminarPersona();
                system("pause");
                break;
            case 0:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opcion invalida!" << endl;
                system("pause");
        }

    } while(opcion != 0);
}







