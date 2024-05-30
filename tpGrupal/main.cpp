#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

#include "fecha.h"
#include "articulo.h"
#include "venta.h"
#include "cliente.h"
#include "factura.h"
#include "mascota.h"
#include "registroAdopciones.h"
#include "formularioAdopcion.h"

int chequearContrasenia()
{
        char contrasenia[20];
        cout << endl;
        cout << "INGRESE CONTRASENA: ";
        cin >> contrasenia;
        if (strcmp(contrasenia, "1234") == 0)
        {
                cout << "CONTRASENA CORRECTA" << endl;
                return 1;
        }
        else
        {
                system("cls");
                cout << "CONTRASENA INCORRECTA" << endl;
                return 0;
        }
        system("pause");
}

void menuArticulos()
{
        int opc;
        while (true)
        {
                system("cls");
                cout << "------------MENU ARTICULOS------------" << endl;
                cout << "1. ALTA ARTICULOS" << endl;
                cout << "2. BAJA ARTICULOS" << endl;
                cout << "3. LISTADO ARTICULOS" << endl;
                cout << "4. LISTADO ORDENADO POR CATEGORIA" << endl;
                cout << "5. LISTADO ORDENADO POR PRECIO" << endl;
                cout << "6. BUSQUEDA POR CODIGO" << endl;
                cout << "7. BUSQUEDA POR DESCRIPCION" << endl;
                cout << "8. BUSQUEDA POR RANGO DE PRECIOS Y CATEGORIA" << endl;
                cout << "9. INFORME DE CATEGORIAS MAS VENDIDAS" << endl;
                cout << "10. MODIFICAR PRECIO GENERAL DE ARTICULOS" << endl;
                cout << "11. MODIFICAR PRECIO DE ARTICULO EN PARTICULAR" << endl;
                cout << "12. MODIFICAR STOCK DE ARTICULO" << endl;
                cout << "0. VOLVER ATRAS" << endl
                     << endl;
                cout << "SELECCIONE UNA OPCION: ";
                cin >> opc;
                switch (opc)
                {
                case 1:
                        system("cls");
                        altaArticulo();
                        system("pause");
                        break;
                case 2:
                        system("cls");
                        bajaArticulo();
                        system("pause");
                        break;
                case 3:
                        system("cls");
                        listadoArticulos();
                        system("pause");

                        break;
                case 4:
                        system("cls");
                        listadoArticulosPorCategoria();
                        system("pause");

                        break;
                case 5:
                        system("cls");
                        listadoArticulosPorPrecio();
                        system("pause");

                        break;
                case 6:
                        system("cls");
                        mostrarArticuloPorCodigo();
                        system("pause");

                        break;
                case 7:
                        system("cls");
                        mostrarArticuloPorDescripcion();
                        system("pause");

                        break;
                case 8:
                        system("cls");
                        mostrarArticuloPorRangoPreciosYCategoria();
                        system("pause");

                        break;
                case 9:
                        system("cls");
                        informeCategoriasMasVendidas();
                        system("pause");
                        break;
                case 10:
                        system("cls");
                        modificarPrecioArticulos();
                        system("pause");
                        break;
                case 11:
                        system("cls");
                        modificarPrecioArticuloEnParticular();
                        system("pause");
                        break;
                case 12:
                        system("cls");
                        modificarStockArticulo();
                        system("pause");
                        break;
                case 0:
                        return;
                        break;
                }
        }
}

void menuVentas()
{

        int opc;
        while (true)
        {
                system("cls");
                cout << "------------MENU VENTAS------------" << endl;
                cout << "1. NUEVA VENTA" << endl;
                cout << "2. DAR DE BAJA VENTA" << endl;
                cout << "3. LISTADO DE VENTAS" << endl;
                cout << "4. LISTADO DE VENTAS POR CLIENTE" << endl;
                cout << "5. LISTADO DE VENTAS POR FECHA" << endl;
                cout << "6. LISTADO DE VENTAS POR ARTICULO" << endl;
                cout << "7. LISTADO DE VENTAS POR METODO DE PAGO" << endl;
                cout << "8. BUSQUEDA DE VENTA POR DNI DE CLIENTE" << endl;
                cout << "9. BUSQUEDA DE VENTA POR FECHA" << endl;
                cout << "10. BUSQUEDA DE VENTA POR CODIGO" << endl;
                cout << "11. INFORME DE VENTAS POR MES" << endl;
                cout << "12. INFORME DE VENTAS POR ANIO" << endl;
                cout << "0. VOLVER ATRAS" << endl
                     << endl;
                cout << "SELECCIONE UNA OPCION: ";
                cin >> opc;
                switch (opc)
                {
                case 1:
                        system("cls");
                        altaVenta();
                        system("pause");

                        break;
                case 2:
                        system("cls");
                        bajaVenta();
                        system("pause");

                        break;
                case 3:
                        system("cls");
                        listadoVentas();
                        system("pause");

                        break;
                case 4:
                        system("cls");
                        listadoVentasPorCliente();
                        system("pause");

                        break;
                case 5:
                        system("cls");
                        listadoVentasPorFechaMayorAMenor();
                        system("pause");

                        break;
                case 6:
                        system("cls");
                        listadoVentasPorArticulo();
                        system("pause");

                        break;
                case 7:
                        system("cls");
                        listadoVentasPorMetodoPago();
                        system("pause");

                        break;
                case 8:
                        system("cls");
                        buscarVentaPorDniCliente();
                        system("pause");

                        break;
                case 9:
                        system("cls");
                        buscarVentaPorFecha();
                        system("pause");

                        break;
                case 10:
                        system("cls");
                        buscarVentaPorCodigo();
                        system("pause");

                        break;
                case 11:
                        system("cls");
                        informeVentasPorMes();
                        system("pause");

                        break;
                case 12:
                        system("cls");
                        informeVentasPorAnio();
                        system("pause");
                        break;

                case 0:
                        return;
                        break;
                }
        }
}

void menuClientes()
{
        while (true)
        {
                int opc;
                system("cls");
                cout << "------------MENU CLIENTES------------" << endl;
                cout << "1. ALTA CLIENTES" << endl;
                cout << "2. BAJA CLIENTES" << endl;
                cout << "3. LISTADO" << endl;
                cout << "4. LISTADO POR DNI" << endl;
                cout << "5. LISTADO POR APELLIDO" << endl;
                cout << "6. LISTADO POR FECHA DE REGISTRO" << endl;
                cout << "7. MODIFICAR CLIENTE" << endl;
                cout << "8. BUSQUEDA DE CLIENTE POR DNI" << endl;
                cout << "9. BUSQUEDA DE CLIENTE POR APELLIDO" << endl;
                cout << "10. LISTADO DE CLIENTES CON MAS DE 5 COMPRAS" << endl;
                cout << "0. VOLVER ATRAS" << endl
                     << endl;
                cout << "SELECCIONE UNA OPCION: ";
                cin >> opc;
                switch (opc)
                {
                case 1:
                        system("cls");
                        altaCliente();
                        system("pause");

                        break;
                case 2:
                        system("cls");
                        bajaCliente();
                        system("pause");

                        break;
                case 3:
                        system("cls");
                        listadoClientes();
                        system("pause");

                        break;
                case 4:
                        system("cls");
                        listadoClientesOrdenadosPorDni();
                        system("pause");

                        break;
                case 5:
                        system("cls");
                        listadoClientesOrdenadosPorApellido();
                        system("pause");

                        break;
                case 6:
                        system("cls");
                        listadoClientesOrdenadosPorFechaRegistro();
                        system("pause");

                        break;
                case 7:
                        system("cls");
                        modificarCliente();
                        system("pause");

                        break;
                case 8:
                        system("cls");
                        buscarClientePorDni();
                        system("pause");

                        break;
                case 9:
                        system("cls");
                        buscarClientePorApellido();
                        system("pause");

                        break;
                case 10:
                        system("cls");
                        listadoClientesConMasDe5Compras();
                        system("pause");

                        break;
                case 0:
                        return;
                        break;
                }
        }
}

void menuFacturas()
{

        while (true)
        {
                system("cls");
                int opc;
                cout << "------------MENU FACTURAS------------" << endl;
                cout << "1. ALTA FACTURAS" << endl;
                cout << "2. BAJA FACTURAS" << endl;
                cout << "3. LISTADO" << endl;
                cout << "4. LISTADO POR FECHA" << endl;
                cout << "5. BUSQUEDA DE FACTURA POR NUMERO" << endl;
                cout << "6. BUSQUEDA DE FACTURA POR CODIGO DE VENTA" << endl;
                cout << "7. INFORME TOTAL FACTURADO POR ANIO" << endl;
                cout << "8. INFORME TOTAL FACTURADO POR CLIENTE" << endl;
                cout << "0. VOLVER ATRAS" << endl
                     << endl;
                cout << "SELECCIONE UNA OPCION: ";
                cin >> opc;
                switch (opc)
                {
                case 1:
                        system("cls");
                        altaFactura();
                        system("pause");
                        break;
                case 2:
                        system("cls");
                        bajaFactura();
                        system("pause");
                        break;
                case 3:
                        system("cls");
                        listadoFacturas();
                        system("pause");
                        break;
                case 4:
                        system("cls");
                        listadoFacturasPorFecha();
                        system("pause");
                        break;
                case 5:
                        system("cls");
                        buscarFacturaPorNumero();
                        system("pause");
                        break;
                case 6:
                        system("cls");
                        buscarFacturaPorCodigoVenta();
                        system("pause");
                        break;
                case 7:
                        system("cls");
                        informeTotalFacturadoPorAnio();
                        system("pause");
                        break;
                case 8:
                        system("cls");
                        informeTotalFacturadoPorCliente();
                        system("pause");
                        break;
                case 0:
                        return;
                        break;
                }
        }
}

void menuAdopcionesEmpleado()
{
        while (true)
        {
                int opc;
                system("cls");
                cout << "------------MENU ADOPCIONES------------" << endl;
                cout << "1. DAR DE ALTA MASCOTA" << endl;
                cout << "2. DAR DE BAJA MASCOTA" << endl;
                cout << "3. VER LISTADO DE MASCOTAS DISPONIBLES" << endl;
                cout << "4. MODIFICAR MASCOTA" << endl;
                cout << "5. FORMULARIOS DE ADOPCION" << endl;
                cout << "6. APROBAR O RECHAZAR ADOPCION" << endl;
                cout << "7. LISTADO REGISTROS DE ADOPCION" << endl;
                cout << "0. VOLVER ATRAS" << endl
                     << endl;
                cout << "SELECCIONE UNA OPCION: ";
                cin >> opc;
                switch (opc)
                {
                case 1:
                        system("cls");
                        altaMascota();
                        system("pause");
                        break;
                case 2:
                        system("cls");
                        bajaMascota();
                        system("pause");
                        break;
                case 3:
                        system("cls");
                        listadoMascotas();
                        system("pause");
                        break;
                case 4:
                        system("cls");
                        modificarMascota();
                        system("pause");
                        break;
                case 5:
                        system("cls");
                        listadoFormulariosAdopcion();
                        system("pause");
                        break;
                case 6:
                        system("cls");
                        aprobarRechazarAdopcion();
                        system("pause");
                        break;
                case 7:
                        system("cls");
                        listadoRegistrosAdopcion();
                        system("pause");
                        break;

                case 0:
                        return;
                        break;
                }
        }
}

void menuAdopcionesCliente()
{
        int opc;
        system("cls");
        cout << "------------MENU ADOPCIONES------------" << endl;
        cout << "1. VER LISTADO DE MASCOTAS DISPONIBLES" << endl;
        cout << "2. FORMULARIO DE ADOPCION" << endl;
        cout << "0. MENU PRINCIPAL" << endl
             << endl;
        cout << "SELECCIONE UNA OPCION: ";
        cin >> opc;
        switch (opc)
        {
        case 1:
                system("cls");
                listadoMascotas();
                system("pause");
                break;
        case 2:
                system("cls");
                altaFormularioAdopcion();
                system("pause");
                break;
        case 0:
                return;
                break;
        }
}

void menuEmpleados()
{
        while (true)
        {
                system("cls");
                int opc;
                cout << "------------MENU EMPLEADOS------------" << endl;
                cout << "1. ARTICULOS" << endl;
                cout << "2. VENTAS" << endl;
                cout << "3. CLIENTES" << endl;
                cout << "4. FACTURAS" << endl;
                cout << "5. ADOPCIONES" << endl;
                cout << "0. MENU PRINCIPAL" << endl
                     << endl;
                cout << "SELECCIONE UNA OPCION: ";
                cin >> opc;
                switch (opc)
                {
                case 1:
                        system("cls");
                        menuArticulos();

                        break;
                case 2:
                        system("cls");
                        menuVentas();

                        break;
                case 3:
                        system("cls");
                        menuClientes();
                        break;
                case 4:
                        system("cls");
                        menuFacturas();
                        break;
                case 5:
                        system("cls");
                        menuAdopcionesEmpleado();
                        break;
                case 0:
                        return;
                        break;
                }
        }
}

int main()
{
        int opc;
        while (true)
        {
                system("cls");
                cout << "------------MENU PRINCIPAL------------" << endl;
                cout << "INGRESE LA OPCION DESEADA: " << endl;
                cout << "1. ADOPCIONES" << endl;
                cout << "2. EMPLEADOS" << endl;
                cout << "0. SALIR" << endl;
                cin >> opc;

                switch (opc)
                {
                case 0:
                        return false;
                        break;
                case 1:
                        system("cls");
                        menuAdopcionesCliente();
                        break;
                case 2:
                        char rta = 'S';
                        int contra = 0;
                        while ((rta == 'S' || rta == 's') && contra != 1)
                        {
                                contra = chequearContrasenia();
                                if (contra == 0)
                                {
                                        cout << "QUIERE PROBAR DEVUELTA? : (S/N)" << endl;
                                        cin >> rta;
                                        if (rta != 'S' && rta != 's')
                                                return 0;
                                        else
                                                system("cls");
                                }
                        }

                        system("cls");
                        menuEmpleados();
                        break;
                }
        }

        return 0;
}
