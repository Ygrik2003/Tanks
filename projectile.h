#pragma once
#include "Animation.h"
#include "map.h"

class Projectile : public Animation
{
public:
    Projectile(sf::Vector2i pos, Direction dir, Team team, Map *map);
    ~Projectile();

    bool moving();

    unsigned short int speed();


private:
    Map* map;



    Direction dir;
};
