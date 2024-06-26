#pragma once

class DetalleCompra{
    private:
        int _id;
        int _numerocompra;
        int _codigoarticulo;
        int _cantidad;
        bool _estado;
    public:
        void Mostrar();
        DetalleCompra();
        DetalleCompra(int id, int numerocompra, int codigoarticulo, int cantidad);
        //GETS
        int getID();
        int getNumeroCompra();
        int getCodigoArticulo();
        int getCantidad();
        int getEstado();
        //SETS
        void setID(int id);
        void setNumeroCompra(int numerocompra);
        void setCodigoArticulo(int codigo);
        void setCantidad(int cantidad);
        void setEstado(bool estado);
};
