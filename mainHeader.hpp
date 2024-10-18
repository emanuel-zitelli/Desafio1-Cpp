#ifndef MAINHEADER_HPP
#define MAINHEADER_HPP

//bibliotecas
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib> // system pause y cls
#include <limits>

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
    double capacidadCarga;
    
    double bateria;
};


enum AccionBasica
{
    oAgregar=1,
    oMostrarYCargar=2,
    oCargarKilometraje=3,
    oTerminar=4,

    oAuto=5,
    oMoto=6,
    oCamion=7
};

short int interfaz(std::string frase);

void cargarAuto(std::vector<Vehiculo*>& lista);
void cargarMoto(std::vector<Vehiculo*>& lista);
void cargarCamion(std::vector<Vehiculo*>& lista);

void cargarKilometros(std::vector<Vehiculo*>& lista);

bool mostrarLista(std::vector<Vehiculo*>& lista);
void limpieza(std::vector<Vehiculo*>& lista);
#endif //MAINHEADER_HPP