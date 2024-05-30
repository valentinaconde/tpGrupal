#ifndef CATEGORIA_H
#define CATEGORIA_H

class Categoria
{
private:
    int idCategoria;
    char nombre[50];
    bool estado;

public:
    void grabarEnDisco(int);
    bool leerDeDisco(int);
    void Cargar();
    void Mostrar();

    int getIdCategoria() { return idCategoria; }
    char* getNombre() { return nombre; }
    bool getEstado() { return estado; }

    void setIdCategoria(int id) { idCategoria = id; }
    void setNombre(char* n) { strcpy(nombre, n); }
    void setEstado(bool s) { estado = s; }
};

void Categoria::Cargar()
{
    cout << "ID CATEGORIA: ";
    cin >> idCategoria;
    cout << "NOMBRE: ";
    cin >> nombre;
}

void Categoria::Mostrar()
{
    if (estado)
    {
        cout << "ID CATEGORIA: ";
        cout << getIdCategoria() << endl;
        cout << "NOMBRE: ";
        cout << getNombre() << endl;
    }
}

void Categoria::grabarEnDisco(int pos = -1)
{
    FILE *p;
    if (pos == -1)
    {
        p = fopen("categorias.dat", "ab");
        if (p == NULL)
        {
            cout << "ERROR DE ARCHIVO" << endl;
            return;
        }
    }
    else
    {
        p = fopen("categorias.dat", "rb+");
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

bool Categoria::leerDeDisco(int pos)
{
    FILE *p;
    p = fopen("categorias.dat", "rb");
    if (p == NULL)
        return false;
    fseek(p, sizeof(Categoria) * pos, 0);
    bool x = fread(this, sizeof *this, 1, p);
    fclose(p);
    return x;
}


#endif