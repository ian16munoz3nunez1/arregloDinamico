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
        cout << left;
        cout << '|';
        cout << setw(4) << i+1;
        cout << personajes[i];
        linea();
    }
}

void Videojuego::guardar(const string &nombreArchivo)
{
    ofstream archivo(nombreArchivo);

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

void Videojuego::abrir(const string &nombreArchivo)
{
    ifstream archivo(nombreArchivo);

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
}
void Videojuego::insertarFinal(const Personaje &personaje)
{
    personajes.insertarFinal(personaje);
}
void Videojuego::insertar(const Personaje &personaje, size_t p)
{
    personajes.insertar(personaje, p);
}

void Videojuego::eliminarInicio()
{
    personajes.eliminarInicio();
}
void Videojuego::eliminarFinal()
{
    personajes.eliminarFinal();
}
void Videojuego::eliminar(size_t p)
{
    personajes.eliminar(p);
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
        cout << left;
        linea();
        cabecera();
        linea();
        cout << '|';
        cout << setw(4) << "1";
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
        cout << left;
        linea();
        cabecera();
        linea();
        for(size_t i = 0; i < ptrs.size(); i++)
        {
            cout << '|';
            cout << setw(4) << i+1;
            cout << *ptrs[i];
            linea();
        }
    }
    else
        cout << "Personaje no encontrado" << endl;
}

void Videojuego::printOrdenado(Arreglo<Personaje> &ordenado)
{
    cout << left;
    linea();
    cabecera();
    linea();
    for(size_t i = 0; i < ordenado.size(); i++)
    {
        cout << '|';
        cout << setw(4) << i+1;
        cout << ordenado[i];
        linea();
    }
}

void Videojuego::cabecera()
{
    cout << left;
    cout << '|';
    cout << setw(4) << "No.";
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
    cout << "+----+----------------+----------------+--------+------+" << endl;
}

size_t Videojuego::size()
{
    return personajes.size();
}
