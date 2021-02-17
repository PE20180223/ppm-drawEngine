#include "parser.hpp"

int main(int argc, char** argv){

	/*
		Commandline Arguments: ppmparser <input_filename>
	*/
	if(argc != 2){
		std::cerr << "bad format, should be: ppmparser <input_filename>\n";
		return -1;
	}

	const char* input_file = argv[1];

	ppm::parser_s parser = ppm::parser_s();

	parser.read_file(input_file);
	parser.create_image();
	return 0;
}