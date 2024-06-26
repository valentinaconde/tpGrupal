#include <iostream>
#include "DetalleCompraArchivo.h"

bool DetalleCompraArchivo::guardar(DetalleCompra registro){
    bool result;
    FILE *pFile;

    pFile = fopen("detallecompras.dat", "ab");

    if(pFile == nullptr){

        return false;
    }

    result = fwrite(&registro, sizeof (DetalleCompra), 1, pFile);

    fclose(pFile);

    return result;
}


bool DetalleCompraArchivo::guardar(int index, DetalleCompra registro){
    bool result;
    FILE *pFile;

    pFile = fopen("detallecompras.dat", "rb+");

    if(pFile == nullptr){

      return false;
    }

    fseek(pFile, sizeof(DetalleCompra) * index, SEEK_SET);

    result = fwrite(&registro, sizeof (DetalleCompra), 1, pFile);

    fclose(pFile);

    return result;
}


DetalleCompra DetalleCompraArchivo::leer(int index){
    bool result;
    DetalleCompra reg;
    FILE *pFile;

    pFile = fopen("detallecompras.dat", "rb");

    if(pFile == nullptr){
      return reg;
    }

    fseek(pFile, index * sizeof (DetalleCompra), SEEK_SET);

    fread(&reg, sizeof(DetalleCompra), 1, pFile);

    fclose(pFile);

    return reg;
}


void DetalleCompraArchivo::leerTodos(DetalleCompra registros[], int cantidad){
    bool result;
    FILE *pFile;

    pFile = fopen("detallecompras.dat", "rb");

    if(pFile == nullptr){
      return;
    }

    fread(registros, sizeof(DetalleCompra), cantidad, pFile);

    fclose(pFile);
}


int DetalleCompraArchivo::buscarByID(int id){
    DetalleCompra reg;
    int pos = 0;
    FILE * pFile;

    pFile = fopen("detallecompras.dat", "rb");
    if(pFile == nullptr){
        return -1;
    }

    while(fread(&reg, sizeof(DetalleCompra), 1, pFile)){
        if(reg.getID() == id){
            fclose(pFile);
            return pos;
        }
        pos++;
    }

    fclose(pFile);
    return -1;
}


int DetalleCompraArchivo::getCantidadRegistros(){
    FILE *pFile;
    int tam;

    pFile = fopen("detallecompras.dat", "rb");

    if(pFile == nullptr){
      return 0;
    }

    fseek(pFile, 0, SEEK_END);

    tam = ftell(pFile) / sizeof (DetalleCompra);

    fclose(pFile);

    return tam;
}


int DetalleCompraArchivo::getNuevoID(){
    int cantidad = getCantidadRegistros();

    if(cantidad>0){
        return leer(cantidad-1).getID()+1;
    }
    else{
        return 1;
    }
}
