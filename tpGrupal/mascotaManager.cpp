#include <iostream>
#include <cstring>
#include "MascotaManager.h"
using namespace std;
void cargarCadena(char *pal, int tam);

void MascotasManager::mostrarMascota(Mascota mascota) {
    if(mascota.getEstado()){
        cout << "ID: " << mascota.getIdMascota() << endl;
        cout << "Nombre: " << mascota.getNombre() << endl;
        cout << "Especie: " << mascota.getEspecie() << endl;
        cout << "Raza: " << mascota.getRaza() << endl;
        cout << "Edad: " << mascota.getEdad() << endl;
        cout << "Genero: " << mascota.getGenero() << endl;
        cout << "Tamanio: " << mascota.getTamanio() << endl;
        cout << "Comportamiento: " << mascota.getComportamiento() << endl;
    }
}

void MascotasManager::agregarMascota() {
    if(_mascotasarchivo.guardar(crearMascota())) {
        cout << "La mascota fue guardada con éxito!" << endl;
    } else {
        cout << "No se pudo guardar la mascota!" << endl;
    }
}

void MascotasManager::listarMascotas() {
    system("cls");
    int cantidad = _mascotasarchivo.getCantidadRegistros();

    Mascota *mascotas = new Mascota[cantidad];

    if(mascotas == nullptr) {
        cout << "No se pudo pedir memoria..." << endl;
        return;
    }

    _mascotasarchivo.leerTodos(mascotas, cantidad);

    cout << "-------- MASCOTAS -------- " << endl;

    if(cantidad <= 0){
        cout << "NO HAY MASCOTAS DISPONIBLES " << endl;
    }
    else{
       for(int i = 0; i < cantidad; i++) {
        if(mascotas[i].getEstado()){
           cout << "--------------------------" << endl;
        mostrarMascota(mascotas[i]);
        cout << "--------------------------" << endl;
        }

        }
    }


    delete[] mascotas;
}

Mascota MascotasManager::crearMascota() {
    int edad, id;
    char nombre[30], especie[30], raza[30], comportamiento[30];
    char genero, tamanio;

    id = _mascotasarchivo.getNuevoID();

    cout << "ID: " << id << endl;
    cout << "Ingrese Nombre: ";
    cargarCadena(nombre,29);
    cout << "Ingrese Especie: ";
    cargarCadena(especie,29);
    cout << "Ingrese Raza: ";
    cargarCadena(raza,29);
    cout << "Ingrese Edad: ";
    cin >> edad;
    cout << "Ingrese Genero: ";
    cin >> genero;
    cout << "Ingrese Tamanio: ";
    cin >> tamanio;
    cout << "Ingrese Comportamiento: ";
    cin >> comportamiento;

    return Mascota(id, nombre, especie, raza, edad, genero, tamanio, comportamiento, true);
}

void MascotasManager::volverCargarMascota(Mascota &registro) {
    int id, edad;
    char nombre[30], especie[30], raza[30], comportamiento[30];
    char genero, tamanio;

    cout << "----- MODIFICANDO -----" << endl;
    cout << "Ingrese Nombre: ";
    cin >> nombre;
    cout << "Ingrese Especie: ";
    cin >> especie;
    cout << "Ingrese Raza: ";
    cin >> raza;
    cout << "Ingrese Edad: ";
    cin >> edad;
    cout << "Ingrese Genero: ";
    cin >> genero;
    cout << "Ingrese Tamanio: ";
    cin >> tamanio;
    cout << "Ingrese Comportamiento: ";
    cin >> comportamiento;

    registro.setIdMascota(id);
    registro.setNombre(nombre);
    registro.setEspecie(especie);
    registro.setRaza(raza);
    registro.setEdad(edad);
    registro.setGenero(genero);
    registro.setTamanio(tamanio);
    registro.setComportamiento(comportamiento);
    registro.setEstado(true);
}

void MascotasManager::modificarMascota() {
    int id;
    Mascota mascota;

    cout << "Ingrese ID de la mascota a modificar: ";
    cin >> id;

    int index = _mascotasarchivo.buscarByID(id);
    if(index != -1 ) mascota = _mascotasarchivo.leer(index);
    
    if(mascota.getEstado()) {
        

        mostrarMascota(mascota);

        volverCargarMascota(mascota);

        if(_mascotasarchivo.guardar(index, mascota)) {
            cout << "Se modificó con éxito!" << endl;
        } else {
            cout << "No se pudo modificar la mascota!" << endl;
        }
    } else {
        cout << "No se encuentra la mascota!" << endl;
    }
}

void MascotasManager::eliminarMascota() {
    int id;
    Mascota mascota;
    bool eliminar;

    cout << "Ingrese ID de la mascota a eliminar: ";
    cin >> id;

    int index = _mascotasarchivo.buscarByID(id);

    if(index != -1) {
        mascota = _mascotasarchivo.leer(index);

        mostrarMascota(mascota);

        cout << "¿Está seguro de que quiere eliminarla? 1-Si 0-No: ";
        cin >> eliminar;

        if(eliminar) {
            mascota.setEstado(false);
            if(_mascotasarchivo.guardar(index, mascota)) {
                cout << "Se eliminó con éxito!" << endl;
            } else {
                cout << "No se pudo eliminar la mascota!" << endl;
            }
        } else {
            cout << "La mascota no fue eliminada!" << endl;
        }
    } else {
        cout << "No se encuentra esa mascota!" << endl;
    }
}

void MascotasManager::listadoMascotasOrdenadasPorEspecie(){
    Mascota reg;
    int cantRegistros = 0;

    cantRegistros = _mascotasarchivo.getCantidadRegistros();

    Mascota *vec = new Mascota[cantRegistros];

    for(int i = 0; i < cantRegistros; i++)
    {
        reg = _mascotasarchivo.leer(i);
        vec[i] = reg;

    }

    for (int i = 0; i < cantRegistros - 1; i++)
    {
        for (int j = 0; j < cantRegistros - 1 - i; j++)
        {
            if (strcmp(vec[j].getEspecie(), vec[j + 1].getEspecie()) > 0)
            {
                Mascota aux = vec[j];
                vec[j] = vec[j + 1];
                vec[j + 1] = aux;
            }
        }
    }

    bool hayMascotas = false;
    system("cls");
    cout << "---------- MASCOTAS ORDENADAS POR ESPECIE --------- " << endl;
    for (int i = 0; i < cantRegistros; i++){
        if (vec[i].getEstado()){
            hayMascotas = true;
            cout << "---------------------------------------------------" << endl;
            mostrarMascota(vec[i]);
            cout << "---------------------------------------------------" << endl;
        }
    }
    if (!hayMascotas){
         cout << "---- NO HAY MASCOTAS DISPONIBLES PARA MOSTRAR -----" << endl << endl;
    }
    delete[] vec;
}


void MascotasManager::listadoMascotasOrdenadasPorRaza()
{
    Mascota reg;
    int cantRegistros = 0;

    cantRegistros = _mascotasarchivo.getCantidadRegistros();

    Mascota *vec = new Mascota[cantRegistros];

    for(int i = 0; i < cantRegistros; i++)
    {
        reg = _mascotasarchivo.leer(i);
        vec[i] = reg;
    }


    for (int i = 0; i < cantRegistros - 1; i++)
    {
        for (int j = 0; j < cantRegistros - 1 - i; j++)
        {
            if (strcmp(vec[j].getRaza(), vec[j + 1].getRaza()) > 0)
            {
                Mascota aux = vec[j];
                vec[j] = vec[j + 1];
                vec[j + 1] = aux;
            }
        }
    }

    bool hayMascotas = false;
    cout << "----------- MASCOTAS ORDENADAS POR RAZA ----------- " << endl;
    for (int i = 0; i < cantRegistros; i++)
    {
        if (vec[i].getEstado())
        {
            hayMascotas = true;
            cout << "----------------------------------------------------" << endl;
            mostrarMascota(vec[i]);
            cout << "----------------------------------------------------" << endl;
        }
    }
    if (!hayMascotas)
    {
         cout << "---- NO HAY MASCOTAS DISPONIBLES PARA MOSTRAR -----" << endl << endl;
    }
    delete[] vec;
}


void MascotasManager::listadoMascotasPorEspecie()
{
    char especieBuscada[30];
    Mascota reg;
    int cantRegistros = 0;

    cantRegistros = _mascotasarchivo.getCantidadRegistros();

    cout << "INGRESE ESPECIE A BUSCAR: ";
    cargarCadena(especieBuscada,29);
    system("cls");
    cout << "MASCOTAS DE LA ESPECIE: " << especieBuscada << endl;

    bool hayMascotas = false;
    for(int i = 0; i < cantRegistros; i++)
    {
        reg = _mascotasarchivo.leer(i);
        if (strcmp(reg.getEspecie(), especieBuscada) == 0 && reg.getEstado())
        {
            hayMascotas = true;
            cout << "----------------------------------------------------" << endl;
            mostrarMascota(reg);
            cout << "----------------------------------------------------" << endl;
        }
    }

    if (!hayMascotas)
    {
        cout << "---- NO HAY MASCOTAS DE LA ESPECIE BUSCADA DISPONIBLES PARA MOSTRAR -----" << endl << endl;
    }
}


void MascotasManager::listadoMascotasPorRaza()
{
    char razaBuscada[30];
    Mascota reg;
    int cantRegistros = 0;

    cantRegistros = _mascotasarchivo.getCantidadRegistros();

    cout << "INGRESE RAZA A BUSCAR: ";
    cargarCadena(razaBuscada,29);
    system("cls");
    cout << "MASCOTAS DE LA RAZA: " << razaBuscada << endl;

    bool hayMascotas = false;
    for(int i = 0; i < cantRegistros; i++)
    {
        reg = _mascotasarchivo.leer(i);
        if (strcmp(reg.getRaza(), razaBuscada) == 0 && reg.getEstado())
        {
            hayMascotas = true;
            cout << "----------------------------------------------------" << endl;
            mostrarMascota(reg);
            cout << "----------------------------------------------------" << endl;
        }
    }

    if (!hayMascotas)
    {
        cout << "---- NO HAY MASCOTAS DE LA RAZA BUSCADA DISPONIBLES PARA MOSTRAR -----" << endl << endl;
    }
}


void MascotasManager::buscarMascotaPorId(){
    int id;
    int pos;
    Mascota reg;

    cout << "INGRESE ID DE LA MASCOTA A BUSCAR: ";
    cin >> id;
    pos = _mascotasarchivo.buscarByID(id);

    reg = _mascotasarchivo.leer(pos);
    if (reg.getEstado() && pos >= 0){
        system("cls");
        cout << "--------------- MASCOTA ENCONTRADA -----------------" << endl;
        mostrarMascota(reg);
        cout << "----------------------------------------------------" << endl;
    }
    else{
        cout << "---- NO SE ENCONTRO LA MASCOTA CON EL ID INGRESADO -----" << endl << endl;
    }

}


void MascotasManager::Menu() {
    int option;
    system("cls");
    do {
        system("cls");

        cout << "------ MENU MASCOTAS ------- " << endl;
        cout << "1- AGREGAR MASCOTA " << endl;
        cout << "2- LISTAR TODAS LAS MASCOTAS" << endl;
        cout << "3- MODIFICAR MASCOTA" << endl;
        cout << "4- ELIMINAR MASCOTA" << endl;
        cout << "-----------------------------" << endl;
        cout << "0- SALIR" << endl;
        cout << "Opcion: ";
        cin >> option;

        switch(option) {
            case 1:
                system("cls");
                agregarMascota();
                system("pause");
                break;
            case 2:
                listarMascotas();
                system("pause");
                break;
            case 3:
                system("cls");
                modificarMascota();
                system("pause");
                break;
            case 4:
                system("cls");
                eliminarMascota();
                system("pause");
                break;
            case 5:
                system("cls");
                buscarMascotaPorId();
                system("pause");
                break;
        }
    } while(option != 0);
}
