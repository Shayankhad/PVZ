#include "global.hpp"

class Game{
public:
    Game(){
        window.create(VideoMode(X_WINDOW , Y_WINDOW) , WINDOWS_TITLE);
        circle_shape.setRadius(50);
        circle_shape.setFillColor(Color::Magenta);
        circle_shape.setOutlineColor(Color::Green);
        circle_shape.setOutlineThickness(3);
    }
    void run(){
        while(window.isOpen()){
            Event event;
            while(window.pollEvent(event)){
                if(event.type == Event::EventType::Closed){
                    window.close();  
                }   
            }
            window.clear(Color::Black);
            window.draw(circle_shape);
            window.display();

        }
    }
private:
    RenderWindow window;
    CircleShape circle_shape;

};

int main(){
    Game pvz;
    pvz.run();
    CircleShape circle_shape(50);
    return 0;
}