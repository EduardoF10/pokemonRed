#include "Text.h"

Text::Text(int speed, int boxOption, std::string text) {
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

    // If 2 liner
    if (this->lineIndex > 0) {

        // First line print
        int firstLineSize = this->readyText.at(this->sentenceIndex).at(this->lineIndex - 1).size();
        for (int i = 0; i < firstLineSize; i++) {
            this->printChar(this->readyText.at(this->sentenceIndex).at(this->lineIndex - 1).at(i), xPos, yPos, CHARS_WIDTH * this->xMult, CHARS_HEIGHT * this->yMult);
            xPos += CHAR_SPACE_X * this->xMult;
        }

        // Second line print
        xPos = startX;
        yPos = this->screenStartY + ((BOX_START_Y + BOX_NEXT_LINE_Y) * this->yMult);
        int charCounter = 0;
        for (int i = 0; i < this->charIndex + 1; i++) {
            this->printChar(this->readyText.at(this->sentenceIndex).at(this->lineIndex).at(i), xPos, yPos, CHARS_WIDTH * this->xMult, CHARS_HEIGHT * this->yMult);
            xPos += CHAR_SPACE_X * this->xMult;
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
            this->printChar(this->readyText.at(this->sentenceIndex).at(this->lineIndex).at(i), xPos, yPos, CHARS_WIDTH * this->xMult, CHARS_HEIGHT * this->yMult);
            xPos += CHAR_SPACE_X * this->xMult;
            charCounter += 1;
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