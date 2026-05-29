#include "facultades.h"
#include <iostream>
using namespace std;

Facultad::Facultad() {
    codigoCarrera = 0;
    nombreCarrera = "";
    estadoCarrera = true;
    tipo = "privado";
}

Facultad::Facultad(int codigo, string nombre, bool estado, string tipo){
    codigoCarrera = codigo;
    nombreCarrera = nombre;
    estadoCarrera = estado;
    this->tipo = tipo;

}

int Facultad:: getCodigoCarrera(){
    return codigoCarrera;
}

string Facultad:: getNombreCarrera(){
    return nombreCarrera;
}

bool Facultad:: getEstadoCarrera(){
    return estadoCarrera;
}

string Facultad:: getTipo(){
    return tipo;
}

void Facultad::setCodigoCarrera(int codigo){
    codigoCarrera = codigo;
}

void Facultad::setNombreCarrera(string nombre){
    nombreCarrera = nombre;
}

void Facultad::setEstadoCarrera(bool estado){
    estadoCarrera = estado;
}

void Facultad::setTipo(string tipo){
    this->tipo = tipo;
}


void Facultad::mostrarInformacion(){
    cout << "Codigo de carrera: "<< codigoCarrera << endl;
    cout << "Nombre de carrera: : "<< nombreCarrera << endl;
    cout << "Estado:  "<< (estadoCarrera ? "Activa" : "Inactiva") << endl;
    cout << "Tipo: "<< tipo << endl;
    cout << "---------------------"<< codigoCarrera << endl;

}
bool Facultad::esPrivado(){
    return tipo == "privado";
}

void Facultad::activarCarrera(){
    estadoCarrera = true;
}

void Facultad::desactivarCarrera(){
    estadoCarrera = false;
}

void Facultad::inicializarFacultades(Facultad facultades[], int tamanio){
    if (tamanio >= 5){
        facultades[0] = Facultad(101, "Facultad de Ingenieria en Sistemas", true , "Privado");
        facultades[1] = Facultad(102, "Facultad de Ciencias Juridicas y Sociales", true , "Privado");
        facultades[2] = Facultad(103, "Facultad de Ciencias Médicas y de la Salud", true , "Privado");
        facultades[3] = Facultad(104, "Facultad de Ciencias de la Administración", true , "Privado");
        facultades[4] = Facultad(105, "Facultad de Humanidades", true , "Privado");
    }
}
