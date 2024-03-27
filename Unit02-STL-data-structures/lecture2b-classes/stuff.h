#pragma once

#include <iostream>

#include <string>
using std::string;
using namespace std;

class Stuff
{
private:
    int integer;
    double decimal;
    string word;

public:
    Stuff(int number, double decimal_number, string text) : integer(number), decimal(decimal_number), word(text) { }

    int get_integer() const { return integer; }
    double get_decimal() const { return decimal; }
    string get_word() const { return word; }
};

ostream &operator<<(ostream &out, Stuff const &stuff)
{
    out << "Integer: " << stuff.get_integer() << endl;
    out << "Decimal: " << stuff.get_decimal() << endl;
    out << "Word: " << stuff.get_word() << endl;
    return out;
}