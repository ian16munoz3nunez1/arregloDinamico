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
    void guardar();
    void abrir();

    void insertarInicio(const Personaje&);
    void insertarFinal(const Personaje&);
    void insertar(const Personaje&, size_t);

    void eliminarInicio();
    void eliminarFinal();
    void eliminar(size_t);

    size_t size();

    friend Videojuego& operator<<(Videojuego &videojuego, const Personaje &personaje)
    {
        videojuego.insertarFinal(personaje);
        return videojuego;
    }
};

#endif//VIDEOJUEGO_H