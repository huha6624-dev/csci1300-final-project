# The Little Prince — Checkpoint 2

## Theme

This project reimagines Antoine de Saint-Exupéry's *The Little Prince* as a small text-based exploration game. The player controls the Prince as he travels between tiny planets and asteroids, each home to one character from the book (the King, the Vain Man, the Drunkard, the Businessman, the Lamplighter, the Geographer, and eventually Earth). Back on the Prince's home asteroid, a Rose depends on him for water, so the player will eventually split attention between exploring and keeping her alive. The tone aims to stay whimsical and a little wistful, echoing the book's mix of gentle humor and quiet melancholy.

## Checkpoint 2 Contents

- `Planet.h` / `Planet.cpp` — base class for every planet the Prince can visit.
- `Planets.h` / `Planets.cpp` — `KingPlanet` and `BusinessmanPlanet`, both inheriting from `Planet` and overriding `visit()`.
- `Prince.h` / `Prince.cpp` — the player character.
- `Rose.h` / `Rose.cpp` — the rose back home.
- `main.cpp` — game loop and main menu tying everything together.

## Building and Running

```
g++ -std=c++11 -Wall -o game main.cpp Planet.cpp Planets.cpp Prince.cpp Rose.cpp
./game
```

## Status

This checkpoint focuses on project structure: at least three classes, a meaningful inheritance relationship (`KingPlanet` and `BusinessmanPlanet` both extend `Planet`), and a working main menu/game loop with placeholder actions. More planets (Vain Man, Drunkard, Lamplighter, Geographer, Earth), the full resource system, and win/loss logic are planned for later checkpoints.
