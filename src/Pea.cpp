#include "global.hpp"

Pea::Pea(Vector2f start_pos){
    if(!pea_texture.loadFromFile(PEA_IMAGE_ADDRESS)){
        cerr << "failed to load pea image";
    }
    pea_sprite.setTexture(pea_texture);
    start_pos.x -= 24;
    start_pos.y -= 32;
    pea_sprite.setPosition(start_pos);
    pea_sprite.setScale({0.15 , 0.15});
}
void Pea::render_pea(RenderWindow &window){
    pea_sprite.move(PEA_SPEED , 0);
    window.draw(pea_sprite);
}
Sprite Pea::get_pea_sprite(){
    return pea_sprite;
}
