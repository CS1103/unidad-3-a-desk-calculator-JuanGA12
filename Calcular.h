//
// Created by Juan Galvez on 2019-10-28.
//

#ifndef DESKCALCULATOR_CALCULAR_H
#define DESKCALCULATOR_CALCULAR_H

#include "Token_stream.h"
#include "Funciones.h"


void calculate()
{
    for (;;) {
        ts.get();
        if (ts.current().kind == Kind::end) break;
        if (ts.current().kind == Kind::print) continue;
        cout << expr(false) << '\n';
    }
}

#endif //DESKCALCULATOR_CALCULAR_H
