#include "item.h"
#include <iostream>
//wip, will incorporate once items list is final
Item::Item(string name, string type, int value, int mods, bool bundle)
    {
    this->name = name;
    this->type = type;
    this->value = value;
    this->mods = mods;
    this->bundle = bundle;
    }

string Item::get_name() { return name; }
string Item::get_type() { return type; }
int Item::get_value() { return value; }
int Item::get_mods() { return mods; }
bool Item::is_bundle() { return bundle; }

void Item::display()
{
cout << name << " [" << type << "]";
    if (bundle)
        {
        cout << " (ransom item)";
        }
cout << endl;
}