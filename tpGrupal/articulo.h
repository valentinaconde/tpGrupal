#pragma once

class Articulo
{
private:
    int _codigo;
    char _descripcion[30];
    float _precio;
    int _stock;
    int _categoria; // se tienen 5 categorias: alimento (1), juguetes(2), ropa(3), higiene(4), accesorios(5)
    bool _estado;

public:
    void Mostrar();
    Articulo();
    Articulo(int codigo, const char *descripcion, float precio, int stock, int categoria);
  //GETS
    int getCodigo();
    const char *getDescripcion();
    float getPrecio();
    int getStock();
    int getCategoria();
    int getEstado();
    //SETS
    void setCodigo(int codigo);
    void setDescripcion(const char *descripcion);
    void setPrecio(float precio);
    void setStock(int stock);
    void setCategoria(int categoria);
    void setEstado(bool estado);
};
