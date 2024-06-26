#include <iostream>
#include "CompraArchivo.h"

bool CompraArchivo::guardar(Compra registro){
    bool result;
    FILE *pFile;

    pFile = fopen("compras.dat", "ab");

    if(pFile == nullptr){

        return false;
    }

    result = fwrite(&registro, sizeof (Compra), 1, pFile);

    fclose(pFile);

    return result;
}

bool CompraArchivo::guardar(int index, Compra registro){
    bool result;
    FILE *pFile;

    pFile = fopen("compras.dat", "rb+");

    if(pFile == nullptr){

      return false;
    }

    fseek(pFile, sizeof(Compra) * index, SEEK_SET);

    result = fwrite(&registro, sizeof (Compra), 1, pFile);

    fclose(pFile);

    return result;
}

Compra CompraArchivo::leer(int index){
    bool result;
    Compra reg;
    FILE *pFile;

    pFile = fopen("compras.dat", "rb");

    if(pFile == nullptr){
      return reg;
    }

    fseek(pFile, index * sizeof (Compra), SEEK_SET);

    fread(&reg, sizeof(Compra), 1, pFile);

    fclose(pFile);

    return reg;
}

void CompraArchivo::leerTodos(Compra registros[], int cantidad){
    bool result;
    FILE *pFile;

    pFile = fopen("compras.dat", "rb");

    if(pFile == nullptr){
      return;
    }

    fread(registros, sizeof(Compra), cantidad, pFile);

    fclose(pFile);
}

int CompraArchivo::buscarByID(int id){
    Compra reg;
    int pos = 0;
    FILE * pFile;

    pFile = fopen("compras.dat", "rb");
    if(pFile == nullptr){
        return -1;
    }

    while(fread(&reg, sizeof(Compra), 1, pFile)){
        if(reg.getNumeroCompra() == id){
            fclose(pFile);
            return pos;
        }
        pos++;
    }

    fclose(pFile);
    return -1;
}

int CompraArchivo::getCantidadRegistros(){
    FILE *pFile;
    int tam;

    pFile = fopen("compras.dat", "rb");

    if(pFile == nullptr){
      return 0;
    }

    fseek(pFile, 0, SEEK_END);

    tam = ftell(pFile) / sizeof (Compra);

    fclose(pFile);

    return tam;
}

int CompraArchivo::getNuevoID(){
    int cantidad = getCantidadRegistros();

    if(cantidad>0){
        return leer(cantidad-1).getNumeroCompra()+1;
    }
    else{
        return 1;
    }
}

