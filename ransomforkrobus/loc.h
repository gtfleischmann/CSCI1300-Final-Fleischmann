#ifndef LOC_H
#define LOC_H
#include <string>
#include <vector>
using namespace std;
//-------------------------------------------------------------------
class Location
{
private:
    string name;
    string description;
    bool unlocked;
    bool visited;
    vector<string> connections;
    vector<string> loc_items;

public:
    Location(string name, string description, bool unlocked);

    string get_name();
    string get_description();
    bool is_unlocked();
    void unlock();
    bool has_been_visited();
    void mark_visited();

    void add_connection(string loc);
    vector<string> get_connections();
    bool connects_to(string loc);

    void add_item(string x);
    bool remove_item(string x);
    vector<string> get_items();

    void display();
};

#endif