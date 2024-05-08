#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>   
enum class GameState {
    MENU,
    GAME
};

int main()
{
    
    sf::RenderWindow window(sf::VideoMode(1200, 600), "Plants vs. Zombies");

    
    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("Frontyard.png")) {
        return EXIT_FAILURE;
    }
    sf::Sprite background(backgroundTexture);


    sf::Texture zombieTexture;
    if (!zombieTexture.loadFromFile("zombie.png")) {
        return EXIT_FAILURE;
    }
    sf::Sprite zombie(zombieTexture);
    zombie.setOrigin(zombie.getGlobalBounds().width / 2, zombie.getGlobalBounds().height / 2); // Set origin to center

  
    sf::Vector2f zombiePosition(window.getSize().x / 2, window.getSize().y / 2);
    zombie.setPosition(zombiePosition);

    float zombieScaleFactor = 0.3f;
    zombie.setScale(zombieScaleFactor, zombieScaleFactor);

  
    float zombieSpeed = 1.0f;

    
    bool zombiePlaced = false;

    
    GameState gameState = GameState::MENU;

    
    while (window.isOpen())
    {
       
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::MouseButtonPressed:
                    if (event.mouseButton.button == sf::Mouse::Left && gameState == GameState::MENU)
                    {
                        
                        zombie.setPosition(sf::Vector2f(event.mouseButton.x, event.mouseButton.y));
                        zombiePlaced = true;
                        gameState = GameState::GAME;
                    }
                    break;
                default:
                    break;
            }
        }

        
        if (zombiePlaced && gameState == GameState::GAME)
        {
        
            zombie.move(-zombieSpeed, 0);

          
            if (zombie.getPosition().x + zombie.getGlobalBounds().width < 0) {
                zombie.setPosition(window.getSize().x, zombie.getPosition().y);
            }
        }

        
        window.clear();

      
        window.draw(background);
        if (zombiePlaced)
        {
            window.draw(zombie);
        }

        window.display();
    }

    return 0;
}