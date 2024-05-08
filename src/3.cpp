#include <SFML/Graphics.hpp>
#include <cstdlib> 
#include <ctime>   

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

   
    srand(time(nullptr));
    int yOffset = rand() % 101 - 50; 
    zombie.setPosition(window.getSize().x / 2, window.getSize().y / 2 - zombie.getGlobalBounds().height / 2 + yOffset);

    float zombieScaleFactor = 0.3f;
    zombie.setScale(zombieScaleFactor, zombieScaleFactor);

    
    float zombieSpeed = 1.0f;

    while (window.isOpen())
    {
        
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        
        zombie.move(-zombieSpeed, 0);

        
        if (zombie.getPosition().x + zombie.getGlobalBounds().width < 0) {
            zombie.setPosition(window.getSize().x, zombie.getPosition().y);
        }

        
        window.clear();

        window.draw(background);
        window.draw(zombie);

        
        window.display();
    }

    return 0;
}
