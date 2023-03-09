#include "player.h"
#include "bonus.h"
#include "bot.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window/Cursor.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/System/Time.hpp>
#include "map.h"
#include <list>

sf::RenderWindow *Animation::window;



int main()
{
    sf::RenderWindow window(sf::VideoMode(COUNT_HORIZONTAL_CELLS * SIZE_CELL.x, COUNT_VERTICAL_CELLS * SIZE_CELL.y), "Tanks!", sf::Style::Titlebar | sf::Style::Close);
    
    Animation::window = &window;



    Map map = Map();


    std::vector<Entity *> entities;
    std::vector<Player> players;
    std::vector<Bot> bots;

    players.push_back(Player("Player1", sf::Vector2i(1, 1), Team::Yellow, &map));
    bots.push_back(Bot("Bot1", sf::Vector2i(18, 18), Team::Red, &map));
    bots.push_back(Bot("Bot2", sf::Vector2i(18, 1), Team::Blue, &map));
    bots.push_back(Bot("Bot3", sf::Vector2i(1, 18), Team::Green, &map));

    for (int i = 0; i < players.size(); i++)
    {
        entities.push_back(&players[i]);
    }
    for (int i = 0; i < bots.size(); i++)
    {
        entities.push_back(&bots[i]);
    }

    std::vector<Projectile>::iterator it;
    
    while (window.isOpen())
    {

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        
        
        window.clear(sf::Color(0, 0, 0));
        
        map.repaint();

        for (int i = 0; i < players.size(); i++)
            players[i].listenEvent();

        for (int i = 0; i < bots.size(); i++)
            bots[i].listenEvent();

        for (int i = 0; i < entities.size(); i++)
        {
            entities[i]->moving();
            if (entities[i]->isAlive())
            {
                entities[i]->update();
            }
            
 

            for (int itProjectile = 0; itProjectile < entities[i]->projectiles.size(); itProjectile++)
            {
                entities[i]->projectiles[itProjectile].update();
                if (entities[i]->projectiles[itProjectile].moving())
                {
                    it = entities[i]->projectiles.begin();
                    std::advance(it, itProjectile);
                    entities[i]->projectiles.erase(it);

                    itProjectile--;
                }
                else
                {
                    for (int j = 0; j < entities.size(); j++)
                    {
                        if (entities[i]->getName() == entities[j]->getName())
                            continue;
                        if (!entities[j]->isAlive())
                            continue;

                        if (entities[i]->projectiles[itProjectile].sprite.getGlobalBounds().intersects(entities[j]->sprite.getGlobalBounds()))
                        {
                            entities[j]->getDamage(*entities[i]);


                            it = entities[i]->projectiles.begin();
                            std::advance(it, itProjectile);
                            entities[i]->projectiles.erase(it);
                            itProjectile--;
                            break;
                        }
                    }
                    
                }

            }
        }
        window.display();
        
        sf::sleep(sf::microseconds(1e6 / FPS));

    }

    return 0;
}
