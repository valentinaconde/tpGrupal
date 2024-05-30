#ifndef FACTURA_H
#define FACTURA_H

#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

class Factura
{
private:
    int numeroFactura;
    int codigoVenta;
    float total;
    bool estado;

public:
    void grabarEnDisco(int);
    bool leerDeDisco(int);
    void Cargar();
    void Mostrar();

    int getNumeroFactura() { return numeroFactura; }
    int getCodigoVenta() { return codigoVenta; }
    float getTotal() { return total; }
    bool getEstado() { return estado; }

    void setNumeroFactura(int n) { numeroFactura = n; }
    void setCodigoVenta(int c) { codigoVenta = c; }
    void setTotal(float t)
    {
        if (t > 0)
            total = t;
    }
    void setEstado(bool s) { estado = s; }
};

int calcularTotal(int codigoVenta)
{
    cout << "CODIGO VENTA: " << codigoVenta << endl;
    FILE *p;
    p = fopen("venta.dat", "rb");
    if (p == NULL)
    {
        cout << "ERROR DE ARCHIVO" << endl;

        return -1;
    }
    Venta reg;
    float total = 0;
    while (fread(&reg, sizeof reg, 1, p) == 1)
    {
        if (reg.getCodigoVenta() == codigoVenta && reg.getEstado())
        {
            total += reg.getPrecioTotal();
        }
    }
    fclose(p);
    return total;
}

int ultimoCodigoFacturaAgregado()
{
    FILE *p;
    p = fopen("factura.dat", "rb");
    if (p == NULL)
    {

        return 0;
    }

    Factura reg;
    fseek(p, -sizeof reg, 2);
    fread(&reg, sizeof reg, 1, p);
    cout << "ULTIMO CODIGO DE FACTURA AGREGADO: " << reg.getNumeroFactura() << endl;
    fclose(p);
    return reg.getNumeroFactura() + 1;
}

void Factura::Cargar()
{
    numeroFactura = ultimoCodigoFacturaAgregado();
    cout << "CODIGO DE VENTA: ";
    cin >> codigoVenta;
    total = calcularTotal(codigoVenta);
    estado = true;
}

void getFechaFactura(int codigoVenta)
{
    FILE *p;
    p = fopen("venta.dat", "rb");
    if (p == NULL)
    {
        cout << "ERROR DE ARCHIVO" << endl;

        return;
    }
    Venta reg;
    while (fread(&reg, sizeof reg, 1, p) == 1)
    {
        if (reg.getCodigoVenta() == codigoVenta && reg.getEstado())
        {
            cout << "FECHA DE FACTURA: ";
            reg.getFechaTransaccion().Mostrar();
            fclose(p);
            return;
        }
    }
    fclose(p);
}

void Factura::Mostrar()
{
    if(estado){
    cout << "NUMERO DE FACTURA: ";
    cout << getNumeroFactura() << endl;
    cout << "CODIGO DE VENTA: ";
    cout << getCodigoVenta() << endl;
    getFechaFactura(getCodigoVenta());
    cout << "TOTAL: ";
    cout << getTotal() << endl;
    }
}

void Factura::grabarEnDisco(int pos = -1)
{
    FILE *p;
    if (pos == -1)
    {
        p = fopen("factura.dat", "ab");
        if (p == NULL)
        {
            cout << "ERROR DE ARCHIVO" << endl;

            return;
        }
    }
    else
    {
        p = fopen("factura.dat", "rb+");
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

bool Factura::leerDeDisco(int pos)
{
    FILE *p;
    p = fopen("factura.dat", "rb");
    if (p == NULL)
        return false;
    fseek(p, sizeof(Factura) * pos, 0);
    bool x = fread(this, sizeof *this, 1, p);
    fclose(p);
    return x;
}

bool chequearExistenciaVenta(int codigoVenta)
{
    FILE *p;
    p = fopen("venta.dat", "rb");
    if (p == NULL)
    {
        cout << "ERROR DE ARCHIVO" << endl;

        return false;
    }
    Venta reg;
    while (fread(&reg, sizeof reg, 1, p) == 1)
    {
        if (reg.getCodigoVenta() == codigoVenta && reg.getEstado())
        {
            fclose(p);
            return true;
        }
    }
    fclose(p);
    return false;
}

int buscarVenta(int num)
{
    Factura reg;
    int pos = 0;
    while (reg.leerDeDisco(pos))
    {
        if (num == reg.getCodigoVenta() && reg.getEstado())
        {
            return pos;
        }
        pos++;
    }

    if (chequearExistenciaVenta(num) == false)
    {
        cout << endl;
        cout << "NO EXISTE EL CODIGO DE VENTA INGRESADO" << endl;
        return -2;
    }

    return -1;
}

void altaFactura()
{
    Factura obj;
    obj.Cargar();
    int pos = buscarVenta(obj.getCodigoVenta());
    if (pos == -1)
    {
        obj.grabarEnDisco();
        cout << "REGISTRO AGREGADO" << endl;
    }
    else
    {
        cout << "YA EXISTE UNA FACTURA PARA EL CODIGO DE VENTA INGRESADO O LA VENTA NO EXISTE" << endl;
        cout << "NO SE GRABO EL REGISTRO" << endl;
    }
}

int buscarNumeroFactura(int num)
{
    Factura reg;
    int pos = 0;

    while (reg.leerDeDisco(pos))
    {
        if (num == reg.getNumeroFactura() && reg.getEstado())
        {
            return pos;
        }
        pos++;
    }
    return -1;
}

void grabarRegistro(Factura reg)
{
    FILE *p;
    p = fopen("factura.dat", "ab");
    if (p == NULL)
    {
        cout << "ERROR DE ARCHIVO" << endl;

        return;
    }
    fwrite(&reg, sizeof reg, 1, p);
    fclose(p);
}

void bajaFactura()
{
    int num;
    cout << "INGRESE EL NUMERO DE FACTURA A ELIMINAR " << endl;
    cin >> num;
    int pos = buscarNumeroFactura(num);
    if (pos == -1)
    {
        cout << "NO EXISTE EL REGISTRO" << endl;

        return;
    }

    Factura obj;
    obj.leerDeDisco(pos);
    if (!obj.getEstado())
    {
        cout << "NO EXISTE EL REGISTRO" << endl;

        return;
    }

    obj.setEstado(false);
    obj.grabarEnDisco(pos);
}

void listadoFacturas()
{
    Factura reg;
    int pos = 0;
    while (reg.leerDeDisco(pos++) == true)
    {
        reg.Mostrar();
        cout << endl;
    }
}

Venta getVentaPorCodigo(int codigoVenta)
{
    FILE *p;
    p = fopen("venta.dat", "rb");
    if (p == NULL)
    {
        cout << "ERROR DE ARCHIVO" << endl;

        return Venta();
    }
    Venta reg;
    while (fread(&reg, sizeof reg, 1, p) == 1)
    {
        if (reg.getCodigoVenta() == codigoVenta && reg.getEstado())
        {
            fclose(p);
            return reg;
        }
    }
    fclose(p);
    return Venta();
}

void listadoFacturasPorFecha()
{
    Factura reg;
    int pos = 0;
    int cantRegistros = 0;
    while (reg.leerDeDisco(pos++) == true)
    {
        cantRegistros++;
    }

    Factura *vec = new Factura[cantRegistros];
    pos = 0;
    while (reg.leerDeDisco(pos++) == true)
    {
        vec[pos - 1] = reg;
    }

    for (int i = 0; i < cantRegistros - 1; i++)
    {
        for (int j = 0; j < cantRegistros - 1; j++)
        {
            Venta aux = getVentaPorCodigo(vec[j].getCodigoVenta());
            Venta aux2 = getVentaPorCodigo(vec[j + 1].getCodigoVenta());
            if (aux.getFechaTransaccion().getAnio() < aux2.getFechaTransaccion().getAnio())
            {
                Factura aux = vec[j];
                vec[j] = vec[j + 1];
                vec[j + 1] = aux;
            }
            else if (aux.getFechaTransaccion().getAnio() == aux2.getFechaTransaccion().getAnio())
            {
                if (aux.getFechaTransaccion().getMes() < aux2.getFechaTransaccion().getMes())
                {
                    Factura aux = vec[j];
                    vec[j] = vec[j + 1];
                    vec[j + 1] = aux;
                }
                else if (aux.getFechaTransaccion().getMes() == aux2.getFechaTransaccion().getMes())
                {
                    if (aux.getFechaTransaccion().getDia() < aux2.getFechaTransaccion().getDia())
                    {
                        Factura aux = vec[j];
                        vec[j] = vec[j + 1];
                        vec[j + 1] = aux;
                    }
                }
            }
        }
    }

    for (int i = 0; i < cantRegistros; i++)
    {
        if (vec[i].getEstado())
        {
            vec[i].Mostrar();
            cout << endl;
        }
    }

    delete[] vec;
}

void buscarFacturaPorNumero()
{
    int num;
    cout << "INGRESE EL NUMERO DE FACTURA A BUSCAR " << endl;
    cin >> num;
    int pos = buscarNumeroFactura(num);
    if (pos == -1)
    {
        cout << "NO EXISTE EL REGISTRO" << endl;

        return;
    }

    Factura obj;
    obj.leerDeDisco(pos);
    obj.Mostrar();
}

void buscarFacturaPorCodigoVenta()
{
    int num;
    cout << "INGRESE EL CODIGO DE VENTA A BUSCAR " << endl;
    cin >> num;
    int pos = buscarVenta(num);
    if (pos == -1)
    {
        cout << "NO EXISTE EL REGISTRO" << endl;

        return;
    }

    Factura obj;
    obj.leerDeDisco(pos);
    obj.Mostrar();
}

void informeTotalFacturadoPorAnio()
{
    int anio;
    cout << "INGRESE EL ANIO A BUSCAR " << endl;
    cin >> anio;
    Factura reg;
    int pos = 0;
    float total = 0;
    while (reg.leerDeDisco(pos++) == true)
    {
        Venta aux = getVentaPorCodigo(reg.getCodigoVenta());
        if (aux.getFechaTransaccion().getAnio() == anio && aux.getEstado())
        {
            total += reg.getTotal();
        }
    }
    cout << "TOTAL FACTURADO EN EL ANIO " << anio << ": " << total << endl;
}

Cliente buscarCliente(int dni)
{
    FILE *p;
    p = fopen("cliente.dat", "rb");
    Cliente reg;
    if (p == NULL)
    {
        cout << "ERROR DE ARCHIVO" << endl;

        return Cliente();
    }
    while (fread(&reg, sizeof reg, 1, p) == 1)
    {
        if (reg.getDni() == dni && reg.getEstado())
        {
            fclose(p);
            return reg;
        }
    }
    fclose(p);
    return Cliente();
}

void informeTotalFacturadoPorCliente()
{
    int dniCliente;
    cout << "INGRESE EL DNI DE CLIENTE A BUSCAR " << endl;
    cin >> dniCliente;
    Factura reg;
    int pos = 0;
    float total = 0;
    while (reg.leerDeDisco(pos++) == true)
    {
        Venta aux = getVentaPorCodigo(reg.getCodigoVenta());
        if (aux.getDniCliente() == dniCliente && aux.getEstado())
        {
            total += reg.getTotal();
        }
    }
    Cliente cliente = buscarCliente(dniCliente);
    cout << "TOTAL FACTURADO AL CLIENTE " << cliente.getNombre() << " " << cliente.getApellido() << ": " << total << endl;
}

#endif
