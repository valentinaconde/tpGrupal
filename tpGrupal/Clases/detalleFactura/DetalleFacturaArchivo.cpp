#include <iostream>
#include "DetalleFacturaArchivo.h"

bool DetalleFacturaArchivo::guardar(DetalleFactura registro){
    bool result;
    FILE *pFile;

    pFile = fopen("detallefacturas.dat", "ab");

    if(pFile == nullptr){

        return false;
    }

    result = fwrite(&registro, sizeof (DetalleFactura), 1, pFile);

    fclose(pFile);

    return result;
}

bool DetalleFacturaArchivo::guardar(int index, DetalleFactura registro){
    bool result;
    FILE *pFile;

    pFile = fopen("detallefacturas.dat", "rb+");

    if(pFile == nullptr){

      return false;
    }

    fseek(pFile, sizeof(DetalleFactura) * index, SEEK_SET);

    result = fwrite(&registro, sizeof (DetalleFactura), 1, pFile);

    fclose(pFile);

    return result;
}

DetalleFactura DetalleFacturaArchivo::leer(int index){
    bool result;
    DetalleFactura reg;
    FILE *pFile;

    pFile = fopen("detallefacturas.dat", "rb");

    if(pFile == nullptr){
      return reg;
    }

    fseek(pFile, index * sizeof (DetalleFactura), SEEK_SET);

    fread(&reg, sizeof(DetalleFactura), 1, pFile);

    fclose(pFile);

    return reg;
}

void DetalleFacturaArchivo::leerTodos(DetalleFactura registros[], int cantidad){
    bool result;
    FILE *pFile;

    pFile = fopen("detallefacturas.dat", "rb");

    if(pFile == nullptr){
      return;
    }

    fread(registros, sizeof(DetalleFactura), cantidad, pFile);

    fclose(pFile);
}

int DetalleFacturaArchivo::buscarByID(int id){
    DetalleFactura reg;
    int pos = 0;
    FILE * pFile;

    pFile = fopen("detallefacturas.dat", "rb");
    if(pFile == nullptr){
        return -1;
    }

    while(fread(&reg, sizeof(DetalleFactura), 1, pFile)){
        if(reg.getID() == id){
            fclose(pFile);
            return pos;
        }
        pos++;
    }

    fclose(pFile);
    return -1;
}

int DetalleFacturaArchivo::getCantidadRegistros(){
    FILE *pFile;
    int tam;

    pFile = fopen("detallefacturas.dat", "rb");

    if(pFile == nullptr){
      return 0;
    }

    fseek(pFile, 0, SEEK_END);

    tam = ftell(pFile) / sizeof (DetalleFactura);

    fclose(pFile);

    return tam;
}

int DetalleFacturaArchivo::getNuevoID(){
    int cantidad = getCantidadRegistros();

    if(cantidad>0){
        return leer(cantidad-1).getID()+1;
    }
    else{
        return 1;
    }
}
