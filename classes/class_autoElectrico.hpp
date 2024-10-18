#ifndef CLASS_AUTOELECTRICO_HPP
#define CLASS_AUTOELECTRICO_HPP

class AutoElectrico : public Auto, public Electricidad
{ 
public:
    AutoElectrico(const std::string& marca, const std::string& modelo, const int year, double kilometraje, const int cantidadPuertas, double bateria)
    : Auto(marca, modelo, year, kilometraje, cantidadPuertas), Electricidad(bateria) {}

    void mostrarInfo() const override
    {

        std::cout << "Prueba de polimorfia Auto Electrico\n";

        std::cout << "Modelo: " << modelo << "\n"
        << "Marca: " << marca << "\n"
        << "Year: " << year << "\n"
        << "Kilometraje: " << kilometraje << "\n"
        << "Cantidad de Puertas: " << cantidadPuertas << "\n"
        << "Bateria: " << bateria << "\n";
    }
    void cargarBateria(double porcentaje) override 
    {
        bateria+=porcentaje;
        std::cout << "Se ha cargado con exito su Auto electrico. \n";
    }
    

};

#endif //CLASS_AUTOELECTRICO_HPP