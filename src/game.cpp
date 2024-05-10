#include "global.hpp"

class Game{
public:
    Game(){
        window.create(VideoMode(X_WINDOW , Y_WINDOW) , WINDOWS_TITLE);
        circle_shape.setRadius(50);
        circle_shape.setFillColor(Color::Magenta);
        circle_shape.setOutlineColor(Color::Green);
        circle_shape.setOutlineThickness(3);
        rect_shape = RectangleShape(Vector2f( 50, 50));
        rect_shape.setFillColor(Color::Red);
        rect_shape.setPosition(100 , 100);
        
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
            window.draw(circle_shape);
            window.draw (rect_shape);
            window.display();
        }
    }
private:
    RenderWindow window;
    CircleShape circle_shape;
    RectangleShape rect_shape;
    Event event;

};

int main(){
    Game pvz;
    pvz.run();
    return 0;
}