#ifndef CLASS_MOTO_HPP
#define CLASS_MOTO_HPP

class Moto : public Vehiculo 
{
public:
    Moto(const std::string& marca, const std::string& modelo, int year, double kilometraje, bool tieneSidecar) 
    : Vehiculo(marca, modelo, year, kilometraje), tieneSidecar(tieneSidecar) {}

    void mostrarInfo() const override
    {

        std::cout << "Prueba de polimorfia Moto\n";
        
        std::cout << "Modelo: " << modelo << "\n"
        << "Marca: " << marca << "\n"
        << "Year: " << year << "\n"
        << "Kilometraje: " << kilometraje << "\n"
        << "Sidecar: " << (tieneSidecar ? "Si" : "No") << "\n";
    }

    void conducir(double km) override
    {
       kilometraje+=km;
       std::cout << "Kilometraje del Moto actualizado. Su nuevo kilometraje es: " << kilometraje << "\n";
    }

protected:

    bool tieneSidecar;

};

#endif //CLASS_MOTO_HPP