#ifndef SUN_HPP
#define SUN_HPP
#include "global.hpp"

class Sun{
public:
    Sun(){
        if(!sun_texture.loadFromFile(SUN_IAMGE_ADDRESS)){
            cerr << "failed to load plant image";
        }
        sun_sprite.setTexture(sun_texture);
        sun_sprite.setOrigin(sun_sprite.getLocalBounds().width / 2 , sun_sprite.getLocalBounds().height/2 );
        sun_sprite.setScale({1, 1});
    }
private:
    Texture sun_texture;
    Sprite sun_sprite;

};






#endif
