#pragma once
#include "text.hpp"
#include <vector>

#define FONT_SCALE(arg) (arg / 6)
#define FONT_WIDTH(arg) (FONT_SCALE(arg) * 5)

class fontsheet {

private:

	int fontsize;
	color foreground;
	color background;

	std::vector<character> sheet;

public:

	fontsheet() {

		this->fontsize = 0;
		this->foreground = color();
		this->background = color();
		this->sheet = std::vector<character>();
	}

	fontsheet(color foreground, color background, int fontsize) {

		this->foreground = foreground;
		this->background = background;
		this->fontsize = fontsize;

		this->construct_sheet();
	}

	image get_char(const char repr) {

		for (auto cur : sheet) {

			if (repr == cur.repr) {
				return cur.draw(this->foreground, this->background, this->fontsize);
			}
		}
		return image(0, 0);
	}

	void construct_sheet() {

		this->sheet = {

            character('a',
                [](color foreground, color background, int fontsize) -> image {

                    image buff = image(FONT_WIDTH(fontsize), fontsize);

                    buff.insert_row({ background, foreground, foreground, foreground, background }, FONT_SCALE(fontsize), 0);
                    buff.insert_row({ foreground, background, background, background, foreground }, FONT_SCALE(fontsize), 1);
                    buff.insert_row({ foreground, foreground, foreground, foreground, foreground }, FONT_SCALE(fontsize), 2);
                    buff.insert_row({ foreground, background, background, background, foreground }, FONT_SCALE(fontsize), 3);
                    buff.insert_row({ foreground, background, background, background, foreground }, FONT_SCALE(fontsize), 4);
                    buff.insert_row({ foreground, background, background, background, foreground }, FONT_SCALE(fontsize), 5);

                    return buff;
                }
            ),

            character('b',
                [](color foreground, color background, int fontsize) -> image {

                    image buff = image(FONT_WIDTH(fontsize), fontsize);

                    buff.insert_row({ foreground, foreground, foreground, foreground, background }, FONT_SCALE(fontsize), 0);
                    buff.insert_row({ foreground, background, background, background, foreground }, FONT_SCALE(fontsize), 1);
                    buff.insert_row({ foreground, foreground, foreground, foreground, background }, FONT_SCALE(fontsize), 2);
                    buff.insert_row({ foreground, background, background, background, foreground }, FONT_SCALE(fontsize), 3);
                    buff.insert_row({ foreground, background, background, background, foreground }, FONT_SCALE(fontsize), 4);
                    buff.insert_row({ foreground, foreground, foreground, foreground, background }, FONT_SCALE(fontsize), 5);

                    return buff;
                }
            ),

            character('c',
                [](color foreground, color background, int fontsize) -> image {

                    image buff = image(FONT_WIDTH(fontsize), fontsize);

                    buff.insert_row({ background, foreground, foreground, foreground, background }, FONT_SCALE(fontsize), 0);
                    buff.insert_row({ foreground, background, background, background, foreground }, FONT_SCALE(fontsize), 1);
                    buff.insert_row({ foreground, background, background, background, background }, FONT_SCALE(fontsize), 2);
                    buff.insert_row({ foreground, background, background, background, background }, FONT_SCALE(fontsize), 3);
                    buff.insert_row({ foreground, background, background, background, foreground }, FONT_SCALE(fontsize), 4);
                    buff.insert_row({ background, foreground, foreground, foreground, background }, FONT_SCALE(fontsize), 5);

                    return buff;
                }
            ),

            character('d',
                [](color foreground, color background, int fontsize) -> image {

                    image buff = image(FONT_WIDTH(fontsize), fontsize);

                    buff.insert_row({ foreground, foreground, foreground, foreground, background }, FONT_SCALE(fontsize), 0);
                    buff.insert_row({ foreground, background, background, background, foreground }, FONT_SCALE(fontsize), 1);
                    buff.insert_row({ foreground, background, background, background, foreground }, FONT_SCALE(fontsize), 2);
                    buff.insert_row({ foreground, background, background, background, foreground }, FONT_SCALE(fontsize), 3);
                    buff.insert_row({ foreground, background, background, background, foreground }, FONT_SCALE(fontsize), 4);
                    buff.insert_row({ foreground, foreground, foreground, foreground, background }, FONT_SCALE(fontsize), 5);

                    return buff;
                }
            ),

            character('e',
                [](color foreground, color background, int fontsize) -> image {

                    image buff = image(FONT_WIDTH(fontsize), fontsize);

                    buff.insert_row({ foreground, foreground, foreground, foreground, foreground }, FONT_SCALE(fontsize), 0);
                    buff.insert_row({ foreground, background, background, background, background }, FONT_SCALE(fontsize), 1);
                    buff.insert_row({ foreground, foreground, foreground, background, background }, FONT_SCALE(fontsize), 2);
                    buff.insert_row({ foreground, background, background, background, background }, FONT_SCALE(fontsize), 3);
                    buff.insert_row({ foreground, background, background, background, background }, FONT_SCALE(fontsize), 4);
                    buff.insert_row({ foreground, foreground, foreground, foreground, foreground }, FONT_SCALE(fontsize), 5);

                    return buff;
                }
            ),

            character('f',
                [](color foreground, color background, int fontsize) -> image {

                    image buff = image(FONT_WIDTH(fontsize), fontsize);

                    buff.insert_row({ foreground, foreground, foreground, foreground, foreground }, FONT_SCALE(fontsize), 0);
                    buff.insert_row({ foreground, background, background, background, background }, FONT_SCALE(fontsize), 1);
                    buff.insert_row({ foreground, foreground, foreground, background, background }, FONT_SCALE(fontsize), 2);
                    buff.insert_row({ foreground, background, background, background, background }, FONT_SCALE(fontsize), 3);
                    buff.insert_row({ foreground, background, background, background, background }, FONT_SCALE(fontsize), 4);
                    buff.insert_row({ foreground, background, background, background, background }, FONT_SCALE(fontsize), 5);

                    return buff;
                }
            ),

            character('g',
                [](color foreground, color background, int fontsize) -> image {

                    image buff = image(FONT_WIDTH(fontsize), fontsize);

                    buff.insert_row({ background, foreground, foreground, foreground, background }, FONT_SCALE(fontsize), 0);
                    buff.insert_row({ foreground, background, background, background, foreground }, FONT_SCALE(fontsize), 1);
                    buff.insert_row({ foreground, background, background, background, background }, FONT_SCALE(fontsize), 2);
                    buff.insert_row({ foreground, background, background, foreground, foreground }, FONT_SCALE(fontsize), 3);
                    buff.insert_row({ foreground, background, background, background, foreground }, FONT_SCALE(fontsize), 4);
                    buff.insert_row({ background, foreground, foreground, foreground, background }, FONT_SCALE(fontsize), 5);

                    return buff;
                }
            ),

            character('h',
                [](color foreground, color background, int fontsize) -> image {

                    image buff = image(FONT_WIDTH(fontsize), fontsize);

                    buff.insert_row({ foreground, background, background, foreground, background }, FONT_SCALE(fontsize), 0);
                    buff.insert_row({ foreground, background, background, foreground, background }, FONT_SCALE(fontsize), 1);
                    buff.insert_row({ foreground, foreground, foreground, foreground, background }, FONT_SCALE(fontsize), 2);
                    buff.insert_row({ foreground, background, background, foreground, background }, FONT_SCALE(fontsize), 3);
                    buff.insert_row({ foreground, background, background, foreground, background }, FONT_SCALE(fontsize), 4);
                    buff.insert_row({ foreground, background, background, foreground, background }, FONT_SCALE(fontsize), 5);

                    return buff;
                }
            ),

            character('i',
                [](color foreground, color background, int fontsize) -> image {

                    image buff = image(FONT_WIDTH(fontsize), fontsize);

                    buff.insert_row({ background, background, foreground, background, background }, FONT_SCALE(fontsize), 0);
                    buff.insert_row({ background, background, foreground, background, background }, FONT_SCALE(fontsize), 1);
                    buff.insert_row({ background, background, foreground, background, background }, FONT_SCALE(fontsize), 2);
                    buff.insert_row({ background, background, foreground, background, background }, FONT_SCALE(fontsize), 3);
                    buff.insert_row({ background, background, foreground, background, background }, FONT_SCALE(fontsize), 4);
                    buff.insert_row({ background, background, foreground, background, background }, FONT_SCALE(fontsize), 5);

                    return buff;
                }
            ),

            character('j',
                [](color foreground, color background, int fontsize) -> image {

                    image buff = image(FONT_WIDTH(fontsize), fontsize);

                    buff.insert_row({ background, background, background, background, foreground }, FONT_SCALE(fontsize), 0);
                    buff.insert_row({ background, background, background, background, foreground }, FONT_SCALE(fontsize), 1);
                    buff.insert_row({ background, background, background, background, foreground }, FONT_SCALE(fontsize), 2);
                    buff.insert_row({ background, background, background, background, foreground }, FONT_SCALE(fontsize), 3);
                    buff.insert_row({ foreground, background, background, background, foreground }, FONT_SCALE(fontsize), 4);
                    buff.insert_row({ background, foreground, foreground, foreground, background }, FONT_SCALE(fontsize), 5);

                    return buff;
                }
            ),

            character('k',
                [](color foreground, color background, int fontsize) -> image {

                    image buff = image(FONT_WIDTH(fontsize), fontsize);

                    buff.insert_row({ foreground, background, background, foreground, background }, FONT_SCALE(fontsize), 0);
                    buff.insert_row({ foreground, background, foreground, background, background }, FONT_SCALE(fontsize), 1);
                    buff.insert_row({ foreground, foreground, background, background, background }, FONT_SCALE(fontsize), 2);
                    buff.insert_row({ foreground, background, foreground, background, background }, FONT_SCALE(fontsize), 3);
                    buff.insert_row({ foreground, background, background, foreground, background }, FONT_SCALE(fontsize), 4);
                    buff.insert_row({ foreground, background, background, foreground, background }, FONT_SCALE(fontsize), 5);

                    return buff;
                }
            ),

            character('l',
                [](color foreground, color background, int fontsize) -> image {

                    image buff = image(FONT_WIDTH(fontsize), fontsize);

                    buff.insert_row({ foreground, background, background, background, background }, FONT_SCALE(fontsize), 0);
                    buff.insert_row({ foreground, background, background, background, background }, FONT_SCALE(fontsize), 1);
                    buff.insert_row({ foreground, background, background, background, background }, FONT_SCALE(fontsize), 2);
                    buff.insert_row({ foreground, background, background, background, background }, FONT_SCALE(fontsize), 3);
                    buff.insert_row({ foreground, background, background, background, background }, FONT_SCALE(fontsize), 4);
                    buff.insert_row({ foreground, foreground, foreground, foreground, background }, FONT_SCALE(fontsize), 5);

                    return buff;
                }
            ),

            character('m',
                [](color foreground, color background, int fontsize) -> image {

                    image buff = image(FONT_WIDTH(fontsize), fontsize);

                    buff.insert_row({ foreground, background, background, background, foreground }, FONT_SCALE(fontsize), 0);
                    buff.insert_row({ foreground, foreground, background, foreground, foreground }, FONT_SCALE(fontsize), 1);
                    buff.insert_row({ foreground, background, foreground, background, foreground }, FONT_SCALE(fontsize), 2);
                    buff.insert_row({ foreground, background, background, background, foreground }, FONT_SCALE(fontsize), 3);
                    buff.insert_row({ foreground, background, background, background, foreground }, FONT_SCALE(fontsize), 4);
                    buff.insert_row({ foreground, background, background, background, foreground }, FONT_SCALE(fontsize), 5);

                    return buff;
                }
            ),

            character('n',
                [](color foreground, color background, int fontsize) -> image {

                    image buff = image(FONT_WIDTH(fontsize), fontsize);

                    buff.insert_row({ foreground, background, background, background, foreground }, FONT_SCALE(fontsize), 0);
                    buff.insert_row({ foreground, foreground, background, background, foreground }, FONT_SCALE(fontsize), 1);
                    buff.insert_row({ foreground, background, foreground, background, foreground }, FONT_SCALE(fontsize), 2);
                    buff.insert_row({ foreground, background, background, foreground, foreground }, FONT_SCALE(fontsize), 3);
                    buff.insert_row({ foreground, background, background, foreground, foreground }, FONT_SCALE(fontsize), 4);
                    buff.insert_row({ foreground, background, background, background, foreground }, FONT_SCALE(fontsize), 5);

                    return buff;
                }
            ),

            character('o',
                [](color foreground, color background, int fontsize) -> image {

                    image buff = image(FONT_WIDTH(fontsize), fontsize);

                    buff.insert_row({ background, foreground, foreground, foreground, background }, FONT_SCALE(fontsize), 0);
                    buff.insert_row({ foreground, background, background, background, foreground }, FONT_SCALE(fontsize), 1);
                    buff.insert_row({ foreground, background, background, background, foreground }, FONT_SCALE(fontsize), 2);
                    buff.insert_row({ foreground, background, background, background, foreground }, FONT_SCALE(fontsize), 3);
                    buff.insert_row({ foreground, background, background, background, foreground }, FONT_SCALE(fontsize), 4);
                    buff.insert_row({ background, foreground, foreground, foreground, background }, FONT_SCALE(fontsize), 5);

                    return buff;
                }
            ),

            character('p',
                [](color foreground, color background, int fontsize) -> image {

                    image buff = image(FONT_WIDTH(fontsize), fontsize);

                    buff.insert_row({ foreground, foreground, foreground, foreground, background }, FONT_SCALE(fontsize), 0);
                    buff.insert_row({ foreground, background, background, background, foreground }, FONT_SCALE(fontsize), 1);
                    buff.insert_row({ foreground, foreground, foreground, foreground, background }, FONT_SCALE(fontsize), 2);
                    buff.insert_row({ foreground, background, background, background, background }, FONT_SCALE(fontsize), 3);
                    buff.insert_row({ foreground, background, background, background, background }, FONT_SCALE(fontsize), 4);
                    buff.insert_row({ foreground, background, background, background, background }, FONT_SCALE(fontsize), 5);

                    return buff;
                }
            ),

            character('q',
                [](color foreground, color background, int fontsize) -> image {

                    image buff = image(FONT_WIDTH(fontsize), fontsize);

                    buff.insert_row({ background, foreground, foreground, foreground, background }, FONT_SCALE(fontsize), 0);
                    buff.insert_row({ foreground, background, background, background, foreground }, FONT_SCALE(fontsize), 1);
                    buff.insert_row({ foreground, background, background, background, foreground }, FONT_SCALE(fontsize), 2);
                    buff.insert_row({ foreground, background, foreground, background, foreground }, FONT_SCALE(fontsize), 3);
                    buff.insert_row({ foreground, background, background, foreground, background }, FONT_SCALE(fontsize), 4);
                    buff.insert_row({ background, foreground, foreground, background, foreground }, FONT_SCALE(fontsize), 5);

                    return buff;
                }
            ),

            character('r',
                [](color foreground, color background, int fontsize) -> image {

                    image buff = image(FONT_WIDTH(fontsize), fontsize);

                    buff.insert_row({ foreground, foreground, foreground, foreground, background }, FONT_SCALE(fontsize), 0);
                    buff.insert_row({ foreground, background, background, background, foreground }, FONT_SCALE(fontsize), 1);
                    buff.insert_row({ foreground, foreground, foreground, foreground, background }, FONT_SCALE(fontsize), 2);
                    buff.insert_row({ foreground, background, background, background, foreground }, FONT_SCALE(fontsize), 3);
                    buff.insert_row({ foreground, background, background, background, foreground }, FONT_SCALE(fontsize), 4);
                    buff.insert_row({ foreground, background, background, background, foreground }, FONT_SCALE(fontsize), 5);

                    return buff;
                }
            ),

            character('s',
                [](color foreground, color background, int fontsize) -> image {

                    image buff = image(FONT_WIDTH(fontsize), fontsize);

                    buff.insert_row({ background, foreground, foreground, foreground, foreground }, FONT_SCALE(fontsize), 0);
                    buff.insert_row({ foreground, background, background, background, background }, FONT_SCALE(fontsize), 1);
                    buff.insert_row({ background, foreground, foreground, foreground, background }, FONT_SCALE(fontsize), 2);
                    buff.insert_row({ background, background, background, background, foreground }, FONT_SCALE(fontsize), 3);
                    buff.insert_row({ background, background, background, background, foreground }, FONT_SCALE(fontsize), 4);
                    buff.insert_row({ foreground, foreground, foreground, foreground, background }, FONT_SCALE(fontsize), 5);

                    return buff;
                }
            ),

            character('t',
                [](color foreground, color background, int fontsize) -> image {

                    image buff = image(FONT_WIDTH(fontsize), fontsize);

                    buff.insert_row({ foreground, foreground, foreground, foreground, foreground }, FONT_SCALE(fontsize), 0);
                    buff.insert_row({ background, background, foreground, background, background }, FONT_SCALE(fontsize), 1);
                    buff.insert_row({ background, background, foreground, background, background }, FONT_SCALE(fontsize), 2);
                    buff.insert_row({ background, background, foreground, background, background }, FONT_SCALE(fontsize), 3);
                    buff.insert_row({ background, background, foreground, background, background }, FONT_SCALE(fontsize), 4);
                    buff.insert_row({ background, background, foreground, background, background }, FONT_SCALE(fontsize), 5);

                    return buff;
                }
            ),

            character('u',
                [](color foreground, color background, int fontsize) -> image {

                    image buff = image(FONT_WIDTH(fontsize), fontsize);

                    buff.insert_row({ foreground, background, background, background, foreground }, FONT_SCALE(fontsize), 0);
                    buff.insert_row({ foreground, background, background, background, foreground }, FONT_SCALE(fontsize), 1);
                    buff.insert_row({ foreground, background, background, background, foreground }, FONT_SCALE(fontsize), 2);
                    buff.insert_row({ foreground, background, background, background, foreground }, FONT_SCALE(fontsize), 3);
                    buff.insert_row({ foreground, background, background, background, foreground }, FONT_SCALE(fontsize), 4);
                    buff.insert_row({ background, foreground, foreground, foreground, background }, FONT_SCALE(fontsize), 5);

                    return buff;
                }
            ),

            character('v',
                [](color foreground, color background, int fontsize) -> image {

                    image buff = image(FONT_WIDTH(fontsize), fontsize);

                    buff.insert_row({ foreground, background, background, background, foreground }, FONT_SCALE(fontsize), 0);
                    buff.insert_row({ foreground, background, background, background, foreground }, FONT_SCALE(fontsize), 1);
                    buff.insert_row({ foreground, background, background, background, foreground }, FONT_SCALE(fontsize), 2);
                    buff.insert_row({ background, foreground, background, foreground, background }, FONT_SCALE(fontsize), 3);
                    buff.insert_row({ background, foreground, background, foreground, background }, FONT_SCALE(fontsize), 4);
                    buff.insert_row({ background, background, foreground, background, background }, FONT_SCALE(fontsize), 5);

                    return buff;
                }
            ),

            character('w',
                [](color foreground, color background, int fontsize) -> image {

                    image buff = image(FONT_WIDTH(fontsize), fontsize);

                    buff.insert_row({ foreground, background, background, background, foreground }, FONT_SCALE(fontsize), 0);
                    buff.insert_row({ foreground, background, background, background, foreground }, FONT_SCALE(fontsize), 1);
                    buff.insert_row({ foreground, background, foreground, background, foreground }, FONT_SCALE(fontsize), 2);
                    buff.insert_row({ foreground, background, foreground, background, foreground }, FONT_SCALE(fontsize), 3);
                    buff.insert_row({ foreground, background, foreground, background, foreground }, FONT_SCALE(fontsize), 4);
                    buff.insert_row({ background, foreground, background, foreground, background }, FONT_SCALE(fontsize), 5);

                    return buff;
                }
            ),

            character('x',
                [](color foreground, color background, int fontsize) -> image {

                    image buff = image(FONT_WIDTH(fontsize), fontsize);

                    buff.insert_row({ foreground, background, background, foreground, background }, FONT_SCALE(fontsize), 0);
                    buff.insert_row({ foreground, background, background, foreground, background }, FONT_SCALE(fontsize), 1);
                    buff.insert_row({ background, foreground, foreground, background, background }, FONT_SCALE(fontsize), 2);
                    buff.insert_row({ foreground, background, background, foreground, background }, FONT_SCALE(fontsize), 3);
                    buff.insert_row({ foreground, background, background, foreground, background }, FONT_SCALE(fontsize), 4);
                    buff.insert_row({ foreground, background, background, foreground, background }, FONT_SCALE(fontsize), 5);

                    return buff;
                }
            ),

            character('y',
                [](color foreground, color background, int fontsize) -> image {

                    image buff = image(FONT_WIDTH(fontsize), fontsize);

                    buff.insert_row({ foreground, background, background, background, foreground }, FONT_SCALE(fontsize), 0);
                    buff.insert_row({ foreground, background, background, background, foreground }, FONT_SCALE(fontsize), 1);
                    buff.insert_row({ background, foreground, background, foreground, background }, FONT_SCALE(fontsize), 2);
                    buff.insert_row({ background, background, foreground, background, background }, FONT_SCALE(fontsize), 3);
                    buff.insert_row({ background, background, foreground, background, background }, FONT_SCALE(fontsize), 4);
                    buff.insert_row({ background, background, foreground, background, background }, FONT_SCALE(fontsize), 5);

                    return buff;
                }
            ),

            character('z',
                [](color foreground, color background, int fontsize) -> image {

                    image buff = image(FONT_WIDTH(fontsize), fontsize);

                    buff.insert_row({ foreground, foreground, foreground, foreground, background }, FONT_SCALE(fontsize), 0);
                    buff.insert_row({ background, background, background, foreground, background }, FONT_SCALE(fontsize), 1);
                    buff.insert_row({ background, background, foreground, background, background }, FONT_SCALE(fontsize), 2);
                    buff.insert_row({ background, foreground, background, background, background }, FONT_SCALE(fontsize), 3);
                    buff.insert_row({ foreground, background, background, background, background }, FONT_SCALE(fontsize), 4);
                    buff.insert_row({ foreground, foreground, foreground, foreground, background }, FONT_SCALE(fontsize), 5);

                    return buff;
                }
            ),

            character('0',
                [](color foreground, color background, int fontsize) -> image {

                    image buff = image(FONT_WIDTH(fontsize), fontsize);

                    buff.insert_row({ background, foreground, foreground, background, background }, FONT_SCALE(fontsize), 0);
                    buff.insert_row({ foreground, background, background, foreground, background }, FONT_SCALE(fontsize), 1);
                    buff.insert_row({ foreground, background, background, foreground, background }, FONT_SCALE(fontsize), 2);
                    buff.insert_row({ foreground, background, background, foreground, background }, FONT_SCALE(fontsize), 3);
                    buff.insert_row({ foreground, background, background, foreground, background }, FONT_SCALE(fontsize), 4);
                    buff.insert_row({ background, foreground, foreground, background, background }, FONT_SCALE(fontsize), 5);

                    return buff;
                }
            ),

            character('1',
                [](color foreground, color background, int fontsize) -> image {

                    image buff = image(FONT_WIDTH(fontsize), fontsize);

                    buff.insert_row({ background, background, foreground, background, background }, FONT_SCALE(fontsize), 0);
                    buff.insert_row({ background, foreground, foreground, background, background }, FONT_SCALE(fontsize), 1);
                    buff.insert_row({ background, background, foreground, background, background }, FONT_SCALE(fontsize), 2);
                    buff.insert_row({ background, background, foreground, background, background }, FONT_SCALE(fontsize), 3);
                    buff.insert_row({ background, background, foreground, background, background }, FONT_SCALE(fontsize), 4);
                    buff.insert_row({ background, foreground, foreground, foreground, background }, FONT_SCALE(fontsize), 5);

                    return buff;
                }
            ),

            character('2',
                [](color foreground, color background, int fontsize) -> image {

                    image buff = image(FONT_WIDTH(fontsize), fontsize);

                    buff.insert_row({ background, foreground, foreground, background, background }, FONT_SCALE(fontsize), 0);
                    buff.insert_row({ foreground, background, background, foreground, background }, FONT_SCALE(fontsize), 1);
                    buff.insert_row({ background, background, foreground, background, background }, FONT_SCALE(fontsize), 2);
                    buff.insert_row({ background, foreground, background, background, background }, FONT_SCALE(fontsize), 3);
                    buff.insert_row({ foreground, background, background, background, background }, FONT_SCALE(fontsize), 4);
                    buff.insert_row({ foreground, foreground, foreground, foreground, background }, FONT_SCALE(fontsize), 5);

                    return buff;
                }
            ),

            character('3',
                [](color foreground, color background, int fontsize) -> image {

                    image buff = image(FONT_WIDTH(fontsize), fontsize);

                    buff.insert_row({ foreground, foreground, foreground, background, background }, FONT_SCALE(fontsize), 0);
                    buff.insert_row({ background, background, background, foreground, background }, FONT_SCALE(fontsize), 1);
                    buff.insert_row({ background, foreground, foreground, background, background }, FONT_SCALE(fontsize), 2);
                    buff.insert_row({ background, background, background, foreground, background }, FONT_SCALE(fontsize), 3);
                    buff.insert_row({ background, background, background, foreground, background }, FONT_SCALE(fontsize), 4);
                    buff.insert_row({ foreground, foreground, foreground, background, background }, FONT_SCALE(fontsize), 5);

                    return buff;
                }
            ),

            character('4',
                [](color foreground, color background, int fontsize) -> image {

                    image buff = image(FONT_WIDTH(fontsize), fontsize);

                    buff.insert_row({ foreground, background, background, foreground, background }, FONT_SCALE(fontsize), 0);
                    buff.insert_row({ foreground, background, background, foreground, background }, FONT_SCALE(fontsize), 1);
                    buff.insert_row({ foreground, background, background, foreground, background }, FONT_SCALE(fontsize), 2);
                    buff.insert_row({ foreground, foreground, foreground, foreground, background }, FONT_SCALE(fontsize), 3);
                    buff.insert_row({ background, background, background, foreground, background }, FONT_SCALE(fontsize), 4);
                    buff.insert_row({ background, background, background, foreground, background }, FONT_SCALE(fontsize), 5);

                    return buff;
                }
            ),

            character('5',
                [](color foreground, color background, int fontsize) -> image {

                    image buff = image(FONT_WIDTH(fontsize), fontsize);

                    buff.insert_row({ foreground, foreground, foreground, foreground, background }, FONT_SCALE(fontsize), 0);
                    buff.insert_row({ foreground, background, background, background, background }, FONT_SCALE(fontsize), 1);
                    buff.insert_row({ foreground, foreground, foreground, background, background }, FONT_SCALE(fontsize), 2);
                    buff.insert_row({ background, background, background, foreground, background }, FONT_SCALE(fontsize), 3);
                    buff.insert_row({ background, background, background, foreground, background }, FONT_SCALE(fontsize), 4);
                    buff.insert_row({ foreground, foreground, foreground, background, background }, FONT_SCALE(fontsize), 5);

                    return buff;
                }
            ),

            character('6',
                [](color foreground, color background, int fontsize) -> image {

                    image buff = image(FONT_WIDTH(fontsize), fontsize);

                    buff.insert_row({ background, foreground, foreground, foreground, background }, FONT_SCALE(fontsize), 0);
                    buff.insert_row({ foreground, background, background, background, background }, FONT_SCALE(fontsize), 1);
                    buff.insert_row({ foreground, foreground, foreground, background, background }, FONT_SCALE(fontsize), 2);
                    buff.insert_row({ foreground, background, background, foreground, background }, FONT_SCALE(fontsize), 3);
                    buff.insert_row({ foreground, background, background, foreground, background }, FONT_SCALE(fontsize), 4);
                    buff.insert_row({ background, foreground, foreground, background, background }, FONT_SCALE(fontsize), 5);

                    return buff;
                }
            ),

            character('7',
                [](color foreground, color background, int fontsize) -> image {

                    image buff = image(FONT_WIDTH(fontsize), fontsize);

                    buff.insert_row({ foreground, foreground, foreground, foreground, background }, FONT_SCALE(fontsize), 0);
                    buff.insert_row({ background, background, background, foreground, background }, FONT_SCALE(fontsize), 1);
                    buff.insert_row({ background, background, background, foreground, background }, FONT_SCALE(fontsize), 2);
                    buff.insert_row({ background, background, background, foreground, background }, FONT_SCALE(fontsize), 3);
                    buff.insert_row({ background, background, background, foreground, background }, FONT_SCALE(fontsize), 4);
                    buff.insert_row({ background, background, background, foreground, background }, FONT_SCALE(fontsize), 5);

                    return buff;
                }
            ),

            character('8',
                [](color foreground, color background, int fontsize) -> image {

                    image buff = image(FONT_WIDTH(fontsize), fontsize);

                    buff.insert_row({ background, foreground, foreground, background, background }, FONT_SCALE(fontsize), 0);
                    buff.insert_row({ foreground, background, background, foreground, background }, FONT_SCALE(fontsize), 1);
                    buff.insert_row({ background, foreground, foreground, background, background }, FONT_SCALE(fontsize), 2);
                    buff.insert_row({ foreground, background, background, foreground, background }, FONT_SCALE(fontsize), 3);
                    buff.insert_row({ foreground, background, background, foreground, background }, FONT_SCALE(fontsize), 4);
                    buff.insert_row({ background, foreground, foreground, background, background }, FONT_SCALE(fontsize), 5);

                    return buff;
                }
            ),

            character('9',
                [](color foreground, color background, int fontsize) -> image {

                    image buff = image(FONT_WIDTH(fontsize), fontsize);

                    buff.insert_row({ foreground, foreground, foreground, foreground, background }, FONT_SCALE(fontsize), 0);
                    buff.insert_row({ foreground, background, background, foreground, background }, FONT_SCALE(fontsize), 1);
                    buff.insert_row({ foreground, foreground, foreground, foreground, background }, FONT_SCALE(fontsize), 2);
                    buff.insert_row({ background, background, background, foreground, background }, FONT_SCALE(fontsize), 3);
                    buff.insert_row({ background, background, background, foreground, background }, FONT_SCALE(fontsize), 4);
                    buff.insert_row({ background, background, background, foreground, background }, FONT_SCALE(fontsize), 5);

                    return buff;
                }
            ),

            character('!',
                [](color foreground, color background, int fontsize) -> image {

                    image buff = image(FONT_WIDTH(fontsize), fontsize);

                    buff.insert_row({ background, background, foreground, background, background }, FONT_SCALE(fontsize), 0);
                    buff.insert_row({ background, background, foreground, background, background }, FONT_SCALE(fontsize), 1);
                    buff.insert_row({ background, background, foreground, background, background }, FONT_SCALE(fontsize), 2);
                    buff.insert_row({ background, background, foreground, background, background }, FONT_SCALE(fontsize), 3);
                    buff.insert_row({ background, background, background, background, background }, FONT_SCALE(fontsize), 4);
                    buff.insert_row({ background, background, foreground, background, background }, FONT_SCALE(fontsize), 5);

                    return buff;
                }
            ),

            character('?',
                [](color foreground, color background, int fontsize) -> image {

                    image buff = image(FONT_WIDTH(fontsize), fontsize);

                    buff.insert_row({ background, foreground, foreground, foreground, background }, FONT_SCALE(fontsize), 0);
                    buff.insert_row({ foreground, background, background, background, foreground }, FONT_SCALE(fontsize), 1);
                    buff.insert_row({ background, background, background, background, foreground }, FONT_SCALE(fontsize), 2);
                    buff.insert_row({ background, background, foreground, foreground, background }, FONT_SCALE(fontsize), 3);
                    buff.insert_row({ background, background, background, background, background }, FONT_SCALE(fontsize), 4);
                    buff.insert_row({ background, background, foreground, background, background }, FONT_SCALE(fontsize), 5);

                    return buff;
                }
            )
		};
	}
};