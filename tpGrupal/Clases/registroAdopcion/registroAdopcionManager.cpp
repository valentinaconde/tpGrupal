#include <iostream>
#include "RegistroAdopcionManager.h" // Asegúrate de tener este archivo de cabecera y definir la clase adecuadamente
using namespace std;

void RegistroAdopcionManager::agregarRegistroAdopcion(){
    if(_registroAdopcionArchivo.guardar(crearRegistroAdopcion())){
        cout << "El registro de adopción fue guardado con éxito!" << endl;
    }
    else{
        cout << "No se pudo guardar el registro de adopción!" << endl;
    }
}

void RegistroAdopcionManager::listarRegistrosAdopcion(){
    int cantidad = _registroAdopcionArchivo.getCantidadRegistros();

    RegistroAdopcion *registrosAdopcion;

    registrosAdopcion = new RegistroAdopcion[cantidad];

    if(registrosAdopcion == nullptr)
    {
        cout << "No se pudo pedir memoria... " << endl;
        return;
    }

    _registroAdopcionArchivo.leerTodos(registrosAdopcion, cantidad);

    for(int i=0; i<cantidad; i++)
    {
        if(registrosAdopcion[i].getEstado())
        {
            cout << "--------------------------" << endl;
            mostrarRegistroAdopcion(registrosAdopcion[i]);
            cout << "--------------------------" << endl;
        }
    }

    delete [] registrosAdopcion;
}

RegistroAdopcion RegistroAdopcionManager::crearRegistroAdopcion(){
    int id;
    int idMascota;
    int idAdoptante;
    string fechaAdopcion;

    id = _registroAdopcionArchivo.getNuevoID();

    cout << "ID: " << id << endl;
    cout << "Ingrese ID de la Mascota: ";
    cin >> idMascota;
    cout << "Ingrese ID del Adoptante: ";
    cin >> idAdoptante;
    cout << "Ingrese Fecha de Adopción: ";
    cin >> fechaAdopcion;

    return RegistroAdopcion(id, idMascota, idAdoptante, fechaAdopcion);
}

void RegistroAdopcionManager::modificarRegistroAdopcion(){
    int id, index;
    RegistroAdopcion registroAdopcion;

    cout << "Ingrese ID del registro de adopción a modificar: ";
    cin >> id;

    index = _registroAdopcionArchivo.buscarByID(id);

    if(index != -1)
    {
        registroAdopcion = _registroAdopcionArchivo.leer(index);

        mostrarRegistroAdopcion(registroAdopcion);

        volverCargarRegistroAdopcion(registroAdopcion);

        if(_registroAdopcionArchivo.guardar(index, registroAdopcion))
        {
            cout << "Se modificó con éxito!" << endl;
        }
        else
        {
            cout << "No se pudo modificar el registro de adopción!" << endl;
        }
    }
    else
    {
        cout << "No se encuentra el registro de adopción!" << endl;
    }
}

void RegistroAdopcionManager::eliminarRegistroAdopcion(){
    int id, index;
    RegistroAdopcion registroAdopcion;
    bool eliminar;

    cout << "Ingrese id del registro de adopción a eliminar: ";
    cin >> id;

    index = _registroAdopcionArchivo.buscarByID(id);

    if(index != -1)
    {
        registroAdopcion = _registroAdopcionArchivo.leer(index);

        mostrarRegistroAdopcion(registroAdopcion);

        cout << "Está seguro de que quiere eliminarlo? 1-Si 0-No: ";
        cin >> eliminar;

        if(eliminar){
            registroAdopcion.setEstado(false);

            if(_registroAdopcionArchivo.guardar(index, registroAdopcion))
            {
                cout << "Se eliminó con éxito!" << endl;
            }
            else
            {
                cout << "No se pudo eliminar el registro de adopción!" << endl;
            }
        }
        else{
            cout << "El registro no fue eliminado!" << endl;
        }
    }
    else
    {
        cout << "No se encuentra ese registro!" << endl;
    }
}

void RegistroAdopcionManager::Menu(){
    int option;
    system("cls");
    do
    {
        system("cls");

        cout << "------ MENU REGISTRO ADOPCION ------- " << endl;
        cout << "1- AGREGAR REGISTRO ADOPCION " << endl;
        cout << "2- LISTAR TODOS REGISTROS ADOPCION" << endl;
        cout << "3- MODIFICAR REGISTRO ADOPCION" << endl;
        cout << "4- ELIMINAR REGISTRO ADOPCION" << endl;
        cout << "-----------------------------" << endl;
        cout << "0- SALIR" << endl;
        cout << "Opcion: ";
        cin >> option;

        switch(option)
        {
        case 1:
            agregarRegistroAdopcion();
            system("pause");
            break;

        case 2:
            listarRegistrosAdopcion();
            system("pause");
            break;

        case 3:
            modificarRegistroAdopcion();
            system("pause");
            break;

        case 4:
            eliminarRegistroAdopcion();
            system("pause");
            break;
        }
    }
    while(option != 0);
}