#ifndef FECHA_H
#define FECHA_H

class Fechas
{
private:
    int dia, mes, anio;

public:
    void Cargar();
    void Mostrar();
    int getDia() { return dia; }
    int getMes() { return mes; }
    int getAnio() { return anio; }

    void setDia(int d) { dia = d; }
    void setMes(int m) { mes = m; }
    void setAnio(int a) { anio = a; }
};

void validarDia(int &dia, int mes)
{

    bool isValid = false;
    while (!isValid)
    {
        if ((dia < 1 || dia > 31) || (mes == 2 && dia > 29) || ((mes == 4 || mes == 6 || mes == 9 || mes == 11) && dia > 30))
        {
            cout << "DIA INVALIDO, INGRESE NUEVAMENTE: ";
            cin >> dia;
        }
        else
        {
            isValid = true;
        }
    }
}

void validarMes(int &mes)
{
    bool isValid = false;
    while (!isValid)
    {
        if (mes >= 1 && mes <= 12)
        {
            isValid = true;
        }
        else
        {
            cout << "MES INVALIDO, INGRESE NUEVAMENTE: ";
            cin >> mes;
        }
    }
}

void validarAnio(int &anio)
{
    bool isValid = false;
    while (!isValid)
    {
        if (anio >= 1900 && anio <= 2024)
        {
            isValid = true;
        }
        else
        {
            cout << "ANIO INVALIDO, INGRESE NUEVAMENTE: ";
            cin >> anio;
        }
    }
}

void Fecha::Cargar()
{
    cout << "ANIO: ";
    cin >> anio;
    validarAnio(anio);
    cout << "MES: ";
    cin >> mes;
    validarMes(mes);
    cout << "DIA: ";
    cin >> dia;
    validarDia(dia, mes);
}

void Fecha::Mostrar()
{
    cout << dia << "/";
    cout << mes << "/";
    cout << anio << endl;
}

#endif