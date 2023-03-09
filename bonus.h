#pragma once
#include "cell.h"
#include <vector>
#include <random>

const unsigned short int COUNT_TYPES = 6;

class Bonus
{
public:

    enum Type
    {
        DoubleDamage,
        FastRearm,
        Invisible,
        DoubleSpeed,
        Live,
        Heal
    };

	Bonus();
	~Bonus();
private:
    Type type;
};
