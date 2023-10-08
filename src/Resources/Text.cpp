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
    int charIndex;
    if (isalnum(textChar)) {
        if (isdigit(textChar)) {
            charIndex = textChar - '0' - '0';
            yIndex = START_NUMS_Y;
        }
        else if (isupper(textChar)) {
            charIndex = textChar - 'A' - 'A';
            yIndex = START_CAPS_Y; 
        }
        else if (islower(textChar)) {
            charIndex = textChar - 'a' - 'a';
            yIndex = START_LETTERS_Y;
        }
        xIndex = START_ALPHA_NUM_X + (charIndex * ALPHA_NUM_SPACE_X);
    }
    else {
        if (textChar == '!') {
            xIndex = START_EXCLAM;
        }
        else if (textChar == '?') {
            xIndex = START_QUES;
        }
        else if (textChar == '.') {
            xIndex = START_POINT;
        }
        else if (textChar == '>') {
            xIndex = START_THREE_DOTS;
        }
        else if (textChar == '{') {
            xIndex = START_LEFT_QUOTES;
        }
        else if (textChar == '}') {
            xIndex = START_RIGHT_QUOTES;
        }
        else if (textChar == '[') {
            xIndex = START_LEFT_SINGQUO;
        }
        else if (textChar == ']') {
            xIndex = START_RIGHT_SINGQUO;
        }
        else if (textChar == '=') {
            xIndex = START_MALE;
        }
        else if (textChar == '+') {
            xIndex = START_FEMALE;
        }
        else if (textChar == ',') {
            xIndex = START_COMMA;
        }
        else if (textChar == '/') {
            xIndex = START_SLASH;
        }
        else {
            xIndex = START_QUES;
        }
        yIndex = START_NUMS_Y;
    }

    allChars.crop(xIndex, yIndex, CHARS_WIDTH, CHARS_HEIGHT);
    return allChars;

}

ofImage Text::getTextBoxImage() {

    // Load all textBoxes
    ofImage allBoxes;

    return allBoxes;
}