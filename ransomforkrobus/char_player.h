#ifndef CHAR_PLAYER_H
#define CHAR_PLAYER_H
#include "char.h"

class Player : public Character
{
private:
    int light;
    int funds;
    int time;
    int penalty;
    string equipped_blade;
    string equipped_armor;
    string equipped_shield;
    bool trained;

public:
    Player(string playername, string loc, int energy, int light, int funds, int time);

    int get_light();
    void set_light(int l);

    int get_funds();
    void set_funds(int f);

    int get_time();
    void set_time(int t);

    int get_penalty();
    void set_penalty(int p);

    string get_equipped_blade();
    void equip_blade(string item_name, int item_combat);

    string get_equipped_armor();
    void equip_armor(string item_name);

    string get_equipped_shield();
    void equip_shield(string item_name);

    bool get_trained();
    void set_trained(bool t);

    int apply_protection(int incoming_damage);
};

#endif
