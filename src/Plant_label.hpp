#ifndef PLANT_LABEL_HPP
#define PLANT_LABEL_HPP
#include "global.hpp"

class Plant_label{
public:
    Plant_label(){
        if(!plant_label_texture.loadFromFile(OPENED_PEASHOOTER_LABEL_ADDRESS)){
            cerr << "failed to load pea image";
        }
        plant_label_sprite.setTexture(plant_label_texture);
        plant_label_sprite.setPosition({0 , 0});
        plant_label_sprite.setScale(0.5 , 0.5 );
    }

    void render_plant_label(RenderWindow &window){
        window.draw(plant_label_sprite);
    }
    Sprite* get_plant_label(){
        return &plant_label_sprite;
    }

private:    
    Texture plant_label_texture;
    Sprite plant_label_sprite;
};

#endif
