#pragma once
#include <vector>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics.hpp>


const unsigned short FPS = 60;
const float INTERVAL_TIME = 1e6 / FPS;

//ENTITY
const unsigned short int MAX_HP = 100;
const unsigned short int MAX_LIVES = 3;
const unsigned short int DEFAULT_DAMAGE = 25;
const unsigned short int BOOSTED_DAMAGE = 50; // If you get boost bonus (TODO)
const float DEFAULT_SPEED = 4.f; // Cells per second
const float BOOSTED_SPEED = 6.f; // If you get boost bonus (TODO)


const float PROJECTILE_SPEED = 10.f; //cells per second
const float RELOADING_TIME = 1.5f; //In seconds
const unsigned short int RESPAWN_TIME = 5; //In seconds

//MAP AND CELLS
const unsigned short int COUNT_HORIZONTAL_CELLS = 20;
const unsigned short int COUNT_VERTICAL_CELLS = 20;

const sf::Vector2f DEFAULT_SCALE(2, 2);
const sf::Vector2i DEFAULT_CELL_SIZE(16, 16);
const sf::Vector2i SIZE_CELL(DEFAULT_SCALE.x * DEFAULT_CELL_SIZE.x, DEFAULT_SCALE.y * DEFAULT_CELL_SIZE.y);

const sf::Vector2i SIZE_HUD(200, COUNT_VERTICAL_CELLS * SIZE_CELL.y);
const unsigned short int SHIFT_STATS = COUNT_VERTICAL_CELLS * SIZE_CELL.y / 4;

enum class Team
{
    Yellow,
    Red,
    Blue,
    Green
};

enum class Direction
{
    Up,
    Right,
    Down,
    Left
};
