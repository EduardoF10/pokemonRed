#include "ofMain.h"
#include <string>

class Text {

    const int START_ALPHA_NUM_X = 0;
    const int START_NUMS_Y = 0;
    const int START_CAPS_Y = 15;
    const int START_LETTERS_Y = 30;
    const int START_EXCLAM = 70;
    const int START_QUES = 77;
    const int START_POINT = 84;
    const int START_DASH = 90;
    const int START_THREE_DOTS = 103;
    const int START_LEFT_QUOTES = 110;
    const int START_RIGHT_QUOTES = 119;
    const int START_LEFT_SINGQUO = 128;
    const int START_RIGHT_SINGQUO = 137;
    const int START_MALE = 146;
    const int START_FEMALE = 155;
    const int START_COMMA = 174;
    const int START_SLASH = 189;
    const int CHARS_WIDTH = 6;
    const int CHARS_HEIGHT = 14;
    const int ALPHA_NUM_SPACE_X = 7;
    const int ASCII_0 = 48;
    const int ASCII_UA = 65;
    const int ASCII_LA = 97;


private:

    int speed;  // The speed of reading text

    int timer;  // Timer for animation

    int textBox;    // Text box choice number

    std::string text;   // Text that will be displayed

    int charIndex;  // Current char position

    ofImage getCharImage(char textChar);    // Returns image of textChar

    ofImage getTextBoxImage();



public:

    Text(int speed, int textBox, std::string text);

    void setSpeed(int speed);

    void setTextBox(int boxOption);

    void setText(std::string text);

    void render();

    void tick();

    void quickDisplay();

    void reset();

};