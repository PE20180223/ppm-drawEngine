#pragma once
#include "image.hpp"
#include <functional>

struct character {

    char repr;
    std::function<image(color, color, int)> draw_routine;

    character(char repr, std::function<image(color, color, int)> draw_routine) {
        this->repr = repr;
        this->draw_routine = draw_routine;
    }

    image draw(color foreground, color background, int fontsize) {

        return this->draw_routine(foreground, background, fontsize);
    }
};