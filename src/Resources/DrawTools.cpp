#include "DrawTools.h"

void rectangle(double startX, double startY, double xDist, double yDist, double width, double height, double scale) {
    ofDrawRectangle(startX + (xDist * scale), startY + (yDist * scale), scale * width, scale * height);
}

void doubleRect(double startX, double startY, double xDist, double yDist, double width, double height, double scale) {
    // Shadow
    ofSetColor(208, 208, 200);
    rectangle(startX, startY, xDist + width, yDist, 1, height + 1, scale);
    rectangle(startX, startY, xDist, yDist + height, width, 1, scale);
    // Normal
    ofSetColor(77, 77, 77);
    rectangle(startX, startY, xDist, yDist, width, height, scale);
}

void setTextColor1() {
    ofSetColor(77, 77, 77);
}

void setTextColor2() {
    ofSetColor(208, 208, 200);
}

void setLastTextboxColor() {
    ofSetColor(224, 232, 224);
}