//
// Created by alejandro on 4/20/19.
//

#ifndef UNIDAD_3_POO_ALEJANDROGH97_CARGA_H
#define UNIDAD_3_POO_ALEJANDROGH97_CARGA_H


class Carga {
    friend class Simulacion;
private:
    int x, y;
    double carga;
public:
    Carga(int _x, int _y, double _carga);
};


#endif //UNIDAD_3_POO_ALEJANDROGH97_CARGA_H
