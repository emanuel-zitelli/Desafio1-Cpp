#ifndef CLASS_AUTO_HPP
#define CLASS_AUTO_HPP

class Auto : public Vehiculo 
{
public:
     

    Auto(const std::string marca, const std::string modelo, const int year, double kilometraje, const int cantidadPuertas)
    : Vehiculo(marca, modelo, year, kilometraje),cantidadPuertas(cantidadPuertas) {}//constructor para poder crear los objetos con parámetros requiere que llame al constructor padre

    void mostrarInfo() const override
    {

        std::cout << "Prueba de polimorfia Auto\n";

        std::cout << "Modelo: " << modelo << "\n"
        << "Marca: " << marca << "\n"
        << "Year: " << year << "\n"
        << "Kilometraje: " << kilometraje << "\n"
        << "Cantidad de Puertas: " << cantidadPuertas << "\n";
    }
    void conducir(double km) override
    {
       kilometraje+=km;
       std::cout << "Kilometraje del Auto actualizado. Su nuevo kilometraje es: " << kilometraje << "\n";
    }
       


protected:

    int cantidadPuertas;

};

#endif //CLASS_AUTO_HPP