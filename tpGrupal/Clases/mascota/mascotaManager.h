#pragma once
#include "Mascota.h"
#include "MascotaArchivo.h"

class MascotaManager {
private:
    void agregarMascota();
    void listarMascotas();
    Mascota crearMascota();
    void volverCargarMascota(Mascota &registro);
    void mostrarMascota(Mascota registro);
    void modificarMascota();
    void eliminarMascota();
    MascotaArchivo _mascotaArchivo;
public:
    void Menu();
};