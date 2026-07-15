#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "char.h"
#include "char_player.h"
#include "char_npc.h"
#include "loc.h"
//#include "item.h" (wip)
using namespace std;
//-------------------------------------------------------------------
//loads loc.txt
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
        string description;
        getline(in_file, description);

        string flagline;
        getline(in_file, flagline);

        Location loc(name, description, flagline == "1");

        string connline;
        while (getline(in_file, connline) && connline != "END")
        {
            loc.add_connection(connline);
        }

        string itemline;
        while (getline(in_file, itemline) && itemline != "END")
        {
            loc.add_item(itemline);
        }

        locs.push_back(loc);
    }

    in_file.close();
    return locs;
}
//-------------------------------------------------------------------
//loads npcs
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
        string loc;
        getline(in_file, loc);
 
        string faction;
        getline(in_file, faction);
 
        string dialogue;
        getline(in_file, dialogue);
 
        string greeting;
        getline(in_file, greeting);
 
        string o1;
        getline(in_file, o1);
 
        string o2;
        getline(in_file, o2);
 
        string o3;
        getline(in_file, o3);
 
        string o4;
        getline(in_file, o4);
 
        string o5;
        getline(in_file, o5);
 
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
//find, validate loc by index
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
//-------------------------------------------------------------------
//travel custom instructions matching ascii map (wip)
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
        if (dir == 'd' || dir == 'D') return "Caves";
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
        if (dir == 's' || dir == 'S') return "Caves";
        }
    else if (current == "Caves")
        {
        if (dir == 'w' || dir == 'W') return "DeepCaves";
        if (dir == 'a' || dir == 'A') return "Sewers";
        if (dir == 's' || dir == 'S') return "WaterHole";
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
        if (dir == 'd' || dir == 'D') return "WaterHole";
        }
    else if (current == "WaterHole")
        {
        if (dir == 'w' || dir == 'W') return "Caves";
        if (dir == 'a' || dir == 'A') return "Laboratory";
        }
    else if (current == "Gate")
        {
        if (dir == 'a' || dir == 'A') return "Caves";
        if (dir == 'd' || dir == 'D') return "Lair";
        }
    else if (current == "Lair")
        {
        if (dir == 'a' || dir == 'A') return "Gate";
        }
    return "";
}
//-------------------------------------------------------------------
//map display
void display_map(int difficulty)
{
    if (difficulty == 0) //bright
    {
        cout << "| (burrows)-( workshop )-(deep caves)--\\________ __ " << endl;
        cout << "|        \\      /          /            |        |  |" << endl;
        cout << "| (bed)--(sewers)------(caves)--(gate)--{ (lair) |):|" << endl;
        cout << "|        /      \\          \\            |________|__|" << endl;
        cout << "| (kitchen)-(laboratory)-(water hole)--/            " << endl;
    }
    else if (difficulty == 1) //dim -- tbd
    {
        cout << "| (burrows)-( workshop )-(deep caves)--\\________ __ " << endl;
        cout << "|        \\      /          /            |        |  |" << endl;
        cout << "| (bed)--(sewers)------(caves)--(gate)--{ (lair) |):|" << endl;
        cout << "|        /      \\          \\            |________|__|" << endl;
        cout << "| (kitchen)-(laboratory)-(water hole)--/            " << endl;
    }
    else if (difficulty == 2) //dark -- tbd
    {
        cout << "| (burrows)-( workshop )-(deep caves)--\\________ __ " << endl;
        cout << "|        \\      /          /            |        |  |" << endl;
        cout << "| (bed)--(sewers)------(caves)--(gate)--{ (lair) |):|" << endl;
        cout << "|        /      \\          \\            |________|__|" << endl;
        cout << "| (kitchen)-(laboratory)-(water hole)--/            " << endl;
    }
    else if (difficulty == 3) //blackout -- tbd
    {
        cout << "| (burrows)-( workshop )-(deep caves)--\\________ __ " << endl;
        cout << "|        \\      /          /            |        |  |" << endl;
        cout << "| (bed)--(sewers)------(caves)--(gate)--{ (lair) |):|" << endl;
        cout << "|        /      \\          \\            |________|__|" << endl;
        cout << "| (kitchen)-(laboratory)-(water hole)--/            " << endl;
    }
}
//-------------------------------------------------------------------
//inv category display (wip)
void display_inventory_menu()
{
    cout << "--- item (#) ---" << endl;
    cout << "(1) mineloot" << endl;
    cout << "(2) food" << endl;
    cout << "(3) brews" << endl;
    cout << "(4) blades" << endl;
    cout << "(5) armor" << endl;
    cout << "(6) equippables" << endl;
    cout << "(7) craftables" << endl;
    cout << "(8) giftables" << endl;
    cout << "(9) ransomwares" << endl;
    cout << "(0) [to exit]" << endl;
}
//-------------------------------------------------------------------
//"giftable" interface
void display_gift_reaction(string npc_name, string item_name, int tier)
{
    if (tier == 1)
    {
        cout << "* " << item_name << " * - " << npc_name << " might like this?" << endl;
    }
    else if (tier == 2)
    {
        cout << "* " << item_name << " * - " << npc_name << " would like this" << endl;
    }
    else if (tier == 3)
    {
        cout << "* " << item_name << " * - " << npc_name << " would love this!" << endl;
    }
}
//-------------------------------------------------------------------
//"ransomable" interface
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
//-------------------------------------------------------------------
//equipped display 
void display_equipped(string blade, string armor, string q1, string q2, string scroll)
{
    cout << "equipped: [ " << blade << " ]-[ " << armor << " ]-[ " << q1 << " ]-[ " << q2 << " ]-[ " << scroll << " ]" << endl;
}
//-------------------------------------------------------------------
//opening scene/difficulty choice
int display_intro()
{
    cout << "you open your eyes..." << endl;
    cout << endl;
    cout << "(1) light    [1000 to win]" << endl;
    cout << "(2) dim      [2000 to win]" << endl;
    cout << "(3) dark     [3000 to win]" << endl;
    cout << "(4) blackout [4000 to win]" << endl;

    int diff_choice;
    cin >> diff_choice;

    int difficulty;

    if (diff_choice == 1)
    {
        cout << "...in a *light* room..." << endl;
        difficulty = 0;
    }
    else if (diff_choice == 2)
    {
        cout << "...in a *dim* room..." << endl;
        difficulty = 1;
    }
    else if (diff_choice == 3)
    {
        cout << "...in a *dark* room..." << endl;
        difficulty = 2;
    }
    else if (diff_choice == 4)
    {
        cout << "...and see nothing at all." << endl;
        difficulty = 3;
    }
    else
    {
        cout << "...in a *light* room." << endl;
        difficulty = 0;
    }

    cout << endl;
    return difficulty;
}
//-------------------------------------------------------------------
//-------------------------------------------------------------------
//-------------------------------------------------------------------
int main()
{
    bool ingame = true;

    cout << "==================================================" << endl;
    cout << "========[placeholder name: free krobus!!]=========" << endl;
    cout << "==================================================" << endl;

    string playername;
    cout << "who are you? :";
    cin >> playername;
    cout << "player name recorded, hello " << playername << "!" << endl;

    int difficulty = display_intro();

    vector<Location> locs = load_locs("loc.txt");

    string starting_loc = "Bed";
    Player player(playername, starting_loc, 10, 10, 0, 1);

    vector<NPC> npcs = load_npcs("char_npc.txt");
//-------------------------------------------------------------------
//main game loop
    while (ingame)
    {
        int idx = find_location_index(locs, player.get_location());

        cout << "==================================================" << endl;
        cout << "[hour: " << player.get_time() << "] --- [" << player.get_location() << "]" << endl;
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
                bool found = false;
                for (int i = 0; i < npcs.size(); i++)
                    {
                    if (npcs[i].get_location() == player.get_location())
                        {
                        npcs[i].interact();
                        found = true;
                        break;
                        }
                    }
                if (!found)
                    {
                    //wip
                    }
                break;
            }
//-------------------------------------------------------------------
//travel interface, wip to make more streamlined
    case 'w':
    case 'W':
    {
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
//-------------------------------------------------------------------
//determines travel time, marks first visit
                player.set_location(dest);
                player.set_time(player.get_time() + 1); 
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
                break;
    }
//-------------------------------------------------------------------
//inventory display functionality (wip)
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
                    case 1: case 2: case 3: case 4: case 5:
                    case 6: case 7: case 8: case 9:
                        player.display_inventory();
                        break;
                    default:
                        cout << "[invalid input, try again]" << endl;
                        break;
                }
                break;
                }

//-------------------------------------------------------------------
//map display
            case 's':
            case 'S':
                display_map(difficulty);
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