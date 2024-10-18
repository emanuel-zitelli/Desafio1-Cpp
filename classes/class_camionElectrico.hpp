#ifndef CLASS_CAMIONELECTRICO_HPP
#define CLASS_CAMIONELECTRICO_HPP

class CamionElectrico :  public Camion, public Electricidad
{
public:
    
    CamionElectrico(const std::string& marca, const std::string& modelo, const int year, const double kilometraje, const double capacidadCarga, const double bateria) 
    : Camion(marca, modelo, year, kilometraje, capacidadCarga), Electricidad(bateria) {}
    
    void mostrarInfo() const override
    {

        std::cout << "Prueba de polimorfia Camion Electrico\n";
        
        std::cout << "Modelo: " << modelo << "\n"
        << "Marca: " << marca << "\n"
        << "Year: " << year << "\n"
        << "Kilometraje: " << kilometraje << "\n"
        << "Capacidad de Carga " << capacidadCarga << "\n"
        << "Bateria: " << bateria << "%" << "\n";
    }

    void cargarBateria(double porcentaje) override 
    {
        bateria+=porcentaje;
        std::cout << "Se ha finalizado con exito la operacion de carga su Camion electrico. \n. \n";
    }
    

};

#endif //CLASS_CAMIONELECTRICO_HPP