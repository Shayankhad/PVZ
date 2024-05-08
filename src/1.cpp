#include <SFML/Graphics.hpp>
#define X_SCREEN_SIZE 1400
#define Y_SCREEN_SIZE 600

int main()
{
    sf::RenderWindow window(sf::VideoMode(  X_SCREEN_SIZE , Y_SCREEN_SIZE), "Plant vs Zombie");
    sf::Texture texture;
    if (!texture.loadFromFile("files/pics/Frontyard.png"))
    {
        return EXIT_FAILURE;
    }
    sf::Sprite sprite(texture);
    float scaleX = static_cast<float>(window.getSize().x) / texture.getSize().x;
    float scaleY = static_cast<float>(window.getSize().y) / texture.getSize().y;
    float scaleFactor = std::min(scaleX, scaleY);
    sprite.setScale(scaleFactor, scaleFactor);
    sprite.setPosition((window.getSize().x - sprite.getLocalBounds().width) / 2,
                       (window.getSize().y - sprite.getLocalBounds().height) / 2);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }
        window.clear();
        window.draw(sprite);
        window.display();
    }
    return EXIT_SUCCESS;
}