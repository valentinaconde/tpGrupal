#pragma once
#include "RegistroAdopcion.h"
#include "RegistroAdopcionArchivo.h"

class RegistroAdopcionManager {
private:
    RegistroAdopcionArchivo _registroAdopcionArchivo;
    void agregarRegistroAdopcion();
    void listarRegistrosAdopcion();
    RegistroAdopcion crearRegistroAdopcion();
    void volverCargarRegistroAdopcion(RegistroAdopcion &registro);
    void mostrarRegistroAdopcion(RegistroAdopcion registro);
    void modificarRegistroAdopcion();
    void eliminarRegistroAdopcion();
    void buscarRegistroPorId();
    void buscarRegistroPorAdopcionId();
    void buscarRegistroPorMascotaId();

public:
    void Menu();
};
