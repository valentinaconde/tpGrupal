#ifndef COMPRA_H
#define COMPRA_H

class Compra
{
private:
    int numeroCompra;
    int codigoDetalleCompra;
    float total;
    bool estado;

public:
    void grabarEnDisco(int);
    bool leerDeDisco(int);
    void Cargar();
    void Mostrar();

    int getNumeroCompra() { return numeroCompra; }
    int getCodigoDetalleCompra() { return codigoDetalleCompra; }
    float getTotal() { return total; }
    bool getEstado() { return estado; }
    
    void setNumeroCompra(int n) { numeroCompra = n; }
    void setCodigoDetalleCompra(int c) { codigoDetalleCompra = c; }
    void setTotal(float t)
    {
        if (t > 0)
            total = t;
    }
    void setEstado(bool s) { estado = s; }
};

float calcularTotalCompra(int codigoDetalleCompra)
{
    cout << "CODIGO DETALLE COMPRA: " << codigoDetalleCompra << endl;
    DetalleCompra reg;
    float total = 0;
    int pos = 0;
    while (reg.leerDeDisco(pos++))
    {
        if (reg.getIdCompra() == codigoDetalleCompra && reg.getEstado())
        {
            total += (reg.getPrecioUnitario() * reg.getCantidad());
        }
    }
    return total;
}

int ultimoCodigoCompraAgregado()
{
    Compra reg;
    int pos = 0;
    while (reg.leerDeDisco(pos++))
    {
    }
    cout << "ULTIMO CODIGO DE COMPRA AGREGADO: " << reg.getNumeroCompra() << endl;
    return reg.getNumeroCompra() + 1;
}

void Compra::Cargar()
{
    cout << "NUMERO COMPRA: ";
    cin >> numeroCompra;
    cout << "CODIGO VENTA: ";
    cin >> codigoDetalleCompra;
    total = calcularTotalCompra(codigoDetalleCompra);
    estado = true;
}

void Compra::Mostrar()
{
    if (estado)
    {
        cout << "NUMERO COMPRA: ";
        cout << numeroCompra << endl;
        cout << "CODIGO VENTA: ";
        cout << codigoDetalleCompra << endl;
        cout << "TOTAL: ";
        cout << total << endl;
    }
}

void Compra::grabarEnDisco(int pos = -1)
{
    FILE *p;
    if (pos == -1)
    {
        p = fopen("compras.dat", "ab");
        if (p == NULL)
        {
            cout << "ERROR DE ARCHIVO" << endl;
            return;
        }
    }
    else
    {
        p = fopen("compras.dat", "rb+");
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

bool Compra::leerDeDisco(int pos)
{
    FILE *p;
    p = fopen("compras.dat", "rb");
    if (p == NULL)
    {
        cout << "ERROR DE ARCHIVO" << endl;
        return false;
    }
    fseek(p, sizeof *this * pos, 0);
    bool leyo = fread(this, sizeof *this, 1, p);
    fclose(p);
    return leyo;
}

#endif // COMPRA_H

