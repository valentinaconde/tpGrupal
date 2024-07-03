#pragma once
#include "Persona.h"
#include "PersonaArchivo.h"

class PersonasManager {
    private:
        void agregarPersona();
        void eliminarPersona();
        void modificarPersona();
        void listarPersonas();
        Persona crearPersona();
        void volverCargarPersona(Persona &registro);
        void mostrarPersona(Persona registro);

        PersonaArchivo _personasarchivo;
    public:
        void Menu();
};
