#include "ppm-engine.hpp"

/*

int main(int argc, char** argv) {

	ppm::image_s* tree = new ppm::image_s(2560, 1440);

	tree->fill(ppm::VERY_DARK_BLUE);
	tree->draw_rect(1180, 900, 1380, 1440, ppm::BROWN);
	tree->draw_circle(1280, 700, 500, ppm::GREEN);
	tree->compile("tree.ppm");

	return 0;
}

*/

int main(int argc, char** argv){

	/*
		Commandline Arguments: ppmparser <input_filename> <output_filename>
	*/
	if(argc != 3){
		std::cerr << "bad format, should be: ppmparser <input_filename> <output_filename>\n";
		return -1;
	}

	const char* input_file = argv[1];
	const char* output_file = argv[2];
}