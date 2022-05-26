#include <iostream>
#include <fstream>
#include <array>
using namespace std;

int main()
{

    /*
    // define array of strings
    string vehiclesList[10] = {"value0", "value1", "value2", "value3", "value4", "value5", "value6", "value7", "value8", "value9"};
    // get array size
    int arraySize = *(&vehiclesList + 1) - vehiclesList;
    // exception handling
    try
    {
        cout << "\nWriting  array contents to file...";
        // open file for writing
        ofstream fw("Valores.txt", std::ofstream::out);
        // check if file was successfully opened for writing
        if (fw.is_open())
        {
            // store array contents to text file
            for (int i = 0; i < arraySize; i++)
            {
                fw << vehiclesList[i] << "\n";
            }
            fw.close();
        }
        else
            cout << "Problem with opening file";
    }
    catch (const char *msg)
    {
        cerr << msg << endl;
    }
    cout << "\nDone!";
    cout << "\nPress any key to exit...";
     Creación de archivos .txt
    std::ofstream { "Productos.txt" };
    // Productos.txt has been created here

    std::ofstream { "Teléfono Proveedor.txt" };
    // Teléfono Proveedor.txt has been created here

    std::ofstream { "Total Productos.txt" };
    // Teléfono Proveedor.txt has been created here
    */

    // Declaramos los arreglos, uno por cada columna de la tabla
    // Primero los codigos
    int codigo[10]{
        1,2,3,4,5,6,7,8,9,10
    };
    // Declaramos los nombres
    array<string, 10> nombres = {
        "Alma mora",
        "Portillo",
        "Colón",
        "Dadá",
        "Elementos",
        "Santa Julia",
        "Fuzion",
        "Emilia",
        "Rosé",
        "Aimé"
        };
    // Declaramos las Marcas
    array<string, 10> marcas = {
        "Malbec",
        "Malbec",
        "Malbec",
        "Malbec",
        "Torrontes",
        "Chenin",
        "Sweet",
        "Red Blend",
        "La Celia"
        "Red Blend"
    };
    // Declaramos las canitdades
    array<int, 10> cantidades = {
        150, 100, 2, 10, 25, 120, 45, 50, 21, 80
    };

    //Declaramos tipo de vino
    array<string, 3> tipo = {
        "Tinto",
        "Blanco",
        "Rosé"
    };

    //Declaramos precios
    array<int, 10> precio = {
        615, 550, 300, 583, 553, 585, 830, 737, 735, 451
    };




    // Mientras que la elección del usuario no sea "2" que es para salir...
    string eleccion = "";
    // Hacer el ciclo
    while (eleccion != "2")
    {
        // Imprimir los artículos
        cout << "____________" << endl;
        for (int i = 0; i < 10; i++)
        {
            // Imprimir el número para que el usuario pueda seleccionar el artículo
            cout << "Número: " << i + 1 << endl;
            cout << "Artículo: " << nombres[i] << endl;
            cout << "Costo: " << precio[i] << endl;
            cout << "Cantidad: " << cantidades[i] << endl;
            cout << "____________" << endl;
        }
        // Imprimir el menú principal
        cout << "1. Comprar artículo\n2. Salir\nSeleccione: ";
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
            // Validamos si el número de artículo está entre 0 y 3
            if (indice >= 0 && indice <= 9)
            {
                // Solicitamos cantidad
                int cantidad;
                cout << "Ingrese la cantidad que compra: ";
                cin >> cantidad;
                // Validar si la cantidad es correcta
                if (cantidad > cantidades[indice])
                {
                    cout << "No hay suficiente existencia" << endl;
                }
                else
                {
                    // En caso de que sí haya suficiente existencia, extraemos el costo
                    double costo = precio[indice];
                    // Sacamos el costo total
                    double total = costo * cantidad;
                    // Imprimimos
                    cout << "========================================" << endl;
                    cout << "Usted ha comprado " << nombres[indice] << " X " << cantidad << endl;
                    cout << "Total: " << total << endl;
                    cout << "GRACIAS POR SU COMPRA" << endl;
                    cout << "========================================" << endl;
                    // Y restamos la cantidad en el arreglo
                    cantidades[indice] = cantidades[indice] - cantidad;
                }
            }
            else
            {
                // Caso contrario, imprimimos que no es un artículo válido
                cout << "Número de artículo " << numeroArticulo << " inválido" << endl;
            }
        }
    }
}
