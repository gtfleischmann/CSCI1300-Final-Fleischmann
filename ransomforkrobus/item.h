#ifndef ITEM_H
#define ITEM_H
#include <string>
using namespace std;

class Item
{
private:
    string name;
    string type;
    int value;
    int power;
    bool requires_strength;

public:
    Item();
    Item(string name, string type, int value, int power, bool requires_strength);

    string get_name();
    string get_type();
    int get_value();
    int get_power();
    bool get_requires_strength();

    void display();
};

#endif