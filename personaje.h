#ifndef PERSONAJE_H
#define PERSONAJE_H

#include<iostream>
#include<iomanip>

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
        out << left;
        out << '|';
        out << setw(16) << personaje.nombre;
        out << '|';
        out << setw(16) << personaje.tipo;
        out << '|';
        out << setw(8) << personaje.fuerza;
        out << '|';
        out << setw(6) << personaje.salud;
        out << '|' << endl;

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
