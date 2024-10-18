#ifndef CLASS_MOTOELECTRICA_HPP
#define CLASS_MOTOELECTRICA_HPP

class MotoElectrica : public Moto, public Electricidad
{
public:

    MotoElectrica(const std::string& marca, const std::string& modelo, int year, double kilometraje, bool tieneSidecar, double bateria) 
    : Moto(marca, modelo, year, kilometraje, tieneSidecar), Electricidad(bateria) {}

    void mostrarInfo() const override
    {

        std::cout << "Prueba de polimorfia Moto Electrica\n";
        
        std::cout << "Modelo: " << modelo << "\n"
        << "Marca: " << marca << "\n"
        << "Year: " << year << "\n"
        << "Kilometraje: " << kilometraje << "\n"
        << "Sidecar: " << tieneSidecar << "\n"
        << "Bateria: " << bateria << "%" << "\n";
    }
    void cargarBateria(double porcentaje) override 
    {
        bateria+=porcentaje;
        std::cout << "Se ha finalizado con exito la operacion de carga su Moto Electrica. \n ";
    }
    
};

#endif //CLASS_MOTOELECTRICA_HPP