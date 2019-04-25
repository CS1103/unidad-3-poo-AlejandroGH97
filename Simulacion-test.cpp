//
// Created by alejandro on 4/24/19.
//
#include "catch2.h"
#include "Simulacion.h"

TEST_CASE("CASO_BASE"){
    int h = 6;
    int w = 7;
    int n = 6;
    int m = 7;
    double epsilon = 0.0000001;
    Simulacion simTest(h,w,n,m);
    REQUIRE(simTest.generarCarga(10,10,2000) == "Carga fuera de rango");
    REQUIRE(simTest.generarCarga(3,1,0.000000001)=="Se genero carga");
    REQUIRE(simTest.getPotencia(1,1)==4.495);
    REQUIRE(simTest.generarCarga(1,3,-0.000000003)=="Se genero carga");
    REQUIRE(simTest.generarCarga(1,3,0.000000003)=="Carga repetida");
    REQUIRE(simTest.getPotencia(3,3)- -8.99 < epsilon);


};