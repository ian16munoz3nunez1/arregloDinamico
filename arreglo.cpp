#include"arreglo.h"

Arreglo::Arreglo()
{
    arreglo = new int[MAX];
    cont = 0;
    tam = MAX;
}

void Arreglo::insertarInicio(int v)
{
    if(cont == tam)
        expandir();

    for(size_t i = cont; i > 0; i--)
        arreglo[i] = arreglo[i-1];

    arreglo[0] = v;
    cont++;
}

void Arreglo::insertarFinal(int v)
{
    if(cont == tam)
        expandir();

    arreglo[cont] = v;
    cont++;
}

void Arreglo::eliminarInicio()
{
    if(cont == 0)
    {
        cout << "Arreglo vacio" << endl << "No se puede eliminar al inicio" << endl;
        return;
    }

    for(size_t i = 0; i < cont-1; i++)
        arreglo[i] = arreglo[i+1];

    cont--;
}

void Arreglo::eliminarFinal()
{
    if(cont == tam)
    {
        cout << "Arreglo vacio" << endl << "No se puede eliminar al final" << endl;
        return;
    }

    cont--;
}

size_t Arreglo::size()
{
    return cont;
}

void Arreglo::expandir()
{
    int *nuevo = new int[tam + MAX];

    for(size_t i = 0; i < cont; i++)
        nuevo[i] = arreglo[i];

    delete[] arreglo;
    arreglo = nuevo;
    tam += MAX;
}

Arreglo::~Arreglo()
{
    delete[] arreglo;
}
