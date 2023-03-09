#include "bonus.h"

Bonus::Bonus()
{
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist(0, COUNT_TYPES - 1);

    type = (Type)dist(rng);
}

Bonus::~Bonus()
{
}
