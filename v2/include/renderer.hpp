#include "fontsheet.hpp"
#include <fstream>
#include <cmath>

#define FORMAT "P6"

class renderer {

public:
    image* img;
    fontsheet sheet;

public:

    renderer(int width, int height) {

        this->img = new image(width, height);
    }

    ~renderer() {
        delete this->img;
    }

    void fill(color value) {

        vec2 size = this->img->get_size();

        for (int y = 0; y < size.y; y++) {
            for (int x = 0; x < size.x; x++) {

                this->img->set(x, y, value);
            }
        }
    }

    void draw_line(vec2 p0, vec2 p1, color value) {

        //bresenham's line drawing algorithm
        int dx;
        int dy;
        int p;
        int x;
        int y;

        dx = p1.x - p0.x;
        dy = p1.y - p0.y;

        x = p0.x;
        y = p0.y;

        p = 2 * dy - dx;

        while (x < p1.x) {

            if (p >= 0) {

                this->img->set(x, y, value);
                y++;
                p = p + 2 * dy - 2 * dx;
            }

            else {

                this->img->set(x, y, value);
                p = p + 2 * dy;
            }
            x++;
        }
    }

    void draw_rect(vec2 p0, vec2 p1, color value) {

        for (int y = p0.y; y < p1.y; y++) {
            for (int x = p0.x; x < p1.x; x++) {
                this->img->set(x, y, value);
            }
        }
    }

    void draw_circle(vec2 p, int radius, color value) {

        int xmin = p.x - radius;
        int xmax = p.x + radius;
        int ymin = p.y - radius;
        int ymax = p.y + radius;

        for (int y = ymin; y <= ymax; y++) {
            for (int x = xmin; x < xmax; x++) {

                int dx = p.x - x;
                int dy = p.y - y;
                double hyp = sqrt(dx*dx + dy*dy);

                if (hyp <= radius) {

                    int ddx = (2 * dx) + x;
                    int ddy = (2 * dy) + y;

                    this->img->set(x, y, value);
                    this->img->set(ddx, y, value);
                    this->img->set(x, ddy, value);
                    this->img->set(ddx, ddy, value);
                }
            }
        }
    }

    void draw_text(vec2 p, const char* text, int fontsize, color foreground, color background = BLANK) {

        
        this->sheet = fontsheet(foreground, background, fontsize);

        image buff = image(FONT_WIDTH(fontsize), fontsize);

        for (int i = 0; text[i] != '\0'; i++) {

            buff = this->sheet.get_char(tolower(text[i]));
            this->img->insert(buff, vec2(p.x + i * (FONT_WIDTH(fontsize) + FONT_SCALE(fontsize)), p.y));
        }
    }

    void compile(const char* filename) {

        std::ofstream stream;
        vec2 size = this->img->get_size();

        stream.open(filename, std::ios_base::binary);

        if (stream.is_open()) {

            stream << FORMAT << std::endl;
            stream << size.x << " " << size.y << std::endl;
            stream << 255 << std::endl;

            for (int y = 0; y < size.y; y++) {
                for (int x = 0; x < size.x; x++) {
                    stream.write((char*)&this->img->get(x, y), sizeof(pixel) - 1);
                }
                stream.flush();
            }
        }

    }
};