#include "ofMain.h"
#include <cmath>
#include <string>
#include <vector>

const std::string ALL_NUMS = "0123456789";
const std::string ALL_UPPER = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const std::string ALL_LOWER = "abcdefghijklmnopqrstuvwxyz";
const std::string OTHER_CHARS = "!?.->{}[]=+,/ *";
const int MAX_CHAR_INDEX = 125;
const int CHARS_WIDTH = 6;
const int CHARS_HEIGHT = 14;
const int ALPHA_NUM_SPACE_X = 7;

const int FIND_START_ALPHA_NUM_X = 0;
const int FIND_START_NUMS_Y = 0;
const int FIND_START_CAPS_Y = 15;
const int FIND_START_LETTERS_Y = 30;
const int FIND_START_EXCLAM = 70;
const int FIND_START_QUES = 77;
const int FIND_START_POINT = 84;
const int FIND_START_DASH = 90;
const int FIND_START_THREE_DOTS = 103;
const int FIND_START_LEFT_QUOTES = 110;
const int FIND_START_RIGHT_QUOTES = 119;
const int FIND_START_LEFT_SINGQUO = 128;
const int FIND_START_RIGHT_SINGQUO = 137;
const int FIND_START_MALE = 146;
const int FIND_START_FEMALE = 155;
const int FIND_START_COMMA = 174;
const int FIND_START_SLASH = 189;

const int FIND_WHITESPACE_X = 187;
const int FIND_WHITESPACE_Y = 15;

const int NEXT_CHAR = '*';
const int FIND_START_NEXT_X = 183;
const int FIND_START_NEXT_Y = 35;
const int NEXT_WIDTH = 8;
const int NEXT_HEIGHT = 7;

const int FIND_BOX_X = 0;
const int FIND_BOX_Y = 0;
const int BOX_WIDTH = 226;
const int BOX_HEIGHT = 42;


class TextSprites {

private:

    std::vector<ofImage> allChars;

    ofImage getCharImage(ofImage charsImage, char textChar);    // Returns image of textChar

    void setSprites();


public:

    TextSprites();

    ofImage getTextBoxImage(int boxOption);

    ofImage getQuickCharImage(int charVal);

};