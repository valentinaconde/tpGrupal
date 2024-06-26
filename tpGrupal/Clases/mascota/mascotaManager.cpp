#include "MascotaManager.h"
#include <iostream>

void MascotaManager::agregarMascota() {
    Mascota nuevaMascota = crearMascota();
    _mascotaArchivo.agregarMascota(nuevaMascota);
}

void MascotaManager::listarMascotas() {
    auto mascotas = _mascotaArchivo.leerMascotas();
    for (const auto& mascota : mascotas) {
        mostrarMascota(mascota);
    }
}

Mascota MascotaManager::crearMascota() {
    // Aquí se solicitarían los datos de la mascota al usuario y se crearía el objeto Mascota
    Mascota mascota;
    // Supongamos que llenamos los datos de mascota aquí
    return mascota;
}

void MascotaManager::volverCargarMascota(Mascota &registro) {
    // Aquí se podría implementar la lógica para recargar los datos de una mascota desde el archivo
}

void MascotaManager::mostrarMascota(Mascota registro) {
    std::cout << "ID: " << registro.getIdMascota() << ", Nombre: " << registro.getNombre() << std::endl;
    // Aquí se mostrarían todos los detalles de la mascota
}

void MascotaManager::modificarMascota() {
    // Aquí se implementaría la lógica para modificar una mascota existente
}

void MascotaManager::eliminarMascota() {
    // Aquí se implementaría la lógica para eliminar una mascota
}

void MascotaManager::Menu() {
    int opcion;
    do {
        std::cout << "1. Agregar Mascota\n";
        std::cout << "2. Listar Mascotas\n";
        std::cout << "3. Modificar Mascota\n";
        std::cout << "4. Eliminar Mascota\n";
        std::cout << "5. Salir\n";
        std::cout << "Seleccione una opción: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                agregarMascota();
                break;
            case 2:
                listarMascotas();
                break;
            case 3:
                modificarMascota();
                break;
            case 4:
                eliminarMascota();
                break;
            case 5:
                std::cout << "Saliendo...\n";
                break;
            default:
                std::cout << "Opción no válida\n";
        }
    } while (opcion != 5);
}