#include "cell.h"


Cell::Cell(Type type)
{
    this->type = type;
	switch (type)
	{
	case Type::Ground:
		this->setTextures(Frames(sf::Vector2i(36, 0), sf::Vector2i(16, 16), 4, 4));
		break;
	case Type::Water:
		this->setTextures(Frames(sf::Vector2i(0, 18), sf::Vector2i(16, 16), 8, 4));
		break;
	case Type::Wall:
		this->setTextures(Frames(sf::Vector2i(0, 0), sf::Vector2i(16, 16), 1, 1));
		break;
	case Type::StrongWall:
		this->setTextures(Frames(sf::Vector2i(18, 0), sf::Vector2i(16, 16), 1, 1));
		break;
	case Type::Bonus:
		this->setTextures(Frames(sf::Vector2i(0, 53), sf::Vector2i(9, 16), 9, 4));
		break;
	case Type::Life:
		this->setTextures(Frames(sf::Vector2i(0, 36), sf::Vector2i(9, 16), 9, 4));
		break;
	default:
		break;
	}
    
}

Cell::~Cell()
{
}

Cell::Type Cell::getType()
{
	return type;
}

bool Cell::isBusy()
{
	return busy;
}

void Cell::setBusy(bool state)
{
	this->busy = state;
}

