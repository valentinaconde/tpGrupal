#ifndef MASCOTA_H
#define MASCOTA_H

#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

class Mascota
{
private:
    int idMascota;
    char nombre[30];
    char especie[30];
    char raza[30];
    int edad;
    char genero; // M, F, O (otro);
    bool estado;
    char tamano; // P, M, G
    char comportamiento[50];

public:
    void grabarEnDisco(int);
    bool leerDeDisco(int);
    void Cargar();
    void Mostrar();

    int getIdMascota() { return idMascota; }
    char *getNombre() { return nombre; }
    char *getEspecie() { return especie; }
    char *getRaza() { return raza; }
    int getEdad() { return edad; }
    char getGenero() { return genero; }
    bool getEstado() { return estado; }
    char getTamano() { return tamano; }
    char *getComportamiento() { return comportamiento; }

    void setIdMascota(int id) { idMascota = id; }
    void setNombre(char *n) { strcpy(nombre, n); }
    void setEspecie(char *e) { strcpy(especie, e); }
    void setRaza(char *r) { strcpy(raza, r); }
    void setEdad(int e)
    {
        if (e > 0)
            edad = e;
    }
    void setGenero(char g) { genero = g;}
    void setEstado(bool s) { estado = s; }
    void setTamano(char t) { tamano = t; }
    void setComportamiento(char *c) { strcpy(comportamiento, c); }
};

void Mascota::Cargar()
{
    cout << "ID MASCOTA: ";
    cin >> idMascota;
    cout << "NOMBRE: ";
    cin >> nombre;
    cout << "ESPECIE: ";
    cin >> especie;
    cout << "RAZA: ";
    cin >> raza;
    cout << "EDAD: ";
    cin >> edad;
    cout << "GENERO: ";
    cin >> genero;
    cout << "ESTADO: ";
    cin >> estado;
    cout << "TAMANO: ";
    cin >> tamano;
    cout << "COMPORTAMIENTO: ";
    cin >> comportamiento;
}

void Mascota::Mostrar()
{
    cout << "ID MASCOTA: ";
    cout << getIdMascota() << endl;
    cout << "NOMBRE: ";
    cout << getNombre() << endl;
    cout << "ESPECIE: ";
    cout << getEspecie() << endl;
    cout << "RAZA: ";
    cout << getRaza() << endl;
    cout << "EDAD: ";
    cout << getEdad() << endl;
    cout << "GENERO: ";
    cout << getGenero() << endl;
    cout << "ESTADO: ";
    cout << getEstado() << endl;
    cout << "TAMANO: ";
    cout << getTamano() << endl;
    cout << "COMPORTAMIENTO: ";
    cout << getComportamiento() << endl;
}

void Mascota::grabarEnDisco(int pos = -1)
{
    FILE *p;
    if (pos == -1)
    {
        p = fopen("mascotas.dat", "ab");
        if (p == NULL)
        {
            cout << "ERROR DE ARCHIVO" << endl;
            system("pause");
            return;
        }
    }
    else
    {
        p = fopen("mascotas.dat", "rb+");
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

bool Mascota::leerDeDisco(int pos)
{
    FILE *p;
    p = fopen("mascotas.dat", "rb");
    if (p == NULL)
        return false;
    fseek(p, sizeof(Mascota) * pos, 0);
    bool x = fread(this, sizeof *this, 1, p);
    fclose(p);
    return x;
}

//////////PROTOTIPOS
void altaMascota();
void bajaMascota();
void listadoMascotas();
int buscarIdMascota(int);
void grabarRegistro(Mascota);

void altaMascota()
{
    Mascota obj;
    obj.Cargar();
    int pos = buscarIdMascota(obj.getIdMascota());
    if (pos == -1)
    {
        obj.grabarEnDisco();
        cout << "REGISTRO AGREGADO" << endl;
    }
    else
    {
        cout << "YA EXISTE EL ID DE MASCOTA" << endl;
        cout << "NO SE GRABO EL REGISTRO" << endl;
    }
    system("pause");
}

int buscarIdMascota(int id)
{
    Mascota reg;
    int pos = 0;

    while (reg.leerDeDisco(pos))
    {
        if (id == reg.getIdMascota())
        {
            return pos;
        }
        pos++;
    }
    return -1;
}

void grabarRegistro(Mascota reg)
{
    FILE *p;
    p = fopen("mascotas.dat", "ab");
    if (p == NULL)
    {
        cout << "ERROR DE ARCHIVO" << endl;
        system("pause");
        return;
    }
    fwrite(&reg, sizeof reg, 1, p);
    fclose(p);
}

void bajaMascota()
{
    int id;
    cout << "INGRESE EL ID DE MASCOTA A ELIMINAR " << endl;
    cin >> id;
    int pos = buscarIdMascota(id);
    if (pos == -1)
    {
        cout << "NO EXISTE EL REGISTRO" << endl;
        system("pause");
        return;
    }

    Mascota obj;
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

void listadoMascotas()
{
    Mascota reg;
    int pos = 0;
    while (reg.leerDeDisco(pos++) == true)
    {
        reg.Mostrar();
        cout << endl;
    }
}

void modificarMascota()
{
    int dni;
    cout << "INGRESE EL ID DE LA MASCOTA A MODIFICAR " << endl;
    cin >> dni;
    int pos = buscarIdMascota(dni);
    if (pos == -1)
    {
        cout << "NO EXISTE EL REGISTRO" << endl;
        system("pause");
        return;
    }

    Mascota obj;
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
    cout << "2. ESPECIE" << endl;
    cout << "3. RAZA" << endl;
    cout << "4. EDAD" << endl;
    cout << "5. GENERO" << endl;
    cout << "6. TAMANO" << endl;
    cout << "7. COMPORTAMIENTO" << endl;

    int opc;
    cin >> opc;

    switch (opc)
    {
    case 1:
        cout << "NOMBRE: ";
        cargarCadena(obj.getNombre(), 30);
        break;
    case 2:
        cout << "ESPECIE: ";
        cargarCadena(obj.getEspecie(), 30);
        break;
    case 3:

        cout << "RAZA: ";
        cargarCadena(obj.getRaza(), 30);
        break;
    case 4:
        int edad;
        cout << "EDAD: ";
        cin >> edad;
        obj.setEdad(edad);
        break;
    case 5:
        char genero;
        cout << "GENERO: ";
        cin >> genero;
        obj.setGenero(genero);
        break;
    case 6:
        char tamano;
        cout << "TAMANO: ";
        cin >> tamano;
        obj.setTamano(tamano);
        break;
    case 7:
        cout << "COMPORTAMIENTO: ";
        cargarCadena(obj.getComportamiento(), 50);
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

#endif