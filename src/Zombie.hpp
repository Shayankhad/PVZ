#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP
#include "global.hpp"
class Zombie{
public:
    Zombie(Vector2f start_pos);
    void render_zombie(RenderWindow &window);
private:
    Texture zombie_texture;
    Sprite zombie_sprite;
};
#endif