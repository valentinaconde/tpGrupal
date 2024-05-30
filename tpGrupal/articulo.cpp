/*# include<iostream>
# include<cstdlib>
# include<cstring>

using namespace std;

#include "articulo.h"

void Articulo::Cargar(){
        cout<<"CODIGO: ";
        cin>>cod;
        cout<<"DESCRIPCION: ";
        cin>>desc;
        cout<<"PU: ";
        cin>>pu;
        cout<<"STOCK: ";
        cin>>stock;
        estado=true;
      }

void Articulo::Mostrar(){
  if(estado==true){
      cout<<"CODIGO: ";
      cout<<getCod()<<endl;
      cout<<"DESCRIPCION: ";
      cout<<desc<<endl;
      cout<<"PU: ";
      cout<<pu<<endl;
      cout<<"STOCK: ";
      cout<<stock<<endl;
    }
  }

void Articulo::grabarEnDisco(int pos=0){
  FILE *p;
  if(pos==0){
    p=fopen("producto.dat","ab");
    if(p==NULL){
      cout<<"ERROR DE ARCHIVO"<<endl;
      system("pause");
      return;
      }
    }
  else{
    p=fopen("producto.dat","rb+");
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


///this: puntero oculto que contiene la direcci�n del objeto que llama
///al m�todo


bool Articulo::leerDeDisco(int pos){
  FILE *p;
  p=fopen("producto.dat","rb");
  if(p==NULL) return false;
  fseek(p, sizeof(Articulo)*pos, 0);
  bool x=fread(this, sizeof *this,1, p);
  fclose(p);
  return x;
}

//////////PROTOTIPOS
void altaArticulo();
void bajaArticulo();
void listadoArticulos();
int buscarCodigoArticulo(char *);
void grabarRegistro(Articulo);
/*
int main(){
  Articulo a;
  int opc;
  while(true){
    system("cls");
    cout<<"------------MENU ARTICULOS------------"<<endl;
    cout<<"1. ALTA ARTICULOS"<<endl;
    cout<<"2. BAJA ARTICULOS"<<endl;
    cout<<"3. LISTADO"<<endl;
    cout<<"4. SALIR"<<endl;
    cout<<"SELECCIONE UNA OPCION: "<<endl;
    cin>>opc;
    switch(opc){
      case 1: system("cls");
              altaArticulo();
              break;
      case 2: bajaArticulo();
              break;
      case 3: system("cls");
              listadoArticulos();
              break;
      case 4: return 0;
              break;


      }
    system("pause");
  }
  return 0;
}

/////////////////////////////

void altaArticulo(){
  Articulo obj;
  obj.Cargar();
  int pos=buscarCodigoArticulo(obj.getCod());
  if(pos==-1){
    obj.grabarEnDisco();
    cout<<"REGISTRO AGREGADO"<<endl;
    }
  else{
    cout<<"YA EXISTE EL CODIGO DE ARTICULOS"<<endl;
    cout<<"NO SE GRABO EL REGISTRO"<<endl;
    }
  system("pause");
  }

int buscarCodigoArticulo(char *cod){
  Articulo reg;
  int pos=0;
  while(reg.leerDeDisco(pos)){
    if(strcmp(cod, reg.getCod())==0){
       return pos;
      }
    pos++;
    }
 return -1 ;
  }


void grabarRegistro(Articulo reg){
  FILE *p;
  p=fopen("producto.dat","ab");
  if(p==NULL){
    cout<<"ERROR DE ARCHIVO"<<endl;
    system("pause");
    return;
  }
  fwrite(&reg, sizeof reg, 1, p);
  fclose(p);
}

void bajaArticulo(){
    char *cod;
    cout<<"INGRESE EL CODIGO DEL OBJETO A ELIMINAR "<<endl;
    cin>>cod;
    int pos=buscarCodigoArticulo(cod);
    if(pos==-1){
      cout<<"NO EXISTE EL REGISTRO"<<endl;
      system("pause");
      return;
    }
    Articulo obj;
    obj.leerDeDisco(pos);
    obj.setEstado(false);
    obj.grabarEnDisco(pos);
  }

void listadoArticulos(){
  Articulo reg;
  int pos=0;
  while(reg.leerDeDisco(pos++)==true){
    reg.Mostrar();
    cout<<endl;
    }
 }



*/
