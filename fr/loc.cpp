#include "loc.h"
#include <iostream>

Location::Location(string name, string description, bool unlocked)
    {
    this->name = name;
    this->description = description;
    this->unlocked = unlocked;
    visited = false;
    }

string Location::get_name() { return name; }
string Location::get_description() { return description; }
bool Location::is_unlocked() { return unlocked; }
void Location::unlock() { unlocked = true; }
bool Location::has_been_visited() { return visited; }
void Location::mark_visited() { visited = true; }

void Location::add_connection(string loc)
    {
    connections.push_back(loc);
    }

vector<string> Location::get_connections() { return connections; }
//-------------------------------------------------------------------
bool Location::connects_to(string loc)
    {
    for (int i = 0; i < connections.size(); i++)
        {
        if (connections[i] == loc)
            {
            return true;
            }
        }
            return false;
}
//-------------------------------------------------------------------
void Location::add_item(string x)
    {
    loc_items.push_back(x);
    }
//-------------------------------------------------------------------
bool Location::remove_item(string x)
{
    bool found = false;
    vector<string> itemsnew;

    for (int i = 0; i < loc_items.size(); i++)
    {
        if (loc_items[i] == x && !found)
            {
            found = true;
            }
        else
            {
            itemsnew.push_back(loc_items[i]);
            }
    }

    loc_items = itemsnew;
    return found;
}
//-------------------------------------------------------------------
vector<string> Location::get_items() { return loc_items; }

void Location::display()
{
cout << "-- " << name << " --" << endl;
cout << description << endl;
}