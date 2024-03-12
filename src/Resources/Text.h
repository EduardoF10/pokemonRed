#include "ofMain.h"
#include "DrawTools.h"

using TextFunctionPointer = std::function<double(double, double, double)>;

class Text {

private:

    std::vector<TextFunctionPointer> textFunctionsList;

    void setFunctions();

public:

    Text();

    double drawChar(char charItem, double x, double y, double scale);

    double drawNext(double x, double y, double scale);

};