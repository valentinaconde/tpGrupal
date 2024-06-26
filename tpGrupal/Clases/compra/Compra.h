#pragma once

class Compra{
    private:
        int _numerocompra;
        Fecha _fecha;
        int _dniproveedor;
        float _total;
        int _metodopago;
        bool _estado;
    public:
        void Mostrar();
        Compra();
        Compra(int numerocompra,Fecha fecha,int dni,float total,int metodopago);
        //GETS
        int getNumeroCompra();
        Fecha getFecha();
        int getDNI();
        float getTotal();
        int getMetodoPago();
        bool getEstado();
        //SETS
        void setNumeroCompra(int numerocompra);
        void setFecha(Fecha fecha);
        void setDNI(int dni);
        void setTotal(float total);
        void setMetodoPago(int metodopago);
        void setEstado(bool estado);
};
