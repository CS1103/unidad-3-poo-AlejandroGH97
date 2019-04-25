//
// Created by alejandro on 4/20/19.
//
#include <iostream>
#include <cmath>
#include <iomanip>
#include <random>
#include <ctime>
#include "Simulacion.h"


Simulacion::Simulacion(int _w, int _h, int _n, int _m):h{_h},w{_w},n{_n},m{_m},k{8990000000}{}

Simulacion::Simulacion(int _w, int _h, int _n, int _m, int num_cargas):h{_h},w{_w},n{_n},m{_m},k{8990000000}{

}

void Simulacion::simular() {
    double potencia = 0;
    std::cout<<std::setw(5)<<"X"<<std::setw(5)<<"Y"<<std::setw(10)<<"Potencia"<<std::endl;
    for(int intervalos_y = 0;intervalos_y<=n;intervalos_y++){
        for(int intervalos_x = 0; intervalos_x<=m;intervalos_x++){
            std::cout<<std::setw(5)<<std::setprecision(5)<<intervalos_x*(w*1.0/m)<<std::setw(5)<<intervalos_y*(h*1.0/n)<<std::setw(10)<<getPotencia(intervalos_x, intervalos_y)<<std::endl;
            potencia = 0;
        }
    }
}

void Simulacion::imprimir_cargas(){
    for(Carga carga: cargas){
        std::cout<<std::setprecision(3)<<std::setw(5)<<carga.x<<" - "<<std::setw(5)<<carga.y<<" - "<<std::setw(5)<<carga.carga<<std::endl;
    }
}

double Simulacion::getPotencia(int x, int y) {
    double potencia = 0;
    for(Carga carga: cargas){
        potencia+=(carga.carga*k)  /  pow(  (pow(carga.y-y,2)  +  pow(carga.x-x,  2)),0.5);
    }
    return potencia;
}

std::string Simulacion::generarCarga(int _x, int _y, double _carga){
    for(Carga carga:cargas) {
        if(carga.x==_x && carga.y == _y){
            return "Carga repetida";
        }
    }

    if (_x <= w && _x >= 0 && _y <= h && _y >= 0) {
        cargas.emplace_back(Carga(_x, _y, _carga));
        return "Se genero carga";
    } else {
        return "Carga fuera de rango";
    }
}



void Simulacion::generarCargas(int num_cargas) {
    std::random_device rd;
    std::mt19937 rng(rd());

    int temp_x, temp_y;

    for(int index = 0;index<num_cargas;index++) {
        std::uniform_int_distribution<int> rand_intX(0, w);
        temp_x = rand_intX(rng);

        std::uniform_int_distribution<int> rand_intY(0, h);
        temp_y = rand_intY(rng);

        for (int y = 0; y < index; y++) {
            if ( temp_x == cargas[y].x && temp_y == cargas[y].y){
                cargas.pop_back();
                index--;
                break;
            }
            else{
                std::uniform_real_distribution<double> rand_intCarga(-1, 1);
                cargas.emplace_back(Carga(temp_x,temp_y,rand_intCarga(rng)/100000000));
            }
        }
    }
}