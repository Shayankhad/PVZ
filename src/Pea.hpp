#ifndef PEA_HPP
#define PEA_HPP
#include "global.hpp"

class Pea{
public:
    Pea(Vector2f start_pos){
        if(!pea_texture.loadFromFile(PEA_IMAGE_ADDRESS)){
            cerr << "failed to load pea image";
        }
        pea_sprite.setTexture(pea_texture);
        pea_sprite.setPosition(start_pos);
        pea_sprite.setScale({0.15 , 0.15});
    }
    void render_pea(RenderWindow &window){
        pea_sprite.move(3 , 0);
        window.draw(pea_sprite);
        
    }
    Sprite get_pea_sprite(){
        return pea_sprite;
    }
    void disappear (){
        
    }
private:
    Texture pea_texture;
    Sprite pea_sprite;
};












#endif