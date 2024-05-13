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
    }

    void make_pea(Clock *clock){
        int elapsed_time = clock->getElapsedTime().asSeconds();
        if((elapsed_time - last_time_made_pea.asSeconds()) >= 0.5){
            Vector2f plant_pos = plant_sprite.getPosition();
            plant_pos.x += 50;
            plant_pos.y += 10;
            temp_pea = new Pea(plant_pos);
            
            pea_vec.emplace_back(temp_pea);
            last_time_made_pea = clock->getElapsedTime();
        }
    }
    void remove_pea(Pea * pea_pointer){
        for(vector<Pea*>::size_type i = 0 ; i < pea_vec.size() ; i++){
            if(pea_vec[i] == pea_pointer){
                pea_vec.erase(pea_vec.begin() + i);
            }
        }
    }

    void render_plant(RenderWindow &window , Clock *clock){
        window.draw(plant_sprite);
        make_pea(clock);
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
    void x(Sprite *zombie_sprite){
        if(is_intersected(&plant_sprite , zombie_sprite)){
            cout << "1";
        }
    }
private:
    Texture plant_texture;
    Sprite plant_sprite;    
    bool is_dragging = false;
    Vector2f offset;
    vector <Pea*> pea_vec;
    Pea *temp_pea;
    Time last_time_made_pea = seconds(0);
};

#endif