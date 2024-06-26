#pragma once
#include <string>


class Factura{
    private:
        int _numerofactura;
        Fecha _fecha;
        int _dnicliente;
        int _metodopago;
        float _total;
        bool _envio;
    public:
        void Mostrar();
        Factura();
        Factura(int numero, Fecha fecha, int dni, int pago, int total, bool envio);
        //GETS
        int getNumeroFactura();
        Fecha getFecha();
        int getDNI();
        int getPago();
        float getTotal();
        bool getEnvio();
        //SETS
        void setNumeroFactura(int numero);
        void setFecha(Fecha fecha);
        void setDNI(int dni);
        void setPago(int pago);
        void setTotal(float total);
        void setEnvio(bool envio);
};
