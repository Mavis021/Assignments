#include <iostream>
#include <graphics.h>
#include<cmath>

class CustomPoint {
public:
    int xPos, yPos;

    CustomPoint(int _x = 0, int _y = 0) : xPos(_x), yPos(_y) {}
};

int customBinomialCoeff(int n, int k) {
    if (k == 0 || k == n)
        return 1;
    return customBinomialCoeff(n - 1, k - 1) + customBinomialCoeff(n - 1, k);
}

CustomPoint calculateCustomBezierPoint(CustomPoint p[], double t, int n) {
    double xVal = 0, yVal = 0;
    int customBinCoeff;

    for (int i = 0; i < n; i++) {
        customBinCoeff = customBinomialCoeff(n - 1, i);
        xVal += customBinCoeff * p[i].xPos * pow(1 - t, n - 1 - i) * pow(t, i);
        yVal += customBinCoeff * p[i].yPos * pow(1 - t, n - 1 - i) * pow(t, i);
    }

    return CustomPoint(static_cast<int>(xVal), static_cast<int>(yVal));
}

int main() {
    int graphicsDriver = DETECT, graphicsMode;
    initgraph(&graphicsDriver, &graphicsMode, (char*)""); 

    int numControlPoints = 4; 
    CustomPoint controlPoints[numControlPoints] = {{150, 400}, {300, 100}, {450, 500}, {600, 200}};

    for (int i = 0; i < numControlPoints; i++) {
        putpixel(controlPoints[i].xPos, controlPoints[i].yPos, WHITE);
        if (i < numControlPoints - 1) {
            line(controlPoints[i].xPos, controlPoints[i].yPos, controlPoints[i + 1].xPos, controlPoints[i + 1].yPos);
        }
    }

    for (double t = 0; t <= 1; t += 0.001) {
        CustomPoint curvePoint = calculateCustomBezierPoint(controlPoints, t, numControlPoints);
        putpixel(curvePoint.xPos, curvePoint.yPos, GREEN);
    }

    delay(10000);
    closegraph();
    return 0;
}