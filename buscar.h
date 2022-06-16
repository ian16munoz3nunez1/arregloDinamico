#ifndef BUSCAR_H
#define BUSCAR_H

#include<iostream>
#include"videojuego.h"
#include"personaje.h"

using namespace std;

void buscar(Videojuego &videojuego)
{
    Personaje buscar;
    string nombre, tipo;
    float fuerza; int salud;
    int opcion;

    cout << "1. Nombre" << endl;
    cout << "2. Tipo" << endl;
    cout << "3. Fuerza" << endl;
    cout << "4. Salud" << endl;
    cin >> opcion; cin.ignore();

    switch(opcion)
    {
        case 1:
            cout << "Ingresa el nombre: ";
            getline(cin, nombre);
            buscar.setNombre(nombre);
            videojuego.buscarNombre(buscar);
        break;

        case 2:
            cout << "Ingresa el tipo: ";
            getline(cin, tipo);
            buscar.setTipo(tipo);
            videojuego.buscarTipo(buscar);
        break;

        case 3:
            cout << "Ingresa la fuerza: ";
            cin >> fuerza; cin.ignore();
            buscar.setFuerza(fuerza);
            videojuego.buscarFuerza(buscar);
        break;

        case 4:
            cout << "Ingresa la salud: ";
            cin >> salud; cin.ignore();
            buscar.setSalud(salud);
            videojuego.buscarSalud(buscar);
        break;

        default:
            cout << "Opcion " << opcion << " invalida" << endl;
        break;
    }
}

void buscarTodos(Videojuego &videojuego)
{
    Personaje buscar;
    string nombre, tipo;
    float fuerza; int salud;
    int opcion;

    cout << "1. Nombre" << endl;
    cout << "2. Tipo" << endl;
    cout << "3. Fuerza" << endl;
    cout << "4. Salud" << endl;
    cin >> opcion; cin.ignore();

    switch(opcion)
    {
        case 1:
            cout << "Ingresa el nombre: ";
            getline(cin, nombre);
            buscar.setNombre(nombre);
            videojuego.buscarTodosNombre(buscar);
        break;

        case 2:
            cout << "Ingresa el tipo: ";
            getline(cin, tipo);
            buscar.setTipo(tipo);
            videojuego.buscarTodosTipo(buscar);
        break;

        case 3:
            cout << "Ingresa la fuerza: ";
            cin >> fuerza; cin.ignore();
            buscar.setFuerza(fuerza);
            videojuego.buscarTodosFuerza(buscar);
        break;
        
        case 4:
            cout << "Ingresa la salud: ";
            cin >> salud; cin.ignore();
            buscar.setSalud(salud);
            videojuego.buscarTodosSalud(buscar);
        break;

        default:
            cout << "Opcion " << opcion << " invalida" << endl;
        break;
    }
}

#endif//BUSCAR_H
