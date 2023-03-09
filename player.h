#include "entity.h"
#include <SFML/Graphics.hpp>
#include "map.h"


class Player : public Entity
{
public:
    Player(std::string name, sf::Vector2i startPos, Team team, Map *map);
    
    ~Player();

    void listenEvent();

};
