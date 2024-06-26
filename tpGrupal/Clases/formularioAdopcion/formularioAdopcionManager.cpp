#include <iostream>
#include "FormularioAdopcionManager.h"
using namespace std;

void cargarCadena(char *pal, int tam);

void FormularioAdopcionManager::agregarFormulario() {
    if(_formulariosAdopcionArchivo.guardar(crearFormulario())) {
        cout << "El formulario de adopción fue guardado con éxito!" << endl;
    } else {
        cout << "No se pudo guardar el formulario de adopción!" << endl;
    }
}

void FormularioAdopcionManager::listarFormularios() {
    int cantidad = _formulariosAdopcionArchivo.getCantidadRegistros();

    FormularioAdopcion *formularios = new FormularioAdopcion[cantidad];

    if(formularios == nullptr) {
        cout << "No se pudo pedir memoria..." << endl;
        return;
    }

    _formulariosAdopcionArchivo.leerTodos(formularios, cantidad);

    for(int i = 0; i < cantidad; i++) {
        cout << "--------------------------" << endl;
        mostrarFormulario(formularios[i]);
        cout << "--------------------------" << endl;
    }

    delete[] formularios;
}

FormularioAdopcion FormularioAdopcionManager::crearFormulario() {
    char nombreAdoptante[50];
    char direccion[100];
    char razonAdopcion[200];
    int idFormulario;

    idFormulario = _formulariosAdopcionArchivo.getNuevoID();

    cout << "ID: " << idFormulario << endl;
    cout << "Ingrese nombre del adoptante: ";
    cargarCadena(nombreAdoptante, 49);
    cout << "Ingrese dirección: ";
    cargarCadena(direccion, 99);
    cout << "Ingrese razón para adoptar: ";
    cargarCadena(razonAdopcion, 199);

    return FormularioAdopcion(idFormulario, nombreAdoptante, direccion, razonAdopcion);
}

void FormularioAdopcionManager::volverCargarFormulario(FormularioAdopcion &registro) {
    char nombreAdoptante[50];
    char direccion[100];
    char razonAdopcion[200];

    cout << "Ingrese nombre del adoptante: ";
    cargarCadena(nombreAdoptante, 49);
    cout << "Ingrese dirección: ";
    cargarCadena(direccion, 99);
    cout << "Ingrese razón para adoptar: ";
    cargarCadena(razonAdopcion, 199);

    registro.setNombreAdoptante(nombreAdoptante);
    registro.setDireccion(direccion);
    registro.setRazonAdopcion(razonAdopcion);
}

void FormularioAdopcionManager::mostrarFormulario(FormularioAdopcion registro) {
    cout << "ID: " << registro.getIdFormulario() << endl;
    cout << "Nombre del Adoptante: " << registro.getNombreAdoptante() << endl;
    cout << "Dirección: " << registro.getDireccion() << endl;
    cout << "Razón para adoptar: " << registro.getRazonAdopcion() << endl;
}

void FormularioAdopcionManager::modificarFormulario() {
    int idFormulario, index;
    FormularioAdopcion formulario;

    cout << "Ingrese id del formulario a modificar: ";
    cin >> idFormulario;

    index = _formulariosAdopcionArchivo.buscarByID(idFormulario);

    if(index != -1) {
        formulario = _formulariosAdopcionArchivo.leer(index);

        mostrarFormulario(formulario);

        volverCargarFormulario(formulario);

        if(_formulariosAdopcionArchivo.guardar(index, formulario)) {
            cout << "Se modificó con éxito!" << endl;
        } else {
            cout << "No se pudo modificar el formulario!" << endl;
        }
    } else {
        cout << "No se encuentra ese formulario!" << endl;
    }
}

void FormularioAdopcionManager::eliminarFormulario() {
    int idFormulario, index;
    FormularioAdopcion formulario;
    bool eliminar;

    cout << "Ingrese id del formulario a eliminar: ";
    cin >> idFormulario;

    index = _formulariosAdopcionArchivo.buscarByID(idFormulario);

    if(index != -1) {
        formulario = _formulariosAdopcionArchivo.leer(index);

        mostrarFormulario(formulario);

        cout << "¿Está seguro de que quiere eliminarlo? 1-Sí 0-No: ";
        cin >> eliminar;

        if(eliminar) {
            if(_formulariosAdopcionArchivo.eliminar(index)) {
                cout << "Se eliminó con éxito!" << endl;
            } else {
                cout << "No se pudo eliminar el formulario!" << endl;
            }
        } else {
            cout << "El formulario no fue eliminado!" << endl;
        }
    } else {
        cout << "No se encuentra ese formulario!" << endl;
    }
}

void FormularioAdopcionManager::Menu() {
    int opcion;
    do {
        system("cls");

        cout << "------ MENÚ FORMULARIOS DE ADOPCIÓN -------" << endl;
        cout << "1- Agregar formulario" << endl;
        cout << "2- Listar formularios" << endl;
        cout << "3- Modificar formulario" << endl;
        cout << "4- Eliminar formulario" << endl;
        cout << "-------------------------------------------" << endl;
        cout << "0- Salir" << endl;
        cout << "Opción: ";
        cin >> opcion;

        switch(opcion) {
            case 1:
                agregarFormulario();
                system("pause");
                break;
            case 2:
                listarFormularios();
                system("pause");
                break;
            case 3:
                modificarFormulario();
                system("pause");
                break;
            case 4:
                eliminarFormulario();
                system("pause");
                break;
        }
    } while(opcion != 0);
}

void cargarCadena(char *pal, int tam) {
    int i;
    fflush (stdin);
    for(i=0; i<tam;i++){
        pal[i]=cin.get();
        if(pal[i]=='\n')break;
    }
    pal[i]='\0';
    fflush(stdin);
}