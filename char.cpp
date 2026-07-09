#include "char.h"

Character::Character(string name, string loc, int energy)
{
    this->name = name;
    this->loc = loc;
    this->energy = energy;
    combat = 0;
    mods = false;
}

string Character::get_name() { return name; }
void Character::set_name(string n) { name = n; }

string Character::get_location() { return loc; }
void Character::set_location(string l) { loc = l; }

int Character::get_energy() { return energy; }
void Character::set_energy(int e) { energy = e; }

int Character::get_combat() { return combat; }
void Character::set_combat(int c) { combat = c; }