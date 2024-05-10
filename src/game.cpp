#include "global.hpp"

class Game{
public:
    Game(){
        window.create(VideoMode(X_WINDOW , Y_WINDOW) , WINDOWS_TITLE);
        if(!frontyard_tex.loadFromFile(BACKGROUND_IMAGE_ADDRESS)){
            cerr << "fialed to open frontyard image!!!";
        }
        frontyard_sprite.setTexture(frontyard_tex);
        


    }
    void mouse_press_handeling(){
        while(window.pollEvent(event)){
            if(event.type == Event::EventType::Closed){
                window.close();
            }
        }
    }
    void run(){
        while(window.isOpen()){
            window.clear(Color::Black);
            window.draw(frontyard_sprite);
            mouse_press_handeling();
            window.display();
        }
    }
private:
    RenderWindow window;
    Event event;
    Texture frontyard_tex;
    Sprite frontyard_sprite;
};

int main(){
    Game pvz;
    pvz.run();
    return 0;
}