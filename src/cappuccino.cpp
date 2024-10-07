#include "cappuccino.h"

Cappuccino::Cappuccino():EspressoBased(){
    name="Cappuccino";
    ingredients = std::vector<Ingredient *>{};
    ingredients.push_back(new Espresso(2));
    ingredients.push_back(new Milk(2));
    ingredients.push_back(new MilkFoam(1));
};

Cappuccino::Cappuccino(const Cappuccino& cap)
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

Cappuccino::~Cappuccino()
{        
    for(const auto& i : side_items)
        delete i;
    side_items.clear();
}

void Cappuccino::operator=(const Cappuccino& cap) {
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



// Cappuccino Cappuccino::copy(const Cappuccino& cap) {
//     Cappuccino newCappuccino; 
//     newCappuccino.name = cap.name; 
//     newCappuccino.ingredients.clear(); 

//     for (const auto& ingredient : cap.ingredients) {
//         newCappuccino.ingredients.push_back(ingredient->copy()); 
//     }

//     newCappuccino.side_items.clear(); 


//     for (const auto& sideItem : cap.side_items) {
//         newCappuccino.side_items.push_back(sideItem->copy()); 
//     }

//     return newCappuccino; 
// }


std::string Cappuccino::get_name()
{
    return name;
}

double Cappuccino::price()
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

void Cappuccino::add_side_item(Ingredient* side)
{
    side_items.push_back(side);
}

std::vector<Ingredient*>& Cappuccino::get_side_items()
{
    return side_items;
}