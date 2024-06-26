#pragma once

class Mascota {
    private:
        int _idMascota;
        char _nombre[30];
        char _especie[30];
        char _raza[30];
        int _edad;
        char _genero[30];
        char _tamanio[30];
        char _comportamiento[30];
        bool _estado;
    public:
        Mascota();
        Mascota(int idMascota, const char nombre[30], const char especie[30], const char raza[30], int edad, const char genero[30], const char tamanio[30], const char comportamiento[30], bool estado);
        //GETS
        int getIdMascota();
        const char* getNombre();
        const char* getEspecie();
        const char* getRaza();
        int getEdad();
        const char* getGenero();
        const char* getTamanio();
        const char* getComportamiento();
        bool getEstado();
        //SETS
        void setIdMascota(int idMascota);
        void setNombre(const char nombre[30]);
        void setEspecie(const char especie[30]);
        void setRaza(const char raza[30]);
        void setEdad(int edad);
        void setGenero(const char genero[30]);
        void setTamanio(const char tamanio[30]);
        void setComportamiento(const char comportamiento[30]);
        void setEstado(bool estado);
};