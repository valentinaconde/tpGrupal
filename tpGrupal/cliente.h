#ifndef CLIENTE_H
#define CLIENTE_H

#include <iostream>
#include <cstring>
#include <cstdio>
#include "fecha.h"

using namespace std;

class Cliente
{
private:
    char nombre[30];
    char apellido[30];
    int dni;
    char direccion[100];
    char contacto[30];
    Fecha fechaRegistro;
    bool estado;

public:
    void grabarEnDisco(int);
    bool leerDeDisco(int);
    void Cargar();
    void Mostrar();

    char *getNombre() { return nombre; }
    char *getApellido() { return apellido; }
    int getDni() { return dni; }
    char *getDireccion() { return direccion; }
    char *getContacto() { return contacto; }
    Fecha getFechaRegistro() { return fechaRegistro; }
    bool getEstado() { return estado; }

    void setNombre(char *n) { strcpy(nombre, n); }
    void setApellido(char *a) { strcpy(apellido, a); }
    void setDni(int d) { dni = d; }
    void setDireccion(char *d) { strcpy(direccion, d); }
    void setContacto(char *c) { strcpy(contacto, c); }
    void setFechaRegistro(Fecha f) { fechaRegistro = f; }
    void setEstado(bool s) { estado = s; }
};

void Cliente::Cargar()
{
    cout << "NOMBRE: ";
    cargarCadena(nombre, 30);
    cout << "APELLIDO: ";
    cargarCadena(apellido, 30);
    cout << "DNI: ";
    cin >> dni;
    cout << "DIRECCION: ";
    cargarCadena(direccion, 30);
    cout << "CONTACTO: ";
    cargarCadena(contacto, 30);
    cout << "FECHA DE REGISTRO: " << endl;
    fechaRegistro.Cargar();
    estado = true;
}

void Cliente::Mostrar()
{

    cout << "APELLIDO Y NOMBRE: ";
    cout << getApellido();
    cout << " ";
    cout << getNombre() << endl;
    cout << "DNI: ";
    cout << getDni() << endl;
    cout << "DIRECCION: ";
    cout << getDireccion() << endl;
    cout << "CONTACTO: ";
    cout << getContacto() << endl;
    fechaRegistro.Mostrar();
    cout << "ESTADO: ";
    cout << estado << endl;
}

void Cliente::grabarEnDisco(int pos = -1)
{
    FILE *p;
    if (pos == -1)
    {
        p = fopen("cliente.dat", "ab");
        if (p == NULL)
        {
            cout << "ERROR DE ARCHIVO" << endl;
            system("pause");
            return;
        }
    }
    else
    {
        p = fopen("cliente.dat", "rb+");
        if (p == NULL)
        {
            cout << "ERROR DE ARCHIVO" << endl;
            system("pause");
            return;
        }
        fseek(p, sizeof *this * pos, 0);
    }
    fwrite(this, sizeof *this, 1, p);
    fclose(p);
}

bool Cliente::leerDeDisco(int pos)
{
    FILE *p;
    p = fopen("cliente.dat", "rb");
    if (p == NULL)
        return false;
    fseek(p, sizeof(Cliente) * pos, 0);
    bool x = fread(this, sizeof *this, 1, p);
    fclose(p);
    return x;
}

//////////PROTOTIPOS
void altaCliente();
void bajaCliente();
void listadoClientes();
int buscarDniCliente(int);
void grabarRegistro(Cliente);

void altaCliente()
{
    Cliente obj;
    obj.Cargar();
    int pos = buscarDniCliente(obj.getDni());
    if (pos == -1)
    {
        obj.grabarEnDisco();
        cout << "REGISTRO AGREGADO" << endl;
    }
    else
    {
        cout << "YA EXISTE EL DNI DEL CLIENTE" << endl;
        cout << "NO SE GRABO EL REGISTRO" << endl;
    }
    system("pause");
}

int buscarDniCliente(int dni)
{
    Cliente reg;
    int pos = 0;

    while (reg.leerDeDisco(pos))
    {
        if (dni == reg.getDni())
        {
            return pos;
        }
        pos++;
    }
    return -1;
}

void grabarRegistro(Cliente reg)
{
    FILE *p;
    p = fopen("cliente.dat", "ab");
    if (p == NULL)
    {
        cout << "ERROR DE ARCHIVO" << endl;
        system("pause");
        return;
    }
    fwrite(&reg, sizeof reg, 1, p);
    fclose(p);
}

void bajaCliente()
{
    int dni;
    cout << "INGRESE EL DNI DEL CLIENTE A ELIMINAR " << endl;
    cin >> dni;
    int pos = buscarDniCliente(dni);
    if (pos == -1)
    {
        cout << "NO EXISTE EL REGISTRO" << endl;
        system("pause");
        return;
    }

    Cliente obj;
    obj.leerDeDisco(pos);
    if (!obj.getEstado())
    {
        cout << "NO EXISTE EL REGISTRO" << endl;
        system("pause");
        return;
    }

    obj.setEstado(false);
    obj.grabarEnDisco(pos);
}

void listadoClientes()
{
    Cliente reg;
    int pos = 0;
    while (reg.leerDeDisco(pos++) == true)
    {
        reg.Mostrar();
        cout << endl;
    }
    system("pause");
}

void listadoClientesOrdenadosPorDni()
{
    Cliente reg;
    int pos = 0;
    int cantRegistros = 0;
    while (reg.leerDeDisco(pos++) == true)
    {
        cantRegistros++;
    }

    Cliente *vec = new Cliente[cantRegistros];
    pos = 0;
    while (reg.leerDeDisco(pos++) == true)
    {
        vec[pos - 1] = reg;
    }

    for (int i = 0; i < cantRegistros - 1; i++)
    {
        for (int j = 0; j < cantRegistros - 1; j++)
        {
            if (vec[j].getDni() > vec[j + 1].getDni())
            {
                Cliente aux = vec[j];
                vec[j] = vec[j + 1];
                vec[j + 1] = aux;
            }
        }
    }

    for (int i = 0; i < cantRegistros; i++)
    {
        vec[i].Mostrar();
        cout << endl;
    }
    delete[] vec;
    system("pause");
}

void listadoClientesOrdenadosPorApellido()
{
    Cliente reg;
    int pos = 0;
    int cantRegistros = 0;
    while (reg.leerDeDisco(pos++) == true)
    {
        cantRegistros++;
    }

    Cliente *vec = new Cliente[cantRegistros];
    pos = 0;
    while (reg.leerDeDisco(pos++) == true)
    {
        vec[pos - 1] = reg;
    }

    for (int i = 0; i < cantRegistros - 1; i++)
    {
        for (int j = 0; j < cantRegistros - 1; j++)
        {
            if (strcmp(vec[j].getApellido(), vec[j + 1].getApellido()) > 0)
            {
                Cliente aux = vec[j];
                vec[j] = vec[j + 1];
                vec[j + 1] = aux;
            }
        }
    }

    for (int i = 0; i < cantRegistros; i++)
    {
        vec[i].Mostrar();
        cout << endl;
    }
    delete[] vec;
    system("pause");
}

void listadoClientesOrdenadosPorFechaRegistro()
{
    Cliente reg;
    int pos = 0;
    int cantRegistros = 0;
    while (reg.leerDeDisco(pos++) == true)
    {
        cantRegistros++;
    }

    Cliente *vec = new Cliente[cantRegistros];
    pos = 0;
    while (reg.leerDeDisco(pos++) == true)
    {
        vec[pos - 1] = reg;
    }

    for (int i = 0; i < cantRegistros - 1; i++)
    {
        for (int j = 0; j < cantRegistros - 1; j++)
        {
            if (vec[j].getFechaRegistro().getAnio() < vec[j + 1].getFechaRegistro().getAnio())
            {
                Cliente aux = vec[j];
                vec[j] = vec[j + 1];
                vec[j + 1] = aux;
            }
            else if (vec[j].getFechaRegistro().getAnio() == vec[j + 1].getFechaRegistro().getAnio())
            {
                if (vec[j].getFechaRegistro().getMes() < vec[j + 1].getFechaRegistro().getMes())
                {
                    Cliente aux = vec[j];
                    vec[j] = vec[j + 1];
                    vec[j + 1] = aux;
                }
                else if (vec[j].getFechaRegistro().getMes() == vec[j + 1].getFechaRegistro().getMes())
                {
                    if (vec[j].getFechaRegistro().getDia() < vec[j + 1].getFechaRegistro().getDia())
                    {
                        Cliente aux = vec[j];
                        vec[j] = vec[j + 1];
                        vec[j + 1] = aux;
                    }
                }
            }
        }
    }

    for (int i = 0; i < cantRegistros; i++)
    {
        vec[i].Mostrar();
        cout << endl;
    }

    delete[] vec;
    system("pause");
}

void modificarCliente()
{
    int dni;
    cout << "INGRESE EL DNI DEL CLIENTE A MODIFICAR " << endl;
    cin >> dni;
    int pos = buscarDniCliente(dni);
    if (pos == -1)
    {
        cout << "NO EXISTE EL REGISTRO" << endl;
        system("pause");
        return;
    }

    Cliente obj;
    obj.leerDeDisco(pos);
    if (!obj.getEstado())
    {
        cout << "NO EXISTE EL REGISTRO" << endl;
        system("pause");
        return;
    }

    obj.Mostrar();
    cout << "INGRESE EL DATO QUE QUIERE MODIFICAR: " << endl;
    cout << "1. NOMBRE" << endl;
    cout << "2. APELLIDO" << endl;
    cout << "3. DIRECCION" << endl;
    cout << "4. CONTACTO" << endl;
    int opc;
    cin >> opc;
    switch (opc)
    {
    case 1:
        cout << "NOMBRE: ";
        cargarCadena(obj.getNombre(), 30);
        break;
    case 2:

        cout << "APELLIDO: ";
        cargarCadena(obj.getApellido(), 30);
        break;
    case 3:

        cout << "DIRECCION: ";
        cargarCadena(obj.getDireccion(), 30);
        break;
    case 4:
        cout << "CONTACTO: ";
        cargarCadena(obj.getContacto(), 30);
        break;
    default:
        cout << "OPCION INCORRECTA" << endl;
        system("pause");
        return;
    }

    obj.grabarEnDisco(pos);
    cout << "REGISTRO MODIFICADO" << endl;
    system("pause");
}

void buscarClientePorDni(){
    int dni;
    cout << "INGRESE EL DNI DEL CLIENTE A BUSCAR " << endl;
    cin >> dni;
    int pos = buscarDniCliente(dni);
    if (pos == -1)
    {
        cout << "NO EXISTE EL REGISTRO" << endl;
        system("pause");
        return;
    }

    Cliente obj;
    obj.leerDeDisco(pos);
    if (!obj.getEstado())
    {
        cout << "NO EXISTE EL REGISTRO" << endl;
        system("pause");
        return;
    }

    obj.Mostrar();
    system("pause");
}

void buscarClientePorApellido(){
    char apellido[30];
    cout << "INGRESE EL APELLIDO DEL CLIENTE A BUSCAR " << endl;
    cargarCadena(apellido, 30);
    Cliente reg;
    int pos = 0;
    while (reg.leerDeDisco(pos++) == true)
    {
        if(strcmp(reg.getApellido(), apellido) == 0){
            reg.Mostrar();
            cout << endl;
        }
    }
    system("pause");
}

void listadoClientesConMasDe5Compras(){
    Cliente reg;
    int pos = 0;
    while (reg.leerDeDisco(pos++) == true)
    {
        if(reg.getEstado()){
            // contar las compras
            int cantCompras = 0;
            FILE *p;
            p = fopen("venta.dat", "rb");
            if (p == NULL)
            {
                cout << "ERROR DE ARCHIVO" << endl;
                system("pause");
                return;
            }
            Venta aux;
            while (fread(&aux, sizeof aux, 1, p) == 1)
            {
                if(aux.getDniCliente() == reg.getDni()){
                    cantCompras++;
                }
            }
            fclose(p);
            if(cantCompras > 5){
                reg.Mostrar();
                cout << "CANTIDAD DE COMPRAS: " << cantCompras << endl;
                cout << endl;
            }
        }
    }
    system("pause");
}

#endif