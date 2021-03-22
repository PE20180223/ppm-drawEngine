#pragma once
#include "color.hpp"
#include "vec.hpp"
#include <vector>
#include <memory>

typedef color pixel;

class image {

private:
    int width;
    int height;
    std::unique_ptr<pixel> pimage;

public:

    image(int width, int height){

        this->width = width;
        this->height = height;
        this->pimage = std::unique_ptr<pixel>(new pixel[height * width]);

        for (int i = 0; i < height * width; i++) {
            this->pimage.get()[i] = (pixel)BLANK;
        }
    }

    pixel* get_ptr() const {

        return this->pimage.get();
    }

    pixel& get(int x, int y) const {

        return this->pimage.get()[y * this->width + x];
    }

    image& set(int x, int y, pixel value){

        if (value.transparent) {
            return *this;
        }

        x = (x < 0 ? 0 : x);
        x = (x >= this->width ? this->width - 1 : x);
        y = (y < 0 ? 0 : y);
        y = (y >= this->height ? this->height - 1 : y);

        this->pimage.get()[y * this->width + x] = value;
	    return *this;
    } 

    vec2 get_size() const {

        return vec2(this->width, this->height);
    }

    void set_scaled(vec2 p, int scale, color value) {

        if (value.transparent)
            return;

        for (int y = 0; y < scale; y++) {
            for (int x = 0; x < scale; x++) {
                this->set(x + p.x, y + p.y, value);
            }
        }
    }

    void insert(image& source, vec2 p) {

        vec2 size = source.get_size();

        for (int y = 0; y < size.y; y++) {
            for (int x = 0; x < size.x; x++) {

                this->set(p.x + x, p.y + y, source.get(x, y));
            }
        }
    }

    void insert_row(std::vector<pixel> row, int scale, int y) {

        image buff = image(row.size() * scale, scale);

        for (int i = 0; i < row.size() * scale; i += scale) {

            buff.set_scaled(vec2(i, 0), scale, row[i / scale]);
        }

        this->insert(buff, vec2(0, y * scale));
    }
};
