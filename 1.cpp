#include <SFML/Graphics.hpp>

int main()
{
    // Create the window
    sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "Plant vs Zombie", sf::Style::Fullscreen);

    // Load the image
    sf::Texture texture;
    if (!texture.loadFromFile("Frontyard.png"))
    {
        // Error handling if image loading fails
        return EXIT_FAILURE;
    }

    // Create a sprite
    sf::Sprite sprite(texture);

    // Scale the sprite to fit the window while maintaining aspect ratio
    float scaleX = static_cast<float>(window.getSize().x) / texture.getSize().x;
    float scaleY = static_cast<float>(window.getSize().y) / texture.getSize().y;
    float scaleFactor = std::min(scaleX, scaleY);
    sprite.setScale(scaleFactor, scaleFactor);

    // Center the sprite in the window
    sprite.setPosition((window.getSize().x - sprite.getLocalBounds().width) / 2,
                       (window.getSize().y - sprite.getLocalBounds().height) / 2);

    // Main loop
    while (window.isOpen())
    {
        // Event handling
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        // Clear the window
        window.clear();

        // Draw the sprite
        window.draw(sprite);

        // Display the window
        window.display();
    }

    return EXIT_SUCCESS;
}