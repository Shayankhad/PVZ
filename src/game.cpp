#include "global.hpp"

class Zombie{
public:
    Zombie(Vector2f start_pos){

        if(!zombie_texture.loadFromFile(ZOMBIE_IMAGE_ADDRESS)){
            cerr << "failed to load zombie image";
        }
        
        zombie_sprite.setTexture(zombie_texture);
        zombie_sprite.setScale({0.2 , 0.2});
        zombie_sprite.setPosition(start_pos);
    }
    void render_zombie(RenderWindow &window){

        window.draw(zombie_sprite);
        zombie_sprite.move(-0.2 , 0);
    }

private:
    Texture zombie_texture;
    Sprite zombie_sprite;
};
class Game{
public:
    RenderWindow window;
    Game(){
        window.create(VideoMode(X_WINDOW , Y_WINDOW) , WINDOWS_TITLE);
        if(!frontyard_tex.loadFromFile(BACKGROUND_IMAGE_ADDRESS)){
            cerr << "fialed to open frontyard image!!!";
        }
        frontyard_sprite.setTexture(frontyard_tex);
        //zombie = new Zombie({900 , 50});
    }

    void mouse_press_handeling(){
        while(window.pollEvent(event)){
            if(event.type == Event::EventType::Closed){
                window.close();
            }
        }
    }
    void make_zombie(){
        zombie_temp = new Zombie({900 , 50});
        zombies.emplace_back(zombie_temp);
    }

    void run(){
        Clock clock;
        Time time_passed = seconds(0);
        while(window.isOpen()){
            time_passed += clock.restart();
            if(time_passed > seconds(3)){
                window.close();
            }

            window.clear(Color::Black);
            window.draw(frontyard_sprite);
            make_zombie();
            for(auto& zombie : zombies){
                zombie->render_zombie(window);
            }
            mouse_press_handeling();
            window.display();
        }
    }
    ~Game(){
        delete zombie_temp;
    }
private:
    //Zombie *zombie;
    vector <Zombie*> zombies;
    Zombie *zombie_temp;
    Event event;
    Texture frontyard_tex;
    Sprite frontyard_sprite;
};


int main(){
    Game pvz;
    pvz.run();
    return 0;
}