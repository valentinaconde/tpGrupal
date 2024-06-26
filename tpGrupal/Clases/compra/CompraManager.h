#pragma once
#include "Compra.h"
#include "CompraArchivo.h"

class ComprasManager{
    private:
        void agregarCompra();
        void listarCompras();
        Compra crearCompra();
        void volverCargarCompra(Compra &registro);
        void mostrarCompra(Compra registro);
        void modificarCompra();
        void eliminarCompra();
        CompraArchivo _comprasarchivo;
    public:
        void Menu();
};
