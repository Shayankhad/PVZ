#ifndef SUNFLOWER_LABEL_HPP
#define SUNFLOWER_LABEL_HPP

#include "global.hpp"

class Sunflower_label {
public:
    Sunflower_label() {
        if (!sunflower_label_texture.loadFromFile(SUNFLOWER_LABEL_ADDRESS)) {
            cerr << "Failed to load sunflower label image";
        }
        sunflower_label_sprite.setTexture(sunflower_label_texture);
        sunflower_label_sprite.setPosition({0, 100});
        sunflower_label_sprite.setScale(0.5, 0.5);
    }

    void render_sunflower_label(RenderWindow& window) {
        window.draw(sunflower_label_sprite);
    }

    Sprite* get_sunflower_label() {
        return &sunflower_label_sprite;
    }

private:
    Texture sunflower_label_texture;
    Sprite sunflower_label_sprite;
};

#endif

