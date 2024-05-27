#ifndef FACTURA_H
#define FACTURA_H

#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

class Factura {
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

    int getNumeroFactura(){return numeroFactura;}
    int getCodigoVenta(){return codigoVenta;}
    float getTotal(){return total;}
    bool getEstado(){return estado;}

    void setNumeroFactura(int n){numeroFactura = n;}
    void setCodigoVenta(int c){codigoVenta = c;}
    void setTotal(float t){if(t>0)total=t;}
    void setEstado(bool s){estado=s;}
};

void Factura::Cargar(){
    cout<<"NUMERO DE FACTURA: ";
    cin>>this->numeroFactura;
    cout<<"CODIGO DE VENTA: ";
    cin>>this->codigoVenta;
    cout<<"TOTAL: ";
    cin>>total;
    estado=true;
}

void Factura::Mostrar(){
    cout<<"NUMERO DE FACTURA: ";
    cout<<getNumeroFactura()<<endl;
    cout<<"CODIGO DE VENTA: ";
    cout<<getCodigoVenta()<<endl;
    cout<<"TOTAL: ";
    cout<<getTotal()<<endl;
    cout<<"ESTADO: ";
    cout<<estado<<endl;
}

void Factura::grabarEnDisco(int pos=-1){
    FILE *p;
    if(pos==-1){
        p=fopen("factura.dat","ab");
        if(p==NULL){
            cout<<"ERROR DE ARCHIVO"<<endl;
            system("pause");
            return;
        }
    }
    else{
        p=fopen("factura.dat","rb+");
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

bool Factura::leerDeDisco(int pos){
    FILE *p;
    p=fopen("factura.dat","rb");
    if(p==NULL) return false;
    fseek(p, sizeof(Factura)*pos, 0);
    bool x=fread(this, sizeof *this,1, p);
    fclose(p);
    return x;
}

//////////PROTOTIPOS
void altaFactura();
void bajaFactura();
void listadoFacturas();
int buscarNumeroFactura(int);
void grabarRegistro(Factura);

void altaFactura(){
    Factura obj;
    obj.Cargar();
    int pos=buscarNumeroFactura(obj.getNumeroFactura());
    if(pos==-1){
        obj.grabarEnDisco();
        cout<<"REGISTRO AGREGADO"<<endl;
    }
    else{
        cout<<"YA EXISTE EL NUMERO DE FACTURA"<<endl;
        cout<<"NO SE GRABO EL REGISTRO"<<endl;
    }
    system("pause");
}

int buscarNumeroFactura(int num){
    Factura reg;
    int pos=0;

    while(reg.leerDeDisco(pos)){
        if(num == reg.getNumeroFactura()){
            return pos;
        }
        pos++;
    }
    return -1 ;
}

void grabarRegistro(Factura reg){
    FILE *p;
    p=fopen("factura.dat","ab");
    if(p==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        system("pause");
        return;
    }
    fwrite(&reg, sizeof reg, 1, p);
    fclose(p);
}

void bajaFactura(){
    int num;
    cout<<"INGRESE EL NUMERO DE FACTURA A ELIMINAR "<<endl;
    cin>>num;
    int pos=buscarNumeroFactura(num);
    if(pos==-1){
        cout<<"NO EXISTE EL REGISTRO"<<endl;
        system("pause");
        return;
    }

    Factura obj;
    obj.leerDeDisco(pos);
    if(!obj.getEstado()){
        cout<<"NO EXISTE EL REGISTRO"<<endl;
        system("pause");
        return;
    }

    obj.setEstado(false);
    obj.grabarEnDisco(pos);
}

void listadoFacturas(){
    Factura reg;
    int pos=0;
    while(reg.leerDeDisco(pos++)==true){
        reg.Mostrar();
        cout<<endl;
    }
}

#endif