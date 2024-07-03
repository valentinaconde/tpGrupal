#pragma once
#include <string>

using namespace std;


class Fecha
{
    private:
        int _dia,_mes,_anio;




    public:
        void AgregarDia();
        void RestarDia();
        void mostrarFecha();
        //Constructores
        Fecha(int dia,int mes,int anio);
        Fecha();

        bool esbisiesto(int anio);

        void AgregarDias(int cantidad);

        void validarDia(int, int, int);
        void validarMes(int);
        void validarAnio(int);
        void cargarFecha();

        //Getters
        int getDia();
        int getMes();
        int getAnio();

        //setters
        void setDia(int dia);
        void setMes(int mes);
        void setAnio(int anio);



        //tostring
        string toString();

};


