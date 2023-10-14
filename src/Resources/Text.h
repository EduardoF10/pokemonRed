#include "ofMain.h"
#include "TextSprites.h"
#include <cmath>
#include <string>

const int LINE_CHAR_LIMIT = 26;

const int CHAR_SPACE_X = 7;
const int CHAR_SPACE_Y = 15;

const int BOX_START_X = 7;
const int BOX_START_Y = 116;
const int BOX_START_TEXT_POS_X = 11;
const int BOX_START_TEXT_POS_Y = 7;
const int BOX_NEXT_LINE_Y = 22;

class Text {

private:

    double xMult;  // Pixel scaling on x-axis
    double yMult;  // Pixel scaling on y-axis
    double screenStartX;   
    double screenStartY;

    int charWidth;  // Pixel width for each char
    int charHeight; // Pixel height for each char

    int speed;  // The speed of reading text

    int timer;  // Timer for animation

    bool finishPrint;    // Print stopper

    bool goNextLine;    // Next line permission

    bool showTextBox;   // Display stopper

    // Indexes for printing chars
    int sentenceIndex;
    int lineIndex;
    int charIndex;

    int boxOption;    // Text box choice number

    std::string text;   // Text that will be displayed

    std::vector<std::vector<std::string>> readyText;

    ofImage textBox;

    TextSprites* textSprites;

    void prepareText();

    void printChar(char charVal, float xPos, float yPos, float width, float height);
    void printAllChars();

    int getCharSpace(char prev);


public:

    Text(int speed, int textBox, std::string text);

    void scaleDims(double startX, double startY, double xMult, double yMult);

    void setSpeed(int speed);

    void setTextBox(int boxOption);

    void setText(std::string text);

    void render();

    void tick();

    void toggleNextLine();

    void toggleShow(bool show);

    void quickDisplay();

    // void save();    // Too slow

    void reset();

};