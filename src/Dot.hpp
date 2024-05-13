#ifndef DOT_HPP
#define DOT_HPP
#include "global.hpp"

class Dot{
public:
    Dot(Vector2f dot_position){
        if(!dot_texture.loadFromFile(DOT_IMAGE_ADDRESS)){
            cerr << "failed to load pea image";
        }
        dot_sprite.setTexture(dot_texture);
        dot_sprite.setScale({0.5 , 0.5});
        dot_sprite.setPosition(dot_position);
        dot_sprite.setOrigin(dot_sprite.getLocalBounds().width / 2 , dot_sprite.getLocalBounds().height/2 );
    }
    void draw_dot(RenderWindow &window){
        window.draw(dot_sprite);
    }

    void dot_mouse_handle(Event * event, bool &is_dot_board_open ){
        if(event->type == Event::EventType::MouseButtonPressed){
            if(event->mouseButton.button == Mouse::Left){
                if(dot_sprite.getGlobalBounds().contains(event->mouseButton.x , event->mouseButton.y )){
                    is_dot_board_open = false;
                }
            }
        }
    }
    

private:
    Texture dot_texture;
    Sprite dot_sprite;
};

#endif