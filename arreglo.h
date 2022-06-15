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

    I* buscar(const I&, bool(*)(I, I)=0);
    Arreglo<I*> buscarTodos(const I&, bool(*)(I, I)=0);

    Arreglo<I> burbuja(bool(*)(I, I)=0);
    Arreglo<I> seleccion(bool(*)(I, I)=0);

    size_t size();

    I &operator[](size_t i)
    {
        return arreglo[i];
    }

    friend Arreglo<I>& operator<<(Arreglo<I> &a, const I &v)
    {
        a.insertarFinal(v);

        return a;
    }

private:
    void expandir();
    void intercambio(Arreglo<I>&, size_t, size_t);
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
I* Arreglo<I>::buscar(const I &v, bool(lambda)(I, I))
{
    for(size_t i = 0; i < cont; i++)
    {
        if(lambda == 0)
        {
            if(arreglo[i] == v)
                return &arreglo[i];
        }
        else
        {
            if(lambda(arreglo[i], v))
                return &arreglo[i];
        }
    }

    return nullptr;
}

template<class I>
Arreglo<I*> Arreglo<I>::buscarTodos(const I &v, bool(lambda)(I, I))
{
    Arreglo<I*> ptrs;

    for(size_t i = 0; i < cont; i++)
    {
        if(lambda == 0)
        {
            if(arreglo[i] == v)
                ptrs.insertarFinal(&arreglo[i]);
        }
        else
        {
            if(lambda(arreglo[i], v))
                ptrs.insertarFinal(&arreglo[i]);
        }
    }

    return ptrs;
}

template<class I>
Arreglo<I> Arreglo<I>::burbuja(bool(lambda)(I, I))
{
    Arreglo<I> ordenado;
    for(size_t i = 0; i < cont; i++)
        ordenado.insertarFinal(arreglo[i]);

    for(size_t i = cont-1; i > 0; i--)
    {
        for(size_t j = 0; j < i; j++)
        {
            if(lambda == 0)
            {
                if(ordenado[j] > ordenado[j+1])
                    intercambio(ordenado, j, j+1);
            }
            else
            {
                if(lambda(ordenado[j], ordenado[j+1]))
                    intercambio(ordenado, j, j+1);
            }
        }
    }

    return ordenado;
}

template<class I>
Arreglo<I> Arreglo<I>::seleccion(bool(lambda)(I, I))
{
    Arreglo<I> ordenado;
    for(size_t i = 0; i < cont; i++)
        ordenado.insertarFinal(arreglo[i]);

    for(size_t i = 0; i < cont-1; i++)
    {
        size_t min = i;
        for(size_t j = i+1; j < cont; j++)
        {
            if(lambda == 0)
            {
                if(ordenado[j] < ordenado[min])
                    min = j;
            }
            else
            {
                if(lambda(ordenado[j], ordenado[min]))
                    min = j;
            }
        }
        intercambio(ordenado, i, min);
    }

    return ordenado;
}

template<class I>
void Arreglo<I>::intercambio(Arreglo<I> &ordenado, size_t i, size_t j)
{
    I aux;
    aux = ordenado[i];
    ordenado[i] = ordenado[j];
    ordenado[j] = aux;
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