#ifndef DETALLECOMPRA_H
#define DETALLECOMPRA_H

class DetalleCompra
{
private:
    int idCompra;
    int idProducto;
    int cantidad;
    float precioUnitario;
    bool estado;

public:
    void grabarEnDisco(int);
    bool leerDeDisco(int);
    void Cargar();
    void Mostrar();

    int getIdCompra() { return idCompra; }
    int getIdProducto() { return idProducto; }
    int getCantidad() { return cantidad; }
    float getPrecioUnitario() { return precioUnitario; }
    bool getEstado() { return estado; }

    void setIdCompra(int id) { idCompra = id; }
    void setIdProducto(int id) { idProducto = id; }
    void setCantidad(int c) { cantidad = c; }
    void setPrecioUnitario(float p) { precioUnitario = p; }
    void setEstado(bool s) { estado = s; }
};

void DetalleCompra::Cargar()
{
    cout << "ID COMPRA: ";
    cin >> idCompra;
    cout << "ID PRODUCTO: ";
    cin >> idProducto;
    cout << "CANTIDAD: ";
    cin >> cantidad;
    cout << "PRECIO UNITARIO: ";
    cin >> precioUnitario;
    estado = true;
}

void DetalleCompra::Mostrar()
{
    if (estado)
    {
        cout << "ID COMPRA: ";
        cout << idCompra << endl;
        cout << "ID PRODUCTO: ";
        cout << idProducto << endl;
        cout << "CANTIDAD: ";
        cout << cantidad << endl;
        cout << "PRECIO UNITARIO: ";
        cout << precioUnitario << endl;
    }
}

void DetalleCompra::grabarEnDisco(int pos = -1)
{
    FILE *p;
    if (pos == -1)
    {
        p = fopen("detallecompras.dat", "ab");
        if (p == NULL)
        {
            cout << "ERROR DE ARCHIVO" << endl;
            return;
        }
    }
    else
    {
        p = fopen("detallecompras.dat", "rb+");
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

bool DetalleCompra::leerDeDisco(int pos)
{
    FILE *p;
    p = fopen("detallecompras.dat", "rb");
    if (p == NULL)
        return false;
    fseek(p, sizeof(DetalleCompra) * pos, 0);
    bool x = fread(this, sizeof *this, 1, p);
    fclose(p);
    return x;
}

#endif