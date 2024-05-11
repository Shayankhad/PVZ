#ifndef PLANT_HPP
#define PLANT_HPP
#include "global.hpp"

class Plant{
public:
    Plant(){
        if(!plant_texture.loadFromFile(PEASHOOTER_IMAGE_ADDRESS)){
            cerr << "failed to load plant image";
        }
        plant_sprite.setTexture(plant_texture);
        plant_sprite.setScale({0.05 , 0.05});
        temp_pea = new Pea({10 ,10});
        pea_vec.emplace_back(temp_pea);
    }
    void render_plant(RenderWindow &window){
        window.draw(plant_sprite);
        //Vector2f plant_pos = plant_sprite.getPosition();
        //Pea * temp_pea;
        //temp_pea = new Pea(plant_pos);
        //window.draw(temp_pea->get_pea_sprite());
        for(auto& pea : pea_vec){
            pea->render_pea(window);
        }
        
    }
    void plant_mouse_handle(Event * event , RenderWindow * window){
        if(event->type == Event::EventType::MouseButtonPressed){
            if(event->mouseButton.button == Mouse::Left){
                if(plant_sprite.getGlobalBounds().contains(event->mouseButton.x , event->mouseButton.y )){
                    is_dragging = true;
                    offset = plant_sprite.getPosition() - Vector2f(event->mouseButton.x , event->mouseButton.y);
                }
            }
        }
        else if(event->type == Event::EventType::MouseButtonReleased){
            if(event->mouseButton.button == Mouse::Left){
                is_dragging = 0;
            }
        }

        if(is_dragging){
            Vector2i mouse_pos = Mouse::getPosition(*window);
            plant_sprite.setPosition(mouse_pos.x + offset.x , mouse_pos.y + offset.y);
        }
    }   
    bool get_is_dragging(){
        return is_dragging;
    }
    Sprite* get_plant_sprite_ptr(){
        return &plant_sprite;
    }
private:
    Texture plant_texture;
    Sprite plant_sprite;    
    bool is_dragging = false;
    Vector2f offset;
    vector <Pea*> pea_vec;
    Pea *temp_pea;
};

#endif