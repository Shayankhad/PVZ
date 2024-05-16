#ifndef GLOBAL_HPP
#define GLOBALL_HPP
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <iostream>
#include <random>
#include <chrono>
#include <sstream>
#include "random_number.hpp"
#include "Game.hpp"
#include "Plant.hpp"
#include "Zombie.hpp"
#include "Pea.hpp"
#include "is_intersected.hpp"
#include "Plant_label.hpp"
#include "Dot.hpp"
#include "Sun.hpp"
#include "Sunflower_label.hpp"
#include "Sunflower.hpp"
#define X_WINDOW 1400
#define Y_WINDOW 600
#define WINDOWS_TITLE "PVZ"
#define BACKGROUND_IMAGE_ADDRESS "files/pics/Frontyard.png"
#define ZOMBIE_IMAGE_ADDRESS "files/pics/Normal_Zombie.png"
#define PEASHOOTER_IMAGE_ADDRESS "files/pics/Peashooter.png" 
#define PEA_IMAGE_ADDRESS "files/pics/Pea.png"
#define OPENED_PEASHOOTER_LABEL_ADDRESS "files/pics/Opened Peashooter Label.png"
#define SUNFLOWER_LABEL_ADDRESS "files/pics/Sunflower_Label.png"
#define CLOSED_PEASHOOTER_LABEL_ADDRESS "files/pics/Closed Peashooter Label.png"
#define DOT_IMAGE_ADDRESS "files/pics/Dot.png"
#define SUN_IAMGE_ADDRESS "files/pics/Sun.png"
#define ZOMBIES_ATE_YOUR_BRAINS_IMAGE_ADDRESS "files/pics/THE ZOMBIES ATE YOUR BRAINS!.png"
#define YOU_WIN_IMAGE_ADDRESS "files/pics/you win.png"
#define START_SCREEN_IMAGE_ADDRESS "files/pics/start_screen.png"
#define SUN_FLOWER_IMAGE_ADDRESS "files/pics/dsunflower.png"
#define FONT_ADDRESS "files/Font/arial.ttf"
#define SONG_ADDRESS "files/audio/song.ogg"
#define SUNFLOWER_CLOSED_IMAGE_ADDRESS "files/pics/icon_sunflower_dim.png"
#define WALNUT_CLOSED_IMAGE_ADDRESS "files/pics/icon_walnut_dim.png"
#define PEA_DAMAGE 25
#define ZOMBIE_HEALTH 100
#define ZOMBIE_SPEED -0.2
#define MAKE_ZOMBIE_EACH_SECOND 5
#define SUN_SPEED 0.3
#define PLANT_SHOOTING_SPEED 1
#define PLANT_SUN_COST  100
#define GIVE_SUN_CAPACITY 5
#define PEA_SPEED 4
#define WIN_TIME_TIME 300
#define AFETER_SECOND_PLANT_AVAILABLE 5
#define SUN_PRICE 25
#define ZOMBIE_X_LINE_WIN_CONDITION 230 
using namespace std;
using namespace sf;
#endif
