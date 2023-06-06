#include<graphics.h>
#include<math.h>
#include<dos.h>

int main(int argc, char const *argv[])
{
    int gd = DETECT, gm;
    initgraph(&gd,&gm,(char*)"");

    int x1,x2,x3,x4;
    float a1;
    
    x1 = 147;
    x2 = 317;
    x3 = 267;
    a1 = 0;

    setcolor(YELLOW);

    for(int i =0;i<400;i++)
    {
        //car body
        line(100+i,200,100+i,300);
        line(100+i,300,110+i,300);
        line(150+i,300,230+i,300);
        line(270+i,300,300+i,300);
        line(300+i,300,300+i,250);
        line(300+i,250,250+i,250);
        line(250+i,250,100+i,250);
        line(250+i,250,200+i,200);
        line(150+i,200,150+i,250);
        line(200+i,200,100+i,200);
        //car body

        //tires
        circle(130+i,300,20);
        circle(250+i,300,20);
        circle(130+i,300,17);
        circle(250+i,300,17);
        line(130+i,300,x1,x2);
        line(250+i,300,x3,x2);
        x1 =130+i+ int(17 * cos(a1));
        x2 =300 + int(17* sin(a1));
        x3 =250+i+ int(17* cos(a1));
        a1 = i*0.10472; //6 degrees division
        //tires

        //road
        line(0,320,800,320);

        delay(100);//1 seconds
        clearviewport();
    }

    getch();
    closegraph();
    return 0;
}
