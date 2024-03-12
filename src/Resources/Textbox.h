#include "ofMain.h"
#include "Text.h"
#include <string>

const int LINE_CHAR_LIMIT = 35;

const int BOX_START_X = 1;
const int BOX_START_Y = 115;
const int BOX_START_TEXT_POS_X = 15;
const int BOX_START_TEXT_POS_Y = 7;
const int NEXT_LINE_Y = 16;

const int BOX_HEIGHT = 42;
const int BOX_WIDTH = 238;
const int BOX_CORNER_HEIGHT = 5;
const int BOX_CORNER_WIDTH = 10;
const int BOX_DEFAULT_WIDTH = 156;

const int NEXT_ICON_SPEED = 15;
const int NEXT_ICON_MOVEDIST = 3;

class Textbox {

private:

    Text textTool;

    double textboxStartX;
    double textboxStartY;

    int primaryTextBoxColor;
    int secondaryTextboxColor;

    double scale;

    int speed;  // The speed of reading text
    int savedSpeed;

    int timer;  // Timer for text animation

    int nextIconTimer;
    int nextIconMove;
    int nextIconDir;

    bool finishPrint;    // Print stopper

    bool goNextLine;    // Next line permission

    bool showTextBox;   // Display stopper

    // Indexes for printing chars
    int sentenceIndex;
    int lineIndex;
    int charIndex;

    int boxOption;    // Text box choice number

    std::string textString;   // Text that will be displayed

    std::vector<std::vector<std::string>> readyText;

    void prepareText();
    
    void printAllChars();

    void updateNextIconTimer();

    void drawTextbox();

    void drawLeftTopCorner(double startX, double startY);
    void drawLeftBottomCorner(double startX, double startY);
    void drawRightTopCorner(double startX, double startY);
    void drawRightBottomCorner(double startX, double startY);
    void drawLeftSide(double startX, double startY, double height);
    void drawRightSide(double startX, double startY, double height);
    void drawTopSide(double startX, double startY, double width);
    void drawBottomSide(double startX, double startY, double width);
    void drawLeftParts();
    void drawRightParts();


public:

    Textbox(int speed, int boxOption, std::string text);

    void scaleDims(double screenStartX, double screenStartY, double scale);

    void setSpeed(int speed) { this->speed = speed; };

    void setTextBoxOption(int boxOption) { this->boxOption = boxOption; };

    void setText(std::string text) {this->textString = text; };

    void render();

    void tick();

    void toggleNextLine();

    void toggleShow(bool show);

    void reset();

};