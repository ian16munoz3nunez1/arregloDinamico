#ifndef PERSONAJE_H
#define PERSONAJE_H

#include<iostream>

using namespace std;

class Personaje
{
    string nombre;
    string tipo;
    float fuerza;
    int salud;

public:
    Personaje();
    Personaje(const string&, const string&, float, int);

    void setNombre(const string&);
    void setTipo(const string&);
    void setFuerza(float);
    void setSalud(int);

    string getNombre();
    string getTipo();
    float getFuerza();
    int getSalud();

    friend ostream& operator<<(ostream &out, const Personaje &personaje)
    {
        out << "Nombre: " << personaje.nombre << endl;
        out << "Tipo: " << personaje.tipo << endl;
        out << "Fuerza: " << personaje.fuerza << endl;
        out << "Salud: " << personaje.salud << endl;

        return out;
    }

    friend istream& operator>>(istream &in, Personaje &personaje)
    {
        cout << "Ingresa el nombre del personaje: ";
        getline(in, personaje.nombre);

        cout << "Ingresa el tipo de personaje: ";
        getline(in, personaje.tipo);

        cout << "Ingresa la fuerza del personaje: ";
        in >> personaje.fuerza;

        cout << "Ingresa la salud del personaje: ";
        in >> personaje.salud; in.ignore();

        personaje.mayusculas(personaje.nombre);
        personaje.mayusculas(personaje.tipo);

        return in;
    }

    bool operator==(const Personaje &personaje)
    {
        return this->nombre == personaje.nombre;
    }
    bool operator==(const Personaje &personaje) const
    {
        return this->nombre == personaje.nombre;
    }

    bool operator>(const Personaje &personaje)
    {
        return this->nombre > personaje.nombre;
    }
    bool operator>(const Personaje &personaje) const
    {
        return this->nombre > personaje.nombre;
    }

    bool operator<(const Personaje &personaje)
    {
        return this->nombre < personaje.nombre;
    }
    bool operator<(const Personaje &personaje) const
    {
        return this->nombre < personaje.nombre;
    }

    bool operator>=(const Personaje &personaje)
    {
        return this->nombre >= personaje.nombre;
    }
    bool operator>=(const Personaje &personaje) const
    {
        return this->nombre >= personaje.nombre;
    }

    bool operator<=(const Personaje &personaje)
    {
        return this->nombre <= personaje.nombre;
    }
    bool operator<=(const Personaje &personaje) const
    {
        return this->nombre <= personaje.nombre;
    }

private:
    void mayusculas(string&);
};

#endif//PERSONAJE_H