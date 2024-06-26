#pragma once

class MetodoPago {
    private:
        int _idMetodo;
        char _nombre[30];
        bool _estado;
    public:
        MetodoPago();
        MetodoPago(int idMetodo, const char nombre[30], bool estado);
        //GETS
        int getIdMetodo();
        const char* getNombre();
        bool getEstado();
        //SETS
        void setIdMetodo(int idMetodo);
        void setNombre(const char nombre[30]);
        void setEstado(bool estado);
};