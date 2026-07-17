#ifndef GAME_H
#define GAME_H
#include <string>
#include "item.h"
#include "char_player.h"
using namespace std;

class enemy
{
public:
    string name;
    int power;
    string drop1_name;
    double drop1_chance;
    int drop1_qty_min;
    int drop1_qty_max;
    string drop2_name;
    double drop2_chance;
    int drop2_qty_min;
    int drop2_qty_max;
};

class Game
{
private:
    enemy mine_mob_roster[7];
    Item all_items[100];
    int item_count;

public:
    Game();

    void load_items(string filename);
    int find_item(string name);
    Item get_item(int index);
    int get_item_count();

    Player resolve_mine_search(int current_tier, Player p);
    int resolve_combat(int player_combat, int player_protection, int enemy_power);

    void show_dwarf_letter(Player p, int max_days);
    bool player_has_type(Player p, string type);
    bool can_enter_lair(Player p);
    void dwarf_king_encounter(Player p);
};

#endif
