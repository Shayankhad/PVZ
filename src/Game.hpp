#ifndef GAME_HPP
#define GAME_HPP
#include "global.hpp"

class Game{
public:
    RenderWindow window;
    Game();
    void mouse_press_handeling();
    void make_zombie();
    void run();
    Time get_elapsed_time();
    void check_dead_zombies();
    void make_plant(Vector2f plant_position);
    void clicked_on_label();
    void make_dot_board();
    ~Game();
private:
    vector <Zombie*> zombies;
    Zombie *zombie_temp;
    Event event;
    Texture frontyard_tex;
    Sprite frontyard_sprite;
    Clock clock;
    Time last_time_made_zombie;
    vector<Plant*> plant_vec;
    Plant_label *plant_label;
    vector<Dot*> dot_vec;
    Dot * temp_dot;
    bool is_dot_board_open = false;
};

#endif

