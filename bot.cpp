#include "bot.h"

Bot::Bot(std::string name, sf::Vector2i startPos, Team team, Map *map) : Entity(name, startPos, team, map)
{

}

Bot::~Bot()
{

}

void Bot::listenEvent()
{
	this->move((Direction)(rand() % 4));
	this->attack();
}
