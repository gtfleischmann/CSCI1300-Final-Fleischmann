#include "char_player.h"

Player::Player(string playername, string loc, int energy, int light, int funds, int time) : Character(playername, loc, energy)
{
    this->light = light;
    this->funds = funds;
    this->time = time;
    penalty = 0;
}

int Player::get_light() { return light; }
void Player::set_light(int l) { light = l; }

int Player::get_funds() { return funds; }
void Player::set_funds(int f) { funds = f; }

int Player::get_time() { return time; }
void Player::set_time(int t) { time = t; }

int Player::get_penalty() { return penalty; }
void Player::set_penalty(int p) { penalty = p; }