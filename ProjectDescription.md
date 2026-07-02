# The Little Prince — Project Description

## Theme

The game is based on *The Little Prince*. The player controls the Prince as he travels between a handful of small planets/asteroids, each home to one character from the book (the King, the Vain Man, the Drunkard, the Businessman, the Lamplighter, the Geographer, and eventually Earth, home to the Fox and the Snake). Back on the Prince's home asteroid, a Rose depends on him for water. The player splits attention between exploring planets and keeping the Rose alive.

## Planned classes

- `Prince` — the player character. Tracks current planet, inventory (water, stars), and days remaining.
- `Rose` — tracks thirst/health over time; wilts if not watered.
- `Planet` (base class) — name, description, a resource the planet offers or demands, and a virtual `visit()` function.
  - `KingPlanet`, `VainManPlanet`, `DrunkardPlanet`, `BusinessmanPlanet`, `LamplighterPlanet`, `GeographerPlanet` — derived from `Planet`, each overriding `visit()` with its own dialogue/quest and reward.
- `Ship` — handles travel between planets and consumes a travel resource (e.g. fuel or time).
- `Game` — owns the vector of planets, the Prince, and the Rose; runs the main day loop and checks win/lose conditions.

## Planned limited resource

**Water.** The Prince starts with a small supply of water. Watering the Rose each day keeps her alive, but water is also the "currency" some planets want in exchange for stars or information. Water slowly regenerates only when the Prince is on his home asteroid, so every trip away is a tradeoff between exploring and neglecting the Rose.

## Plan for handling time

The game runs in discrete days. Each day the player gets a fixed number of actions (e.g. travel, water the Rose, talk to a planet's inhabitant, rest). At the end of each day, the Rose's thirst increases and the Prince's water/star totals are updated. The game ends after a fixed number of days (e.g. 20) or earlier if the Rose withers.

## Tradeoff system

The Businessman offers to buy the Prince's collected stars for water, on the spot, no travel required — similar to selling to JojaMart for convenience. Trading with him is fast and reliable, but stars sold to the Businessman are gone for good. Alternatively, the Prince can carry stars back to the Lamplighter or Geographer, who exchange stars for larger, delayed rewards (extra water regeneration, a permanent boost to travel speed) but only if the Prince makes the trip and spends the time. This mirrors the Community Center vs. JojaMart choice: quick guaranteed value now vs. a larger payout later if the player invests the travel/time.

## Mapping style

There is no grid map. Instead, the "map" is a small set of connected planets, represented as a `vector<Planet*>` (or similar), each with a name and short description. The player picks a destination by name/number from a menu (e.g. "Where do you want to travel? 1) King's planet 2) Businessman's planet ..."), and the Ship deducts travel resources accordingly. This fits the source material better than a 2D grid, since each planet is tiny and isolated in space.

## Win / lose condition

**Win:** the Prince reaches Earth with the Rose still alive (thirst below a maximum threshold) before the day counter runs out.

**Lose:** the Rose's thirst reaches its maximum (she wilts) before the Prince reaches Earth, or the day counter runs out first.

## Extra credit plans

(TBA — likely candidates: inheritance/polymorphism across `Planet` subclasses with virtual `visit()`, dynamic memory management for the planet list, and file I/O to save/load progress between sessions.)