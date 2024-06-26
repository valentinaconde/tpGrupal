#include <iostream>
#include "FacturaArchivo.h"

bool FacturaArchivo::guardar(Factura registro){
    bool result;
    FILE *pFile;

    pFile = fopen("facturas.dat", "ab");

    if(pFile == nullptr){

        return false;
    }

    result = fwrite(&registro, sizeof (Factura), 1, pFile);

    fclose(pFile);

    return result;
}

bool FacturaArchivo::guardar(int index, Factura registro){
    bool result;
    FILE *pFile;

    pFile = fopen("facturas.dat", "rb+");

    if(pFile == nullptr){

      return false;
    }

    fseek(pFile, sizeof(Factura) * index, SEEK_SET);

    result = fwrite(&registro, sizeof (Factura), 1, pFile);

    fclose(pFile);

    return result;
}

Factura FacturaArchivo::leer(int index){
    bool result;
    Factura reg;
    FILE *pFile;

    pFile = fopen("facturas.dat", "rb");

    if(pFile == nullptr){
      return reg;
    }

    fseek(pFile, index * sizeof (Factura), SEEK_SET);

    fread(&reg, sizeof(Factura), 1, pFile);

    fclose(pFile);

    return reg;
}

void FacturaArchivo::leerTodos(Factura registros[], int cantidad){
    bool result;
    FILE *pFile;

    pFile = fopen("facturas.dat", "rb");

    if(pFile == nullptr){
      return;
    }

    fread(registros, sizeof(Factura), cantidad, pFile);

    fclose(pFile);
}

int FacturaArchivo::buscarByID(int id){
    Factura reg;
    int pos = 0;
    FILE * pFile;

    pFile = fopen("facturas.dat", "rb");
    if(pFile == nullptr){
        return -1;
    }

    while(fread(&reg, sizeof(Factura), 1, pFile)){
        if(reg.getNumeroFactura() == id){
            fclose(pFile);
            return pos;
        }
        pos++;
    }

    fclose(pFile);
    return -1;
}

int FacturaArchivo::getCantidadRegistros(){
    FILE *pFile;
    int tam;

    pFile = fopen("facturas.dat", "rb");

    if(pFile == nullptr){
      return 0;
    }

    fseek(pFile, 0, SEEK_END);

    tam = ftell(pFile) / sizeof (Factura);

    fclose(pFile);

    return tam;
}

int FacturaArchivo::getNuevoID(){
    int cantidad = getCantidadRegistros();

    if(cantidad>0){
        return leer(cantidad-1).getNumeroFactura()+1;
    }
    else{
        return 1;
    }
}

