#include <SFML/Graphics.hpp>
#include <iostream>

enum class GameState {
    StartScreen,
    GameScreen
};

class Game {
public:
    Game() : window(sf::VideoMode(1200, 800), "Plant vs Zombies"), state(GameState::StartScreen) {
        // Load background textures
        if (!startScreenTexture.loadFromFile("start_screen.png")) {
            // Handle error
        }
        startScreen.setTexture(startScreenTexture);

        if (!gameScreenTexture.loadFromFile("frontyard.png")) {
            // Handle error
        }
        gameScreen.setTexture(gameScreenTexture);

        // Load menu textures
        if (!peashooterTexture.loadFromFile("peashooter.png")) {
            // Handle error
        }
        peashooter.setTexture(peashooterTexture);
        peashooter.setScale(0.05f, 0.05f); // Reduce the size even more

        if (!walnutTexture.loadFromFile("walnut_body.png")) {
            // Handle error
        }
        walnut.setTexture(walnutTexture);
        walnut.setScale(0.05f, 0.05f); // Reduce the size even more

        if (!sunflowerTexture.loadFromFile("sunflower.png")) {
            // Handle error
        }
        sunflower.setTexture(sunflowerTexture);
        sunflower.setScale(0.05f, 0.05f); // Reduce the size even more

        // Position the menu items
        peashooter.setPosition(50, 50);
        walnut.setPosition(50, 150);
        sunflower.setPosition(50, 250);
    }

    void run() {
        while (window.isOpen()) {
            processEvents();
            update();
            render();
        }
    }

private:
    void processEvents() {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                if (state == GameState::StartScreen) {
                    state = GameState::GameScreen; // Transition to game screen
                } else if (state == GameState::GameScreen) {
                    // Check if any menu item is clicked
                    if (peashooter.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                        // Handle click on peashooter
                        std::cout << "Peashooter selected\n";
                    } else if (walnut.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                        // Handle click on walnut
                        std::cout << "Walnut selected\n";
                    } else if (sunflower.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                        // Handle click on sunflower
                        std::cout << "Sunflower selected\n";
                    }
                }
            }
        }
    }

    void update() {
        // Update game logic here
    }

    void render() {
        window.clear();
        if (state == GameState::StartScreen) {
            window.draw(startScreen);
        } else if (state == GameState::GameScreen) {
            window.draw(gameScreen);
            // Draw menu items
            window.draw(peashooter);
            window.draw(walnut);
            window.draw(sunflower);
        }
        window.display();
    }

private:
    sf::RenderWindow window;
    GameState state;
    sf::Texture startScreenTexture;
    sf::Sprite startScreen;
    sf::Texture gameScreenTexture;
    sf::Sprite gameScreen;
    sf::Texture peashooterTexture;
    sf::Sprite peashooter;
    sf::Texture walnutTexture;
    sf::Sprite walnut;
    sf::Texture sunflowerTexture;
    sf::Sprite sunflower;
};

int main() {
    Game game;
    game.run();

    return 0;
}
