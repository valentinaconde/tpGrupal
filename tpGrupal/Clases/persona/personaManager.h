#pragma once
#include "Persona.h"
#include "PersonaArchivo.h"

class PersonasManager {
    private:
        void agregarPersona();
        void listarPersonas();
        Persona crearPersona();
        void volverCargarPersona(Persona &registro);
        void mostrarPersona(Persona registro);
        void modificarPersona();
        void eliminarPersona();
        PersonaArchivo _personasarchivo;
    public:
        void Menu();
};