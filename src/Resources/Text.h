#include "ofMain.h"
#include "TextSprites.h"
#include <cmath>
#include <string>

class Text {

    const int BOX_WIDTH = 226;
    const int BOX_HEIGHT = 42;
    const int CHARS_WIDTH = 6;
    const int CHARS_HEIGHT = 14;
    const int CHAR_SPACE_X = 7;
    const int CHAR_SPACE_Y = 15;

    const int BOX_START_X = 7;
    const int BOX_START_Y = 116;
    const int BOX_START_TEXT_POS_X = 9;
    const int BOX_START_TEXT_POS_Y = 7;


private:

    double xMult;  // Pixel scaling on x-axis
    double yMult;  // Pixel scaling on y-axis
    double screenStartX;   
    double screenStartY;

    int charWidth;  // Pixel width for each char
    int charHeight; // Pixel height for each char

    int speed;  // The speed of reading text

    int timer;  // Timer for animation

    int boxOption;    // Text box choice number

    std::string text;   // Text that will be displayed

    ofImage textBox;

    int charIndex;  // Current char position

    TextSprites* textSprites;


public:

    Text(int speed, int textBox, std::string text);

    void scaleDims(double startX, double startY, double xMult, double yMult);

    void setSpeed(int speed);

    void setTextBox(int boxOption);

    void setText(std::string text);

    void render();

    void tick();

    void quickDisplay();

    // void save();    // Too slow

    void reset();

};