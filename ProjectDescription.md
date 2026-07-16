# The Little Prince — Project Description

## Theme

The game is based on *The Little Prince*. The player controls the Prince as he travels between a handful of small planets/asteroids, each home to one character from the book (the King, the Vain Man, the Drunkard, the Businessman, the Lamplighter, the Geographer, and eventually Earth, home to the Fox and the Snake). Back on the Prince's home asteroid, a Rose depends on him for water. The player splits attention between exploring planets and keeping the Rose alive.

## Planned classes

- `Prince` — the player character. Tracks current planet, inventory (water, stars), and days remaining.
- `Rose` — tracks thirst/health over time; wilts if not watered.
- `Planet` (base class) — name, description, a resource the planet offers or demands, and a virtual `visit()` function.
  - `KingPlanet`, `VainManPlanet`, `DrunkardPlanet`, `BusinessmanPlanet`, `LamplighterPlanet`, `GeographerPlanet` — derived from `Planet`, each overriding `visit()` with its own dialogue/quest and reward.
Riddles maybe as well.
- `Game` — owns the vector of planets, the Prince, and the Rose; runs the main day loop and checks win/lose conditions.

## Planned limited resource

**Water.** The Prince starts with 15 days to collect the stars before the rose withers. the alloted time can be changed by answering a riddle.

# npc
when the little prince travels to one of the planets the npcs ask him a comp sci related question "simple one" and if you answer correctly you will recive a star or another reward like the next question you asnwer will give you 2 stars if answerd correctly. You may also get more turns due to one of the npcs travelling and watering the rose for you.

## Plan for handling time

The game runs in days. Each day the player gets to make one move so move to one planet and also interact with one npc. (e.g. travel, water the Rose, talk to a planet's inhabitant, rest). At the end of each day the amount of stars updates. The game ends after a fixed number of days 15 or earlier if the player collects the right amount of stars
.


## Mapping style

There is no grid map. Instead, the "map" is a small set of connected planets, represented as a `vector<Planet*>` (or similar), each with a name and short description. The player picks a destination by name/number from a menu (e.g. "Where do you want to travel? 1) King's planet 2) Businessman's planet ..."), 

## Win / lose condition

**Win:** the Prince reaches Earth with the Rose still alive by collecting 10 stars and giving them to the snake to send him home.

**Lose:** the prince does not collect the 10 stars and interact with the snake in the alloted time
