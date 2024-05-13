#ifndef PEA_HPP
#define PEA_HPP
#include "global.hpp"

class Pea{
public:
    Pea(Vector2f start_pos);
    void render_pea(RenderWindow &window);
    Sprite get_pea_sprite();
private:
    Texture pea_texture;
    Sprite pea_sprite;
};

#endif