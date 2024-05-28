#ifndef FECHA_H
#define FECHA_H

#include <iostream>
using namespace std;
class Fecha
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

void Fecha::Cargar()
{
    cout << "DIA: ";
    cin >> dia;
    cout << "MES: ";
    cin >> mes;
    cout << "ANIO: ";
    cin >> anio;
 
}

void Fecha::Mostrar()
{
    cout << dia << "/";
    cout << mes << "/";
    cout << anio << endl;
}

#endif // FECHA_H