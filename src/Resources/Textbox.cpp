#include "Textbox.h"

std::vector<std::vector<int>> primaryTextboxColors = {
    {0, 247, 152},      // Green
    {247, 218, 0},      // Yellow
    {247, 137, 0},      // Orange
    {247, 0, 0},        // Red
    {0, 125, 247},      // Blue
    {206, 0, 247},      // Purple
    {112, 104, 128},    // Blue-Gray
    {71, 71, 71},       // Black
    {208, 208, 208}     // Light-Gray
};

std::vector<std::vector<int>> secondaryTextboxColors = {
    {0, 199, 184},      // Green
    {199, 174, 0},      // Yellow
    {199, 106, 0},      // Orange
    {199, 0, 0},        // Red
    {0, 97, 199},       // Blue
    {138, 0, 199},      // Purple
    {91, 85, 106},      // Blue-Gray
    {45, 45, 45},       // Black
    {165, 165, 165}     // Light-Gray
};

Textbox::Textbox(int speed, int boxOption, std::string text) {
    this->textTool = Text();
    this->primaryTextBoxColor = 0;
    this->secondaryTextboxColor = 0;
    this->sentenceIndex = 0;
    this->lineIndex = 0;
    this->charIndex = 0;
    this->speed = speed;
    this->savedSpeed = speed;
    this->finishPrint = false;
    this->goNextLine = false;
    this->showTextBox = true;
    this->boxOption = boxOption;
    this->textString = text;
    this->timer = 0;
    this->nextIconTimer = 0;
    this->nextIconMove = 0;
    this->nextIconDir = 1;
    this->prepareText();
}

void Textbox::scaleDims(double screenStartX, double screenStartY, double scale) {
    this->textboxStartX = screenStartX + (BOX_START_X * scale);
    this->textboxStartY = screenStartY + (BOX_START_Y * scale);
    this->scale = scale;
}

void Textbox::tick() {

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

                        this->updateNextIconTimer();

                        if (this->goNextLine) {
                            this->sentenceIndex += 1;
                            this->charIndex = 0;
                            this->lineIndex = 0;
                            this->goNextLine = false;
                            this->speed = this->savedSpeed;
                        }
                        else {
                            this->timer = this->speed;
                        }
                    }

                }
                else {
                    if (this->lineIndex > 0) {

                        this->updateNextIconTimer();

                        if (this->goNextLine) {
                            this->lineIndex += 1;
                            this->charIndex = 0;
                            this->goNextLine = false;
                            this->speed = this->savedSpeed;
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

        this->updateNextIconTimer();

        if (this->goNextLine) {
            this->showTextBox = false;
            this->goNextLine = false;
        }
    }

    this->goNextLine = false;
}

void Textbox::toggleNextLine() {
    this->goNextLine = true;
    this->speed = 0;
    this->timer = 0;
}

void Textbox::toggleShow(bool show) {
    this->showTextBox = show;
}

void Textbox::render() {

    if (this->showTextBox) {
        this->drawTextbox();
        this->printAllChars();
    }
    
}

void Textbox::printAllChars() {

    int startX = this->textboxStartX + (BOX_START_TEXT_POS_X * this->scale);
    int xPos = startX;
    int yPos = this->textboxStartY + (BOX_START_TEXT_POS_Y * this->scale);
    char curChar;

    // If 2 liner
    if (this->lineIndex > 0) {

        // First line print
        int firstLineSize = this->readyText.at(this->sentenceIndex).at(this->lineIndex - 1).size();
        for (int i = 0; i < firstLineSize; i++) {
            curChar = this->readyText.at(this->sentenceIndex).at(this->lineIndex - 1).at(i);
            xPos += this->textTool.drawChar(curChar, xPos, yPos, this->scale);
        }

        // Second line print
        xPos = startX;
        yPos += (NEXT_LINE_Y * this->scale);
        for (int i = 0; i < this->charIndex + 1; i++) {
            curChar = this->readyText.at(this->sentenceIndex).at(this->lineIndex).at(i);
            xPos += this->textTool.drawChar(curChar, xPos, yPos, this->scale);
        }

        // If end of line
        if (this->charIndex + 1 == this->readyText.at(this->sentenceIndex).at(this->lineIndex).size()) {
            this->textTool.drawNext(xPos, yPos + (this->nextIconMove * this->scale), this->scale);
        }

    }
    else {
        for (int i = 0; i < this->charIndex + 1; i++) {
            curChar = this->readyText.at(this->sentenceIndex).at(this->lineIndex).at(i);
            xPos += this->textTool.drawChar(curChar, xPos, yPos, this->scale);
        }
        // If end of line
        if (this->charIndex + 1 == this->readyText.at(this->sentenceIndex).at(this->lineIndex).size()) {
            // If end of sentence
            if (this->lineIndex == this->readyText.at(this->sentenceIndex).size() - 1) {
                this->textTool.drawNext(xPos, yPos + (this->nextIconMove * this->scale), this->scale);
            }
        }
    }

}

void Textbox::prepareText() {
    std::vector<std::string> lineWords;
    int curLineSize = 0;
    std::string curWord= "";
    std::string curLine = "";

    for (char charVal : this->textString) {

        curWord += charVal;
        curLineSize += 1;

        if (curLineSize > LINE_CHAR_LIMIT) {
            lineWords.push_back(curLine);
            curLine = "";
            curLineSize = curWord.size();
        }

        if (charVal == ' ') {
            curLine += curWord;
            curWord = "";
        }
        else if (charVal == '.' || charVal == '!' || charVal == '?' || charVal == '_' || charVal == '>') {    // Sentence terminators
            curLine += curWord;
            lineWords.push_back(curLine);
            this->readyText.push_back(lineWords);
            curWord = "";
            curLine = "";
            lineWords.clear();
            curLineSize = 0;
        }
        
    }

}

void Textbox::updateNextIconTimer() {

    // Updating next icon movement
    if (this->nextIconTimer == NEXT_ICON_SPEED) {
        this->nextIconMove += this->nextIconDir;
        this->nextIconTimer = 0;
    }
    else {
        this->nextIconTimer += 1;
    }

    // Updating next icon direction
    if (this->nextIconMove == NEXT_ICON_MOVEDIST + 1 || this->nextIconMove == -1) {
        this->nextIconDir *= -1;
        this->nextIconMove += (this->nextIconDir * 2);
    }

}

void Textbox::drawTextbox() {
    this->drawLeftParts();
    this->drawTopSide(this->textboxStartX + (BOX_CORNER_WIDTH * this->scale), this->textboxStartY, BOX_WIDTH - (BOX_CORNER_WIDTH * 2));
    this->drawBottomSide(this->textboxStartX + (BOX_CORNER_WIDTH * this->scale), this->textboxStartY + ((BOX_HEIGHT - BOX_CORNER_HEIGHT) * this->scale), BOX_WIDTH - (BOX_CORNER_WIDTH * 2));
    this->drawRightParts();
}


void Textbox::drawLeftTopCorner(double startX, double startY) {
    // Primary Color
    std::vector<int> rgbVals = primaryTextboxColors[this->primaryTextBoxColor];
    ofSetColor(rgbVals[0], rgbVals[1], rgbVals[2]);
    rectangle(startX, startY, 5, 0, 5, 3, this->scale);
    rectangle(startX, startY, 3, 1, 2, 2, this->scale);
    rectangle(startX, startY, 2, 2, 1, 3, this->scale);
    rectangle(startX, startY, 1, 3, 1, 2, this->scale);
    // Secondary Color
    rgbVals = secondaryTextboxColors[this->secondaryTextboxColor];
    ofSetColor(rgbVals[0], rgbVals[1], rgbVals[2]);
    rectangle(startX, startY, 5, 2, 4, 1, this->scale);
    rectangle(startX, startY, 3, 3, 5, 1, this->scale);
    rectangle(startX, startY, 3, 4, 4, 1, this->scale);
    // Last Color
    setLastTextboxColor();
    rectangle(startX, startY, 8, 3, 1, 1, this->scale);
    rectangle(startX, startY, 7, 4, 1, 1, this->scale);
}

void Textbox::drawLeftBottomCorner(double startX, double startY) {
    // Primary Color
    std::vector<int> rgbVals = primaryTextboxColors[this->primaryTextBoxColor];
    ofSetColor(rgbVals[0], rgbVals[1], rgbVals[2]);
    rectangle(startX, startY, 1, 0, 2, 2, this->scale);
    rectangle(startX, startY, 2, 2, 1, 1, this->scale);
    rectangle(startX, startY, 3, 2, 2, 2, this->scale);
    rectangle(startX, startY, 5, 2, 5, 3, this->scale);
    // Secondary Color
    rgbVals = secondaryTextboxColors[this->secondaryTextboxColor];
    ofSetColor(rgbVals[0], rgbVals[1], rgbVals[2]);
    rectangle(startX, startY, 3, 0, 5, 2, this->scale);
    rectangle(startX, startY, 5, 2, 4, 1, this->scale);
    // Last Color
    setLastTextboxColor();
    rectangle(startX, startY, 7, 0, 1, 1, this->scale);
    rectangle(startX, startY, 8, 1, 1, 1, this->scale);
}

void Textbox::drawRightTopCorner(double startX, double startY) {
    // Primary Color
    std::vector<int> rgbVals = primaryTextboxColors[this->primaryTextBoxColor];
    ofSetColor(rgbVals[0], rgbVals[1], rgbVals[2]);
    rectangle(startX, startY, 0, 0, 5, 3, this->scale);
    rectangle(startX, startY, 5, 1, 2, 2, this->scale);
    rectangle(startX, startY, 7, 2, 1, 3, this->scale);
    rectangle(startX, startY, 8, 3, 1, 2, this->scale);
    // Secondary Color
    rgbVals = secondaryTextboxColors[this->secondaryTextboxColor];
    ofSetColor(rgbVals[0], rgbVals[1], rgbVals[2]);
    rectangle(startX, startY, 1, 2, 4, 1, this->scale);
    rectangle(startX, startY, 2, 3, 5, 2, this->scale);
    // Last Color
    setLastTextboxColor();
    rectangle(startX, startY, 1, 3, 1, 1, this->scale);
    rectangle(startX, startY, 2, 4, 1, 1, this->scale);
}

void Textbox::drawRightBottomCorner(double startX, double startY) {
    // Primary Color
    std::vector<int> rgbVals = primaryTextboxColors[this->primaryTextBoxColor];
    ofSetColor(rgbVals[0], rgbVals[1], rgbVals[2]);
    rectangle(startX, startY, 0, 2, 5, 3, this->scale);
    rectangle(startX, startY, 5, 2, 2, 2, this->scale);
    rectangle(startX, startY, 7, 0, 1, 3, this->scale);
    rectangle(startX, startY, 8, 0, 1, 2, this->scale);
    // Secondary Color
    rgbVals = secondaryTextboxColors[this->secondaryTextboxColor];
    ofSetColor(rgbVals[0], rgbVals[1], rgbVals[2]);
    rectangle(startX, startY, 1, 2, 4, 1, this->scale);
    rectangle(startX, startY, 2, 0, 5, 2, this->scale);
    // Last Color
    setLastTextboxColor();
    rectangle(startX, startY, 1, 1, 1, 1, this->scale);
    rectangle(startX, startY, 2, 0, 1, 1, this->scale);
}

void Textbox::drawLeftSide(double startX, double startY, double height) {
    // Primary Color
    std::vector<int> rgbVals = primaryTextboxColors[this->primaryTextBoxColor];
    ofSetColor(rgbVals[0], rgbVals[1], rgbVals[2]);
    rectangle(startX, startY, 0, 0, 2, height, this->scale);
    // Secondary Color
    rgbVals = secondaryTextboxColors[this->secondaryTextboxColor];
    ofSetColor(rgbVals[0], rgbVals[1], rgbVals[2]);
    rectangle(startX, startY, 2, 0, 4, height, this->scale);
    // Last Color
    setLastTextboxColor();
    rectangle(startX, startY, 6, 0, 1, height, this->scale);
}

void Textbox::drawRightSide(double startX, double startY, double height) {
    // Primary Color
    std::vector<int> rgbVals = primaryTextboxColors[this->primaryTextBoxColor];
    ofSetColor(rgbVals[0], rgbVals[1], rgbVals[2]);
    rectangle(startX, startY, 8, 0, 2, height, this->scale);
    // Secondary Color
    rgbVals = secondaryTextboxColors[this->secondaryTextboxColor];
    ofSetColor(rgbVals[0], rgbVals[1], rgbVals[2]);
    rectangle(startX, startY, 4, 0, 4, height, this->scale);
    // Last Color
    setLastTextboxColor();
    rectangle(startX, startY, 3, 0, 1, height, this->scale);
}

void Textbox::drawTopSide(double startX, double startY, double width) {
    // Primary Color
    std::vector<int> rgbVals = primaryTextboxColors[this->primaryTextBoxColor];
    ofSetColor(rgbVals[0], rgbVals[1], rgbVals[2]);
    rectangle(startX, startY, 0, 0, width, 2, this->scale);
    // Last Color
    setLastTextboxColor();
    rectangle(startX, startY, 0, 2, width, 1, this->scale);
}

void Textbox::drawBottomSide(double startX, double startY, double width) {
    // Primary Color
    std::vector<int> rgbVals = primaryTextboxColors[this->primaryTextBoxColor];
    ofSetColor(rgbVals[0], rgbVals[1], rgbVals[2]);
    rectangle(startX, startY, 0, 3, width, 2, this->scale);
    // Last Color
    setLastTextboxColor();
    rectangle(startX, startY, 0, 2, width, 1, this->scale);
}

void Textbox::drawLeftParts() {
    this->drawLeftTopCorner(this->textboxStartX, this->textboxStartY);
    this->drawLeftSide(this->textboxStartX, this->textboxStartY + (BOX_CORNER_HEIGHT * this->scale), BOX_HEIGHT - (BOX_CORNER_HEIGHT * 2));
    this->drawLeftBottomCorner(this->textboxStartX, this->textboxStartY + ((BOX_HEIGHT - BOX_CORNER_HEIGHT) * this->scale));
}

void Textbox::drawRightParts() {
    double commonX = this->textboxStartX + ((BOX_WIDTH - BOX_CORNER_WIDTH) * this->scale);
    this->drawRightTopCorner(commonX, this->textboxStartY);
    this->drawRightSide(commonX, this->textboxStartY + (BOX_CORNER_HEIGHT * this->scale), BOX_HEIGHT - (BOX_CORNER_HEIGHT * 2));
    this->drawRightBottomCorner(commonX, this->textboxStartY + ((BOX_HEIGHT - BOX_CORNER_HEIGHT) * this->scale));
}




