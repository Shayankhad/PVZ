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
        if(!is_dot_full){
            window.draw(dot_sprite);
        }
        
    }

    Sprite* dot_get_sprite(){
        return &dot_sprite;
    }
    Vector2f get_dot_position(){
        return dot_sprite.getPosition();
    }
    void set_is_dot_full(bool full ){
        is_dot_full = full;
    }
    

private:
    Texture dot_texture;
    Sprite dot_sprite;
    bool is_dot_full = false;
};

#endif