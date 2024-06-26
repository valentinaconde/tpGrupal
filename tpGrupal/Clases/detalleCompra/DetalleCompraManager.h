#pragma once
#include "DetalleCompra.h"
#include "DetalleCompraArchivo.h"

class DetalleComprasManager{
    private:
        void agregarDetalleCompra();
        void listarDetallesCompras();
        DetalleCompra crearDetalleCompra();
        void volverCargarDetalleCompra(DetalleCompra &registro);
        void mostrarDetalleCompra(DetalleCompra registro);
        void modificarDetalleCompra();
        void eliminarDetalleCompra();
        DetalleCompraArchivo _detallecomprasarchivo;
    public:
        void Menu();
};
