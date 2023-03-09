#pragma once

#include "entity.h"



class HUD
{
public:
    HUD(std::vector<Entity> entities, sf::Vector2i pos);

    void update(Entity entity);
};
