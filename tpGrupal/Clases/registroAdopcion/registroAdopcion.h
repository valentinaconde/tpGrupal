#pragma once

class RegistroAdopcion {
    private:
        int _idRegistro;
        int _idAdopcion;
        Fecha _fechaRegistro;
    public:
        RegistroAdopciones();
        RegistroAdopciones(int idRegistro, int idAdopcion, Fecha fechaRegistro);
        //GETS
        int getIdRegistro();
        int getIdAdopcion();
        Fecha getFechaRegistro();
        //SETS
        void setIdRegistro(int idRegistro);
        void setIdAdopcion(int idAdopcion);
        void setFechaRegistro(Fecha fechaRegistro);
};