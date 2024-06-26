#include <ctime>
#include <iostream>
#include <cstdlib>
#include "Fecha.h"
using namespace std;
//contructor
Fecha::Fecha(int dia,int mes,int anio){
    _dia=dia;
    _mes=mes;
    _anio=anio;

    if(_dia<=0 || _mes<=0 || _anio<=0 || _mes>12 ){
        _dia=1;
        _mes=1;
        _anio=2023;
    }
    else{

    int Meses[12]={31,28,31,30,31,30,31,31,30,31,30,31};

    if(esbisiesto(_anio)== true){
        Meses[1]++;
    }

    if(_dia > Meses[_mes-1]){
        _dia=1;
        _mes=1;
        _anio=2023;
    }
    }

}

Fecha::Fecha(){
    time_t t = time(NULL);
    struct tm *f = localtime(&t);
    _dia = f->tm_mday;
    _mes = f->tm_mon+1;
    _anio = f->tm_year+1900;
}

bool Fecha::esbisiesto(int anio){
    if( (anio % 4 == 0 && anio%100 !=0) || anio%400 ==0 ){
        return true;
    }
    else{
        return false;
    }
}

//Getters
int Fecha::getDia(){
    return _dia;
}

int Fecha::getMes(){
    return _mes;
}

int Fecha::getAnio(){
    return _anio;
}

//Setters
void Fecha::setDia(int dia){
    _dia=dia;
}

void Fecha::setMes(int mes){
    _mes=mes;
}

void Fecha::setAnio(int anio){
    _anio=anio;
}

void Fecha::AgregarDia(){
    _dia++;

    int Meses[12]={31,28,31,30,31,30,31,31,30,31,30,31};

    if(esbisiesto(_anio)== true){
        Meses[1]++;
    }

    if(_dia > Meses[_mes-1]){
        _dia=1;
        _mes++;
        if(_mes>12){
            _mes=1;
            _anio++;
        }
    }
}

void Fecha::RestarDia(){
    _dia--;

    int Meses[12]={31,28,31,30,31,30,31,31,30,31,30,31};

    if(esbisiesto(_anio)== true){
        Meses[1]++;
    }

    if(_dia<1){
        _dia=Meses[_mes-1];
        _mes--;
        if(_mes<1){
            _mes=12;
            _anio--;
        }
    }
}

void Fecha::AgregarDias(int cantidad){
    if(cantidad>0){
    for(int i=0;i<cantidad;i++){
        AgregarDia();
    }
    }
    if(cantidad<0){
        for(int i=0;i<(cantidad*-1);i++){
        RestarDia();
    }
    }


}

std::string Fecha::toString(){
    std::string fechaFormato = "";
    std::string DD = std::to_string(_dia);
    std::string MM = std::to_string(_mes);
    std::string YYYY = std::to_string(_anio);

    if(_dia<10){
        DD = "0" + std::to_string(_dia);
    }
    if(_mes<10){
        MM = "0" + std::to_string(_mes);
    }

    fechaFormato = DD + "/" + MM + "/" + YYYY;

    return fechaFormato;
}

void Fecha::validarDia(int dia, int mes)
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

void Fecha::validarMes(int mes)
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

void Fecha::validarAnio(int anio)
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


void Fecha::cargarFecha()
{
    cout << "ANIO: ";
    cin >> _anio;
    validarAnio(_anio);
    cout << "MES: ";
    cin >> _mes;
    validarMes(_mes);
    cout << "DIA: ";
    cin >> _dia;
    validarDia(_dia, _mes);
}
