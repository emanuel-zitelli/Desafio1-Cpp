#include "mainHeader.hpp"

double validarCarga(double bateriaActual)
{
    double bateriaNueva;
    double capacity = (100 - bateriaActual);

    if (capacity == 0)
    {
        std::cout << "Usted no puede cargar mas bateria.\n";
        return 0; 
    }
    else
    {
        try
        {
            std::cout << "Usted no puede cargar mas de " << capacity << "%\n"
                      << "Ingrese el porcentaje de bateria que quiere cargar: ";
            std::cin >> bateriaNueva;

            if (std::cin.fail())
            {
                std::cin.clear(); // Limpia el estado de error de cin, por el dato incorrecto
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //va ignorando hasta llegar a su maximo o al encontrar un salto de linea


                throw std::invalid_argument("Solo se pueden ingresar numeros.\n");
            }

            if (bateriaNueva < 0 || bateriaNueva > capacity)
                throw std::out_of_range("La bateria no puede ser menor a 0 o mayor a la capacidad maxima\n");

            return bateriaNueva;
        }
        catch (const std::invalid_argument &exception)
        {
            std::cout << exception.what();
            return -1;
        }
        catch (const std::out_of_range &exception)
        {
            std::cout << exception.what();
            return -1;
        }
    }
}

short int interfaz(std::string frase)
{
    short int opcion;
    
    std::cout << frase;

    std::cout << "1. Agregar \n"
              << "2. Mostrar y Cargar Bateria \n"
              << "3. Cargar Kilometros \n"
              << "4. Finalizar \n";

    std::cin >> opcion;
    std::cin.ignore(); // porque sino el enter llena el nombre, porque queda en el buffer

    return opcion;
}
void cargarAuto(std::vector<Vehiculo*>& lista)
{   
    auxAutos auxAutos;
    char esElectrico;
    
    system("cls");
    std::cin.ignore();

    std::cout << "Ingrese la marca: ";
    std::getline(std::cin, auxAutos.marca);
    

    std::cout << "Ingrese el modelo: ";
    std::getline(std::cin, auxAutos.modelo);
    

    std::cout << "Ingrese el year del auto: ";
    std::cin >> auxAutos.year;
    

    std::cout << "Ingrese el kilometraje: ";
    std::cin >> auxAutos.kilometraje;

    std::cout << "Ingrese la cantidad de puertas: ";
    std::cin >> auxAutos.cantPuertas;
    

    std::cout << "Es el auto electrico? (Y/N): ";
    std::cin >> esElectrico;
    

    std::tolower(esElectrico);

    if (esElectrico == 'y')
    {
        do
        {
            std::cout << "Ingrese la bateria actual: ";
            std::cin >> auxAutos.bateria;
        } while (auxAutos.bateria<0 || auxAutos.bateria>100);
        
        lista.push_back(new AutoElectrico(auxAutos.marca, auxAutos.modelo, auxAutos.year, auxAutos.kilometraje, auxAutos.cantPuertas, auxAutos.bateria));
    }
    else if (esElectrico == 'n')
    {
        lista.push_back(new Auto(auxAutos.marca, auxAutos.modelo, auxAutos.year, auxAutos.kilometraje, auxAutos.cantPuertas));
    }
    else
        std::cout << "Dato incorrecto. \n";
}
void cargarMoto(std::vector<Vehiculo*>& lista)
{
    auxMotos auxMotos;
    char esElectrico;

    system("cls");
    std::cin.ignore();

    std::cout << "Ingrese la marca: ";
    std::getline(std::cin, auxMotos.marca);

    std::cout << "Ingrese el modelo: ";
    std::getline(std::cin, auxMotos.modelo);

    std::cout << "Ingrese el year del auto: ";
    std::cin >> auxMotos.year;

    std::cout << "Ingrese el kilometraje: ";
    std::cin >> auxMotos.kilometraje;

    std::cout << "Tiene carside? (No:0/ Si:1): ";
    std::cin >> auxMotos.tieneSidecar;

    std::cout << "Es el auto electrico? (Y/N): ";
    std::cin >> esElectrico;
    std::tolower(esElectrico);

    if (esElectrico == 'y')
    {
        do
        {
            std::cout << "Ingrese la bateria actual: ";
            std::cin >> auxMotos.bateria;
        } while (auxMotos.bateria<0 || auxMotos.bateria>100);
        
        lista.push_back(new MotoElectrica(auxMotos.marca, auxMotos.modelo, auxMotos.year, auxMotos.kilometraje, auxMotos.tieneSidecar, auxMotos.bateria));
    }
    else if (esElectrico == 'n')
    {
        lista.push_back(new Moto(auxMotos.marca, auxMotos.modelo, auxMotos.year, auxMotos.kilometraje, auxMotos.tieneSidecar));
    }
    else
        std::cout << "Dato incorrecto. \n";

}

void cargarCamion(std::vector<Vehiculo*>& lista)
{
    auxCamiones auxCamiones;
    char esElectrico;

    system("cls");
    std::cin.ignore();

    std::cout << "Ingrese la marca: ";
    std::getline(std::cin, auxCamiones.marca);

    std::cout << "Ingrese el modelo: ";
    std::getline(std::cin, auxCamiones.modelo);

    std::cout << "Ingrese el year del auto: ";
    std::cin >> auxCamiones.year;
    

    std::cout << "Ingrese el kilometraje: ";
    std::cin >> auxCamiones.kilometraje;
    

    std::cout << "Cuanta es la capacidad de carga? (en kg): ";
    std::cin >> auxCamiones.capacidadCarga;
    std::cin.ignore();
    

    std::cout << "Es el auto electrico? (Y/N): ";
    std::cin >> esElectrico;
    std::tolower(esElectrico);

    if (esElectrico == 'y')
    {
        do
        {
            std::cout << "Ingrese la bateria actual: ";
            std::cin >> auxCamiones.bateria;
        } while (auxCamiones.bateria<0 || auxCamiones.bateria>100);
        
        lista.push_back(new CamionElectrico(auxCamiones.marca, auxCamiones.modelo, auxCamiones.year, auxCamiones.kilometraje, auxCamiones.capacidadCarga, auxCamiones.bateria));
    }
    else if (esElectrico == 'n')
    {
        lista.push_back(new Camion(auxCamiones.marca, auxCamiones.modelo, auxCamiones.year, auxCamiones.kilometraje, auxCamiones.capacidadCarga));
    }
    else
        std::cout << "Dato incorrecto. \n";
}


bool mostrarLista(std::vector<Vehiculo*>& lista) // Devuelve un bool para saber si hay vehiculos. Si no hay no quiero habilitar los inputs
{   
    char quiereRecargar;
    double bateria;

    system("cls");

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
            Electricidad* vehiculoElectrico = dynamic_cast<Electricidad*>(vehiculo); // Verificar si el vehículo es eléctrico usando dynamic_cast

            if (vehiculoElectrico) // Se cumple la condicion con un puntero no nulo, o sea, vehiculo electrico
            {
                // Se cumple la condicion si vehiculo (puntero del elemento i) es un tipo de puntero Electricidad (un puntero derivado)
                std::cout << "El siguiente vehiculo es electrico:\n" << i+1 << ". ";
                
                (*lista[i]).mostrarInfo();
                std::cout << "\n";

                std::cout << "Desea recargarlo? (Y/N): ";
                std::cin >> quiereRecargar;
                std::tolower(quiereRecargar);

                if(quiereRecargar == 'y')
                {
                    bateria=validarCarga((*vehiculoElectrico).getBateria());
                    if(bateria!=-1)
                        (*vehiculoElectrico).cargarBateria(bateria);
                    else
                        std::cout << "Operacion Fallida. Vuelva a intentarlo despues. \n";
                }
            }
            else
            {
                // solo mostramos la info del vehiculo
                std::cout << i+1 << ". ";
                (*lista[i]).mostrarInfo();
                std::cout << "\n";
            }
        }
        return true;
    }
}
void cargarKilometros(std::vector<Vehiculo*>& lista)
{
    int pos;
    double kilometraje;

    if(mostrarLista(lista)==false)
        std::cout << "No hay vehiculos cargados para aumentarles el kilometraje\n";
    else
    {
        do
        {
           std::cout << "Ingrese a que vehiculo quiere modificarle el kilometraje: ";
            std::cin >> pos;
        } while (pos<1 || pos>lista.size());

        do
        {
            std::cout << "Ingrese el kilometraje: ";
            std::cin >> kilometraje;
        } while (kilometraje<0);

        (*lista[pos-1]).conducir(kilometraje);
    }
}


void limpieza(std::vector<Vehiculo*>& lista) // para liberar la memoria. De paso limpiamos los punteros que no apuntan a nada
{   system("cls");
    for (size_t i = 0; i < lista.size(); ++i)
    {
        delete lista[i];    // Libera la memoria de cada objeto
        lista[i] = nullptr; // Establece el puntero en nullptr
    }
    std::cout << "Memoria Liberada. Finalizando programa.";
}
