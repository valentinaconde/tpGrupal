#pragma once
#include "Factura.h"
#include "FacturaArchivo.h"

class FacturasManager{
    private:
        void agregarFactura();
        void listarFacturas();
        Factura crearFactura();
        void volverCargarFactura(Factura &registro);
        void mostrarFactura(Factura registro);
        void modificarFactura();
        void eliminarFactura();
        FacturaArchivo _facturasArchivo;
    public:
        void Menu();
};
