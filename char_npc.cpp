#include "char_npc.h"

NPC::NPC(string name, string loc, int energy, string faction) : Character(name, loc, energy)
{
    relation = 0;
    dialogue = "[placeholder]";
    this->faction = faction;
    quest = "[placeholder]";
}

int NPC::get_relation() { return relation; }
void NPC::set_relation(int r) { relation = r; }

string NPC::get_dialogue() { return dialogue; }
void NPC::set_dialogue(string d) { dialogue = d; }

string NPC::get_faction() { return faction; }
void NPC::set_faction(string f) { faction = f; }

string NPC::get_quest() { return quest; }
void NPC::set_quest(string q) { quest = q; }