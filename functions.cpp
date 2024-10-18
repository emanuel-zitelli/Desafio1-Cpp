#include "mainHeader.hpp"


double validarCarga(double bateriaNueva, double bateriaActual)
{
    try
        {
            std::cout << "Ingrese el porcentaje de bateria que quiere cargar: ";
            std::cin >> bateriaNueva;

            if(std::cin.fail())
            {
                throw std::invalid_argument("Solo se pueden ingresar numeros.\n");
                std::cin.clear();
            }
                
            if(bateriaNueva<0 || bateriaNueva>100)
                throw std::out_of_range("La bateria no puede ser menor a 0 o mayor a 100\n");

            return bateriaNueva;
        }
        catch(const std::invalid_argument& exception)
        {
            std::cout << exception.what();
            return -1;
        }
        catch(const std::out_of_range& exception)
        {
            std::cout << exception.what();
            return -1;
        }
}

short int interfaz(std::string frase)
{
    short int opcion;

    std::cout << frase;

    std::cout << "1. Agregar \n"
    << "2. Mostrar y Cargar Bateria \n"
    << "3. Finalizar \n"; 

    std::cin >> opcion;
    std::cin.ignore(); //porque sino el enter llena el nombre, porque queda en el buffer

    return opcion;
    
}

bool mostrarLista(std::vector<Vehiculo*>& lista) //Devuelve un bool para saber si hay vehiculos. Si no hay no quiero habilitar los inputs
{
    if (lista.size() == 0)
    {
        std::cout << "No hay vehiculos ingresados\n";
        return false;
    }
    else
    {
        std::cout << "\nLista de Vehiculos:" << "\n";
        for (int i = 0; i < lista.size(); i++) 
        {
            Vehiculo* vehiculo = lista[i];

            // Verificar si el vehículo es eléctrico usando dynamic_cast
            if (Electricidad* vehiculoElectrico = dynamic_cast<Electricidad*>(vehiculo)) //Se cumple la condicion con un puntero no nulo
            {
                //Se cumple la condicion si vehiculo (puntero del elemento i) es un tipo de puntero Electricidad (un puntero derivado)
                std::cout << "(El siguiente vehiculo es electrico:)\n";
            }

            // Mostrar la información del vehículo
            (*vehiculo).mostrarInfo();
            std::cout << "\n";
        }
        return true;
    }
}

void limpieza(std::vector<Vehiculo*>& lista) //para liberar la memoria. De paso limpiamos los punteros que no apuntan a nada
{
    for (size_t i = 0; i < lista.size(); ++i) 
    {
        delete lista[i];  // Libera la memoria de cada objeto
        lista[i] = nullptr;  // Establece el puntero en nullptr
    }
    std::cout << "Memoria Liberada. Finalizando programa.";
}
