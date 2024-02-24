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

const int NEXT_ICON_SPEED = 4;
const int NEXT_ICON_MOVEDIST = 3;

class Text {

private:

    double execTimeCount = 0;
    double execTimeTotal = 0;
    double execTimeAvg = 0;

    double xMult;  // Pixel scaling on x-axis
    double yMult;  // Pixel scaling on y-axis
    double screenStartX;   
    double screenStartY;

    int scale;

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

    void horizontalStick(double startX, double startY, double xDist, double yDist, double width);
    void verticalStick(double startX, double startY, double xDist, double yDist, double length);
    void rectangle(double startX, double startY, double xDist, double yDist, double width, double height);
    void doubleRect(double startX, double startY, double xDist, double yDist, double width, double height);

    // double timeChecker(double (Text::*)(double startX, double startY), double xPos, double yPos);
    // template <typename Func>
    // double timeChecker(Func func, double xPos, double yPos);



    double lowerA(double startX, double startY);
    double lowerB(double startX, double startY);
    double lowerC(double startX, double startY);
    double lowerD(double startX, double startY);
    double lowerE(double startX, double startY);
    double lowerF(double startX, double startY);
    double lowerG(double startX, double startY);
    double lowerH(double startX, double startY);
    double lowerI(double startX, double startY);
    double lowerJ(double startX, double startY);
    double lowerK(double startX, double startY);
    double lowerL(double startX, double startY);
    double lowerM(double startX, double startY);
    double lowerN(double startX, double startY);
    double lowerO(double startX, double startY);
    double lowerP(double startX, double startY);
    double lowerQ(double startX, double startY);
    double lowerR(double startX, double startY);
    double lowerS(double startX, double startY);
    double lowerT(double startX, double startY);
    double lowerU(double startX, double startY);
    double lowerV(double startX, double startY);
    double lowerW(double startX, double startY);
    double lowerX(double startX, double startY);
    double lowerY(double startX, double startY);
    double lowerZ(double startX, double startY);

    double upperA(double startX, double startY);
    double upperB(double startX, double startY);
    double upperC(double startX, double startY);
    double upperD(double startX, double startY);
    double upperE(double startX, double startY);
    double upperF(double startX, double startY);
    double upperG(double startX, double startY);
    double upperH(double startX, double startY);
    double upperI(double startX, double startY);
    double upperJ(double startX, double startY);
    double upperK(double startX, double startY);
    double upperL(double startX, double startY);
    double upperM(double startX, double startY);
    double upperN(double startX, double startY);
    double upperO(double startX, double startY);
    double upperP(double startX, double startY);
    double upperQ(double startX, double startY);
    double upperR(double startX, double startY);
    double upperS(double startX, double startY);
    double upperT(double startX, double startY);
    double upperU(double startX, double startY);
    double upperV(double startX, double startY);
    double upperW(double startX, double startY);
    double upperX(double startX, double startY);
    double upperY(double startX, double startY);
    double upperZ(double startX, double startY);

    // double normalA(double startX, double startY);
    // double fasterA(double startX, double startY);


    void newCharPrints();
};