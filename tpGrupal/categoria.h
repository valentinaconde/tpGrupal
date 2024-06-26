#pragma once
#include <string>

class Categoria {
    private:
        int _idCategoria;
        char _nombre[30];
        bool _estado;
    public:
        void Mostrar();
        Categoria();
        Categoria(int idCategoria, const char nombre[30], bool estado);
        //GETS
        int getIdCategoria();
        const char* getNombre();
        bool getEstado();
        //SETS
        void setIdCategoria(int idCategoria);
        void setNombre(const char nombre[30]);
        void setEstado(bool estado);
};