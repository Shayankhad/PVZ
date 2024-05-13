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
};

#endif

