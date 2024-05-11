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
    zombie_sprite.move(-0.4 , 0);
}