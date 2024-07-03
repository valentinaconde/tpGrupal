
#include <iostream>
#include <cstring>
#include "backup.h"

#include "Cliente.h"
#include "Articulo.h"
#include "Categoria.h"
#include "FormularioAdopcion.h"
#include "RegistroAdopcion.h"
#include "Mascota.h"
#include "Persona.h"


using namespace std;


void cargarCadena(char *pal, int tam);



void Backup::backupClientes(){
    FILE *archivoClientes;
    FILE *backupClientes;
    Cliente cliente;
    archivoClientes = fopen("clientes.dat", "rb");
    backupClientes = fopen("backup/backupClientes.dat", "wb");
    if(archivoClientes == nullptr || backupClientes == nullptr){
        cout << "ERROR AL ABRIR LOS ARCHIVOS" << endl;
        return;
    }
    while(fread(&cliente, sizeof(Cliente), 1, archivoClientes)){
        fwrite(&cliente, sizeof(Cliente), 1, backupClientes);
    }
    fclose(archivoClientes);
    fclose(backupClientes);
    cout << "BACKUP REALIZADO CON EXITO!" << endl;
}   

void Backup::backupArticulos(){
    FILE *archivoArticulos;
    FILE *backupArticulos;
    Articulo articulo;
    archivoArticulos = fopen("articulos.dat", "rb");
    backupArticulos = fopen("backup/backupArticulos.dat", "wb");
    if(archivoArticulos == nullptr || backupArticulos == nullptr){
        cout << "ERROR AL ABRIR LOS ARCHIVOS" << endl;
        return;
    }
    while(fread(&articulo, sizeof(Articulo), 1, archivoArticulos)){
        fwrite(&articulo, sizeof(Articulo), 1, backupArticulos);
    }
    fclose(archivoArticulos);
    fclose(backupArticulos);
    cout << "BACKUP REALIZADO CON EXITO!" << endl;
}   


void Backup::backupCategorias(){
    FILE *archivoCategorias;
    FILE *backupCategorias;
    Categoria categoria;
    archivoCategorias = fopen("categorias.dat", "rb");
    backupCategorias = fopen("backup/backupCategorias.dat", "wb");
    if(archivoCategorias == nullptr || backupCategorias == nullptr){
        cout << "ERROR AL ABRIR LOS ARCHIVOS" << endl;
        return;
    }
    while(fread(&categoria, sizeof(Categoria), 1, archivoCategorias)){
        fwrite(&categoria, sizeof(Categoria), 1, backupCategorias);
    }
    fclose(archivoCategorias);
    fclose(backupCategorias);
    cout << "BACKUP REALIZADO CON EXITO!" << endl;
}   

void Backup::backupFormulariosAdopcion(){
    FILE *archivoFormulariosAdopcion;
    FILE *backupFormulariosAdopcion;
    FormularioAdopcion formularioAdopcion;
    archivoFormulariosAdopcion = fopen("formulariosAdopcion.dat", "rb");
    backupFormulariosAdopcion = fopen("backup/backupFormulariosAdopcion.dat", "wb");
    if(archivoFormulariosAdopcion == nullptr || backupFormulariosAdopcion == nullptr){
        cout << "ERROR AL ABRIR LOS ARCHIVOS" << endl;
        return;
    }
    while(fread(&formularioAdopcion, sizeof(FormularioAdopcion), 1, archivoFormulariosAdopcion)){
        fwrite(&formularioAdopcion, sizeof(FormularioAdopcion), 1, backupFormulariosAdopcion);
    }
    fclose(archivoFormulariosAdopcion);
    fclose(backupFormulariosAdopcion);
    cout << "BACKUP REALIZADO CON EXITO!" << endl;
}   

void Backup::backupRegistrosAdopcion(){
    FILE *archivoRegistrosAdopcion;
    FILE *backupRegistrosAdopcion;
    RegistroAdopcion registroAdopcion;
    archivoRegistrosAdopcion = fopen("registrosAdopcion.dat", "rb");
    backupRegistrosAdopcion = fopen("backup/backupRegistrosAdopcion.dat", "wb");
    if(archivoRegistrosAdopcion == nullptr || backupRegistrosAdopcion == nullptr){
        cout << "ERROR AL ABRIR LOS ARCHIVOS" << endl;
        return;
    }
    while(fread(&registroAdopcion, sizeof(RegistroAdopcion), 1, archivoRegistrosAdopcion)){
        fwrite(&registroAdopcion, sizeof(RegistroAdopcion), 1, backupRegistrosAdopcion);
    }
    fclose(archivoRegistrosAdopcion);
    fclose(backupRegistrosAdopcion);
    cout << "BACKUP REALIZADO CON EXITO!" << endl;
}   

void Backup::backupMascotas(){
    FILE *archivoMascotas;
    FILE *backupMascotas;
    Mascota mascota;
    archivoMascotas = fopen("mascotas.dat", "rb");
    backupMascotas = fopen("backup/backupMascotas.dat", "wb");
    if(archivoMascotas == nullptr || backupMascotas == nullptr){
        cout << "ERROR AL ABRIR LOS ARCHIVOS" << endl;
        return;
    }
    while(fread(&mascota, sizeof(Mascota), 1, archivoMascotas)){
        fwrite(&mascota, sizeof(Mascota), 1, backupMascotas);
    }
    fclose(archivoMascotas);
    fclose(backupMascotas);
    cout << "BACKUP REALIZADO CON EXITO!" << endl;
}

void Backup::backupPersonas(){
    FILE *archivoPersonas;
    FILE *backupPersonas;
    Persona persona;
    archivoPersonas = fopen("personas.dat", "rb");
    backupPersonas = fopen("backup/backupPersonas.dat", "wb");
    if(archivoPersonas == nullptr || backupPersonas == nullptr){
        cout << "ERROR AL ABRIR LOS ARCHIVOS" << endl;
        return;
    }
    while(fread(&persona, sizeof(Persona), 1, archivoPersonas)){
        fwrite(&persona, sizeof(Persona), 1, backupPersonas);
    }
    fclose(archivoPersonas);
    fclose(backupPersonas);
    cout << "BACKUP REALIZADO CON EXITO!" << endl;
}


void restoreClientes(){
    FILE *archivoClientes;
    FILE *backupClientes;
    Cliente cliente;
    archivoClientes = fopen("clientes.dat", "wb");
    backupClientes = fopen("backup/backupClientes.dat", "rb");
    if(archivoClientes == nullptr || backupClientes == nullptr){
        cout << "ERROR AL ABRIR LOS ARCHIVOS" << endl;
        return;
    }
    while(fread(&cliente, sizeof(Cliente), 1, backupClientes)){
        fwrite(&cliente, sizeof(Cliente), 1, archivoClientes);
    }
    fclose(archivoClientes);
    fclose(backupClientes);
    cout << "RESTORE REALIZADO CON EXITO!" << endl;
}

void restoreArticulos(){
    FILE *archivoArticulos;
    FILE *backupArticulos;
    Articulo articulo;
    archivoArticulos = fopen("articulos.dat", "wb");
    backupArticulos = fopen("backup/backupArticulos.dat", "rb");
    if(archivoArticulos == nullptr || backupArticulos == nullptr){
        cout << "ERROR AL ABRIR LOS ARCHIVOS" << endl;
        return;
    }
    while(fread(&articulo, sizeof(Articulo), 1, backupArticulos)){
        fwrite(&articulo, sizeof(Articulo), 1, archivoArticulos);
    }
    fclose(archivoArticulos);
    fclose(backupArticulos);
    cout << "RESTORE REALIZADO CON EXITO!" << endl;
}

void restoreCategorias(){
    FILE *archivoCategorias;
    FILE *backupCategorias;
    Categoria categoria;
    archivoCategorias = fopen("categorias.dat", "wb");
    backupCategorias = fopen("backup/backupCategorias.dat", "rb");
    if(archivoCategorias == nullptr || backupCategorias == nullptr){
        cout << "ERROR AL ABRIR LOS ARCHIVOS" << endl;
        return;
    }
    while(fread(&categoria, sizeof(Categoria), 1, backupCategorias)){
        fwrite(&categoria, sizeof(Categoria), 1, archivoCategorias);
    }
    fclose(archivoCategorias);
    fclose(backupCategorias);
    cout << "RESTORE REALIZADO CON EXITO!" << endl;
}

void restoreFormulariosAdopcion(){
    FILE *archivoFormulariosAdopcion;
    FILE *backupFormulariosAdopcion;
    FormularioAdopcion formularioAdopcion;
    archivoFormulariosAdopcion = fopen("formulariosAdopcion.dat", "wb");
    backupFormulariosAdopcion = fopen("backup/backupFormulariosAdopcion.dat", "rb");
    if(archivoFormulariosAdopcion == nullptr || backupFormulariosAdopcion == nullptr){
        cout << "ERROR AL ABRIR LOS ARCHIVOS" << endl;
        return;
    }
    while(fread(&formularioAdopcion, sizeof(FormularioAdopcion), 1, backupFormulariosAdopcion)){
        fwrite(&formularioAdopcion, sizeof(FormularioAdopcion), 1, archivoFormulariosAdopcion);
    }
    fclose(archivoFormulariosAdopcion);
    fclose(backupFormulariosAdopcion);
    cout << "RESTORE REALIZADO CON EXITO!" << endl;
}

void restoreRegistrosAdopcion(){
    FILE *archivoRegistrosAdopcion;
    FILE *backupRegistrosAdopcion;
    RegistroAdopcion registroAdopcion;
    archivoRegistrosAdopcion = fopen("registrosAdopcion.dat", "wb");
    backupRegistrosAdopcion = fopen("backup/backupRegistrosAdopcion.dat", "rb");
    if(archivoRegistrosAdopcion == nullptr || backupRegistrosAdopcion == nullptr){
        cout << "ERROR AL ABRIR LOS ARCHIVOS" << endl;
        return;
    }
    while(fread(&registroAdopcion, sizeof(RegistroAdopcion), 1, backupRegistrosAdopcion)){
        fwrite(&registroAdopcion, sizeof(RegistroAdopcion), 1, archivoRegistrosAdopcion);
    }
    fclose(archivoRegistrosAdopcion);
    fclose(backupRegistrosAdopcion);
    cout << "RESTORE REALIZADO CON EXITO!" << endl;
}

void restoreMascotas(){
    FILE *archivoMascotas;
    FILE *backupMascotas;
    Mascota mascota;
    archivoMascotas = fopen("mascotas.dat", "wb");
    backupMascotas = fopen("backup/backupMascotas.dat", "rb");
    if(archivoMascotas == nullptr || backupMascotas == nullptr){
        cout << "ERROR AL ABRIR LOS ARCHIVOS" << endl;
        return;
    }
    while(fread(&mascota, sizeof(Mascota), 1, backupMascotas)){
        fwrite(&mascota, sizeof(Mascota), 1, archivoMascotas);
    }
    fclose(archivoMascotas);
    fclose(backupMascotas);
    cout << "RESTORE REALIZADO CON EXITO!" << endl;

}

void restorePersonas(){
    FILE *archivoPersonas;
    FILE *backupPersonas;
    Persona persona;
    archivoPersonas = fopen("personas.dat", "wb");
    backupPersonas = fopen("backup/backupPersonas.dat", "rb");
    if(archivoPersonas == nullptr || backupPersonas == nullptr){
        cout << "ERROR AL ABRIR LOS ARCHIVOS" << endl;
        return;
    }
    while(fread(&persona, sizeof(Persona), 1, backupPersonas)){
        fwrite(&persona, sizeof(Persona), 1, archivoPersonas);
    }
    fclose(archivoPersonas);
    fclose(backupPersonas);
    cout << "RESTORE REALIZADO CON EXITO!" << endl;

}

void Backup::restore(){
    int opcion;
    do{
        system("cls");
        cout << "1. RESTAURAR BACKUP DE CLIENTES" << endl;
        cout << "2. RESTAURAR BACKUP DE ARTICULOS" << endl;
        cout << "3. RESTAURAR BACKUP DE CATEGORIAS" << endl;
        cout << "4. RESTAURAR BACKUP DE FORMULARIOS DE ADOPCION" << endl;
        cout << "5. RESTAURAR BACKUP DE REGISTROS DE ADOPCION" << endl;
        cout << "6. RESTAURAR BACKUP DE MASCOTAS" << endl;
        cout << "7. RESTAURAR BACKUP DE PERSONAS" << endl;
        cout << "0. SALIR" << endl;
        cout << "INGRESE UNA OPCION: ";
        
        cin >> opcion;
        switch(opcion){
            case 1:
                restoreClientes();
                break;
            case 2:
                restoreArticulos();
                break;
            case 3:
                restoreCategorias();
                break;
            case 4:
                restoreFormulariosAdopcion();
                break;
            case 5:
                restoreRegistrosAdopcion();
                break;
            case 6:
                restoreMascotas();
                break;
            case 7:
                restorePersonas();
                break;
            case 0:
                cout << "SALIENDO..." << endl;
                break;
            default:
                cout << "OPCION INVALIDA" << endl;
                break;
        }
    }while(opcion != 0);
}

void Backup::backup(){
    int opcion;
    do{
        system("cls");
        cout << "REALIZAR BACKUP DE CLIENTES" << endl;
        cout << "REALIZAR BACKUP DE ARTICULOS" << endl;
        cout << "REALIZAR BACKUP DE CATEGORIAS" << endl;
        cout << "REALIZAR BACKUP DE FORMULARIOS DE ADOPCION" << endl;
        cout << "REALIZAR BACKUP DE REGISTROS DE ADOPCION" << endl;
        cout << "REALIZAR BACKUP DE MASCOTAS" << endl;
        cout << "REALIZAR BACKUP DE PERSONAS" << endl;
        cout << "0. SALIR" << endl;
        cout << "INGRESE UNA OPCION: ";
        cin >> opcion;
        switch(opcion){
            case 1:
                system("cls");
                backupClientes();
                system("pause");
                break;
            case 2:
                system("cls");
                backupArticulos();
                system("pause");
                break;
            case 3:
                system("cls");
                backupCategorias();
                system("pause");
                break;
            case 4:
                system("cls");
                backupFormulariosAdopcion();
                system("pause");
                break;
            case 5:
                system("cls");
                backupRegistrosAdopcion();
                system("pause");
                break;
            case 6:
                system("cls");
                backupMascotas();
                system("pause");
                break;
            case 7:
                system("cls");
                backupPersonas();
                system("pause");
                break;
            case 0:
                system("cls");
                cout << "SALIENDO..." << endl;
                system("pause");
                break;
            default:
                cout << "OPCION INVALIDA" << endl;
                break;
        }
    }while(opcion != 0);
}


void Backup::Menu(){
    int opcion;
    do{
        system("cls");
        cout << "1. REALIZAR BACKUP" << endl;
        cout << "2. RESTAURAR BACKUP" << endl;
        cout << "0. SALIR" << endl;
        cout << "INGRESE UNA OPCION: ";
        cin >> opcion;
        switch(opcion){
            case 1:
                backup();
                break;
            case 2:
                restore();
                break;
            case 0:
                cout << "SALIENDO..." << endl;
                break;
            default:
                cout << "OPCION INVALIDA" << endl;
                break;
        }
    }while(opcion != 0);
}


