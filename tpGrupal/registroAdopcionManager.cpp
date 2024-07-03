#include <iostream>
#include "RegistroAdopcionManager.h"
#include "formularioAdopcionManager.h"
#include "FormularioAdopcion.h"
#include "mascota.h"
#include "mascotaManager.h"
using namespace std;

void RegistroAdopcionManager::mostrarRegistroAdopcion(RegistroAdopcion registro)
{

    if (registro.getEstado())
    {

        FormularioAdopcionManager formManager;
        FormularioAdopcion form;
        MascotasManager mascManager;
        Mascota mascota;

        int pos = formManager._formulariosAdopcionArchivo.buscarByID(registro.getIdAdopcion());
        form = formManager._formulariosAdopcionArchivo.leer(pos);

        int posMascota = mascManager._mascotasarchivo.buscarByID(form.getIdMascota());
        mascota = mascManager._mascotasarchivo.leer(posMascota);

        cout << "ID REGISTRO DE ADOPCION: " << registro.getIdRegistro() << endl;
        cout << "------------------------------" << endl;
        cout << "ID FORMULARIO DE ADOPCION: " << registro.getIdAdopcion() << endl;
        cout << "------------------------------" << endl;
        cout << "CLIENTE:" << endl;
        cout << "NOMBRE: " << form.getCliente().getNombre() << endl;
        cout << "APELLIDO: " << form.getCliente().getApellido() << endl;
        cout << "DNI: " << form.getCliente().getDni() << endl;
        cout << "TELEFONO: " << form.getCliente().getTelefono() << endl;
        cout << "EMAIL: " << form.getCliente().getEmail() << endl;
        cout << "DIRECCION: " << form.getCliente().getDireccion() << endl;
        cout << "------------------------------" << endl;
        cout << "MASCOTA:" << endl;
        cout << "ID MASCOTA: " << mascota.getIdMascota() << endl;
        cout << "NOMBRE: " << mascota.getNombre() << endl;
        cout << "ESPECIE: " << mascota.getEspecie() << endl;
        cout << "RAZA: " << mascota.getRaza() << endl;
        cout << "EDAD: " << mascota.getEdad() << endl;
        cout << "GENERO: " << mascota.getGenero() << endl;
        cout << "TAMANIO: " << mascota.getTamanio() << endl;
        cout << "COMPORTAMIENTO: " << mascota.getComportamiento() << endl;
        cout << "------------------------------" << endl;

        cout << "FECHA: ";
        registro.getFechaRegistro().mostrarFecha();
    }
}

void RegistroAdopcionManager::volverCargarRegistroAdopcion(RegistroAdopcion &registro)
{
    int idAdopcion;
    Fecha fecha;
    FormularioAdopcionArchivo formArchivo;

    cout << "ID: " << registro.getIdRegistro() << endl;
    cout << "ID FORMULARIO DE ADOPCION: ";
    cin >> idAdopcion;
    int pos = formArchivo.buscarByID(idAdopcion);

    while (pos < 0)
    {
        cout << "FORMULARIO DE ARCHIVO INEXISTENTE, INTENTE NUEVAMENTE " << endl;
        cout << "ID FORMULARIO DE ADOPCION: ";
        cin >> idAdopcion;
        pos = formArchivo.buscarByID(idAdopcion);
    }

    cout << "FECHA: " << endl;
    fecha.cargarFecha();

    registro.setIdAdopcion(idAdopcion);
    registro.setFechaRegistro(fecha);
}

void RegistroAdopcionManager::agregarRegistroAdopcion()
{
    if (_registroAdopcionArchivo.guardar(crearRegistroAdopcion()))
    {
        cout << "El registro de adopcion fue guardado con exito!" << endl;
    }
    else
    {
        cout << "No se pudo guardar el registro de adopcion!" << endl;
    }
}

void RegistroAdopcionManager::listarRegistrosAdopcion()
{
    int cantidad = _registroAdopcionArchivo.getCantidadRegistros();

    RegistroAdopcion *registrosAdopcion;

    registrosAdopcion = new RegistroAdopcion[cantidad];

    if (registrosAdopcion == nullptr)
    {
        cout << "No se pudo pedir memoria... " << endl;
        return;
    }

    _registroAdopcionArchivo.leerTodos(registrosAdopcion, cantidad);

    system("cls");
    cout << "--------- REGISTROS DE ADOPCION ---------" << endl;
    for (int i = 0; i < cantidad; i++)
    {
        if (registrosAdopcion[i].getIdRegistro() != -1)
        {
            if(registrosAdopcion[i].getEstado()){
            cout << "--------------------------------------------" << endl;
            mostrarRegistroAdopcion(registrosAdopcion[i]);
            cout << "--------------------------------------------" << endl;
            }
        }
    }

    if (cantidad == 0)
    {
        cout << "NO HAY REGISTROS DE ADOPCION DISPONIBLES PARA MOSTRAR" << endl
             << endl;
    }

    delete[] registrosAdopcion;
}

RegistroAdopcion RegistroAdopcionManager::crearRegistroAdopcion()
{
    int id, idAdopcion;
    Fecha fecha;
    FormularioAdopcionArchivo formArchivo;
    FormularioAdopcion formAdopcion;

    id = _registroAdopcionArchivo.getNuevoID();

    cout << "ID: " << id << endl;
    cout << "ID FORMULARIO DE ADOPCION: ";
    cin >> idAdopcion;
    int pos = formArchivo.buscarByID(idAdopcion);
    if (pos >= 0)
        formAdopcion = formArchivo.leer(pos);

    int cantReg = _registroAdopcionArchivo.getCantidadRegistros();
    bool existeRegistro = false;

    bool flag = true;
    while ((pos < 0 || !formAdopcion.getEstado() || existeRegistro) && flag)
    {
        if (pos < 0 || !formAdopcion.getEstado())
        {
            cout << "FORMULARIO DE ARCHIVO INEXISTENTE, INTENTE NUEVAMENTE " << endl;
            cout << "ID FORMULARIO DE ADOPCION O 0 PARA SALIR: ";
            cin >> idAdopcion;
            if (idAdopcion == 0)
            {
                return RegistroAdopcion();
            }
        }

        if (!existeRegistro)
        {
            existeRegistro = false;
            for (int i = 0; i < cantReg; i++)
            {
                if (_registroAdopcionArchivo.leer(i).getIdAdopcion() == idAdopcion && _registroAdopcionArchivo.leer(i).getIdRegistro() != -1)
                {
                    existeRegistro = true;
                }
            }
        }

        if (existeRegistro)
        {
            cout << "YA EXISTE REGISTRO PARA ESE ID DE ADOPCION, INGRESE OTRO" << endl;
            cout << "ID FORMULARIO DE ADOPCION O 0 PARA SALIR: ";
            cin >> idAdopcion;
            if (idAdopcion == 0)
            {
                return RegistroAdopcion();
            }
        }

        pos = formArchivo.buscarByID(idAdopcion);
        if (pos >= 0)
            formAdopcion = formArchivo.leer(pos);
    }

    if (flag)
    {
        pos = formArchivo.buscarByID(idAdopcion);
        if (pos >= 0)
            formAdopcion = formArchivo.leer(pos);
        formAdopcion.setEstado(false);
        formArchivo.guardar(pos, formAdopcion);

        cout << "INGRESE FECHA: " << endl;
        fecha.cargarFecha();

        MascotasManager mascotaManager;
        Mascota mascota;
        int posMascota = mascotaManager._mascotasarchivo.buscarByID(formAdopcion.getIdMascota());
        mascota = mascotaManager._mascotasarchivo.leer(posMascota);
        mascota.setEstado(false);
        mascotaManager._mascotasarchivo.guardar(posMascota, mascota);

        int cantRegForm = formArchivo.getCantidadRegistros();
        for (int i = 0; i < cantRegForm; i++)
        {
            formAdopcion = formArchivo.leer(i);
            if (formAdopcion.getIdMascota() == mascota.getIdMascota() && formAdopcion.getEstado())
            {
                formAdopcion.setEstado(false);
                formArchivo.guardar(i, formAdopcion);
            }
        }

        return RegistroAdopcion(id, idAdopcion, fecha, true);
    }
    else
        return RegistroAdopcion();
}

void RegistroAdopcionManager::modificarRegistroAdopcion()
{
    int id, index;
    RegistroAdopcion registroAdopcion;

    cout << "Ingrese ID del registro de adopcion a modificar: ";
    cin >> id;

    cout << endl;

    RegistroAdopcion registro;
    index = _registroAdopcionArchivo.buscarByID(id);
    if (index != -1 ) registro = _registroAdopcionArchivo.leer(index);
    if (index != -1 && registro.getEstado())
    {
        registroAdopcion = _registroAdopcionArchivo.leer(index);

        mostrarRegistroAdopcion(registroAdopcion);

        cout << endl;
        cout << "----- MODIFICANDO -----" << endl;

        volverCargarRegistroAdopcion(registroAdopcion);

        if (_registroAdopcionArchivo.guardar(index, registroAdopcion))
        {
            cout << "Se modifico con exito!" << endl;
        }
        else
        {
            cout << "No se pudo modificar el registro de adopcion!" << endl;
        }
    }
    else
    {
        cout << "No se encuentra el registro de adopcion!" << endl;
    }
}

void RegistroAdopcionManager::buscarRegistroPorId()
{

    int id;
    cout << "Ingrese el ID del registro de adopcion a buscar: ";
    cin >> id;

    int pos = _registroAdopcionArchivo.buscarByID(id);

    if (pos >= 0)
    {
        mostrarRegistroAdopcion(_registroAdopcionArchivo.leer(pos));
    }
    else
    {
        cout << "NO SE ENCONTRO EL REGISTRO DE ADOPCION" << endl;
    }
}

void RegistroAdopcionManager::buscarRegistroPorAdopcionId()
{
    RegistroAdopcionManager registroManager;
    int id;
    cout << "Ingrese el ID del formulario de adopcion a buscar: ";
    cin >> id;

    int cantReg = registroManager._registroAdopcionArchivo.getCantidadRegistros();
    bool encontro = false;
    for (int i = 0; i < cantReg; i++)
    {
        if (registroManager._registroAdopcionArchivo.leer(i).getIdAdopcion() == id)
        {
            encontro = true;
            mostrarRegistroAdopcion(registroManager._registroAdopcionArchivo.leer(i));
        }
    }
    if (!encontro)
    {
        cout << "NO SE ENCONTRO EL REGISTRO DE ADOPCION" << endl;
    }
}

void RegistroAdopcionManager::buscarRegistroPorMascotaId()
{
    RegistroAdopcionManager registroManager;
    int id;
    cout << "Ingrese el ID de la mascota a buscar: ";
    cin >> id;

    MascotasManager mascotaManager;
    int pos = mascotaManager._mascotasarchivo.buscarByID(id);
    if (pos >= 0)
    {
        int cantReg = registroManager._registroAdopcionArchivo.getCantidadRegistros();
        bool encontro = false;
        for (int i = 0; i < cantReg; i++)
        {
            if (mascotaManager._mascotasarchivo.leer(pos).getIdMascota() == registroManager._registroAdopcionArchivo.leer(i).getIdAdopcion())
            {
                encontro = true;
                mostrarRegistroAdopcion(registroManager._registroAdopcionArchivo.leer(i));
            }
        }
        if (!encontro)
        {
            cout << "NO SE ENCONTRO EL REGISTRO DE ADOPCION" << endl;
        }
    }
    else
    {
        cout << "NO SE ENCONTRO LA MASCOTA" << endl;
    }
}

void RegistroAdopcionManager::Menu()
{
    int option;
    system("cls");
    do
    {
        system("cls");

        cout << "------ MENU REGISTRO ADOPCIONES ------- " << endl;
        cout << "1- AGREGAR REGISTRO ADOPCION " << endl;
        cout << "2- LISTAR TODOS REGISTROS ADOPCION" << endl;
        cout << "3- MODIFICAR REGISTRO ADOPCION" << endl;
        cout << "-----------------------------" << endl;
        cout << "0- SALIR" << endl;
        cout << "Opcion: ";
        cin >> option;

        switch (option)
        {
        case 1:
            system("cls");
            agregarRegistroAdopcion();
            system("pause");
            break;

        case 2:
            system("cls");
            listarRegistrosAdopcion();
            system("pause");
            break;

        case 3:
            system("cls");
            modificarRegistroAdopcion();
            system("pause");
            break;
        case 4:
            system("cls");
            buscarRegistroPorId();
            system("pause");
            break;
        case 5:
            system("cls");
            buscarRegistroPorAdopcionId();
            system("pause");
            break;
        case 6:
            system("cls");
            buscarRegistroPorMascotaId();
            system("pause");
            break;
        }
    } while (option != 0);
}
