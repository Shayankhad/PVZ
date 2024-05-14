#ifndef GAME_HPP
#define GAME_HPP
#include "global.hpp"

class Game{
public:
    RenderWindow window;
    Game();
    void mouse_press_handeling();
    void make_zombie();
    void zombie_time_handeling();
    void run();
    Time get_elapsed_time();
    void check_dead_zombies();
    void make_plant(Vector2f plant_position);
    void clicked_on_label();
    void make_dot_board();
    void check_side();
    void render_plant_vec();
    void sun_mouse_handeling();
    void make_sun();
    void sun_time_handeling();
    void set_text();
    ~Game();
private:
    vector <Zombie*> zombies;
    Zombie *zombie_temp;
    Event event;
    Texture frontyard_tex;
    Sprite frontyard_sprite;
    Clock clock;
    Time last_time_made_zombie;
    Time last_time_made_sun;
    vector<Plant*> plant_vec;
    Plant_label *plant_label;
    vector<Dot*> dot_vec;
    Dot * temp_dot;
    bool is_dot_board_open = false;
    vector <bool> is_side_full;
    vector<Sun*> sun_vec;
    Sun *sun_temp;
    int collected_sun = 50;
    Text text;
};

#endif

