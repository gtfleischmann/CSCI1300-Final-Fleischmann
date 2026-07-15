#include "char_npc.h"
#include <iostream>

NPC::NPC(string name, string loc, int energy, string faction) : Character(name, loc, energy)
{
    relation = false;
    dialogue = "tbd";
    this->faction = faction;
    greeting = "tbd";
    o1 = "tbd";
    o2 = "tbd";
    o3 = "tbd";
    o4 = "tbd";
    o5 = "tbd";
}

bool NPC::get_relation() { return relation; }
void NPC::set_relation(bool r) { relation = r; }

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