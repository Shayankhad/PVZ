#include "global.hpp"

bool is_intersected(Sprite sprite_1 , Sprite sprite_2 ){
    FloatRect rect_1 = sprite_1.getGlobalBounds();
    FloatRect rect_2 = sprite_2.getGlobalBounds();
    if(rect_1.intersects(rect_2)){
        return true;
    }else{
        return false;
    }
}