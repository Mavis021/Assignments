
//BLA Algorithms 
#include<iostream>
#include<graphics.h>
#include<cmath>
#include<conio.h>
#include<dos.h>

class BeserhamLineAlgorithm
{
    private:
    int a,b,x1,x2,y1,y2,i,delx,dely,p0;

    public:
    BeserhamLineAlgorithm():p0(0),i(0)
    {
        getData();

        delx = fabs(x2-x1);
        dely = fabs(y2-y1);
        if(x2>x1)
        a = 1;
        else 
        a = -1;

        if(y2>y1)
        b = 1;
        else
        b = -1;        
    }

    void calculation()
    {
        if(delx>dely)
        {
            p0 += 2*dely  - delx;

            for(i =0 ;i<=delx;i++)
            {

                putpixel(x1,x2,RED);
                delay(50);

                if(p0<0)
                {
                    x1 += a;
                    p0 += 2*dely;
                }
                else
                {
                    x1 += a;
                    y1 += b;
                    p0 += 2*dely - 2*delx;
                }
            }
        }
        else
        {
            p0 += 2*delx - dely;

            for(i = 0;i<dely;i++)
            {
                putpixel(x1,y1,YELLOW);
                delay(50);

            if(p0<= 0)
            {
                y1 += b;
                p0 += 2 * delx;
            }
            else
            {
                x1 += a;
                y1 += b;
                p0 += 2*delx-2*dely;
            }
            }
        }
    }
    void getData()
    {
        std::cout<<"ENTER THE END-POINTS OF THE LINE: ";
        std::cin>>x1>>y1>>x2>>y2;
    }

};

int main(int argc, char const *argv[])
{
    int gd = DETECT, gm;
    initgraph(&gd,&gm,(char*)"");

   BeserhamLineAlgorithm BLA;
   BLA.calculation();

    getch();
    closegraph();
    return 0;
}
