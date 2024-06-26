#pragma once
#include "DetalleFactura.h"
#include "DetalleFacturaArchivo.h"

class DetalleFacturasManager{
    private:
        void agregarDetalleFactura();
        void listarDetallesFacturas();
        DetalleFactura crearDetalleFactura();
        void volverCargarDetalleFactura(DetalleFactura &registro);
        void mostrarDetalleFactura(DetalleFactura registro);
        void modificarDetalleFactura();
        void eliminarDetalleFactura();
        DetalleFacturaArchivo _detallefacturasArchivo;
    public:
        void Menu();
};
