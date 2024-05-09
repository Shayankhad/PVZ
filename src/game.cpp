#include "global.hpp"

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
    string window_title = WINDOWS_TITLE;
    string background_image = BACKGROUND_IMAGE_ADDRESS;
};

int main() {
    Game mainwindow;
    mainwindow.run();
}