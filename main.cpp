#include<iostream>
#include"arreglo.h"

using namespace std;

int main()
{
    Arreglo<int> enteros;

    for(size_t i = 1; i <= 16; i++)
    {
        if(i % 2 == 0)
            enteros.insertarFinal(i);
        else
            enteros.insertarInicio(i);
    }

    enteros.insertar(24, 2);
    enteros.insertar(24, 4);
    enteros.insertar(24, 8);
    enteros.insertar(24, 16);

    for(size_t i = 0; i < enteros.size(); i++)
        cout << enteros[i] << " ";

    cout << endl;
    Arreglo<int> burbuja = enteros.burbuja();
    for(size_t i = 0; i < burbuja.size(); i++)
        cout << burbuja[i] << " ";

    cout << endl;
    Arreglo<int> seleccion = enteros.seleccion();
    for(size_t i = 0; i < seleccion.size(); i++)
        cout << seleccion[i] << " ";

    return 0;
}
