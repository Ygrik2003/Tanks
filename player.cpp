#include "player.h"

#include<iostream>

using namespace std;

Player::Player(string name, sf::Vector2i startPos, Team team, Map *map) : Entity(name, startPos, team, map)
{
	
}

Player::~Player()
{

}

void Player::listenEvent()
{
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || (sf::Keyboard::isKeyPressed(sf::Keyboard::A))))
	{
		this->move(Direction::Left);
	}
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || (sf::Keyboard::isKeyPressed(sf::Keyboard::D))))
	{
		this->move(Direction::Right);
	}
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || (sf::Keyboard::isKeyPressed(sf::Keyboard::W))))
	{
		this->move(Direction::Up);
	}
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || (sf::Keyboard::isKeyPressed(sf::Keyboard::S))))
	{
		this->move(Direction::Down);
	}
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))))
	{
		this->attack();
	}
}