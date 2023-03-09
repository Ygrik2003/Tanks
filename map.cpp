#include "map.h"

#include <iostream>



Map::Map()
{
    cells.resize(COUNT_VERTICAL_CELLS);

    for (int i = 0; i < COUNT_VERTICAL_CELLS; i++)
    {
        cells[i].resize(COUNT_HORIZONTAL_CELLS);
        for (int j = 0; j < COUNT_HORIZONTAL_CELLS; j++)
        {
            cells[i][j] = Cell((Cell::Type)mask[i][j]);
            cells[i][j].setPosition(sf::Vector2i(j, i), Alignment::Center);
        }
    }

    
}

Map::~Map()
{
}

Cell &Map::getCell(unsigned short x, unsigned short y)
{
    return cells[y][x];
}

Cell &Map::getCell(sf::Vector2i pos)
{
    return cells[pos.y][pos.x];
}

void Map::repaint()
{
    for (int i = 0; i < COUNT_VERTICAL_CELLS; i++)
    {
        for (int j = 0; j < COUNT_HORIZONTAL_CELLS; j++)
        {
            cells[i][j].update();
        }
    }
}

