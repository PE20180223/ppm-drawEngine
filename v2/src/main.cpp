#include "renderer.hpp"


int main() {

	renderer* render = new renderer(800, 400);

	render->fill(YELLOW);
	render->draw_text({ 10, 10 }, "hello world", 60, PINK);
	render->compile("testfile.ppm");
	render->~renderer();
	return 0;
}
