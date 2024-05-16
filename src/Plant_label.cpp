#include "global.hpp"


Plant_label::Plant_label(){
    if(!plant_label_texture.loadFromFile(OPENED_PEASHOOTER_LABEL_ADDRESS)){
        cerr << "failed to load plant_label image";
    }
    plant_label_sprite.setTexture(plant_label_texture);
    plant_label_sprite.setPosition({0 , 0});
    plant_label_sprite.setScale(0.5 , 0.5 );
}
void Plant_label::set_sprite_label(bool open_or_close){
    if(open_or_close == true){
        if(!plant_label_texture.loadFromFile(OPENED_PEASHOOTER_LABEL_ADDRESS)){
            cerr << "failed to load plant_label image";
        }
        plant_label_sprite.setTexture(plant_label_texture);
        plant_label_sprite.setPosition({0 , 0});
        plant_label_sprite.setScale(0.5 , 0.5 );
    }
    else if(open_or_close == false){
        if(!plant_label_texture.loadFromFile(CLOSED_PEASHOOTER_LABEL_ADDRESS)){
            cerr << "failed to load plant_label image";
        }
        plant_label_sprite.setTexture(plant_label_texture);
        plant_label_sprite.setPosition({0 , 0});
        plant_label_sprite.setScale(0.5 , 0.5 ); 
    }
}

void Plant_label::render_plant_label(RenderWindow &window , Time *last_time_made_plant , Clock *clock , int collected_sun ){
    if((clock->getElapsedTime().asSeconds() - last_time_made_plant->asSeconds() >= 5)&& (collected_sun >= PLANT_SUN_COST )){
        set_sprite_label(true);
    }   
    else {
        set_sprite_label(false);
    }
    window.draw(plant_label_sprite);
}
Sprite* Plant_label::get_plant_label(){
    return &plant_label_sprite;
}



