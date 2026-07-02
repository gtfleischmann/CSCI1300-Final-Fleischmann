# CSCI 1300 Final - Garrett Fleischmann
 
## Theme
Set in Stardew's sewer/mines: Krobus has been kidnapped and held for ransom by a rival faction of dwarves, and the player must free him in any way possible.

(game/characters currently unnamed)
## Classes
(Base classes contain various derived classes as noted)

- Character:
  contains various player actions, energy/light, traits selected at game start)
  
- Non-Player Character:
  contains individual character traits/items/conditionals, potentially with an additional division of Dwarf vs Sewer creatures (affects communication, combat, friendliness etc)
  
- Item:
  contains any storable inventory item, with subdivisions for bundle, inventory of player and NPCs, stackable vs singular, etc)
  
- Location:
  contains all map locations, possibly also unmarked, location-based interactables (shrines, fishing spots, etc)
  
- Game Concepts:
  loosely defined currently, could potentially involve relationships between locations/characters or any other features not attributable to other classes.
  
## Limited Resources
- Light (limited strength/duration of torch or battery light, affects traversal options or interactions with various puzzles/locations)
- Energy (certain tasks require lots of energy, could be supplemented with food/magic items)
  
## Time
The ransom will last for a set duration (likely 3-7 days), with time incremented by hour. Time progresses variously with traversal/interactions. No real day/night cycle intended due to its underground setting, so it might be represented more abstractly.
 
## Tradeoff System
- Stardew's Wizard incorporated as a magic quest-fulfillment mechanism (creating items, altering time, etc.) at the expense of ending points
- A dwarf king or guard who can be bribed for money as ransom rather than the specific bundle items requested (less penalized but discouraged by game dialogue, lesser ending).

## Mapping Style
will likely consist of ASCII art around each map area, depicted spatially with branches, with potential paths marked but locations obscured until entered/unlocked (marked as `[???]` or something similar).
 
## Win/Lose Condition
Win (free Krobus) by:
- Defeating dwarves in final battle
- Completing ransom with bundle completion
- Completing ransom with bribery
- Potential indirect/alternative victory (easter-egg mechanic or something involving the Wizard)

Lose by:
- Being defeated by dwarves in final battle
- Running out of time
- Running out of light/energy in unsafe areas (or a time penalty, depending on context)
- Overrelying on wizard's help (maybe following 3+ interactions and/or a warning)

## EC Ideas
Options 2 and 6 seem most in line with my current plans, but I'm open to incorporating basically any of the options if I'm able to do so seamlessly.
