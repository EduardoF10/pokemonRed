#include "TextSprites.h"

TextSprites::TextSprites() {
    this->allChars.resize(MAX_CHAR_INDEX + 1);
    this->setSprites();
}

ofImage TextSprites::getCharImage(ofImage charsImage, char textChar) {

    ofImage charImage;
    charImage.allocate(CHARS_WIDTH, CHARS_HEIGHT, OF_IMAGE_COLOR_ALPHA);

    int xIndex;
    int yIndex;
    int charIndex;
    if (isalnum(textChar)) {
        if (isdigit(textChar)) {
            charIndex = textChar - '0';
            yIndex = FIND_START_NUMS_Y;
        }
        else if (isupper(textChar)) {
            charIndex = textChar - 'A';
            yIndex = FIND_START_CAPS_Y; 
        }
        else if (islower(textChar)) {
            charIndex = textChar - 'a';
            yIndex = FIND_START_LETTERS_Y;
        }
        xIndex = FIND_START_ALPHA_NUM_X + (charIndex * ALPHA_NUM_SPACE_X);
    }
    else {

        yIndex = FIND_START_NUMS_Y;

        if (textChar == '!') {
            xIndex = FIND_START_EXCLAM;
        }
        else if (textChar == '?') {
            xIndex = FIND_START_QUES;
        }
        else if (textChar == '.') {
            xIndex = FIND_START_POINT;
        }
        else if (textChar == '-') {
            xIndex = FIND_START_DASH;
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
        else if (textChar == ' ') {
            xIndex = FIND_WHITESPACE_X;
            yIndex = FIND_WHITESPACE_Y;
        }
        else if (textChar == '*') {
            charImage.cropFrom(charsImage, FIND_START_NEXT_X, FIND_START_NEXT_Y, NEXT_WIDTH, NEXT_HEIGHT);
            return charImage;
        }
        else {
            xIndex = FIND_START_QUES;
        }
    }

    charImage.cropFrom(charsImage, xIndex, yIndex, CHARS_WIDTH, CHARS_HEIGHT);
    return charImage;

}

ofImage TextSprites::getTextBoxImage(int boxOption) {

    // Load all textBoxes
    ofImage allBoxes;
    allBoxes.load("sprites/textBoxes.png");

    // Works for first 7 boxes
    int startX = FIND_BOX_X;
    int startY = FIND_BOX_Y + (boxOption * BOX_HEIGHT);

    allBoxes.crop(startX, startY, BOX_WIDTH, BOX_HEIGHT);
    return allBoxes;

}

void TextSprites::setSprites() {

    // Load image containing all chars
    ofImage charsImage;
    charsImage.load("sprites/textB1.png");

    for (char number : ALL_NUMS) {
        this->allChars[number] = this->getCharImage(charsImage, number);
    }
    for (char upperChar : ALL_UPPER) {
        this->allChars[upperChar] = this->getCharImage(charsImage, upperChar);
    }
    for (char lowerChar : ALL_LOWER) {
        this->allChars[lowerChar] = this->getCharImage(charsImage, lowerChar);
    }
    for (char otherChar : OTHER_CHARS) {
        this->allChars[otherChar] = this->getCharImage(charsImage, otherChar);
    }
}

ofImage TextSprites::getQuickCharImage(int charVal) {

    ofImage charImage;
    charImage.allocate(CHARS_WIDTH, CHARS_HEIGHT, OF_IMAGE_COLOR_ALPHA);
    charImage = this->allChars[charVal];
    return charImage;

}