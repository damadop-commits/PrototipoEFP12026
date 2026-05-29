#ifndef CARRERA_H
#define CARRERA_H

// Creado por David Alegria 9959-23-11277

#include <iostream>
#include <fstream>
#include <iomanip>
#include <conio.h>
#include <vector>

using namespace std;

class Carrera
{
    private:
        string codigoCarrera;
        string nombreCarrera;
        bool estadoCarrera;

    public:
        Carrera();
        Carrera(string codigoCarrera, string nombreCarrera, bool estadoCarrera);

        // Get
        string getcodigoCarrera();
        string getnombreCarrera();
        bool getestadoCarrera();

        // Set
        void setcodigoCarrera(string codigoCarrera);
        void setnombreCarrera(string nombreCarrera);
        void setestadoCarrera(bool estadoCarrera);

        // Metodos
        vector<Carrera> datosCarreras();

        void menu();
        void insertar();
        void desplegar();
        void modificar();
        void buscar();
        void borrar();
};

#endif // CARRERA_H
