#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#define X_WINDOW 1200
#define Y_WINDOW 600
using namespace std;
using namespace sf;



class Game {
public:
    Game()
        : window(VideoMode(X_WINDOW, Y_WINDOW), window_title)
        {
        backgroundTexture.loadFromFile(background_image);
        backgroundSprite.setTexture(backgroundTexture);
    }
    void run() {
        while (window.isOpen()) {
            Event event;
            while (window.pollEvent(event)) {
                if (event.type == Event::Closed) {
                    window.close();
                }
            }

            window.clear();
            window.draw(backgroundSprite);
            window.display();
        }
    }

private:
    RenderWindow window;
    Texture backgroundTexture;
    Sprite backgroundSprite;
    string window_title = "PVZ";
    string background_image = "files/pics/Frontyard.png";
};

int main() {
    try {
        Game mainWindow;
        mainWindow.run();
    } catch (const std::exception& e) {
            cerr << "Error: " << e.what() << endl; 
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}