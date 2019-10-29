#include <iostream>

#include "Token_stream.h"
#include "Error_Handling.h"
#include "Calcular.h"

using namespace std;


map<string,double> table;
Token_stream ts {cin};

int main()
{
    cout<<"Bienvenido a la calculadora"<<endl;
    cout<<"Por favor realice sus operaciones"<<endl;
    table["pi"] = 3.1415926535897932385;
    table["e"] = 2.7182818284590452354;
    calculate();
    return no_of_errors;
}