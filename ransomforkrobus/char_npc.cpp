#include "char_npc.h"
#include <iostream>

NPC::NPC(string name, string loc, int energy, string faction) : Character(name, loc, energy)
{
    relation = false;
    friendship = 0;
    dialogue = "tbd";
    this->faction = faction;
    greeting = "tbd";
    o1 = "tbd";
    o2 = "tbd";
    o3 = "tbd";
    o4 = "tbd";
    o5 = "tbd";
    recipe_count = 0;
}
//-------------------------------------------------------------------
bool NPC::get_relation() { return relation; }
void NPC::set_relation(bool r) { relation = r; }

int NPC::get_friendship() { return friendship; }
void NPC::set_friendship(int f) { friendship = f; }

string NPC::get_dialogue() { return dialogue; }
void NPC::set_dialogue(string d) { dialogue = d; }

string NPC::get_faction() { return faction; }
void NPC::set_faction(string f) { faction = f; }

string NPC::get_greeting() { return greeting; }
void NPC::set_greeting(string g) { greeting = g; }

string NPC::get_o1() { return o1; }
void NPC::set_o1(string o) { o1 = o; }

string NPC::get_o2() { return o2; }
void NPC::set_o2(string o) { o2 = o; }

string NPC::get_o3() { return o3; }
void NPC::set_o3(string o) { o3 = o; }

string NPC::get_o4() { return o4; }
void NPC::set_o4(string o) { o4 = o; }

string NPC::get_o5() { return o5; }
void NPC::set_o5(string o) { o5 = o; }
//-------------------------------------------------------------------
string NPC::get_relationmod()
{
    if (friendship >= 10)
    {
        return "your friend ";
    }
    return "";
}
//-------------------------------------------------------------------
void NPC::react_to_gift(string item_name, int item_value)
{
    if (item_value <= 50)
    {
        cout << "* " << item_name << " * - " << get_name() << " might like this?" << endl;
    }
    else if (item_value <= 75)
    {
        cout << "* " << item_name << " * - " << get_name() << " would like this" << endl;
    }
    else
    {
        cout << "* " << item_name << " * - " << get_name() << " would love this!" << endl;
    }
}
//-------------------------------------------------------------------
void NPC::add_recipe(string result_name, string result_type, int result_value, int result_power, bool result_requires_strength, string ingredient_name, int ingredient_qty)
{
    if (recipe_count < 30)
    {
        known_recipes[recipe_count].result_name = result_name;
        known_recipes[recipe_count].result_type = result_type;
        known_recipes[recipe_count].result_value = result_value;
        known_recipes[recipe_count].result_power = result_power;
        known_recipes[recipe_count].result_requires_strength = result_requires_strength;
        known_recipes[recipe_count].ingredient_name = ingredient_name;
        known_recipes[recipe_count].ingredient_qty = ingredient_qty;
        recipe_count++;
    }
}
//-------------------------------------------------------------------
void NPC::load_tortus_recipes()
{
    add_recipe("Copper Dagger", "blade", 6, 8, false, "Copper Ore", 3);
    add_recipe("Iron Dagger", "blade", 12, 15, false, "Iron Ore", 3);
    add_recipe("Titanium Dagger", "blade", 22, 25, false, "Titanium Ore", 3);
    add_recipe("Iridium Dagger", "blade", 35, 38, false, "Iridium Ore", 3);
    add_recipe("Copper Sword", "blade", 8, 14, true, "Copper Ore", 5);
    add_recipe("Iron Sword", "blade", 16, 24, true, "Iron Ore", 5);
    add_recipe("Titanium Sword", "blade", 28, 38, true, "Titanium Ore", 5);
    add_recipe("Iridium Sword", "blade", 42, 55, true, "Iridium Ore", 5);
    add_recipe("Copper Shield", "protection", 4, 6, false, "Copper Ore", 3);
    add_recipe("Iron Shield", "protection", 8, 10, false, "Iron Ore", 3);
    add_recipe("Titanium Shield", "protection", 15, 16, false, "Titanium Ore", 3);
    add_recipe("Iridium Shield", "protection", 22, 24, false, "Iridium Ore", 3);
    add_recipe("Copper Armor", "protection", 6, 10, false, "Copper Ore", 5);
    add_recipe("Iron Armor", "protection", 12, 16, false, "Iron Ore", 5);
    add_recipe("Titanium Armor", "protection", 20, 26, false, "Titanium Ore", 5);
    add_recipe("Iridium Armor", "protection", 30, 36, false, "Iridium Ore", 5);
}
//-------------------------------------------------------------------
void NPC::load_remy_recipes()
{
    add_recipe("Bug Skewer", "feast", 6, 10, false, "Bug", 1);
    add_recipe("Slug Chowder", "feast", 10, 16, false, "Slug", 1);
    add_recipe("Bat Fruit Tart", "feast", 16, 24, false, "Bat Fruit", 1);
    add_recipe("Ratatouille", "feast", 20, 30, false, "Mushroom", 3);
    add_recipe("Remy's Feast", "feast", 90, 100, false, "Magic Mushroom", 3);
}
//-------------------------------------------------------------------
void NPC::load_razmona_recipes()
{
    add_recipe("Pale Ale", "brew", 3, 6, false, "Mushroom", 1);
    add_recipe("Heavy Ale", "brew", 8, 14, false, "Pale Ale", 3);
    add_recipe("Cider", "brew", 5, 10, false, "Bat Fruit", 1);
    add_recipe("Hard Cider", "brew", 14, 22, false, "Cider", 3);
    add_recipe("Crystal Cider", "brew", 45, 55, false, "Hard Cider", 3);
    add_recipe("Bug Brew", "brew", 20, 28, false, "Bug", 3);
    add_recipe("Slug Brew", "brew", 20, 28, false, "Slug", 3);
    add_recipe("Ooze Booze", "brew", 12, 18, false, "Ooze", 3);
    add_recipe("Shale Ale", "brew", 16, 24, false, "Stone", 3);
    add_recipe("Snakebite Ale", "brew", 18, 26, false, "Snake Oil", 1);
    add_recipe("Moonshine", "brew", 40, 50, false, "Iridium Ore", 3);
}
//-------------------------------------------------------------------
Player NPC::gift_item(Player p)
{
    cin.ignore(1000, '\n');
    cout << "what would you like to give " << get_name() << "? ";
    string item_name;
    getline(cin, item_name);

    if (p.remove_item(item_name))
    {
        react_to_gift(item_name, 50);
        set_friendship(get_friendship() + 2);
    }
    else
    {
        cout << "you don't have " << item_name << "." << endl;
    }
    return p;
}
//-------------------------------------------------------------------
Player NPC::train(Player p)
{
    if (p.get_energy() >= 10)
    {
        p.set_energy(p.get_energy() - 10);
        p.set_trained(true);
        cout << "splinter puts you through a grueling regimen... you feel stronger." << endl;
    }
    else
    {
        cout << "you're too exhausted to train right now." << endl;
    }
    return p;
}
//-------------------------------------------------------------------
Player NPC::remy_chat(Player p)
{
    if (p.get_energy() >= 3)
    {
        p.set_energy(p.get_energy() - 3);
        set_friendship(get_friendship() + 2);

        if (get_friendship() >= 10)
        {
            cout << "remy grins. \"good to see you again -- let me know if you want me cooking something up for the others too.\"" << endl;
        }
        else
        {
            cout << "remy chats with you for a while. you feel a bit closer." << endl;
        }
    }
    else
    {
        cout << "you're too tired to chat right now." << endl;
    }
    return p;
}
//-------------------------------------------------------------------
Player NPC::craft_menu(Player p)
{
    bool crafting = true;
    while (crafting)
    {
        cout << get_name() << "'s recipes:" << endl;
        for (int i = 0; i < recipe_count; i++)
        {
            cout << i + 1 << ". " << known_recipes[i].result_name << " (needs " << known_recipes[i].ingredient_qty << " " << known_recipes[i].ingredient_name << ")" << endl;
        }
        cout << "[0] [exit]" << endl;

        int choice;
        cin >> choice;

        if (choice == 0)
        {
            crafting = false;
        }
        else if (choice >= 1 && choice <= recipe_count)
        {
            recipe r = known_recipes[choice - 1];
            if (p.count_item(r.ingredient_name) >= r.ingredient_qty)
            {
                for (int i = 0; i < r.ingredient_qty; i++)
                {
                    p.remove_item(r.ingredient_name);
                }
                p.add_item(r.result_name);
                cout << "you crafted " << r.result_name << "!" << endl;
            }
            else
            {
                cout << "you need " << r.ingredient_qty << " " << r.ingredient_name << "." << endl;
            }
        }
        else
        {
            cout << "[invalid input, try again]" << endl;
        }
    }
    return p;
}
//-------------------------------------------------------------------
Player NPC::magic_shortcut(Player p)
{
    if (p.get_penalty() > 0)
    {
        cout << "the magic is already bound to you." << endl;
    }
    else if (p.get_energy() >= 50)
    {
        p.set_energy(p.get_energy() - 50);
        p.set_penalty(1);
        cout << "razmona binds a strange spell to you. the dwarf gate should answer to it." << endl;
    }
    else
    {
        cout << "you need 50 energy for the spell." << endl;
    }
    return p;
}
//-------------------------------------------------------------------
Player NPC::tortus_shop_menu(Player p)
{
    bool shopping = true;
    while (shopping)
    {
        cout << get_relationmod() << get_name() << "'s workshop!" << endl;
        cout << "(1) forge" << endl;
        cout << "(2) sledge" << endl;
        cout << "(4) [gift]" << endl;
        cout << "(5) [character info]" << endl;
        cout << "[0] [exit]" << endl;

        int choice;
        cin >> choice;

        switch (choice)
        {
            case 1: p = craft_menu(p); break;
            case 2: cout << "the paths through the caves are already clear." << endl; break;
            case 4: p = gift_item(p); break;
            case 5: cout << get_dialogue() << endl; break;
            case 0: shopping = false; break;
            default: cout << "[invalid input, try again]" << endl;
        }
    }
    return p;
}
//-------------------------------------------------------------------
Player NPC::remy_shop_menu(Player p)
{
    bool shopping = true;
    while (shopping)
    {
        cout << get_relationmod() << get_name() << "'s kitchen!" << endl;
        cout << "(1) cook" << endl;
        cout << "(2) chat" << endl;
        cout << "(4) [gift]" << endl;
        cout << "(5) [character info]" << endl;
        cout << "[0] [exit]" << endl;

        int choice;
        cin >> choice;

        switch (choice)
        {
            case 1: p = craft_menu(p); break;
            case 2: p = remy_chat(p); break;
            case 4: p = gift_item(p); break;
            case 5: cout << get_dialogue() << endl; break;
            case 0: shopping = false; break;
            default: cout << "[invalid input, try again]" << endl;
        }
    }
    return p;
}
//-------------------------------------------------------------------
Player NPC::splinter_shop_menu(Player p)
{
    bool shopping = true;
    while (shopping)
    {
        cout << get_relationmod() << get_name() << "'s shop!" << endl;
        cout << "(1) train" << endl;
        cout << "(2) buy/sell" << endl;
        cout << "(4) [gift]" << endl;
        cout << "(5) [character info]" << endl;
        cout << "[0] [exit]" << endl;

        int choice;
        cin >> choice;

        switch (choice)
        {
            case 1: p = train(p); break;
            case 2: cout << "splinter's shelves are picked clean." << endl; break;
            case 4: p = gift_item(p); break;
            case 5: cout << get_dialogue() << endl; break;
            case 0: shopping = false; break;
            default: cout << "[invalid input, try again]" << endl;
        }
    }
    return p;
}
//-------------------------------------------------------------------
Player NPC::razmona_shop_menu(Player p)
{
    bool shopping = true;
    while (shopping)
    {
        cout << get_relationmod() << get_name() << "'s lab!" << endl;
        cout << "(1) brew" << endl;
        cout << "(2) imbue [50 energy]" << endl;
        cout << "(4) [gift]" << endl;
        cout << "(5) [character info]" << endl;
        cout << "[0] [exit]" << endl;

        int choice;
        cin >> choice;

        switch (choice)
        {
            case 1: p = craft_menu(p); break;
            case 2: p = magic_shortcut(p); break;
            case 4: p = gift_item(p); break;
            case 5: cout << get_dialogue() << endl; break;
            case 0: shopping = false; break;
            default: cout << "[invalid input, try again]" << endl;
        }
    }
    return p;
}
//-------------------------------------------------------------------
void NPC::interact()
{
    bool in_shop = true;
    while (in_shop)
    {
        cout << get_name() << "'s shop!" << endl;
        cout << "(1) " << o1 << endl;
        cout << "(2) " << o2 << endl;
        cout << "(3) " << o3 << endl;
        cout << "(4) " << o4 << endl;
        cout << "(5) " << o5 << endl;
        cout << "[0] [exit]" << endl;

        int choice;
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "[" << o1 << " -- tbd]" << endl;
                break;
            case 2:
                cout << "[" << o2 << " -- tbd]" << endl;
                break;
            case 3:
                cout << "[" << o3 << " -- tbd]" << endl;
                break;
            case 4:
                cout << "[" << o4 << " -- tbd]" << endl;
                break;
            case 5:
                cout << dialogue << endl;
                break;
            case 0:
                in_shop = false;
                break;
            default:
                cout << "[invalid input, try again]" << endl;
                break;
        }
    }
}
