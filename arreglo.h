#ifndef ARREGLO_H
#define ARREGLO_H

#include<iostream>

using namespace std;

class Arreglo
{
    int *arreglo;
    size_t cont;
    size_t tam;
    const static size_t MAX = 5;

public:
    Arreglo();
    ~Arreglo();

    void insertarInicio(int);
    void insertarFinal(int);

    void eliminarInicio();
    void eliminarFinal();

    size_t size();

    int operator[](size_t i)
    {
        return arreglo[i];
    }

private:
    void expandir();
};

#endif//ARREGLO_H