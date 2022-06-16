#include<iostream>
#include"videojuego.h"
#include"personaje.h"
#include"buscar.h"
#include"burbuja.h"
#include"seleccion.h"

using namespace std;

int menu();

int main()
{
    Videojuego videojuego;
    Personaje personaje;
    string input, nombreArchivo;
    size_t posicion;
    int opcion;
    char res;
    bool salir = false;

    while(!salir)
    {
        opcion = menu();
        switch(opcion)
        {
            case 0:
                cout << "Segur@ que quieres salir?...\n[s/n] ";
                cin >> res; cin.ignore();
                
                if(res == 'S' || res == 's')
                    salir = true;

            break;

            case 1:
                cin >> personaje;
                videojuego.insertarInicio(personaje);

            break;

            case 2:
                cin >> personaje;
                videojuego.insertarFinal(personaje);

            break;

            case 3:
                cout << "Ingresa la posicion: ";
                cin >> posicion; cin.ignore();
                cin >> personaje;
                videojuego.insertar(personaje, posicion);

            break;

            case 4:
                cout << "Segur@ que quieres eliminar al inicio?...\n[s/n] ";
                cin >> res; cin.ignore();

                if(res == 'S' || res == 's')
                    videojuego.eliminarInicio();
                else
                    cout << "Operacion cancelada" << endl;

            break;

            case 5:
                cout << "Segur@ que quieres eliminar al final?...\n[s/n] ";
                cin >> res; cin.ignore();

                if(res == 'S' || res == 's')
                    videojuego.eliminarFinal();
                else
                    cout << "Operacion cancelada" << endl;
            break;

            case 6:
                cout << "Ingresa la posicion: ";
                cin >> posicion; cin.ignore();
                cout << "Segur@ que quieres eliminar en la posicion " << posicion << "?...\n[s/n] ";
                cin >> res; cin.ignore();

                if(res == 'S' || res == 's')
                    videojuego.eliminar(posicion);
                else
                    cout << "Operacion cancelada" << endl;

            break;

            case 7:
                videojuego.mostrar();
            break;

            case 8:
                cout << "Segur@ que quieres guardar los datos?...\n[s/n] ";
                cin >> res; cin.ignore();

                if(res == 'S' || res == 's')
                {
                    cout << "Ingresa el nombre del archivo: ";
                    getline(cin, nombreArchivo);
                    videojuego.guardar(nombreArchivo);
                }
                else
                    cout << "Operacion cancelada" << endl;

            break;

            case 9:
                cout << "Segur@ que quieres cargar datos?...\n[s/n] ";
                cin >> res; cin.ignore();

                if(res == 'S' || res == 's')
                {
                    cout << "Ingresa el nombre del archivo: ";
                    getline(cin, nombreArchivo);
                    videojuego.abrir(nombreArchivo);
                }
                else
                    cout << "Operacion cancelada" << endl;
            break;

            case 10:
                buscar(videojuego);
            break;

            case 11:
                buscarTodos(videojuego);
            break;

            case 12:
                if(videojuego.size() > 0)
                    menuBurbuja(videojuego);
                else
                    cout << "Videojuego vacio" << endl << "No se puede ordenar" << endl;
            break;

            case 13:
                if(videojuego.size() > 0)
                    menuSeleccion(videojuego);
                else
                    cout << "Videojuego vacio" << endl << "No se puede ordenar" << endl;
            break;

            default:
                cout << "Opcion " << opcion << " invalida" << endl;
            break;
        }
        cout << "Presiona 'Enter' para continuar..." << endl;
        getline(cin, input);
        system("clear");
    }

    return 0;
}

int menu()
{
    int opcion;

    cout << "0. Salir" << endl;
    cout << "1. Insertar a inicio" << endl;
    cout << "2. Insertar al final" << endl;
    cout << "3. Insertar" << endl;
    cout << "4. Eliminar al inicio" << endl;
    cout << "5. Eliminar al final" << endl;
    cout << "6. Eliminar" << endl;
    cout << "7. Mostrar" << endl;
    cout << "8. Guardar" << endl;
    cout << "9. Abrir" << endl;
    cout << "10. Buscar" << endl;
    cout << "11. Buscar todas las coincidencias" << endl;
    cout << "12. Ordenamiento burbuja" << endl;
    cout << "13. Ordenamiento seleccion" << endl;
    cin >> opcion; cin.ignore();

    return opcion;
}

