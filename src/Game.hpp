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
    ~Game();
private:
    //Zombie *zombie;
    vector <Zombie*> zombies;
    Zombie *zombie_temp;
    Event event;
    Texture frontyard_tex;
    Sprite frontyard_sprite;
    Clock clock;
    Time last_time_made_zombie;
    Plant *plant;
};
#endif

