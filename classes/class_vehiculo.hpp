#ifndef CLASS_VEHICULO_HPP
#define CLASS_VEHICULO_HPP


//Clase abstracta vehiculo, clase padre de todos los tipos de vehiculo
class Vehiculo
{
public:

    Vehiculo(const std::string& marca, const std::string& modelo, const int year, double kilometraje)
    : marca(marca), modelo(modelo), year(year), kilometraje(kilometraje) {} //constructor de vehiculos

    virtual void mostrarInfo() const = 0;
    virtual void conducir(double km) = 0;
    

protected: //ya que quiero que estas variables sean propias de las clases hijas, y no que sea un acceso directo a la clase vehiculo

    std::string marca;
    std::string modelo;
    int year;
    double kilometraje=0;

};

#endif //CLASS_VEHICULO_HPP