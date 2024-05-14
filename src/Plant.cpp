#include "global.hpp"



Plant::Plant(Vector2f plant_position){
    if(!plant_texture.loadFromFile(PEASHOOTER_IMAGE_ADDRESS)){
        cerr << "failed to load plant image";
    }
    plant_sprite.setTexture(plant_texture);
    plant_sprite.setOrigin(plant_sprite.getLocalBounds().width / 2 , plant_sprite.getLocalBounds().height/2 );
    plant_sprite.setScale({0.05 , 0.05});
    plant_sprite.setPosition(plant_position);
}

void Plant::make_pea(Clock *clock){
    int elapsed_time = clock->getElapsedTime().asSeconds();
    if((elapsed_time - last_time_made_pea.asSeconds()) >= PLANT_SHOOTING_SPEED ){
        Vector2f plant_pos = plant_sprite.getPosition();
        plant_pos.x += 50;
        plant_pos.y += 10;
        temp_pea = new Pea(plant_pos);
        
        pea_vec.emplace_back(temp_pea);
        last_time_made_pea = clock->getElapsedTime();
    }
}
void Plant::remove_pea(Pea * pea_pointer){
    for(vector<Pea*>::size_type i = 0 ; i < pea_vec.size() ; i++){
        if(pea_vec[i] == pea_pointer){
            pea_vec.erase(pea_vec.begin() + i);
        }
    }
}

void Plant::render_plant(RenderWindow &window , Clock *clock , bool is_side_full){
    window.draw(plant_sprite);
    if(is_side_full){
        make_pea(clock);
    }
    for(auto& pea : pea_vec){
        pea->render_pea(window);
    }
    
}

void Plant::plant_mouse_handle(Event * event , RenderWindow * window){
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

bool Plant::get_is_dragging(){
    return is_dragging;
}
Sprite* Plant::get_plant_sprite_ptr(){
    return &plant_sprite;
}
void Plant::pea_hit_zombie(Sprite *zombie_sprite , Zombie *zombie_pointer){
    for(vector<Pea*>::size_type i = 0 ; i < pea_vec.size() ; i++){
        if(is_intersected( (pea_vec[i]->get_pea_sprite()) , *zombie_sprite)){
            pea_vec.erase(pea_vec.begin() + i);
            zombie_pointer->decrease_health(PEA_DAMAGE);
        }
    }
}
int Plant::get_plant_y_position(){
    return plant_sprite.getPosition().y;
}
