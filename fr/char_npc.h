#ifndef CHAR_NPC_H
#define CHAR_NPC_H
#include "char.h"

class NPC : public Character
{
private:
    bool relation;
    string dialogue;
    string faction;
    string greeting;
    string o1;
    string o2;
    string o3;
    string o4;
    string o5;

public:
    NPC(string name, string loc, int energy, string faction);

    bool get_relation();
    void set_relation(bool r);

    string get_dialogue();
    void set_dialogue(string d);

    string get_faction();
    void set_faction(string f);

    string get_greeting();
    void set_greeting(string g);

//shop options
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

    void interact();
};

#endif