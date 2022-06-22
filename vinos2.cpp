#include <iostream>
#include <fstream>
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

struct Ingreso
{
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
    string codigo;
    string marca;
    string nombre;
    int cantidades;
    string tipo;
    int precio;
    Fecha fecha;
    Ingreso ingreso;
    Proveedor proveedor;
    bool existe;
    int venta = precio + (precio * 0.15);
};

string busquedaNombre()
{
    string nombre;
    while (true)
    {
        cin >> nombre;
        if (nombre.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ") ==
            std::string::npos)
        {
            return nombre;
            break;
        }
        cout << "Por favor ingrese un nombre sin numeros ni caracteres especiales: " << endl;
    }
}

string codeIngreso()
{
    string cod;
    while (true)
    {
        cin >> cod;
        if (cod.find_first_not_of("1") == std::string::npos)
        {
            return cod;
            break;
        }
        cout << "Por favor ingrese un codigo contemplado en el stock: " << endl;
    }
}

int mesIngreso()
{
    int mes;
    while (true)
    {
        cin >> mes;
        if (mes <= 12 && mes >= 0)
        {
            return mes;
            break;
        }
        cout << "Ingrese un mes del 1 al 12" << endl;
    }
}

int anioIngreso()
{
    int anio;
    while (true)
    {
        cin >> anio;
        if (anio < 2022 && anio > 2000)
        {
            return anio;
            break;
        }
        cout << "Ingrese un anio del 2000 al 2022" << endl;
    }
}

int integerPositivo(){
    int p;
    while (true)
    {
        cin >>p;
        if (p>=0)
        {
            return p;
            break;
        }
        cout<<" Ingrese un valor positvio porfavor "<<endl;
    }
    
}

int main()
{

    Vino datos[50];

    datos[0] = {"1", "Malbec", "Alma Mora", 1493, "Tinto", 615, {18, 7, 2012}, {12, 2015}, {"Antonio", "3515083581", "44195188"}, true};
    datos[1] = {"2", "Malbec", "Portillo", 2042, "Tinto", 615, {18, 7, 2012}, {12, 2015}, {"Rodrigo", "3515083581", "44195188"}, true};
    datos[2] = {"3", "Malbec", "Colón", 3453, "Tinto", 300, {18, 7, 2012}, {12, 2015}, {"Juan", "3515083581", "44195188"}, true};
    datos[3] = {"4", "Malbec", "Dada", 2342, "Tinto", 554, {18, 7, 2012}, {12, 2015}, {"Beto", "3515083581", "44195188"}, true};
    datos[4] = {"5", "Torrentes", "Elementos", 1042, "Blanco", 615, {18, 7, 2012}, {12, 2015}, {"Lucas", "3515083581", "44195188"}, true};
    datos[5] = {"6", "Chenin", "Santa Julia", 562, "Blanco", 820, {18, 7, 2012}, {12, 2015}, {"Jose", "3515083581", "44195188"}, true};
    datos[6] = {"7", "Sweet", "Fuzion", 550, "Blanco", 800, {18, 7, 2012}, {12, 2015}, {"Jose", "3515083581", "44195188"}, true};
    datos[7] = {"8", "Red Blend", "Emilia", 562, "Rosado", 650, {18, 7, 2012}, {12, 2015}, {"Rodrigo", "3515083581", "44195188"}, true};
    datos[8] = {"9", "La Celia", "Rose", 403, "Rosado", 950, {18, 7, 2012}, {12, 2015}, {"Manuel", "3515083581", "44195188"}, true};
    datos[9] = {"10", "Red Blend", "Aime", 1023, "Rosado", 820, {18, 7, 2012}, {12, 2015}, {"Mariano", "3515083581", "44195188"}, true};

    int contador = 9;
    int codigos = contador + 1;

    string eleccion = "";
    // Hacer el ciclo
    while (eleccion != "8")
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
        cout << "1. Comprar artículo\n2. Búsqueda por proveedor\n3. Búsqueda por nombre \n4. Impresion de productos \n5. Impresion de proveedores \n6. Total de productos \n7. Opciones de administrador\n8. Salir\n \nSeleccione:\n ";
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
            bool x = true;
            cout << "Ingrese el nombre del proveedor" << endl;
            prov = busquedaNombre();
            for (int i = 0; i <= contador; i++)
            {
                if (datos[i].proveedor.nombre == prov)
                {
                    cout << datos[i].nombre << endl;
                    cout << "____________" << endl;
                    x = false;
                }
            }
            if (x = true)
            {
                cout<<"Ningun proveedor registrado a ese nombre" <<endl;
            }
            
            std::this_thread::sleep_for(1500ms);
        }
        if (eleccion == "3")
        {
            cout << "Ingrese el nombre del vino" << endl;
            string n = busquedaNombre();
            for (int i = 0; i <= contador; i++)
            {
                if (datos[i].nombre == n)
                {
                    cout << "\nMarca: " << datos[i].marca << endl;
                    cout << "Nombre: " << datos[i].nombre << endl;
                    cout << "Cantidad en stock: " << datos[i].cantidades << endl;
                    cout << datos[i].tipo << endl;
                    cout << "Precio: " << datos[i].precio << endl;
                    cout << "____________" << endl;
                }
            }
            std::this_thread::sleep_for(3500ms);
        }

        if (eleccion == "4")
        {
            string c;
            cout << "\nVinos catalogados:\n " << endl;
            for (int i = 0; i <= contador; i++)
            {
                cout << datos[i].codigo << " (" << datos[i].nombre << ") " << endl;
                cout << "_____________________" << endl;
            }
            cout << "Ingrese el codigo del vino: " << endl;
            cin >> c;
            for (int i = 0; i <= contador; i++)
            {
                if (datos[i].codigo == c)
                {
                    ofstream fw("Impresión de producto.txt", std::ofstream::out);
                    if (fw.is_open())
                    {
                        fw << "Impresion del vino codigo: " << datos[i].codigo << endl;
                        fw << "Nombre: " << datos[i].nombre << "\n";
                        fw << "Marca: " << datos[i].marca << "\n";
                        fw << "Tipo: " << datos[i].tipo << "\n";
                        fw << "Precio de venta: " << datos[i].precio << "\n";
                        fw << "Fecha de Ingreso: " << datos[i].ingreso.mes << "/" << datos[i].ingreso.anio << "\n";
                        fw << "Cantidad en stock: " << datos[i].cantidades << "\n";

                        cout << "\nDatos impresos!" << endl;
                        std::this_thread::sleep_for(2500ms);
                        fw.close();
                    }
                    else
                        cout << "Hubo un problema al abrir el archivo";
                };
            }
        }

        if (eleccion == "5")
        {
            string p;
            cout << "\nProveedores catalogados:\n " << endl;
            for (int i = 0; i <= contador; i++)
            {
                cout << datos[i].proveedor.nombre << " (" << datos[i].nombre << ") " << endl;
                cout << "_____________________" << endl;
            }

            cout << "Ingrese el nombre del proveedor" << endl;
            cin >> p;
            for (int i = 0; i <= contador; i++)
            {
                if (datos[i].proveedor.nombre == p)
                {
                    ofstream fw("Datos proveedor.txt", std::ofstream::out);
                    if (fw.is_open())
                    {
                        fw << "Impresion del proveedor: " << datos[i].proveedor.nombre << endl;
                        fw << "Nombre: " << datos[i].proveedor.nombre << "\n";
                        fw << "Número de teléfono: " << datos[i].proveedor.numero << "\n";
                        fw << "Número de DNI: " << datos[i].proveedor.dni << "\n";
                        fw.close();

                        cout << "\nDatos impresos!" << endl;
                        std::this_thread::sleep_for(2500ms);
                    }
                    else
                        cout << "Hubo un problema al abrir el archivo";
                }
            }
        }

        if (eleccion == "6")
        {
            int suma;
            cout << "Generando archivo de suma de productos...";
            ofstream fw("Productos.txt", std::ofstream::out);

            for (int i = 0; i < contador; i++)
            {
                if (datos[i].existe)
                {
                    if (fw.is_open())
                    {
                        fw << "Impresion del vino codigo: " << datos[i].codigo << endl;
                        fw << "Nombre: " << datos[i].nombre << "\n";
                        fw << "Marca: " << datos[i].marca << "\n";
                        fw << "Tipo: " << datos[i].tipo << "\n";
                        fw << "Precio de venta: " << datos[i].venta << "\n";
                        fw << "Cantidad en stock: " << datos[i].cantidades << "\n";
                        fw << "______________________________" << endl;
                        suma += datos[i].venta;
                    }
                    else
                        cout << "Hubo un problema al abrir el archivo";
                };
            }
            fw << "La suma de precio de los vinos es: " << suma << endl;

            cout << "\nDatos impresos!" << endl;
            std::this_thread::sleep_for(2500ms);
        }

        if (eleccion == "7")
        {
            string rm;
            bool repetido = false;
            string nombre_ingresado;
            string marca_ingresada;
            int cantidad_ingresada;
            int precio_ingresado;
            bool estado = true;
            int i = 0;
            int x;
            int y;

            int opcion;
            string c;
            int p;
            cout << endl
                 << "_________________________________________"
                 << "\n1. Agregar Producto\n2. Quitar producto\n3. Modificar Precio \n4. Modificar fecha de ingreso\n5. Salir \nSeleccione: " << endl;
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

                cout << "Igrese los datos solicitados:" << endl;
                cout << "Nombre: " << endl;
                nombre_ingresado = busquedaNombre();

                while (estado)
                {
                    if (datos[i].nombre == nombre_ingresado && datos[i].existe)
                    {
                        cout << "Un vino con ese nombre ya ha sido registrado en el sistema." << endl;
                        std::this_thread::sleep_for(1000ms);
                        cout << "Vuelva a ingresar un valor: " << endl;
                        cin >> nombre_ingresado;
                        std::this_thread::sleep_for(1500ms);
                        i = 0;
                    }
                    else
                    {
                        datos[i].nombre = nombre_ingresado;

                        cout << "Marca: " << endl;
                        marca_ingresada = busquedaNombre();
                        datos[i].marca = marca_ingresada;

                        cout << "Precio: " << endl;
                        precio_ingresado = integerPositivo();
                        datos[i].precio = precio_ingresado;

                        cout << "Cantidad: " << endl;
                        cantidad_ingresada = integerPositivo();
                        datos[i].cantidades = cantidad_ingresada;

                        datos[i].existe = true;
                        contador++;
                        estado = false;
                    }
                    i++;
                }

                break;

            case 2:

                cout << endl
                     << "Listado de vinos: " << endl
                     << endl;
                for (int i = 0; i <= contador; i++)
                {
                    if (datos[i].existe)
                    {
                        cout << datos[i].nombre << endl;
                        cout << "____________" << endl;
                    }
                }

                cout << "Seleccione el nombre del vino a remover: " << endl;
                rm = busquedaNombre();
                for (int i = 0; i <= contador; i++)
                {
                    if (datos[i].nombre == rm)
                    {
                        datos[i].existe = false;
                        cout << "Vino " << datos[i].nombre << " excluído de stock" << endl;
                        std::this_thread::sleep_for(1500ms);
                    }
                }
                break;

            case 3:
                cout << "Ingrese el código del producto: " << endl;
                c = codeIngreso();
                for (int i = 0; i <= contador; i++)
                {
                    if (datos[i].codigo == c)
                    {
                        cout << "Precio actual del vino " << datos[i].nombre << ": " << datos[i].precio << endl;
                        cout << "Ingrese el nuevo precio: " << endl;
                        cin >> p;
                        datos[i].precio = p;
                        cout << "Nuevo precio del vino " << datos[i].nombre << " , " << datos[i].precio << endl;
                        std::this_thread::sleep_for(3000ms);
                    }
                }
                break;

            case 4:
                cout << "Ingrese el codigo del vino a modificar su fecha de ingreso: " << endl;
                cin >> c;

                for (int i = 0; i <= contador; i++)
                {
                    if (datos[i].codigo == c)
                    {
                        cout << "Fecha de ingreso al supermercado de " << datos[i].nombre << "\nMes de ingreso: " << datos[i].ingreso.mes << "\nAño: " << datos[i].ingreso.anio << endl;
                        cout << "Ingrese la nueva fecha de ingreso: " << endl;
                        cout << "Mes de ingreso: " << endl;
                        x = mesIngreso();
                        cout << "Año de ingreso: " << endl;
                        y = anioIngreso();
                        datos[i].ingreso.mes = x;
                        datos[i].ingreso.anio = y;
                        cout << "Nueva fecha de ingreso del vino " << datos[i].nombre << ": " << datos[i].ingreso.mes << "/" << datos[i].ingreso.anio << endl;
                        std::this_thread::sleep_for(3000ms);
                    }
                }
            }
        }
    }
}
