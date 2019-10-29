//
// Created by Juan Galvez on 2019-10-24.
//

#ifndef DESKCALCULATOR_TOKEN_STREAM_H
#define DESKCALCULATOR_TOKEN_STREAM_H

#include "Parser.h"
#include "Error_Handling.h"
#include <iostream>
#include <string>
#include <map>
#include <cctype>

using namespace std;

class Token_stream {
public:
        Token_stream(istream& s) : ip{&s}, owns{false} { }
        Token_stream(istream* p) : ip{p}, owns{true} { }
        ~Token_stream() {
            close();
        }
        Token get();
        Token& current(){
            return ct;
        }
        void set_input(istream& s) { close(); ip = &s; owns=false; }
        void set_input(istream* p) { close(); ip = p; owns = true; }


private:
        void close() { if (owns) delete ip; }
        istream * ip;
        bool owns;
        Token ct {Kind::end} ;
};

extern Token_stream ts;

Token Token_stream::get(){

    char ch;
    do {
        if (!ip->get(ch)) return ct={Kind::end};
    }while (ch!='\n' && isspace(ch));

    switch (ch) {
        case ';':
        case '\n':
            return ct={Kind::print};
        case '*':
        case '/':
        case '+':
        case '-':
        case '(':
        case ')':
        case '=':
            return ct={static_cast<Kind>(ch)};
        case '0': case '1': case '2': case '3': case '4':
        case '5': case '6': case '7': case '8': case '9':
        case '.':
            ip->putback(ch);
            *ip >> ct.number_value;
            ct.kind=Kind::number;
            return ct;
        default:
            if (isalpha(ch)) {
                ct.string_value = ch;
                while (ip->get(ch) && isalnum(ch))
                    ct.string_value += ch;
                ip->putback(ch);
                return ct={Kind::name};
            }
            error("bad token");
            return ct={Kind::print};
    }
}




#endif //DESKCALCULATOR_TOKEN_STREAM_H
