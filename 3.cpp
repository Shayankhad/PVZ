#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

enum class GameState {
    StartScreen,
    GameScreen
};

class Game {
public:
    Game() : window(sf::VideoMode(1200, 800), "Plant vs Zombies"), state(GameState::StartScreen), isDragging(false) {
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

        // Set the initial positions of the menu items
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
                        createShape(peashooter);
                    } else if (walnut.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                        // Handle click on walnut
                        createShape(walnut);
                    } else if (sunflower.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                        // Handle click on sunflower
                        createShape(sunflower);
                    } else {
                        // Check if any existing shape is clicked for dragging
                        for (auto& shape : shapes) {
                            if (shape.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                                selectedShape = &shape;
                                isDragging = true;
                                dragOffset = sf::Vector2f(event.mouseButton.x - shape.getPosition().x, event.mouseButton.y - shape.getPosition().y);
                                break;
                            }
                        }
                    }
                }
            } else if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left) {
                isDragging = false;
                selectedShape = nullptr;
            } else if (event.type == sf::Event::MouseMoved && isDragging) {
                // Update the position of the selected shape while dragging
                selectedShape->setPosition(event.mouseMove.x - dragOffset.x, event.mouseMove.y - dragOffset.y);
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
            // Draw all placed shapes
            for (const auto& shape : shapes) {
                window.draw(shape);
            }
            // Draw menu items
            window.draw(peashooter);
            window.draw(walnut);
            window.draw(sunflower);
        }
        window.display();
    }

    void createShape(const sf::Sprite& sprite) {
        sf::Sprite newShape(sprite);
        newShape.setPosition(100, 100); // Set initial position
        shapes.push_back(newShape);
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
    std::vector<sf::Sprite> shapes; // Store placed shapes
    sf::Sprite* selectedShape; // Pointer to the currently selected shape for dragging
    bool isDragging; // Flag to indicate if dragging a shape
    sf::Vector2f dragOffset; // Offset for dragging
};

int main() {
    Game game;
    game.run();

    return 0;
}

