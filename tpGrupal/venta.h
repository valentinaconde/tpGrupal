#ifndef VENTA_H
#define VENTA_H

#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

#include "fecha.h"

class Venta {
  private:
    int codigoVenta;
    int dniCliente;
    int codigoArticulo;
    float precioTotal;
    bool envioDomicilio;
    Fecha fechaTransaccion;
    char metodoPago[30];
    int cantidad;
    bool estado;
  public:
    void grabarEnDisco(int);
    bool leerDeDisco(int);
    void Cargar();
    void Mostrar();

    int getCodigoVenta(){return codigoVenta;}
    int getDniCliente(){return dniCliente;}
    int getCodigoArticulo(){return codigoArticulo;}
    float getPrecioTotal(){return precioTotal;}
    bool getEnvioDomicilio(){return envioDomicilio;}
    Fecha getFechaTransaccion(){return fechaTransaccion;}
    char *getMetodoPago(){return metodoPago;}
    int getCantidad(){return cantidad;}
    bool getEstado(){return estado;}

    void setCodigoVenta(int c){codigoVenta = c;}
    void setDniCliente(int d){dniCliente = d;}
    void setCodigoArticulo(int c){codigoArticulo = c;}
    void setPrecioTotal(float p){if(p>0)precioTotal=p;}
    void setEnvioDomicilio(bool e){envioDomicilio=e;}
    void setFechaTransaccion(Fecha f){fechaTransaccion = f;}
    void setMetodoPago(char *m){strcpy(metodoPago, m);}
    void setCantidad(int c){if(c>0)cantidad=c;}
    void setEstado(bool e){estado=e;}
};

void Venta::Cargar(){
    cout<<"CODIGO DE VENTA: ";
    cin>>this->codigoVenta;
    cout<<"DNI CLIENTE: ";
    cin>>this->dniCliente;
    cout<<"CODIGO ARTICULO: ";
    cin>>this->codigoArticulo;
    cout<<"PRECIO TOTAL: ";
    cin>>this->precioTotal;
    cout<<"ENVIO A DOMICILIO (1 para SI, 0 para NO): ";
    cin>>this->envioDomicilio;
    // Asumiendo que la fecha se carga de alguna manera
    cout<<"METODO DE PAGO: ";
    cin>>this->metodoPago;
    cout<<"CANTIDAD: ";
    cin>>this->cantidad;
}

void Venta::Mostrar(){
    cout<<"CODIGO DE VENTA: ";
    cout<<getCodigoVenta()<<endl;
    cout<<"DNI CLIENTE: ";
    cout<<getDniCliente()<<endl;
    cout<<"CODIGO ARTICULO: ";
    cout<<getCodigoArticulo()<<endl;
    cout<<"PRECIO TOTAL: ";
    cout<<getPrecioTotal()<<endl;
    cout<<"ENVIO A DOMICILIO: ";
    cout<<(getEnvioDomicilio() ? "SI" : "NO")<<endl;
    // Asumiendo que la fecha se muestra de alguna manera
    cout<<"METODO DE PAGO: ";
    cout<<getMetodoPago()<<endl;
    cout<<"CANTIDAD: ";
    cout<<getCantidad()<<endl;
}

void Venta::grabarEnDisco(int pos=-1){
    FILE *p;
    if(pos==-1){
        p=fopen("venta.dat","ab");
        if(p==NULL){
            cout<<"ERROR DE ARCHIVO"<<endl;
            system("pause");
            return;
        }
    }
    else{
        p=fopen("venta.dat","rb+");
        if(p==NULL){
            cout<<"ERROR DE ARCHIVO"<<endl;
            system("pause");
            return;
        }
        fseek(p, sizeof *this*pos, 0);
    }
    fwrite(this, sizeof *this, 1, p);
    fclose(p);
}

bool Venta::leerDeDisco(int pos){
    FILE *p;
    p=fopen("venta.dat","rb");
    if(p==NULL) return false;
    fseek(p, sizeof(Venta)*pos, 0);
    bool x=fread(this, sizeof *this,1, p);
    fclose(p);
    return x;
}

//////////PROTOTIPOS
void altaVenta();
void bajaVenta();
void listadoVentas();
int buscarCodigoVenta(int);
void grabarRegistro(Venta);

void altaVenta(){
    Venta obj;
    obj.Cargar();
    int pos=buscarCodigoVenta(obj.getCodigoVenta());
    if(pos==-1){
        obj.grabarEnDisco();
        cout<<"REGISTRO AGREGADO"<<endl;
    }
    else{
        cout<<"YA EXISTE EL CODIGO DE VENTA"<<endl;
        cout<<"NO SE GRABO EL REGISTRO"<<endl;
    }
    system("pause");
}

int buscarCodigoVenta(int cod){
    Venta reg;
    int pos=0;

    while(reg.leerDeDisco(pos)){
        if(cod == reg.getCodigoVenta()){
            return pos;
        }
        pos++;
    }
    return -1 ;
}

void grabarRegistro(Venta reg){
    FILE *p;
    p=fopen("venta.dat","ab");
    if(p==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        system("pause");
        return;
    }
    fwrite(&reg, sizeof reg, 1, p);
    fclose(p);
}

void bajaVenta(){
    int cod;
    cout<<"INGRESE EL CODIGO DE VENTA A ELIMINAR "<<endl;
    cin>>cod;
    int pos=buscarCodigoVenta(cod);
    if(pos==-1){
        cout<<"NO EXISTE EL REGISTRO"<<endl;
        system("pause");
        return;
    }

    Venta obj;
    obj.leerDeDisco(pos);
    if(!obj.getEstado()){
        cout<<"NO EXISTE EL REGISTRO"<<endl;
        system("pause");
        return;
    }

    obj.setEstado(false);
    obj.grabarEnDisco(pos);
}

void listadoVentas(){
    Venta reg;
    int pos=0;
    while(reg.leerDeDisco(pos++)==true){
        reg.Mostrar();
        cout<<endl;
    }
}

#endif