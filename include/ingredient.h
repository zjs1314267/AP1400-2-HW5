#ifndef INGREDIENT_H
#define INGREDIENT_H
#include <string>
#include <cstddef>
class Ingredient
{
public:
    double get_price_unit();
    size_t get_units();
    virtual std::string get_name()=0;
    virtual Ingredient *copy() = 0;
    double price();
    

protected:
    Ingredient(double price_unit, size_t units);
    double price_unit;
    size_t units;
    std::string name;
};

inline Ingredient::Ingredient(double price_unit, size_t units) : price_unit(price_unit), units(units) {};

inline double Ingredient:: get_price_unit()
{ 
    return price_unit; 
}

inline size_t Ingredient::get_units()
{
    return units;
}

inline double Ingredient::price()
{ 
    return price_unit*units; 
}

#endif // INGREDIENT_H

