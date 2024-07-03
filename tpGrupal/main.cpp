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


#include "Mascota.h"
#include "MascotaArchivo.h"
#include "MascotaManager.h"

#include "FormularioAdopcion.h"
#include "FormularioAdopcionArchivo.h"
#include "FormularioAdopcionManager.h"

#include "RegistroAdopcion.h"
#include "RegistroAdopcionArchivo.h"
#include "RegistroAdopcionManager.h"

#include "backup.h"



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





*/



int main()
{

        ArticulosManager articulosManager;
        CategoriasManager categoriasManager;
        ClientesManager clientesManager;
        FormularioAdopcionManager formularioAdopcionManager;
        MascotasManager mascotasManager;
        PersonasManager personasManager;
        RegistroAdopcionManager registroAdopcionManager;
        Backup backup;

        while (true)
        {
                system("cls");
                int opc;
                cout << "------------MENU EMPLEADOS------------" << endl;
                cout << "1. ARTICULOS" << endl;
                cout << "2. CATEGORIAS" << endl;
                cout << "3. PERSONAS" << endl;
                cout << "4. CLIENTES" << endl;
                cout << "5. PROVEEDORES" << endl;
                cout << "6. METODOS DE PAGO" << endl;
                cout << "7. DETALLES DE FACTURAS" << endl;
                cout << "8. DETALLES DE COMPRA" << endl;
                cout << "9. FORMULARIOS DE ADOPCION" << endl;
                cout << "10. REGISTRO DE ADOPCIONES" << endl;
                cout << "11. MASCOTAS" << endl;
                cout << "12. BACKUP" << endl;
                cout << "0. SALIR" << endl
                     << endl;
                cout << "SELECCIONE UNA OPCION: ";
                cin >> opc;
                switch (opc)
                {
                case 1:
                        system("cls");
                        articulosManager.Menu();

                        break;
                case 2:
                        system("cls");
                        categoriasManager.Menu();
                        break;
                case 3:
                        system("cls");
                        personasManager.Menu();
                        break;
                case 4:
                        system("cls");
                        clientesManager.Menu();
                        break;
                case 9:
                        system("cls");
                        formularioAdopcionManager.Menu();
                        break;
                case 10:
                        system("cls");
                        registroAdopcionManager.Menu();
                        break;
                case 11:
                    system("cls");
                    mascotasManager.Menu();
                    break;
                case 12:
                    system("cls");
                    backup.Menu();
                    break;
                case 0:
                        return 0;
                        break;
                }
        }

        return 0;
}
