#include "global.hpp"



Game::Game(){
    window.create(VideoMode(X_WINDOW , Y_WINDOW) , WINDOWS_TITLE);
    if(!frontyard_tex.loadFromFile(BACKGROUND_IMAGE_ADDRESS)){
        cerr << "fialed to open frontyard image!!!";
    }
    frontyard_sprite.setTexture(frontyard_tex);
    plant = new Plant();
}

void Game::mouse_press_handeling(){
    while(window.pollEvent(event)){
        if(event.type == Event::EventType::Closed){
            window.close();
        }
    }
}


void Game::make_zombie(){
    int random_num = random_number(1 , 5);
    if(random_num == 1){
        zombie_temp = new Zombie({900 , 50});
        zombies.emplace_back(zombie_temp);
    }
    if(random_num == 2){
        zombie_temp = new Zombie({900 , 150});
        zombies.emplace_back(zombie_temp);
    }
    if(random_num == 3){
        zombie_temp = new Zombie({900 , 250});
        zombies.emplace_back(zombie_temp);
    }
    if(random_num == 4){
        zombie_temp = new Zombie({900 , 350});
        zombies.emplace_back(zombie_temp);
    }
    if(random_num == 5){
        zombie_temp = new Zombie({900 , 450});
        zombies.emplace_back(zombie_temp);
    }
}


void Game::run(){
    while(window.isOpen()){
        if(clock.getElapsedTime().asSeconds() - last_time_made_zombie.asSeconds() >= 3){
            make_zombie();
            last_time_made_zombie = clock.getElapsedTime();
        }
        window.clear(Color::Black);
        window.draw(frontyard_sprite);
        
        for(auto& zombie : zombies){
            zombie->render_zombie(window);
        }
        plant->render_plant(window);
        mouse_press_handeling();
        window.display();
    }
}
Game::~Game(){
    delete zombie_temp;
    delete plant;
}


