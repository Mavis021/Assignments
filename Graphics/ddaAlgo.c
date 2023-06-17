//DDA Algorithms 
#include<graphics.h>
#include<math.h>
#include<conio.h>
#include<dos.h>

int main(int argc, char const *argv[])
{
    int gd = DETECT, gm;
    initgraph(&gd,&gm,(char*)"");

    int x1,x2,y1,y2,i;
    float delx,dely,steps,xin,yin;

printf("ENTER THE ENDPOINTS OF THE LINE: ");
scanf("%d %d %d %d",&x1,&y1,&x2,&y2);

    delx = x2 - x1;
    dely = y2 - y1;

    if(abs(delx)>=abs(dely))
        steps = abs(delx);
    else
        steps = abs(dely);

    xin = delx/steps;
    yin = dely/steps;

    for(i = 0;i<=steps;i++)
    {
        putpixel(int(x1),int(y1),WHITE);
        x1 +=xin;
        y1 += yin;
        delay(100);
    }  
    
    getch();
    closegraph();
    return 0;
}
