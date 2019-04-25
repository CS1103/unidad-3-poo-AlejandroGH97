//
// Created by alejandro on 4/20/19.
//

#include "Carga.h"
#include <vector>

#ifndef UNIDAD_3_POO_ALEJANDROGH97_SIMULACION_H
#define UNIDAD_3_POO_ALEJANDROGH97_SIMULACION_H


class Simulacion {
private:
    std::vector<Carga> cargas;
    int h, w, n, m;
    double k;
public:
    Simulacion(int _w, int _h, int _n, int _m);
    Simulacion(int _w, int _h, int _n, int _m, int num_cargas);
    void simular();
    void imprimir_cargas();
    std::string generarCarga(int _X, int _y, double carga);
    double getPotencia(int x, int y);
    void generarCargas(int num_cargas);
};


#endif //UNIDAD_3_POO_ALEJANDROGH97_SIMULACION_H
