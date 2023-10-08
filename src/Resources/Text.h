#include "ofMain.h"
#include <cmath>
#include <string>

class Text {

    const int FIND_BOX_X = 0;
    const int FIND_BOX_Y = 0;
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

    const int BOX_WIDTH = 226;
    const int BOX_HEIGHT = 42;
    const int CHARS_WIDTH = 6;
    const int CHARS_HEIGHT = 14;
    const int ALPHA_NUM_SPACE_X = 7;

    const int BOX_START_X = 7;
    const int BOX_START_Y = 116;
    const int BOX_START_TEXT_POS_X = 9;
    const int BOX_START_TEXT_POS_Y = 7;


private:

    double xMult;  // Pixel scaling on x-axis
    double yMult;  // Pixel scaling on y-axis

    int charWidth;  // Pixel width for each char
    int charHeight; // Pixel height for each char

    int speed;  // The speed of reading text

    int timer;  // Timer for animation

    int boxOption;    // Text box choice number

    std::string text;   // Text that will be displayed

    ofImage textBox;

    int charIndex;  // Current char position

    ofImage getCharImage(char textChar);    // Returns image of textChar

    ofImage getTextBoxImage();



public:

    Text(int speed, int textBox, std::string text);

    void scaleDims(double xMult, double yMult);

    void setSpeed(int speed);

    void setTextBox(int boxOption);

    void setText(std::string text);

    void render();

    void tick();

    void quickDisplay();

    void reset();

};