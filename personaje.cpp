#include"personaje.h"

Personaje::Personaje()
{

}

Personaje::Personaje(const string &nombre, const string &tipo, float fuerza, int salud)
{
    this->nombre = nombre;
    this->tipo = tipo;
    this->fuerza = fuerza;
    this->salud = salud;
    mayusculas(this->nombre);
    mayusculas(this->tipo);
}

void Personaje::setNombre(const string &nombre)
{
    this->nombre = nombre;
    mayusculas(this->nombre);
}
void Personaje::setTipo(const string &tipo)
{
    this->tipo = tipo;
    mayusculas(this->tipo);
}
void Personaje::setFuerza(float fuerza)
{
    this->fuerza = fuerza;
}
void Personaje::setSalud(int salud)
{
    this->salud = salud;
}

string Personaje::getNombre()
{
    return this->nombre;
}
string Personaje::getTipo()
{
    return this->tipo;
}
float Personaje::getFuerza()
{
    return this->fuerza;
}
int Personaje::getSalud()
{
    return this->salud;
}

void Personaje::mayusculas(string &cadena)
{
    for(size_t i = 0; i < cadena.length(); i++)
        cadena[i] = toupper(cadena[i]);
}
