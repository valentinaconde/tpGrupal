#include <iostream>
#include "ClienteArchivo.h"

bool ClienteArchivo::guardar(Cliente registro){
    bool result;
    FILE *pFile;

    pFile = fopen("clientes.dat", "ab");

    if(pFile == nullptr){
        return false;
    }

    result = fwrite(&registro, sizeof(Cliente), 1, pFile);

    fclose(pFile);

    return result;
}

bool ClienteArchivo::guardar(int index, Cliente registro){
    bool result;
    FILE *pFile;

    pFile = fopen("clientes.dat", "rb+");

    if(pFile == nullptr){
      return false;
    }

    fseek(pFile, sizeof(Cliente) * index, SEEK_SET);

    result = fwrite(&registro, sizeof(Cliente), 1, pFile);

    fclose(pFile);

    return result;
}

Cliente ClienteArchivo::leer(int index){
    Cliente reg;
    FILE *pFile;

    pFile = fopen("clientes.dat", "rb");

    if(pFile == nullptr){
      return reg;
    }

    fseek(pFile, index * sizeof(Cliente), SEEK_SET);

    fread(&reg, sizeof(Cliente), 1, pFile);

    fclose(pFile);

    return reg;
}

void ClienteArchivo::leerTodos(Cliente registros[], int cantidad){
    FILE *pFile;

    pFile = fopen("clientes.dat", "rb");

    if(pFile == nullptr){
      return;
    }

    fread(registros, sizeof(Cliente), cantidad, pFile);

    fclose(pFile);
}

int ClienteArchivo::buscarPorDni(int id){
    Cliente reg;
    int pos = 0;
    FILE *pFile;

    pFile = fopen("clientes.dat", "rb");
    if(pFile == nullptr){
        return -1;
    }

    while(fread(&reg, sizeof(Cliente), 1, pFile)){
        if(reg.getDni() == id && reg.getEstado()){
            fclose(pFile);
            return pos;
        }
        pos++;
    }

    fclose(pFile);
    return -1;
}

int ClienteArchivo::getCantidadRegistros(){
    FILE *pFile;
    int tam;

    pFile = fopen("clientes.dat", "rb");

    if(pFile == nullptr){
      return 0;
    }

    fseek(pFile, 0, SEEK_END);

    tam = ftell(pFile) / sizeof(Cliente);

    fclose(pFile);

    return tam;
}

int ClienteArchivo::getNuevoID(){
    int cantidad = getCantidadRegistros();

    if(cantidad > 0){
        return leer(cantidad - 1).getDni() + 1;
    }
    else{
        return 1;
    }
}
