#ifndef MAINHEADER_HPP
#define MAINHEADER_HPP

//bibliotecas
#include <iostream>
#include <vector>
#include <string>

//classes
#include "./classes/class_vehiculo.hpp"
#include "./classes/class_electricidad.hpp"

#include "./classes/class_auto.hpp"
#include "./classes/class_autoElectrico.hpp"

#include "./classes/class_camion.hpp"
#include "./classes/class_camionElectrico.hpp"

#include "./classes/class_moto.hpp"
#include "./classes/class_motoElectrica.hpp"

struct auxAutos 
{
    std::string marca;
    std::string modelo;
    int year;
    double kilometraje;
    int cantPuertas;
    
    double bateria;
};

struct auxMotos
{
    std::string marca;
    std::string modelo;
    int year;
    double kilometraje;
    bool tieneSidecar;
    
    double bateria;
};

struct auxCamiones
{
    std::string marca;
    std::string modelo;
    int year;
    double kilometraje;
    bool capacidadCarga;
    
    double bateria;
};


enum AccionBasica
{
    Agregar=1,
    MostrarYCargar=2,
    Terminar=3,
    Auto=1,
    Moto=2,
    Camion=3
};

short int interfaz(std::string frase);
bool mostrarLista(std::vector<Vehiculo*>& vector);
void limpieza(std::vector<Vehiculo*>& lista);
#endif //MAINHEADER_HPP