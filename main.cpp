#include "mainHeader.hpp"


int main()
{
    short int opcion;
    auxAutos auxAutos;
    auxMotos auxMotos;
    auxCamiones auxCamiones;

    std::vector<Vehiculo*> listadoVehiculos;
    
    /*
    listadoVehiculos.push_back(new AutoElectrico("ford", "focus", 1999, 30.9, 5, 0));
    listadoVehiculos.push_back(new Moto("volkswagen", "gol", 2020, 31, 0));
    listadoVehiculos.push_back(new Camion("volkswagen", "gol", 2020, 31, 5));
    mostrarLista(listadoVehiculos);

    opcion!=static_cast<int>(AccionBasica::Terminar)
    opcion!=static_cast<int>(AccionBasica::MostrarYCargar)

    
    */
    opcion=interfaz("Bienvenido al sistema de Gestion de Vehiculos. Seleccione una operacion: \n");
    while(opcion!=AccionBasica::Terminar)
    {
        if(opcion==AccionBasica::Agregar)
        {
            std::cout << "Que clase de vehiculo le gustaria agregar? \n"
            << "1. Auto\n"
            << "2. Moto Electrico\n"
            << "3. Camion\n";
            std::cin >> opcion;

            if(opcion==AccionBasica::Auto)
            {
                std::cout << "Ingrese la marca: \n";
                
            }
            
        }

        if(opcion==AccionBasica::MostrarYCargar)
            mostrarLista(listadoVehiculos);

        opcion=interfaz("Seleccione otra operacion: \n");
    }
    
    limpieza(listadoVehiculos);

    

    
    return 0;
}


