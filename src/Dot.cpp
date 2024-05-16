#include "global.hpp"


Dot::Dot(Vector2f dot_position){
    if(!dot_texture.loadFromFile(DOT_IMAGE_ADDRESS)){
        cerr << "failed to load pea image";
    }
    dot_sprite.setTexture(dot_texture);
    dot_sprite.setScale({0.5 , 0.5});
    dot_sprite.setPosition(dot_position);
    dot_sprite.setOrigin(dot_sprite.getLocalBounds().width / 2 , dot_sprite.getLocalBounds().height/2 );
}
void Dot::draw_dot(RenderWindow &window){
    if(!is_dot_full){
        window.draw(dot_sprite);
    }
    
}

Sprite* Dot::dot_get_sprite(){
    return &dot_sprite;
}
Vector2f Dot::get_dot_position(){
    return dot_sprite.getPosition();
}
void Dot::set_is_dot_full(bool full ){
    is_dot_full = full;
}
