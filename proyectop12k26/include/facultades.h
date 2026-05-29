#ifndef FACULTADES_h
#define FACULTADES_h
#include <string>
using namespace std;

class Facultad{
private:
    int codigoCarrera;
    string nombreCarrera;
    bool estadoCarrera;
    string tipo;


public:
    Facultad();
    Facultad(int codigo, string nombre, bool estado, string tipo);

    int getCodigoCarrera();
    string getNombreCarrera();
    bool getEstadoCarrera();
    string getTipo();

    void setCodigoCarrera(int codigo);
    void setNombreCarrera(string nombre);
    void setEstadoCarrera(bool estado);
    void setTipo(string tipo);

    void mostrarInformacion();
    bool esPrivado();

    void activarCarrera();
    void desactivarCarrera();

    static void inicializarFacultades(Facultad facultades[], int tamanio);


};


#endif
