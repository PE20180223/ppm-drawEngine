#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <cmath>

#define FORMAT "P6"
#define MAX_RGB 255

/*
	Authors: Elias Plank
	Co-Author: Elias Gierlinger

	Date: 15/01/2021
*/

namespace ppm {

	struct Color {

		uint8_t r;
		uint8_t g;
		uint8_t b;

		Color() : r(0), g(0), b(0) {}
		Color(uint8_t r, uint8_t g, uint8_t b) : r(r), g(g), b(b) {}
	};

	typedef Color Pixel;

	static const Pixel
		GREY(192, 192, 192), DARK_GREY(128, 128, 128), VERY_DARK_GREY(64, 64, 64),
		RED(255, 0, 0), DARK_RED(128, 0, 0), VERY_DARK_RED(64, 0, 0),
		YELLOW(255, 255, 0), DARK_YELLOW(128, 128, 0), VERY_DARK_YELLOW(64, 64, 0),
		GREEN(0, 255, 0), DARK_GREEN(0, 128, 0), VERY_DARK_GREEN(0, 64, 0),
		CYAN(0, 255, 255), DARK_CYAN(0, 128, 128), VERY_DARK_CYAN(0, 64, 64),
		BLUE(0, 0, 255), DARK_BLUE(0, 0, 128), VERY_DARK_BLUE(0, 0, 64),
		MAGENTA(255, 0, 255), DARK_MAGENTA(128, 0, 128), VERY_DARK_MAGENTA(64, 0, 64),
		WHITE(255, 255, 255), BLACK(0, 0, 0), BLANK(0, 0, 0), BROWN(165, 100, 6), BELL(69, 4, 20);

	class Image {

	public:
		uint32_t width, height;
		std::vector<std::vector<Pixel>> vImage;

		Image(uint32_t width, uint32_t height);
		~Image();

		void fill(Pixel color);
		void drawRect(uint32_t x1, uint32_t y1, uint32_t x2, uint32_t y2, Color color);
		void drawCircle(uint32_t x, uint32_t y, uint32_t r, Color color);
		void drawLine(uint32_t x1, uint32_t y1, uint32_t x2, uint32_t y2, Color color);
		void compile(const char* filename);
	};

	Image::Image(uint32_t width, uint32_t height) {

		this->height = height;
		this->width = width;


		vImage = std::vector<std::vector<Pixel>>(height, std::vector<Pixel>(width));
	}

	Image::~Image() {
		vImage.resize(0);
	}

	void Image::fill(Pixel color) {

		for (uint32_t i = 0; i < this->height; i++) {
			for (uint32_t j = 0; j < this->width; j++) {
				this->vImage[i][j] = color;
			}
		}

	}

	void Image::drawRect(uint32_t x1, uint32_t y1, uint32_t x2, uint32_t y2, Color color) {

		if (x2 >= this->width) {
			x2 = this->width - 1;
		}
		if (y2 >= this->height) {
			y2 = this->height - 1;
		}

		for (uint32_t i = y1; i < y2; i++) {
			for (uint32_t j = x1; j < x2; j++) {
				this->vImage[i][j] = color;
			}
		}
	}

	void Image::drawCircle(uint32_t x, uint32_t y, uint32_t r, Color color) {

		uint32_t xmin = ((int32_t)x - (int32_t)r < 0 ? 0 : (int32_t)x - (int32_t)r);
		//uint32_t xmax = (x + r >= this->width ? this->width - 1 : x + r);
		uint32_t xmax = x;
		uint32_t ymin = ((int32_t)y - (int32_t)r < 0 ? 0 : (int32_t)y - (int32_t)r);
		//uint32_t ymax = (y + r >= this->height ? this->height - 1 : y + r);
		uint32_t ymax = y;



		uint32_t _x, _y, rp;

		for (uint32_t i = ymin; i <= ymax; i++) {
			for (uint32_t j = xmin; j <= xmax; j++) {

				//std::cout << "i: " << i << "\nj: " << j << std::endl;

				_x = x - j;
				_y = y - i;

				rp = hypot(_x, _y);

				if (rp <= r) {
					this->vImage[i][j] = color;

					uint32_t di = (2 * _y) + i;
					uint32_t dj = (2 * _x) + j;
					uint32_t b = 0;

					if (di >= this->height - 1) {
						di = this->height - 1;
					}
					if (dj >= this->width - 1) {
						dj = this->width - 1;
					}

					this->vImage[di][j] = color;
					this->vImage[i][dj] = color;
					this->vImage[di][dj] = color;
				}
			}
		}
	}

	void Image::drawLine(uint32_t x1, uint32_t y1, uint32_t x2, uint32_t y2, Color color) {

		int32_t dx, dy, p, x, y;

		dx = x2 - x1;
		dy = y2 - y1;

		x = x1;
		y = y1;

		p = 2 * dy - dx;

		while (x < x2) {
			if (p >= 0) {
				this->vImage[y][x] = color;
				y++;
				p = p + 2 * dy - 2 * dx;
			}
			else {
				this->vImage[y][x] = color;
				p = p + 2 * dy;
			}
			x++;
		}

	}

	void Image::compile(const char* filename) {

		std::ofstream imageFileStream;

		imageFileStream.open(filename, std::ios_base::binary);

		if (imageFileStream.is_open()) {
			imageFileStream << FORMAT << std::endl;
			imageFileStream << this->width << " " << this->height << std::endl;
			imageFileStream << MAX_RGB << std::endl;

			for (uint32_t i = 0; i < this->height; i++) {
				for (uint32_t j = 0; j < this->width; j++) {
					imageFileStream.write((char*)&this->vImage[i][j], sizeof(Pixel));
				}
			}

			imageFileStream.close();
		}
	}
}