#ifndef REGISTRO_ADOPCION_H
#define REGISTRO_ADOPCION_H

class RegistroAdopcion
{
private:
    int idRegistro;
    int idAdopcion;
    bool estado;

public:
    void grabarEnDisco(int);
    bool leerDeDisco(int);
    void Cargar();
    void Mostrar();

    int getIdRegistro() { return idRegistro; }
    int getIdAdopcion() { return idAdopcion; }
    bool getEstado() { return estado; }

    void setIdRegistro(int id) { idRegistro = id; }
    void setIdAdopcion(int id) { idAdopcion = id; }
    void setEstado(bool s) { estado = s; }
};

void RegistroAdopcion::Cargar()
{
    cout << "ID REGISTRO: ";
    cin >> idRegistro;
    cout << "ID ADOPCION: ";
    cin >> idAdopcion;
}

void RegistroAdopcion::Mostrar()
{
    if (estado)
    {
        cout << "ID REGISTRO: ";
        cout << getIdRegistro() << endl;
        cout << "ID ADOPCION: ";
        cout << getIdAdopcion() << endl;
    }
}

void RegistroAdopcion::grabarEnDisco(int pos = -1)
{
    FILE *p;
    if (pos == -1)
    {
        p = fopen("registros_adopcion.dat", "ab");
        if (p == NULL)
        {
            cout << "ERROR DE ARCHIVO" << endl;

            return;
        }
    }
    else
    {
        p = fopen("registros_adopcion.dat", "rb+");
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

bool RegistroAdopcion::leerDeDisco(int pos)
{
    FILE *p;
    p = fopen("registros_adopcion.dat", "rb");
    if (p == NULL)
        return false;
    fseek(p, sizeof(RegistroAdopcion) * pos, 0);
    bool x = fread(this, sizeof *this, 1, p);
    fclose(p);
    return x;
}

// int buscarIdRegistro(int id)
// {
//     RegistroAdopcion reg;
//     int pos = 0;

//     while (reg.leerDeDisco(pos))
//     {
//         if (id == reg.getIdRegistro() && reg.getEstado())
//         {
//             return pos;
//         }
//         pos++;
//     }
//     return -1;
// }

// void altaRegistroAdopcion()
// {
//     RegistroAdopcion obj;
//     obj.Cargar();
//     int pos = buscarIdRegistro(obj.getIdRegistro());
//     if (pos == -1)
//     {
//         obj.grabarEnDisco();
//         cout << "REGISTRO AGREGADO" << endl;
//     }
//     else
//     {
//         cout << "YA EXISTE EL ID DE REGISTRO" << endl;
//         cout << "NO SE GRABO EL REGISTRO" << endl;
//     }
// }

// void grabarRegistro(RegistroAdopcion reg)
// {
//     FILE *p;
//     p = fopen("registros_adopcion.dat", "ab");
//     if (p == NULL)
//     {
//         cout << "ERROR DE ARCHIVO" << endl;

//         return;
//     }
//     fwrite(&reg, sizeof reg, 1, p);
//     fclose(p);
// }

void listadoRegistrosAdopcion()
{
    RegistroAdopcion reg;
    int pos = 0;
    bool hayRegistros = false;
    while (reg.leerDeDisco(pos++) == true)
    {
        if (reg.getEstado())
        {
            hayRegistros = true;
            reg.Mostrar();
            cout << endl;
        }
    }

    if (!hayRegistros)
    {
        cout << "NO HAY REGISTROS DE ADOPCION" << endl;
    }
}

#endif