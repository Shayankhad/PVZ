#ifndef PLANT_HPP
#define PLANT_HPP
#include "global.hpp"

class Plant{
public:
    Plant(){
        if(!plant_texture.loadFromFile(PEASHOOTER_IMAGE_ADDRESS)){
            cerr << "failed to load zombie image";
        }
        plant_sprite.setTexture(plant_texture);
        plant_sprite.setScale({0.2 , 0.2});
    }
private:
    Texture plant_texture;
    Sprite plant_sprite;    
};

#endif