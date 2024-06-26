#include "ArticuloArchivo.h"
#include <iostream>

bool ArticuloArchivo::guardar(Articulo registro){
    bool result;
    FILE *pFile;

    pFile = fopen("articulos.dat", "ab");

    if(pFile == nullptr){

        return false;
    }

    result = fwrite(&registro, sizeof (Articulo), 1, pFile);

    fclose(pFile);

    return result;
}

bool ArticuloArchivo::guardar(int index, Articulo registro){
    bool result;
    FILE *pFile;

    pFile = fopen("articulos.dat", "rb+");

    if(pFile == nullptr){

      return false;
    }

    fseek(pFile, sizeof(Articulo) * index, SEEK_SET);

    result = fwrite(&registro, sizeof (Articulo), 1, pFile);

    fclose(pFile);

    return result;
}

Articulo ArticuloArchivo::leer(int index){
    bool result;
    Articulo reg;
    FILE *pFile;

    pFile = fopen("articulos.dat", "rb");

    if(pFile == nullptr){
      return reg;
    }

    fseek(pFile, index * sizeof (Articulo), SEEK_SET);

    fread(&reg, sizeof(Articulo), 1, pFile);

    fclose(pFile);

    return reg;
}

void ArticuloArchivo::leerTodos(Articulo registros[], int cantidad){
    bool result;
    FILE *pFile;

    pFile = fopen("articulos.dat", "rb");

    if(pFile == nullptr){
      return;
    }

    fread(registros, sizeof(Articulo), cantidad, pFile);

    fclose(pFile);
}

int ArticuloArchivo::buscarByID(int id){
    Articulo reg;
    int pos = 0;
    FILE * pFile;

    pFile = fopen("articulos.dat", "rb");
    if(pFile == nullptr){
        return -1;
    }

    while(fread(&reg, sizeof(Articulo), 1, pFile)){
        if(reg.getCodigo() == id){
            fclose(pFile);
            return pos;
        }
        pos++;
    }

    fclose(pFile);
    return -1;
}

int ArticuloArchivo::getCantidadRegistros(){
    FILE *pFile;
    int tam;

    pFile = fopen("articulos.dat", "rb");

    if(pFile == nullptr){
      return 0;
    }

    fseek(pFile, 0, SEEK_END);

    tam = ftell(pFile) / sizeof (Articulo);

    fclose(pFile);

    return tam;
}

int ArticuloArchivo::getNuevoID(){
    int cantidad = getCantidadRegistros();

    if(cantidad>0){
        return leer(cantidad-1).getCodigo()+1;
    }
    else{
        return 1;
    }
}
