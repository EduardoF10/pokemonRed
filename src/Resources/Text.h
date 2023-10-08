#include <string>

class Text {

    const int START_ALPHA_NUM_X = 0;
    const int START_NUMS_Y = 0;
    const int START_CAPS_Y = 15;
    const int START_LETTERS_Y = 32;
    const int ALPHA_NUM_WIDTH = 6;
    const int ALPHA_NUM_HEIGHT = 12;
    const int ALPHA_NUM_SPACE_X = 7;


private:

    int speed;  // The speed of reading text

    int timer;  // Timer for animation

    int textBox;    // Text box choice number

    std::string text;   // Text that will be displayed

    int charIndex;  // Current char position

    ofImage getCharImage(char textChar);    // Returns image of textChar




public:

    Text(int speed, int textBox, std::string text);

    void setSpeed(int speed);

    void setTextBox(int boxOption);

    void setText(std::string text);

    void render();

    void tick();

    void quickDisplay();

    void reset();

};