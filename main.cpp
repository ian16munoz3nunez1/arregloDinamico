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
    int *valor = enteros.buscar(4);
    if(valor != nullptr)
        cout << "Valor: " << *valor;
    else
        cout << "Valor no encontrado";

    cout << endl;
    Arreglo<int*> valores = enteros.buscarTodos(24);
    if(valores.size() > 0)
    {
        for(size_t i = 0; i < valores.size(); i++)
            cout << *valores[i] << " ";
        cout << endl;
    }
    else
        cout << "Valor no encontrado" << endl;

    return 0;
}
