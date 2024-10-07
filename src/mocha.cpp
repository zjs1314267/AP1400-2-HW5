#include "mocha.h"

Mocha::Mocha():EspressoBased(){
    name="Mocha";
    ingredients = std::vector<Ingredient *>{};
    ingredients.push_back(new Espresso(2));
    ingredients.push_back(new Milk(2));
    ingredients.push_back(new MilkFoam(1));
    ingredients.push_back(new Chocolate(1));
};

Mocha::Mocha(const Mocha& cap)
{
    this->name = cap.name; 
    this->ingredients.clear(); 

    for (const auto& ingredient : cap.ingredients) {
        this->ingredients.push_back(ingredient->copy()); 
    }

    this->side_items.clear(); 


    for (const auto& sideItem : cap.side_items) {
        this->side_items.push_back(sideItem->copy()); 
    }

};

Mocha::~Mocha()
{        
    for(const auto& i : side_items)
        delete i;
    side_items.clear();
}

void Mocha::operator=(const Mocha& cap) {
    if (this != &cap) { 
        for (const auto& item : side_items) {
            delete item;
        }
        side_items.clear();

        for (const auto& item : ingredients) {
            delete item;
        }
        ingredients.clear();
        name = cap.name;
        for (const auto& ingredient : cap.ingredients) {
            ingredients.push_back(ingredient->copy());
        }

        for (const auto& sideItem : cap.side_items) {
            side_items.push_back(sideItem->copy());
        }
    }
}



// Mocha Mocha::copy(const Mocha& cap) {
//     Mocha newMocha; 
//     newMocha.name = cap.name; 
//     newMocha.ingredients.clear(); 

//     for (const auto& ingredient : cap.ingredients) {
//         newMocha.ingredients.push_back(ingredient->copy()); 
//     }

//     newMocha.side_items.clear(); 


//     for (const auto& sideItem : cap.side_items) {
//         newMocha.side_items.push_back(sideItem->copy()); 
//     }

//     return newMocha; 
// }


std::string Mocha::get_name()
{
    return name;
}

double Mocha::price()
{
    double count=0;
    for(const auto &i:ingredients) {
        count+=i->price();
    }
    for(const auto &s:side_items) {
        count+=s->price();
    }
    return count;
}

void Mocha::add_side_item(Ingredient* side)
{
    side_items.push_back(side);
}

std::vector<Ingredient*>& Mocha::get_side_items()
{
    return side_items;
}