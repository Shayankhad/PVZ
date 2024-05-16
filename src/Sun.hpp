#ifndef SUN_HPP
#define SUN_HPP
#include "global.hpp"

class Sun{
public:
    Sun();
    void render_sun(RenderWindow *window);
    Sprite* get_sun_sprite();
private:
    Texture sun_texture;
    Sprite sun_sprite;
};
#endif
