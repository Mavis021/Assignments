#include <iostream>
#include <graphics.h>

void floodFill(int x, int y, int fillColor, int oldColor) {
    if (x < 0 || x >= getmaxx() || y < 0 || y >= getmaxy() || getpixel(x, y) != oldColor)
        return;

    putpixel(x, y, fillColor);

    floodFill(x + 1, y, fillColor, oldColor); // Right
    floodFill(x - 1, y, fillColor, oldColor); // Left
    floodFill(x, y + 1, fillColor, oldColor); // Down
    floodFill(x, y - 1, fillColor, oldColor); // Up
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");

    rectangle(200, 200, 350, 350);
    floodFill(250, 250, RED, BLACK);

    getch();
    closegraph();
    return 0;
}
