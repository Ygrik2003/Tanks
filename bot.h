#pragma once

#include "entity.h"
#include "base.h"


class Bot : public Entity
{
public:
    Bot(std::string name, sf::Vector2i startPos, Team team, Map* map);
    ~Bot();

    void listenEvent();

};
