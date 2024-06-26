#pragma once

class FormularioAdopcion {
    private:
        int _idAdopcion;
        Cliente _cliente;
        int _idMascota;
        bool _estado;
    public:
        FormularioAdopcion();
        FormularioAdopcion(int idAdopcion, Cliente cliente, int idMascota, bool estado);
        //GETS
        int getIdAdopcion();
        Cliente getCliente();
        int getIdMascota();
        bool getEstado();
        //SETS
        void setIdAdopcion(int idAdopcion);
        void setCliente(Cliente cliente);
        void setIdMascota(int idMascota);
        void setEstado(bool estado);
};