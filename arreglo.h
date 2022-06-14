#ifndef ARREGLO_H
#define ARREGLO_H

#include<iostream>

using namespace std;

template<class I>
class Arreglo
{
    I *arreglo;
    size_t cont;
    size_t tam;
    const static size_t MAX = 5;

public:
    Arreglo();
    ~Arreglo();

    void insertarInicio(const I&);
    void insertarFinal(const I&);
    void insertar(const I&, size_t);

    void eliminarInicio();
    void eliminarFinal();
    void eliminar(size_t);

    size_t size();

    I &operator[](size_t i)
    {
        return arreglo[i];
    }

private:
    void expandir();
};

template<class I>
Arreglo<I>::Arreglo()
{
    arreglo = new I[MAX];
    cont = 0;
    tam = MAX;
}

template<class I>
void Arreglo<I>::insertarInicio(const I &v)
{
    if(cont == tam)
        expandir();

    for(size_t i = cont; i > 0; i--)
        arreglo[i] = arreglo[i-1];

    arreglo[0] = v;
    cont++;
}

template<class I>
void Arreglo<I>::insertarFinal(const I &v)
{
    if(cont == tam)
        expandir();

    arreglo[cont] = v;
    cont++;
}

template<class I>
void Arreglo<I>::insertar(const I &v, size_t p)
{
    if(p-1 <= 0 || p-1 >= cont)
    {
        cout << "Posicion " << p << " no valida" << endl;
        return;
    }

    if(cont == tam)
        expandir();

    for(size_t i = cont; i > p-1; i--)
        arreglo[i] = arreglo[i-1];

    arreglo[p-1] = v;
    cont++;
}

template<class I>
void Arreglo<I>::eliminarInicio()
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

template<class I>
void Arreglo<I>::eliminarFinal()
{
    if(cont == 0)
    {
        cout << "Arreglo vacio" << endl << "No se puede eliminar al final" << endl;
        return;
    }

    cont--;
}

template<class I>
void Arreglo<I>::eliminar(size_t p)
{
    if(cont == 0)
    {
        cout << "Arreglo vacio" << endl << "No se puede eliminar" << endl;
        return;
    }

    if(p-1 <= 0 || p-1 >= cont)
    {
        cout << "Posicion " << p << " no valida" << endl;
        return;
    }

    for(size_t i = p-1; i < cont-1; i++)
        arreglo[i] = arreglo[i+1];

    cont--;
}

template<class I>
size_t Arreglo<I>::size()
{
    return cont;
}

template<class I>
void Arreglo<I>::expandir()
{
    I *nuevo = new I[tam + MAX];

    for(size_t i = 0; i < cont; i++)
        nuevo[i] = arreglo[i];

    delete[] arreglo;
    arreglo = nuevo;
    tam += MAX;
}

template<class I>
Arreglo<I>::~Arreglo()
{
    delete[] arreglo;
}

#endif//ARREGLO_H