#include "item.h"
#include <iostream>

Item::Item()
{
    name = "empty";
    type = "none";
    value = 0;
    power = 0;
    requires_strength = false;
}

Item::Item(string name, string type, int value, int power, bool requires_strength)
{
    this->name = name;
    this->type = type;
    this->value = value;
    this->power = power;
    this->requires_strength = requires_strength;
}

string Item::get_name() { return name; }
string Item::get_type() { return type; }
int Item::get_value() { return value; }
int Item::get_power() { return power; }
bool Item::get_requires_strength() { return requires_strength; }

void Item::display()
{
    cout << name << " [" << type << "] value:" << value << " power:" << power;
    if (requires_strength)
    {
        cout << " (needs strength)";
    }
    cout << endl;
}