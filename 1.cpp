#include <SFML/Graphics.hpp>

enum class GameState {
    StartScreen,
    GameScreen
};

class Game {
public:
    Game() : window(sf::VideoMode(1200, 800), "Plant vs Zombies"), state(GameState::StartScreen) {
        // Load background textures
        if (!startScreenTexture.loadFromFile("Starting_Screen.png")) {
            // Handle error
        }
        startScreen.setTexture(startScreenTexture);

        if (!gameScreenTexture.loadFromFile("Frontyard.png")) {
            // Handle error
        }
        gameScreen.setTexture(gameScreenTexture);
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
                    state = GameState::GameScreen;
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
            // Draw other game elements here
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
};

int main() {
    Game game;
    game.run();

    return 0;
}