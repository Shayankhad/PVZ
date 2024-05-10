#include "global.hpp"

class Game{
public:
    Game(){
        window.create(VideoMode(X_WINDOW , Y_WINDOW) , WINDOWS_TITLE);
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
            window.display();
        }
    }
private:
    RenderWindow window;
    Event event;

};

int main(){
    Game pvz;
    pvz.run();
    return 0;
}