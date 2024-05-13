#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP
#include "global.hpp"
class Zombie{
public:
    Zombie(Vector2f start_pos);
    void render_zombie(RenderWindow &window);
    Sprite* get_zombie_sprite();
    void decrease_health(int damage);
    int get_health();
private:
    Texture zombie_texture;
    Sprite zombie_sprite;
    int health = ZOMBIE_HEALTH;
};
#endif