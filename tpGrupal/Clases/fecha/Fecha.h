#pragma once
#include <string>


class Fecha
{
    private:
        int _dia,_mes,_anio;

        void AgregarDia();
        void RestarDia();


    public:
        //Constructores
        Fecha(int dia,int mes,int anio);
        Fecha();

        bool esbisiesto(int anio);

        void AgregarDias(int cantidad);

        //Getters
        int getDia();
        int getMes();
        int getAnio();

        //setters
        void setDia(int dia);
        void setMes(int mes);
        void setAnio(int anio);

        //tostring
        std::string toString();

};
