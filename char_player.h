#ifndef CHAR_PLAYER_H
#define CHAR_PLAYER_H
#include "char.h"

class Player : public Character
{
private:
    int light;
    int funds;
    int time;
    int penalty;

public:
    Player(string playername, string loc, int energy, int light, int funds, int time);

    int get_light();
    void set_light(int l);

    int get_funds();
    void set_funds(int f);

    int get_time();
    void set_time(int t);

    int get_penalty();
    void set_penalty(int p);
};

#endif