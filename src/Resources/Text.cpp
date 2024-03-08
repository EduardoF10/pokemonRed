#include "Text.h"

Text::Text(int speed, int boxOption, std::string text) {
    this->scale = 7;
    this->sentenceIndex = 0;
    this->lineIndex = 0;
    this->charIndex = 0;
    this->speed = speed;
    this->finishPrint = false;
    this->goNextLine = false;
    this->showTextBox = true;
    this->boxOption = boxOption;
    this->text = text;
    this->timer = 0;
    this->charIndex = 0;
    this->textSprites = new TextSprites();
    this->textBox = textSprites->getTextBoxImage(boxOption);
    this->prepareText();
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

    // If chars are left to print
    if (!this->finishPrint) {

        // If enough time passed to jump to next char
        if (this->timer == this->speed) {

            // Reset timer
            this->timer = 0;

            // If going to next line
            if (this->charIndex + 1 > this->readyText.at(this->sentenceIndex).at(this->lineIndex).size() - 1) {

                // If going to next sentence
                if (this->lineIndex + 1 > this->readyText.at(this->sentenceIndex).size() - 1) {

                    // If no more sentences
                    if (this->sentenceIndex + 1 > this->readyText.size() - 1) {
                        this->finishPrint = true;
                    }
                    else {
                        if (this->goNextLine) {
                            this->sentenceIndex += 1;
                            this->charIndex = 0;
                            this->lineIndex = 0;
                            this->goNextLine = false;
                        }
                        else {
                            this->timer = this->speed;
                        }
                    }

                }
                else {
                    if (this->lineIndex > 0) {
                        if (this->goNextLine) {
                            this->lineIndex += 1;
                            this->charIndex = 0;
                            this->goNextLine = false;
                        }
                        else {
                            this->timer = this->speed;
                        }
                    }
                    else {
                        this->lineIndex += 1;
                        this->charIndex = 0;
                    }
                }

            }
            else {
                this->charIndex += 1;
            }

        }
        else {
            this->timer += 1;
        }

    }
    else {
        if (this->goNextLine) {
            this->showTextBox = false;
            this->goNextLine = false;
        }
    }

    this->goNextLine = false;
}

void Text::toggleNextLine() {
    this->goNextLine = true;
}

void Text::toggleShow(bool show) {
    this->showTextBox = show;
}

void Text::render() {

    if (this->showTextBox) {
        this->textBox.draw(this->screenStartX + (BOX_START_X * this->xMult), this->screenStartY + (BOX_START_Y * this->yMult), BOX_WIDTH * this->xMult, BOX_HEIGHT * this->yMult);
        this->printAllChars();
    }
    
}

void Text::printChar(char charVal, float xPos, float yPos, float width, float height) {

    // If whitespace simply do nothing
    if (charVal == ' ') {
        return;
    }

    ofImage charImage;
    charImage.allocate(CHARS_WIDTH, CHARS_HEIGHT, OF_IMAGE_COLOR_ALPHA);
    charImage = this->textSprites->getQuickCharImage(charVal);
    charImage.draw(xPos, yPos, width, height);
}

void Text::printAllChars() {

    int startX = this->screenStartX + ((BOX_START_X + BOX_START_TEXT_POS_X) * this->xMult);
    int xPos = startX;
    int yPos = this->screenStartY + ((BOX_START_Y + BOX_START_TEXT_POS_Y) * this->yMult);
    char curChar;
    // char prev = ' ';
    int charSpace;

    // If 2 liner
    if (this->lineIndex > 0) {

        // First line print
        int firstLineSize = this->readyText.at(this->sentenceIndex).at(this->lineIndex - 1).size();
        for (int i = 0; i < firstLineSize; i++) {
            curChar = this->readyText.at(this->sentenceIndex).at(this->lineIndex - 1).at(i);
            this->printChar(curChar, xPos, yPos, CHARS_WIDTH * this->xMult, CHARS_HEIGHT * this->yMult);
            charSpace = getCharSpace(curChar);
            xPos += charSpace * this->xMult;
        }

        // Second line print
        // prev = ' ';
        xPos = startX;
        yPos = this->screenStartY + ((BOX_START_Y + BOX_NEXT_LINE_Y) * this->yMult);
        int charCounter = 0;
        for (int i = 0; i < this->charIndex + 1; i++) {
            curChar = this->readyText.at(this->sentenceIndex).at(this->lineIndex).at(i);
            this->printChar(curChar, xPos, yPos, CHARS_WIDTH * this->xMult, CHARS_HEIGHT * this->yMult);
            charSpace = getCharSpace(curChar);
            xPos += charSpace * this->xMult;
            charCounter += 1;
        }
        // If end of line
        if (charCounter == this->readyText.at(this->sentenceIndex).at(this->lineIndex).size()) {
            
            this->printChar(NEXT_CHAR, xPos, yPos, NEXT_WIDTH * this->xMult, NEXT_HEIGHT * this->yMult);
            // //  If last line
            // if (this->lineIndex == this->readyText.at(this->sentenceIndex).size() - 1) {
            //     this->printChar(NEXT_CHAR, xPos, yPos, NEXT_WIDTH * this->xMult, NEXT_HEIGHT * this->yMult);
            // }
        }

    }
    else {
        int charCounter = 0;
        for (int i = 0; i < this->charIndex + 1; i++) {
            curChar = this->readyText.at(this->sentenceIndex).at(this->lineIndex).at(i);
            this->printChar(curChar, xPos, yPos, CHARS_WIDTH * this->xMult, CHARS_HEIGHT * this->yMult);
            charCounter += 1;
            charSpace = getCharSpace(curChar);
            xPos += charSpace * this->xMult;
        }
        // If end of line
        if (charCounter == this->readyText.at(this->sentenceIndex).at(this->lineIndex).size()) {
            // If end of sentence
            if (this->lineIndex == this->readyText.at(this->sentenceIndex).size() - 1) {
                this->printChar(NEXT_CHAR, xPos, yPos, NEXT_WIDTH * this->xMult, NEXT_HEIGHT * this->yMult);
            }
        }
    }

}


void Text::prepareText() {

    std::vector<std::string> lineWords;
    int curLineSize = 0;
    std::string curWord = "";
    std::string newLine = "";

    for (char charVal : this->text) {

        curWord += charVal;
        curLineSize += 1;

        if (curLineSize > LINE_CHAR_LIMIT) {
            lineWords.push_back(newLine);
            newLine = "";
            curLineSize = curWord.size();
        }

        if (charVal == ' ') {
            newLine += curWord;
            curWord = "";
        }
        else if (charVal == '.' or charVal == '!' or charVal == '?' or charVal == '>') {    // Sentence terminators
            newLine += curWord;
            lineWords.push_back(newLine);
            this->readyText.push_back(lineWords);
            curWord = "";
            newLine = "";
            lineWords.clear();
            curLineSize = 0;
        }
        
    }

}

int Text::getCharSpace(char prev) {

    int result = CHAR_SPACE_X;

    if (prev == 'i') {
        result -= 4;
    }
    else if (prev == 'l') {
        result -= 3;
    }
    else if (prev == 'f' || prev == 'k' || prev == 'n' || prev == 'r' || prev == 's' || prev == 't' || prev == 'u') {
        result -= 1;
    }

    return result;

}


// void Text::horizontalStick(double startX, double startY, double xDist, double yDist, double width) {
//     ofDrawRectangle(startX + (xDist * this->scale), startY + (yDist * this->scale), width * this->scale, this->scale);
// }

// void Text::verticalStick(double startX, double startY, double xDist, double yDist, double length) {
//     ofDrawRectangle(startX + (xDist * this->scale), startY + (yDist * this->scale), this->scale, length * this->scale);
// }

void Text::rectangle(double startX, double startY, double xDist, double yDist, double width, double height) {
    ofDrawRectangle(startX + (xDist * this->xMult), startY + (yDist * this->yMult), this->xMult * width, this->yMult * height);
}

void Text::doubleRect(double startX, double startY, double xDist, double yDist, double width, double height) {
    // Shadow
    ofSetColor(208, 208, 200);
    rectangle(startX, startY, xDist + width, yDist, 1, height + 1);
    rectangle(startX, startY, xDist, yDist + height, width, 1);
    // Normal
    ofSetColor(77, 77, 77);
    rectangle(startX, startY, xDist, yDist, width, height);
}

void Text::setTextColor2() {
    ofSetColor(208, 208, 200);
}

void Text::setTextColor1() {
    ofSetColor(77, 77, 77);
}



// UPPER LETTERS

double Text::upperA(double startX, double startY) {
    doubleRect(startX, startY, 0, 4, 1, 7);
    doubleRect(startX, startY, 1, 3, 3, 1);
    doubleRect(startX, startY, 1, 7, 3, 1);
    doubleRect(startX, startY, 4, 4, 1, 7);
    return 6 * this->scale;
}

double Text::upperB(double startX, double startY) {
    doubleRect(startX, startY, 0, 3, 1, 8);
    doubleRect(startX, startY, 1, 3, 3, 1);
    doubleRect(startX, startY, 1, 6, 3, 1);
    doubleRect(startX, startY, 1, 10, 3, 1);
    doubleRect(startX, startY, 4, 4, 1, 2);
    doubleRect(startX, startY, 4, 7, 1, 3);
    ofSetColor(255, 255, 255);
    rectangle(startX, startY, 5, 6, 1, 1);
    return 6 * this->scale;
}

double Text::upperC(double startX, double startY) {
    doubleRect(startX, startY, 0, 4, 1, 6);
    doubleRect(startX, startY, 1, 3, 3, 1);
    doubleRect(startX, startY, 1, 10, 3, 1);
    doubleRect(startX, startY, 4, 4, 1, 1);
    doubleRect(startX, startY, 4, 9, 1, 1);
    return 6 * this->scale;
}

double Text::upperD(double startX, double startY) {
    doubleRect(startX, startY, 0, 3, 1, 8);
    doubleRect(startX, startY, 1, 3, 3, 1);
    doubleRect(startX, startY, 1, 10, 3, 1);
    doubleRect(startX, startY, 4, 4, 1, 6);
    return 6 * this->scale;
}

double Text::upperE(double startX, double startY) {
    doubleRect(startX, startY, 0, 3, 1, 8);
    doubleRect(startX, startY, 1, 3, 4, 1);
    doubleRect(startX, startY, 1, 6, 3, 1);
    doubleRect(startX, startY, 1, 10, 4, 1);
    return 6 * this->scale;
}

double Text::upperF(double startX, double startY) {
    doubleRect(startX, startY, 0, 3, 1, 8);
    doubleRect(startX, startY, 1, 3, 4, 1);
    doubleRect(startX, startY, 1, 6, 3, 1);
    return 6 * this->scale;
}

double Text::upperG(double startX, double startY) {
    doubleRect(startX, startY, 0, 4, 1, 6);
    doubleRect(startX, startY, 1, 3, 3, 1);
    doubleRect(startX, startY, 1, 10, 3, 1);
    doubleRect(startX, startY, 3, 7, 1, 1);
    doubleRect(startX, startY, 4, 4, 1, 6);
    ofSetColor(255, 255, 255);
    rectangle(startX, startY, 4, 6, 2, 1);
    return 6 * this->scale;
}

double Text::upperH(double startX, double startY) {
    doubleRect(startX, startY, 0, 3, 1, 8);
    doubleRect(startX, startY, 1, 6, 3, 1);
    doubleRect(startX, startY, 4, 3, 1, 8);
    return 6 * this->scale;
}

double Text::upperI(double startX, double startY) {
    doubleRect(startX, startY, 0, 3, 5, 1);
    doubleRect(startX, startY, 2, 4, 1, 6);
    doubleRect(startX, startY, 0, 10, 5, 1);
    return 6 * this->scale;
}

double Text::upperJ(double startX, double startY) {
    doubleRect(startX, startY, 0, 9, 1, 1);
    doubleRect(startX, startY, 1, 10, 3, 1);
    doubleRect(startX, startY, 4, 3, 1, 7);
    return 6 * this->scale;
}

double Text::upperK(double startX, double startY) {
    doubleRect(startX, startY, 0, 3, 1, 8);
    doubleRect(startX, startY, 1, 6, 1, 2);
    doubleRect(startX, startY, 4, 10, 1, 1);
    rectangle(startX, startY, 2, 5, 1, 1);
    rectangle(startX, startY, 2, 8, 1, 1);
    rectangle(startX, startY, 3, 4, 1, 1);
    rectangle(startX, startY, 3, 9, 1, 1);
    rectangle(startX, startY, 4, 3, 1, 1);
    setTextColor2();
    rectangle(startX, startY, 3, 5, 1, 1);
    rectangle(startX, startY, 3, 8, 1, 1);
    rectangle(startX, startY, 4, 4, 1, 1);
    rectangle(startX, startY, 4, 9, 1, 1);
    rectangle(startX, startY, 5, 3, 1, 1);
    return 6 * this->scale;
}

double Text::upperL(double startX, double startY) {
    doubleRect(startX, startY, 0, 3, 1, 8);
    doubleRect(startX, startY, 1, 10, 4, 1);
    return 6 * this->scale;
}

double Text::upperM(double startX, double startY) {
    doubleRect(startX, startY, 0, 3, 1, 8);
    doubleRect(startX, startY, 1, 4, 1, 2);
    doubleRect(startX, startY, 2, 6, 1, 2);
    doubleRect(startX, startY, 3, 4, 1, 2);
    doubleRect(startX, startY, 4, 3, 1, 8);
    return 6 * this->scale;
}

double Text::upperN(double startX, double startY) {
    doubleRect(startX, startY, 0, 3, 1, 8);
    doubleRect(startX, startY, 1, 4, 1, 2);
    doubleRect(startX, startY, 2, 6, 1, 1);
    doubleRect(startX, startY, 3, 7, 1, 2);
    doubleRect(startX, startY, 4, 3, 1, 8);
    return 6 * this->scale;
}

double Text::upperO(double startX, double startY) {
    doubleRect(startX, startY, 0, 4, 1, 6);
    doubleRect(startX, startY, 1, 3, 3, 1);
    doubleRect(startX, startY, 1, 10, 3, 1);
    doubleRect(startX, startY, 4, 4, 1, 6);
    return 6 * this->scale;
}

double Text::upperP(double startX, double startY) {
    doubleRect(startX, startY, 0, 3, 1, 8);
    doubleRect(startX, startY, 1, 3, 3, 1);
    doubleRect(startX, startY, 1, 7, 3, 1);
    doubleRect(startX, startY, 4, 4, 1, 3);
    return 6 * this->scale;
}

double Text::upperQ(double startX, double startY) {
    doubleRect(startX, startY, 0, 4, 1, 6);
    doubleRect(startX, startY, 1, 3, 3, 1);
    doubleRect(startX, startY, 1, 8, 2, 1);
    doubleRect(startX, startY, 1, 10, 3, 1);
    doubleRect(startX, startY, 4, 4, 1, 6);
    doubleRect(startX, startY, 5, 10, 1, 1);
    rectangle(startX, startY, 3, 9, 1, 1);
    ofSetColor(255, 255, 255);
    rectangle(startX, startY, 4, 11, 1, 1);
    rectangle(startX, startY, 6, 10, 1, 2);
    return 6 * this->scale;
}

double Text::upperR(double startX, double startY) {
    doubleRect(startX, startY, 0, 3, 1, 8);
    doubleRect(startX, startY, 1, 3, 3, 1);
    doubleRect(startX, startY, 1, 7, 2, 1);
    doubleRect(startX, startY, 4, 4, 1, 3);
    doubleRect(startX, startY, 3, 7, 1, 2);
    doubleRect(startX, startY, 4, 9, 1, 2);
    return 6 * this->scale;
}

double Text::upperS(double startX, double startY) {
    doubleRect(startX, startY, 1, 3, 3, 1);
    doubleRect(startX, startY, 4, 4, 1, 1);
    doubleRect(startX, startY, 0, 4, 1, 2);
    doubleRect(startX, startY, 1, 6, 2, 1);
    doubleRect(startX, startY, 3, 7, 1, 1);
    doubleRect(startX, startY, 4, 8, 1, 2);
    doubleRect(startX, startY, 0, 9, 1, 1);
    doubleRect(startX, startY, 1, 10, 3, 1);
    ofSetColor(255, 255, 255);
    rectangle(startX, startY, 4, 5, 2, 1);
    rectangle(startX, startY, 3, 8, 1, 1);
    return 6 * this->scale;
}

double Text::upperT(double startX, double startY) {
    doubleRect(startX, startY, 0, 3, 5, 1);
    doubleRect(startX, startY, 2, 4, 1, 7);
    return 6 * this->scale;
}

double Text::upperU(double startX, double startY) {
    doubleRect(startX, startY, 0, 3, 1, 7);
    doubleRect(startX, startY, 4, 3, 1, 7);
    doubleRect(startX, startY, 1, 10, 3, 1);
    return 6 * this->scale;
}

double Text::upperV(double startX, double startY) {
    doubleRect(startX, startY, 0, 3, 1, 4);
    doubleRect(startX, startY, 1, 7, 1, 2);
    doubleRect(startX, startY, 2, 9, 1, 2);
    doubleRect(startX, startY, 3, 7, 1, 2);
    doubleRect(startX, startY, 4, 3, 1, 4);
    return 6 * this->scale;
}

double Text::upperW(double startX, double startY) {
    doubleRect(startX, startY, 0, 3, 1, 8);
    doubleRect(startX, startY, 1, 8, 1, 2);
    doubleRect(startX, startY, 2, 5, 1, 3);
    doubleRect(startX, startY, 3, 8, 1, 2);
    doubleRect(startX, startY, 4, 3, 1, 8);
    return 6 * this->scale;
}

double Text::upperX(double startX, double startY) {
    doubleRect(startX, startY, 0, 3, 1, 2);
    doubleRect(startX, startY, 0, 9, 1, 2);
    doubleRect(startX, startY, 1, 5, 1, 1);
    doubleRect(startX, startY, 1, 8, 1, 1);
    doubleRect(startX, startY, 2, 6, 1, 2);
    doubleRect(startX, startY, 3, 5, 1, 1);
    doubleRect(startX, startY, 3, 8, 1, 1);
    doubleRect(startX, startY, 4, 3, 1, 2);
    doubleRect(startX, startY, 4, 9, 1, 2);
    ofSetColor(255, 255, 255);
    rectangle(startX, startY, 2, 9, 1, 1);
    rectangle(startX, startY, 0, 5, 1, 1);
    return 6 * this->scale;
}

double Text::upperY(double startX, double startY) {
    doubleRect(startX, startY, 0, 3, 1, 2);
    doubleRect(startX, startY, 1, 5, 1, 2);
    doubleRect(startX, startY, 2, 7, 1, 4);
    doubleRect(startX, startY, 3, 5, 1, 2);
    doubleRect(startX, startY, 4, 3, 1, 2);
    return 6 * this->scale;
}

double Text::upperZ(double startX, double startY) {
    doubleRect(startX, startY, 0, 3, 4, 1);
    doubleRect(startX, startY, 4, 3, 1, 2);
    doubleRect(startX, startY, 0, 9, 1, 2);
    doubleRect(startX, startY, 1, 8, 1, 1);
    doubleRect(startX, startY, 2, 6, 1, 2);
    doubleRect(startX, startY, 3, 5, 1, 1);
    doubleRect(startX, startY, 1, 10, 4, 1);
    return 6 * this->scale;
}



// LOWER LETTERS

double Text::lowerA(double startX, double startY) {
    doubleRect(startX, startY, 0, 7, 1, 3);
    doubleRect(startX, startY, 1, 10, 2, 1);
    doubleRect(startX, startY, 1, 6, 4, 1);
    doubleRect(startX, startY, 4, 7, 1, 4);
    rectangle(startX, startY, 3, 9, 1, 1);
    ofSetColor(255, 255, 255);
    rectangle(startX, startY, 3, 11, 1, 1);
    return 6 * this->xMult;
}

double Text::lowerB(double startX, double startY) {
    doubleRect(startX, startY, 0, 3, 1, 8);
    doubleRect(startX, startY, 1, 6, 3, 1);
    doubleRect(startX, startY, 1, 10, 3, 1);
    doubleRect(startX, startY, 4, 7, 1, 3);
    return 6 * this->xMult;
}

double Text::lowerC(double startX, double startY) {
    doubleRect(startX, startY, 1, 6, 3, 1);
    doubleRect(startX, startY, 0, 7, 1, 3);
    doubleRect(startX, startY, 1, 10, 3, 1);
    doubleRect(startX, startY, 4, 9, 1, 1);
    rectangle(startX, startY, 4, 7, 1, 1);
    setTextColor2();
    rectangle(startX, startY, 5, 7, 1, 1);
    return 6 * this->xMult;
}

double Text::lowerD(double startX, double startY) {
    doubleRect(startX, startY, 0, 7, 1, 3);
    doubleRect(startX, startY, 1, 6, 3, 1);
    doubleRect(startX, startY, 1, 10, 3, 1);
    doubleRect(startX, startY, 4, 3, 1, 8);
    return 6 * this->xMult;
}

double Text::lowerE(double startX, double startY) {
    doubleRect(startX, startY, 1, 6, 3, 1);
    doubleRect(startX, startY, 0, 7, 1, 3);
    doubleRect(startX, startY, 1, 8, 3, 1);
    doubleRect(startX, startY, 1, 10, 4, 1);
    doubleRect(startX, startY, 4, 7, 1, 2);
    ofSetColor(255, 255, 255);
    rectangle(startX, startY, 5, 9, 1, 1);
    rectangle(startX, startY, 5, 11, 1, 1);
    return 6 * this->xMult;
}

double Text::lowerF(double startX, double startY) {
    doubleRect(startX, startY, 2, 3, 2, 1);
    doubleRect(startX, startY, 1, 4, 1, 7);
    doubleRect(startX, startY, 0, 6, 4, 1);
    rectangle(startX, startY, 1, 7, 1, 1);
    ofSetColor(255, 255, 255);
    rectangle(startX, startY, 4, 4, 1, 1);
    return 5 * this->xMult;
}

double Text::lowerG(double startX, double startY) {
    doubleRect(startX, startY, 0, 7, 1, 3);
    doubleRect(startX, startY, 1, 6, 3, 1);
    doubleRect(startX, startY, 1, 10, 3, 1);
    doubleRect(startX, startY, 1, 12, 3, 1);
    doubleRect(startX, startY, 4, 7, 1, 5);
    return 6 * this->xMult;
}

double Text::lowerH(double startX, double startY) {
    doubleRect(startX, startY, 0, 3, 1, 8);
    doubleRect(startX, startY, 1, 6, 3, 1);
    doubleRect(startX, startY, 4, 7, 1, 4);
    return 6 * this->xMult;
}

double Text::lowerI(double startX, double startY) {
    doubleRect(startX, startY, 0, 3, 1, 1);
    doubleRect(startX, startY, 0, 6, 1, 5);
    return 2 * this->xMult;
}

double Text::lowerJ(double startX, double startY) {
    doubleRect(startX, startY, 3, 3, 1, 1);
    doubleRect(startX, startY, 3, 6, 1, 6);
    doubleRect(startX, startY, 0, 10, 1, 2);
    doubleRect(startX, startY, 1, 12, 2, 1);
    return 5 * this->xMult;
}

double Text::lowerK(double startX, double startY) {
    doubleRect(startX, startY, 0, 3, 1, 8);
    doubleRect(startX, startY, 1, 8, 1, 1);
    doubleRect(startX, startY, 2, 7, 1, 1);
    doubleRect(startX, startY, 3, 6, 1, 1);
    doubleRect(startX, startY, 2, 9, 1, 1);
    doubleRect(startX, startY, 3, 10, 1, 1);
    ofSetColor(255, 255, 255);
    rectangle(startX, startY, 3, 8, 1, 1);
    rectangle(startX, startY, 4, 7, 1, 1);
    return 5 * this->xMult;
}

double Text::lowerL(double startX, double startY) { 
    doubleRect(startX, startY, 0, 3, 1, 1);
    doubleRect(startX, startY, 1, 3, 1, 8);
    return 3 * this->xMult;
}

double Text::lowerM(double startX, double startY) {
    doubleRect(startX, startY, 0, 6, 1, 5);
    doubleRect(startX, startY, 2, 6, 1, 5);
    doubleRect(startX, startY, 3, 6, 1, 1);
    doubleRect(startX, startY, 4, 7, 1, 4);
    rectangle(startX, startY, 1, 6, 1, 1);
    ofSetColor(255, 255, 255);
    rectangle(startX, startY, 1, 11, 1, 1);
    rectangle(startX, startY, 3, 11, 1, 1);
    return 6 * this->xMult;
}

double Text::lowerN(double startX, double startY) {
    doubleRect(startX, startY, 0, 6, 1, 5);
    doubleRect(startX, startY, 1, 6, 2, 1);
    doubleRect(startX, startY, 3, 7, 1, 4);
    return 5 * this->xMult;
}

double Text::lowerO(double startX, double startY) {
    doubleRect(startX, startY, 0, 7, 1, 3);
    doubleRect(startX, startY, 1, 6, 3, 1);
    doubleRect(startX, startY, 1, 10, 3, 1);
    doubleRect(startX, startY, 4, 7, 1, 3);
    return 6 * this->xMult;
}

double Text::lowerP(double startX, double startY) {
    doubleRect(startX, startY, 0, 6, 1, 7);
    doubleRect(startX, startY, 1, 6, 3, 1);
    doubleRect(startX, startY, 1, 10, 3, 1);
    doubleRect(startX, startY, 4, 7, 1, 3);
    return 6 * this->xMult;
}

double Text::lowerQ(double startX, double startY) {
    doubleRect(startX, startY, 0, 7, 1, 3);
    doubleRect(startX, startY, 1, 6, 3, 1);
    doubleRect(startX, startY, 1, 10, 3, 1);
    doubleRect(startX, startY, 4, 6, 1, 7);
    return 6 * this->xMult;
}

double Text::lowerR(double startX, double startY) {
    doubleRect(startX, startY, 0, 6, 1, 5);
    doubleRect(startX, startY, 2, 6, 2, 1);
    doubleRect(startX, startY, 1, 7, 1, 1);
    return 5 * this->xMult;
}

double Text::lowerS(double startX, double startY) {
    doubleRect(startX, startY, 0, 6, 1, 2);
    doubleRect(startX, startY, 1, 6, 3, 1);
    doubleRect(startX, startY, 1, 8, 2, 1);
    doubleRect(startX, startY, 0, 10, 3, 1);
    doubleRect(startX, startY, 3, 9, 1, 2);
    return 5 * this->xMult;
}

double Text::lowerT(double startX, double startY) {
    doubleRect(startX, startY, 1, 4, 1, 2);
    doubleRect(startX, startY, 0, 6, 4, 1);
    doubleRect(startX, startY, 1, 7, 1, 4);
    doubleRect(startX, startY, 2, 10, 2, 1);
    return 5 * this->xMult;
}

double Text::lowerU(double startX, double startY) {
    doubleRect(startX, startY, 0, 6, 1, 4);
    doubleRect(startX, startY, 1, 10, 2, 1);
    doubleRect(startX, startY, 3, 6, 1, 4);
    doubleRect(startX, startY, 4, 10, 1, 1);
    ofSetColor(255, 255, 255);
    rectangle(startX, startY, 3, 11, 1, 1);
    rectangle(startX, startY, 5, 10, 1, 2);
    return 5 * this->xMult;
}

double Text::lowerV(double startX, double startY) {
    doubleRect(startX, startY, 0, 6, 1, 2);
    doubleRect(startX, startY, 1, 8, 1, 2);
    doubleRect(startX, startY, 2, 10, 1, 1);
    doubleRect(startX, startY, 3, 8, 1, 2);
    doubleRect(startX, startY, 4, 6, 1, 2);
    return 6 * this->xMult;
}

double Text::lowerW(double startX, double startY) {
    doubleRect(startX, startY, 0, 6, 1, 4);
    doubleRect(startX, startY, 1, 10, 1, 1);
    doubleRect(startX, startY, 2, 6, 1, 4);
    doubleRect(startX, startY, 3, 10, 1, 1);
    doubleRect(startX, startY, 4, 6, 1, 4);
    return 6 * this->xMult;
}

double Text::lowerX(double startX, double startY) {
    doubleRect(startX, startY, 0, 6, 1, 1);
    doubleRect(startX, startY, 1, 7, 1, 1);
    doubleRect(startX, startY, 2, 8, 1, 1);
    doubleRect(startX, startY, 3, 9, 1, 1);
    doubleRect(startX, startY, 4, 10, 1, 1);
    doubleRect(startX, startY, 0, 10, 1, 1);
    doubleRect(startX, startY, 4, 6, 1, 1);
    rectangle(startX, startY, 1, 9, 1, 1);
    rectangle(startX, startY, 3, 7, 1, 1);
    return 6 * this->xMult;
}

double Text::lowerY(double startX, double startY) {
    doubleRect(startX, startY, 0, 6, 1, 4);
    doubleRect(startX, startY, 1, 10, 3, 1);
    doubleRect(startX, startY, 1, 12, 3, 1);
    doubleRect(startX, startY, 4, 6, 1, 6);
    rectangle(startX, startY, 0, 12, 1, 1);
    return 6 * this->xMult;
}

double Text::lowerZ(double startX, double startY) {
    doubleRect(startX, startY, 0, 6, 5, 1);
    doubleRect(startX, startY, 3, 7, 1, 1);
    doubleRect(startX, startY, 2, 8, 1, 1);
    rectangle(startX, startY, 1, 9, 1, 1);
    doubleRect(startX, startY, 0, 10, 5, 1);
    return 6 * this->xMult;
}



// NUMBERS

double Text::number0(double startX, double startY) {
    doubleRect(startX, startY, 0, 3, 1, 7);
    doubleRect(startX, startY, 1, 2, 3, 1);
    doubleRect(startX, startY, 1, 10, 3, 1);
    doubleRect(startX, startY, 4, 3, 1, 7);
    return 6 * this->xMult;
}

double Text::number1(double startX, double startY) {
    doubleRect(startX, startY, 0, 3, 1, 1);
    doubleRect(startX, startY, 1, 2, 1, 8);
    doubleRect(startX, startY, 0, 10, 3, 1);
    return 3 * this->xMult;
}

double Text::number2(double startX, double startY) {
    doubleRect(startX, startY, 0, 3, 1, 2);
    doubleRect(startX, startY, 1, 2, 3, 1);
    doubleRect(startX, startY, 4, 3, 1, 3);
    doubleRect(startX, startY, 3, 6, 1, 1);
    doubleRect(startX, startY, 2, 7, 1, 1);
    doubleRect(startX, startY, 1, 8, 1, 1);
    doubleRect(startX, startY, 0, 9, 1, 2);
    doubleRect(startX, startY, 1, 10, 4, 1);
    return 6 * this->xMult;
}

double Text::number3(double startX, double startY) {
    doubleRect(startX, startY, 0, 3, 1, 1);
    doubleRect(startX, startY, 1, 2, 3, 1);
    doubleRect(startX, startY, 4, 3, 1, 3);
    doubleRect(startX, startY, 2, 6, 2, 1);
    doubleRect(startX, startY, 4, 7, 1, 3);
    doubleRect(startX, startY, 0, 9, 1, 1);
    doubleRect(startX, startY, 1, 10, 3, 1);
    ofSetColor(255, 255, 255);
    rectangle(startX, startY, 1, 9, 1, 1);
    rectangle(startX, startY, 5, 6, 1, 1);
    return 6 * this->xMult;
}

double Text::number4(double startX, double startY) {
    doubleRect(startX, startY, 1, 3, 1, 2);
    doubleRect(startX, startY, 0, 5, 1, 3);
    doubleRect(startX, startY, 0, 8, 5, 1);
    doubleRect(startX, startY, 3, 2, 1, 9);
    rectangle(startX, startY, 2, 2, 1, 1);
    rectangle(startX, startY, 4, 8, 1, 1);
    return 6 * this->xMult;
}

double Text::number5(double startX, double startY) {
    doubleRect(startX, startY, 0, 2, 5, 1);
    doubleRect(startX, startY, 0, 3, 1, 4);
    doubleRect(startX, startY, 1, 6, 3, 1);
    doubleRect(startX, startY, 4, 7, 1, 3);
    doubleRect(startX, startY, 0, 9, 1, 1);
    doubleRect(startX, startY, 1, 10, 3, 1);
    ofSetColor(255, 255, 255);
    rectangle(startX, startY, 1, 9, 3, 1);
    return 6 * this->xMult;
}

double Text::number6(double startX, double startY) {
    doubleRect(startX, startY, 1, 2, 3, 1);
    doubleRect(startX, startY, 4, 3, 1, 1);
    doubleRect(startX, startY, 0, 3, 1, 7);
    doubleRect(startX, startY, 1, 6, 3, 1);
    doubleRect(startX, startY, 1, 10, 3, 1);
    doubleRect(startX, startY, 4, 7, 1, 3);
    return 6 * this->xMult;
}

double Text::number7(double startX, double startY) {
    doubleRect(startX, startY, 0, 2, 5, 1);
    doubleRect(startX, startY, 4, 3, 1, 3);
    doubleRect(startX, startY, 3, 6, 1, 2);
    doubleRect(startX, startY, 2, 8, 1, 3);
    return 6 * this->xMult;
}

double Text::number8(double startX, double startY) {
    doubleRect(startX, startY, 0, 3, 1, 3);
    doubleRect(startX, startY, 0, 7, 1, 3);
    doubleRect(startX, startY, 1, 2, 3, 1);
    doubleRect(startX, startY, 1, 6, 3, 1);
    doubleRect(startX, startY, 1, 10, 3, 1);
    doubleRect(startX, startY, 4, 3, 1, 3);
    doubleRect(startX, startY, 4, 7, 1, 3);
    ofSetColor(255, 255, 255);
    rectangle(startX, startY, 5, 6, 1, 1);
    return 6 * this->xMult;
}

double Text::number9(double startX, double startY) {
    doubleRect(startX, startY, 0, 3, 1, 3);
    doubleRect(startX, startY, 0, 9, 1, 1);
    doubleRect(startX, startY, 1, 2, 3, 1);
    doubleRect(startX, startY, 1, 6, 3, 1);
    doubleRect(startX, startY, 1, 10, 3, 1);
    doubleRect(startX, startY, 4, 3, 1, 7);
    ofSetColor(255, 255, 255);
    rectangle(startX, startY, 0, 6, 1, 1);
    return 6 * this->xMult;
}



// OTHER

double Text::whitespace(double startX, double startY) {
    return 4 * this->xMult;
}

double Text::exclamationMark(double startX, double startY) {
    doubleRect(startX, startY, 0, 1, 1, 10);
    ofSetColor(255, 255, 255);
    rectangle(startX, startY, 0, 8, 2, 1);
    return 3 * this->xMult;
}

double Text::questionMark(double startX, double startY) {
    doubleRect(startX, startY, 0, 2, 1, 2);
    doubleRect(startX, startY, 1, 1, 3, 1);
    doubleRect(startX, startY, 4, 2, 1, 3);
    doubleRect(startX, startY, 2, 6, 1, 6);
    doubleRect(startX, startY, 3, 5, 1, 1);
    ofSetColor(255, 255, 255);
    rectangle(startX, startY, 2, 8, 2, 1);
    return 6 * this->xMult;
}

double Text::periodMark(double startX, double startY) {
    doubleRect(startX, startY, 0, 9, 2, 2);
    return 6 * this->xMult;
}

double Text::dashMark(double startX, double startY) {
    doubleRect(startX, startY, 1, 6, 5, 1);
    return 7 * this->xMult;
}

double Text::midPointMark(double startX, double startY) {
    doubleRect(startX, startY, 1, 6, 2, 2);
    return 4 * this->xMult;
}

double Text::threePoints(double startX, double startY) {
    doubleRect(startX, startY, 0, 10, 5, 1);
    setTextColor2();
    rectangle(startX, startY, 1, 10, 1, 1);
    rectangle(startX, startY, 3, 10, 1, 1);
    return 4 * this->xMult;
}

double Text::leftQuotes(double startX, double startY) {
    doubleRect(startX, startY, 0, 1, 2, 3);
    doubleRect(startX, startY, 1, 0, 1, 1);
    doubleRect(startX, startY, 3, 1, 2, 3);
    doubleRect(startX, startY, 4, 0, 1, 1);
    ofSetColor(255, 255, 255);
    rectangle(startX, startY, 2, 1, 1, 1);
    rectangle(startX, startY, 5, 1, 1, 1);
    return 6 * this->xMult;
}

double Text::rightQuotes(double startX, double startY) {
    doubleRect(startX, startY, 0, 0, 5, 3);
    doubleRect(startX, startY, 0, 3, 1, 1);
    doubleRect(startX, startY, 3, 3, 1, 1);
    setTextColor2();
    rectangle(startX, startY, 2, 0, 1, 3);
    rectangle(startX, startY, 0, 2, 1, 1);
    rectangle(startX, startY, 3, 2, 1, 1);
    return 6 * this->xMult;
}

double Text::leftApostrophe(double startX, double startY) {
    doubleRect(startX, startY, 0, 1, 2, 3);
    doubleRect(startX, startY, 1, 0, 1, 1);
    ofSetColor(255, 255, 255);
    rectangle(startX, startY, 0, 0, 1, 1);
    rectangle(startX, startY, 2, 1, 1, 1);
    return 3 * this->xMult;
}

double Text::rightApostrophe(double startX, double startY) {
    doubleRect(startX, startY, 0, 0, 2, 2);
    doubleRect(startX, startY, 1, 2, 1, 1);
    doubleRect(startX, startY, 0, 3, 1, 1);
    return 3 * this->xMult;
}

double Text::maleSymbol(double startX, double startY) {
    doubleRect(startX, startY, 0, 3, 1, 1);
    doubleRect(startX, startY, 2, 1, 1, 5);
    doubleRect(startX, startY, 4, 3, 1, 1);
    doubleRect(startX, startY, 0, 7, 1, 3);
    doubleRect(startX, startY, 1, 6, 3, 1);
    doubleRect(startX, startY, 1, 10, 3, 1);
    doubleRect(startX, startY, 4, 7, 1, 3);
    rectangle(startX, startY, 1, 2, 1, 1);
    rectangle(startX, startY, 3, 2, 1, 1);
    return 6 * this->xMult;
}

double Text::femaleSymbol(double startX, double startY) {
    doubleRect(startX, startY, 0, 2, 1, 3);
    doubleRect(startX, startY, 1, 1, 3, 1);
    doubleRect(startX, startY, 1, 5, 3, 1);
    doubleRect(startX, startY, 4, 2, 1, 3);
    doubleRect(startX, startY, 0, 7, 5, 1);
    doubleRect(startX, startY, 2, 8, 1, 3);
    rectangle(startX, startY, 2, 6, 1, 1);
    return 6 * this->xMult;
}

double Text::genderlessSymbol(double startX, double startY) {
    doubleRect(startX, startY, 1, 1, 1, 6);
    doubleRect(startX, startY, 2, 1, 2, 1);
    doubleRect(startX, startY, 2, 5, 1, 1);
    doubleRect(startX, startY, 4, 2, 1, 3);
    doubleRect(startX, startY, 0, 7, 5, 1);
    doubleRect(startX, startY, 0, 9, 5, 1);
    doubleRect(startX, startY, 1, 10, 1, 1);
    rectangle(startX, startY, 3, 5, 1, 1);
    rectangle(startX, startY, 1, 8, 1, 1);
    return 6 * this->xMult;
}

double Text::commaMark(double startX, double startY) {
    doubleRect(startX, startY, 0, 9, 2, 2);
    doubleRect(startX, startY, 1, 11, 1, 1);
    doubleRect(startX, startY, 0, 12, 1, 1);
    return 3 * this->xMult;
}

double Text::multiplySymbol(double startX, double startY) {
    doubleRect(startX, startY, 0, 4, 1, 1);
    doubleRect(startX, startY, 1, 5, 1, 1);
    doubleRect(startX, startY, 2, 6, 2, 2);
    doubleRect(startX, startY, 1, 8, 1, 1);
    doubleRect(startX, startY, 0, 9, 1, 1);
    doubleRect(startX, startY, 4, 5, 1, 1);
    doubleRect(startX, startY, 4, 8, 1, 1);
    doubleRect(startX, startY, 5, 4, 1, 1);
    doubleRect(startX, startY, 5, 9, 1, 1);
    return 7 * this->xMult;
}

double Text::divisionSymbol(double startX, double startY) {
    doubleRect(startX, startY, 0, 9, 1, 2);
    doubleRect(startX, startY, 1, 7, 1, 2);
    doubleRect(startX, startY, 2, 5, 1, 2);
    doubleRect(startX, startY, 3, 3, 1, 2);
    doubleRect(startX, startY, 4, 1, 1, 2);
    return 6 * this->xMult;
}

double Text::specialE(double startX, double startY) {
    doubleRect(startX, startY, 2, 3, 2, 1);
    rectangle(startX, startY, 1, 4, 1, 1);
    ofSetColor(255, 255, 255);
    rectangle(startX, startY, 4, 4, 1, 1);
    lowerE(startX, startY);
    return 6 * this->xMult;
}

double Text::ampersandSymbol(double startX, double startY) {
    doubleRect(startX, startY, 2, 1, 1, 1);
    doubleRect(startX, startY, 1, 2, 1, 2);
    doubleRect(startX, startY, 3, 2, 1, 2);
    doubleRect(startX, startY, 2, 4, 1, 2);
    doubleRect(startX, startY, 1, 6, 1, 1);
    doubleRect(startX, startY, 0, 7, 1, 2);
    doubleRect(startX, startY, 1, 9, 2, 1);
    doubleRect(startX, startY, 3, 6, 1, 3);
    doubleRect(startX, startY, 4, 5, 1, 1);
    doubleRect(startX, startY, 4, 9, 1, 1);
    ofSetColor(255, 255, 255);
    rectangle(startX, startY, 4, 4, 1, 1);
    rectangle(startX, startY, 3, 10, 1, 1);
    return 6 * this->xMult;
}

double Text::additionSymbol(double startX, double startY) {
    doubleRect(startX, startY, 0, 7, 2, 1);
    doubleRect(startX, startY, 2, 5, 1, 5);
    doubleRect(startX, startY, 3, 7, 2, 1);
    return 6 * this->xMult;
}

double Text::levelSymbol(double startX, double startY) {
    doubleRect(startX, startY, 0, 4, 1, 7);
    doubleRect(startX, startY, 1, 10, 2, 1);
    lowerV(startX + (4 * this->xMult), startY);
    return 10 * this->xMult;
}

double Text::equalSign(double startX, double startY) {
    doubleRect(startX, startY, 0, 4, 5, 1);
    doubleRect(startX, startY, 0, 7, 5, 1);
    return 6 * this->xMult;
}

double Text::semiColonMark(double startX, double startY) {
    doubleRect(startX, startY, 0, 3, 2, 2);
    doubleRect(startX, startY, 0, 7, 2, 2);
    doubleRect(startX, startY, 1, 9, 1, 1);
    doubleRect(startX, startY, 0, 10, 1, 1);
    return 6 * this->xMult;
}

double Text::percentageSymbol(double startX, double startY) {
    doubleRect(startX, startY, 0, 2, 3, 4);
    doubleRect(startX, startY, 1, 10, 1, 2);
    doubleRect(startX, startY, 2, 8, 1, 2);
    doubleRect(startX, startY, 3, 6, 1, 2);
    doubleRect(startX, startY, 4, 4, 1, 2);
    doubleRect(startX, startY, 5, 2, 1, 2);
    doubleRect(startX, startY, 4, 8, 3, 4);
    setTextColor2();
    rectangle(startX, startY, 1, 3, 1, 2);
    rectangle(startX, startY, 5, 9, 1, 2);
    ofSetColor(255, 255, 255);
    rectangle(startX, startY, 3, 10, 1, 1);
    return 6 * this->xMult;
}

double Text::upArrow(double startX, double startY) {
    doubleRect(startX, startY, 0, 4, 2, 1);
    rectangle(startX, startY, 1, 3, 1, 1);
    doubleRect(startX, startY, 2, 2, 5, 6);
    rectangle(startX, startY, 3, 1, 3, 1);
    rectangle(startX, startY, 4, 0, 1, 1);
    doubleRect(startX, startY, 7, 3, 1, 2);
    doubleRect(startX, startY, 8, 4, 1, 1);
    setTextColor2();
    rectangle(startX, startY, 5, 0, 1, 1);
    rectangle(startX, startY, 6, 1, 1, 1);
    rectangle(startX, startY, 7, 2, 1, 1);
    return 10 * this->xMult;
}

double Text::downArrow(double startX, double startY) {
    doubleRect(startX, startY, 4, 8, 1, 1);
    doubleRect(startX, startY, 5, 7, 1, 1);
    doubleRect(startX, startY, 6, 6, 1, 1);
    doubleRect(startX, startY, 7, 5, 1, 1);
    doubleRect(startX, startY, 8, 4, 1, 1);
    rectangle(startX, startY, 7, 4, 1, 1);
    rectangle(startX, startY, 2, 1, 5, 6);
    rectangle(startX, startY, 3, 7, 2, 1);
    rectangle(startX, startY, 0, 4, 1, 1);
    rectangle(startX, startY, 1, 4, 1, 2);
    setTextColor2();
    rectangle(startX, startY, 0, 5, 1, 1);
    rectangle(startX, startY, 1, 6, 1, 1);
    rectangle(startX, startY, 2, 7, 1, 1);
    rectangle(startX, startY, 3, 8, 1, 1);
    rectangle(startX, startY, 7, 1, 1, 3);
    return 10 * this->xMult;
}

double Text::leftArrow(double startX, double startY) {
    doubleRect(startX, startY, 4, 0, 1, 2);
    rectangle(startX, startY, 3, 1, 1, 1);
    doubleRect(startX, startY, 2, 2, 6, 5);
    rectangle(startX, startY, 1, 3, 1, 3);
    rectangle(startX, startY, 0, 4, 1, 1);
    rectangle(startX, startY, 3, 7, 1, 1);
    doubleRect(startX, startY, 4, 7, 1, 2);
    setTextColor2();
    rectangle(startX, startY, 0, 5, 1, 1);
    rectangle(startX, startY, 1, 6, 1, 1);
    rectangle(startX, startY, 2, 7, 1, 1);
    rectangle(startX, startY, 3, 8, 1, 1);
    return 9 * this->xMult;
}

double Text::rightArrow(double startX, double startY) {
    doubleRect(startX, startY, 0, 2, 6, 5);
    rectangle(startX, startY, 3, 0, 1, 1);
    rectangle(startX, startY, 3, 1, 2, 1);
    doubleRect(startX, startY, 6, 3, 1, 3);
    doubleRect(startX, startY, 7, 4, 1, 1);
    doubleRect(startX, startY, 3, 7, 1, 2);
    doubleRect(startX, startY, 4, 7, 1, 1);
    setTextColor2();
    rectangle(startX, startY, 4, 0, 1, 1);
    rectangle(startX, startY, 5, 1, 1, 1);
    rectangle(startX, startY, 6, 2, 1, 1);
    return 9 * this->xMult;
}

double Text::nextLineSymbol(double startX, double startY) {
    rectangle(startX, startY, 0, 6, 1, 3);
    rectangle(startX, startY, 1, 6, 6, 1);
    rectangle(startX, startY, 1, 9, 1, 1);
    rectangle(startX, startY, 2, 10, 1, 1);
    rectangle(startX, startY, 3, 11, 1, 1);
    rectangle(startX, startY, 4, 10, 1, 1);
    rectangle(startX, startY, 5, 9, 1, 1);
    rectangle(startX, startY, 6, 7, 1, 2);
    ofSetColor(210, 0, 0);
    rectangle(startX, startY, 1, 7, 5, 1);
    ofSetColor(228, 0, 0);
    rectangle(startX, startY, 1, 8, 5, 1);
    ofSetColor(255, 0, 0);
    rectangle(startX, startY, 2, 9, 3, 1);
    rectangle(startX, startY, 3, 10, 1, 1);
    return 6 * this->xMult;
}





// template <typename Func>
// double timeChecker(Func func, double xPos, double yPos) {
//     // Record the start time
//     auto startTime = std::chrono::high_resolution_clock::now();

//     (this->*func)(xPos, yPos);

//     // Record the end time
//     auto endTime = std::chrono::high_resolution_clock::now();

//     // Calculate the duration in microseconds
//     auto duration = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime).count();

//     // Print the execution time
//     // std::cout << "Execution time: " << duration << " microseconds" << std::endl;

//     this->execTimeCount += 1;
//     this->execTimeTotal += duration;
//     this-> execTimeAvg = this->execTimeTotal / this->execTimeCount;

//     // Print the execution time avg
//     std::cout << "Execution time Avg: " << this->execTimeAvg << " microseconds" << std::endl;

//     return 0;
// }

void Text::newCharPrints() {
    double xPos = this->screenStartX + ((BOX_START_X + BOX_START_TEXT_POS_X) * this->xMult);
    double yPos = this->screenStartY + ((BOX_START_Y + BOX_START_TEXT_POS_Y) * this->yMult);
    ofSetColor(0, 0, 0);




    // this->upperA(xPos, yPos);
    // this->upperB(xPos, yPos);
    // this->upperC(xPos, yPos);
    // this->upperD(xPos, yPos);
    // this->upperE(xPos, yPos);
    // this->upperF(xPos, yPos);
    // this->upperG(xPos, yPos);
    // this->upperH(xPos, yPos);
    // this->upperI(xPos, yPos);
    // this->upperJ(xPos, yPos);
    // this->upperK(xPos, yPos);
    // this->upperL(xPos, yPos);
    // this->upperM(xPos, yPos);
    // this->upperN(xPos, yPos);
    // this->upperO(xPos, yPos);
    // this->upperP(xPos, yPos);
    // this->upperQ(xPos, yPos);
    // this->upperR(xPos, yPos);
    // this->upperS(xPos, yPos);
    // this->upperT(xPos, yPos);
    // this->upperU(xPos, yPos);
    // this->upperV(xPos, yPos);
    // this->upperW(xPos, yPos);
    // this->upperX(xPos, yPos);
    // this->upperY(xPos, yPos);
    // this->upperZ(xPos, yPos);



    // this->lowerA(xPos, yPos);
    // this->lowerB(xPos, yPos);
    // this->lowerC(xPos, yPos);
    // this->lowerD(xPos, yPos);
    // this->lowerE(xPos, yPos);
    // this->lowerF(xPos, yPos);
    // this->lowerG(xPos, yPos);
    // this->lowerH(xPos, yPos);
    // this->lowerI(xPos, yPos);
    // this->lowerJ(xPos, yPos);
    // this->lowerK(xPos, yPos);
    // this->lowerL(xPos, yPos);
    // this->lowerM(xPos, yPos);
    // this->lowerN(xPos, yPos);
    // this->lowerO(xPos, yPos);
    // this->lowerP(xPos, yPos);
    // this->lowerQ(xPos, yPos);
    // this->lowerR(xPos, yPos);
    // this->lowerS(xPos, yPos);
    // this->lowerT(xPos, yPos);
    // this->lowerU(xPos, yPos);
    // this->lowerV(xPos, yPos);
    // this->lowerW(xPos, yPos);
    // this->lowerX(xPos, yPos);
    // this->lowerY(xPos, yPos);
    // this->lowerZ(xPos, yPos);



    // this->number0(xPos, yPos);
    // this->number1(xPos, yPos);
    // this->number2(xPos, yPos);
    // this->number3(xPos, yPos);
    // this->number4(xPos, yPos);
    // this->number5(xPos, yPos);
    // this->number6(xPos, yPos);
    // this->number7(xPos, yPos);
    // this->number8(xPos, yPos);
    // this->number9(xPos, yPos);



    // this->exclamationMark(xPos, yPos);
    // this->questionMark(xPos, yPos);
    // this->periodMark(xPos, yPos);
    // this->dashMark(xPos, yPos);
    // this->midPointMark(xPos, yPos);
    // this->threePoints(xPos, yPos);
    // this->leftQuotes(xPos, yPos);
    //  this->rightQuotes(xPos, yPos);
    // this->leftApostrophe(xPos, yPos);
    // this->rightApostrophe(xPos, yPos);
    // this->maleSymbol(xPos, yPos);
    // this->femaleSymbol(xPos, yPos);
    // this->genderlessSymbol(xPos, yPos);
    // this->commaMark(xPos, yPos);
    // this->multiplySymbol(xPos, yPos);
    // this->divisionSymbol(xPos, yPos);
    // this->specialE(xPos, yPos);
    // this->ampersandSymbol(xPos, yPos);
    // this->additionSymbol(xPos, yPos);
    // this->levelSymbol(xPos, yPos);
    // this->equalSign(xPos, yPos);
    // this->semiColonMark(xPos, yPos);
    // this->percentageSymbol(xPos, yPos);
    // this->upArrow(xPos, yPos);
    // this->downArrow(xPos, yPos);
    // this->leftArrow(xPos, yPos);
    // this->rightArrow(xPos, yPos);
    // this->nextLineSymbol(xPos, yPos);
}