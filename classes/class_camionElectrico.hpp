#ifndef CLASS_CAMIONELECTRICO_HPP
#define CLASS_CAMIONELECTRICO_HPP

class CamionElectrico :  public Camion, public Electricidad
{
public:
    
    CamionElectrico(const std::string& marca, const std::string& modelo, int year, double kilometraje, double capacidadCarga) 
    : Camion(marca, modelo, year, kilometraje, capacidadCarga), Electricidad(bateria) {}
    
    void mostrarInfo() const override
    {

        std::cout << "Prueba de polimorfia Camion\n";
        
        std::cout << "Modelo: " << modelo << "\n"
        << "Marca: " << marca << "\n"
        << "Year: " << year << "\n"
        << "Kilometraje: " << kilometraje << "\n"
        << "Capacidad de Carga " << capacidadCarga << "\n"
        << "Bateria: " << bateria << "\n";
    }

    void cargarBateria(double porcentaje) override 
    {
        bateria+=porcentaje;
        std::cout << "Se ha cargado con exito su Camion electrico. \n";
    }
    

};

#endif //CLASS_CAMIONELECTRICO_HPP