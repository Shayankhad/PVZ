#ifndef GLOBAL_HPP
#define GLOBALL_HPP
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <string>
#include <iostream>
#include <random>
#include <chrono>
#include "random_number.hpp"
#include "Game.hpp"
#include "Plant.hpp"
#include "Zombie.hpp"
#include "Pea.hpp"
#include "is_intersected.hpp"



#define X_WINDOW 1400
#define Y_WINDOW 600
#define WINDOWS_TITLE "PVZ"
#define BACKGROUND_IMAGE_ADDRESS "files/pics/Frontyard.png"
#define ZOMBIE_IMAGE_ADDRESS "files/pics/Normal_Zombie.png"
#define PEASHOOTER_IMAGE_ADDRESS "files/pics/Peashooter.png" 
#define PEA_IMAGE_ADDRESS "files/pics/Pea.png"
#define OPENED_PEASHOOTER_LABEL_ADDRESS "files/pics/Opened Peashooter Label.png"
#define CLOSED_PEASHOOTER_LABEL_ADDRESS "files/pics/Closed Peashooter Label.png"
#define PEA_DAMAGE 25
#define ZOMBIE_HEALTH 100
using namespace std;
using namespace sf;
#endif