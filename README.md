# Jazz Jackrabbit - Game

## Table of Contents
1. [About](#about)
2. [Game Description](#game-description)
3. [Project Structure](#project-structure)
4. [Main Data Structures](#main-data-structures)
5. [Notable Algorithms](#notable-algorithms)
6. [How to Run](#how-to-run)
7. [Video Links](#video-links)

## About
Jazz Jackrabbit is an exciting adventure game developed in C++ using the SFML library. This classic game features a brave rabbit named Jazz who embarks on a journey to reach the end of various stages while battling against formidable enemies, the turtles. Jazz will have to collect ammunition during his adventure to fend off the turtles and overcome obstacles. The game also includes a life system, with Jazz losing lives when hit by obstacles or enemies, but he can regain life by collecting carrots.

## Game Description
In Jazz Jackrabbit, players control Jazz, the rabbit, and guide him through challenging levels. Your mission is to help Jazz reach the end of each stage, avoiding or defeating the turtles and other obstacles along the way. Jazz can collect ammunition to fight the turtles and gather carrots to restore his life.

## Project Structure
The project is organized into several classes:

- **Controller**: Responsible for managing the game.
- **Board**: Handles the game board and conflict resolution.
- **GameObject**: A base class for all characters in the game.
- **MovingObject**: Inherited from GameObject, responsible for dynamic characters like Jazz and the turtles.
- **Jazz**: Inherited from MovingObject, manages Jazz's actions.
- **StaticObject**: Inherited from GameObject, handles static characters like walls and carrots.
- **Resources**: Manages the graphical interface.
- **Menu**: Responsible for the in-game menu screen.

  
## Main Data Structures
Here are the main data structures used in the project:

- `std::unique_ptr<Jazz> m_jazz`: Points to an object of type Jazz.
- `std::vector<std::unique_ptr<MovingObject>> m_enemies`: A vector of pointers to dynamic objects (turtles).
- `std::vector<std::unique_ptr<StaticObject>> m_presents`: A vector of pointers to static objects (gifts).
- `std::vector<std::unique_ptr<StaticObject>> m_ammos`: A vector of pointers to ammunition.
- `std::vector<std::unique_ptr<StaticObject>> m_statics`: A vector of pointers to static objects (walls).
- `std::vector<sf::RectangleShape> m_blockers`: Rectangular shapes used for path delimitation.
- `std::vector<std::unique_ptr<Ammo>> m_bullets`: Responsible for Jazz's shooting.
- `std::map<int, std::map<int, std::vector<sf::IntRect>>> m_map`: Loads textures for animations.

## Notable Algorithms
- **Gravity Function**: Implemented in the Jazz class, this algorithm handles character gravity, making characters fall unless they're on a surface.
- **Fire Function**: Found in the Board class, this algorithm is responsible for Jazz's shooting ability.

## How to Run
To run Jazz Jackrabbit, follow these steps:
1. Clone this repository to your local machine.
2. Compile the source code using a C++ compiler that supports the SFML library.
3. Run the compiled executable.

## Video Links
For a demonstration of the game, check out the following video:
- [Gameplay Video ](https://youtu.be/bmSxTaqav1Q)

Enjoy playing Jazz Jackrabbit!
