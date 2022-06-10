#include <iostream>
#include <fstream>
#include <array>
#include <chrono>
#include <thread>

using namespace std::chrono;
using namespace std;

struct Fecha
{
    int dia;
    int mes;
    int anio;
};

struct Proveedor
{
    string nombre;
    string numero;
    string dni;
};

struct Vino
{
    int codigo;
    string marca;
    string nombre;
    int cantidades;
    string tipo;
    int precio;
    Fecha fecha;
    Proveedor proveedor;
    bool existe = true;
};

int main()
{
    Vino datos[100];

    datos[0] = {1, "Malbec", "Alma Mora", 1493, "Tinto", 615, {18, 7, 2012}, {"Antonio", "3515083581", "44195188"}};
    datos[1] = {2, "Malbec", "Portillo", 2042, "Tinto", 615, {18, 7, 2012}, {"Rodrigo", "3515083581", "44195188"}};
    datos[2] = {3, "Malbec", "Colón", 3453, "Tinto", 300, {18, 7, 2012}, {"Juan", "3515083581", "44195188"}};
    datos[3] = {4, "Malbec", "Dada", 2342, "Tinto", 554, {18, 7, 2012}, {"Beto", "3515083581", "44195188"}};
    datos[4] = {5, "Torrentes", "Elementos", 1042, "Blanco", 615, {18, 7, 2012}, {"Lucas", "3515083581", "44195188"}};
    datos[5] = {6, "Chenin", "Santa Julia", 562, "Blanco", 820, {18, 7, 2012}, {"Jose", "3515083581", "44195188"}};
    datos[6] = {7, "Sweet", "Fuzion", 550, "Blanco", 800, {18, 7, 2012}, {"Jose", "3515083581", "44195188"}};
    datos[7] = {8, "Red Blend", "Emilia", 562, "Rosado", 650, {18, 7, 2012}, {"Rodrigo", "3515083581", "44195188"}};
    datos[8] = {9, "La Celia", "Rose", 403, "Rosado", 950, {18, 7, 2012}, {"Manuel", "3515083581", "44195188"}};
    datos[9] = {10, "Red Blend", "Aime", 1023, "Rosado", 820, {18, 7, 2012}, {"Mariano", "3515083581", "44195188"}};

    int contador = 9;
    int codigos = contador + 1;

    string eleccion = "";
    // Hacer el ciclo
    while (eleccion != "5")
    {
        // Imprimir los artículos
        cout << "____________" << endl;
        for (int i = 0; i <= contador; i++)
        {
            if (datos[i].existe)
            {
                // Imprimir el número para que el usuario pueda seleccionar el artículo
                cout << "Número: " << i + 1 << endl;
                cout << "Artículo: " << datos[i].nombre << endl;
                cout << "Costo: " << datos[i].precio << endl;
                cout << "____________" << endl;
            }
        }
        // Imprimir el menú principal
        cout << "1. Comprar artículo\n2. Búsqueda por proveedor\n3. Búsqueda por nombre \n4. Opciones de administrador\n5. Salir\n Seleccione:\n ";
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
                    cout << "\nNo hay suficiente existencia\n"
                         << endl;
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
                std::this_thread::sleep_for(2500ms);
            }
        }
        if (eleccion == "2")
        {
            string prov;
            cout << "Ingrese el nombre del proveedor"<<endl;
            cin>>prov;
            for (int i = 0; i <= contador; i++)
            {
                if (datos[i].proveedor.nombre == prov)
                {
                    cout<<datos[i].nombre<<endl;
                    cout << "____________" << endl;
                }
            }
            std::this_thread::sleep_for(2500ms);
        }
        if (eleccion == "3")
        {
            cout << "Ingrese el nombre del vino";
            cout << endl
                 << "Listado de vinos: " << endl
                 << endl;
            for (int i = 0; i <= contador; i++)
            {
                cout << datos[i].nombre << endl;
                cout << "____________" << endl;
            }
        }

        if (eleccion == "4")
        {
            string rm;
            bool repetido = false;
            string txt;
            int opcion;
            cout << endl
                 << "1. Agregar Producto\n2. Quitar producto\n3. Salir\n Seleccione: ";
            cin >> opcion;
            switch (opcion)
            {
            case 1:
                cout << endl
                     << "Listado de vinos: " << endl
                     << endl;
                for (int i = 0; i <= contador; i++)
                {
                    cout << datos[i].nombre << endl;
                    cout << "____________" << endl;
                }
                contador++;
                datos[contador].codigo = codigos;
                cout << "Igrese los datos solicitados:" << endl;
                cout << "Nombre: " << endl;
                cin >> txt;
                for (int i = 0; i <= contador; i++)
                {
                    if (datos[i].nombre == txt)
                    {
                        cout << "Un vino con ese nombre ya ha sido registrado en el sistema." << endl;
                        repetido = true;
                        std::this_thread::sleep_for(1000ms);
                        cout << "Vuelva a ingresar un valor: " << endl;
                        std::this_thread::sleep_for(1500ms);
                    }
                }
                cout << repetido;
                break;

            case 2:
                cout << endl
                     << "Listado de vinos: " << endl
                     << endl;
                for (int i = 0; i <= contador; i++)
                {
                    cout << datos[i].nombre << endl;
                    cout << "____________" << endl;
                }
                cout << "Seleccione el nombre del vino a remover: " << endl;
                cin >> rm;
                for (int i = 0; i <= contador; i++)
                {
                    if (datos[i].nombre == rm)
                    {
                        datos[i].existe = false;
                        std::this_thread::sleep_for(1000ms);
                    }
                }
                break;
            }
        }
    }
}
