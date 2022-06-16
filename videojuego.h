#ifndef VIDEOJUEGO_H
#define VIDEOJUEGO_H

#include<iostream>
#include"arreglo.h"
#include"personaje.h"

using namespace std;

class Videojuego
{
    Arreglo<Personaje> personajes;

public:
    Videojuego();

    void mostrar();
    void guardar(const string&);
    void abrir(const string&);

    void insertarInicio(const Personaje&);
    void insertarFinal(const Personaje&);
    void insertar(const Personaje&, size_t);

    void eliminarInicio();
    void eliminarFinal();
    void eliminar(size_t);

    void buscarNombre(const Personaje&);
    void buscarTipo(const Personaje&);
    void buscarFuerza(const Personaje&);
    void buscarSalud(const Personaje&);

    void buscarTodosNombre(const Personaje&);
    void buscarTodosTipo(const Personaje&);
    void buscarTodosFuerza(const Personaje&);
    void buscarTodosSalud(const Personaje&);

    void ascBurbujaNombre();
    void ascBurbujaTipo();
    void ascBurbujaFuerza();
    void ascBurbujaSalud();
    void descBurbujaNombre();
    void descBurbujaTipo();
    void descBurbujaFuerza();
    void descBurbujaSalud();

    void ascSeleccionNombre();
    void ascSeleccionTipo();
    void ascSeleccionFuerza();
    void ascSeleccionSalud();
    void descSeleccionNombre();
    void descSeleccionTipo();
    void descSeleccionFuerza();
    void descSeleccionSalud();

    size_t size();

    friend Videojuego& operator<<(Videojuego &videojuego, const Personaje &personaje)
    {
        videojuego.insertarFinal(personaje);
        return videojuego;
    }

private:
    void isPtr(const Personaje*);
    void isPtrs(Arreglo<Personaje*>&);
    void printOrdenado(Arreglo<Personaje>&);
    void cabecera();
    void linea();
};

#endif//VIDEOJUEGO_H
