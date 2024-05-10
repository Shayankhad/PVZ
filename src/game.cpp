#include "global.hpp"

class Game{
public:
    Game(){
        window.create(VideoMode(X_WINDOW , Y_WINDOW) , WINDOWS_TITLE);
        if(!frontyard_tex.loadFromFile(BACKGROUND_IMAGE_ADDRESS)){
            cerr << "fialed to open frontyard image!!!";
        }
        Vector2f screen_size = {X_WINDOW , Y_WINDOW};
        rec_shape.setSize(screen_size);
        rec_shape.setTexture(&frontyard_tex);


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
            mouse_press_handeling();
            window.draw(rec_shape);
            window.display();
        }
    }
private:
    RenderWindow window;
    Event event;
    Texture frontyard_tex;
    RectangleShape rec_shape;
};

int main(){
    Game pvz;
    pvz.run();
    return 0;
}