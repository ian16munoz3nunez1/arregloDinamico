#include<iostream>
#include"arreglo.h"
#include"personaje.h"

using namespace std;

int main()
{
    Arreglo<Personaje> personajes;
    Personaje p01("personaje 1", "guerrero", 84.93, 30);
    Personaje p02("personaje 2", "hechizero", 27.93, 90);
    Personaje p03("personaje 3", "sirena", 99.99, 100);
    Personaje p04("personaje 4", "reina", 97.21, 90);
    Personaje p05("personaje 5", "arquero", 16.37, 70);
    Personaje p06("personaje 6", "dragon", 199.99, 150);

    personajes << p02 << p01 << p04 << p03 << p06 << p05;

    for(size_t i = 0; i < personajes.size(); i++)
        cout << personajes[i];

    cout << "-----------------------------------------------" << endl;
    Arreglo<Personaje> burbuja = personajes.burbuja();
    for(size_t i = 0; i < burbuja.size(); i++)
        cout << burbuja[i];

    cout << "-----------------------------------------------" << endl;
    Arreglo<Personaje> seleccion = personajes.seleccion();
    for(size_t i = 0; i < seleccion.size(); i++)
        cout << seleccion[i];

    return 0;
}
