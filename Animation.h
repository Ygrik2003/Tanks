#pragma once
#include "base.h"
#include <SFML/Graphics.hpp>


enum class Alignment
{
	LeftTop,
	RightTop,
	CenterTop,
	LeftBottom,
	RightBottom,
	CenterBottom,
	LeftCenter,
	RightCenter,
	Center

};

struct Frames
{
	Frames(sf::Vector2i pos, sf::Vector2i sizeFrame, unsigned short int count, unsigned short int FPS, unsigned int interval = 2)
	{
		this->pos = pos;
		this->sizeFrame = sizeFrame;
		this->count = count;
		this->FPS = FPS;
		this->interval = interval;
	}
	unsigned int interval = 2;
	sf::Vector2i pos, sizeFrame;
	unsigned short int count;
	unsigned short int FPS;
};

class Animation
{
public:
	Animation();
	Animation(Frames frames);

	static sf::RenderWindow* window;
	

	void update();
	void setPosition(sf::Vector2i pos, Alignment align = Alignment::CenterTop);
	void setScale(sf::Vector2f scale);

	void setStateAnimation(bool state);

	void setTextures(Frames frames);


	sf::Sprite sprite;
protected:
	

	std::vector<sf::Texture> textures;
	
	bool state = true;

	unsigned short int currentFrame = 0;

	float time = 0;
	unsigned short int FPS = 1;

	sf::Image image;
};
