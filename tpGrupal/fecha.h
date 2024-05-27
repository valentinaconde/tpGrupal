#ifndef FECHA_H
#define FECHA_H

#include <iostream>

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
    std::cin >> dia;
    std::cin >> mes;
    std::cin >> anio;
}

void Fecha::Mostrar()
{
    std::cout << dia << "/";
    std::cout << mes << "/";
    std::cout << anio << std::endl;
}

#endif // FECHA_H