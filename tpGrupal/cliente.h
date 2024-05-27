#ifndef CLIENTE_H
#define CLIENTE_H

#include <iostream>
#include <cstring>
#include <cstdio>
#include "fecha.h"

using namespace std;

class Cliente {
  private:
    char nombre[30];
    char apellido[30];
    int dni;
    char direccion[100];
    char contacto[30];
    Fecha fechaRegistro;
    bool estado;
  public:
    void grabarEnDisco(int);
    bool leerDeDisco(int);
    void Cargar();
    void Mostrar();

    char *getNombre(){return nombre;}
    char *getApellido(){return apellido;}
    int getDni(){return dni;}
    char *getDireccion(){return direccion;}
    char *getContacto(){return contacto;}
    Fecha getFechaRegistro(){return fechaRegistro;}
    bool getEstado(){return estado;}

    void setNombre(char *n){strcpy(nombre, n);}
    void setApellido(char *a){strcpy(apellido, a);}
    void setDni(int d){dni = d;}
    void setDireccion(char *d){strcpy(direccion, d);}
    void setContacto(char *c){strcpy(contacto, c);}
    void setFechaRegistro(Fecha f){fechaRegistro = f;}
    void setEstado(bool s){estado=s;}
};

void Cliente::Cargar(){
    cout<<"NOMBRE: ";
    cin>>this->nombre;
    cout<<"APELLIDO: ";
    cin>>this->apellido;
    cout<<"DNI: ";
    cin>>this->dni;
    cout<<"DIRECCION: ";
    cin>>this->direccion;
    cout<<"CONTACTO: ";
    cin>>this->contacto;
    // Asumiendo que la fecha se carga de alguna manera
    estado=true;
}

void Cliente::Mostrar(){
    cout<<"NOMBRE: ";
    cout<<getNombre()<<endl;
    cout<<"APELLIDO: ";
    cout<<getApellido()<<endl;
    cout<<"DNI: ";
    cout<<getDni()<<endl;
    cout<<"DIRECCION: ";
    cout<<getDireccion()<<endl;
    cout<<"CONTACTO: ";
    cout<<getContacto()<<endl;
    // Asumiendo que la fecha se muestra de alguna manera
    cout<<"ESTADO: ";
    cout<<estado<<endl;
}

void Cliente::grabarEnDisco(int pos=-1){
    FILE *p;
    if(pos==-1){
        p=fopen("cliente.dat","ab");
        if(p==NULL){
            cout<<"ERROR DE ARCHIVO"<<endl;
            system("pause");
            return;
        }
    }
    else{
        p=fopen("cliente.dat","rb+");
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

bool Cliente::leerDeDisco(int pos){
    FILE *p;
    p=fopen("cliente.dat","rb");
    if(p==NULL) return false;
    fseek(p, sizeof(Cliente)*pos, 0);
    bool x=fread(this, sizeof *this,1, p);
    fclose(p);
    return x;
}

//////////PROTOTIPOS
void altaCliente();
void bajaCliente();
void listadoClientes();
int buscarDniCliente(int);
void grabarRegistro(Cliente);

void altaCliente(){
    Cliente obj;
    obj.Cargar();
    int pos=buscarDniCliente(obj.getDni());
    if(pos==-1){
        obj.grabarEnDisco();
        cout<<"REGISTRO AGREGADO"<<endl;
    }
    else{
        cout<<"YA EXISTE EL DNI DEL CLIENTE"<<endl;
        cout<<"NO SE GRABO EL REGISTRO"<<endl;
    }
    system("pause");
}

int buscarDniCliente(int dni){
    Cliente reg;
    int pos=0;

    while(reg.leerDeDisco(pos)){
        if(dni == reg.getDni()){
            return pos;
        }
        pos++;
    }
    return -1 ;
}

void grabarRegistro(Cliente reg){
    FILE *p;
    p=fopen("cliente.dat","ab");
    if(p==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        system("pause");
        return;
    }
    fwrite(&reg, sizeof reg, 1, p);
    fclose(p);
}

void bajaCliente(){
    int dni;
    cout<<"INGRESE EL DNI DEL CLIENTE A ELIMINAR "<<endl;
    cin>>dni;
    int pos=buscarDniCliente(dni);
    if(pos==-1){
        cout<<"NO EXISTE EL REGISTRO"<<endl;
        system("pause");
        return;
    }

    Cliente obj;
    obj.leerDeDisco(pos);
    if(!obj.getEstado()){
        cout<<"NO EXISTE EL REGISTRO"<<endl;
        system("pause");
        return;
    }

    obj.setEstado(false);
    obj.grabarEnDisco(pos);
}

void listadoClientes(){
    Cliente reg;
    int pos=0;
    while(reg.leerDeDisco(pos++)==true){
        reg.Mostrar();
        cout<<endl;
    }
}

#endif