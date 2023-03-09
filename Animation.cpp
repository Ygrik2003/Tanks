#include "Animation.h"


Animation::Animation()
{
	image.loadFromFile("res/res.png");
}

Animation::Animation(Frames frames)
{
	image.loadFromFile("res/res.png");
	this->setTextures(frames);
}

void Animation::update()
{
	if (state)
	{
		this->time += INTERVAL_TIME;
		if (this->time > 1e6 / this->FPS)
		{
			currentFrame = (currentFrame + 1) % textures.size();
			this->time = 0;
		}
	}
	
	

	
	sprite.setTexture(textures[currentFrame]);
	window->draw(sprite);
}

void Animation::setPosition(sf::Vector2i pos, Alignment align)
{
	sf::Vector2f pixelPos(pos.x * SIZE_CELL.x, pos.y * SIZE_CELL.y);
	switch (align)
	{
	case Alignment::LeftTop:
		pixelPos.x += textures[0].getSize().x / 2;
		pixelPos.y += textures[0].getSize().y / 2;
		break;
	case Alignment::RightTop:
		pixelPos.x += SIZE_CELL.x - textures[0].getSize().x / 2;
		pixelPos.y += textures[0].getSize().y / 2;
		break;
	case Alignment::CenterTop:
		pixelPos.x += SIZE_CELL.x / 2;
		pixelPos.y += textures[0].getSize().y / 2;
		break;
	case Alignment::LeftBottom:
		pixelPos.x += textures[0].getSize().x / 2;
		pixelPos.y += SIZE_CELL.y - textures[0].getSize().y / 2;
		break;
	case Alignment::RightBottom:
		pixelPos.x += SIZE_CELL.x - textures[0].getSize().x / 2;
		pixelPos.y += SIZE_CELL.y - textures[0].getSize().y / 2;
		break;
	case Alignment::CenterBottom:
		pixelPos.x += SIZE_CELL.x / 2;
		pixelPos.y += SIZE_CELL.y - textures[0].getSize().y / 2;
		break;
	case Alignment::LeftCenter:
		pixelPos.x += textures[0].getSize().x / 2;
		pixelPos.y += SIZE_CELL.y / 2;
		break;
	case Alignment::RightCenter:
		pixelPos.x += SIZE_CELL.x - textures[0].getSize().x / 2;
		pixelPos.y += SIZE_CELL.y / 2;
		break;
	case Alignment::Center:
		pixelPos.x += SIZE_CELL.x / 2;
		pixelPos.y += SIZE_CELL.y / 2;
		break;

	}

	sprite.setPosition(pixelPos);
}

void Animation::setScale(sf::Vector2f scale)
{
	sprite.setScale(scale);
}

void Animation::setStateAnimation(bool state)
{
	this->state = state;
}

void Animation::setTextures(Frames frames)
{
	this->FPS = frames.FPS;
	textures.resize(frames.count);
	for (int i = 0; i < frames.count; i++)
	{
		textures[i].loadFromImage(image, sf::IntRect(
			frames.pos.x + i * (frames.sizeFrame.x + frames.interval),
			frames.pos.y,
			frames.sizeFrame.x,
			frames.sizeFrame.y
		));
	}
	this->setScale(DEFAULT_SCALE);
	this->update();
	this->sprite.setOrigin(0.5 * this->sprite.getTextureRect().width, 0.5 * this->sprite.getTextureRect().height);
}

