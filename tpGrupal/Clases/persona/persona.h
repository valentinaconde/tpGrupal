#pragma once
#include <string>

class Persona {
    private:
        int _dni;
        char _nombre[30];
        char _apellido[30];
        int _telefono;
        char _direccion[30];
        char _email[30];
        bool _estado;
    public:
        void Mostrar();
        Persona();
        Persona(int dni, const char nombre[30], const char apellido[30], int telefono, const char direccion[30], const char email[30], bool estado);
        //GETS
        int getDni();
        const char* getNombre();
        const char* getApellido();
        int getTelefono();
        const char* getDireccion();
        const char* getEmail();
        bool getEstado();
        //SETS
        void setDni(int dni);
        void setNombre(const char nombre[30]);
        void setApellido(const char apellido[30]);
        void setTelefono(int telefono);
        void setDireccion(const char direccion[30]);
        void setEmail(const char email[30]);
        void setEstado(bool estado);
};