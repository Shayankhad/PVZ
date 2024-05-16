#ifndef PLANT_LABEL_HPP
#define PLANT_LABEL_HPP
#include "global.hpp"

class Plant_label{
public:
    Plant_label();
    void set_sprite_label(bool open_or_close);
    void render_plant_label(RenderWindow &window , Time *last_time_made_plant , Clock *clock , int collected_sun );
    Sprite* get_plant_label();
private:    
    Texture plant_label_texture;
    Sprite plant_label_sprite;
};

#endif
