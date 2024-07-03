#pragma once
#include "Mascota.h"
#include "MascotaArchivo.h"

class MascotasManager {
private:



public:
    MascotaArchivo _mascotasarchivo;
    void agregarMascota();
    Mascota crearMascota();
    void volverCargarMascota(Mascota &registro);
    void mostrarMascota(Mascota registro);
    void modificarMascota();
    void eliminarMascota();
    void listarMascotas();
    void listadoMascotasOrdenadasPorEspecie();
    void listadoMascotasOrdenadasPorRaza();
    void listadoMascotasPorEspecie();
    void listadoMascotasPorRaza();
    void buscarMascotaPorId();
    void Menu();
};
