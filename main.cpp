#include <iostream>
#include "Simulacion.h"

#define CATCH_CONFIG_MAIN
#include "catch2.h"
#ifndef CATCH_CONFIG_MAIN
int main() {
    int h, w, m, n, cargas;
    std::cin>>h>>w>>n>>m>>cargas;
    Simulacion simulacion(h,w,n,m,cargas);
    simulacion.generarCargas();
    simulacion.simular();
    simulacion.imprimir_cargas();
}
#endif