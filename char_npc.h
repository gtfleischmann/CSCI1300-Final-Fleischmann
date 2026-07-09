#ifndef CHAR_NPC_H
#define CHAR_NPC_H
#include "char.h"

class NPC : public Character
{
private:
    int relation;
    string dialogue;
    string faction;
    string quest;

public:
    NPC(string name, string loc, int energy, string faction);

    int get_relation();
    void set_relation(int r);

    string get_dialogue();
    void set_dialogue(string d);

    string get_faction();
    void set_faction(string f);

    string get_quest();
    void set_quest(string q);
};

#endif