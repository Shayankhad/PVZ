#ifndef PLANT_LABEL_HPP
#define PLANT_LABEL_HPP
#include "global.hpp"

class Plant_label {
public:
    Plant_label() {
        if (!plant_label_texture.loadFromFile(OPENED_PEASHOOTER_LABEL_ADDRESS)) {
            cerr << "failed to load pea image";
        }
        plant_label_sprite.setTexture(plant_label_texture);
        plant_label_sprite.setPosition({ 0 , 0 });
        plant_label_sprite.setScale(0.5 , 0.5 );

        
        if (!sunflower_texture.loadFromFile("files/pics/sunflower.png")) {
            cerr << "failed to load sunflower image";
        }
        sunflower_sprite.setTexture(sunflower_texture);
        
        sunflower_sprite.setPosition({ 0, plant_label_sprite.getPosition().y + plant_label_sprite.getGlobalBounds().height });

        
    }

    void render_plant_label(RenderWindow &window) {
        window.draw(plant_label_sprite);
        window.draw(sunflower_sprite); 
    }

    Sprite* get_plant_label() {
        return &plant_label_sprite;
    }

private:    
    Texture plant_label_texture;
    Sprite plant_label_sprite;

    Texture sunflower_texture;
    Sprite sunflower_sprite;
};

#endif
