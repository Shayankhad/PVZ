#include "global.hpp"

class Zombie{
public:
    Zombie(){
        if(!zombie_texture.loadFromFile(ZOMBIE_IMAGE_ADDRESS)){
            cerr << "failed to load zombie image";
        }
        zombie_sprite.setTexture(zombie_texture);
        zombie_sprite.setPosition(start_pos);
    }
    void render_zombie(RenderWindow &window){
        window.draw(zombie_sprite);
    }
    void set_start_pos(Vector2f start_position){
        start_pos = start_position;
    }
private:
    Texture zombie_texture;
    Sprite zombie_sprite;
    Vector2f start_pos;
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
        zombie = new Zombie();
        zombie->set_start_pos({1300 , 300});
    }
    void mouse_press_handeling(){
        while(window.pollEvent(event)){
            if(event.type == Event::EventType::Closed){
                window.close();
            }
        }
    }
    void run(){
        while(window.isOpen()){
            window.clear(Color::Black);
            window.draw(frontyard_sprite);
            zombie->render_zombie(window);
            mouse_press_handeling();
            window.display();
        }
    }
    ~Game(){
        delete zombie;
    }
private:
    Zombie *zombie;
    Event event;
    Texture frontyard_tex;
    Sprite frontyard_sprite;
};



int main(){
    Game pvz;
    pvz.run();
    return 0;
}