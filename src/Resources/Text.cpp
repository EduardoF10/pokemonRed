#include "Text.h"

Text::Text() : textFunctionsList(128) {
    this->setFunctions();
}

// UPPER LETTERS

double upperA(double startX, double startY, double scale) {
    doubleRect(startX, startY, 0, 4, 1, 7, scale);
    doubleRect(startX, startY, 1, 3, 3, 1, scale);
    doubleRect(startX, startY, 1, 7, 3, 1, scale);
    doubleRect(startX, startY, 4, 4, 1, 7, scale);
    return 6 * scale;
}

double upperB(double startX, double startY, double scale) {
    doubleRect(startX, startY, 0, 3, 1, 8, scale);
    doubleRect(startX, startY, 1, 3, 3, 1, scale);
    doubleRect(startX, startY, 1, 6, 3, 1, scale);
    doubleRect(startX, startY, 1, 10, 3, 1, scale);
    doubleRect(startX, startY, 4, 4, 1, 2, scale);
    doubleRect(startX, startY, 4, 7, 1, 3, scale);
    ofSetColor(255, 255, 255);
    rectangle(startX, startY, 5, 6, 1, 1, scale);
    return 6 * scale;
}

double upperC(double startX, double startY, double scale) {
    doubleRect(startX, startY, 0, 4, 1, 6, scale);
    doubleRect(startX, startY, 1, 3, 3, 1, scale);
    doubleRect(startX, startY, 1, 10, 3, 1, scale);
    doubleRect(startX, startY, 4, 4, 1, 1, scale);
    doubleRect(startX, startY, 4, 9, 1, 1, scale);
    return 6 * scale;
}

double upperD(double startX, double startY, double scale) {
    doubleRect(startX, startY, 0, 3, 1, 8, scale);
    doubleRect(startX, startY, 1, 3, 3, 1, scale);
    doubleRect(startX, startY, 1, 10, 3, 1, scale);
    doubleRect(startX, startY, 4, 4, 1, 6, scale);
    return 6 * scale;
}

double upperE(double startX, double startY, double scale) {
    doubleRect(startX, startY, 0, 3, 1, 8, scale);
    doubleRect(startX, startY, 1, 3, 4, 1, scale);
    doubleRect(startX, startY, 1, 6, 3, 1, scale);
    doubleRect(startX, startY, 1, 10, 4, 1, scale);
    return 6 * scale;
}

double upperF(double startX, double startY, double scale) {
    doubleRect(startX, startY, 0, 3, 1, 8, scale);
    doubleRect(startX, startY, 1, 3, 4, 1, scale);
    doubleRect(startX, startY, 1, 6, 3, 1, scale);
    return 6 * scale;
}

double upperG(double startX, double startY, double scale) {
    doubleRect(startX, startY, 0, 4, 1, 6, scale);
    doubleRect(startX, startY, 1, 3, 3, 1, scale);
    doubleRect(startX, startY, 1, 10, 3, 1, scale);
    doubleRect(startX, startY, 3, 7, 1, 1, scale);
    doubleRect(startX, startY, 4, 4, 1, 6, scale);
    ofSetColor(255, 255, 255);
    rectangle(startX, startY, 4, 6, 2, 1, scale);
    return 6 * scale;
}

double upperH(double startX, double startY, double scale) {
    doubleRect(startX, startY, 0, 3, 1, 8, scale);
    doubleRect(startX, startY, 1, 6, 3, 1, scale);
    doubleRect(startX, startY, 4, 3, 1, 8, scale);
    return 6 * scale;
}

double upperI(double startX, double startY, double scale) {
    doubleRect(startX, startY, 0, 3, 5, 1, scale);
    doubleRect(startX, startY, 2, 4, 1, 6, scale);
    doubleRect(startX, startY, 0, 10, 5, 1, scale);
    return 6 * scale;
}

double upperJ(double startX, double startY, double scale) {
    doubleRect(startX, startY, 0, 9, 1, 1, scale);
    doubleRect(startX, startY, 1, 10, 3, 1, scale);
    doubleRect(startX, startY, 4, 3, 1, 7, scale);
    return 6 * scale;
}

double upperK(double startX, double startY, double scale) {
    doubleRect(startX, startY, 0, 3, 1, 8, scale);
    doubleRect(startX, startY, 1, 6, 1, 2, scale);
    doubleRect(startX, startY, 4, 10, 1, 1, scale);
    rectangle(startX, startY, 2, 5, 1, 1, scale);
    rectangle(startX, startY, 2, 8, 1, 1, scale);
    rectangle(startX, startY, 3, 4, 1, 1, scale);
    rectangle(startX, startY, 3, 9, 1, 1, scale);
    rectangle(startX, startY, 4, 3, 1, 1, scale);
    setTextColor2();
    rectangle(startX, startY, 3, 5, 1, 1, scale);
    rectangle(startX, startY, 3, 8, 1, 1, scale);
    rectangle(startX, startY, 4, 4, 1, 1, scale);
    rectangle(startX, startY, 4, 9, 1, 1, scale);
    rectangle(startX, startY, 5, 3, 1, 1, scale);
    return 6 * scale;
}

double upperL(double startX, double startY, double scale) {
    doubleRect(startX, startY, 0, 3, 1, 8, scale);
    doubleRect(startX, startY, 1, 10, 4, 1, scale);
    return 6 * scale;
}

double upperM(double startX, double startY, double scale) {
    doubleRect(startX, startY, 0, 3, 1, 8, scale);
    doubleRect(startX, startY, 1, 4, 1, 2, scale);
    doubleRect(startX, startY, 2, 6, 1, 2, scale);
    doubleRect(startX, startY, 3, 4, 1, 2, scale);
    doubleRect(startX, startY, 4, 3, 1, 8, scale);
    return 6 * scale;
}

double upperN(double startX, double startY, double scale) {
    doubleRect(startX, startY, 0, 3, 1, 8, scale);
    doubleRect(startX, startY, 1, 4, 1, 2, scale);
    doubleRect(startX, startY, 2, 6, 1, 1, scale);
    doubleRect(startX, startY, 3, 7, 1, 2, scale);
    doubleRect(startX, startY, 4, 3, 1, 8, scale);
    return 6 * scale;
}

double upperO(double startX, double startY, double scale) {
    doubleRect(startX, startY, 0, 4, 1, 6, scale);
    doubleRect(startX, startY, 1, 3, 3, 1, scale);
    doubleRect(startX, startY, 1, 10, 3, 1, scale);
    doubleRect(startX, startY, 4, 4, 1, 6, scale);
    return 6 * scale;
}

double upperP(double startX, double startY, double scale) {
    doubleRect(startX, startY, 0, 3, 1, 8, scale);
    doubleRect(startX, startY, 1, 3, 3, 1, scale);
    doubleRect(startX, startY, 1, 7, 3, 1, scale);
    doubleRect(startX, startY, 4, 4, 1, 3, scale);
    return 6 * scale;
}

double upperQ(double startX, double startY, double scale) {
    doubleRect(startX, startY, 0, 4, 1, 6, scale);
    doubleRect(startX, startY, 1, 3, 3, 1, scale);
    doubleRect(startX, startY, 1, 8, 2, 1, scale);
    doubleRect(startX, startY, 1, 10, 3, 1, scale);
    doubleRect(startX, startY, 4, 4, 1, 6, scale);
    doubleRect(startX, startY, 5, 10, 1, 1, scale);
    rectangle(startX, startY, 3, 9, 1, 1, scale);
    ofSetColor(255, 255, 255);
    rectangle(startX, startY, 4, 11, 1, 1, scale);
    rectangle(startX, startY, 6, 10, 1, 2, scale);
    return 6 * scale;
}

double upperR(double startX, double startY, double scale) {
    doubleRect(startX, startY, 0, 3, 1, 8, scale);
    doubleRect(startX, startY, 1, 3, 3, 1, scale);
    doubleRect(startX, startY, 1, 7, 2, 1, scale);
    doubleRect(startX, startY, 4, 4, 1, 3, scale);
    doubleRect(startX, startY, 3, 7, 1, 2, scale);
    doubleRect(startX, startY, 4, 9, 1, 2, scale);
    return 6 * scale;
}

double upperS(double startX, double startY, double scale) {
    doubleRect(startX, startY, 1, 3, 3, 1, scale);
    doubleRect(startX, startY, 4, 4, 1, 1, scale);
    doubleRect(startX, startY, 0, 4, 1, 2, scale);
    doubleRect(startX, startY, 1, 6, 2, 1, scale);
    doubleRect(startX, startY, 3, 7, 1, 1, scale);
    doubleRect(startX, startY, 4, 8, 1, 2, scale);
    doubleRect(startX, startY, 0, 9, 1, 1, scale);
    doubleRect(startX, startY, 1, 10, 3, 1, scale);
    ofSetColor(255, 255, 255);
    rectangle(startX, startY, 4, 5, 2, 1, scale);
    rectangle(startX, startY, 3, 8, 1, 1, scale);
    return 6 * scale;
}

double upperT(double startX, double startY, double scale) {
    doubleRect(startX, startY, 0, 3, 5, 1, scale);
    doubleRect(startX, startY, 2, 4, 1, 7, scale);
    return 6 * scale;
}

double upperU(double startX, double startY, double scale) {
    doubleRect(startX, startY, 0, 3, 1, 7, scale);
    doubleRect(startX, startY, 4, 3, 1, 7, scale);
    doubleRect(startX, startY, 1, 10, 3, 1, scale);
    return 6 * scale;
}

double upperV(double startX, double startY, double scale) {
    doubleRect(startX, startY, 0, 3, 1, 4, scale);
    doubleRect(startX, startY, 1, 7, 1, 2, scale);
    doubleRect(startX, startY, 2, 9, 1, 2, scale);
    doubleRect(startX, startY, 3, 7, 1, 2, scale);
    doubleRect(startX, startY, 4, 3, 1, 4, scale);
    return 6 * scale;
}

double upperW(double startX, double startY, double scale) {
    doubleRect(startX, startY, 0, 3, 1, 8, scale);
    doubleRect(startX, startY, 1, 8, 1, 2, scale);
    doubleRect(startX, startY, 2, 5, 1, 3, scale);
    doubleRect(startX, startY, 3, 8, 1, 2, scale);
    doubleRect(startX, startY, 4, 3, 1, 8, scale);
    return 6 * scale;
}

double upperX(double startX, double startY, double scale) {
    doubleRect(startX, startY, 0, 3, 1, 2, scale);
    doubleRect(startX, startY, 0, 9, 1, 2, scale);
    doubleRect(startX, startY, 1, 5, 1, 1, scale);
    doubleRect(startX, startY, 1, 8, 1, 1, scale);
    doubleRect(startX, startY, 2, 6, 1, 2, scale);
    doubleRect(startX, startY, 3, 5, 1, 1, scale);
    doubleRect(startX, startY, 3, 8, 1, 1, scale);
    doubleRect(startX, startY, 4, 3, 1, 2, scale);
    doubleRect(startX, startY, 4, 9, 1, 2, scale);
    ofSetColor(255, 255, 255);
    rectangle(startX, startY, 2, 9, 1, 1, scale);
    rectangle(startX, startY, 0, 5, 1, 1, scale);
    return 6 * scale;
}

double upperY(double startX, double startY, double scale) {
    doubleRect(startX, startY, 0, 3, 1, 2, scale);
    doubleRect(startX, startY, 1, 5, 1, 2, scale);
    doubleRect(startX, startY, 2, 7, 1, 4, scale);
    doubleRect(startX, startY, 3, 5, 1, 2, scale);
    doubleRect(startX, startY, 4, 3, 1, 2, scale);
    return 6 * scale;
}

double upperZ(double startX, double startY, double scale) {
    doubleRect(startX, startY, 0, 3, 4, 1, scale);
    doubleRect(startX, startY, 4, 3, 1, 2, scale);
    doubleRect(startX, startY, 0, 9, 1, 2, scale);
    doubleRect(startX, startY, 1, 8, 1, 1, scale);
    doubleRect(startX, startY, 2, 6, 1, 2, scale);
    doubleRect(startX, startY, 3, 5, 1, 1, scale);
    doubleRect(startX, startY, 1, 10, 4, 1, scale);
    return 6 * scale;
}



// LOWER LETTERS

double lowerA(double startX, double startY, double scale) {
    doubleRect(startX, startY, 0, 7, 1, 3, scale);
    doubleRect(startX, startY, 1, 10, 2, 1, scale);
    doubleRect(startX, startY, 1, 6, 4, 1, scale);
    doubleRect(startX, startY, 4, 7, 1, 4, scale);
    rectangle(startX, startY, 3, 9, 1, 1, scale);
    ofSetColor(255, 255, 255);
    rectangle(startX, startY, 3, 11, 1, 1, scale);
    return 6 * scale;
}

double lowerB(double startX, double startY, double scale) {
    doubleRect(startX, startY, 0, 3, 1, 8, scale);
    doubleRect(startX, startY, 1, 6, 3, 1, scale);
    doubleRect(startX, startY, 1, 10, 3, 1, scale);
    doubleRect(startX, startY, 4, 7, 1, 3, scale);
    return 6 * scale;
}

double lowerC(double startX, double startY, double scale) {
    doubleRect(startX, startY, 1, 6, 3, 1, scale);
    doubleRect(startX, startY, 0, 7, 1, 3, scale);
    doubleRect(startX, startY, 1, 10, 3, 1, scale);
    doubleRect(startX, startY, 4, 9, 1, 1, scale);
    rectangle(startX, startY, 4, 7, 1, 1, scale);
    setTextColor2();
    rectangle(startX, startY, 5, 7, 1, 1, scale);
    return 6 * scale;
}

double lowerD(double startX, double startY, double scale) {
    doubleRect(startX, startY, 0, 7, 1, 3, scale);
    doubleRect(startX, startY, 1, 6, 3, 1, scale);
    doubleRect(startX, startY, 1, 10, 3, 1, scale);
    doubleRect(startX, startY, 4, 3, 1, 8, scale);
    return 6 * scale;
}

double lowerE(double startX, double startY, double scale) {
    doubleRect(startX, startY, 1, 6, 3, 1, scale);
    doubleRect(startX, startY, 0, 7, 1, 3, scale);
    doubleRect(startX, startY, 1, 8, 3, 1, scale);
    doubleRect(startX, startY, 1, 10, 4, 1, scale);
    doubleRect(startX, startY, 4, 7, 1, 2, scale);
    ofSetColor(255, 255, 255);
    rectangle(startX, startY, 5, 9, 1, 1, scale);
    rectangle(startX, startY, 5, 11, 1, 1, scale);
    return 6 * scale;
}

double lowerF(double startX, double startY, double scale) {
    doubleRect(startX, startY, 2, 3, 2, 1, scale);
    doubleRect(startX, startY, 1, 4, 1, 7, scale);
    doubleRect(startX, startY, 0, 6, 4, 1, scale);
    rectangle(startX, startY, 1, 7, 1, 1, scale);
    ofSetColor(255, 255, 255);
    rectangle(startX, startY, 4, 4, 1, 1, scale);
    return 5 * scale;
}

double lowerG(double startX, double startY, double scale) {
    doubleRect(startX, startY, 0, 7, 1, 3, scale);
    doubleRect(startX, startY, 1, 6, 3, 1, scale);
    doubleRect(startX, startY, 1, 10, 3, 1, scale);
    doubleRect(startX, startY, 1, 12, 3, 1, scale);
    doubleRect(startX, startY, 4, 7, 1, 5, scale);
    return 6 * scale;
}

double lowerH(double startX, double startY, double scale) {
    doubleRect(startX, startY, 0, 3, 1, 8, scale);
    doubleRect(startX, startY, 1, 6, 3, 1, scale);
    doubleRect(startX, startY, 4, 7, 1, 4, scale);
    return 6 * scale;
}

double lowerI(double startX, double startY, double scale) {
    doubleRect(startX, startY, 1, 3, 1, 1, scale);
    doubleRect(startX, startY, 1, 6, 1, 5, scale);
    return 4 * scale;
}

double lowerJ(double startX, double startY, double scale) {
    doubleRect(startX, startY, 3, 3, 1, 1, scale);
    doubleRect(startX, startY, 3, 6, 1, 6, scale);
    doubleRect(startX, startY, 0, 10, 1, 2, scale);
    doubleRect(startX, startY, 1, 12, 2, 1, scale);
    return 5 * scale;
}

double lowerK(double startX, double startY, double scale) {
    doubleRect(startX, startY, 0, 3, 1, 8, scale);
    doubleRect(startX, startY, 1, 8, 1, 1, scale);
    doubleRect(startX, startY, 2, 7, 1, 1, scale);
    doubleRect(startX, startY, 3, 6, 1, 1, scale);
    doubleRect(startX, startY, 2, 9, 1, 1, scale);
    doubleRect(startX, startY, 3, 10, 1, 1, scale);
    ofSetColor(255, 255, 255);
    rectangle(startX, startY, 3, 8, 1, 1, scale);
    rectangle(startX, startY, 4, 7, 1, 1, scale);
    return 5 * scale;
}

double lowerL(double startX, double startY, double scale) { 
    doubleRect(startX, startY, 0, 3, 1, 1, scale);
    doubleRect(startX, startY, 1, 3, 1, 8, scale);
    return 4 * scale;
}

double lowerM(double startX, double startY, double scale) {
    doubleRect(startX, startY, 0, 6, 1, 5, scale);
    doubleRect(startX, startY, 2, 6, 1, 5, scale);
    doubleRect(startX, startY, 3, 6, 1, 1, scale);
    doubleRect(startX, startY, 4, 7, 1, 4, scale);
    rectangle(startX, startY, 1, 6, 1, 1, scale);
    ofSetColor(255, 255, 255);
    rectangle(startX, startY, 1, 11, 1, 1, scale);
    rectangle(startX, startY, 3, 11, 1, 1, scale);
    return 6 * scale;
}

double lowerN(double startX, double startY, double scale) {
    doubleRect(startX, startY, 0, 6, 1, 5, scale);
    doubleRect(startX, startY, 1, 6, 2, 1, scale);
    doubleRect(startX, startY, 3, 7, 1, 4, scale);
    return 5 * scale;
}

double lowerO(double startX, double startY, double scale) {
    doubleRect(startX, startY, 0, 7, 1, 3, scale);
    doubleRect(startX, startY, 1, 6, 3, 1, scale);
    doubleRect(startX, startY, 1, 10, 3, 1, scale);
    doubleRect(startX, startY, 4, 7, 1, 3, scale);
    return 6 * scale;
}

double lowerP(double startX, double startY, double scale) {
    doubleRect(startX, startY, 0, 6, 1, 7, scale);
    doubleRect(startX, startY, 1, 6, 3, 1, scale);
    doubleRect(startX, startY, 1, 10, 3, 1, scale);
    doubleRect(startX, startY, 4, 7, 1, 3, scale);
    return 6 * scale;
}

double lowerQ(double startX, double startY, double scale) {
    doubleRect(startX, startY, 0, 7, 1, 3, scale);
    doubleRect(startX, startY, 1, 6, 3, 1, scale);
    doubleRect(startX, startY, 1, 10, 3, 1, scale);
    doubleRect(startX, startY, 4, 6, 1, 7, scale);
    return 6 * scale;
}

double lowerR(double startX, double startY, double scale) {
    doubleRect(startX, startY, 0, 6, 1, 5, scale);
    doubleRect(startX, startY, 2, 6, 2, 1, scale);
    doubleRect(startX, startY, 1, 7, 1, 1, scale);
    return 5 * scale;
}

double lowerS(double startX, double startY, double scale) {
    doubleRect(startX, startY, 0, 6, 1, 2, scale);
    doubleRect(startX, startY, 1, 6, 3, 1, scale);
    doubleRect(startX, startY, 1, 8, 2, 1, scale);
    doubleRect(startX, startY, 0, 10, 3, 1, scale);
    doubleRect(startX, startY, 3, 9, 1, 2, scale);
    return 5 * scale;
}

double lowerT(double startX, double startY, double scale) {
    doubleRect(startX, startY, 1, 4, 1, 2, scale);
    doubleRect(startX, startY, 0, 6, 4, 1, scale);
    doubleRect(startX, startY, 1, 7, 1, 4, scale);
    doubleRect(startX, startY, 2, 10, 2, 1, scale);
    return 5 * scale;
}

double lowerU(double startX, double startY, double scale) {
    doubleRect(startX, startY, 0, 6, 1, 4, scale);
    doubleRect(startX, startY, 1, 10, 2, 1, scale);
    doubleRect(startX, startY, 3, 6, 1, 4, scale);
    doubleRect(startX, startY, 4, 10, 1, 1, scale);
    ofSetColor(255, 255, 255);
    rectangle(startX, startY, 3, 11, 1, 1, scale);
    rectangle(startX, startY, 5, 10, 1, 2, scale);
    return 5 * scale;
}

double lowerV(double startX, double startY, double scale) {
    doubleRect(startX, startY, 0, 6, 1, 2, scale);
    doubleRect(startX, startY, 1, 8, 1, 2, scale);
    doubleRect(startX, startY, 2, 10, 1, 1, scale);
    doubleRect(startX, startY, 3, 8, 1, 2, scale);
    doubleRect(startX, startY, 4, 6, 1, 2, scale);
    return 6 * scale;
}

double lowerW(double startX, double startY, double scale) {
    doubleRect(startX, startY, 0, 6, 1, 4, scale);
    doubleRect(startX, startY, 1, 10, 1, 1, scale);
    doubleRect(startX, startY, 2, 6, 1, 4, scale);
    doubleRect(startX, startY, 3, 10, 1, 1, scale);
    doubleRect(startX, startY, 4, 6, 1, 4, scale);
    return 6 * scale;
}

double lowerX(double startX, double startY, double scale) {
    doubleRect(startX, startY, 0, 6, 1, 1, scale);
    doubleRect(startX, startY, 1, 7, 1, 1, scale);
    doubleRect(startX, startY, 2, 8, 1, 1, scale);
    doubleRect(startX, startY, 3, 9, 1, 1, scale);
    doubleRect(startX, startY, 4, 10, 1, 1, scale);
    doubleRect(startX, startY, 0, 10, 1, 1, scale);
    doubleRect(startX, startY, 4, 6, 1, 1, scale);
    rectangle(startX, startY, 1, 9, 1, 1, scale);
    rectangle(startX, startY, 3, 7, 1, 1, scale);
    return 6 * scale;
}

double lowerY(double startX, double startY, double scale) {
    doubleRect(startX, startY, 0, 6, 1, 4, scale);
    doubleRect(startX, startY, 1, 10, 3, 1, scale);
    doubleRect(startX, startY, 1, 12, 3, 1, scale);
    doubleRect(startX, startY, 4, 6, 1, 6, scale);
    rectangle(startX, startY, 0, 12, 1, 1, scale);
    return 6 * scale;
}

double lowerZ(double startX, double startY, double scale) {
    doubleRect(startX, startY, 0, 6, 5, 1, scale);
    doubleRect(startX, startY, 3, 7, 1, 1, scale);
    doubleRect(startX, startY, 2, 8, 1, 1, scale);
    rectangle(startX, startY, 1, 9, 1, 1, scale);
    doubleRect(startX, startY, 0, 10, 5, 1, scale);
    return 6 * scale;
}



// NUMBERS

double number0(double startX, double startY, double scale) {
    doubleRect(startX, startY, 0, 3, 1, 7, scale);
    doubleRect(startX, startY, 1, 2, 3, 1, scale);
    doubleRect(startX, startY, 1, 10, 3, 1, scale);
    doubleRect(startX, startY, 4, 3, 1, 7, scale);
    return 6 * scale;
}

double number1(double startX, double startY, double scale) {
    doubleRect(startX, startY, 0, 3, 1, 1, scale);
    doubleRect(startX, startY, 1, 2, 1, 8, scale);
    doubleRect(startX, startY, 0, 10, 3, 1, scale);
    return 3 * scale;
}

double number2(double startX, double startY, double scale) {
    doubleRect(startX, startY, 0, 3, 1, 2, scale);
    doubleRect(startX, startY, 1, 2, 3, 1, scale);
    doubleRect(startX, startY, 4, 3, 1, 3, scale);
    doubleRect(startX, startY, 3, 6, 1, 1, scale);
    doubleRect(startX, startY, 2, 7, 1, 1, scale);
    doubleRect(startX, startY, 1, 8, 1, 1, scale);
    doubleRect(startX, startY, 0, 9, 1, 2, scale);
    doubleRect(startX, startY, 1, 10, 4, 1, scale);
    return 6 * scale;
}

double number3(double startX, double startY, double scale) {
    doubleRect(startX, startY, 0, 3, 1, 1, scale);
    doubleRect(startX, startY, 1, 2, 3, 1, scale);
    doubleRect(startX, startY, 4, 3, 1, 3, scale);
    doubleRect(startX, startY, 2, 6, 2, 1, scale);
    doubleRect(startX, startY, 4, 7, 1, 3, scale);
    doubleRect(startX, startY, 0, 9, 1, 1, scale);
    doubleRect(startX, startY, 1, 10, 3, 1, scale);
    ofSetColor(255, 255, 255);
    rectangle(startX, startY, 1, 9, 1, 1, scale);
    rectangle(startX, startY, 5, 6, 1, 1, scale);
    return 6 * scale;
}

double number4(double startX, double startY, double scale) {
    doubleRect(startX, startY, 1, 3, 1, 2, scale);
    doubleRect(startX, startY, 0, 5, 1, 3, scale);
    doubleRect(startX, startY, 0, 8, 5, 1, scale);
    doubleRect(startX, startY, 3, 2, 1, 9, scale);
    rectangle(startX, startY, 2, 2, 1, 1, scale);
    rectangle(startX, startY, 4, 8, 1, 1, scale);
    return 6 * scale;
}

double number5(double startX, double startY, double scale) {
    doubleRect(startX, startY, 0, 2, 5, 1, scale);
    doubleRect(startX, startY, 0, 3, 1, 4, scale);
    doubleRect(startX, startY, 1, 6, 3, 1, scale);
    doubleRect(startX, startY, 4, 7, 1, 3, scale);
    doubleRect(startX, startY, 0, 9, 1, 1, scale);
    doubleRect(startX, startY, 1, 10, 3, 1, scale);
    ofSetColor(255, 255, 255);
    rectangle(startX, startY, 1, 9, 3, 1, scale);
    return 6 * scale;
}

double number6(double startX, double startY, double scale) {
    doubleRect(startX, startY, 1, 2, 3, 1, scale);
    doubleRect(startX, startY, 4, 3, 1, 1, scale);
    doubleRect(startX, startY, 0, 3, 1, 7, scale);
    doubleRect(startX, startY, 1, 6, 3, 1, scale);
    doubleRect(startX, startY, 1, 10, 3, 1, scale);
    doubleRect(startX, startY, 4, 7, 1, 3, scale);
    return 6 * scale;
}

double number7(double startX, double startY, double scale) {
    doubleRect(startX, startY, 0, 2, 5, 1, scale);
    doubleRect(startX, startY, 4, 3, 1, 3, scale);
    doubleRect(startX, startY, 3, 6, 1, 2, scale);
    doubleRect(startX, startY, 2, 8, 1, 3, scale);
    return 6 * scale;
}

double number8(double startX, double startY, double scale) {
    doubleRect(startX, startY, 0, 3, 1, 3, scale);
    doubleRect(startX, startY, 0, 7, 1, 3, scale);
    doubleRect(startX, startY, 1, 2, 3, 1, scale);
    doubleRect(startX, startY, 1, 6, 3, 1, scale);
    doubleRect(startX, startY, 1, 10, 3, 1, scale);
    doubleRect(startX, startY, 4, 3, 1, 3, scale);
    doubleRect(startX, startY, 4, 7, 1, 3, scale);
    ofSetColor(255, 255, 255);
    rectangle(startX, startY, 5, 6, 1, 1, scale);
    return 6 * scale;
}

double number9(double startX, double startY, double scale) {
    doubleRect(startX, startY, 0, 3, 1, 3, scale);
    doubleRect(startX, startY, 0, 9, 1, 1, scale);
    doubleRect(startX, startY, 1, 2, 3, 1, scale);
    doubleRect(startX, startY, 1, 6, 3, 1, scale);
    doubleRect(startX, startY, 1, 10, 3, 1, scale);
    doubleRect(startX, startY, 4, 3, 1, 7, scale);
    ofSetColor(255, 255, 255);
    rectangle(startX, startY, 0, 6, 1, 1, scale);
    return 6 * scale;
}



// OTHER

double whitespace(double startX, double startY, double scale) {
    return 4 * scale;
}

double exclamationMark(double startX, double startY, double scale) {
    doubleRect(startX, startY, 1, 1, 1, 10, scale);
    ofSetColor(255, 255, 255);
    rectangle(startX, startY, 1, 8, 2, 1, scale);
    return 5 * scale;
}

double questionMark(double startX, double startY, double scale) {
    doubleRect(startX, startY, 0, 2, 1, 2, scale);
    doubleRect(startX, startY, 1, 1, 3, 1, scale);
    doubleRect(startX, startY, 4, 2, 1, 3, scale);
    doubleRect(startX, startY, 2, 6, 1, 5, scale);
    doubleRect(startX, startY, 3, 5, 1, 1, scale);
    ofSetColor(255, 255, 255);
    rectangle(startX, startY, 2, 8, 2, 1, scale);
    return 7 * scale;
}

double periodMark(double startX, double startY, double scale) {
    doubleRect(startX, startY, 0, 9, 2, 2, scale);
    return 6 * scale;
}

double dashMark(double startX, double startY, double scale) {
    doubleRect(startX, startY, 1, 6, 5, 1, scale);
    return 7 * scale;
}

double midPointMark(double startX, double startY, double scale) {
    doubleRect(startX, startY, 1, 6, 2, 2, scale);
    return 4 * scale;
}

double threePoints(double startX, double startY, double scale) {
    doubleRect(startX, startY, 0, 10, 5, 1, scale);
    setTextColor2();
    rectangle(startX, startY, 1, 10, 1, 1, scale);
    rectangle(startX, startY, 3, 10, 1, 1, scale);
    return 4 * scale;
}

double leftQuotes(double startX, double startY, double scale) {
    doubleRect(startX, startY, 0, 1, 2, 3, scale);
    doubleRect(startX, startY, 1, 0, 1, 1, scale);
    doubleRect(startX, startY, 3, 1, 2, 3, scale);
    doubleRect(startX, startY, 4, 0, 1, 1, scale);
    ofSetColor(255, 255, 255);
    rectangle(startX, startY, 2, 1, 1, 1, scale);
    rectangle(startX, startY, 5, 1, 1, 1, scale);
    return 6 * scale;
}

double rightQuotes(double startX, double startY, double scale) {
    doubleRect(startX, startY, 0, 0, 5, 3, scale);
    doubleRect(startX, startY, 0, 3, 1, 1, scale);
    doubleRect(startX, startY, 3, 3, 1, 1, scale);
    setTextColor2();
    rectangle(startX, startY, 2, 0, 1, 3, scale);
    rectangle(startX, startY, 0, 2, 1, 1, scale);
    rectangle(startX, startY, 3, 2, 1, 1, scale);
    return 6 * scale;
}

double leftApostrophe(double startX, double startY, double scale) {
    doubleRect(startX, startY, 0, 1, 2, 3, scale);
    doubleRect(startX, startY, 1, 0, 1, 1, scale);
    ofSetColor(255, 255, 255);
    rectangle(startX, startY, 0, 0, 1, 1, scale);
    rectangle(startX, startY, 2, 1, 1, 1, scale);
    return 3 * scale;
}

double rightApostrophe(double startX, double startY, double scale) {
    doubleRect(startX, startY, 0, 0, 2, 2, scale);
    doubleRect(startX, startY, 1, 2, 1, 1, scale);
    doubleRect(startX, startY, 0, 3, 1, 1, scale);
    return 3 * scale;
}

double maleSymbol(double startX, double startY, double scale) {
    doubleRect(startX, startY, 0, 3, 1, 1, scale);
    doubleRect(startX, startY, 2, 1, 1, 5, scale);
    doubleRect(startX, startY, 4, 3, 1, 1, scale);
    doubleRect(startX, startY, 0, 7, 1, 3, scale);
    doubleRect(startX, startY, 1, 6, 3, 1, scale);
    doubleRect(startX, startY, 1, 10, 3, 1, scale);
    doubleRect(startX, startY, 4, 7, 1, 3, scale);
    rectangle(startX, startY, 1, 2, 1, 1, scale);
    rectangle(startX, startY, 3, 2, 1, 1, scale);
    return 6 * scale;
}

double femaleSymbol(double startX, double startY, double scale) {
    doubleRect(startX, startY, 0, 2, 1, 3, scale);
    doubleRect(startX, startY, 1, 1, 3, 1, scale);
    doubleRect(startX, startY, 1, 5, 3, 1, scale);
    doubleRect(startX, startY, 4, 2, 1, 3, scale);
    doubleRect(startX, startY, 0, 7, 5, 1, scale);
    doubleRect(startX, startY, 2, 8, 1, 3, scale);
    rectangle(startX, startY, 2, 6, 1, 1, scale);
    return 6 * scale;
}

double genderlessSymbol(double startX, double startY, double scale) {
    doubleRect(startX, startY, 1, 1, 1, 6, scale);
    doubleRect(startX, startY, 2, 1, 2, 1, scale);
    doubleRect(startX, startY, 2, 5, 1, 1, scale);
    doubleRect(startX, startY, 4, 2, 1, 3, scale);
    doubleRect(startX, startY, 0, 7, 5, 1, scale);
    doubleRect(startX, startY, 0, 9, 5, 1, scale);
    doubleRect(startX, startY, 1, 10, 1, 1, scale);
    rectangle(startX, startY, 3, 5, 1, 1, scale);
    rectangle(startX, startY, 1, 8, 1, 1, scale);
    return 6 * scale;
}

double commaMark(double startX, double startY, double scale) {
    doubleRect(startX, startY, 0, 9, 2, 2, scale);
    doubleRect(startX, startY, 1, 11, 1, 1, scale);
    doubleRect(startX, startY, 0, 12, 1, 1, scale);
    return 3 * scale;
}

double multiplySymbol(double startX, double startY, double scale) {
    doubleRect(startX, startY, 0, 4, 1, 1, scale);
    doubleRect(startX, startY, 1, 5, 1, 1, scale);
    doubleRect(startX, startY, 2, 6, 2, 2, scale);
    doubleRect(startX, startY, 1, 8, 1, 1, scale);
    doubleRect(startX, startY, 0, 9, 1, 1, scale);
    doubleRect(startX, startY, 4, 5, 1, 1, scale);
    doubleRect(startX, startY, 4, 8, 1, 1, scale);
    doubleRect(startX, startY, 5, 4, 1, 1, scale);
    doubleRect(startX, startY, 5, 9, 1, 1, scale);
    return 7 * scale;
}

double divisionSymbol(double startX, double startY, double scale) {
    doubleRect(startX, startY, 0, 9, 1, 2, scale);
    doubleRect(startX, startY, 1, 7, 1, 2, scale);
    doubleRect(startX, startY, 2, 5, 1, 2, scale);
    doubleRect(startX, startY, 3, 3, 1, 2, scale);
    doubleRect(startX, startY, 4, 1, 1, 2, scale);
    return 6 * scale;
}

double specialE(double startX, double startY, double scale) {
    doubleRect(startX, startY, 2, 3, 2, 1, scale);
    rectangle(startX, startY, 1, 4, 1, 1, scale);
    ofSetColor(255, 255, 255);
    rectangle(startX, startY, 4, 4, 1, 1, scale);
    lowerE(startX, startY, scale);
    return 6 * scale;
}

double ampersandSymbol(double startX, double startY, double scale) {
    doubleRect(startX, startY, 2, 2, 1, 1, scale);
    doubleRect(startX, startY, 1, 3, 1, 2, scale);
    doubleRect(startX, startY, 3, 3, 1, 2, scale);
    doubleRect(startX, startY, 2, 5, 1, 2, scale);
    doubleRect(startX, startY, 1, 7, 1, 1, scale);
    doubleRect(startX, startY, 0, 8, 1, 2, scale);
    doubleRect(startX, startY, 1, 10, 2, 1, scale);
    doubleRect(startX, startY, 3, 7, 1, 3, scale);
    doubleRect(startX, startY, 4, 6, 1, 1, scale);
    doubleRect(startX, startY, 4, 10, 1, 1, scale);
    ofSetColor(255, 255, 255);
    rectangle(startX, startY, 4, 5, 1, 1, scale);
    rectangle(startX, startY, 3, 11, 1, 1, scale);
    return 6 * scale;
}

double additionSymbol(double startX, double startY, double scale) {
    doubleRect(startX, startY, 0, 7, 2, 1, scale);
    doubleRect(startX, startY, 2, 5, 1, 5, scale);
    doubleRect(startX, startY, 3, 7, 2, 1, scale);
    return 6 * scale;
}

double levelSymbol(double startX, double startY, double scale) {
    doubleRect(startX, startY, 0, 4, 1, 7, scale);
    doubleRect(startX, startY, 1, 10, 2, 1, scale);
    lowerV(startX + (4 * scale), startY, scale);
    return 10 * scale;
}

double equalSign(double startX, double startY, double scale) {
    doubleRect(startX, startY, 0, 4, 5, 1, scale);
    doubleRect(startX, startY, 0, 7, 5, 1, scale);
    return 6 * scale;
}

double semiColonMark(double startX, double startY, double scale) {
    doubleRect(startX, startY, 0, 3, 2, 2, scale);
    doubleRect(startX, startY, 0, 7, 2, 2, scale);
    doubleRect(startX, startY, 1, 9, 1, 1, scale);
    doubleRect(startX, startY, 0, 10, 1, 1, scale);
    return 6 * scale;
}

double percentageSymbol(double startX, double startY, double scale) {
    doubleRect(startX, startY, 0, 2, 3, 4, scale);
    doubleRect(startX, startY, 1, 10, 1, 2, scale);
    doubleRect(startX, startY, 2, 8, 1, 2, scale);
    doubleRect(startX, startY, 3, 6, 1, 2, scale);
    doubleRect(startX, startY, 4, 4, 1, 2, scale);
    doubleRect(startX, startY, 5, 2, 1, 2, scale);
    doubleRect(startX, startY, 4, 8, 3, 4, scale);
    setTextColor2();
    rectangle(startX, startY, 1, 3, 1, 2, scale);
    rectangle(startX, startY, 5, 9, 1, 2, scale);
    ofSetColor(255, 255, 255);
    rectangle(startX, startY, 3, 10, 1, 1, scale);
    return 6 * scale;
}

double upArrow(double startX, double startY, double scale) {
    doubleRect(startX, startY, 0, 4, 2, 1, scale);
    rectangle(startX, startY, 1, 3, 1, 1, scale);
    doubleRect(startX, startY, 2, 2, 5, 6, scale);
    rectangle(startX, startY, 3, 1, 3, 1, scale);
    rectangle(startX, startY, 4, 0, 1, 1, scale);
    doubleRect(startX, startY, 7, 3, 1, 2, scale);
    doubleRect(startX, startY, 8, 4, 1, 1, scale);
    setTextColor2();
    rectangle(startX, startY, 5, 0, 1, 1, scale);
    rectangle(startX, startY, 6, 1, 1, 1, scale);
    rectangle(startX, startY, 7, 2, 1, 1, scale);
    return 10 * scale;
}

double downArrow(double startX, double startY, double scale) {
    doubleRect(startX, startY, 4, 8, 1, 1, scale);
    doubleRect(startX, startY, 5, 7, 1, 1, scale);
    doubleRect(startX, startY, 6, 6, 1, 1, scale);
    doubleRect(startX, startY, 7, 5, 1, 1, scale);
    doubleRect(startX, startY, 8, 4, 1, 1, scale);
    rectangle(startX, startY, 7, 4, 1, 1, scale);
    rectangle(startX, startY, 2, 1, 5, 6, scale);
    rectangle(startX, startY, 3, 7, 2, 1, scale);
    rectangle(startX, startY, 0, 4, 1, 1, scale);
    rectangle(startX, startY, 1, 4, 1, 2, scale);
    setTextColor2();
    rectangle(startX, startY, 0, 5, 1, 1, scale);
    rectangle(startX, startY, 1, 6, 1, 1, scale);
    rectangle(startX, startY, 2, 7, 1, 1, scale);
    rectangle(startX, startY, 3, 8, 1, 1, scale);
    rectangle(startX, startY, 7, 1, 1, 3, scale);
    return 10 * scale;
}

double leftArrow(double startX, double startY, double scale) {
    doubleRect(startX, startY, 4, 0, 1, 2, scale);
    rectangle(startX, startY, 3, 1, 1, 1, scale);
    doubleRect(startX, startY, 2, 2, 6, 5, scale);
    rectangle(startX, startY, 1, 3, 1, 3, scale);
    rectangle(startX, startY, 0, 4, 1, 1, scale);
    rectangle(startX, startY, 3, 7, 1, 1, scale);
    doubleRect(startX, startY, 4, 7, 1, 2, scale);
    setTextColor2();
    rectangle(startX, startY, 0, 5, 1, 1, scale);
    rectangle(startX, startY, 1, 6, 1, 1, scale);
    rectangle(startX, startY, 2, 7, 1, 1, scale);
    rectangle(startX, startY, 3, 8, 1, 1, scale);
    return 9 * scale;
}

double rightArrow(double startX, double startY, double scale) {
    doubleRect(startX, startY, 0, 2, 6, 5, scale);
    rectangle(startX, startY, 3, 0, 1, 1, scale);
    rectangle(startX, startY, 3, 1, 2, 1, scale);
    doubleRect(startX, startY, 6, 3, 1, 3, scale);
    doubleRect(startX, startY, 7, 4, 1, 1, scale);
    doubleRect(startX, startY, 3, 7, 1, 2, scale);
    doubleRect(startX, startY, 4, 7, 1, 1, scale);
    setTextColor2();
    rectangle(startX, startY, 4, 0, 1, 1, scale);
    rectangle(startX, startY, 5, 1, 1, 1, scale);
    rectangle(startX, startY, 6, 2, 1, 1, scale);
    return 9 * scale;
}

double nextLineSymbol(double startX, double startY, double scale) {
    ofSetColor(94, 94, 94);
    rectangle(startX, startY, 0, 4, 1, 3, scale);
    rectangle(startX, startY, 1, 4, 6, 1, scale);
    rectangle(startX, startY, 1, 7, 1, 1, scale);
    rectangle(startX, startY, 2, 8, 1, 1, scale);
    rectangle(startX, startY, 3, 9, 1, 1, scale);
    rectangle(startX, startY, 4, 8, 1, 1, scale);
    rectangle(startX, startY, 5, 7, 1, 1, scale);
    rectangle(startX, startY, 6, 5, 1, 2, scale);
    ofSetColor(210, 0, 0);
    rectangle(startX, startY, 1, 5, 5, 1, scale);
    ofSetColor(228, 0, 0);
    rectangle(startX, startY, 1, 6, 5, 1, scale);
    ofSetColor(255, 0, 0);
    rectangle(startX, startY, 2, 7, 3, 1, scale);
    rectangle(startX, startY, 3, 8, 1, 1, scale);
    return 6 * scale;
}



// Storing text functions as pointers

void Text::setFunctions() {
    textFunctionsList['A'] = upperA;
    textFunctionsList['B'] = upperB;
    textFunctionsList['C'] = upperC;
    textFunctionsList['D'] = upperD;
    textFunctionsList['E'] = upperE;
    textFunctionsList['F'] = upperF;
    textFunctionsList['G'] = upperG;
    textFunctionsList['H'] = upperH;
    textFunctionsList['I'] = upperI;
    textFunctionsList['J'] = upperJ;
    textFunctionsList['K'] = upperK;
    textFunctionsList['L'] = upperL;
    textFunctionsList['M'] = upperM;
    textFunctionsList['N'] = upperN;
    textFunctionsList['O'] = upperO;
    textFunctionsList['P'] = upperP;
    textFunctionsList['Q'] = upperQ;
    textFunctionsList['R'] = upperR;
    textFunctionsList['S'] = upperS;
    textFunctionsList['T'] = upperT;
    textFunctionsList['U'] = upperU;
    textFunctionsList['V'] = upperV;
    textFunctionsList['W'] = upperW;
    textFunctionsList['X'] = upperX;
    textFunctionsList['Y'] = upperY;
    textFunctionsList['Z'] = upperZ;
    textFunctionsList['a'] = lowerA;
    textFunctionsList['b'] = lowerB;
    textFunctionsList['c'] = lowerC;
    textFunctionsList['d'] = lowerD;
    textFunctionsList['e'] = lowerE;
    textFunctionsList['f'] = lowerF;
    textFunctionsList['g'] = lowerG;
    textFunctionsList['h'] = lowerH;
    textFunctionsList['i'] = lowerI;
    textFunctionsList['j'] = lowerJ;
    textFunctionsList['k'] = lowerK;
    textFunctionsList['l'] = lowerL;
    textFunctionsList['m'] = lowerM;
    textFunctionsList['n'] = lowerN;
    textFunctionsList['o'] = lowerO;
    textFunctionsList['p'] = lowerP;
    textFunctionsList['q'] = lowerQ;
    textFunctionsList['r'] = lowerR;
    textFunctionsList['s'] = lowerS;
    textFunctionsList['t'] = lowerT;
    textFunctionsList['u'] = lowerU;
    textFunctionsList['v'] = lowerV;
    textFunctionsList['w'] = lowerW;
    textFunctionsList['x'] = lowerX;
    textFunctionsList['y'] = lowerY;
    textFunctionsList['z'] = lowerZ;
    textFunctionsList['0'] = number0;
    textFunctionsList['1'] = number1;
    textFunctionsList['2'] = number2;
    textFunctionsList['3'] = number3;
    textFunctionsList['4'] = number4;
    textFunctionsList['5'] = number5;
    textFunctionsList['6'] = number6;
    textFunctionsList['7'] = number7;
    textFunctionsList['8'] = number8;
    textFunctionsList['9'] = number9;
    textFunctionsList[' '] = whitespace;
    textFunctionsList['!'] = exclamationMark;
    textFunctionsList['?'] = questionMark;
    textFunctionsList['.'] = periodMark;
    textFunctionsList['-'] = dashMark;
    textFunctionsList['_'] = threePoints;
    textFunctionsList['{'] = leftQuotes;
    textFunctionsList['}'] = rightQuotes;
    textFunctionsList['['] = leftApostrophe;
    textFunctionsList[']'] = rightApostrophe;
    textFunctionsList['\''] = maleSymbol;
    textFunctionsList['"'] = femaleSymbol;
    textFunctionsList['|'] = genderlessSymbol;
    textFunctionsList[','] = commaMark;
    textFunctionsList['*'] = multiplySymbol;
    textFunctionsList['/'] = divisionSymbol;
    textFunctionsList['~'] = specialE;
    textFunctionsList['&'] = ampersandSymbol;
    textFunctionsList['+'] = leftApostrophe;
    textFunctionsList['^'] = levelSymbol;
    textFunctionsList['='] = equalSign;
    textFunctionsList[';'] = semiColonMark;
    textFunctionsList['%'] = percentageSymbol;
    textFunctionsList[10] = nextLineSymbol;
}

double Text::drawChar(char charItem, double x, double y, double scale) {
    return this->textFunctionsList[charItem](x, y, scale);
}

double Text::drawNext(double x, double y, double scale) {
    return this->textFunctionsList[10](x, y, scale);
}