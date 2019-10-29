//
// Created by Juan Galvez on 2019-10-28.
//

#ifndef DESKCALCULATOR_ERROR_HANDLING_H
#define DESKCALCULATOR_ERROR_HANDLING_H

#include "iostream"

using namespace std;
int no_of_errors;
double error(const string& s)
{
    no_of_errors++;
    cerr << "error: " << s << '\n';
    return 1;
}

#endif //DESKCALCULATOR_ERROR_HANDLING_H
