#include <iostream>
#include <cstring>
#include "FormularioAdopcionManager.h"
#include "Cliente.h"
#include "ClienteArchivo.h"
#include "clienteManager.h"
#include "mascota.h"
#include "mascotaArchivo.h"
#include "mascotaManager.h"

using namespace std;

void cargarCadena(char *pal, int tam);

void FormularioAdopcionManager::agregarFormulario()
{
    if (_formulariosAdopcionArchivo.guardar(crearFormulario()))
    {
        cout << "El formulario de adopcion fue guardado con exito!" << endl;
    }
    else
    {
        cout << "No se pudo guardar el formulario de adopción!" << endl;
    }
}

void FormularioAdopcionManager::listarFormularios()
{
    int cantidad = _formulariosAdopcionArchivo.getCantidadRegistros();

    FormularioAdopcion *formularios = new FormularioAdopcion[cantidad];

    if (formularios == nullptr)
    {
        cout << "No se pudo pedir memoria..." << endl;
        return;
    }

    _formulariosAdopcionArchivo.leerTodos(formularios, cantidad);

    system("cls");
    cout << "---------- FORMULARIOS DE ADOPCION ---------" << endl
         << endl;
    int leyo = 0;
    for (int i = 0; i < cantidad; i++)
    {
        if (formularios[i].getEstado())
        {
            leyo++;
            cout << "--------------------------------------------" << endl;
            mostrarFormulario(formularios[i]);
            cout << "--------------------------------------------" << endl;
        }
    }

    if (leyo == 0)
    {
        cout << "NO HAY FORMULARIOS DISPONIBLES PARA MOSTRAR" << endl
             << endl;
    }

    delete[] formularios;
}

FormularioAdopcion FormularioAdopcionManager::crearFormulario()
{
    int dni, idMascota, idFormulario;

    idFormulario = _formulariosAdopcionArchivo.getNuevoID();

    cout << "ID: " << idFormulario << endl;
    cout << "Ingrese dni del adoptante: ";
    cin >> dni;
    int eleccion = 1;
    Cliente cliente;
    ClienteArchivo clienteArchivo;
    ClientesManager clienteManager;
    int pos = -1;
    pos = clienteArchivo.buscarPorDni(dni);
    if (pos >= 0)
        cliente = clienteArchivo.leer(pos);
    while (pos < 0 || !cliente.getEstado() || !cliente.getAptoAdopcion() && eleccion != 0)
    {
        system("cls");
        cout << "NO EXISTE EL CLIENTE INGRESADO O NO ES APTO PARA ADOPTAR" << endl;
        cout << "INGRESE OTRO DNI O DE DE ALTA UN NUEVO CLIENTE." << endl;
        cout << "QUE QUIERE HACER?" << endl;
        cout << "0) SALIR" << endl;
        cout << "1) INGRESAR NUEVO" << endl;
        cout << "2) DAR DE ALTA" << endl;

        cin >> eleccion;

        if (eleccion = 0)
        {
            return FormularioAdopcion();
        }

        if (eleccion == 1)
        {
            system("cls");
            cout << "Ingrese dni del adoptante: ";
            cin >> dni;
            system("cls");
            pos = clienteArchivo.buscarPorDni(dni);
            if (pos >= 0)
                cliente = clienteArchivo.leer(pos);
            cliente.Mostrar();
        }
        else if (eleccion == 2)
        {
            clienteManager.agregarCliente();
            pos = clienteArchivo.buscarPorDni(dni);
            if (pos >= 0)
                cliente = clienteArchivo.leer(pos);
            cliente.Mostrar();
        }
        else
        {
            system("cls");
            cout << "OPCION INVALIDA" << endl;
            system("pause");
        }
    }

    cout << "INGRESE ID DE LA MASCOTA SOLICITADA: ";
    cin >> idMascota;
    cout << endl;

    Mascota mascota;
    MascotaArchivo mascotaArchivo;
    MascotasManager mascotaManager;

    int posMascota;
    int eleccionMascota = 1;
    posMascota = mascotaArchivo.buscarByID(idMascota);
    if (posMascota >= 0)
        mascota = mascotaArchivo.leer(posMascota);
    while (posMascota < 0 || !mascota.getEstado() && eleccionMascota != 0)
    {
        system("cls");
        cout << "NO EXISTE LA MASCOTA INGRESADA, INGRESE OTRA MASCOTA" << endl;
        cout << "QUE QUIERE HACER?" << endl;
        cout << "1) ELEGIR OTRA MASCOTA" << endl;
        cout << "2) VER MASCOTAS DISPONIBLES" << endl;
        cout << "0) SALIR" << endl;
        cin >> eleccionMascota;

        if (eleccionMascota == 0)
        {
            return FormularioAdopcion();
        }

        if (eleccionMascota == 1)
        {
            cout << "INGRESE ID DE LA MASCOTA SOLICITADA: ";
            cin >> idMascota;
            posMascota = mascotaArchivo.buscarByID(idMascota);
            if (posMascota >= 0)
                mascota = mascotaArchivo.leer(posMascota);
        }
        else if (eleccionMascota == 2)
        {
            mascotaManager.listarMascotas();
            system("pause");
        }
        else
        {
            system("cls");
            cout << "OPCION INVALIDA" << endl;
            system("pause");
        }
    }

    if (cliente.getAptoAdopcion())
        return FormularioAdopcion(idFormulario, cliente, idMascota, true);
    else
        return FormularioAdopcion(idFormulario, cliente, idMascota, false);
}

void FormularioAdopcionManager::volverCargarFormulario(FormularioAdopcion &registro)
{
    int dni, idMascota, idFormulario;

    cout << "ID: " << idFormulario << endl;
    cout << "Ingrese dni del adoptante: ";
    cin >> dni;
    int eleccion;
    Cliente cliente;
    ClienteArchivo clienteArchivo;
    ClientesManager clienteManager;
    int pos = -1;
    pos = clienteArchivo.buscarPorDni(dni);
    if (pos >= 0)
        cliente = clienteArchivo.leer(pos);
    while (pos < 0 || !cliente.getEstado() || !cliente.getAptoAdopcion() && eleccion != 0)
    {
        system("cls");
        cout << "NO EXISTE EL CLIENTE INGRESADO O NO ES APTO PARA ADOPTAR" << endl;
        cout << "INGRESE OTRO DNI O DE DE ALTA UN NUEVO CLIENTE." << endl;
        cout << "QUE QUIERE HACER?" << endl;
        cout << "0) SALIR" << endl;
        cout << "1) INGRESAR NUEVO" << endl;
        cout << "2) DAR DE ALTA" << endl;
        cin >> eleccion;

        if (eleccion == 0)
        {
            return;
        }

        if (eleccion == 1)
        {
            cout << "Ingrese dni del adoptante: ";
            cin >> dni;

            pos = clienteArchivo.buscarPorDni(dni);
            if (pos >= 0)
                cliente = clienteArchivo.leer(pos);
            cliente.Mostrar();
        }
        else if (eleccion == 2)
        {
            clienteManager.agregarCliente();
            pos = clienteArchivo.buscarPorDni(dni);
            if (pos >= 0)
                cliente = clienteArchivo.leer(pos);
            cliente.Mostrar();
        }
        else
        {
            system("cls");
            cout << "OPCION INVALIDA" << endl;
            system("pause");
        }
    }

    cout << "INGRESE ID DE LA MASCOTA SOLICITADA: ";
    cin >> idMascota;
    cout << endl;

    Mascota mascota;
    MascotaArchivo mascotaArchivo;
    MascotasManager mascotaManager;

    int posMascota;
    int eleccionMascota = 1;
    posMascota = mascotaArchivo.buscarByID(idMascota);
    if (posMascota >= 0)
        mascota = mascotaArchivo.leer(posMascota);
    while (posMascota < 0 || !mascota.getEstado() && eleccionMascota != 0)
    {
        system("cls");
        cout << "NO EXISTE LA MASCOTA INGRESADA, INGRESE OTRA MASCOTA" << endl;
        cout << "QUE QUIERE HACER?" << endl;
        cout << "0) SALIR" << endl;
        cout << "1) ELEGIR OTRA MASCOTA" << endl;
        cout << "2) VER MASCOTAS DISPONIBLES" << endl;
        cin >> eleccionMascota;
        cout << eleccionMascota << endl;

        if (eleccionMascota == 0)
        {
            return;
        }
        if (eleccionMascota == 1)
        {
            cout << "INGRESE ID DE LA MASCOTA SOLICITADA: ";
            cin >> idMascota;
            posMascota = mascotaArchivo.buscarByID(idMascota);
            if (posMascota >= 0)
                mascota = mascotaArchivo.leer(posMascota);
        }
        else if (eleccionMascota == 2)
        {
            mascotaManager.listarMascotas();
            system("pause");
        }
        else
        {
            system("cls");
            cout << "OPCION INVALIDA" << endl;
            system("pause");
        }
    }

    registro.setCliente(cliente);
    registro.setIdMascota(idMascota);
}

void FormularioAdopcionManager::mostrarFormulario(FormularioAdopcion registro)
{
    Cliente cliente;
    cout << "ID FORMULARIO: " << registro.getIdAdopcion() << endl
         << endl;
    cout << "CLIENTE: " << endl;
    cliente = registro.getCliente();
    cliente.Mostrar();
    cout << "MASCOTA: " << endl;

    MascotasManager managerMascota;
    Mascota mascota;

    int pos = managerMascota._mascotasarchivo.buscarByID(registro.getIdMascota());
    if (pos >= 0)
        mascota = managerMascota._mascotasarchivo.leer(pos);

    cout << "ID MASCOTA: " << mascota.getIdMascota() << endl;
    cout << "NOMBRE: " << mascota.getNombre() << endl;
    cout << "ESPECIE: " << mascota.getEspecie() << endl;
    cout << "RAZA: " << mascota.getRaza() << endl;
    cout << "EDAD: " << mascota.getEdad() << endl;
    cout << "GENERO: " << mascota.getGenero() << endl;
    cout << "TAMANIO: " << mascota.getTamanio() << endl;
    cout << "COMPORTAMIENTO: " << mascota.getComportamiento() << endl;
}

void FormularioAdopcionManager::modificarFormulario()
{
    int idFormulario, index;
    FormularioAdopcion formulario;

    cout << "Ingrese id del formulario a modificar: ";
    cin >> idFormulario;

    index = _formulariosAdopcionArchivo.buscarByID(idFormulario);
    if (index != -1)
        formulario = _formulariosAdopcionArchivo.leer(index);
    if (formulario.getEstado())
    {

        mostrarFormulario(formulario);

        volverCargarFormulario(formulario);

        if (_formulariosAdopcionArchivo.guardar(index, formulario))
        {
            cout << "Se modifico con exito!" << endl;
        }
        else
        {
            cout << "No se pudo modificar el formulario!" << endl;
        }
    }
    else
    {
        cout << "No se encuentra ese formulario!" << endl;
    }
}

void FormularioAdopcionManager::rechazarFormulario()
{
    int idFormulario, index;
    FormularioAdopcion formulario;
    bool eliminar;

    cout << "Ingrese id del formulario a eliminar: ";
    cin >> idFormulario;

    index = _formulariosAdopcionArchivo.buscarByID(idFormulario);
    if (index != -1)
        formulario = _formulariosAdopcionArchivo.leer(index);

    if (formulario.getEstado())
    {

        mostrarFormulario(formulario);

        cout << "Esta seguro de que quiere rechazarlo? 1-SI 0-NO: ";
        cin >> eliminar;

        if (eliminar)
        {
            formulario.setEstado(false);
            if (_formulariosAdopcionArchivo.guardar(index, formulario))
            {
                cout << "Se rechazo con exito!" << endl
                     << endl;
                int opc;
                cout << "Quiere que el cliente quede NO apto para adopcion? 1-SI 0-NO:";
                cin >> opc;

                if (opc)
                {
                    ClientesManager clienteManager;
                    clienteManager.volverClienteNoAptoAdopcion(formulario.getCliente());
                }
            }
            else
            {
                cout << "No se pudo rechazar el formulario!" << endl;
            }
        }
        else
        {
            cout << "El formulario no fue rechazado!" << endl;
        }
    }
    else
    {
        cout << "No se encuentra ese formulario!" << endl;
    }
}

void FormularioAdopcionManager::buscarPorIdAdopcion()
{
    int idFormulario, index;
    FormularioAdopcion formulario;

    cout << "Ingrese id del formulario a buscar: ";
    cin >> idFormulario;

    index = _formulariosAdopcionArchivo.buscarByID(idFormulario);
    if (index != -1)
        formulario = _formulariosAdopcionArchivo.leer(index);
    if (formulario.getEstado())
    {
        mostrarFormulario(formulario);
    }
    else
    {
        cout << "No se encuentra ese formulario!" << endl;
    }
}

void FormularioAdopcionManager::buscarPorApellidoCliente()
{
    char apellido[30];
    int cantidad = _formulariosAdopcionArchivo.getCantidadRegistros();

    FormularioAdopcion *formularios = new FormularioAdopcion[cantidad];

    if (formularios == nullptr)
    {
        cout << "No se pudo pedir memoria..." << endl;
        return;
    }

    _formulariosAdopcionArchivo.leerTodos(formularios, cantidad);

    system("cls");
    cout << "---------- FORMULARIOS DE ADOPCION ---------" << endl
         << endl;
    int leyo = 0;
    cout << "Ingrese apellido del cliente: ";
    cargarCadena(apellido, 30);
    for (int i = 0; i < cantidad; i++)
    {
        if (formularios[i].getEstado() && strcmp(apellido, formularios[i].getCliente().getApellido()) == 0)
        {
            leyo++;
            cout << "--------------------------------------------" << endl;
            mostrarFormulario(formularios[i]);
            cout << "--------------------------------------------" << endl;
        }
    }

    if (leyo == 0)
    {
        cout << "NO HAY FORMULARIOS DISPONIBLES PARA MOSTRAR" << endl
             << endl;
    }

    delete[] formularios;
}

void FormularioAdopcionManager::buscarPorIdMascota()
{
    int idMascota, cantidad = _formulariosAdopcionArchivo.getCantidadRegistros();

    FormularioAdopcion *formularios = new FormularioAdopcion[cantidad];

    if (formularios == nullptr)
    {
        cout << "No se pudo pedir memoria..." << endl;
        return;
    }

    _formulariosAdopcionArchivo.leerTodos(formularios, cantidad);

    system("cls");
    cout << "---------- FORMULARIOS DE ADOPCION ---------" << endl
         << endl;
    int leyo = 0;
    cout << "Ingrese id de la mascota: ";
    cin >> idMascota;
    for (int i = 0; i < cantidad; i++)
    {
        if (formularios[i].getEstado() && idMascota == formularios[i].getIdMascota())
        {
            leyo++;
            cout << "--------------------------------------------" << endl;
            mostrarFormulario(formularios[i]);
            cout << "--------------------------------------------" << endl;
        }
    }

    if (leyo == 0)
    {
        cout << "NO HAY FORMULARIOS DISPONIBLES PARA MOSTRAR" << endl
             << endl;
    }

    delete[] formularios;
}

void FormularioAdopcionManager::Menu()
{
    int opcion;
    do
    {
        system("cls");

        cout << "------ MENU FORMULARIOS DE ADOPCION -------" << endl;
        cout << "1- AGREGAR FORMULARIO" << endl;
        cout << "2- LISTAR FORMULARIOS" << endl;
        cout << "3- MODIFICAR FORMULARIO" << endl;
        cout << "4- RECHAZAR FORMULARIO" << endl;
        cout << "-------------------------------------------" << endl;
        cout << "0- Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            system("cls");
            agregarFormulario();
            system("pause");
            break;
        case 2:
            system("cls");
            listarFormularios();
            system("pause");
            break;
        case 3:
            system("cls");
            modificarFormulario();
            system("pause");
            break;
        case 4:
            system("cls");
            rechazarFormulario();
            system("pause");
            break;
        case 5:
            system("cls");
            buscarPorIdAdopcion();
            system("pause");
            break;
        case 6:
            system("cls");
            buscarPorIdMascota();
            system("pause");
            break;
        case 7:
            system("cls");
            buscarPorApellidoCliente();
            system("pause");
            break;
        }
    } while (opcion != 0);
}
/*
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
*/
