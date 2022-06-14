#include<iostream>
#include"arreglo.h"

using namespace std;

int main()
{
    Arreglo enteros;

    for(size_t i = 1; i <= 16; i++)
    {
        if(i % 2 == 0)
            enteros.insertarFinal(i);
        else
            enteros.insertarInicio(i);
    }

    for(size_t i = 0; i < enteros.size(); i++)
        cout << enteros[i] << " ";


    enteros.eliminarInicio();
    enteros.eliminarFinal();

    cout << endl;
    for(size_t i = 0; i < enteros.size(); i++)
        cout << enteros[i] << " ";

    return 0;
}
