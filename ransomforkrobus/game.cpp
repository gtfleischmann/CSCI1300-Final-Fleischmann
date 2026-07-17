#include "game.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;
//-------------------------------------------------------------------
string clean_game_line(string line)
{
    if (line.size() > 0 && line[line.size() - 1] == '\r')
    {
        line = line.substr(0, line.size() - 1);
    }
    return line;
}
//-------------------------------------------------------------------
string lower_game_string(string s)
{
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
        {
            s[i] = s[i] + 32;
        }
    }
    return s;
}
//-------------------------------------------------------------------
int string_to_int(string s)
{
    int result = 0;
    for (int i = 0; i < s.size(); i++)
    {
        result = result * 10 + (s[i] - '0');
    }
    return result;
}
//-------------------------------------------------------------------
Game::Game()
{
    mine_mob_roster[0] = { "minitaur",    5,  "Minitaur Hide", 0.5, 1, 1, "Minitaur Shank", 0.5, 1, 1 };
    mine_mob_roster[1] = { "megataur",    15, "Megataur Hide", 0.5, 1, 1, "Megataur Shank", 0.5, 1, 1 };
    mine_mob_roster[2] = { "snake",       7,  "Snake Oil",     1.0, 1, 1, "Snake Skin",     0.5, 1, 1 };
    mine_mob_roster[3] = { "saber tooth", 7,  "Saber's Tooth", 0.3, 1, 1, "", 0.0, 0, 0 };
    mine_mob_roster[4] = { "fruit bat",   2,  "Bat Fruit",     1.0, 1, 3, "", 0.0, 0, 0 };
    mine_mob_roster[5] = { "goblin",      3,  "Goblin Steak",  1.0, 1, 3, "", 0.0, 0, 0 };
    mine_mob_roster[6] = { "dwarf",       4,  "Dwarven Scroll I", 0.3, 1, 1, "", 0.0, 0, 0 };

    item_count = 0;
    load_items("blades.txt");
    load_items("protection.txt");
    load_items("feast.txt");
    load_items("brew.txt");
    load_items("jewels.txt");
    load_items("scrolls.txt");
    load_items("mineloot.txt");
    load_items("accessories.txt");
}
//-------------------------------------------------------------------
void Game::load_items(string filename)
{
    ifstream in_file(filename);

    if (!in_file.is_open())
    {
        cout << "warning: could not open " << filename << endl;
        return;
    }

    string name;
    while (getline(in_file, name))
    {
        name = clean_game_line(name);

        string type;
        getline(in_file, type);
        type = clean_game_line(type);

        string value_line;
        getline(in_file, value_line);
        value_line = clean_game_line(value_line);

        string power_line;
        getline(in_file, power_line);
        power_line = clean_game_line(power_line);

        string strength_line;
        getline(in_file, strength_line);
        strength_line = clean_game_line(strength_line);

        if (item_count < 100)
        {
            all_items[item_count] = Item(name, type, string_to_int(value_line), string_to_int(power_line), strength_line == "TRUE");
            item_count++;
        }
    }

    in_file.close();
}
//-------------------------------------------------------------------
int Game::find_item(string name)
{
    string check_name = lower_game_string(name);
    for (int i = 0; i < item_count; i++)
    {
        if (lower_game_string(all_items[i].get_name()) == check_name)
        {
            return i;
        }
    }
    return -1;
}
//-------------------------------------------------------------------
Item Game::get_item(int index)
{
    return all_items[index];
}
//-------------------------------------------------------------------
int Game::get_item_count()
{
    return item_count;
}
//-------------------------------------------------------------------
Player Game::resolve_mine_search(int current_tier, Player p)
{
    int roll = (rand() % 100) + 1;
    string result_name = "";
    string result_type = "";

    if (current_tier == 1)
    {
        if      (roll <= 45) { result_name = "Stone";        result_type = "item"; }
        else if (roll <= 55) { result_name = "Slug";         result_type = "item"; }
        else if (roll <= 65) { result_name = "Bug";          result_type = "item"; }
        else if (roll <= 75) { result_name = "Mushroom";     result_type = "item"; }
        else if (roll <= 85) { result_name = "Copper Ore";   result_type = "item"; }
        else if (roll <= 92) { result_name = "Iron Ore";     result_type = "item"; }
        else if (roll <= 96) { result_name = "Titanium Ore"; result_type = "item"; }
        else if (roll <= 98) { result_name = "Iridium Ore";  result_type = "item"; }
        else                 { result_name = "mob";          result_type = "mob"; }
    }
    else if (current_tier == 2)
    {
        if      (roll <= 20) { result_name = "Stone";        result_type = "item"; }
        else if (roll <= 38) { result_name = "Copper Ore";   result_type = "item"; }
        else if (roll <= 53) { result_name = "Iron Ore";     result_type = "item"; }
        else if (roll <= 63) { result_name = "Titanium Ore"; result_type = "item"; }
        else if (roll <= 68) { result_name = "Iridium Ore";  result_type = "item"; }
        else if (roll <= 71) { result_name = "Amethyst";     result_type = "item"; }
        else if (roll <= 74) { result_name = "Diamond";      result_type = "item"; }
        else if (roll <= 77) { result_name = "Emerald";      result_type = "item"; }
        else if (roll <= 80) { result_name = "Ruby";         result_type = "item"; }
        else if (roll <= 83) { result_name = "Sapphire";     result_type = "item"; }
        else                 { result_name = "mob";          result_type = "mob"; }
    }
    else
    {
        if      (roll <= 15) { result_name = "Copper Ore";   result_type = "item"; }
        else if (roll <= 30) { result_name = "Iron Ore";     result_type = "item"; }
        else if (roll <= 45) { result_name = "Titanium Ore"; result_type = "item"; }
        else if (roll <= 57) { result_name = "Iridium Ore";  result_type = "item"; }
        else if (roll <= 62) { result_name = "Amethyst";     result_type = "item"; }
        else if (roll <= 67) { result_name = "Diamond";      result_type = "item"; }
        else if (roll <= 72) { result_name = "Emerald";      result_type = "item"; }
        else if (roll <= 77) { result_name = "Ruby";         result_type = "item"; }
        else if (roll <= 82) { result_name = "Sapphire";     result_type = "item"; }
        else if (roll <= 85) { result_name = "Magic Mushroom"; result_type = "item"; }
        else                 { result_name = "mob";          result_type = "mob"; }
    }

    if (result_type == "item")
    {
        int found_idx = find_item(result_name);
        if (found_idx != -1)
        {
            cout << "you found:" << endl;
            all_items[found_idx].display();
            p.add_item(all_items[found_idx].get_name());
        }
        else
        {
            cout << "you found " << result_name << "." << endl;
            p.add_item(result_name);
        }
    }
    else
    {
        int mob_index;
        if (current_tier == 1)
        {
            int tier1_mob_options[3] = {2, 4, 5};
            mob_index = tier1_mob_options[rand() % 3];
        }
        else if (current_tier == 2)
        {
            int tier2_mob_options[5] = {0, 2, 3, 4, 5};
            mob_index = tier2_mob_options[rand() % 5];
        }
        else
        {
            int tier3_mob_options[5] = {0, 1, 2, 3, 4};
            mob_index = tier3_mob_options[rand() % 5];
        }

        enemy foe = mine_mob_roster[mob_index];
        cout << "a " << foe.name << " attacks!" << endl;

        int damage = resolve_combat(p.get_combat(), 0, foe.power);
        damage = p.apply_protection(damage);

        if (damage == 0)
        {
            cout << "you defeat the " << foe.name << "." << endl;

            int drop1_roll = rand() % 100;
            if (foe.drop1_name != "" && drop1_roll < foe.drop1_chance * 100)
            {
                int drop_qty = foe.drop1_qty_min;
                if (foe.drop1_qty_max > foe.drop1_qty_min)
                {
                    drop_qty = foe.drop1_qty_min + rand() % (foe.drop1_qty_max - foe.drop1_qty_min + 1);
                }
                for (int i = 0; i < drop_qty; i++)
                {
                    p.add_item(foe.drop1_name);
                }
                cout << "you found " << drop_qty << " " << foe.drop1_name << "." << endl;
            }

            int drop2_roll = rand() % 100;
            if (foe.drop2_name != "" && drop2_roll < foe.drop2_chance * 100)
            {
                int drop_qty = foe.drop2_qty_min;
                if (foe.drop2_qty_max > foe.drop2_qty_min)
                {
                    drop_qty = foe.drop2_qty_min + rand() % (foe.drop2_qty_max - foe.drop2_qty_min + 1);
                }
                for (int i = 0; i < drop_qty; i++)
                {
                    p.add_item(foe.drop2_name);
                }
                cout << "you found " << drop_qty << " " << foe.drop2_name << "." << endl;
            }
        }
        else
        {
            p.set_energy(p.get_energy() - damage);
            cout << "you escape, but lose " << damage << " energy." << endl;
        }
    }

    return p;
}
//-------------------------------------------------------------------
int Game::resolve_combat(int player_combat, int player_protection, int enemy_power)
{
    int player_roll = player_combat + (rand() % 6);
    int enemy_roll = enemy_power + (rand() % 6);

    if (player_roll >= enemy_roll)
    {
        return 0;
    }

    int damage = (enemy_roll - player_roll) - player_protection;
    if (damage < 1)
    {
        damage = 1;
    }
    return damage;
}
//-------------------------------------------------------------------
void Game::show_dwarf_letter(Player p, int max_days)
{
    cout << p.get_name() << "... you may have noticed your friend krobus is gone..." << endl;
    cout << "in exchange for his freedom, i demand:" << endl;
    cout << "the sharpest blade," << endl;
    cout << "the strongest brew," << endl;
    cout << "the most flavorful feast," << endl;
    cout << "and the shiniest jewel" << endl;
    cout << "you can procure." << endl;
    cout << endl;
    cout << "bring these to my dungeon gate before day " << max_days << " is up....." << endl;
    cout << endl;
    cout << "-drokk, the dwarf king" << endl;
}
//-------------------------------------------------------------------
bool Game::player_has_type(Player p, string type)
{
    for (int i = 0; i < p.get_inventory_size(); i++)
    {
        int item_index = find_item(p.get_inventory_item(i));
        if (item_index != -1 && all_items[item_index].get_type() == type)
        {
            return true;
        }
    }
    return false;
}
//-------------------------------------------------------------------
bool Game::can_enter_lair(Player p)
{
    if (p.get_penalty() > 0)
    {
        return true;
    }

    return player_has_type(p, "blade") &&
           player_has_type(p, "brew") &&
           player_has_type(p, "feast") &&
           player_has_type(p, "jewel");
}
//-------------------------------------------------------------------
void Game::dwarf_king_encounter(Player p)
{
    if (p.get_penalty() > 0)
    {
        cout << "drokk raises a hand, but razmona's magic flashes across the room." << endl;
        cout << "the locks around krobus break before the dwarf king can stop them." << endl;
        cout << p.get_name() << ", you used magic to free krobus!" << endl;
        return;
    }

    int offering_score = 0;

    cout << p.get_name() << "..... what took you so long..." << endl;
    cout << "let's see what you've brought me....." << endl;
    cout << endl;

    cin.ignore(1000, '\n');

    //-------------------------------------------------------------------
    cout << "(give blade)" << endl;
    cout << "which blade will you offer? ";
    string blade_name;
    getline(cin, blade_name);
    int blade_idx = find_item(blade_name);

    if (blade_idx == -1 || !p.has_item(get_item(blade_idx).get_name()) || get_item(blade_idx).get_type() != "blade")
    {
        cout << "drokk waits, arms crossed. that is not a blade you carry." << endl;
    }
    else
    {
        Item chosen = get_item(blade_idx);
        cout << "drokk runs your " << chosen.get_name() << " through his hands, testing its might." << endl;

        // blade value cutoffs
        if (chosen.get_value() >= 20)
        {
            cout << "oooooh.... this blade is incredible!" << endl;
            offering_score += 3;
        }
        else if (chosen.get_value() >= 10)
        {
            cout << "ah... this blade is quite nice." << endl;
            offering_score += 2;
        }
        else
        {
            cout << "hmm... this blade is... adequate." << endl;
            offering_score += 1;
        }
    }
    cout << endl;

    //-------------------------------------------------------------------
    cout << "(give brew)" << endl;
    cout << "which brew will you offer? ";
    string brew_name;
    getline(cin, brew_name);
    int brew_idx = find_item(brew_name);

    if (brew_idx == -1 || !p.has_item(get_item(brew_idx).get_name()) || get_item(brew_idx).get_type() != "brew")
    {
        cout << "drokk waits, arms crossed. that is not a brew you carry." << endl;
    }
    else
    {
        Item chosen = get_item(brew_idx);
        cout << "drokk takes a sip of your " << chosen.get_name() << "... and another sip for good measure." << endl;

        // brew value cutoffs
        if (chosen.get_value() >= 20)
        {
            cout << "oooooh.... this brew is incredible!" << endl;
            offering_score += 3;
        }
        else if (chosen.get_value() >= 10)
        {
            cout << "ah... this brew is quite nice." << endl;
            offering_score += 2;
        }
        else
        {
            cout << "hmm... this brew is... adequate." << endl;
            offering_score += 1;
        }
    }
    cout << endl;

    //-------------------------------------------------------------------
    cout << "(give feast)" << endl;
    cout << "which feast will you offer? ";
    string feast_name;
    getline(cin, feast_name);
    int feast_idx = find_item(feast_name);

    if (feast_idx == -1 || !p.has_item(get_item(feast_idx).get_name()) || get_item(feast_idx).get_type() != "feast")
    {
        cout << "drokk waits, arms crossed. that is not a feast you carry." << endl;
    }
    else
    {
        Item chosen = get_item(feast_idx);
        cout << "drokk breathes in your " << chosen.get_name() << " and takes a hearty bite." << endl;

        // feast value cutoffs
        if (chosen.get_value() >= 20)
        {
            cout << "oooooh.... this feast is incredible!" << endl;
            offering_score += 3;
        }
        else if (chosen.get_value() >= 10)
        {
            cout << "ah... this feast is quite nice." << endl;
            offering_score += 2;
        }
        else
        {
            cout << "hmm... this feast is... adequate." << endl;
            offering_score += 1;
        }
    }
    cout << endl;

    //-------------------------------------------------------------------
    cout << "(give jewel)" << endl;
    cout << "which jewel will you offer? ";
    string jewel_name;
    getline(cin, jewel_name);
    int jewel_idx = find_item(jewel_name);

    if (jewel_idx == -1 || !p.has_item(get_item(jewel_idx).get_name()) || get_item(jewel_idx).get_type() != "jewel")
    {
        cout << "drokk waits, arms crossed. that is not a jewel you carry." << endl;
    }
    else
    {
        Item chosen = get_item(jewel_idx);
        cout << "drokk shines your " << chosen.get_name() << " up to the light, greed shining in his eyes." << endl;

        // jewel value cutoffs
        if (chosen.get_value() >= 20)
        {
            cout << "oooooh.... this jewel is incredible!" << endl;
            offering_score += 3;
        }
        else if (chosen.get_value() >= 10)
        {
            cout << "ah... this jewel is quite nice." << endl;
            offering_score += 2;
        }
        else
        {
            cout << "hmm... this jewel is... adequate." << endl;
            offering_score += 1;
        }
    }
    cout << endl;

    //-------------------------------------------------------------------
    // final offering score cutoffs
    if (offering_score >= 10)
    {
        cout << p.get_name() << ", these offerings are more than sufficient." << endl;
    }
    else if (offering_score >= 7)
    {
        cout << p.get_name() << ", these offerings are sufficient." << endl;
    }
    else
    {
        cout << p.get_name() << ", these offerings are less than sufficient... but i might as well free krobus anyways." << endl;
    }

    cout << "drokk opens the cell. krobus is free!" << endl;
}
