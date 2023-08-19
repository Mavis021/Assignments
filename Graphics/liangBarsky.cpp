#include <iostream>
#include <graphics.h>

#define TopLimit 400
#define BottomLimit 100
#define RightLimit 500
#define LeftLimit 200

void drawClippingWindow()
{
    line(LeftLimit, BottomLimit, RightLimit, BottomLimit);
    line(RightLimit, BottomLimit, RightLimit, TopLimit);
    line(RightLimit, TopLimit, LeftLimit, TopLimit);
    line(LeftLimit, TopLimit, LeftLimit, BottomLimit);
}

int clipTest(float numerator, float denominator, float *u1, float *u2)
{
    float t;
    int result = 1;
    t = denominator / numerator;
    
    if (numerator < 0.0)
    {
        if (t > *u2)
            result = 0;
        else if (t > *u1)
            *u1 = t;
    }
    else if (numerator > 0.0)
    {
        if (t < *u1)
            result = 0;
        else if (t < *u2)
            *u2 = t;
    }
    else
    {
        if (denominator < 0.0)
        {
            std::cout << "Line is parallel and outside the clipping window" << std::endl;
            result = 0;
        }
    }
    return (result);
}

void liangClipping(float x1, float y1, float x2, float y2)
{
    int flag = 0;
    float numerator[4], denominator[4];
    float u1 = 0;
    float u2 = 1;
    float dx = x2 - x1;
    float dy = y2 - y1;

    numerator[0] = -dx;
    numerator[1] = dx;
    numerator[2] = -dy;
    numerator[3] = dy;

    denominator[0] = x1 - LeftLimit;
    denominator[1] = RightLimit - x1;
    denominator[2] = y1 - BottomLimit;
    denominator[3] = TopLimit - y1;

    if (clipTest(numerator[0], denominator[0], &u1, &u2))
        if (clipTest(numerator[1], denominator[1], &u1, &u2))
            if (clipTest(numerator[2], denominator[2], &u1, &u2))
                if (clipTest(numerator[3], denominator[3], &u1, &u2))
                {
                    if (u2 < 1.0)
                    {
                        x2 = x1 + u2 * dx;
                        y2 = y1 + u2 * dy;
                    }
                    if (u1 > 0.0)
                    {
                        x1 += u1 * dx;
                        y1 += u1 * dy;
                    }
                    flag = 1;
                    line(x1, y1, x2, y2);
                }
    if (flag == 0)
    {
        std::cout << "Line lies completely outside!" << std::endl;
    }
}

int main()
{
    float start_x, start_y, end_x, end_y;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char *)"");
    start_x = 500;
    start_y = 400;
    end_x = 80;
    end_y = 80;
    drawClippingWindow();
    liangClipping(start_x, start_y, end_x, end_y);
    getch();
    closegraph();
    return 0;
}