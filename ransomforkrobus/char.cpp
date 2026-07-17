#include "char.h"
#include <iostream>
//-------------------------------------------------------------------
Character::Character(string name, string loc, int energy)
{
    this->name = name;
    this->loc = loc;
    this->energy = energy;
    combat = 0;
    mods = false;
}
//-------------------------------------------------------------------
string Character::get_name() { return name; }
void Character::set_name(string n) { name = n; }

string Character::get_location() { return loc; }
void Character::set_location(string l) { loc = l; }

int Character::get_energy() { return energy; }
void Character::set_energy(int e) { energy = e; }

int Character::get_combat() { return combat; }
void Character::set_combat(int c) { combat = c; }
//-------------------------------------------------------------------
//add item
void Character::add_item(string x)
{
    inv.push_back(x);
}
//-------------------------------------------------------------------
//remove item and mark as t/f
bool Character::remove_item(string x)
{
    bool y = false;
    vector<string> invnew;

    for (int i = 0; i < inv.size(); i++)
    {
        if (inv[i] == x && !y)
        {
            y = true;
        }
        else
        {
            invnew.push_back(inv[i]);
        }
    }

    inv = invnew;
    return y;
}
//-------------------------------------------------------------------
//check for item (will use later for bundles/combat etc)
bool Character::has_item(string x)
{
    for (int i = 0; i < inv.size(); i++)
    {
    if (inv[i] == x)
        {
        return true;
        }
    }
    return false;
}
//-------------------------------------------------------------------
int Character::count_item(string x)
{
    int count = 0;
    for (int i = 0; i < inv.size(); i++)
    {
        if (inv[i] == x)
        {
            count++;
        }
    }
    return count;
}
//-------------------------------------------------------------------
int Character::get_inventory_size()
{
    return inv.size();
}
//-------------------------------------------------------------------
string Character::get_inventory_item(int index)
{
    if (index >= 0 && index < inv.size())
    {
        return inv[index];
    }
    return "";
}
//-------------------------------------------------------------------
//print inv entireky
void Character::display_inventory()
{
    if (inv.size() == 0)
    {
    cout << "[inventory currently empty]" << endl;
    return;
    }

    for (int i = 0; i < inv.size(); i++)
    {
    cout << (i + 1) << ". " << inv[i] << endl;
    }
}
