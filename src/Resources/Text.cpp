#include "Text.h"

Text::Text(int speed, int boxOption, std::string text) {
    this->speed = speed;
    this->boxOption = boxOption;
    this->text = text;
    this->timer = 0;
    this->charIndex = 0;
    this->textBox = this->getTextBoxImage();
}

ofImage Text::getCharImage(char textChar) {

    // Loading image of all text characters
    ofImage allChars;
    allChars.load("sprites/text.png");

    int xIndex;
    int yIndex;
    int charIndex;
    if (isalnum(textChar)) {
        if (isdigit(textChar)) {
            charIndex = textChar - '0' - '0';
            yIndex = FIND_START_NUMS_Y;
        }
        else if (isupper(textChar)) {
            charIndex = textChar - 'A' - 'A';
            yIndex = FIND_START_CAPS_Y; 
        }
        else if (islower(textChar)) {
            charIndex = textChar - 'a' - 'a';
            yIndex = FIND_START_LETTERS_Y;
        }
        xIndex = FIND_START_ALPHA_NUM_X + (charIndex * ALPHA_NUM_SPACE_X);
    }
    else {
        if (textChar == '!') {
            xIndex = FIND_START_EXCLAM;
        }
        else if (textChar == '?') {
            xIndex = FIND_START_QUES;
        }
        else if (textChar == '.') {
            xIndex = FIND_START_POINT;
        }
        else if (textChar == '>') {
            xIndex = FIND_START_THREE_DOTS;
        }
        else if (textChar == '{') {
            xIndex = FIND_START_LEFT_QUOTES;
        }
        else if (textChar == '}') {
            xIndex = FIND_START_RIGHT_QUOTES;
        }
        else if (textChar == '[') {
            xIndex = FIND_START_LEFT_SINGQUO;
        }
        else if (textChar == ']') {
            xIndex = FIND_START_RIGHT_SINGQUO;
        }
        else if (textChar == '=') {
            xIndex = FIND_START_MALE;
        }
        else if (textChar == '+') {
            xIndex = FIND_START_FEMALE;
        }
        else if (textChar == ',') {
            xIndex = FIND_START_COMMA;
        }
        else if (textChar == '/') {
            xIndex = FIND_START_SLASH;
        }
        else {
            xIndex = FIND_START_QUES;
        }
        yIndex = FIND_START_NUMS_Y;
    }

    allChars.crop(xIndex, yIndex, CHARS_WIDTH, CHARS_HEIGHT);
    return allChars;

}

ofImage Text::getTextBoxImage() {

    // Load all textBoxes
    ofImage allBoxes;
    allBoxes.load("sprites/textBoxes.png");

    // Works for first 7 boxes
    int startX = FIND_BOX_X;
    int startY = FIND_BOX_Y + (this->boxOption * 42);

    allBoxes.crop(startX, startY, BOX_WIDTH, BOX_HEIGHT);
    return allBoxes;

}

void Text::scaleDims(double xMult, double yMult) {
    this->xMult = xMult;
    this->yMult = yMult;
}

void Text::render() {

    this->textBox.draw(BOX_START_X * this->xMult, BOX_START_Y * this->yMult, BOX_WIDTH * this->xMult, BOX_HEIGHT * this->yMult);

    // // If enough time passed to print letter
    // if (timer == speed) {

    // }


}