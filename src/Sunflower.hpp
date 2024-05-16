#ifndef SUNFLOWER_HPP
#define SUNFLOWER_HPP
#include "global.hpp"

class Sunflower{
public:
    Sunflower(Vector2f sunflower_position){
        if(!sunflower_texture.loadFromFile(SUN_FLOWER_IMAGE_ADDRESS)){
            cerr << "failed to load sunflower image";
        }
        sunflower_sprite.setTexture(sunflower_texture);
        sunflower_sprite.setOrigin(sunflower_sprite.getLocalBounds().width / 2 , sunflower_sprite.getLocalBounds().height/2 );
        sunflower_sprite.setScale({0.05 , 0.05});
        sunflower_sprite.setPosition(sunflower_position);
    }

private:
    Texture sunflower_texture;
    Sprite sunflower_sprite;    
};



#endif