#pragma once
#include "FormularioAdopcion.h"
#include "FormularioAdopcionArchivo.h"

class FormularioAdopcionManager {
private:
    void agregarFormulario();
    void listarFormularios();
    FormularioAdopcion crearFormulario();
    void volverCargarFormulario(FormularioAdopcion &registro);
    void mostrarFormulario(FormularioAdopcion registro);
    void modificarFormulario();
    void eliminarFormulario();
    FormularioAdopcionArchivo _formulariosAdopcionArchivo;
public:
    void Menu();
};