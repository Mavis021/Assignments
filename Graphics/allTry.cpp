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

class midpointCircleAlgorithm
{
    private:
    int a,b,r,xk,yk,pk,i;

    public:
    midpointCircleAlgorithm():i(0)
    {
        getData();

        xk = 0;
        yk = r;     
        pk = 1-r; 
    }

    void composeOneEighth()
    {
        delay(50);

        if(pk <= 0)
        {
            xk += 1;
            pk +=2 *xk +1;
        }
        else
        {
            xk += 1;
            yk -= 1;
            pk += 2*xk - 2*yk +1;
        }

    }

    void makeCircle()
    {
        for( i =0 ; xk<=yk; i++)
        {
           putpixel(yk+b,xk+a,1);
            putpixel(yk+b,-xk+a,2);
            putpixel(-yk+b, xk+a,3);
            putpixel(-yk+b,-xk+a,4);
            putpixel(xk+a,yk+b,5);
            putpixel(-xk+a,yk+b,6);
            putpixel(-xk+a,yk+b,7);
            putpixel(xk+a,-yk+b,8);
            composeOneEighth();
        }
    }
    void getData()
    {
        std::cout<<"ENTER THE CENTER AND RADIUS OF THE CIRCLE: ";
        std::cin>>a>>b>>r;
    }

};

int main(int argc, char const *argv[])
{
    int gd = DETECT, gm;
    initgraph(&gd,&gm,(char*)"");

//    BeserhamLineAlgorithm BLA;
//    BLA.calculation();

midpointCircleAlgorithm mpa;
mpa.makeCircle();

    getch();
    closegraph();
    return 0;
}


