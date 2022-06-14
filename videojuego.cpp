#include"videojuego.h"
#include<fstream>

Videojuego::Videojuego()
{

}

void Videojuego::mostrar()
{
    for(size_t i = 0; i < personajes.size(); i++)
        cout << personajes[i];
}

void Videojuego::guardar()
{
    ofstream archivo("personajes.txt");

    if(archivo.is_open())
    {
        for(size_t i = 0; i < personajes.size(); i++)
        {
            archivo << personajes[i].getNombre() << endl;
            archivo << personajes[i].getTipo() << endl;
            archivo << personajes[i].getFuerza() << endl;
            archivo << personajes[i].getSalud() << endl;
        }

        cout << "DATOS GUARDADOS" << endl;
    }
    else
        cout << "ERROR AL GUARDAR LOS DATOS" << endl;

    archivo.close();
}

void Videojuego::abrir()
{
    ifstream archivo("personajes.txt");

    if(archivo.is_open())
    {
        Personaje personaje;
        string cadena;
        float fuerza;
        int salud;

        while(true)
        {
            getline(archivo, cadena);
            personaje.setNombre(cadena);

            getline(archivo, cadena);
            personaje.setTipo(cadena);

            if(archivo.eof()) break;

            getline(archivo, cadena);
            fuerza = stof(cadena);
            personaje.setFuerza(fuerza);

            getline(archivo, cadena);
            salud = stoi(cadena);
            personaje.setSalud(salud);

            insertarFinal(personaje);
        }

        cout << "DATOS CARGADOS" << endl;
    }
    else
        cout << "ERROR AL CARGAR LOS DATOS" << endl;

    archivo.close();
}

void Videojuego::insertarInicio(const Personaje &personaje)
{
    personajes.insertarInicio(personaje);
    cout << "Personaje insertado al inicio" << endl;
}
void Videojuego::insertarFinal(const Personaje &personaje)
{
    personajes.insertarFinal(personaje);
    cout << "Personaje insertado al final" << endl;
}
void Videojuego::insertar(const Personaje &personaje, size_t p)
{
    personajes.insertar(personaje, p);
    cout << "Personaje insertado en la posicion " << p << endl;
}

void Videojuego::eliminarInicio()
{
    personajes.eliminarInicio();
    cout << "Personaje eliminado al inicio" << endl;
}
void Videojuego::eliminarFinal()
{
    personajes.eliminarFinal();
    cout << "Personaje eliminado al final" << endl;
}
void Videojuego::eliminar(size_t p)
{
    personajes.eliminar(p);
    cout << "Personaje eliminado en la posicion " << p << endl;
}

size_t Videojuego::size()
{
    return personajes.size();
}
