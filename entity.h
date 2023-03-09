#pragma once
#include "cell.h"
#include "base.h"
#include <string>
#include <iostream>
#include "map.h"
#include "projectile.h"
#include <list>


class Entity : public Animation
{
public:

    Entity(std::string name, sf::Vector2i startPos, Team team, Map* map);
    ~Entity();
    
    void getDamage(Entity sender);
    void getHeal();
    void getLife();

    void death();
    void respawn();

    void move(Direction dir);
    void moving();
    void listenEvent() {};
    void attack();


    //Getters
    std::string getName();
    Direction getDirection();
    Team getTeam();
    sf::Vector2i getPos();
    unsigned short int damage();
    unsigned short int speed();
    bool isAlive();


    std::vector<Projectile> projectiles;

protected:
    Team team;
    
    short int hp = MAX_HP;
    unsigned short int lives = MAX_LIVES;

    bool bostedDamage = false;
    bool bostedSpeed = false;

    bool reloading = false;

    sf::Vector2i pos;
    Direction dir = Direction::Up;

    bool isMoving = false;

    sf::Clock respawnTimer;
    bool respawning = false;
    bool isDead = false;

    std::string name;

    Map* map = nullptr;
private:
    float pastTime = 0;

    sf::Clock attackTimer;
};
