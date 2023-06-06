#include<graphics.h>
#include<math.h>
#include<dos.h>

int main(int argc, char const *argv[])
{
    int gd = DETECT, gm;
    initgraph(&gd,&gm,(char*)"");

    int x1,x2;
    float a1;
    
    x1 = 380;
    x2 = 200;
    a1 = 0;

    setcolor(YELLOW);

    for(int i =0;i<60;i++)
    {
        circle(320,200,65);
        x1 =320 + int(60 * cos(-1.57075 +a1));
        x2 =200 + int(60 * sin(-1.57075 +a1));
        line(320,200,x1,x2);
        a1 = i*0.10472; //6 degrees division
        delay(1000);//1 seconds
        clearviewport();
    }

    getch();
    closegraph();
    return 0;
}
