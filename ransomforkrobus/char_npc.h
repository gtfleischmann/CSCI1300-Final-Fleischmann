#ifndef CHAR_NPC_H
#define CHAR_NPC_H
#include "char.h"
#include "char_player.h"

class recipe
{
public:
    string result_name;
    string result_type;
    int result_value;
    int result_power;
    bool result_requires_strength;
    string ingredient_name;
    int ingredient_qty;
};

class NPC : public Character
{
private:
    bool relation;
    int friendship;
    string dialogue;
    string faction;
    string greeting;
    string o1;
    string o2;
    string o3;
    string o4;
    string o5;
    recipe known_recipes[30];
    int recipe_count;

public:
    NPC(string name, string loc, int energy, string faction);

    bool get_relation();
    void set_relation(bool r);

    int get_friendship();
    void set_friendship(int f);

    string get_dialogue();
    void set_dialogue(string d);

    string get_faction();
    void set_faction(string f);

    string get_greeting();
    void set_greeting(string g);

    string get_o1();
    void set_o1(string o1);

    string get_o2();
    void set_o2(string o2);

    string get_o3();
    void set_o3(string o3);

    string get_o4();
    void set_o4(string o4);

    string get_o5();
    void set_o5(string o5);

    string get_relationmod();
    void react_to_gift(string item_name, int item_value);
    void add_recipe(string result_name, string result_type, int result_value, int result_power, bool result_requires_strength, string ingredient_name, int ingredient_qty);

    void load_tortus_recipes();
    void load_remy_recipes();
    void load_razmona_recipes();

    Player gift_item(Player p);
    Player train(Player p);
    Player remy_chat(Player p);
    Player craft_menu(Player p);
    Player magic_shortcut(Player p);

    Player tortus_shop_menu(Player p);
    Player remy_shop_menu(Player p);
    Player splinter_shop_menu(Player p);
    Player razmona_shop_menu(Player p);

    void interact();
};

#endif
