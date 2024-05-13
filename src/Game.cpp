#include "global.hpp"



Game::Game(){
    window.create(VideoMode(X_WINDOW , Y_WINDOW) , WINDOWS_TITLE);
    if(!frontyard_tex.loadFromFile(BACKGROUND_IMAGE_ADDRESS)){
        cerr << "fialed to open frontyard image!!!";
    }
    frontyard_sprite.setTexture(frontyard_tex);
    plant_label = new Plant_label();
    make_dot_board();
}

void Game::mouse_press_handeling(){
    while(window.pollEvent(event)){
        
        if(event.type == Event::EventType::Closed){
            window.close();
        }
        for(auto& plant : plant_vec){
            plant->plant_mouse_handle(&event , &window);
        }
        clicked_on_label();
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
        window.clear(Color::Black);
        if(clock.getElapsedTime().asSeconds() - last_time_made_zombie.asSeconds() >= 3){
            make_zombie();
            last_time_made_zombie = clock.getElapsedTime();
        }
        

        window.draw(frontyard_sprite);
        plant_label->render_plant_label(window);
        for(auto& zombie : zombies){
            zombie->render_zombie(window);
            for(auto& plant : plant_vec){
                plant->pea_hit_zombie((zombie->get_zombie_sprite()) , zombie);
            }
        }
        check_dead_zombies();
        for(auto& plant : plant_vec){
           plant->render_plant(window , &clock); 
        }
        mouse_press_handeling();
        if(is_dot_board_open){
            for(auto & dot : dot_vec ){
                dot->draw_dot(window);
            }
        }

        window.display();
    }
    
}

Time Game::get_elapsed_time(){
    Time elapsed_time;
    elapsed_time = clock.getElapsedTime();
    return elapsed_time;
}

void Game::check_dead_zombies(){
    for (vector<Zombie*>::size_type i = 0; i < zombies.size() ; i++){
        if(zombies[i]->get_health() <=0){
            zombies.erase(zombies.begin() + i);
        }
    }
}

void Game::make_plant(){
    Plant * plant_ptr = new Plant();
    plant_vec.emplace_back(plant_ptr);
}

void Game::clicked_on_label(){
    if(event.type == Event::EventType::MouseButtonPressed ){
        if(event.mouseButton.button == Mouse::Left){
            if(plant_label->get_plant_label()->getGlobalBounds().contains(event.mouseButton.x , event.mouseButton.y )){
                make_plant();
                is_dot_board_open = true;
            }
        }
    }
}
void Game::make_dot_board(){

    vector <Vector2f> dot_positions = {{295 , 130} , {374 , 130}
    , {455 , 130} , {537 , 130} , {618 , 130} , {700 , 130} 
    , {777 , 130} , {853 , 130} , {937 , 130} , {300 , 225} 
    , {452 , 225} , {535 , 225} , {614 , 225} , {373 , 225}
    , {695 , 225} , {775 , 225} , {850 , 225} , {943 , 225}
    , {300 , 325} , {374 , 325} , {457 , 325} , {540 , 325}
    , {615 , 325} , {697 , 325} , {776 , 325} , {856 , 325}
    , {948 , 325} , {293 , 420} , {374 , 420} , {456 , 420}
    , {537 , 420} , {614 , 420} , {697 , 420} , {775 , 420}
    , {857 , 420} , {946 , 420} , {290 , 520} , {376 , 520}
    , {457 , 520} , {540 , 520} , {622 , 520} , {700 , 520}
    , {780 , 520} , {861 , 520} , {947 , 520}};
    
    for(auto& pos : dot_positions){
        temp_dot = new Dot(pos);
        dot_vec.emplace_back(temp_dot);
    }
}

Game::~Game(){
    delete zombie_temp;
}


