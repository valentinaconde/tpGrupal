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

bool menuArticulos()
{
        int opc;
        while (true)
        {
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
                        break;
                case 2:
                        system("cls");
                        bajaArticulo();
                        break;
                case 3:
                        system("cls");
                        listadoArticulos();
                        break;
                case 4:
                        system("cls");
                        listadoArticulosPorCategoria();
                        break;
                case 5:
                        system("cls");
                        listadoArticulosPorPrecio();
                        break;
                case 6:
                        system("cls");
                        mostrarArticuloPorCodigo();
                        break;
                case 7:
                        system("cls");
                        mostrarArticuloPorDescripcion();
                        break;
                case 8:
                        system("cls");
                        mostrarArticuloPorRangoPreciosYCategoria();
                        break;
                case 9:
                        system("cls");
                        informeCategoriasMasVendidas();
                        break;
                case 10:
                        system("cls");
                        modificarPrecioArticulos();
                        break;
                case 11:
                        system("cls");
                        modificarPrecioArticuloEnParticular();
                        break;
                case 12:
                        system("cls");
                        modificarStockArticulo();
                        break;
                case 0:
                        return true;
                        break;
                }
                system("pause");
        }
}

bool menuVentas()
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
                cout << "12. INFORME DE VENTAS POR AÑO" << endl;
                cout << "0. VOLVER ATRAS" << endl
                     << endl;
                cout << "SELECCIONE UNA OPCION: ";
                cin >> opc;
                switch (opc)
                {
                case 1:
                        system("cls");
                        altaVenta();
                        break;
                case 2:
                        system("cls");
                        bajaVenta();
                        break;
                case 3:
                        system("cls");
                        listadoVentas();
                        break;
                case 4:
                        system("cls");
                        listadoVentasPorCliente();
                        break;
                case 5:
                        system("cls");
                        listadoVentasPorFechaMayorAMenor();
                        break;
                case 6:
                        system("cls");
                        listadoVentasPorArticulo();
                        break;
                case 7:
                        system("cls");
                        listadoVentasPorMetodoPago();
                        break;
                case 8:
                        system("cls");
                        buscarVentaPorDniCliente();
                        break;
                case 9:
                        system("cls");
                        buscarVentaPorFecha();
                        break;
                case 10:
                        system("cls");
                        buscarVentaPorCodigo();
                        break;
                case 11:
                        system("cls");
                        informeVentasPorMes();
                        break;
                case 12:
                        system("cls");
                        informeVentasPorAnio();
                        break;

                case 0:
                        return false;
                        break;
                }
        }
}

bool menuClientes()
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
                        break;
                case 2:
                        system("cls");
                        bajaCliente();
                        break;
                case 3:
                        system("cls");
                        listadoClientes();
                        break;
                case 4:
                        system("cls");
                        listadoClientesOrdenadosPorDni();
                        break;
                case 5:
                        system("cls");
                        listadoClientesOrdenadosPorApellido();
                        break;
                case 6:
                        system("cls");
                        listadoClientesOrdenadosPorFechaRegistro();
                        break;
                case 7:
                        system("cls");
                        modificarCliente();
                        break;
                case 8:
                        system("cls");
                        buscarClientePorDni();
                        break;
                case 9:
                        system("cls");
                        buscarClientePorApellido();
                        break;
                case 10:
                        system("cls");
                        listadoClientesConMasDe5Compras();
                        break;
                case 0:
                        system("cls");
                        return false;
                        break;
                }
        }
}

bool menuFacturas()
{

        while (true)
        {
                int opc;
                cout << "------------MENU FACTURAS------------" << endl;
                cout << "1. ALTA FACTURAS" << endl;
                cout << "2. BAJA FACTURAS" << endl;
                cout << "3. LISTADO" << endl;
                cout << "4. LISTADO POR FECHA" << endl;
                cout << "5. BUSQUEDA DE FACTURA POR NUMERO" << endl;
                cout << "6. BUSQUEDA DE FACTURA POR CODIGO DE VENTA" << endl;
                cout << "7. INFORME TOTAL FACTURADO POR AÑO" << endl;
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
                        break;
                case 2:
                        bajaFactura();
                        break;
                case 3:
                        system("cls");
                        listadoFacturas();
                        break;
                case 4:
                        system("cls");
                        listadoFacturasPorFecha();
                        break;
                case 5:
                        system("cls");
                        buscarFacturaPorNumero();
                        break;
                case 6:
                        system("cls");
                        buscarFacturaPorCodigoVenta();
                        break;
                case 7:
                        system("cls");
                        informeTotalFacturadoPorAnio();
                        break;
                case 8:
                        system("cls");
                        informeTotalFacturadoPorCliente();
                        break;
                case 0:
                        system("cls");
                        return false;
                        break;
                }
        }
}

bool menuAdopcionesCliente()
{
        int opc;
        cout << "------------MENU ADOPCIONES------------" << endl;
        cout << "1. VER LISTADO DE MASCOTAS DISPONIBLES" << endl;
        cout << "2. FORMULARIO DE ADOPCION" << endl;
        cout << "0. MENU PRINCIPAL" << endl << endl;
        cout << "SELECCIONE UNA OPCION: ";
        cin >> opc;
        switch (opc)
        {
        case 1:
                system("cls");
                listadoMascotas();
                break;
        case 2:
                altaFormularioAdopcion();
                break;
        case 0:
                return false;
                break;
        }
        system("pause");

        return false;
}

bool menuAdopcionesEmpleado()
{
        while (true)
        {
                int opc;
                cout << "------------MENU ADOPCIONES------------" << endl;
                cout << "1. DAR DE ALTA MASCOTA" << endl;
                cout << "2. DAR DE BAJA MASCOTA" << endl;
                cout << "3. VER LISTADO DE MASCOTAS DISPONIBLES" << endl;
                cout << "4. MODIFICAR MASCOTA" << endl;
                cout << "5. FORMULARIOS DE ADOPCION" << endl;
                cout << "6. APROBAR O RECHAZAR ADOPCION" << endl;
                cout << "0. VOLVER ATRAS" << endl
                     << endl;
                cout << "SELECCIONE UNA OPCION: ";
                cin >> opc;
                switch (opc)
                {
                case 1:
                        system("cls");
                        altaMascota();
                        break;
                case 2:
                        system("cls");
                        bajaMascota();
                        break;
                case 3:
                        system("cls");
                        listadoMascotas();
                        break;
                case 4:
                        system("cls");
                        modificarMascota();
                        break;
                case 5:
                        system("cls");
                        listadoFormulariosAdopcion();
                        break;
                case 6:
                        system("cls");
                        aprobarRechazarAdopcion();
                        break;

                case 0:
                        system("pause");
                        return false;
                        break;
                }
        }
}

bool menuEmpleados()
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
                        return false;
                        break;
                }
        }

        return false;
}

int main()
{
        int opc;
        bool shouldContinue = true;
        while (true || shouldContinue)
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
                        return 0;
                        break;
                case 1:
                        system("cls");
                        shouldContinue = menuAdopcionesCliente();
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
                        shouldContinue = menuEmpleados();
                        break;
                }
        }
        return 0;
}
