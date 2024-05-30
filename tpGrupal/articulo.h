
#ifndef ARTICULO_H
#define ARTICULO_H

void cargarCadena(char *palabra, int tamano)
{

  int i = 0;
  fflush(stdin);
  for (i = 0; i < tamano; i++)
  {
    palabra[i] = cin.get();
    if (palabra[i] == '\n')
    {
      break;
    }
  }
  palabra[i] = '\0';
  fflush(stdin);
}

class Articulo
{
private:
  int cod;
  char desc[30];
  float pu;
  int stock;
  int categoria; // se tienen 5 categorias: alimento (1), juguetes(2), ropa(3), higiene(4), accesorios(5)
  bool estado;

public:
  void grabarEnDisco(int);
  bool leerDeDisco(int);
  void Cargar();
  void Mostrar();

  int getCod() { return cod; }
  char *getDesc() { return desc; }
  float getPu() { return pu; }
  int getStock() { return stock; }
  int getCategoria() { return categoria; }
  int getEstado() { return estado; }

  void setCod(int c) { cod = c; }
  void setDesc(char *d) { strcpy(desc, d); }
  void setPu(float p)
  {
    if (p > 0)
      pu = p;
  }
  void setStock(int s) { stock = s; }
  void setCategoria(int c) { categoria = c; }
  void setEstado(bool s) { estado = s; }
};

int ultimoCodigoArticuloAgregado()
{
    Articulo reg;
    int pos = 0;
    while(reg.leerDeDisco(pos++)) {} 
    cout << "ULTIMO CODIGO DE ARTICULO AGREGADO: " << reg.getCod() << endl;
    return reg.getCod() + 1;
}


void Articulo::Cargar()
{
  cod = ultimoCodigoArticuloAgregado();
  cout << "CATEGORIA: ";
  cin >> categoria;
  cout << "DESCRIPCION: ";
  cargarCadena(desc, 30);
  cout << "PU: ";
  cin >> pu;
  cout << "STOCK: ";
  cin >> stock;
  estado = true;
}

void Articulo::Mostrar()
{
  if (estado)
  {
    cout << "CODIGO: ";
    cout << cod << endl;
    cout << "CATEGORIA: ";
    cout << categoria << endl;
    cout << "DESCRIPCION: ";
    cout << desc << endl;
    cout << "PU: ";
    cout << pu << endl;
    cout << "STOCK: ";
    cout << stock << endl;
  }
}

void Articulo::grabarEnDisco(int pos = -1)
{

  FILE *p;
  if (pos == -1)
  {
    p = fopen("articulo.dat", "ab");
    if (p == NULL)
    {
      return;
    }
  }
  else
  {
    p = fopen("articulo.dat", "rb+");
    if (p == NULL)
    {
      cout << "ERROR DE ARCHIVO" << endl;
      return;
    }
    fseek(p, sizeof *this * pos, 0);
  }
  fwrite(this, sizeof *this, 1, p);
  fclose(p);
}

bool Articulo::leerDeDisco(int pos)
{
  FILE *p;
  p = fopen("articulo.dat", "rb");
  if (p == NULL)
    return false;
  fseek(p, sizeof(Articulo) * pos, 0);
  bool x = fread(this, sizeof *this, 1, p);
  fclose(p);
  return x;
}

int buscarCodigoArticulo(int cod)
{
  Articulo reg;
  int pos = 0;

  while (reg.leerDeDisco(pos))
  {
    if (cod == reg.getCod() && reg.getEstado())
    {
      return pos;
    }
    pos++;
  }
  return -1;
}

void altaArticulo()
{
  Articulo obj;
  obj.Cargar();
  int pos = buscarCodigoArticulo(obj.getCod());
  if (pos == -1)
  {
    obj.grabarEnDisco();
    cout << "REGISTRO AGREGADO" << endl;
  }
  else
  {
    cout << "YA EXISTE EL CODIGO DE ARTICULOS" << endl;
    cout << "NO SE GRABO EL REGISTRO" << endl;
  }
}

void grabarRegistro(Articulo reg)
{
  FILE *p;
  p = fopen("articulo.dat", "ab");
  if (p == NULL)
  {
    cout << "ERROR DE ARCHIVO" << endl;
    return;
  }
  fwrite(&reg, sizeof reg, 1, p);
  fclose(p);
}

void bajaArticulo()
{

  int cod;
  cout << "INGRESE EL CODIGO DEL OBJETO A ELIMINAR " << endl;
  cin >> cod;
  int pos = buscarCodigoArticulo(cod);
  if (pos == -1)
  {
    cout << "NO EXISTE EL REGISTRO" << endl;
    return;
  }

  Articulo obj;
  obj.leerDeDisco(pos);
  if (!obj.getEstado())
  {
    cout << "NO EXISTE EL REGISTRO" << endl;
    return;
  }

  obj.setEstado(false);
  cout << "pos " << pos << endl;
  obj.grabarEnDisco(pos);
}

void listadoArticulos()
{
  Articulo reg;
  int pos = 0;
  bool hayArticulos = false;
  while (reg.leerDeDisco(pos++) == true)
  {
    if(reg.getEstado()){
      reg.Mostrar();
      cout << endl;
      hayArticulos = true;
    }
  }
  if (!hayArticulos)
  {
    cout << "NO HAY ARTICULOS" << endl;
  }
}

void listadoArticulosPorCategoria()
{
  Articulo reg;
  int pos = 0;
  const char *categorias[5] = {"Alimento", "Juguetes", "Ropa", "Higiene", "Accesorios"};
  bool hayArticulos = false;

  for (int i = 0; i < 5; i++)
  {
    cout << "Categoria: " << categorias[i] << endl
         << endl;
    hayArticulos = false;
    pos = 0;
    while (reg.leerDeDisco(pos++) == true)
    {
      if (reg.getCategoria() == i + 1 && reg.getEstado())
      {
        hayArticulos = true;
        reg.Mostrar();
        cout << endl;
      }
    }

    if (!hayArticulos)
    {
      cout << "No hay articulos en esta categoria" << endl;
    }
    cout << "--------------------------------" << endl;
  }
}

void listadoArticulosPorPrecio()
{
  Articulo reg;
  int pos = 0;
  Articulo articulos[100];
  int cantArticulos = 0;

  while (reg.leerDeDisco(pos++) == true)
  {
    articulos[cantArticulos] = reg;
    cantArticulos++;
  }

  Articulo aux;
  for (int i = 0; i < cantArticulos; i++)
  {
    for (int j = 0; j < cantArticulos; j++)
    {
      if (articulos[i].getPu() < articulos[j].getPu())
      {
        aux = articulos[i];
        articulos[i] = articulos[j];
        articulos[j] = aux;
      }
    }
  }

  bool hayArticulos = false;
  for (int i = 0; i < cantArticulos; i++)
  {
    if (articulos[i].getEstado())
    {
      articulos[i].Mostrar();
      cout << endl;
      hayArticulos = true;
    }
  }

  if (!hayArticulos)
  {
    cout << "NO HAY ARTICULOS" << endl;
  }
}

void mostrarArticuloPorCodigo()
{
  int cod;
  cout << "Ingrese el codigo del articulo: ";
  cin >> cod;

  Articulo reg;
  int pos = buscarCodigoArticulo(cod);
  if (pos == -1)
  {
    cout << "No se encontro el articulo" << endl;
    return;
  }

  reg.leerDeDisco(pos);
  reg.Mostrar();
  return;
}

void mostrarArticuloPorDescripcion()
{
  char desc[30];
  cout << "Ingrese la descripcion del articulo: ";
  cargarCadena(desc, 30);

  Articulo reg;
  int pos = 0;
  bool encontrado = false;
  while (reg.leerDeDisco(pos++) == true)
  {
    if (strcmp(reg.getDesc(), desc) == 0 && reg.getEstado())
    {
      reg.Mostrar();
      encontrado = true;
    }
  }

  if (!encontrado)
  {
    cout << "No se encontro el articulo" << endl;
  }
  return;
}

void mostrarArticuloPorRangoPreciosYCategoria()
{
  float min, max;
  int categoria;
  cout << "Ingrese el precio minimo: ";
  cin >> min;
  cout << "Ingrese el precio maximo: ";
  cin >> max;
  cout << "Ingrese la categoria: ";
  cin >> categoria;

  Articulo reg;
  int pos = 0;
  bool encontrado = false;
  while (reg.leerDeDisco(pos++) == true)
  {
    if (reg.getPu() >= min && reg.getPu() <= max && reg.getCategoria() == categoria && reg.getEstado())
    {
      reg.Mostrar();
      encontrado = true;
    }
  }

  if (!encontrado)
  {
    cout << "No se encontraron articulos para ese rango de precios y categoria" << endl;
  }
  return;
}

void informeCategoriasMasVendidas()
{
  Articulo reg;
  int pos = 0;
  int cantidades[5] = {0, 0, 0, 0, 0};
  const char *categorias[5] = {"Alimento", "Juguetes", "Ropa", "Higiene", "Accesorios"};

  while (reg.leerDeDisco(pos++) == true)
  {
    if (reg.getEstado())
    {
      cantidades[reg.getCategoria() - 1]++;
    }
  }

  for (int i = 0; i < 5; i++)
  {
    cout << "Categoria " << categorias[i] << ": " << cantidades[i] << " articulos" << endl;
  }

  cout << "--------------------------------" << endl;
  return;
}

void modificarPrecioArticulos()
{
  float porcentaje;
  cout << "Ingrese el porcentaje de aumento: ";
  cin >> porcentaje;

  Articulo reg;
  int pos = 0;
  while (reg.leerDeDisco(pos++) == true)
  {
    reg.setPu(reg.getPu() * (1 + porcentaje / 100));
    reg.grabarEnDisco(pos - 1);
  }

  cout << "Precios modificados" << endl;
  return;
}

void modificarPrecioArticuloEnParticular()
{
  int cod;
  float nuevoPrecio;
  cout << "Ingrese el codigo del articulo: ";
  cin >> cod;
  cout << "Ingrese el nuevo precio: ";
  cin >> nuevoPrecio;

  Articulo reg;
  int pos = buscarCodigoArticulo(cod);
  if (pos == -1)
  {
    cout << "No se encontro el articulo" << endl;
    return;
  }

  reg.leerDeDisco(pos);
  reg.setPu(nuevoPrecio);
  reg.grabarEnDisco(pos);
  cout << "Precio modificado" << endl;
  return;
}

void modificarStockArticulo()
{
  int cod;
  int nuevoStock;
  cout << "Ingrese el codigo del articulo: ";
  cin >> cod;
  cout << "Ingrese el nuevo stock: ";
  cin >> nuevoStock;

  Articulo reg;
  int pos = buscarCodigoArticulo(cod);
  if (pos == -1)
  {
    cout << "No se encontro el articulo" << endl;
    return;
  }

  reg.leerDeDisco(pos);
  reg.setStock(nuevoStock);
  reg.grabarEnDisco(pos);
  cout << "Stock modificado" << endl;
  return;
}

#endif
