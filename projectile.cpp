#include "projectile.h"

Projectile::Projectile(sf::Vector2i pos, Direction dir, Team team, Map *map)
{
    this->map = map;

    this->dir = dir;

    switch (team)
    {
    case Team::Yellow:
        this->setTextures(Frames(sf::Vector2i(122, 71), sf::Vector2i(3, 5), 1, 1, 0));
        break;
    case Team::Red:
        this->setTextures(Frames(sf::Vector2i(122, 92), sf::Vector2i(3, 5), 1, 1, 0));
        break;
    case Team::Blue:
        this->setTextures(Frames(sf::Vector2i(122, 113), sf::Vector2i(3, 5), 1, 1, 0));
        break;
    case Team::Green:
        this->setTextures(Frames(sf::Vector2i(122, 134), sf::Vector2i(3, 5), 1, 1, 0));
        break;
    default:
        break;
    }

    this->setPosition(pos, Alignment::Center); //TODO 

    this->sprite.rotate(90 * (int)this->dir);
    this->setStateAnimation(false);
}

Projectile::~Projectile()
{
}

bool Projectile::moving()
{
    bool isAlive;

    sf::Vector2f pixelPos = this->sprite.getPosition();
    sf::Vector2i pos(int(pixelPos.x / SIZE_CELL.x), int(pixelPos.y / SIZE_CELL.y));
    
    isAlive = !((map->getCell(pos).getType() == Cell::Type::StrongWall || map->getCell(pos).getType() == Cell::Type::Wall));

    /*if (isAlive)
    {
        for (auto entity : entities)
        {
            if (this->sprite.getGlobalBounds().intersects(entity.sprite.getGlobalBounds()))
            {
                entity.getDamage(parent);
            }
        }
    }*/

    if (isAlive)
    {
        switch (this->dir) {
        case Direction::Left:
            this->sprite.move(sf::Vector2f(-INTERVAL_TIME * speed() * SIZE_CELL.x / 1e6, 0));
            break;
        case Direction::Right:
            this->sprite.move(sf::Vector2f(INTERVAL_TIME * speed() * SIZE_CELL.x / 1e6, 0));
            break;
        case Direction::Down:
            this->sprite.move(sf::Vector2f(0, INTERVAL_TIME * speed() * SIZE_CELL.y / 1e6));
            break;
        case Direction::Up:
            this->sprite.move(sf::Vector2f(0, -INTERVAL_TIME * speed() * SIZE_CELL.x / 1e6));
            break;
        }
    }

    return !isAlive;
}

unsigned short int Projectile::speed()
{
    return PROJECTILE_SPEED;
}
