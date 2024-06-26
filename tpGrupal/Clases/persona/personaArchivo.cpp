#include <iostream>
#include "PersonaArchivo.h"

bool PersonaArchivo::guardar(Persona registro){
    bool result;
    FILE *pFile;

    pFile = fopen("personas.dat", "ab");

    if(pFile == nullptr){
        return false;
    }

    result = fwrite(&registro, sizeof(Persona), 1, pFile);

    fclose(pFile);

    return result;
}

bool PersonaArchivo::guardar(int index, Persona registro){
    bool result;
    FILE *pFile;

    pFile = fopen("personas.dat", "rb+");

    if(pFile == nullptr){
      return false;
    }

    fseek(pFile, sizeof(Persona) * index, SEEK_SET);

    result = fwrite(&registro, sizeof(Persona), 1, pFile);

    fclose(pFile);

    return result;
}

Persona PersonaArchivo::leer(int index){
    Persona reg;
    FILE *pFile;

    pFile = fopen("personas.dat", "rb");

    if(pFile == nullptr){
      return reg; // Return an empty or default-initialized Persona object
    }

    fseek(pFile, index * sizeof(Persona), SEEK_SET);

    fread(&reg, sizeof(Persona), 1, pFile);

    fclose(pFile);

    return reg;
}

void PersonaArchivo::leerTodos(Persona registros[], int cantidad){
    FILE *pFile;

    pFile = fopen("personas.dat", "rb");

    if(pFile == nullptr){
      return;
    }

    fread(registros, sizeof(Persona), cantidad, pFile);

    fclose(pFile);
}

int PersonaArchivo::buscarByDNI(const char* dni){
    Persona reg;
    int pos = 0;
    FILE *pFile;

    pFile = fopen("personas.dat", "rb");
    if(pFile == nullptr){
        return -1;
    }

    while(fread(&reg, sizeof(Persona), 1, pFile)){
        if(strcmp(reg.getDNI(), dni) == 0){
            fclose(pFile);
            return pos;
        }
        pos++;
    }

    fclose(pFile);
    return -1;
}

int PersonaArchivo::getCantidadRegistros(){
    FILE *pFile;
    int tam;

    pFile = fopen("personas.dat", "rb");

    if(pFile == nullptr){
      return 0;
    }

    fseek(pFile, 0, SEEK_END);

    tam = ftell(pFile) / sizeof(Persona);

    fclose(pFile);

    return tam;
}

int PersonaArchivo::getNuevoID(){
    int cantidad = getCantidadRegistros();

    if(cantidad > 0){
        Persona ultimoRegistro = leer(cantidad - 1);
        // Assuming Persona has a method getID() to get its ID
        return ultimoRegistro.getID() + 1;
    }
    else{
        return 1;
    }
}