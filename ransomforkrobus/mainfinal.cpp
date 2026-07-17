#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include "char.h"
#include "char_player.h"
#include "char_npc.h"
#include "loc.h"
#include "game.h"
using namespace std;

string clean_line(string line)
{
    if (line.size() > 0 && line[line.size() - 1] == '\r')
    {
        line = line.substr(0, line.size() - 1);
    }
    return line;
}
//-------------------------------------------------------------------
vector<Location> load_locs(string filename)
{
    vector<Location> locs;
    ifstream in_file(filename);

    if (!in_file.is_open())
    {
        cout << "warning: could not open " << filename << endl;
        return locs;
    }

    string name;
    while (getline(in_file, name))
    {
        name = clean_line(name);

        string description;
        getline(in_file, description);
        description = clean_line(description);

        string flagline;
        getline(in_file, flagline);
        flagline = clean_line(flagline);

        Location loc(name, description, flagline == "1");

        string connline;
        while (getline(in_file, connline))
        {
            connline = clean_line(connline);
            if (connline == "END")
            {
                break;
            }
            loc.add_connection(connline);
        }

        string itemline;
        while (getline(in_file, itemline))
        {
            itemline = clean_line(itemline);
            if (itemline == "END")
            {
                break;
            }
            loc.add_item(itemline);
        }

        locs.push_back(loc);
    }

    in_file.close();
    return locs;
}
//-------------------------------------------------------------------
vector<NPC> load_npcs(string filename)
{
    vector<NPC> npcs;
    ifstream in_file(filename);

    if (!in_file.is_open())
    {
        cout << "warning: could not open " << filename << endl;
        return npcs;
    }

    string name;
    while (getline(in_file, name))
    {
        name = clean_line(name);

        string loc;
        getline(in_file, loc);
        loc = clean_line(loc);

        string faction;
        getline(in_file, faction);
        faction = clean_line(faction);

        string dialogue;
        getline(in_file, dialogue);
        dialogue = clean_line(dialogue);

        string greeting;
        getline(in_file, greeting);
        greeting = clean_line(greeting);

        string o1;
        getline(in_file, o1);
        o1 = clean_line(o1);

        string o2;
        getline(in_file, o2);
        o2 = clean_line(o2);

        string o3;
        getline(in_file, o3);
        o3 = clean_line(o3);

        string o4;
        getline(in_file, o4);
        o4 = clean_line(o4);

        string o5;
        getline(in_file, o5);
        o5 = clean_line(o5);

        NPC n(name, loc, 10, faction);
        n.set_dialogue(dialogue);
        n.set_greeting(greeting);
        n.set_o1(o1);
        n.set_o2(o2);
        n.set_o3(o3);
        n.set_o4(o4);
        n.set_o5(o5);

        npcs.push_back(n);
    }

    in_file.close();
    return npcs;
}
//-------------------------------------------------------------------

int find_location_index(vector<Location> locs, string name)
{
    for (int i = 0; i < locs.size(); i++)
    {
        if (locs[i].get_name() == name)
        {
            return i;
        }
    }
    return -1;
}

string get_travel_target(string current, char dir)
{
    if (current == "Bed")
        {
        if (dir == 'd' || dir == 'D') return "Sewers";
        }
    else if (current == "Sewers")
        {
        if (dir == 'w' || dir == 'W') return "Burrows";
        if (dir == 'a' || dir == 'A') return "Bed";
        if (dir == 's' || dir == 'S') return "Kitchen";
        if (dir == 'd' || dir == 'D') return "Mines";
        }
    else if (current == "Burrows")
        {
        if (dir == 'd' || dir == 'D') return "Workshop";
        if (dir == 's' || dir == 'S') return "Sewers";
        }
    else if (current == "Workshop")
        {
        if (dir == 'a' || dir == 'A') return "Burrows";
        if (dir == 'd' || dir == 'D') return "DeepCaves";
        }
    else if (current == "DeepCaves")
        {
        if (dir == 'a' || dir == 'A') return "Workshop";
        if (dir == 's' || dir == 'S') return "Mines";
        }
    else if (current == "Mines")
        {
        if (dir == 'w' || dir == 'W') return "DeepCaves";
        if (dir == 'a' || dir == 'A') return "Sewers";
        if (dir == 's' || dir == 'S') return "Caves";
        if (dir == 'd' || dir == 'D') return "Gate";
        }
    else if (current == "Kitchen")
        {
        if (dir == 'w' || dir == 'W') return "Sewers";
        if (dir == 'd' || dir == 'D') return "Laboratory";
        }
    else if (current == "Laboratory")
        {
        if (dir == 'a' || dir == 'A') return "Kitchen";
        if (dir == 'd' || dir == 'D') return "Caves";
        }
    else if (current == "Caves")
        {
        if (dir == 'w' || dir == 'W') return "Mines";
        if (dir == 'a' || dir == 'A') return "Laboratory";
        }
    else if (current == "Gate")
        {
        if (dir == 'a' || dir == 'A') return "Mines";
        if (dir == 'd' || dir == 'D') return "Lair";
        }
    else if (current == "Lair")
        {
        if (dir == 'a' || dir == 'A') return "Gate";
        }
    return "";
}

void display_map(string current)
{
    if (current == "Bed")
    {
        cout << "| (burrows)-(tortus' den)-(deep caves)--\\________ __ " << endl;
        cout << "|        \\      /          /            |        |  |" << endl;
        cout << "| [BED]--(sewers)------(mines)--(gate)--{ (lair) |):|" << endl;
        cout << "|        /      \\          \\            |________|__|" << endl;
        cout << "| (kitchen)-(alchemy lab)-(caves)--/            " << endl;
    }
    else if (current == "Sewers")
    {
        cout << "| (burrows)-(tortus' den)-(deep caves)--\\________ __ " << endl;
        cout << "|        \\      /          /            |        |  |" << endl;
        cout << "| (bed)--[SEWERS]------(mines)--(gate)--{ (lair) |):|" << endl;
        cout << "|        /      \\          \\            |________|__|" << endl;
        cout << "| (kitchen)-(alchemy lab)-(caves)--/            " << endl;
    }
    else if (current == "Burrows")
    {
        cout << "| [BURROWS]-(tortus' den)-(deep caves)--\\________ __ " << endl;
        cout << "|        \\      /          /            |        |  |" << endl;
        cout << "| (bed)--(sewers)------(mines)--(gate)--{ (lair) |):|" << endl;
        cout << "|        /      \\          \\            |________|__|" << endl;
        cout << "| (kitchen)-(alchemy lab)-(caves)--/            " << endl;
    }
    else if (current == "Kitchen")
    {
        cout << "| (burrows)-(tortus' den)-(deep caves)--\\________ __ " << endl;
        cout << "|        \\      /          /            |        |  |" << endl;
        cout << "| (bed)--(sewers)------(mines)--(gate)--{ (lair) |):|" << endl;
        cout << "|        /      \\          \\            |________|__|" << endl;
        cout << "| [KITCHEN]-(alchemy lab)-(caves)--/            " << endl;
    }
    else if (current == "Workshop")
    {
        cout << "| (burrows)-[TORTUS' DEN]-(deep caves)--\\________ __ " << endl;
        cout << "|        \\      /          /            |        |  |" << endl;
        cout << "| (bed)--(sewers)------(mines)--(gate)--{ (lair) |):|" << endl;
        cout << "|        /      \\          \\            |________|__|" << endl;
        cout << "| (kitchen)-(alchemy lab)-(caves)--/            " << endl;
    }
    else if (current == "Laboratory")
    {
        cout << "| (burrows)-(tortus' den)-(deep caves)--\\________ __ " << endl;
        cout << "|        \\      /          /            |        |  |" << endl;
        cout << "| (bed)--(sewers)------(mines)--(gate)--{ (lair) |):|" << endl;
        cout << "|        /      \\          \\            |________|__|" << endl;
        cout << "| (kitchen)-[ALCHEMY LAB]-(caves)--/            " << endl;
    }
    else if (current == "Mines")
    {
        cout << "| (burrows)-(tortus' den)-(deep caves)--\\________ __ " << endl;
        cout << "|        \\      /          /            |        |  |" << endl;
        cout << "| (bed)--(sewers)------[MINES]--(gate)--{ (lair) |):|" << endl;
        cout << "|        /      \\          \\            |________|__|" << endl;
        cout << "| (kitchen)-(alchemy lab)-(caves)--/            " << endl;
    }
    else if (current == "DeepCaves")
    {
        cout << "| (burrows)-(tortus' den)-[DEEP CAVES]--\\________ __ " << endl;
        cout << "|        \\      /          /            |        |  |" << endl;
        cout << "| (bed)--(sewers)------(mines)--(gate)--{ (lair) |):|" << endl;
        cout << "|        /      \\          \\            |________|__|" << endl;
        cout << "| (kitchen)-(alchemy lab)-(caves)--/            " << endl;
    }
    else if (current == "Caves")
    {
        cout << "| (burrows)-(tortus' den)-(deep caves)--\\________ __ " << endl;
        cout << "|        \\      /          /            |        |  |" << endl;
        cout << "| (bed)--(sewers)------(mines)--(gate)--{ (lair) |):|" << endl;
        cout << "|        /      \\          \\            |________|__|" << endl;
        cout << "| (kitchen)-(alchemy lab)-[CAVES]--/            " << endl;
    }
    else if (current == "Gate")
    {
        cout << "| (burrows)-(tortus' den)-(deep caves)--\\________ __ " << endl;
        cout << "|        \\      /          /            |        |  |" << endl;
        cout << "| (bed)--(sewers)------(mines)--[GATE]--{ (lair) |):|" << endl;
        cout << "|        /      \\          \\            |________|__|" << endl;
        cout << "| (kitchen)-(alchemy lab)-(caves)--/            " << endl;
    }
    else if (current == "Lair")
    {
        cout << "| (burrows)-(tortus' den)-(deep caves)--\\________ __ " << endl;
        cout << "|         \\                /            |        |  |" << endl;
        cout << "| (bed)--(sewers)------(mines)--(gate)--{ [LAIR] |):|" << endl;
        cout << "|         /                \\            |________|__|" << endl;
        cout << "| (kitchen)-(alchemy lab)-(caves)--/            " << endl;
    }
}

void display_days(int current_day)
{
    if (current_day == 1)
    {
        cout << "DAY: [1]-X-X-X-X-X-X" << endl;
    }
    else if (current_day == 2)
    {
        cout << "DAY: 1-[2]-X-X-X-X-X" << endl;
    }
    else if (current_day == 3)
    {
        cout << "DAY: 1-2-[3]-X-X-X-X" << endl;
    }
    else if (current_day == 4)
    {
        cout << "DAY: 1-2-3-[4]-X-X-X" << endl;
    }
    else if (current_day == 5)
    {
        cout << "DAY: 1-2-3-4-[5]-X-X" << endl;
    }
    else if (current_day == 6)
    {
        cout << "DAY: 1-2-3-4-5-[6]-X" << endl;
    }
    else if (current_day == 7)
    {
        cout << "DAY: 1-2-3-4-5-6-[7]" << endl;
    }
    else
    {
        cout << "DAY: X-X-X-X-X-X-X" << endl;
    }
}

int mining_tier_for_location(string loc_name)
{
    if (loc_name == "Mines")
    {
        return 1;
    }
    if (loc_name == "Caves")
    {
        return 2;
    }
    if (loc_name == "DeepCaves")
    {
        return 3;
    }
    return 0;
}

void display_inventory_menu()
{
    cout << "--- item (#) ---" << endl;
    cout << "(1) mineloot" << endl;
    cout << "(2) feast" << endl;
    cout << "(3) brew" << endl;
    cout << "(4) blades" << endl;
    cout << "(5) protection" << endl;
    cout << "(6) accessories" << endl;
    cout << "(7) scrolls" << endl;
    cout << "(8) jewels" << endl;
    cout << "(9) offerings" << endl;
    cout << "(0) [to exit]" << endl;
}

void display_ransom_reaction(string item_class, int tier)
{
    if (tier == 1)
    {
        cout << "* the king might like this " << item_class << "?" << endl;
    }
    else if (tier == 2)
    {
        cout << "* the king would like this " << item_class << endl;
    }
    else if (tier == 3)
    {
        cout << "* the king would love this " << item_class << "..." << endl;
    }
}

void display_equipped(string blade, string armor, string q1, string q2, string scroll)
{
    cout << "equipped: [ " << blade << " ]-[ " << armor << " ]-[ " << q1 << " ]-[ " << q2 << " ]-[ " << scroll << " ]" << endl;
}

int display_intro()
{
    cout << "you open your eyes..." << endl;
    cout << endl;
    cout << "(1) light    [7 days]" << endl;
    cout << "(2) dim      [6 days]" << endl;
    cout << "(3) dark     [5 days]" << endl;
    cout << "(4) blackout [4 days]" << endl;

    int diff_choice;
    cin >> diff_choice;

    int max_days;

    if (diff_choice == 1)
    {
        cout << "...in a *light* room..." << endl;
        max_days = 7;
    }
    else if (diff_choice == 2)
    {
        cout << "...in a *dim* room..." << endl;
        max_days = 6;
    }
    else if (diff_choice == 3)
    {
        cout << "...in a *dark* room..." << endl;
        max_days = 5;
    }
    else if (diff_choice == 4)
    {
        cout << "...and see nothing at all." << endl;
        max_days = 4;
    }
    else
    {
        cout << "...in a *light* room." << endl;
        max_days = 7;
    }

    cout << endl;
    return max_days;
}

int main()
{
    srand(time(0));
    bool ingame = true;

    cout << "========[A Ransom for Krobus]=========" << endl;
        cout << "========[CSCI1300 - Garrett Fleischmann]=========" << endl;


    string playername;
    cout << "who are you? :";
    cin >> playername;
    cout << "player name recorded, hello " << playername << "!" << endl;

    int max_days = display_intro();

    vector<Location> locs = load_locs("loc.txt");

    string starting_loc = "Bed";
    Player player(playername, starting_loc, 100, 10, 0, 1);
    player.add_item("Spiky Stone");
    player.equip_blade("Spiky Stone", 4);

    int start_idx = find_location_index(locs, starting_loc);
    if (start_idx != -1)
    {
        locs[start_idx].mark_visited();
    }

    vector<NPC> npcs = load_npcs("char_npc.txt");
    for (int i = 0; i < npcs.size(); i++)
    {
        if (npcs[i].get_name() == "Tortus")
        {
            npcs[i].load_tortus_recipes();
        }
        else if (npcs[i].get_name() == "Remy")
        {
            npcs[i].load_remy_recipes();
        }
        else if (npcs[i].get_name() == "Razmona")
        {
            npcs[i].load_razmona_recipes();
        }
    }
    Game game;
    cout << endl;
    game.show_dwarf_letter(player, max_days);
    cout << endl;

    while (ingame)
    {
        int idx = find_location_index(locs, player.get_location());

        cout << "==================================================" << endl;
        display_days(player.get_time());
        cout << "[" << player.get_location() << "] --- [energy: " << player.get_energy() << "]" << endl;
        cout << "==================================================" << endl;
            cout << endl;

        if (idx != -1)
            {
            locs[idx].display();
            }
            cout << endl;

        cout << "what will you do?" << endl;
        cout << "[Q] interact" << endl;
        cout << "[W] travel" << endl;
        cout << "[E] access inventory" << endl;
        cout << "[S] view map" << endl;
        cout << "[Z] access settings" << endl;
        cout << "[X] quit" << endl;
        cout << "==================================================" << endl;

        char choice;
        cin >> choice;

        switch (choice)
        {
            case 'q':
            case 'Q':
                {
                if (player.get_location() == "Bed")
                    {
                    cout << "you climb into bed and rest up..." << endl;
                    player.set_energy(100);
                    player.set_time(player.get_time() + 1);
                    cout << "[day " << player.get_time() << " begins]" << endl;

                    if (player.get_time() > max_days)
                        {
                        cout << "the dwarves' deadline has passed... you're out of time." << endl;
                        ingame = false;
                        }
                    break;
                    }

                if (player.get_location() == "Lair")
                    {
                    game.dwarf_king_encounter(player);
                    ingame = false;
                    break;
                    }
                else if (player.get_location() == "Gate")
                    {
                    if (game.can_enter_lair(player))
                        {
                        int lair_idx = find_location_index(locs, "Lair");
                        if (lair_idx != -1)
                            {
                            locs[lair_idx].unlock();
                            }
                        if (player.get_penalty() > 0)
                            {
                            cout << "razmona's magic answers the gate. the way to the lair is open." << endl;
                            }
                        else
                            {
                            cout << "the offerings answer the gate. the way to the lair is open." << endl;
                            }
                        }
                    else
                        {
                        cout << "the gate remains shut. you still need a blade, brew, feast, and jewel." << endl;
                        cout << "razmona's magic could also open it." << endl;
                        }
                    }
                else
                    {
                    int tier = mining_tier_for_location(player.get_location());
                    if (tier != 0)
                        {
                        player = game.resolve_mine_search(tier, player);
                        }
                    else
                        {
                        bool found = false;
                        for (int i = 0; i < npcs.size(); i++)
                            {
                            if (npcs[i].get_location() == player.get_location())
                                {
                                found = true;
                                string npc_name = npcs[i].get_name();
                                if (npc_name == "Tortus")
                                    {
                                    player = npcs[i].tortus_shop_menu(player);
                                    }
                                else if (npc_name == "Remy")
                                    {
                                    player = npcs[i].remy_shop_menu(player);
                                    }
                                else if (npc_name == "Splinter")
                                    {
                                    player = npcs[i].splinter_shop_menu(player);
                                    }
                                else if (npc_name == "Razmona")
                                    {
                                    player = npcs[i].razmona_shop_menu(player);
                                    }
                                else
                                    {
                                    npcs[i].interact();
                                    }
                                break;
                                }
                            }
                        if (!found)
                            {
                            cout << "[nobody to talk to here]" << endl;
                            }
                        }
                    }

                player.set_energy(player.get_energy() - 1);
                if (player.get_energy() <= 0)
                    {
                    cout << "you collapse from exhaustion! someone drags you back to bed..." << endl;
                    player.set_location("Bed");
                    player.set_energy(100);
                    player.set_time(player.get_time() + 1);

                    if (player.get_time() > max_days)
                        {
                        cout << "the dwarves' deadline has passed. you're out of time." << endl;
                        ingame = false;
                        }
                    }
                break;
            }

    case 'w':
    case 'W':
    {
                display_map(player.get_location());

                if (idx == -1)
                {
                    cout << "[can't travel this way]" << endl;
                    break;
                }
                string up = get_travel_target(player.get_location(), 'w');
                string left = get_travel_target(player.get_location(), 'a');
                string down = get_travel_target(player.get_location(), 's');
                string right = get_travel_target(player.get_location(), 'd');

                cout << "which way?" << endl;
                if (up != "") cout << "[W] up    -> " << up << endl;
                if (left != "") cout << "[A] left  -> " << left << endl;
                if (down != "") cout << "[S] down  -> " << down << endl;
                if (right != "") cout << "[D] right -> " << right << endl;

                char dir;
                cin >> dir;

                string dest = get_travel_target(player.get_location(), dir);

                if (dest == "")
                    {
                    cout << "[invalid input, try again]" << endl;
                    break;
                    }

                int dest_idx = find_location_index(locs, dest);
                if (dest_idx == -1 || !locs[dest_idx].is_unlocked())
                    {
                    cout << "that area isn't accessible yet." << endl;
                    break;
                    }

                player.set_location(dest);
                cout << "you travel to the " << dest << "." << endl;

                if (!locs[dest_idx].has_been_visited())
                {
                    for (int i = 0; i < npcs.size(); i++)
                    {
                    if (npcs[i].get_location() == dest)
                            {
                            cout << npcs[i].get_greeting() << endl;
                            break;
                            }
                    }
                    locs[dest_idx].mark_visited();
                }

                player.set_energy(player.get_energy() - 1);
                if (player.get_energy() <= 0)
                    {
                    cout << "you collapse from exhaustion! someone drags you back to bed..." << endl;
                    player.set_location("Bed");
                    player.set_energy(100);
                    player.set_time(player.get_time() + 1);

                    if (player.get_time() > max_days)
                        {
                        cout << "the dwarves' deadline has passed. you're out of time." << endl;
                        ingame = false;
                        }
                    }
                break;
    }

            case 'e':
            case 'E':
            {
                display_inventory_menu();
                int category;
                cin >> category;

                switch (category)
                {
                    case 0:
                        break;
                    case 4:
                        {
                        player.display_inventory();
                        cin.ignore(1000, '\n');
                        cout << "which blade will you equip? ";
                        string blade_name;
                        getline(cin, blade_name);
                        int blade_idx = game.find_item(blade_name);

                        if (blade_idx == -1 || !player.has_item(game.get_item(blade_idx).get_name()) || game.get_item(blade_idx).get_type() != "blade")
                            {
                            cout << "you don't have that blade." << endl;
                            }
                        else if (game.get_item(blade_idx).get_requires_strength() && !player.get_trained())
                            {
                            cout << "you need training before you can use that blade." << endl;
                            }
                        else
                            {
                            player.equip_blade(game.get_item(blade_idx).get_name(), game.get_item(blade_idx).get_power());
                            cout << "you equip " << game.get_item(blade_idx).get_name() << "." << endl;
                            }
                        break;
                        }
                    case 5:
                        {
                        player.display_inventory();
                        cin.ignore(1000, '\n');
                        cout << "which protection will you equip? ";
                        string protection_name;
                        getline(cin, protection_name);
                        int protection_idx = game.find_item(protection_name);

                        if (protection_idx == -1 || !player.has_item(game.get_item(protection_idx).get_name()) || game.get_item(protection_idx).get_type() != "protection")
                            {
                            cout << "you don't have that protection." << endl;
                            }
                        else if (game.get_item(protection_idx).get_name().find("Shield") != string::npos)
                            {
                            player.equip_shield(game.get_item(protection_idx).get_name());
                            cout << "you equip " << game.get_item(protection_idx).get_name() << "." << endl;
                            }
                        else
                            {
                            player.equip_armor(game.get_item(protection_idx).get_name());
                            cout << "you equip " << game.get_item(protection_idx).get_name() << "." << endl;
                            }
                        break;
                        }
                    case 1: case 2: case 3:
                    case 6: case 7: case 8: case 9:
                        player.display_inventory();
                        break;
                    default:
                        cout << "[invalid input, try again]" << endl;
                        break;
                }
                break;
                }

            case 's':
            case 'S':
                display_map(player.get_location());
                break;

            case 'z':
            case 'Z':
                cout << "[placeholder: settings]" << endl;
                break;

            case 'x':
            case 'X':
                {
                cout << "are you sure you want to quit? [Y] to confirm" << endl;
                char confirm;
                cin >> confirm;
                if (confirm == 'y' || confirm == 'Y')
                {
                    ingame = false;
                }
                break;
                }

            default:
                cout << "[invalid input, try again]" << endl;
                break;
        }

        cout << endl;
    }

    return 0;
}
