#include "global.hpp"


Zombie::Zombie(Vector2f start_pos){
        if(!zombie_texture.loadFromFile(ZOMBIE_IMAGE_ADDRESS)){
            cerr << "failed to load zombie image";
        }
        zombie_sprite.setTexture(zombie_texture);
        zombie_sprite.setScale({0.2 , 0.2});
        zombie_sprite.setPosition(start_pos);
    }

void Zombie::render_zombie(RenderWindow &window){
    window.draw(zombie_sprite);
    zombie_sprite.move(ZOMBIE_SPEED , 0);
}

Sprite* Zombie::get_zombie_sprite(){
        return &zombie_sprite;
}

void Zombie::decrease_health(int damage){
    health -= damage;
}
int Zombie::get_health(){
    return health;
}

int Zombie::get_zombie_y_position(){
    return zombie_sprite.getPosition().y;
}

int Zombie::get_zombie_x_position(){
    return zombie_sprite.getPosition().x;
}