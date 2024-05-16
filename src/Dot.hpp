#ifndef DOT_HPP
#define DOT_HPP
#include "global.hpp"

class Dot{
public:
    Dot(Vector2f dot_position);
    void draw_dot(RenderWindow &window);
    Sprite* dot_get_sprite();
    Vector2f get_dot_position();
    void set_is_dot_full(bool full );
private:
    Texture dot_texture;
    Sprite dot_sprite;
    bool is_dot_full = false;
};

#endif