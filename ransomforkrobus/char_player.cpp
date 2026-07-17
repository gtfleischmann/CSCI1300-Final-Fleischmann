#include "char_player.h"

Player::Player(string playername, string loc, int energy, int light, int funds, int time) : Character(playername, loc, energy)
{
    this->light = light;
    this->funds = funds;
    this->time = time;
    penalty = 0;
    equipped_blade = "";
    equipped_armor = "";
    equipped_shield = "";
    trained = false;
}

int Player::get_light() { return light; }
void Player::set_light(int l) { light = l; }

int Player::get_funds() { return funds; }
void Player::set_funds(int f) { funds = f; }

int Player::get_time() { return time; }
void Player::set_time(int t) { time = t; }

int Player::get_penalty() { return penalty; }
void Player::set_penalty(int p) { penalty = p; }

string Player::get_equipped_blade() { return equipped_blade; }
void Player::equip_blade(string item_name, int item_combat)
{
    equipped_blade = item_name;
    set_combat(item_combat);
}

string Player::get_equipped_armor() { return equipped_armor; }
void Player::equip_armor(string item_name)
{
    equipped_armor = item_name;
}

string Player::get_equipped_shield() { return equipped_shield; }
void Player::equip_shield(string item_name)
{
    equipped_shield = item_name;
}

bool Player::get_trained() { return trained; }
void Player::set_trained(bool t) { trained = t; }

int Player::apply_protection(int incoming_damage)
{
    int mitigation = 0;
    if (equipped_armor != "")
    {
        mitigation += 25;
    }
    if (equipped_shield != "")
    {
        mitigation += 25;
    }

    int reduced = incoming_damage - (incoming_damage * mitigation / 100);
    if (reduced < 0)
    {
        reduced = 0;
    }
    return reduced;
}
