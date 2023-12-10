#include "Text.h"

Text::Text(int speed, int boxOption, std::string text) {
    this->scale = 3;
    this->r = 0;
    this->g = 0;
    this->b = 0;
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
    char prev = ' ';
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
        prev = ' ';
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


void Text::horizontalStick(double startX, double startY, double length) {
    ofDrawRectangle(startX, startY, length * this->scale, this->scale);
}

void Text::verticalStick(double startX, double startY, double length) {
    ofDrawRectangle(startX, startY, this->scale, length * this->scale);
}


double Text::lowerA(double startX, double startY) {

    // Record the start time
    auto startTime = std::chrono::high_resolution_clock::now();

    ofDrawRectangle(startX, startY, this->scale, 7 * this->scale);
    ofDrawRectangle(startX + this->scale, startY - this->scale, 3 * this->scale, this->scale);
    ofDrawRectangle(startX + this->scale, startY + (3 * this->scale), 3 * this->scale, this->scale);
    ofDrawRectangle(startX + (4 * this->scale), startY, this->scale, 7 * this->scale);

    // Record the end time
    auto endTime = std::chrono::high_resolution_clock::now();

    // Calculate the duration in microseconds
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime).count();

    // Print the execution time
    // std::cout << "Execution time: " << duration << " microseconds" << std::endl;

    this->execTimeCount += 1;
    this->execTimeTotal += duration;
    this-> execTimeAvg = this->execTimeTotal / this->execTimeCount;

    // Print the execution time avg
    std::cout << "Execution time Avg: " << this->execTimeAvg << " microseconds" << std::endl;

    return 6 * this->scale;
}

// double Text::lowerB(double startX, double startY) {

// }

double Text::normalA(double startX, double startY) {

    ofDrawRectangle(startX, startY, this->scale, 7 * this->scale);
    ofDrawRectangle(startX + this->scale, startY - this->scale, 3 * this->scale, this->scale);
    ofDrawRectangle(startX + this->scale, startY + (3 * this->scale), 3 * this->scale, this->scale);
    ofDrawRectangle(startX + (4 * this->scale), startY, this->scale, 7 * this->scale);
    return 6 * this->scale;
}

double Text::fasterA(double startX, double startY) {
    ofDrawRectangle(startX, startY, this->scale, 7 * this->scale);
    ofDrawRectangle(startX + this->scale, startY - this->scale, 3 * this->scale, this->scale);
    ofDrawRectangle(startX + this->scale, startY + (3 * this->scale), 3 * this->scale, this->scale);
    ofDrawRectangle(startX + (4 * this->scale), startY, this->scale, 7 * this->scale);
    return 6 * this->scale;
}





void Text::newCharPrints() {
    double xPos = this->screenStartX + ((BOX_START_X + BOX_START_TEXT_POS_X) * this->xMult);
    double yPos = this->screenStartY + ((BOX_START_Y + BOX_START_TEXT_POS_Y) * this->yMult);
    ofSetColor(0, 0, 0);
    this->lowerA(xPos, yPos);
}