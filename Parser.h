//
// Created by Juan Galvez on 2019-10-24.
//

#ifndef DESKCALCULATOR_PARSER_H
#define DESKCALCULATOR_PARSER_H

#include <iostream>
using namespace std;

enum class Kind : char { name, number, end,
    plus='+',
    minus='-',
    mul='*',
    div='/',
    print=';',
    assign='=',
    lp='(',
    rp=')'
};

struct Token {
    Kind kind;
    string string_value;
    double number_value;


};

#endif //DESKCALCULATOR_PARSER_H
