#include <iostream>
#include "char.h"
#include "char_player.h"
#include "char_npc.h"
using namespace std;

//future functions?

int main() 
{

bool ingame = true;

cout << "==================================================" << endl;
cout << "========[placeholder name: FREE KROBUS!!]=========" << endl;
cout << "==================================================" << endl;

string playername;
cout << "who are you? :";
cin >> playername;
cout << "player name recorded, hello " << playername << "!" << endl;

int hour = 1;
string loc = "[STARTING LOCATION]";

Player player(playername, loc, 10, 10, 0, 1);

while (ingame) 
    {

        cout << "==================================================" << endl;
        cout << "[hour: " << hour << "] --- [" << loc << "]" << endl;
        cout << "==================================================" << endl;

        cout << endl;
        cout << "[Work in progress! narrator messages/location context etc will be here in the final game. ]" << endl;
        cout << endl;

        cout << "You can:" << endl;
        cout << "[Q] Interact" << endl;
        cout << "[W] Travel" << endl;
        cout << "[E] Access Inventory" << endl;
        cout << "[Z] Access Settings" << endl;
        cout << "[X] Quit" << endl;
        cout << "==================================================" << endl;

        char choice;
        cin >> choice;

        switch (choice) 
        {
            case 'Q':
                cout << "[placeholder: interact]" << endl;
                break;
            case 'W':
                cout << "[placeholder: travel]" << endl;
                break;
            case 'E':
                cout << "[placeholder: inventory check]" << endl;
                break;
            case 'Z':
                cout << "[placeholder: settings]" << endl;
                break;
            case 'X':
                ingame = false;
                cout << "[placeholder: 'are you sure you want to quit?']" << endl;
                break;
        default:
                cout << "[placeholder: 'invalid input, try again:']" << endl;
                break;
        }

        cout << endl;
    }

    return 0;
}