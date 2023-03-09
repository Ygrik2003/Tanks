#pragma once
#include <SFML/System/Vector2.hpp>
#include "Animation.h"



class Cell : public Animation
{
public:
    enum class Type
    {
        Ground,
        Water,
        Wall,
        StrongWall,
        Bonus,
        Life
    };
    Cell() {};
    Cell(Type type);
    ~Cell();

    Type getType();

    bool isBusy();
    void setBusy(bool state);

private:
    Type type = Type::Ground;
    bool busy = false;
};
