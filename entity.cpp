#include "entity.h"
#include "base.h"


Entity::Entity(std::string name, sf::Vector2i startPos, Team team, Map* map)
{
    this->name = name;
    this->pos = startPos;
    this->team = team;

    this->map = map;

    

    switch (team)
    {
    case Team::Yellow:
        this->setTextures(Frames(sf::Vector2i(0, 71), sf::Vector2i(11, 16), 3, 6, 4));
        break;
    case Team::Red:
        this->setTextures(Frames(sf::Vector2i(0, 92), sf::Vector2i(11, 16), 3, 6, 4));
        break;
    case Team::Blue:
        this->setTextures(Frames(sf::Vector2i(0, 113), sf::Vector2i(11, 16), 3, 6, 4));
        break;
    case Team::Green:
        this->setTextures(Frames(sf::Vector2i(0, 134), sf::Vector2i(11, 16), 3, 6, 4));
        break;
    default:
        break;
    }

    this->setPosition(this->pos, Alignment::Center);

    this->setStateAnimation(false);
}

Entity::~Entity()
{
}

void Entity::getDamage(Entity sender)
{
    if (!this->isAlive())
        return ;
    std::cout << this->getName() << " get " << sender.damage() << " damage from " << sender.getName() << std::endl;
    this->hp -= sender.damage();
    std::cout << this->getName() << " have " << this->hp << " HP" << std::endl;

    if (this->hp <= 0)
        this->death();

}

void Entity::getHeal()
{
    if (!this->isAlive())
        return;
    this->hp = std::max(this->hp + 50, (int)MAX_HP);
}

void Entity::getLife()
{
    if (!this->isAlive())
        return;
    if (this->lives < 3)
        this->lives++;
    else 
        this->hp = MAX_HP;

}

void Entity::death()
{
    map->getCell(pos.x, pos.y).setBusy(false);

    if (this->lives > 0)
    {
        this->lives--;
       
        this->respawn();
    }
    else
    {
        isDead = true;
    }

    
}

void Entity::respawn()
{
    respawning = true;
    
    respawnTimer.restart();
}

void Entity::move(Direction dir)
{
    if (!this->isAlive())
        return;
    if (isMoving)
    {
        return;
    }

    switch (dir) {
    case Direction::Left:
        if (map->getCell(pos.x - 1, pos.y).getType() == Cell::Type::Ground && !map->getCell(pos.x - 1, pos.y).isBusy())
        {
            map->getCell(pos.x, pos.y).setBusy(false);
            pos.x -= 1;
            map->getCell(pos.x, pos.y).setBusy(true);
            isMoving = true;
        }
        break;
    case Direction::Right:
        if (map->getCell(pos.x + 1, pos.y).getType() == Cell::Type::Ground && !map->getCell(pos.x + 1, pos.y).isBusy())
        {
            map->getCell(pos.x, pos.y).setBusy(false);
            pos.x += 1;
            map->getCell(pos.x, pos.y).setBusy(true);

            isMoving = true;
        }
        break;
    case Direction::Down:
        if (map->getCell(pos.x, pos.y + 1).getType() == Cell::Type::Ground && !map->getCell(pos.x, pos.y + 1).isBusy())
        {
            map->getCell(pos.x, pos.y).setBusy(false);
            pos.y += 1;
            map->getCell(pos.x, pos.y).setBusy(true);
            isMoving = true;
        }
        break;
    case Direction::Up:
        if (map->getCell(pos.x, pos.y - 1).getType() == Cell::Type::Ground && !map->getCell(pos.x, pos.y - 1).isBusy())
        {
            map->getCell(pos.x, pos.y).setBusy(false);
            pos.y -= 1;
            map->getCell(pos.x, pos.y).setBusy(true);
            isMoving = true;
        }
        break;
    default:
        return ;
    }

    
    

    this->sprite.rotate(-90 * (int)this->dir);
    this->dir = dir;
    this->sprite.rotate(90 * (int)this->dir);

    if (isMoving)
        this->setStateAnimation(true);


}

void Entity::moving()
{  
    if (isDead)
        return;
    if (respawning)
    {
        if (respawnTimer.getElapsedTime().asSeconds() > RESPAWN_TIME)
        {
            respawning = false;
            this->hp = 100;
            map->getCell(pos.x, pos.y).setBusy(true);
        }
        return;
    }
    if (isMoving)
    {
        if (pastTime <= 1e6 / speed())
        {
            pastTime += INTERVAL_TIME;
            switch (dir) {
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
            default:
                return;
            }
        }
        else
        {
            isMoving = false;
            pastTime = 0;
            this->setStateAnimation(false);
        }
    }
    
}

void Entity::attack()
{
    if (!this->isAlive())
        return ; 
    if (attackTimer.getElapsedTime().asSeconds() < RELOADING_TIME)
        return ;
    
    Projectile projectile(pos, dir, team, map);
    projectiles.push_back(projectile);
    attackTimer.restart();
}

std::string Entity::getName()
{
    return this->name;
}

Direction Entity::getDirection()
{
    return dir;
}

Team Entity::getTeam()
{
    return team;
}

sf::Vector2i Entity::getPos()
{
    return pos;
}

unsigned short int Entity::damage()
{
    if (this->bostedDamage)
        return BOOSTED_DAMAGE;
    else
        return DEFAULT_DAMAGE;
}

unsigned short int Entity::speed()
{
    if (this->bostedSpeed)
        return BOOSTED_SPEED;
    else
        return DEFAULT_SPEED;
}

bool Entity::isAlive()
{
    return !(respawning || isDead);
}
