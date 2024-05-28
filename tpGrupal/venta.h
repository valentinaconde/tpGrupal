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

int getPrecioFinal(int codigoArticulo, int cantidad)
{
  FILE *p;
  p = fopen("producto.dat", "rb");
  if (p == NULL)
  {
    cout << "NO HAY ARTICULOS CARGADOS" << endl;
    return 0;
  }

  Articulo reg;
  while (fread(&reg, sizeof reg, 1, p))
  {
    if (reg.getCod() == codigoArticulo)
    {
      fclose(p);
      return reg.getPu() * cantidad;
    }
  }
  fclose(p);
  return 0;
}

int ultimoCodigoVentaAgregado()
{
  FILE *p;
  p = fopen("venta.dat", "rb");
  if (p == NULL)
  {
    cout << "NO HAY VENTAS CARGADAS" << endl;
    return 0;
  }

  Venta reg;
  fseek(p, -sizeof reg, 2);
  fread(&reg, sizeof reg, 1, p);
  cout << "ULTIMO CODIGO DE VENTA AGREGADO: " << reg.getCodigoVenta() << endl;
  fclose(p);
  return reg.getCodigoVenta() + 1;
}
void Venta::Cargar(){
    cout<<"CODIGO VENTA: ";
    cin>>this->codigoVenta;
    cout<<"DNI CLIENTE: ";
    cin>>this->dniCliente;
    cout<<"CODIGO ARTICULO: ";
    cin>>this->codigoArticulo;
    cout<<"CANTIDAD: ";
    cin>>this->cantidad;
    this->precioTotal = getPrecioFinal(this->codigoArticulo, this->cantidad);
    cout<<"ENVIO A DOMICILIO (1 para SI, 0 para NO): ";
    cin>>this->envioDomicilio;
    fechaTransaccion.Cargar();
    cout<<"METODO DE PAGO: ";
    cin>>this->metodoPago;
    
}

void Venta::Mostrar(){
    cout<<"CODIGO DE VENTA: ";
    cout<<getCodigoVenta()<<endl;
    cout<<"DNI CLIENTE: ";
    cout<<getDniCliente()<<endl;
    cout<<"CODIGO ARTICULO: ";
    cout<<getCodigoArticulo()<<endl;
    cout<<"CANTIDAD: ";
    cout<<getCantidad()<<endl;
    cout<<"PRECIO TOTAL: ";
    cout<<getPrecioTotal()<<endl;
    cout<<"PRECIO UNITARIO:";
    cout<<getPrecioTotal()/getCantidad()<<endl;
    cout<<"ENVIO A DOMICILIO: ";
    cout<<(getEnvioDomicilio() ? "SI" : "NO")<<endl;
    cout<<"FECHA DE TRANSACCION: ";
    fechaTransaccion.Mostrar();
    cout<<"METODO DE PAGO: ";
    cout<<getMetodoPago()<<endl;
    
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
    obj.grabarEnDisco();
    cout<<"REGISTRO AGREGADO"<<endl;
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
    system("pause");
}

void listadoVentasPorFechaMayorAMenor(){
    Venta reg;
    int pos=0;
    int cantRegistros=0;
    while(reg.leerDeDisco(pos++)==true){
        cantRegistros++;
    }

    Venta *vec = new Venta[cantRegistros];
    pos=0;
    while(reg.leerDeDisco(pos++)==true){
        vec[pos-1] = reg;
    }

    for(int i=0; i<cantRegistros-1; i++){
        for(int j=0; j<cantRegistros-1; j++){
            if(vec[j].getFechaTransaccion().getAnio() < vec[j+1].getFechaTransaccion().getAnio()){
                Venta aux = vec[j];
                vec[j] = vec[j+1];
                vec[j+1] = aux;
            }
            else if(vec[j].getFechaTransaccion().getAnio() == vec[j+1].getFechaTransaccion().getAnio()){
                if(vec[j].getFechaTransaccion().getMes() < vec[j+1].getFechaTransaccion().getMes()){
                    Venta aux = vec[j];
                    vec[j] = vec[j+1];
                    vec[j+1] = aux;
                }
                else if(vec[j].getFechaTransaccion().getMes() == vec[j+1].getFechaTransaccion().getMes()){
                    if(vec[j].getFechaTransaccion().getDia() < vec[j+1].getFechaTransaccion().getDia()){
                        Venta aux = vec[j];
                        vec[j] = vec[j+1];
                        vec[j+1] = aux;
                    }
                }
            }
        }
    }

    for(int i=0; i<cantRegistros; i++){
        vec[i].Mostrar();
        cout<<endl;
    }
    delete[] vec;
    system("pause");  

}

void listadoVentasPorCliente(){
    Venta reg;
    int pos=0;
    int cantRegistros=0;
    while(reg.leerDeDisco(pos++)==true){
        cantRegistros++;
    }

    Venta *vec = new Venta[cantRegistros];
    pos=0;
    while(reg.leerDeDisco(pos++)==true){
        vec[pos-1] = reg;
    }

    for(int i=0; i<cantRegistros-1; i++){
        for(int j=0; j<cantRegistros-1; j++){
            if(vec[j].getDniCliente() > vec[j+1].getDniCliente()){
                Venta aux = vec[j];
                vec[j] = vec[j+1];
                vec[j+1] = aux;
            }
        }
    }

    for(int i=0; i<cantRegistros; i++){
        vec[i].Mostrar();
        cout<<endl;
    }
    delete[] vec;
    system("pause");  
}

void listadoVentasPorArticulo(){
    Venta reg;
    int pos=0;
    int cantRegistros=0;
    while(reg.leerDeDisco(pos++)==true){
        cantRegistros++;
    }

    Venta *vec = new Venta[cantRegistros];
    pos=0;
    while(reg.leerDeDisco(pos++)==true){
        vec[pos-1] = reg;
    }

    for(int i=0; i<cantRegistros-1; i++){
        for(int j=0; j<cantRegistros-1; j++){
            if(vec[j].getCodigoArticulo() > vec[j+1].getCodigoArticulo()){
                Venta aux = vec[j];
                vec[j] = vec[j+1];
                vec[j+1] = aux;
            }
        }
    }

    for(int i=0; i<cantRegistros; i++){
        vec[i].Mostrar();
        cout<<endl;
    }
    delete[] vec;
    system("pause");  
}

void listadoVentasPorMetodoPago(){
    Venta reg;
    int pos=0;
    int cantRegistros=0;
    while(reg.leerDeDisco(pos++)==true){
        cantRegistros++;
    }

    Venta *vec = new Venta[cantRegistros];
    pos=0;
    while(reg.leerDeDisco(pos++)==true){
        vec[pos-1] = reg;
    }

    for(int i=0; i<cantRegistros-1; i++){
        for(int j=0; j<cantRegistros-1; j++){
            if(strcmp(vec[j].getMetodoPago(), vec[j+1].getMetodoPago()) > 0){
                Venta aux = vec[j];
                vec[j] = vec[j+1];
                vec[j+1] = aux;
            }
        }
    }

    for(int i=0; i<cantRegistros; i++){
        vec[i].Mostrar();
        cout<<endl;
    }
    delete[] vec;
    system("pause");  
}

void buscarVentaPorDniCliente(){
    Venta reg;
    int pos=0;
    int dni;
    cout<<"INGRESE EL DNI DEL CLIENTE A BUSCAR: ";
    cin>>dni;
    while(reg.leerDeDisco(pos++)==true){
        if(reg.getDniCliente() == dni){
            reg.Mostrar();
            cout<<endl;
        }
    }
    system("pause");
}

void buscarVentaPorFecha(){
    Venta reg;
    int pos=0;
    Fecha f;
    f.Cargar();
    while(reg.leerDeDisco(pos++)==true){
        if(reg.getFechaTransaccion().getAnio() == f.getAnio() && reg.getFechaTransaccion().getMes() == f.getMes() && reg.getFechaTransaccion().getDia() == f.getDia()){
            reg.Mostrar();
            cout<<endl;
        }
    }
    system("pause");
}

void informeVentasPorMes(){
    Venta reg;
    int pos=0;
    int mes;
    int cantVentas=0;
    cout<<"INGRESE EL MES A BUSCAR: ";
    cin>>mes;
    float total=0;
    while(reg.leerDeDisco(pos++)==true){
        if(reg.getFechaTransaccion().getMes() == mes){
            total+=reg.getPrecioTotal();
            cantVentas++;
        }
    }
    cout<<"TOTAL VENTAS EN EL MES " <<mes<< ": " <<cantVentas<<endl;
    cout<<"PRECIO FINAL TOTAL VENDIDO: $"<<total<<endl;
    system("pause");
}

void informeVentasPorAnio(){
    Venta reg;
    int pos=0;
    int anio;
    int cantVentas=0;
    cout<<"INGRESE EL ANIO A BUSCAR: ";
    cin>>anio;
    float total=0;
    while(reg.leerDeDisco(pos++)==true){
        if(reg.getFechaTransaccion().getAnio() == anio){
            total+=reg.getPrecioTotal();
            cantVentas++;
        }
    }
    cout<<"TOTAL VENTAS EN EL ANIO " <<anio<< ": " <<cantVentas<<endl;
    cout<<"PRECIO FINAL TOTAL VENDIDO: $"<<total<<endl;
    system("pause");
}

#endif