#include "global.hpp"

Pea::Pea(Vector2f start_pos){
    if(!pea_texture.loadFromFile(PEA_IMAGE_ADDRESS)){
        cerr << "failed to load pea image";
    }
    pea_sprite.setTexture(pea_texture);
    pea_sprite.setPosition(start_pos);
    pea_sprite.setScale({0.15 , 0.15});
}
void Pea::render_pea(RenderWindow &window){
    pea_sprite.move(3 , 0);
    window.draw(pea_sprite);
}
Sprite Pea::get_pea_sprite(){
    return pea_sprite;
}