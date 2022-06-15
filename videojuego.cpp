#include"videojuego.h"
#include<fstream>
#include<iomanip>

Videojuego::Videojuego()
{

}

void Videojuego::mostrar()
{
    linea();
    cabecera();
    linea();
    for(size_t i = 0; i < personajes.size(); i++)
    {
        cout << personajes[i];
        linea();
    }
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

void Videojuego::buscarNombre(const Personaje &personaje)
{
    Personaje *ptr = personajes.buscar(personaje);
    isPtr(ptr);
}
void Videojuego::buscarTipo(const Personaje &personaje)
{
    Personaje *ptr = personajes.buscar(personaje,
        [](Personaje p1, Personaje p2){return p1.getTipo() == p2.getTipo();});
    isPtr(ptr);
}
void Videojuego::buscarFuerza(const Personaje &personaje)
{
    Personaje *ptr = personajes.buscar(personaje,
        [](Personaje p1, Personaje p2){return p1.getFuerza() == p2.getFuerza();});
    isPtr(ptr);
}
void Videojuego::buscarSalud(const Personaje &personaje)
{
    Personaje *ptr = personajes.buscar(personaje,
        [](Personaje p1, Personaje p2){return p1.getSalud() == p2.getSalud();});
    isPtr(ptr);
}

void Videojuego::buscarTodosNombre(const Personaje &personaje)
{
    Arreglo<Personaje*> ptrs = personajes.buscarTodos(personaje);
    isPtrs(ptrs);
}
void Videojuego::buscarTodosTipo(const Personaje &personaje)
{
    Arreglo<Personaje*> ptrs = personajes.buscarTodos(personaje,
        [](Personaje p1, Personaje p2){return p1.getTipo() == p2.getTipo();});
    isPtrs(ptrs);
}
void Videojuego::buscarTodosFuerza(const Personaje &personaje)
{
    Arreglo<Personaje*> ptrs = personajes.buscarTodos(personaje,
        [](Personaje p1, Personaje p2){return p1.getFuerza() == p2.getFuerza();});
    isPtrs(ptrs);
}
void Videojuego::buscarTodosSalud(const Personaje &personaje)
{
    Arreglo<Personaje*> ptrs = personajes.buscarTodos(personaje,
        [](Personaje p1, Personaje p2){return p1.getSalud() == p2.getSalud();});
    isPtrs(ptrs);
}

void Videojuego::ascBurbujaNombre()
{
    Arreglo<Personaje> burbuja = personajes.burbuja();

    printOrdenado(burbuja);
}
void Videojuego::ascBurbujaTipo()
{
    Arreglo<Personaje> burbuja = personajes.burbuja(
        [](Personaje p1, Personaje p2){return p1.getTipo() > p2.getTipo();});

    printOrdenado(burbuja);
}
void Videojuego::ascBurbujaFuerza()
{
    Arreglo<Personaje> burbuja = personajes.burbuja(
        [](Personaje p1, Personaje p2){return p1.getFuerza() > p2.getFuerza();});

    printOrdenado(burbuja);
}
void Videojuego::ascBurbujaSalud()
{
    Arreglo<Personaje> burbuja = personajes.burbuja(
        [](Personaje p1, Personaje p2){return p1.getSalud() > p2.getSalud();});

    printOrdenado(burbuja);
}

void Videojuego::descBurbujaNombre()
{
    Arreglo<Personaje> burbuja = personajes.burbuja(
        [](Personaje p1, Personaje p2){return p1.getNombre() < p2.getNombre();});

    printOrdenado(burbuja);
}
void Videojuego::descBurbujaTipo()
{
    Arreglo<Personaje> burbuja = personajes.burbuja(
        [](Personaje p1, Personaje p2){return p1.getTipo() < p2.getTipo();});

    printOrdenado(burbuja);
}
void Videojuego::descBurbujaFuerza()
{
    Arreglo<Personaje> burbuja = personajes.burbuja(
        [](Personaje p1, Personaje p2){return p1.getFuerza() < p2.getFuerza();});

    printOrdenado(burbuja);
}
void Videojuego::descBurbujaSalud()
{
    Arreglo<Personaje> burbuja = personajes.burbuja(
        [](Personaje p1, Personaje p2){return p1.getSalud() < p2.getSalud();});

    printOrdenado(burbuja);
}

void Videojuego::ascSeleccionNombre()
{
    Arreglo<Personaje> seleccion = personajes.seleccion();

    printOrdenado(seleccion);
}
void Videojuego::ascSeleccionTipo()
{
    Arreglo<Personaje> seleccion = personajes.seleccion(
        [](Personaje p1, Personaje p2){return p1.getTipo() < p2.getTipo();});

    printOrdenado(seleccion);
}
void Videojuego::ascSeleccionFuerza()
{
    Arreglo<Personaje> seleccion = personajes.seleccion(
            [](Personaje p1, Personaje p2){return p1.getFuerza() < p2.getFuerza();});

        printOrdenado(seleccion);
}
void Videojuego::ascSeleccionSalud()
{
    Arreglo<Personaje> seleccion = personajes.seleccion(
        [](Personaje p1, Personaje p2){return p1.getSalud() < p2.getSalud();});

    printOrdenado(seleccion);
}

void Videojuego::descSeleccionNombre()
{
    Arreglo<Personaje> seleccion = personajes.seleccion(
        [](Personaje p1, Personaje p2){return p1.getNombre() > p2.getNombre();});

printOrdenado(seleccion);
}
void Videojuego::descSeleccionTipo()
{
    Arreglo<Personaje> seleccion = personajes.seleccion(
        [](Personaje p1, Personaje p2){return p1.getTipo() > p2.getTipo();});

    printOrdenado(seleccion);
}
void Videojuego::descSeleccionFuerza()
{
    Arreglo<Personaje> seleccion = personajes.seleccion(
        [](Personaje p1, Personaje p2){return p1.getFuerza() > p2.getFuerza();});

    printOrdenado(seleccion);
}
void Videojuego::descSeleccionSalud()
{
    Arreglo<Personaje> seleccion = personajes.seleccion(
        [](Personaje p1, Personaje p2){return p1.getSalud() > p2.getSalud();});

    printOrdenado(seleccion);
}

void Videojuego::isPtr(const Personaje *ptr)
{
    if(ptr != nullptr)
    {
        linea();
        cabecera();
        linea();
        cout << *ptr;
        linea();
    }
    else
        cout << "Personaje no encontrado" << endl;
}

void Videojuego::isPtrs(Arreglo<Personaje*> &ptrs)
{
    if(ptrs.size() > 0)
    {
        linea();
        cabecera();
        linea();
        for(size_t i = 0; i < ptrs.size(); i++)
        {
            cout << *ptrs[i];
            linea();
        }
    }
    else
        cout << "Personaje no encontrado" << endl;
}

void Videojuego::printOrdenado(Arreglo<Personaje> &ordenado)
{
    linea();
    cabecera();
    linea();
    for(size_t i = 0; i < ordenado.size(); i++)
    {
        cout << ordenado[i];
        linea();
    }
}

void Videojuego::cabecera()
{
    cout << left;
    cout << '|';
    cout << setw(16) << "Nombre";
    cout << '|';
    cout << setw(16) << "Tipo";
    cout << '|';
    cout << setw(8) << "Fuerza";
    cout << '|';
    cout << setw(6) << "Salud";
    cout << '|' << endl;
}

void Videojuego::linea()
{
    cout << "+----------------+----------------+--------+------+" << endl;
}

size_t Videojuego::size()
{
    return personajes.size();
}
