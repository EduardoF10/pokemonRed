#include "Text.h"

Text::Text(int speed, int textBox, std::string text) {
    this->speed = speed;
    this->textBox = textBox;
    this->text = text;
    this->timer = 0;
    this->charIndex = 0;
}

ofImage Text::getCharImage(char textChar) {

    // Loading image of all text characters
    ofImage allChars;
    allChars.load("sprites/text.png");

    int xIndex;
    int yIndex;
    if (isdigit(textChar)) {
        int numVal = textChar - '0';
        xIndex = START_ALPHA_NUM_X + (numVal * 7);
        yIndex = START_NUMS_Y;
        allChars.crop(xIndex, yIndex, ALPHA_NUM_WIDTH, ALPHA_NUM_HEIGHT);
    }
    else if (isupper(textChar)) {
        
    }

}