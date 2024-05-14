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
        sun_sprite.setScale(0.5 , 0.5);
        sun_sprite.setPosition(300 ,300);
    }
    void render_sun(RenderWindow *window){
        sun_sprite.move(0 , SUN_SPEED);
        window->draw(sun_sprite);
    }
    Sprite* get_sun_sprite(){
        return &sun_sprite;
    }
private:
    Texture sun_texture;
    Sprite sun_sprite;

};






#endif
