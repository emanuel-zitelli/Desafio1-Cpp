#ifndef CLASS_ELECTRICIDAD_HPP
#define CLASS_ELECTRICIDAD_HPP

class Electricidad
{

public:
    Electricidad(double const bateria) : bateria(bateria) {}
    virtual void cargarBateria(double porcentaje) = 0;

protected:

    double bateria=0; 

};

#endif //CLASS_ELECTRICIDAD_HPP