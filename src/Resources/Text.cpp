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
    ofSetColor(208, 208, 200);
    ofDrawRectangle(startX + (xDist * this->xMult), startY + (yDist * this->yMult), this->xMult * (width + 1), this->yMult * (height + 1));
    ofSetColor(77, 77, 77);
    ofDrawRectangle(startX + (xDist * this->xMult), startY + (yDist * this->yMult), this->xMult * width, this->yMult * height);
}

void Text::setTextColor2() {
    ofSetColor(208, 208, 200);
}

void Text::setTextColor1() {
    ofSetColor(77, 77, 77);
}




double Text::upperA(double startX, double startY) {

    doubleRect(startX, startY, 0, 1, 1, 7);
    doubleRect(startX, startY, 1, 0, 3, 1);
    doubleRect(startX, startY, 1, 4, 3, 1);
    doubleRect(startX, startY, 4, 1, 1, 7);

    return 6 * this->scale;
}

double Text::upperB(double startX, double startY) {

    doubleRect(startX, startY, 0, 0, 1, 8);
    doubleRect(startX, startY, 1, 0, 3, 1);
    doubleRect(startX, startY, 1, 3, 3, 1);
    doubleRect(startX, startY, 1, 7, 3, 1);
    doubleRect(startX, startY, 4, 1, 1, 2);
    doubleRect(startX, startY, 4, 4, 1, 3);
    ofSetColor(255, 255, 255);
    rectangle(startX, startY, 5, 3, 1, 1);

    return 6 * this->scale;

}

double Text::upperC(double startX, double startY) {

    doubleRect(startX, startY, 0, 1, 1, 6);
    doubleRect(startX, startY, 1, 0, 3, 1);
    doubleRect(startX, startY, 1, 7, 3, 1);
    doubleRect(startX, startY, 4, 1, 1, 1);
    doubleRect(startX, startY, 4, 6, 1, 1);

    return 6 * this->scale;

}

double Text::upperD(double startX, double startY) {

    doubleRect(startX, startY, 0, 0, 1, 8);
    doubleRect(startX, startY, 1, 0, 3, 1);
    doubleRect(startX, startY, 1, 7, 3, 1);
    doubleRect(startX, startY, 4, 1, 1, 6);

    return 6 * this->scale;

}

double Text::upperE(double startX, double startY) {

    doubleRect(startX, startY, 0, 0, 1, 8);
    doubleRect(startX, startY, 1, 0, 4, 1);
    doubleRect(startX, startY, 1, 3, 3, 1);
    doubleRect(startX, startY, 1, 7, 4, 1);

    return 6 * this->scale;

}

double Text::upperF(double startX, double startY) {

    doubleRect(startX, startY, 0, 0, 1, 8);
    doubleRect(startX, startY, 1, 0, 4, 1);
    doubleRect(startX, startY, 1, 3, 3, 1);

    return 6 * this->scale;

}

double Text::upperG(double startX, double startY) {

    doubleRect(startX, startY, 0, 1, 1, 6);
    doubleRect(startX, startY, 1, 0, 3, 1);
    doubleRect(startX, startY, 1, 7, 3, 1);
    doubleRect(startX, startY, 3, 4, 1, 1);
    doubleRect(startX, startY, 4, 1, 1, 6);
    ofSetColor(255, 255, 255);
    rectangle(startX, startY, 4, 3, 2, 1);

    return 6 * this->scale;

}

double Text::upperH(double startX, double startY) {

    doubleRect(startX, startY, 0, 0, 1, 8);
    doubleRect(startX, startY, 1, 3, 3, 1);
    doubleRect(startX, startY, 4, 0, 1, 8);

    return 6 * this->scale;

}

double Text::upperI(double startX, double startY) {

    doubleRect(startX, startY, 0, 0, 5, 1);
    doubleRect(startX, startY, 2, 1, 1, 6);
    doubleRect(startX, startY, 0, 7, 5, 1);

    return 6 * this->scale;

}

double Text::upperJ(double startX, double startY) {

    doubleRect(startX, startY, 0, 6, 1, 1);
    doubleRect(startX, startY, 1, 7, 3, 1);
    doubleRect(startX, startY, 4, 0, 1, 7);

    return 6 * this->scale;

}

double Text::upperK(double startX, double startY) {

    doubleRect(startX, startY, 0, 0, 1, 8);
    doubleRect(startX, startY, 1, 3, 1, 2);
    doubleRect(startX, startY, 4, 7, 1, 1);
    rectangle(startX, startY, 2, 2, 1, 1);
    rectangle(startX, startY, 2, 5, 1, 1);
    rectangle(startX, startY, 3, 1, 1, 1);
    rectangle(startX, startY, 3, 6, 1, 1);
    rectangle(startX, startY, 4, 0, 1, 1);
    setTextColor2();
    rectangle(startX, startY, 3, 2, 1, 1);
    rectangle(startX, startY, 3, 5, 1, 1);
    rectangle(startX, startY, 4, 1, 1, 1);
    rectangle(startX, startY, 4, 6, 1, 1);
    rectangle(startX, startY, 5, 0, 1, 1);

    return 6 * this->scale;

}

double Text::upperL(double startX, double startY) {

    doubleRect(startX, startY, 0, 0, 1, 8);
    doubleRect(startX, startY, 1, 7, 4, 1);

    return 6 * this->scale;

}

double Text::upperM(double startX, double startY) {

    doubleRect(startX, startY, 0, 0, 1, 8);
    doubleRect(startX, startY, 1, 1, 1, 2);
    doubleRect(startX, startY, 2, 3, 1, 2);
    doubleRect(startX, startY, 3, 1, 1, 2);
    doubleRect(startX, startY, 4, 0, 1, 8);

    return 6 * this->scale;

}

double Text::upperN(double startX, double startY) {

    doubleRect(startX, startY, 0, 0, 1, 8);
    doubleRect(startX, startY, 1, 1, 1, 2);
    doubleRect(startX, startY, 2, 3, 1, 1);
    doubleRect(startX, startY, 3, 4, 1, 2);
    doubleRect(startX, startY, 4, 0, 1, 8);

    return 6 * this->scale;

}

double Text::upperO(double startX, double startY) {

    doubleRect(startX, startY, 0, 1, 1, 6);
    doubleRect(startX, startY, 1, 0, 3, 1);
    doubleRect(startX, startY, 1, 7, 3, 1);
    doubleRect(startX, startY, 4, 1, 1, 6);

    return 6 * this->scale;

}

double Text::upperP(double startX, double startY) {

    doubleRect(startX, startY, 0, 0, 1, 8);
    doubleRect(startX, startY, 1, 0, 3, 1);
    doubleRect(startX, startY, 1, 4, 3, 1);
    doubleRect(startX, startY, 4, 1, 1, 3);

    return 6 * this->scale;

}

double Text::upperQ(double startX, double startY) {

    doubleRect(startX, startY, 0, 1, 1, 6);
    doubleRect(startX, startY, 1, 0, 3, 1);
    doubleRect(startX, startY, 1, 5, 2, 1);
    doubleRect(startX, startY, 1, 7, 3, 1);
    doubleRect(startX, startY, 4, 1, 1, 6);
    doubleRect(startX, startY, 5, 7, 1, 1);
    rectangle(startX, startY, 3, 6, 1, 1);
    ofSetColor(255, 255, 255);
    rectangle(startX, startY, 4, 8, 1, 1);
    rectangle(startX, startY, 6, 7, 1, 2);

    return 6 * this->scale;

}

double Text::upperR(double startX, double startY) {

    doubleRect(startX, startY, 0, 0, 1, 8);
    doubleRect(startX, startY, 1, 0, 3, 1);
    doubleRect(startX, startY, 1, 4, 2, 1);
    doubleRect(startX, startY, 4, 1, 1, 3);
    doubleRect(startX, startY, 3, 4, 1, 2);
    doubleRect(startX, startY, 4, 6, 1, 2);

    return 6 * this->scale;

}

double Text::upperS(double startX, double startY) {

    doubleRect(startX, startY, 1, 0, 3, 1);
    doubleRect(startX, startY, 4, 1, 1, 1);
    doubleRect(startX, startY, 0, 1, 1, 2);
    doubleRect(startX, startY, 1, 3, 2, 1);
    doubleRect(startX, startY, 3, 4, 1, 1);
    doubleRect(startX, startY, 4, 5, 1, 2);
    doubleRect(startX, startY, 0, 6, 1, 1);
    doubleRect(startX, startY, 1, 7, 3, 1);
    ofSetColor(255, 255, 255);
    rectangle(startX, startY, 4, 2, 2, 1);
    rectangle(startX, startY, 3, 5, 1, 1);

    return 6 * this->scale;

}

double Text::upperT(double startX, double startY) {

    doubleRect(startX, startY, 0, 0, 5, 1);
    doubleRect(startX, startY, 2, 1, 1, 7);

    return 6 * this->scale;

}

double Text::upperU(double startX, double startY) {

    doubleRect(startX, startY, 0, 0, 1, 7);
    doubleRect(startX, startY, 4, 0, 1, 7);
    doubleRect(startX, startY, 1, 7, 3, 1);
    
    return 6 * this->scale;

}

double Text::upperV(double startX, double startY) {

    doubleRect(startX, startY, 0, 0, 1, 4);
    doubleRect(startX, startY, 1, 4, 1, 2);
    doubleRect(startX, startY, 2, 6, 1, 2);
    doubleRect(startX, startY, 3, 4, 1, 2);
    doubleRect(startX, startY, 4, 0, 1, 4);
    
    return 6 * this->scale;

}

double Text::upperW(double startX, double startY) {

    doubleRect(startX, startY, 0, 0, 1, 8);
    doubleRect(startX, startY, 1, 5, 1, 2);
    doubleRect(startX, startY, 2, 2, 1, 3);
    doubleRect(startX, startY, 3, 5, 1, 2);
    doubleRect(startX, startY, 4, 0, 1, 8);

    return 6 * this->scale;

}

double Text::upperX(double startX, double startY) {

    doubleRect(startX, startY, 0, 0, 1, 2);
    doubleRect(startX, startY, 0, 6, 1, 2);
    doubleRect(startX, startY, 1, 2, 1, 1);
    doubleRect(startX, startY, 1, 5, 1, 1);
    doubleRect(startX, startY, 2, 3, 1, 2);
    doubleRect(startX, startY, 3, 2, 1, 1);
    doubleRect(startX, startY, 3, 5, 1, 1);
    doubleRect(startX, startY, 4, 0, 1, 2);
    doubleRect(startX, startY, 4, 6, 1, 2);
    ofSetColor(255, 255, 255);
    rectangle(startX, startY, 2, 6, 1, 1);

    return 6 * this->scale;

}

double Text::upperY(double startX, double startY) {

    doubleRect(startX, startY, 0, 0, 1, 2);
    doubleRect(startX, startY, 1, 2, 1, 2);
    doubleRect(startX, startY, 2, 4, 1, 4);
    doubleRect(startX, startY, 3, 2, 1, 2);
    doubleRect(startX, startY, 4, 0, 1, 2);

    return 6 * this->scale;

}

double Text::upperZ(double startX, double startY) {
    
    doubleRect(startX, startY, 0, 0, 4, 1);
    doubleRect(startX, startY, 4, 0, 1, 2);
    doubleRect(startX, startY, 0, 6, 1, 2);
    doubleRect(startX, startY, 1, 5, 1, 1);
    doubleRect(startX, startY, 2, 3, 1, 2);
    doubleRect(startX, startY, 3, 2, 1, 1);
    doubleRect(startX, startY, 1, 7, 4, 1);

    return 6 * this->scale;

}


double Text::lowerA(double startX, double startY) {

    doubleRect(startX, startY, 0, 4, 1, 3);
    doubleRect(startX, startY, 1, 7, 2, 1);
    doubleRect(startX, startY, 1, 3, 4, 1);
    doubleRect(startX, startY, 4, 4, 1, 4);
    rectangle(startX, startY, 3, 6, 1, 1);
    ofSetColor(255, 255, 255);
    rectangle(startX, startY, 3, 8, 1, 1);

    return 6 * this->xMult;
}

double Text::lowerB(double startX, double startY) {

    doubleRect(startX, startY, 0, 0, 1, 8);
    doubleRect(startX, startY, 1, 3, 3, 1);
    doubleRect(startX, startY, 1, 7, 3, 1);
    doubleRect(startX, startY, 4, 4, 1, 3);

    return 6 * this->xMult;
}

double Text::lowerC(double startX, double startY) {

    doubleRect(startX, startY, 1, 3, 3, 1);
    doubleRect(startX, startY, 0, 4, 1, 3);
    doubleRect(startX, startY, 1, 7, 3, 1);
    doubleRect(startX, startY, 4, 6, 1, 1);
    rectangle(startX, startY, 4, 4, 1, 1);
    setTextColor2();
    rectangle(startX, startY, 5, 4, 1, 1);

    return 6 * this->xMult;
}

double Text::lowerD(double startX, double startY) {

    doubleRect(startX, startY, 0, 4, 1, 3);
    doubleRect(startX, startY, 1, 3, 3, 1);
    doubleRect(startX, startY, 1, 7, 3, 1);
    doubleRect(startX, startY, 4, 0, 1, 8);

    return 6 * this->xMult;
}

double Text::lowerE(double startX, double startY) {

    doubleRect(startX, startY, 1, 3, 3, 1);
    doubleRect(startX, startY, 0, 4, 1, 3);
    doubleRect(startX, startY, 1, 5, 3, 1);
    doubleRect(startX, startY, 1, 7, 4, 1);
    doubleRect(startX, startY, 4, 4, 1, 2);

    ofSetColor(255, 255, 255);
    rectangle(startX, startY, 5, 6, 1, 1);
    rectangle(startX, startY, 5, 8, 1, 1);

    return 6 * this->xMult;
}

double Text::lowerF(double startX, double startY) {
    
    doubleRect(startX, startY, 2, 0, 2, 1);
    doubleRect(startX, startY, 1, 1, 1, 7);
    doubleRect(startX, startY, 0, 3, 4, 1);
    rectangle(startX, startY, 1, 4, 1, 1);
    ofSetColor(255, 255, 255);
    rectangle(startX, startY, 4, 1, 1, 1);

    return 5 * this->xMult;

}

double Text::lowerG(double startX, double startY) {
    
    doubleRect(startX, startY, 0, 4, 1, 3);
    doubleRect(startX, startY, 1, 3, 3, 1);
    doubleRect(startX, startY, 1, 7, 3, 1);
    doubleRect(startX, startY, 1, 9, 3, 1);
    doubleRect(startX, startY, 4, 4, 1, 5);

    return 6 * this->xMult;

}

double Text::lowerH(double startX, double startY) {
    
    doubleRect(startX, startY, 0, 0, 1, 8);
    doubleRect(startX, startY, 1, 3, 3, 1);
    doubleRect(startX, startY, 4, 4, 1, 4);

    return 6 * this->xMult;

}

double Text::lowerI(double startX, double startY) {
    
    doubleRect(startX, startY, 0, 0, 1, 1);
    doubleRect(startX, startY, 0, 3, 1, 5);

    return 2 * this->xMult;

}

double Text::lowerJ(double startX, double startY) {
    
    doubleRect(startX, startY, 3, 0, 1, 1);
    doubleRect(startX, startY, 3, 3, 1, 6);
    doubleRect(startX, startY, 0, 7, 1, 2);
    doubleRect(startX, startY, 1, 9, 2, 1);

    return 5 * this->xMult;

}

double Text::lowerK(double startX, double startY) {
    
    doubleRect(startX, startY, 0, 0, 1, 8);
    doubleRect(startX, startY, 1, 5, 1, 1);
    doubleRect(startX, startY, 2, 4, 1, 1);
    doubleRect(startX, startY, 3, 3, 1, 1);
    doubleRect(startX, startY, 2, 6, 1, 1);
    doubleRect(startX, startY, 3, 7, 1, 1);
    ofSetColor(255, 255, 255);
    rectangle(startX, startY, 3, 5, 1, 1);
    rectangle(startX, startY, 4, 4, 1, 1);
    return 5 * this->xMult;

}

double Text::lowerL(double startX, double startY) {
    
    doubleRect(startX, startY, 0, 0, 1, 1);
    doubleRect(startX, startY, 1, 0, 1, 8);

    return 3 * this->xMult;

}

double Text::lowerM(double startX, double startY) {
    
    doubleRect(startX, startY, 0, 3, 1, 5);
    doubleRect(startX, startY, 2, 3, 1, 5);
    doubleRect(startX, startY, 3, 3, 1, 1);
    doubleRect(startX, startY, 4, 4, 1, 4);
    rectangle(startX, startY, 1, 3, 1, 1);
    ofSetColor(255, 255, 255);
    rectangle(startX, startY, 1, 8, 1, 1);
    rectangle(startX, startY, 3, 8, 1, 1);

    return 6 * this->xMult;

}

double Text::lowerN(double startX, double startY) {
    
    doubleRect(startX, startY, 0, 3, 1, 5);
    doubleRect(startX, startY, 1, 3, 2, 1);
    doubleRect(startX, startY, 3, 4, 1, 4);

    return 5 * this->xMult;

}

double Text::lowerO(double startX, double startY) {
    
    doubleRect(startX, startY, 0, 4, 1, 3);
    doubleRect(startX, startY, 1, 3, 3, 1);
    doubleRect(startX, startY, 1, 7, 3, 1);
    doubleRect(startX, startY, 4, 4, 1, 3);

    return 6 * this->xMult;

}

double Text::lowerP(double startX, double startY) {
    
    doubleRect(startX, startY, 0, 3, 1, 7);
    doubleRect(startX, startY, 1, 3, 3, 1);
    doubleRect(startX, startY, 1, 7, 3, 1);
    doubleRect(startX, startY, 4, 4, 1, 3);

    return 6 * this->xMult;

}

double Text::lowerQ(double startX, double startY) {
    
    doubleRect(startX, startY, 0, 4, 1, 3);
    doubleRect(startX, startY, 1, 3, 3, 1);
    doubleRect(startX, startY, 1, 7, 3, 1);
    doubleRect(startX, startY, 4, 3, 1, 7);

    return 6 * this->xMult;

}

double Text::lowerR(double startX, double startY) {
    
    doubleRect(startX, startY, 0, 3, 1, 5);
    doubleRect(startX, startY, 2, 3, 2, 1);
    doubleRect(startX, startY, 1, 4, 1, 1);

    return 5 * this->xMult;

}

double Text::lowerS(double startX, double startY) {
    
    doubleRect(startX, startY, 0, 3, 1, 2);
    doubleRect(startX, startY, 1, 3, 3, 1);
    doubleRect(startX, startY, 1, 5, 2, 1);
    doubleRect(startX, startY, 0, 7, 3, 1);
    doubleRect(startX, startY, 3, 6, 1, 2);

    return 5 * this->xMult;

}

double Text::lowerT(double startX, double startY) {
    
    doubleRect(startX, startY, 1, 1, 1, 2);
    doubleRect(startX, startY, 0, 3, 4, 1);
    doubleRect(startX, startY, 1, 4, 1, 4);
    doubleRect(startX, startY, 2, 7, 2, 1);

    return 5 * this->xMult;

}

double Text::lowerU(double startX, double startY) {
    
    doubleRect(startX, startY, 0, 3, 1, 4);
    doubleRect(startX, startY, 1, 7, 2, 1);
    doubleRect(startX, startY, 3, 3, 1, 4);
    doubleRect(startX, startY, 4, 7, 1, 1);
    ofSetColor(255, 255, 255);
    rectangle(startX, startY, 3, 8, 1, 1);
    rectangle(startX, startY, 5, 7, 1, 2);

    return 5 * this->xMult;

}

double Text::lowerV(double startX, double startY) {
    
    doubleRect(startX, startY, 0, 3, 1, 2);
    doubleRect(startX, startY, 1, 5, 1, 2);
    doubleRect(startX, startY, 2, 7, 1, 1);
    doubleRect(startX, startY, 3, 5, 1, 2);
    doubleRect(startX, startY, 4, 3, 1, 2);

    return 6 * this->xMult;

}

double Text::lowerW(double startX, double startY) {
    
    doubleRect(startX, startY, 0, 3, 1, 4);
    doubleRect(startX, startY, 1, 7, 1, 1);
    doubleRect(startX, startY, 2, 3, 1, 4);
    doubleRect(startX, startY, 3, 7, 1, 1);
    doubleRect(startX, startY, 4, 3, 1, 4);

    return 6 * this->xMult;

}

double Text::lowerX(double startX, double startY) {
    
    doubleRect(startX, startY, 0, 3, 1, 1);
    doubleRect(startX, startY, 1, 4, 1, 1);
    doubleRect(startX, startY, 2, 5, 1, 1);
    doubleRect(startX, startY, 3, 6, 1, 1);
    doubleRect(startX, startY, 4, 7, 1, 1);
    doubleRect(startX, startY, 0, 7, 1, 1);
    doubleRect(startX, startY, 4, 3, 1, 1);
    rectangle(startX, startY, 1, 6, 1, 1);
    rectangle(startX, startY, 3, 4, 1, 1);

    return 6 * this->xMult;

}

double Text::lowerY(double startX, double startY) {
    
    doubleRect(startX, startY, 0, 3, 1, 4);
    doubleRect(startX, startY, 1, 7, 3, 1);
    doubleRect(startX, startY, 1, 9, 3, 1);
    doubleRect(startX, startY, 4, 3, 1, 6);
    rectangle(startX, startY, 0, 9, 1, 1);

    return 6 * this->xMult;

}

double Text::lowerZ(double startX, double startY) {
    
    doubleRect(startX, startY, 0, 3, 5, 1);
    doubleRect(startX, startY, 3, 4, 1, 1);
    doubleRect(startX, startY, 2, 5, 1, 1);
    rectangle(startX, startY, 1, 6, 1, 1);
    doubleRect(startX, startY, 0, 7, 5, 1);

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
    // this->upperX(xPos + 100, yPos);
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



}