#include "global.hpp"


Game::Game(){
    load_from_files();
    plant_label = new Plant_label();
    make_dot_board();
    make_sun();
    last_time_made_plant = seconds(0);
}

void Game::load_from_files(){
    window.create(VideoMode(X_WINDOW , Y_WINDOW) , WINDOWS_TITLE);
    if(!frontyard_tex.loadFromFile(BACKGROUND_IMAGE_ADDRESS)){
        cerr << "fialed to open frontyard image!!!";
    }
    frontyard_sprite.setTexture(frontyard_tex);
    if(!game_over_texture.loadFromFile(ZOMBIES_ATE_YOUR_BRAINS_IMAGE_ADDRESS)){
        cerr << "fialed to open game_over image!!!";
    }
    game_over_sprite.setTexture(game_over_texture);
    game_over_sprite.setOrigin(game_over_sprite.getLocalBounds().width / 2 , game_over_sprite.getLocalBounds().height / 2);
    game_over_sprite.setPosition(X_WINDOW/2 , Y_WINDOW/2);
    if(!you_win_texture.loadFromFile(YOU_WIN_IMAGE_ADDRESS)){
        cerr << "fialed to open you_win image!!!";
    }
    you_win_sprite.setTexture(you_win_texture);
    you_win_sprite.setOrigin(you_win_sprite.getLocalBounds().width / 2 , you_win_sprite.getLocalBounds().height / 2);
    you_win_sprite.setPosition(X_WINDOW/2 , Y_WINDOW/2);

    if(!start_screen_texture.loadFromFile(START_SCREEN_IMAGE_ADDRESS)){
        cerr << "fialed to open start_screen image!!!";
    }
    start_screen_sprite.setTexture(start_screen_texture);
    start_screen_sprite.setOrigin(start_screen_sprite.getLocalBounds().width / 2 , start_screen_sprite.getLocalBounds().height / 2);
    start_screen_sprite.setPosition(X_WINDOW/2 , Y_WINDOW/2);

    if(!music.openFromFile(SONG_ADDRESS)){
        cerr << "fialed to open song!!!";
    }
}

void Game::mouse_press_handeling(){
    while(window.pollEvent(event)){
        clicked_on_label();
        sun_mouse_handeling();
        dot_mouse_handeling();
    }
}
void Game::dot_mouse_handeling(){
    for(auto & dot : dot_vec){
        if(event.type == Event::EventType::MouseButtonPressed){
            if(event.mouseButton.button == Mouse::Left){
                if((dot->dot_get_sprite()->getGlobalBounds().contains(event.mouseButton.x , event.mouseButton.y ))
                && (is_dot_board_open == true) && ((clock.getElapsedTime().asSeconds()  - last_time_made_plant.asSeconds() >= AFETER_SECOND_PLANT_AVAILABLE))
                && (collected_sun >= PLANT_SUN_COST)){
                    is_dot_board_open = false;
                    make_plant(dot->get_dot_position());
                    last_time_made_plant = clock.getElapsedTime();
                    dot->set_is_dot_full(true);
                }
            }
        }
    }
}
void Game::sun_mouse_handeling(){
    if(event.type == Event::EventType::MouseButtonPressed){
        if(event.mouseButton.button == Mouse::Left){
            for(vector<Sun*>::size_type i = 0 ; i <sun_vec.size() ; i++){
                if(sun_vec[i]->get_sun_sprite()->getGlobalBounds().contains(event.mouseButton.x , event.mouseButton.y )){
                    sun_vec.erase(sun_vec.begin() + i);
                    collected_sun += SUN_PRICE;
                }
            }
        }
    }
}

void Game::clicked_on_label(){
    if(event.type == Event::EventType::MouseButtonPressed ){
        if(event.mouseButton.button == Mouse::Left){
            if(plant_label->get_plant_label()->getGlobalBounds().contains(event.mouseButton.x , event.mouseButton.y )){
                is_dot_board_open = true;
            }
        }
    }
}

void Game::make_zombie(){
    int random_num = random_number(1 , 5);
    if(random_num == 1){
        zombie_temp = new Zombie({950 , 50});
        zombies.emplace_back(zombie_temp);
    }
    if(random_num == 2){
        zombie_temp = new Zombie({950 , 150});
        zombies.emplace_back(zombie_temp);
    }
    if(random_num == 3){
        zombie_temp = new Zombie({950 , 250});
        zombies.emplace_back(zombie_temp);
    }
    if(random_num == 4){
        zombie_temp = new Zombie({950 , 350});
        zombies.emplace_back(zombie_temp);
    }
    if(random_num == 5){
        zombie_temp = new Zombie({950 , 450});
        zombies.emplace_back(zombie_temp);
    }
}
void Game::check_side(){
    is_side_full = {false , false , false , false , false };
    for(auto & zombie : zombies){
        if(zombie->get_zombie_y_position() == 50){
            is_side_full[0] = true;
        }
        if(zombie->get_zombie_y_position() == 150){
            is_side_full[1] = true;
        }
        if(zombie->get_zombie_y_position() == 250){
            is_side_full[2] = true;
        }
        if(zombie->get_zombie_y_position() == 350){
            is_side_full[3] = true;
        }
        if(zombie->get_zombie_y_position() == 450){
            is_side_full[4] = true;
        }
    }
}

void Game::render_plant_vec(){

    for(auto& plant : plant_vec){
        if(plant->get_plant_y_position() == 130){     
            plant->render_plant(window , &clock ,is_side_full[0]);
        }
        if(plant->get_plant_y_position() == 225){
            plant->render_plant(window , &clock ,is_side_full[1]);
        }
        if(plant->get_plant_y_position() == 325){
            plant->render_plant(window , &clock ,is_side_full[2]);
        }
        if(plant->get_plant_y_position() == 420){
            plant->render_plant(window , &clock ,is_side_full[3]);
        }
        if(plant->get_plant_y_position() == 520){
            plant->render_plant(window , &clock ,is_side_full[4]);
        }
    }
}
void Game::zombie_time_handeling(){
    if(clock.getElapsedTime().asSeconds() - last_time_made_zombie.asSeconds() >= MAKE_ZOMBIE_EACH_SECOND){
        make_zombie();
        
        last_time_made_zombie = clock.getElapsedTime();
    }
}
void Game::run_start_menu(){
    while((!is_clicked_on_first_screen) && (window.isOpen())){
        window.clear(Color::Black);
        window.draw(start_screen_sprite);
        while(window.pollEvent(event)){
            if(event.type == Event::EventType::Closed){
                window.close();
            }
        }
        if(event.type == Event::EventType::MouseButtonPressed){
            if(event.mouseButton.button == Mouse::Left){
                is_clicked_on_first_screen = true;
            }
        }
        window.display();

    }
}

void Game::run_core_game(){
    while((window.isOpen()) && (!is_game_over) && (!is_won)){
        if(event.type == Event::EventType::Closed){
            window.close();
        }
        window.clear(Color::Black);
        zombie_time_handeling();
        check_side();
        window.draw(frontyard_sprite);
        plant_label->render_plant_label(window , &last_time_made_plant , &clock , collected_sun);
        for(auto& zombie : zombies){
            zombie->render_zombie(window);
            for(auto& plant : plant_vec){
                plant->pea_hit_zombie((zombie->get_zombie_sprite()) , zombie);
            }
        }
        check_dead_zombies();
        render_plant_vec();
        mouse_press_handeling();
        if(is_dot_board_open){
            for(auto & dot : dot_vec ){
                dot->draw_dot(window);
            }
        }
        sun_time_handeling();
        for(auto& sun : sun_vec){
            sun->render_sun(&window);
        }
        cout << collected_sun << endl;
        check_game_over();
        check_won();
        
        window.display();
    }
}

void Game::run_game_over(){
    while((window.isOpen()) && (is_game_over)){
        while(window.pollEvent(event)){
            if(event.type == Event::EventType::Closed){
                window.close();
            }
        }
        window.clear();
        window.draw(game_over_sprite);
        window.display();
    }
}

void Game::run_you_win(){
    while((window.isOpen()) && (is_won)){
        while(window.pollEvent(event)){
            if(event.type == Event::EventType::Closed){
                window.close();
            }
        }
        window.clear();
        window.draw(you_win_sprite);
        window.display();
    }
}

void Game::run(){
    music.play();
    run_start_menu();
    run_core_game();
    run_game_over();
    run_you_win();
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

void Game::make_plant(Vector2f plant_position){
    Plant * plant_ptr = new Plant(plant_position);
    plant_vec.emplace_back(plant_ptr);
    collected_sun -= PLANT_SUN_COST;
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

void Game::make_sun(){
    sun_temp = new Sun();
    sun_vec.emplace_back(sun_temp);
}

void Game::sun_time_handeling(){
    if(clock.getElapsedTime().asSeconds() - last_time_made_sun.asSeconds() >= GIVE_SUN_CAPACITY){
        make_sun();
        last_time_made_sun = clock.getElapsedTime();
    }
}

void Game::check_game_over(){
    for(auto& zombie : zombies){
        if(zombie->get_zombie_x_position() <= ZOMBIE_X_LINE_WIN_CONDITION){
            is_game_over = true;
        }
    }
}

void Game::check_won(){
    if(clock.getElapsedTime().asSeconds() >= WIN_TIME_TIME){
        is_won = true;
        
    }
}
void Game::set_text(){
    if (!font->loadFromFile(FONT_ADDRESS)) {
        cerr << "fail to load font!!!";
    }
    text->setFont(*font);
    text->setCharacterSize(24);
    text->setPosition(700, 300);
}
void Game::render_text(){
    stringstream ss;
    ss << collected_sun;
    string str = ss.str();
    string *collected_sun_str = &str;
    text->setString(*collected_sun_str);
}
Game::~Game(){
}