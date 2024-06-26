#pragma once

class DetalleFactura{
    private:
        int _id;
        int _numerofactura;
        int _codigoarticulo;
        int _cantidad;
        bool _estado;
    public:
        void Mostrar();
        DetalleFactura();
        DetalleFactura(int id, int factura, int codigoarticulo, int cantidad);
        //GETS
        int getID();
        int getNumeroFactura();
        int getCodigoArticulo();
        int getCantidad();
        int getEstado();
        //SETS
        void setID(int id);
        void setNumeroFactura(int factura);
        void setCodigoArticulo(int codigo);
        void setCantidad(int cantidad);
        void setEstado(bool estado);
};
