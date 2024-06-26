#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

#include "Fecha.h"

#include "Articulo.h"
#include "ArticuloArchivo.h"
#include "ArticuloManager.h"


#include "categoria.h"
#include "categoriaArchivo.h"
#include "categoriaManager.h"

#include "Persona.h"
#include "PersonaArchivo.h"
#include "PersonaManager.h"

#include "Cliente.h"
#include "ClienteArchivo.h"
#include "ClienteManager.h"
/*

#include "DetalleCompra.h"
#include "DetalleCompraArchivo.h"
#include "DetalleCompraManager.h"

#include "DetalleFactura.h"
#include "DetalleFacturaArchivo.h"
#include "DetalleFacturaManager.h"

#include "Factura.h"
#include "FacturaArchivo.h"
#include "FacturaManager.h"

#include "Compra.h"
#include "CompraArchivo.h"
#include "CompraManager.h"




#include "Mascota.h"
// #include "Clases/mascota/MascotaArchivo.h"
// #include "Clases/mascota/MascotaManager.h"


// #include "Clases/metodoPago/metodoPago.h"
// #include "Clases/metodoPago/metodoPagoArchivo.h"
// // #include "Clases/metodoPago/metodoPagoManager.h"



// #include "Clases/proveedor/Proveedor.h"
// #include "Clases/proveedor/ProveedorArchivo.h"
// // #include "Clases/proveedor/ProveedorManager.h"


#include "FormularioAdopcion.h"
#include "FormularioAdopcionArchivo.h"
#include "FormularioAdopcionManager.h"

#include "RegistroAdopcion.h"
#include "RegistroAdopcionArchivo.h"
// #include "Clases/registroAdopcion/RegistroAdopcionManager.h"

*/
int main()
{

       CategoriasManager cat;
       cat.Menu();
        /*
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
*/
        return 0;
}
