# CSCI1300-Final-Fleischmann
"Ransom for Krobus"

## Theme

Stardew Valley is not so peaceful underground..
Its resident shadow-creature Krobus has been kidnapped and held for ransom by a rival faction of dwarves, and it's your task to free him in any way you can.
Will you use combat, bribery, diplomacy or magic? The choice is yours!

## Goal

The dwarf's ransom asks for
"the sharpest BLADE,	
the strongest BREW,	
the most flavorful FEAST,	
and the shiniest JEWEL"
that the player can get in time (within 4-7 days depending on difficulty).

The cumulative value points of all four bundle items determines ending dialogue and "win strength",
Additional options (wizard Razmoda's "joja" mechanic, combat) can provide alternate endings.

## How to compile and run

Compile in VSCode via the "terminalrun.txt" file or with the alternate "compile.ps1" txt.

## How to play

After selecting difficulty/time limit, the player can travel to/interact with various NPCs to fulfill bundle requirements:
Remy (kitchen) to craft feasts
Razmoda (laboratory) to brew brews
Tortus (workshop) to forge blades/armor
Splinter (burrows) for strength training
All four bundle items or their materials can be sourced in the mines and processed/gifted for alternate pathways.

## Classes

Character: contains (Player) and (NPC), with some shared attributes and relevant subclass traits for each (eg. time/energy/equipped items for player, crafting/"shop" mechanics for NPC's)
Location: contains each location's relevant locations/custom ASCII map, lock status and location-specific items/NPCs).
Item: contains name, power, value and type (sourced from 8 .txt files).
Game: contains miscellaneous features including:
- randomly-generated mine loot / mob encounter system (required <cstdlib> and <ctime> to generate and seed time)
- final dwarf king "ransom" presentation and win conditions
- bundle list refresh, item processing/inventory functionality, etc

## Extra credit
none finished

*ChatGPT/Excel used for:
- item value assignment, .txt file template for formatting/sorting item lists
- mine level randomization/loot drop rate scaling
- deriving/tracking variable and function names
