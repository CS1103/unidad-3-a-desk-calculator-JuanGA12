//
// Created by Juan Galvez on 2019-10-28.
//

#ifndef DESKCALCULATOR_FUNCIONES_H
#define DESKCALCULATOR_FUNCIONES_H

#include <iostream>
#include "Error_Handling.h"
#include "Token_stream.h"

extern map<string,double> table;

double expr(bool);
double term(bool);


double prim(bool get){
    if (get) ts.get();
    switch (ts.current().kind) {
        case Kind::number:
        { double v = ts.current().number_value;
            ts.get();
            return v;
        }
        case Kind::name:
        { double& v = table[ts.current().string_value];
            if (ts.get().kind == Kind::assign) v = expr(true);
            return v;
        }
        case Kind::minus:
            return -prim(true);
        case Kind::lp:
        { auto e = expr(true);
            if (ts.current().kind != Kind::rp) return error("')' expected");
            ts.get();
            return e;
        }
        default:
            return error("primary expected");
    }
}



double expr(bool get){
    double left = term(get);
    for (;;) {
        switch (ts.current().kind) {
            case Kind::plus:
                left += term(true);
                break;
            case Kind::minus:
                left -= term(true);
                break;
            default:
                return left;
        }
    }
}


double term(bool get)
{
    double left = prim(get);
    for (;;) {
        switch (ts.current().kind) {
            case Kind::mul:
                left *= prim(true);
                break;
            case Kind::div:
                if (auto d = prim(true)) {
                    left /= d;
                    break;
                }
                return error("No se puede dividir entre 0");
            default:
                return left;
        }
    }
}

#endif //DESKCALCULATOR_FUNCIONES_H
