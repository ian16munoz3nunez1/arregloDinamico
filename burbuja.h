#ifndef BURBUJA_H
#define BURBUJA_H

#include<iostream>
#include"videojuego.h"

using namespace std;

void burbujaAsc(Videojuego&);
void burbujaDesc(Videojuego&);

void menuBurbuja(Videojuego &videojuego)
{
    int opcion;

    cout << "1. Ascendente" << endl;
    cout << "2. Descendente" << endl;
    cin >> opcion; cin.ignore();

    switch(opcion)
    {
        case 1:
            burbujaAsc(videojuego);
        break;
        case 2:
            burbujaDesc(videojuego);
        break;
        default:
            cout << "Opcion " << opcion << " invalida" << endl;
        break;
    }
}

void burbujaAsc(Videojuego &videojuego)
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
            videojuego.ascBurbujaNombre();
        break;
        case 2:
            videojuego.ascBurbujaTipo();
        break;
        case 3:
            videojuego.ascBurbujaFuerza();
        break;
        case 4:
            videojuego.ascBurbujaSalud();
        break;
        default:
            cout << "Opcion " << opcion << " invalida" << endl;
        break;
    }
}

void burbujaDesc(Videojuego &videojuego)
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
            videojuego.descBurbujaNombre();
        break;
        case 2:
            videojuego.descBurbujaTipo();
        break;
        case 3:
            videojuego.descBurbujaFuerza();
        break;
        case 4:
            videojuego.descBurbujaSalud();
        break;
        default:
            cout << "Opcion " << opcion << " invalida" << endl;
        break;
    }

}

#endif//BURBUJA_H