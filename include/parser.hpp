#pragma once
#include "ppm-engine.hpp"
#include <regex>
#include <sstream>

namespace ppm{

    const std::regex name("NAME\\{[A-Za-z]{1,}\\.ppm\\}");
    const std::regex size("SIZE\\{[0-9]{1,},[0-9]{1,}\\}");
    const std::regex fill("FILL\\{[0-9]{1,3},[0-9]{1,3},[0-9]{1,3}\\}");
    const std::regex rect("RECT\\{[0-9]{1,},[0-9]{1,},[0-9]{1,},[0-9]{1,},[0-9]{1,3},[0-9]{1,3},[0-9]{1,3}\\}");
    const std::regex circle("CIRCLE\\{[0-9]{1,},[0-9]{1,},[0-9]{1,},[0-9]{1,3},[0-9]{1,3},[0-9]{1,3}\\}");
    const std::regex line("LINE\\{[0-9]{1,},[0-9]{1,},[0-9]{1,},[0-9]{1,},[0-9]{1,3},[0-9]{1,3},[0-9]{1,3}\\}");
    const std::regex end("END");

    std::vector<std::string> split(const std::string& str, char delim){

        std::vector<std::string> ret = std::vector<std::string>();

        std::stringstream ss(str);
        std::string token;
        while(std::getline(ss, token, delim)){
            ret.push_back(token);
        }
        return ret;
    }
    struct parser_s {

        const char* input_filename;

        std::vector<std::string> parser_file;

        ppm::image_s* image;

        parser_s();
        parser_s(const char* input_filename);

        void read_file();
        void read_file(const char* filename);

        void create_image();
    };

    parser_s::parser_s(){
        this->image = new ppm::image_s();
        this->parser_file = std::vector<std::string>();
    }

    parser_s::parser_s(const char* input_filename) : parser_s(){
        this->input_filename = input_filename;
    }

    void parser_s::read_file(){
        this->read_file(this->input_filename);
    }

    void parser_s::read_file(const char* filename){
        
        std::ifstream in(filename);

        if(!in){
            std::cerr << "can't open file: " << filename << std::endl;
            return;
        }

        std::string buff;

        while(std::getline(in, buff)){
            this->parser_file.push_back(buff);
        }
    }

    void parser_s::create_image(){
        
        if(this->parser_file.empty()){
            std::cerr << "input file must not be empty." << std::endl;
            return;
        }

        for(std::string current : this->parser_file){

            if(std::regex_match(current, name)){

                std::string content = current.substr(5, current.length() - 6);
                this->image->set_filename(content.c_str());
            }
            else if(std::regex_match(current, size)){

                std::string content = current.substr(5, current.length() - 6);
                std::vector<std::string> values = split(content, ',');

                uint32_t width = std::stoi(values[0]);
                uint32_t height = std::stoi(values[1]);

                this->image->set_dimensions(width, height);
            }
            else if(std::regex_match(current, fill)){

                std::string content = current.substr(5, current.length() - 6);
                std::vector<std::string> values = split(content, ',');

                uint8_t r = std::stoi(values[0]);
                uint8_t g = std::stoi(values[1]);
                uint8_t b = std::stoi(values[2]);

                this->image->fill(ppm::color_s(r, g, b));
            }
            else if(std::regex_match(current, rect)){

                std::string content = current.substr(5, current.length() - 6);
                std::vector<std::string> values = split(content, ',');

                uint32_t x1 = std::stoi(values[0]);
                uint32_t y1 = std::stoi(values[1]);
                uint32_t x2 = std::stoi(values[2]);
                uint32_t y2 = std::stoi(values[3]);
                uint8_t r = std::stoi(values[4]);
                uint8_t g = std::stoi(values[5]);
                uint8_t b = std::stoi(values[6]);

                this->image->draw_rect(x1, y1, x2, y2, ppm::color_s(r, g, b));
            }
            else if(std::regex_match(current, circle)){
                
                std::string content = current.substr(7, current.length() - 8);
                std::vector<std::string> values = split(content, ',');

                uint32_t x = std::stoi(values[0]);
                uint32_t y = std::stoi(values[1]);
                uint32_t rad = std::stoi(values[2]);
                uint8_t r = std::stoi(values[3]);
                uint8_t g = std::stoi(values[4]);
                uint8_t b = std::stoi(values[5]);

                this->image->draw_circle(x, y, rad, ppm::color_s(r, g, b));
            }
            else if(std::regex_match(current, line)){

                std::string content = current.substr(5, current.length() - 6);
                std::vector<std::string> values = split(content, ',');

                uint32_t x1 = std::stoi(values[0]);
                uint32_t y1 = std::stoi(values[1]);
                uint32_t x2 = std::stoi(values[2]);
                uint32_t y2 = std::stoi(values[3]);
                uint8_t r = std::stoi(values[4]);
                uint8_t g = std::stoi(values[5]);
                uint8_t b = std::stoi(values[6]);

                this->image->draw_line(x1, y1, x2, y2, ppm::color_s(r, g, b));
            }
            else if(std::regex_match(current, end)){
                this->image->compile();
            }
        }

    }
}
