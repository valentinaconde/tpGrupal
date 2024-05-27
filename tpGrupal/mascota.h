#ifndef MASCOTA_H
#define MASCOTA_H

#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

class Mascota {
  private:
    int idMascota;
    char nombre[30];
    char especie[30];
    char raza[30];
    int edad;
    char genero[10];
    bool estado;
    char tamano[10];
    char comportamiento[50];
  public:
    void grabarEnDisco(int);
    bool leerDeDisco(int);
    void Cargar();
    void Mostrar();

    int getIdMascota(){return idMascota;}
    char *getNombre(){return nombre;}
    char *getEspecie(){return especie;}
    char *getRaza(){return raza;}
    int getEdad(){return edad;}
    char *getGenero(){return genero;}
    bool getEstado(){return estado;}
    char *getTamano(){return tamano;}
    char *getComportamiento(){return comportamiento;}

    void setIdMascota(int id){idMascota = id;}
    void setNombre(char *n){strcpy(nombre, n);}
    void setEspecie(char *e){strcpy(especie, e);}
    void setRaza(char *r){strcpy(raza, r);}
    void setEdad(int e){if(e>0) edad=e;}
    void setGenero(char *g){strcpy(genero, g);}
    void setEstado(bool s){estado = s;}
    void setTamano(char *t){strcpy(tamano, t);}
    void setComportamiento(char *c){strcpy(comportamiento, c);}
};

void Mascota::Cargar(){
    cout<<"ID MASCOTA: ";
    cin>>this->idMascota;
    cout<<"NOMBRE: ";
    cin>>this->nombre;
    cout<<"ESPECIE: ";
    cin>>this->especie;
    cout<<"RAZA: ";
    cin>>this->raza;
    cout<<"EDAD: ";
    cin>>this->edad;
    cout<<"GENERO: ";
    cin>>this->genero;
    cout<<"ESTADO: ";
    cin>>this->estado;
    cout<<"TAMANO: ";
    cin>>this->tamano;
    cout<<"COMPORTAMIENTO: ";
    cin>>this->comportamiento;
}

void Mascota::Mostrar(){
    cout<<"ID MASCOTA: ";
    cout<<getIdMascota()<<endl;
    cout<<"NOMBRE: ";
    cout<<getNombre()<<endl;
    cout<<"ESPECIE: ";
    cout<<getEspecie()<<endl;
    cout<<"RAZA: ";
    cout<<getRaza()<<endl;
    cout<<"EDAD: ";
    cout<<getEdad()<<endl;
    cout<<"GENERO: ";
    cout<<getGenero()<<endl;
    cout<<"ESTADO: ";
    cout<<getEstado()<<endl;
    cout<<"TAMANO: ";
    cout<<getTamano()<<endl;
    cout<<"COMPORTAMIENTO: ";
    cout<<getComportamiento()<<endl;
}

void Mascota::grabarEnDisco(int pos=-1){
    FILE *p;
    if(pos==-1){
        p=fopen("mascotas.dat","ab");
        if(p==NULL){
            cout<<"ERROR DE ARCHIVO"<<endl;
            system("pause");
            return;
        }
    }
    else{
        p=fopen("mascotas.dat","rb+");
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

bool Mascota::leerDeDisco(int pos){
    FILE *p;
    p=fopen("mascotas.dat","rb");
    if(p==NULL) return false;
    fseek(p, sizeof(Mascota)*pos, 0);
    bool x=fread(this, sizeof *this,1, p);
    fclose(p);
    return x;
}

//////////PROTOTIPOS
void altaMascota();
void bajaMascota();
void listadoMascotas();
int buscarIdMascota(int);
void grabarRegistro(Mascota);

void altaMascota(){
    Mascota obj;
    obj.Cargar();
    int pos=buscarIdMascota(obj.getIdMascota());
    if(pos==-1){
        obj.grabarEnDisco();
        cout<<"REGISTRO AGREGADO"<<endl;
    }
    else{
        cout<<"YA EXISTE EL ID DE MASCOTA"<<endl;
        cout<<"NO SE GRABO EL REGISTRO"<<endl;
    }
    system("pause");
}

int buscarIdMascota(int id){
    Mascota reg;
    int pos=0;

    while(reg.leerDeDisco(pos)){
        if(id == reg.getIdMascota()){
            return pos;
        }
        pos++;
    }
    return -1 ;
}

void grabarRegistro(Mascota reg){
    FILE *p;
    p=fopen("mascotas.dat","ab");
    if(p==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        system("pause");
        return;
    }
    fwrite(&reg, sizeof reg, 1, p);
    fclose(p);
}

void bajaMascota(){
    int id;
    cout<<"INGRESE EL ID DE MASCOTA A ELIMINAR "<<endl;
    cin>>id;
    int pos=buscarIdMascota(id);
    if(pos==-1){
        cout<<"NO EXISTE EL REGISTRO"<<endl;
        system("pause");
        return;
    }

    Mascota obj;
    obj.leerDeDisco(pos);
    if(!obj.getEstado()){
        cout<<"NO EXISTE EL REGISTRO"<<endl;
        system("pause");
        return;
    }

    obj.setEstado(false);
    obj.grabarEnDisco(pos);
}

void listadoMascotas(){
    Mascota reg;
    int pos=0;
    while(reg.leerDeDisco(pos++)==true){
        reg.Mostrar();
        cout<<endl;
    }
}

#endif