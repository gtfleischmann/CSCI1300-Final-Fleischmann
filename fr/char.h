#ifndef CHAR_H
#define CHAR_H
#include <string>
#include <vector>
using namespace std;
//-------------------------------------------------------------------
class Character
{
private:
    string name;
    string loc;
    int energy;
    vector<string> inv;
    int combat;
    bool mods;

public:
    Character(string name, string loc, int energy);

    string get_name();
    void set_name(string n);

    string get_location();
    void set_location(string l);

    int get_energy();
    void set_energy(int e);

    int get_combat();
    void set_combat(int c);

    void add_item(string x);
    bool remove_item(string x);
    bool has_item(string x);
    void display_inventory();
};

#endif