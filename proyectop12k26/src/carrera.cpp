#include "Carrera.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <conio.h>
#include <stdlib.h>

using namespace std;

// Creado por David Alegria 9959-23-11277

Carrera::Carrera()
{
    // ctor
}

Carrera::Carrera(string codigoCarrera, string nombreCarrera, bool estadoCarrera)
{
    this->codigoCarrera = codigoCarrera;
    this->nombreCarrera = nombreCarrera;
    this->estadoCarrera = estadoCarrera;
}

vector<Carrera> Carrera::datosCarreras()
{
    vector<Carrera> infoCarreras;

    infoCarreras.push_back(Carrera("9959", "Ingenieria en Sistemas", true));
    infoCarreras.push_back(Carrera("9975", "Ingenieria Industrial", true));
    infoCarreras.push_back(Carrera("9973", "Ingenieria Civil", true));

    return infoCarreras;
}

void Carrera::menu()
{
    int opcion;
    char x;

    do
    {
        system("cls");

        cout << "\n\t\t----------------------------------" << endl;
        cout << "\t\t |   SISTEMA DE CARRERAS   |" << endl;
        cout << "\t\t----------------------------------" << endl;
        cout << "\t\t 1. Ingresar Carrera" << endl;
        cout << "\t\t 2. Mostrar Carreras" << endl;
        cout << "\t\t 3. Modificar Carrera" << endl;
        cout << "\t\t 4. Buscar Carrera" << endl;
        cout << "\t\t 5. Eliminar Carrera" << endl;
        cout << "\t\t 6. Salir" << endl;
        cout << "\t\t----------------------------------" << endl;

        cout << "\nIngrese una opcion: ";
        cin >> opcion;

        switch(opcion)
        {
            case 1:
                do
                {
                    insertar();

                    cout << "\nDesea agregar otra carrera (Y/N): ";
                    cin >> x;

                } while(x == 'y' || x == 'Y');

                break;

            case 2:
                desplegar();
                break;

            case 3:
                modificar();
                break;

            case 4:
                buscar();
                break;

            case 5:
                borrar();
                break;

            case 6:
                exit(0);
                break;

            default:
                cout << "\nOpcion invalida...";
        }

        getch();

    } while(opcion != 6);
}

void Carrera::insertar()
{
    system("cls");

    fstream file;
    string codigoTemp, nombreTemp;
    bool estadoTemp;
    bool existe = false;

    cout << "\n---------------- AGREGAR CARRERA ----------------" << endl;

    cout << "Ingrese codigo de la carrera: ";
    cin >> codigoTemp;

    // Verificar si ya existe
    file.open("Carreras.txt", ios::in);

    if(file)
    {
        while(getline(file, codigoCarrera, '|'))
        {
            getline(file, nombreCarrera, '|');
            file >> estadoCarrera;
            file.ignore();

            if(codigoTemp == codigoCarrera)
            {
                existe = true;
                break;
            }
        }

        file.close();
    }

    if(existe)
    {
        cout << "\nEl codigo ya existe...";
        return;
    }

    cin.ignore();

    cout << "Ingrese nombre de la carrera: ";
    getline(cin, nombreTemp);

    cout << "Ingrese estado de la carrera (1 = Activa, 0 = Inactiva): ";
    cin >> estadoTemp;

    file.open("Carreras.txt", ios::app | ios::out);

    file << codigoTemp << "|"
         << nombreTemp << "|"
         << estadoTemp << "\n";

    file.close();

    cout << "\nCarrera agregada correctamente...";
}

void Carrera::desplegar()
{
    system("cls");

    fstream file;
    int total = 0;

    cout << "\n---------------- LISTA DE CARRERAS ----------------" << endl;

    // MOSTRAR LAS CARRERAS PREDEFINIDAS
    vector<Carrera> carreras = datosCarreras();

    for(int i = 0; i < carreras.size(); i++)
    {
        cout << "\nCodigo Carrera: " << carreras[i].getcodigoCarrera() << endl;
        cout << "Nombre Carrera: " << carreras[i].getnombreCarrera() << endl;
        cout << "Estado Carrera: " << carreras[i].getestadoCarrera() << endl;

        total++;
    }

    // MOSTRAR LAS CARRERAS DEL ARCHIVO
    file.open("Carreras.txt", ios::in);

    if(file)
    {
        while(getline(file, codigoCarrera, '|'))
        {
            getline(file, nombreCarrera, '|');
            file >> estadoCarrera;
            file.ignore();

            cout << "\nCodigo Carrera: " << codigoCarrera << endl;
            cout << "Nombre Carrera: " << nombreCarrera << endl;
            cout << "Estado Carrera: " << estadoCarrera << endl;

            total++;
        }

        file.close();
    }

    if(total == 0)
    {
        cout << "\nNo hay informacion...";
    }
}

void Carrera::modificar()
{
    system("cls");

    fstream file, file1;
    string codigoBuscar;
    int encontrado = 0;

    cout << "\n---------------- MODIFICAR CARRERA ----------------" << endl;

    file.open("Carreras.txt", ios::in);

    if(!file)
    {
        cout << "\nNo hay informacion...";
    }
    else
    {
        cout << "Ingrese el codigo de la carrera a modificar: ";
        cin >> codigoBuscar;

        file1.open("Temporal.txt", ios::out);

        while(getline(file, codigoCarrera, '|'))
        {
            getline(file, nombreCarrera, '|');
            file >> estadoCarrera;
            file.ignore();

            if(codigoBuscar != codigoCarrera)
            {
                file1 << codigoCarrera << "|"
                      << nombreCarrera << "|"
                      << estadoCarrera << "\n";
            }
            else
            {
                cout << "\nIngrese nuevo codigo: ";
                cin >> codigoCarrera;

                cin.ignore();

                cout << "Ingrese nuevo nombre: ";
                getline(cin, nombreCarrera);

                cout << "Ingrese nuevo estado (1 = Activa, 0 = Inactiva): ";
                cin >> estadoCarrera;

                file1 << codigoCarrera << "|"
                      << nombreCarrera << "|"
                      << estadoCarrera << "\n";

                encontrado++;
            }
        }

        file.close();
        file1.close();

        remove("Carreras.txt");
        rename("Temporal.txt", "Carreras.txt");

        if(encontrado == 0)
        {
            cout << "\nCarrera no encontrada...";
        }
        else
        {
            cout << "\nCarrera modificada correctamente...";
        }
    }
}

void Carrera::buscar()
{
    system("cls");

    fstream file;
    string codigoBuscar;
    int encontrado = 0;

    cout << "\n---------------- BUSCAR CARRERA ----------------" << endl;

    cout << "Ingrese el codigo de la carrera a buscar: ";
    cin >> codigoBuscar;

    // BUSCAR EN VECTOR
    vector<Carrera> carreras = datosCarreras();

    for(int i = 0; i < carreras.size(); i++)
    {
        if(codigoBuscar == carreras[i].getcodigoCarrera())
        {
            cout << "\nCodigo Carrera: " << carreras[i].getcodigoCarrera() << endl;
            cout << "Nombre Carrera: " << carreras[i].getnombreCarrera() << endl;
            cout << "Estado Carrera: " << carreras[i].getestadoCarrera() << endl;

            encontrado++;
        }
    }

    // BUSCAR EN ARCHIVO
    file.open("Carreras.txt", ios::in);

    if(file)
    {
        while(getline(file, codigoCarrera, '|'))
        {
            getline(file, nombreCarrera, '|');
            file >> estadoCarrera;
            file.ignore();

            if(codigoBuscar == codigoCarrera)
            {
                cout << "\nCodigo Carrera: " << codigoCarrera << endl;
                cout << "Nombre Carrera: " << nombreCarrera << endl;
                cout << "Estado Carrera: " << estadoCarrera << endl;

                encontrado++;
            }
        }

        file.close();
    }

    if(encontrado == 0)
    {
        cout << "\nCarrera no encontrada...";
    }
}

void Carrera::borrar()
{
    system("cls");

    fstream file, file1;
    string codigoBuscar;
    int encontrado = 0;

    cout << "\n---------------- ELIMINAR CARRERA ----------------" << endl;

    file.open("Carreras.txt", ios::in);

    if(!file)
    {
        cout << "\nNo hay informacion...";
    }
    else
    {
        cout << "Ingrese el codigo de la carrera a eliminar: ";
        cin >> codigoBuscar;

        file1.open("Temporal.txt", ios::out);

        while(getline(file, codigoCarrera, '|'))
        {
            getline(file, nombreCarrera, '|');
            file >> estadoCarrera;
            file.ignore();

            if(codigoBuscar != codigoCarrera)
            {
                file1 << codigoCarrera << "|"
                      << nombreCarrera << "|"
                      << estadoCarrera << "\n";
            }
            else
            {
                encontrado++;
            }
        }

        file.close();
        file1.close();

        remove("Carreras.txt");
        rename("Temporal.txt", "Carreras.txt");

        if(encontrado == 0)
        {
            cout << "\nCarrera no encontrada...";
        }
        else
        {
            cout << "\nCarrera eliminada correctamente...";
        }
    }
}

string Carrera::getnombreCarrera()
{
    return this->nombreCarrera;
}

string Carrera::getcodigoCarrera()
{
    return this->codigoCarrera;
}

bool Carrera::getestadoCarrera()
{
    return this->estadoCarrera;
}

void Carrera::setnombreCarrera(string nombreCarrera)
{
    this->nombreCarrera = nombreCarrera;
}

void Carrera::setcodigoCarrera(string codigoCarrera)
{
    this->codigoCarrera = codigoCarrera;
}

void Carrera::setestadoCarrera(bool estadoCarrera)
{
    this->estadoCarrera = estadoCarrera;
}
