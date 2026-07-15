#ifndef ITEM_H
#define ITEM_H
#include <string>
using namespace std;
//-------------------------------------------------------------------
class Item
{
private:
    string name;
    string type;
    int value;
    int mods;
    bool bundle;

public:
    Item(string name, string type, int value, int mods, bool bundle);

    string get_name();
    string get_type();
    int get_value();
    int get_mods();
    bool is_bundle();

    void display();
};

#endif