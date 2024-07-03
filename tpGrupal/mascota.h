#pragma once

class Mascota {
    private:
        int _idMascota;
        char _nombre[30];
        char _especie[30];
        char _raza[30];
        int _edad;
        char _genero;
        char _tamanio;
        char _comportamiento[30];
        bool _estado;
    public:
        Mascota();
        Mascota(int idMascota, const char* nombre, const char* especie, const char* raza, int edad, char genero, char tamanio, const char comportamiento[30], bool estado);
        //GETS
        int getIdMascota();
        const char* getNombre();
        const char* getEspecie();
        const char* getRaza();
        int getEdad();
        char getGenero();
        char getTamanio();
        const char* getComportamiento();
        bool getEstado();
        //SETS
        void setIdMascota(int idMascota);
        void setNombre(const char* nombre);
        void setEspecie(const char* especie);
        void setRaza(const char* raza);
        void setEdad(int edad);
        void setGenero(char genero);
        void setTamanio(char tamanio);
        void setComportamiento(const char* comportamiento);
        void setEstado(bool estado);
};
