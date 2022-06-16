#ifndef SELECCION_H
#define SELECCION_H

#include<iostream>
#include"videojuego.h"

using namespace std;

void seleccionAsc(Videojuego&);
void seleccionDesc(Videojuego&);

void menuSeleccion(Videojuego &videojuego)
{
    int opcion;

    cout << "1. Ascendente" << endl;
    cout << "2. Descendente" << endl;
    cin >> opcion; cin.ignore();

    switch(opcion)
    {
        case 1:
            seleccionAsc(videojuego);
        break;
        case 2:
            seleccionDesc(videojuego);
        break;
        default:
            cout << "Opcion " << opcion << " invalida" << endl;
        break;
    }
}

void seleccionAsc(Videojuego &videojuego)
{
    int opcion;

    cout << "1. Nombre" << endl;
    cout << "2. Tipo" << endl;
    cout << "3. Fuerza" << endl;
    cout << "4. Salud" << endl;
    cin >> opcion; cin.ignore();

    switch(opcion)
    {
        case 1:
            videojuego.ascSeleccionNombre();
        break;
        case 2:
            videojuego.ascSeleccionTipo();
        break;
        case 3:
            videojuego.ascSeleccionFuerza();
        break;
        case 4:
            videojuego.ascSeleccionSalud();
        break;
        default:
            cout << "Opcion " << opcion << " invalida" << endl;
        break;
    }
}

void seleccionDesc(Videojuego &videojuego)
{
    int opcion;

    cout << "1. Nombre" << endl;
    cout << "2. Tipo" << endl;
    cout << "3. Fuerza" << endl;
    cout << "4. Salud" << endl;
    cin >> opcion; cin.ignore();

    switch(opcion)
    {
        case 1:
            videojuego.descSeleccionNombre();
        break;
        case 2:
            videojuego.descSeleccionTipo();
        break;
        case 3:
            videojuego.descSeleccionFuerza();
        break;
        case 4:
            videojuego.descSeleccionSalud();
        break;
        default:
            cout << "Opcion " << opcion << " invalida" << endl;
        break;
    }
}

#endif//SELECCION_H
