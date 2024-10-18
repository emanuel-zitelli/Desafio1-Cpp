#ifndef CLASS_CAMION_HPP
#define CLASS_CAMION_HPP

class Camion : public Vehiculo 
{
public:
    Camion(const std::string& marca, const std::string& modelo, int year, double kilometraje, double capacidadCarga) 
    : Vehiculo(marca, modelo, year, kilometraje), capacidadCarga(capacidadCarga) {}

    void mostrarInfo() const override
    {

        std::cout << "Prueba de polimorfia Camion\n";
        
        std::cout << "Modelo: " << modelo << "\n"
        << "Marca: " << marca << "\n"
        << "Year: " << year << "\n"
        << "Kilometraje: " << kilometraje << "\n"
        << "Capacidad de Carga " << capacidadCarga << "\n";
    }

    void conducir(double km) override
    {
       kilometraje+=km;
       std::cout << "Kilometraje del Camion actualizado. Su nuevo kilometraje es: " << kilometraje << "\n";
    }

protected:

    double capacidadCarga;

};

#endif //CLASS_CAMION_HPP