#include "Text.h"

Text::Text(int speed, int boxOption, std::string text) {
    this->speed = speed;
    this->boxOption = boxOption;
    this->text = text;
    this->timer = 0;
    this->charIndex = 0;
    this->textSprites = new TextSprites();
    this->textBox = textSprites->getTextBoxImage(boxOption);
}

void Text::scaleDims(double startX, double startY, double xMult, double yMult) {
    this->screenStartX = startX;
    this->screenStartY = startY;
    this->xMult = xMult;
    this->yMult = yMult;
}

// // Too slow
// void Text::save() {
//     ofImage newTextBox;
//     newTextBox.grabScreen(BOX_START_X * this->xMult, BOX_START_Y * this->yMult, BOX_WIDTH * this->xMult, BOX_HEIGHT * this->yMult);
//     this->textBox = newTextBox;
// }

void Text::tick() {

    // If enough time passed to jump to next letter
    if (timer == speed) {

    }
}

void Text::render() {

    this->textBox.draw(this->screenStartX + (BOX_START_X * this->xMult), this->screenStartY + (BOX_START_Y * this->yMult), BOX_WIDTH * this->xMult, BOX_HEIGHT * this->yMult);
    
}