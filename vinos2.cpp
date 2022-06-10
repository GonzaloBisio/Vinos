#include <iostream>
#include <fstream>
#include <array>
#include <chrono>
#include <thread>

using namespace std::chrono;
using namespace std;

struct Vino
{
    int codigo;
    string marca;
    string nombre;
    int cantidades;
    string tipo;
    int precio;
    int dia;
    int mes;
    int anio;
    string NombreProveedor;
    int NumeroProveedor;
    int DNIProveedor;
};

int main()
{
    Vino AlmaMora{1, "Malbec", "Alma Mora", 1493, "Tinto", 615, 18, 6, 1992};
    Vino Portillo{2, "Malbec", "Portillo", 2042, "Tinto", 615, 18, 6, 1998};
    Vino Colón{3, "Malbec", "Colón", 3453, "Tinto", 300, 21, 4, 1968};
    Vino Dada{4, "Malbec", "Dada", 2342, "Tinto", 554, 18, 9, 1984};
    Vino Elementos{5, "Torrentes", "Elementos", 1042, "Blanco", 615, 18, 6, 1998};
    Vino SantaJulia{6, "Chenin", "Santa Julia", 562, "Blanco", 820, 25, 6, 2012};
    Vino Fuzion{7, "Sweet", "Fuzion", 550, "Blanco", 800, 25, 6, 2012};
    Vino Emilia{8, "Red Blend", "Emilia", 562, "Rosado", 650, 15, 9, 2000};
    Vino Rose{9, "La Celia", "Rose", 403, "Rosado", 950, 17, 6, 2012};
    Vino Aime{10, "Red Blend", "Aime", 1023, "Rosado", 820, 25, 6, 2012};

    Vino datos[100] = {AlmaMora, Portillo, Colón, Dada, Elementos, SantaJulia, Fuzion, Emilia, Rose, Aime};
    int contador = 9;
    int codigos = contador + 1;

    string eleccion = "";
    // Hacer el ciclo
    while (eleccion != "2")
    {
        // Imprimir los artículos
        cout << "____________" << endl;
        for (int i = 0; i <= contador; i++)
        {
            // Imprimir el número para que el usuario pueda seleccionar el artículo
            cout << "Número: " << i + 1 << endl;
            cout << "Artículo: " << datos[i].nombre << endl;
            cout << "Costo: " << datos[i].precio << endl;
            cout << "____________" << endl;
        }
        // Imprimir el menú principal
        cout << "1. Comprar artículo\n2. Salir\n3. Opciones de administrador\n Seleccione:\n ";
        // Leer lo que el usuario elija
        cin >> eleccion;
        // Si elige 1, entonces solicitar número de artículo y cantidad
        if (eleccion == "1")
        {
            int numeroArticulo;
            cout << "Ingrese el número de artículo: ";
            cin >> numeroArticulo;
            // Necesitamos el índice del arreglo, que sería restarle 1 al número que elige el usuario pues los arreglos comienzan a contar en 0
            int indice = numeroArticulo - 1;
            // Validamos si el número de artículo está entre 0 y 9
            if (indice >= 0 && indice <= 9)
            {
                // Solicitamos cantidad
                int cantidad;
                cout << "Ingrese la cantidad que compra: ";
                cin >> cantidad;
                // Validar si la cantidad es correcta
                if (cantidad > datos[indice].cantidades)
                {
                    cout << "\nNo hay suficiente existencia\n" << endl;
                    std::this_thread::sleep_for(2000ms);
                }
                else
                {
                    // En caso de que sí haya suficiente existencia, extraemos el costo
                    double costo = datos[indice].precio;
                    // Sacamos el costo total
                    double total = costo * cantidad;
                    // Imprimimos
                    cout << "========================================" << endl;
                    cout << "Usted ha comprado " << datos[indice].nombre << " X " << cantidad << endl;
                    cout << "Total: " << total << endl;
                    cout << "GRACIAS POR SU COMPRA" << endl;
                    cout << "========================================" << endl;
                    // Y restamos la cantidad en el arreglo
                    datos[indice].cantidades = datos[indice].cantidades - cantidad;
                    std::this_thread::sleep_for(2000ms);
                }
            }
            else
            {
                // Caso contrario, imprimimos que no es un artículo válido
                cout << "Número de artículo " << numeroArticulo << " inválido" << endl;
            }
        }
        if (eleccion == "3")
        {
            int opcion;
            cout << endl
                 << "1. Agregar Producto\n2. Quitar producto\n3. Salir\n Seleccione: ";
            cin >> opcion;
            switch (opcion)
            {
            case 1:
                bool repetido = false;
                string txt;
                cout << endl
                     << "Listado de vinos: " << endl
                     << endl;
                for (int i = 0; i < contador; i++)
                {
                    cout << datos[i].nombre << endl;
                    cout << "____________" << endl;
                }
                contador++;
                datos[contador].codigo = codigos;
                cout << "Igrese los datos solicitados:" << endl;
                cout << "Nombre: " << endl;
                cin >> txt;
                for (int i = 0; i < contador; i++)
                {
                    if (datos[i].nombre == txt)
                {
                    cout <<"Un vino con ese nombre ya ha sido registrado en el sistema."<<endl;
                    repetido = true;
                    std::this_thread::sleep_for(1000ms);
                    cout<<"Vuelva a ingresar un valor: "<<endl;
                    std::this_thread::sleep_for(1500ms);
                }
                }
                if (repetido = false)
                {
                    
                }
                else{
                    
                }
                cout<<repetido;
                break;

            /*case 2:
                cout << endl
                     << "Listado de vinos: " << endl
                     << endl;
                for (int i = 0; i < contador; i++)
                {
                    cout << datos[i].nombre << endl;
                    cout << "____________" << endl;
                }
                string rm;
                cout << "Seleccione el nombre del vino a remover: " << endl;
                cin >> rm;
                for (int i = 0; i <= contador; i++)
                {
                    if (datos[i].nombre == rm)
                    {
                    }
                }
                break;*/

            }
        }
    }
}