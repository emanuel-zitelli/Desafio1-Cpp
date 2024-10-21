#include "mainHeader.hpp"


int main()
{
    short int opcion;
    std::vector<Vehiculo*> listadoVehiculos;
   
   
    opcion=interfaz("Bienvenido al sistema de Gestion de Vehiculos. Seleccione una operacion: \n");
    while(opcion!=AccionBasica::oTerminar)
    {
        //opcion 1, agregar vehiculos
        if(opcion==AccionBasica::oAgregar)
        {
            system("cls");
            std::cout << "Que clase de vehiculo le gustaria agregar? \n"
            << "5. Auto\n"
            << "6. Moto\n"
            << "7. Camion\n";
            std::cin >> opcion;

            if(opcion==AccionBasica::oAuto)
                cargarAuto(listadoVehiculos);
            else if(opcion==AccionBasica::oMoto)
                cargarMoto(listadoVehiculos);
            else if(opcion==AccionBasica::oCamion)
                cargarCamion(listadoVehiculos);
        }
        //opcion 2, mostrar vehiculos (y llamada a metodo cargar)
        if(opcion==AccionBasica::oMostrarYCargar)
            mostrarLista(listadoVehiculos);

        //opcion 3, cargarle kilometros a un auto
        if(opcion==AccionBasica::oCargarKilometraje)
            cargarKilometros(listadoVehiculos);

        opcion=interfaz("Seleccione otra operacion: \n");
    }
    
    
    limpieza(listadoVehiculos);
    
    return 0;
}


