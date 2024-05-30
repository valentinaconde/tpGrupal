#ifndef PERSONA_H
#define PERSONA_H

class Persona
{
private:
    int dni;
    char nombre[50];
    char apellido[50];
    bool estado;

public:
    void grabarEnDisco(int);
    bool leerDeDisco(int);
    void Cargar();
    void Mostrar();

    int getDni() { return dni; }
    char *getNombre() { return nombre; }
    bool getEstado() { return estado; }

    void setDni(int id) { dni = id; }
    void setNombre(char *n) { strcpy(nombre, n); }
    void setEstado(bool s) { estado = s; }
};

void Persona::Cargar()
{

    cout << "ID PERSONA: ";
    cin >> dni;
    cout << "NOMBRE: ";
    cin >> nombre;
    cout << "APELLIDO: ";
    cin >> apellido;
    estado = true;
}

void Persona::Mostrar()
{
    if (estado)
    {
        cout << "ID PERSONA: ";
        cout << dni << endl;
        cout << "NOMBRE: ";
        cout << getNombre() << endl;
        cout << "APELLIDO: ";
        cout << apellido << endl;
    }
}

void Persona::grabarEnDisco(int pos = -1)
{
    FILE *p;
    if (pos == -1)
    {
        p = fopen("personas.dat", "ab");
        if (p == NULL)
        {
            cout << "ERROR DE ARCHIVO" << endl;
            return;
        }
    }
    else
    {
        p = fopen("personas.dat", "rb+");
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

bool Persona::leerDeDisco(int pos)
{
    FILE *p;
    p = fopen("personas.dat", "rb");
    if (p == NULL)
        return false;
    fseek(p, sizeof(Persona) * pos, 0);
    bool x = fread(this, sizeof *this, 1, p);
    fclose(p);
    return x;
}

int buscarIdPersona(int id)
{
    Persona per;
    int pos = 0;

    while (per.leerDeDisco(pos))
    {
        if (id == per.getDni() && per.getEstado())
        {
            return pos;
        }
        pos++;
    }
    return -1;
}

void altaPersona()
{
    Persona obj;
    obj.Cargar();
    int pos = buscarIdPersona(obj.getDni());
    if (pos == -1)
    {
        obj.grabarEnDisco();
        cout << "PERSONA AGREGADA" << endl;
    }
    else
    {
        cout << "YA EXISTE EL ID DE PERSONA" << endl;
        cout << "NO SE GRABO LA PERSONA" << endl;
    }
}

void grabarPersona(Persona per)
{
    FILE *p;
    p = fopen("personas.dat", "ab");
    if (p == NULL)
    {
        cout << "ERROR DE ARCHIVO" << endl;

        return;
    }
    fwrite(&per, sizeof per, 1, p);
    fclose(p);
}

void listarPersonas()
{
    Persona per;
    int pos = 0;
    bool hayPersonas = false;
    while (per.leerDeDisco(pos))
    {
        if (per.getEstado())
        {
            hayPersonas = true;
            per.Mostrar();
            pos++;
        }
    }

    
}

#endif