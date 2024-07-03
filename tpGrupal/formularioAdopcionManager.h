#pragma once
#include "FormularioAdopcion.h"
#include "FormularioAdopcionArchivo.h"

class FormularioAdopcionManager {
private:

public:
    void agregarFormulario();
    void listarFormularios();
    FormularioAdopcion crearFormulario();
    void volverCargarFormulario(FormularioAdopcion &registro);
    void mostrarFormulario(FormularioAdopcion registro);
    void modificarFormulario();
    void rechazarFormulario();
    void buscarPorIdAdopcion();
    void buscarPorIdMascota();
    void buscarPorApellidoCliente();
    FormularioAdopcionArchivo _formulariosAdopcionArchivo;
    void Menu();
};
