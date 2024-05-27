#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

#include "fecha.h"
#include "articulo.h"
#include "factura.h"
#include "cliente.h"
#include "venta.h"
#include "formularioAdopcion.h"
#include "mascota.h"
#include "registroAdopciones.h"

int chequearContrasenia()
{
        char contrasenia[20];
        cout << "INGRESE CONTRASENA: ";
        cin >> contrasenia;
        if (strcmp(contrasenia, "1234") == 0)
        {
                cout << "CONTRASENA CORRECTA" << endl;
                return 1;
        }
        else
        {
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
                cout << "0. SALIR" << endl;
                cout << "SELECCIONE UNA OPCION: " << endl;
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
        cout << "------------MENU VENTAS------------" << endl;
        cout << "1. VENDER" << endl;
        cout << "2. DEVOLUCION" << endl;
        cout << "3. LISTADO" << endl;
        cout << "4. SALIR" << endl;
        cout << "SELECCIONE UNA OPCION: " << endl;
        cin >> opc;
        switch (opc)
        {
        case 1:
                system("cls");
                // altaCliente();
                break;
        case 2:
                // bajaCliente();
                break;
        case 3:
                system("cls");
                // listadoClientes();
                break;
        case 0:
                return true;
                break;
        }
        system("pause");

        return true;
};

bool menuClientes()
{
        int opc;
        cout << "------------MENU CLIENTES------------" << endl;
        cout << "1. ALTA CLIENTES" << endl;
        cout << "2. BAJA CLIENTES" << endl;
        cout << "3. LISTADO" << endl;
        cout << "4. SALIR" << endl;
        cout << "SELECCIONE UNA OPCION: " << endl;
        cin >> opc;
        switch (opc)
        {
        case 1:
                system("cls");
                altaCliente();
                break;
        case 2:
                bajaCliente();
                break;
        case 3:
                system("cls");
                listadoClientes();
                break;
        case 0:
                return true;
                break;
        }
        system("pause");
        return true;
}

bool menuFacturas()
{
        int opc;
        cout << "------------MENU FACTURAS------------" << endl;
        cout << "1. ALTA FACTURAS" << endl;
        cout << "2. BAJA FACTURAS" << endl;
        cout << "3. LISTADO" << endl;
        cout << "4. SALIR" << endl;
        cout << "SELECCIONE UNA OPCION: " << endl;
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
        case 0:
                return true;
                break;
        }
        system("pause");
        return true;
}

bool menuAdopciones()
{
        int opc;
        cout << "------------MENU ADOPCIONES------------" << endl;
        cout << "1. VER LISTADO DE MASCOTAS DISPONIBLES" << endl;
        cout << "2. FORMULARIO DE ADOPCION" << endl;
        cout << "0. SALIR" << endl;
        cout << "SELECCIONE UNA OPCION: " << endl;
        cin >> opc;
        switch (opc)
        {
        case 1:
                system("cls");
                // altaCliente();
                break;
        case 2:
                // bajaCliente();
                break;
        case 0:
                return false;
                break;
        }
        system("pause");

        return false;
}

bool menuEmpleados()
{
        int opc;
        cout << "------------MENU EMPLEADOS------------" << endl;
        cout << "1. ARTICULOS" << endl;
        cout << "2. VENTAS" << endl;
        cout << "3. CLIENTES" << endl;
        cout << "4. FACTURAS" << endl;
        cout << "5. ADOPCIONES" << endl;
        cout << "0. SALIR" << endl;
        cout << "SELECCIONE UNA OPCION: " << endl;
        cin >> opc;
        switch (opc)
        {
        case 1:
                system("cls");
                return menuArticulos();
                break;
        case 2:
                system("cls");
                return menuVentas();
                break;
        case 3:
                system("cls");
                return menuClientes();
                break;
        case 4:
                system("cls");
                return menuFacturas();
                break;
        case 5:
                system("cls");
                return menuAdopciones();
                break;
        case 0:
                return false;
                break;
        }
        system("pause");

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
                        shouldContinue = menuAdopciones();
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
