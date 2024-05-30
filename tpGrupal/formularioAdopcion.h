#ifndef FORMULARIOADOPCION_H
#define FORMULARIOADOPCION_H

#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

class FormularioAdopcion {
  private:
    int idAdopcion;
    char nombre[30];
    char apellido[30];
    int cantidadMascotas;
    int edad;
    int idMascota;
    char direccion[50];
    char telefono[15];
    bool estado;
  public:
    void grabarEnDisco(int);
    bool leerDeDisco(int);
    void Cargar();
    void Mostrar();

    int getIdAdopcion(){return idAdopcion;}
    char *getNombre(){return nombre;}
    char *getApellido(){return apellido;}
    int getCantidadMascotas(){return cantidadMascotas;}
    int getEdad(){return edad;}
    int getIdMascota(){return idMascota;}
    char *getDireccion(){return direccion;}
    char *getTelefono(){return telefono;}
    bool getEstado(){return estado;}

    void setIdAdopcion(int id){idAdopcion = id;}
    void setNombre(char *n){strcpy(nombre, n);}
    void setApellido(char *a){strcpy(apellido, a);}
    void setCantidadMascotas(int c){if(c>=0) cantidadMascotas=c;}
    void setEdad(int e){if(e>0) edad=e;}
    void setIdMascota(int id){idMascota = id;}
    void setDireccion(char *d){strcpy(direccion, d);}
    void setTelefono(char *t){strcpy(telefono, t);}
    void setEstado(bool s){estado=s;}
};

void FormularioAdopcion::Cargar(){
    cout<<"ID ADOPCION: ";
    cin>>idAdopcion;
    cout<<"ID MASCOTA ELEGIDA: ";
    cin>>idMascota;
    cout<<"NOMBRE: ";
    cargarCadena(nombre, 30);
    cout<<"APELLIDO: ";
    cargarCadena(apellido, 30);
    cout<<"EDAD: ";
    cin>>edad;
    cout<<"CANTIDAD DE MASCOTAS EN CASA: ";
    cin>>cantidadMascotas;
    cout<<"DIRECCION: ";
    cargarCadena(direccion, 50);
    cout<<"TELEFONO DE CONTACTO: ";
    cin>>telefono;
    estado = true;
}

void FormularioAdopcion::Mostrar(){
    cout<<"ID ADOPTION: ";
    cout<<getIdAdopcion()<<endl;
    cout<<"NOMBRE: ";
    cout<<getNombre()<<endl;
    cout<<"APELLIDO: ";
    cout<<getApellido()<<endl;
    cout<<"CANTIDAD DE MASCOTAS: ";
    cout<<getCantidadMascotas()<<endl;
    cout<<"EDAD: ";
    cout<<getEdad()<<endl;
    cout<<"ID MASCOTA: ";
    cout<<getIdMascota()<<endl;
    cout<<"DIRECCION: ";
    cout<<getDireccion()<<endl;
    cout<<"TELEFONO: ";
    cout<<getTelefono()<<endl;
    cout << "ESTADO: ";
    cout << getEstado() << endl;
}

void FormularioAdopcion::grabarEnDisco(int pos=-1){
    FILE *p;
    if(pos==-1){
        p=fopen("formularioAdopcion.dat","ab");
        if(p==NULL){
            cout<<"ERROR DE ARCHIVO"<<endl;
            system("pause");
            return;
        }
    }
    else{
        p=fopen("formularioAdopcion.dat","rb+");
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

bool FormularioAdopcion::leerDeDisco(int pos){
    FILE *p;
    p=fopen("formularioAdopcion.dat","rb");
    if(p==NULL) return false;
    fseek(p, sizeof(FormularioAdopcion)*pos, 0);
    bool x=fread(this, sizeof *this,1, p);
    fclose(p);
    return x;
}

//////////PROTOTIPOS
void altaFormularioAdopcion();
void bajaFormularioAdopcion();
void listadoFormulariosAdopcion();
int buscarIdAdopcion(int);
void grabarRegistro(FormularioAdopcion);

void altaFormularioAdopcion(){
    FormularioAdopcion obj;
    obj.Cargar();
    int pos=buscarIdAdopcion(obj.getIdAdopcion());
    if(pos==-1){
        obj.grabarEnDisco();
        cout<<"REGISTRO AGREGADO"<<endl;
    }
    else{
        cout<<"YA EXISTE EL ID DE ADOPCION"<<endl;
        cout<<"NO SE GRABO EL REGISTRO"<<endl;
    }
    system("pause");
}

int buscarIdAdopcion(int id){
    FormularioAdopcion reg;
    int pos=0;

    while(reg.leerDeDisco(pos)){
        if(id == reg.getIdAdopcion()){
            return pos;
        }
        pos++;
    }
    return -1 ;
}

void grabarRegistro(FormularioAdopcion reg){
    FILE *p;
    p=fopen("formularioAdopcion.dat","ab");
    if(p==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        system("pause");
        return;
    }
    fwrite(&reg, sizeof reg, 1, p);
    fclose(p);
}

void bajaFormularioAdopcion(){
    int id;
    cout<<"INGRESE EL ID DE ADOPCION A ELIMINAR "<<endl;
    cin>>id;
    int pos=buscarIdAdopcion(id);
    if(pos==-1){
        cout<<"NO EXISTE EL REGISTRO"<<endl;
        system("pause");
        return;
    }

    FormularioAdopcion obj;
    obj.leerDeDisco(pos);
    if(!obj.getEstado()){
        cout<<"NO EXISTE EL REGISTRO"<<endl;
        system("pause");
        return;
    }

    obj.setEstado(false);
    obj.grabarEnDisco(pos);
}

void listadoFormulariosAdopcion(){
    FormularioAdopcion reg;
    int pos=0;
    while(reg.leerDeDisco(pos++)==true){
        reg.Mostrar();
        cout<<endl;
    }
}
int ultimoCodigoRegistroAgregado()
{
  FILE *p;
  p = fopen("producto.dat", "rb");
  if (p == NULL)
  {

    return 0;
  }

  RegistroAdopcion reg;
  fseek(p, -sizeof reg, 2);
  fread(&reg, sizeof reg, 1, p);
  cout << "ULTIMO CODIGO DE ARTICULO AGREGADO: " << reg.getIdRegistro() << endl;
  fclose(p);
  return reg.getIdRegistro() + 1;
}

void aprobarRechazarAdopcion(){
    int id;
    cout<<"INGRESE EL ID DE ADOPCION A APROBAR O RECHAZAR"<<endl;
    cin>>id;
    int pos=buscarIdAdopcion(id);
    if(pos==-1){
        cout<<"NO EXISTE EL REGISTRO"<<endl;
        system("pause");
        return;
    }

    FormularioAdopcion obj;
    obj.leerDeDisco(pos);
    
    if(!obj.getEstado()){
        cout<<"NO EXISTE EL REGISTRO"<<endl;
        system("pause");
        return;
    }

    cout<<"1. APROBAR"<<endl;
    cout<<"2. RECHAZAR"<<endl;
    int opc;
    cin>>opc;

    RegistroAdopcion reg;
    reg.leerDeDisco(pos);

    Mascota mascota;
    mascota.leerDeDisco(buscarIdMascota(obj.getIdMascota()));


    if(opc==1){
        reg.setIdRegistro(ultimoCodigoRegistroAgregado());
        reg.setIdAdopcion(obj.getIdAdopcion());
        reg.grabarEnDisco();
        mascota.setEstado(false);
        mascota.grabarEnDisco(buscarIdMascota(obj.getIdMascota()));
    }
    else if(opc==2){
        obj.setEstado(false);
        obj.grabarEnDisco(pos);
    }
    else{
        cout<<"OPCION INCORRECTA"<<endl;
    }
}

#endif