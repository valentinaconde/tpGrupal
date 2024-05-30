#ifndef PROVEEDOR_H
#define PROVEEDOR_H
#include "Persona.h"

class Proveedor : public Persona
{
private:
    int idProveedor;
    char direccion[50];
    char contacto[50];
    bool estado;

public:
    void grabarEnDisco(int);
    bool leerDeDisco(int);
    void Cargar();
    void Mostrar();

    int getIdProveedor() { return idProveedor; }
    char* getDireccion() { return direccion; }
    char* getContacto() { return contacto; }
    bool getEstado() { return estado; }

    void setIdProveedor(int id) { idProveedor = id; }
    void setDireccion(char* d) { strcpy(direccion, d); }
    void setContacto(char* c) { strcpy(contacto, c); }
    void setEstado(bool s) { estado = s; }
};
void Proveedor::Cargar()
{
    cout << "ID PROVEEDOR: ";
    cin >> idProveedor;
    cout << "DIRECCION: ";
    cargarCadena(direccion, 50);
    cout << "CONTACTO: ";
    cargarCadena(contacto, 50);
    estado = true;
}

void Proveedor::Mostrar()
{
    if (estado)
    {
        cout << "ID PROVEEDOR: ";
        cout << idProveedor << endl;
        cout << "NOMBRE: ";
        cout << getNombre() << endl;
        cout << "DIRECCION: ";
        cout << direccion << endl;
        cout << "CONTACTO: ";
        cout << contacto << endl;
    }
}

void Proveedor::grabarEnDisco(int pos = -1)
{
    FILE *p;
    if (pos == -1)
    {
        p = fopen("proveedores.dat", "ab");
        if (p == NULL)
        {
            cout << "ERROR DE ARCHIVO" << endl;
            return;
        }
    }
    else
    {
        p = fopen("proveedores.dat", "rb+");
        if (p == NULL)
        {
            cout << "ERROR DE ARCHIVO" << endl;
            return;
        }
        fseek(p, sizeof *this * pos, 0);
    }
    fwrite(this, sizeof *this, 1, p);
    fclose(p);
}

bool Proveedor::leerDeDisco(int pos)
{
    FILE *p;
    p = fopen("proveedores.dat", "rb");
    if (p == NULL)
        return false;
    fseek(p, sizeof(Proveedor) * pos, 0);
    bool x = fread(this, sizeof *this, 1, p);
    fclose(p);
    return x;
}

int buscarIdProveedor(int id)
{
    Proveedor prov;
    int pos = 0;

    while (prov.leerDeDisco(pos))
    {
        if (id == prov.getIdProveedor() && prov.getEstado())
        {
            return pos;
        }
        pos++;
    }
    return -1;
}

void altaProveedor()
{
    Proveedor obj;
    obj.Cargar();
    int pos = buscarIdProveedor(obj.getIdProveedor());
    if (pos == -1)
    {
        obj.grabarEnDisco();
        cout << "PROVEEDOR AGREGADO" << endl;
    }
    else
    {
        cout << "YA EXISTE EL ID DE PROVEEDOR" << endl;
        cout << "NO SE GRABO EL PROVEEDOR" << endl;
    }
}

void grabarProveedor(Proveedor prov)
{
    FILE *p;
    p = fopen("proveedores.dat", "ab");
    if (p == NULL)
    {
        cout << "ERROR DE ARCHIVO" << endl;

        return;
    }
    fwrite(&prov, sizeof prov, 1, p);
    fclose(p);
}

#endif