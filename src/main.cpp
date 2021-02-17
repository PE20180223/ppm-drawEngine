#include "ppm-engine.hpp"

int main(int argc, char** argv) {

	ppm::Image* Tree = new ppm::Image(2560, 1440);

	Tree->fill(ppm::VERY_DARK_BLUE);
	Tree->drawRect(1180, 900, 1380, 1440, ppm::BROWN);
	Tree->drawCircle(1280, 700, 500, ppm::GREEN);
	Tree->compile("tree.ppm");

	return 0;
}