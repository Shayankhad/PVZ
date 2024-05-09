#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#define X_WINDOW 1200
#define Y_WINDOW 600
using namespace std;
using namespace sf;



class Game {
public:
    Game(string title, string backgroundImage)
        : window(VideoMode(X_WINDOW, Y_WINDOW), title),
          backgroundTexture(),
          backgroundSprite() 
        {
        backgroundTexture.loadFromFile(backgroundImage);
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
    string 
};

int main() {
    try {
        Game mainWindow("SFML Window with Background", "Frontyard.png");
        mainWindow.run();
    } catch (const std::exception& e) {
            cerr << "Error: " << e.what() << endl; 
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}