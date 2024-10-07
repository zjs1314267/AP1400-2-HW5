#ifndef SUB_INGREDIENTS_H
#define SUB_INGREDIENTS_H
#include "ingredient.h"
#define DEFCLASS(ClassName, Value) \
class ClassName : public Ingredient { \
public: \
    ClassName(size_t units) : Ingredient(Value, units) { \
        this->name = #ClassName; \
    } \
    virtual Ingredient *copy()\
    {\
        return new ClassName(units);\
    }\
    virtual std::string get_name() { return this->name; } \
};

 DEFCLASS(Cinnamon, 5);
 DEFCLASS(Chocolate, 5);
 DEFCLASS(Sugar, 1);
 DEFCLASS(Cookie, 10);
 DEFCLASS(Espresso, 15);
 DEFCLASS(Milk, 10);
 DEFCLASS(MilkFoam, 5);
 DEFCLASS(Water, 1);


#endif // SUB_INGREDIENTS_H