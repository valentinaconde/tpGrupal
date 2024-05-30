#ifndef VENTA_H
#define VENTA_H

class Venta
{
private:
    int codigoVenta;
    int dniCliente;
    int codigoArticulo;
    int cantidad;
    float precioTotal;
    bool envioDomicilio;
    Fecha fechaTransaccion;
    char metodoPago[30];
    bool estado;

public:
    void grabarEnDisco(int);
    bool leerDeDisco(int);
    void Cargar();
    void Mostrar();

    int getCodigoVenta() { return codigoVenta; }
    int getDniCliente() { return dniCliente; }
    int getCodigoArticulo() { return codigoArticulo; }
    float getPrecioTotal() { return precioTotal; }
    bool getEnvioDomicilio() { return envioDomicilio; }
    Fecha getFechaTransaccion() { return fechaTransaccion; }
    char *getMetodoPago() { return metodoPago; }
    int getCantidad() { return cantidad; }
    bool getEstado() { return estado; }

    void setCodigoVenta(int c) { codigoVenta = c; }
    void setDniCliente(int d) { dniCliente = d; }
    void setCodigoArticulo(int c) { codigoArticulo = c; }
    void setPrecioTotal(float p)
    {
        if (p > 0)
            precioTotal = p;
    }
    void setEnvioDomicilio(bool e) { envioDomicilio = e; }
    void setFechaTransaccion(Fecha f) { fechaTransaccion = f; }
    void setMetodoPago(char *m) { strcpy(metodoPago, m); }
    void setCantidad(int c)
    {
        if (c > 0)
            cantidad = c;
    }
    void setEstado(bool e) { estado = e; }
};

int getPrecioFinal(int codigoArticulo, int cantidad)
{
    Articulo reg;
    int pos = 0;
    while (reg.leerDeDisco(pos++))
    {
        if (reg.getCod() == codigoArticulo && reg.getEstado())
        {
            return reg.getPu() * cantidad;
        }
    }
    return 0;
}

int ultimoCodigoVentaAgregado()
{
    Venta reg;
    int pos = 0;
    while (reg.leerDeDisco(pos++))
    {
    }
    cout << "ULTIMO CODIGO DE VENTA AGREGADO: " << reg.getCodigoVenta() << endl;
    return reg.getCodigoVenta() + 1;
}

bool validarArticulo(int codigoArticulo)
{
    Articulo reg;
    int pos = 0;
    while (reg.leerDeDisco(pos++))
    {
        if (reg.getCod() == codigoArticulo && reg.getEstado() && reg.getStock() > 0)
        {
            return true;
        }
    }
    cout << "NO EXISTE UN ARTICULO CON ESE CODIGO O NO TIENE STOCK. INGRESE UN NUEVO ";
    return false;
}

bool validarStock(int codigoArticulo, int cantidad)
{
    Articulo reg;
    int pos = 0;
    while (reg.leerDeDisco(pos++))
    {
        if (reg.getCod() == codigoArticulo && reg.getEstado())
        {
            if (reg.getStock() < cantidad)
            {
                cout << "NO HAY STOCK SUFICIENTE PARA REALIZAR LA VENTA" << endl;
                return false;
            }
            reg.setStock(reg.getStock() - cantidad);
            reg.grabarEnDisco(pos - 1);
            cout << "- stock actualizado -" << endl;
            return true;
        }
    }

    return false;
}

void Venta::Cargar()
{
    cout << "CODIGO VENTA: ";
    cin >> codigoVenta;
    cout << "DNI CLIENTE: ";
    cin >> dniCliente;
    cout << "CODIGO ARTICULO: ";
    cin >> codigoArticulo;
    bool isArticulo = validarArticulo(codigoArticulo);
    while (!isArticulo)
    {
        cout << "CODIGO ARTICULO: ";
        cin >> codigoArticulo;
        isArticulo = validarArticulo(codigoArticulo);
    }
    cout << "CANTIDAD: ";
    cin >> cantidad;
    bool isStock = validarStock(codigoArticulo, cantidad);
    while (!isStock)
    {
        cout << "CANTIDAD: ";
        cin >> cantidad;
        isStock = validarStock(codigoArticulo, cantidad);
    }
    precioTotal = getPrecioFinal(codigoArticulo, cantidad);
    cout << "ENVIO A DOMICILIO (1 para SI, 0 para NO): ";
    cin >> envioDomicilio;
    fechaTransaccion.Cargar();
    cout << "METODO DE PAGO: ";
    cin >> metodoPago;
}

void Venta::Mostrar()
{
    if (estado)
    {
        cout << "CODIGO DE VENTA: ";
        cout << getCodigoVenta() << endl;
        cout << "DNI CLIENTE: ";
        cout << getDniCliente() << endl;
        cout << "CODIGO ARTICULO: ";
        cout << getCodigoArticulo() << endl;
        cout << "CANTIDAD: ";
        cout << getCantidad() << endl;
        cout << "PRECIO TOTAL: ";
        cout << getPrecioTotal() << endl;
        cout << "PRECIO UNITARIO:";
        cout << getPrecioTotal() / getCantidad() << endl;
        cout << "ENVIO A DOMICILIO: ";
        cout << (getEnvioDomicilio() ? "SI" : "NO") << endl;
        cout << "FECHA DE TRANSACCION: ";
        fechaTransaccion.Mostrar();
        cout << "METODO DE PAGO: ";
        cout << getMetodoPago() << endl;
    }
}

void Venta::grabarEnDisco(int pos = -1)
{
    FILE *p;
    if (pos == -1)
    {
        p = fopen("venta.dat", "ab");
        if (p == NULL)
        {
            cout << "ERROR DE ARCHIVO" << endl;

            return;
        }
    }
    else
    {
        p = fopen("venta.dat", "rb+");
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

bool Venta::leerDeDisco(int pos)
{
    FILE *p;
    p = fopen("venta.dat", "rb");
    if (p == NULL)
        return false;
    fseek(p, sizeof(Venta) * pos, 0);
    bool x = fread(this, sizeof *this, 1, p);
    fclose(p);
    return x;
}

int buscarCodigoVenta(int cod)
{
    Venta reg;
    int pos = 0;

    while (reg.leerDeDisco(pos))
    {
        if (cod == reg.getCodigoVenta() && reg.getEstado())
        {
            return pos;
        }
        pos++;
    }
    return -1;
}
void altaVenta()
{
    Venta obj;
    obj.Cargar();
    obj.grabarEnDisco();
    cout << "REGISTRO AGREGADO" << endl;
}

// void grabarRegistro(Venta reg)
// {
//     FILE *p;
//     p = fopen("venta.dat", "ab");
//     if (p == NULL)
//     {
//         cout << "ERROR DE ARCHIVO" << endl;

//         return;
//     }
//     fwrite(&reg, sizeof reg, 1, p);
//     fclose(p);
// }

void bajaVenta()
{
    int cod;
    cout << "INGRESE EL CODIGO DE VENTA A ELIMINAR " << endl;
    cin >> cod;
    int pos = buscarCodigoVenta(cod);
    if (pos == -1)
    {
        cout << "NO EXISTE EL REGISTRO" << endl;

        return;
    }

    Venta obj;
    obj.leerDeDisco(pos);
    if (!obj.getEstado())
    {
        cout << "NO EXISTE EL REGISTRO" << endl;

        return;
    }

    obj.setEstado(false);
    obj.grabarEnDisco(pos);
}

void listadoVentas()
{
    Venta reg;
    int pos = 0;
    bool hayVentas = false;
    while (reg.leerDeDisco(pos++) == true)
    {
        if (reg.getEstado())
        {
            hayVentas = true;
            reg.Mostrar();
            cout << endl;
        }
    }

    if (!hayVentas)
    {
        cout << "NO HAY VENTAS" << endl;
    }
}

void listadoVentasPorFechaMayorAMenor()
{
    Venta reg;
    int pos = 0;
    int cantRegistros = 0;
    while (reg.leerDeDisco(pos++) == true)
    {
        cantRegistros++;
    }

    Venta *vec = new Venta[cantRegistros];
    pos = 0;
    while (reg.leerDeDisco(pos++) == true)
    {
        vec[pos - 1] = reg;
    }

    for (int i = 0; i < cantRegistros - 1; i++)
    {
        for (int j = 0; j < cantRegistros - 1; j++)
        {
            if (vec[j].getFechaTransaccion().getAnio() < vec[j + 1].getFechaTransaccion().getAnio())
            {
                Venta aux = vec[j];
                vec[j] = vec[j + 1];
                vec[j + 1] = aux;
            }
            else if (vec[j].getFechaTransaccion().getAnio() == vec[j + 1].getFechaTransaccion().getAnio())
            {
                if (vec[j].getFechaTransaccion().getMes() < vec[j + 1].getFechaTransaccion().getMes())
                {
                    Venta aux = vec[j];
                    vec[j] = vec[j + 1];
                    vec[j + 1] = aux;
                }
                else if (vec[j].getFechaTransaccion().getMes() == vec[j + 1].getFechaTransaccion().getMes())
                {
                    if (vec[j].getFechaTransaccion().getDia() < vec[j + 1].getFechaTransaccion().getDia())
                    {
                        Venta aux = vec[j];
                        vec[j] = vec[j + 1];
                        vec[j + 1] = aux;
                    }
                }
            }
        }
    }

    bool hayVentas = false;
    for (int i = 0; i < cantRegistros; i++)
    {
        if (vec[i].getEstado())
        {
            hayVentas = true;
            vec[i].Mostrar();
            cout << endl;
        }
    }

    if (!hayVentas)
    {
        cout << "NO HAY VENTAS" << endl;
    }
    delete[] vec;
}

void listadoVentasPorCliente()
{
    Venta reg;
    int pos = 0;
    int cantRegistros = 0;
    while (reg.leerDeDisco(pos++) == true)
    {
        cantRegistros++;
    }

    Venta *vec = new Venta[cantRegistros];
    pos = 0;
    while (reg.leerDeDisco(pos++) == true)
    {
        vec[pos - 1] = reg;
    }

    for (int i = 0; i < cantRegistros - 1; i++)
    {
        for (int j = 0; j < cantRegistros - 1; j++)
        {
            if (vec[j].getDniCliente() > vec[j + 1].getDniCliente())
            {
                Venta aux = vec[j];
                vec[j] = vec[j + 1];
                vec[j + 1] = aux;
            }
        }
    }

    bool hayVentas = false;
    for (int i = 0; i < cantRegistros; i++)
    {
        if (vec[i].getEstado())
        {
            hayVentas = true;
            vec[i].Mostrar();
            cout << endl;
        }
    }

    if (!hayVentas)
    {
        cout << "NO HAY VENTAS" << endl;
    }
    delete[] vec;
}

void listadoVentasPorArticulo()
{
    Venta reg;
    int pos = 0;
    int cantRegistros = 0;
    while (reg.leerDeDisco(pos++) == true)
    {
        cantRegistros++;
    }

    Venta *vec = new Venta[cantRegistros];
    pos = 0;
    while (reg.leerDeDisco(pos++) == true)
    {
        vec[pos - 1] = reg;
    }

    for (int i = 0; i < cantRegistros - 1; i++)
    {
        for (int j = 0; j < cantRegistros - 1; j++)
        {
            if (vec[j].getCodigoArticulo() > vec[j + 1].getCodigoArticulo())
            {
                Venta aux = vec[j];
                vec[j] = vec[j + 1];
                vec[j + 1] = aux;
            }
        }
    }

    bool hayVentas = false;
    for (int i = 0; i < cantRegistros; i++)
    {
        if (vec[i].getEstado())
        {
            hayVentas = true;
            vec[i].Mostrar();
            cout << endl;
        }
    }

    if (!hayVentas)
    {
        cout << "NO HAY VENTAS" << endl;
    }
    delete[] vec;
}

void listadoVentasPorMetodoPago()
{
    Venta reg;
    int pos = 0;
    int cantRegistros = 0;
    while (reg.leerDeDisco(pos++) == true)
    {
        cantRegistros++;
    }

    Venta *vec = new Venta[cantRegistros];
    pos = 0;
    while (reg.leerDeDisco(pos++) == true)
    {
        vec[pos - 1] = reg;
    }

    for (int i = 0; i < cantRegistros - 1; i++)
    {
        for (int j = 0; j < cantRegistros - 1; j++)
        {
            if (strcmp(vec[j].getMetodoPago(), vec[j + 1].getMetodoPago()) > 0)
            {
                Venta aux = vec[j];
                vec[j] = vec[j + 1];
                vec[j + 1] = aux;
            }
        }
    }

    bool hayVentas = false;
    for (int i = 0; i < cantRegistros; i++)
    {
        if (vec[i].getEstado())
        {
            hayVentas = true;
            vec[i].Mostrar();
            cout << endl;
        }
    }

    if (!hayVentas)
    {
        cout << "NO HAY VENTAS" << endl;
    }
    delete[] vec;
}

void buscarVentaPorDniCliente()
{
    Venta reg;
    int pos = 0;
    int dni;
    cout << "INGRESE EL DNI DEL CLIENTE A BUSCAR: ";
    cin >> dni;
    while (reg.leerDeDisco(pos++) == true)
    {
        if (reg.getDniCliente() == dni && reg.getEstado())
        {
            reg.Mostrar();
            cout << endl;
        }
    }
}

void buscarVentaPorFecha()
{
    Venta reg;
    int pos = 0;
    Fecha f;
    f.Cargar();
    while (reg.leerDeDisco(pos++) == true)
    {
        if (reg.getFechaTransaccion().getAnio() == f.getAnio() && reg.getFechaTransaccion().getMes() == f.getMes() && reg.getFechaTransaccion().getDia() == f.getDia() && reg.getEstado())
        {
            reg.Mostrar();
            cout << endl;
        }
    }
}

void informeVentasPorMes()
{
    Venta reg;
    int pos = 0;
    int mes;
    int cantVentas = 0;
    cout << "INGRESE EL MES A BUSCAR: ";
    cin >> mes;
    float total = 0;
    while (reg.leerDeDisco(pos++) == true)
    {
        if (reg.getFechaTransaccion().getMes() == mes && reg.getEstado())
        {
            total += reg.getPrecioTotal();
            cantVentas++;
        }
    }
    cout << "TOTAL VENTAS EN EL MES " << mes << ": " << cantVentas << endl;
    cout << "PRECIO FINAL TOTAL VENDIDO: $" << total << endl;
}

void informeVentasPorAnio()
{
    Venta reg;
    int pos = 0;
    int anio;
    int cantVentas = 0;
    cout << "INGRESE EL ANIO A BUSCAR: ";
    cin >> anio;
    float total = 0;
    while (reg.leerDeDisco(pos++) == true)
    {
        if (reg.getFechaTransaccion().getAnio() == anio && reg.getEstado())
        {
            total += reg.getPrecioTotal();
            cantVentas++;
        }
    }
    cout << "TOTAL VENTAS EN EL ANIO " << anio << ": " << cantVentas << endl;
    cout << "PRECIO FINAL TOTAL VENDIDO: $" << total << endl;
}

void buscarVentaPorCodigo()
{
    Venta reg;
    int pos = 0;
    int codigo;
    cout << "INGRESE EL CODIGO DE VENTA A BUSCAR: ";
    cin >> codigo;
    while (reg.leerDeDisco(pos++) == true)
    {
        if (reg.getCodigoVenta() == codigo && reg.getEstado())
        {
            reg.Mostrar();
            cout << endl;
        }
    }
}

#endif