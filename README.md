# CSCI 1300 Final Project

## Theme

This project is a text-based adventure game inspired by *The Little Prince*, reskinning the standard "Final Bundle" project theme. Instead of restoring a Community Center, the player guides the Prince between small planets/asteroids, each home to a character from the book (the King, the Businessman, the Vain Man, the Drunkard, and eventually Earth). The Prince has a limited number of days to earn 10 stars — awarded by NPCs for correctly answering short computer-science questions — while also keeping a Rose back on his home asteroid watered using a limited canteen of water. The game ends when the Prince gives 10 stars to the Snake on Earth, or when he runs out of days first.

## Goal

Collect 10 stars by correctly answering the NPCs' comp-sci questions (or by taking the Businessman's costly shortcut), then travel to Earth and give the stars to the Snake before your 15 days run out. Keep the Rose alive along the way by spending your limited water supply wisely.

## Theme Mapping

| Stardew Valley concept (handout default) | Little Prince equivalent |
|---|---|
| Final Community Center bundle | Collecting 10 stars and giving them to the Snake |
| Stardew characters (Lewis, Pierre, etc.) | The King, the Businessman, the Vain Man, the Drunkard |
| Farm, Beach, Mines, Town | The King's Planet, the Businessman's Planet, the Vain Man's Planet, the Drunkard's Planet, Earth |
| JojaMart / Morris shortcut | The Businessman's "buy stars for days" shortcut |
| Energy / Money as second resource | Water canteen (limited uses for watering the Rose) |
| Community restoration ending | Reaching Earth and giving the Snake 10 stars |

## How to compile and run

```
g++ -std=c++11 -o game main.cpp planet.cpp Prince.cpp Rose.cpp KingPlanet.cpp BusinessmanPlanet.cpp
./game
```

`planets.txt` must be in the same folder as the compiled program — it's read at startup for each planet's name, description, and NPC question.

## How to play

Each turn, choose from the main menu: visit a planet, water the Rose, view your status, view your inventory, or travel to Earth to see the Snake. Visiting a planet and traveling to Earth each cost one day. Answering an NPC's question correctly earns stars (and an item for your inventory); the Businessman also offers a shortcut that trades days for guaranteed stars. Reach 10 stars and deliver them to the Snake before your days run out to win.

## Classes

- `Planet` (`planet.h`/`.cpp`) — base class for every planet. Stores name, description, and NPC question data; provides the shared `askQuestion()` used by every planet, and a virtual `visit()`.
- `KingPlanet` (`KingPlanet.h`/`.cpp`) — inherits from `Planet`; overrides `visit()` with the King's dialogue.
- `BusinessmanPlanet` (`BusinessmanPlanet.h`/`.cpp`) — inherits from `Planet`; overrides `visit()` to offer the shortcut/tradeoff system (buy stars for days).
- `Prince` (`Prince.h`/`.cpp`) — the player character. Tracks stars, days remaining, water, current planet, and inventory.
- `Rose` (`Rose.h`/`.cpp`) — tracks thirst; wilts if not watered.
- `main.cpp` — reads `planets.txt`, builds the planet objects, and runs the main game loop/menu.

## File I/O

`planets.txt` stores one line per planet (King, Businessman, Vain Man, Drunkard) in the format `name|description|question|answer|starReward`. `main.cpp` reads it with `ifstream` and `getline(stream, variable, '|')` at startup and uses the data to construct each planet object.

## Status

Checkpoint 3: core gameplay loop, 4 characters/locations, file-driven NPC questions, an inventory, two limited resources (days and water), the Businessman shortcut/tradeoff system, and win/loss conditions are all implemented and tested. Still to come: the Lamplighter and Geographer, and multiple distinct endings based on how much the player relied on the Businessman's shortcut.

## Extra credit

None attempted yet.
