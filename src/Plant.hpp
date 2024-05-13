#ifndef PLANT_HPP
#define PLANT_HPP
#include "global.hpp"


class Plant{
public:
    Plant(Vector2f plant_position);

    void make_pea(Clock *clock);
    void remove_pea(Pea * pea_pointer);

    void render_plant(RenderWindow &window , Clock *clock);
    void plant_mouse_handle(Event * event , RenderWindow * window);
    bool get_is_dragging();
    Sprite* get_plant_sprite_ptr();
    void pea_hit_zombie(Sprite *zombie_sprite , Zombie *zombie_pointer);
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