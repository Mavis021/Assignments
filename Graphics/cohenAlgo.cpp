//cohen sutherland line clipping algorithm

#include<iostream>
#include<cmath>
#include<graphics.h>
#include<dos.h>
#include<cstring>

class cohenSutherland{

private:
int xmin,ymin,xmax,ymax;
int inside,top,bottom,left,right,code1,code2;
int x1,y1,x2,y2;
float slope;

public:
cohenSutherland():xmin(100),ymin(100),xmax(400),ymax(400){

//TOP-BOTTOM-RIGHT-LEFT
top = 8;// {1,0,0,0};
bottom = 4; //{0,1,0,0};
left = 1;//{0,0,0,1};
right = 2; //{0,0,1,0};
inside = 0; //{0,0,0,0};

code1 = 0; //{0,0,0,0};
code2 = 0; //{0,0,0,0};
getLine();
drawWindow();
drawLine();
}

void getLine(){
    std::cout<<"\n ENTER THE ENDPOINTS OF THE LINE: ";
    std::cin>>x1>>y1>>x2>>y2;
    slope = (y2-y1)/(x2-x1);
}

int code(float x, float y){

    int c = inside;

    if(x<xmin)
    c |= left;
    else if(x> xmax)
    c |= right;
    if(y<ymin)
    c |= bottom;
    else if(y > ymax)
    c |= top;

    return c;
}


void trivialAcceptance(){

bool accept = false;
code1 = code(x1,y1);
code2 = code(x2,y2);

while(true){
    if((code1 == 0) && (code2 == 0)){
        accept = true;
        break;
    }
    else if(code1 & code2){
        //outside
        break;
    }
    else{

        int codeo;
        double x, y;
        //for first point

        if(code1 != 0)
        codeo = code1;
        else 
        codeo = code2;

        if((codeo & top)){
            x = x1 + (x2 - x1) *(ymax - y1)/(y2 - y1);
             y = ymax;
        }
        else if((codeo & bottom)){
            
            x = x1 + (x2 - x1)*(ymin - y1)/(y2-y1);
            y = ymin;
        }
        else if((codeo & right)){
            
            y = y1 + (y2 - y1)* (xmax - x1) / (x2 - x1);
            x = xmax;
        }
        else if((codeo & left)){   //indicating left side
            
            y = y1+ (y2 - y1) * (xmin - x1) / (x2 - x1);
            x = xmin;
        }

        if(codeo == code1){
            x1 = x;
            y1 = y;
            code1 = code(x1,y1);
        }
        else{
            x2 = x;
            y2 = y;
            code2 = code(x2,y2);
        }

    }
}

if(accept){
    std::cout<<"after clip: ";
    delay(2000);
    clearviewport();
    drawWindow();
    drawLine();
}
else
{
    std::cout<<"the line is outside the boundary. ";
}
}

void drawWindow(){
    rectangle(xmin,ymin,xmax,ymax);
}
void drawLine(){
    line(x1,y1,x2,y2);
}

};

int main(int argc, const char* argv[]){
    int gd = DETECT,gm;
    initgraph(&gd,&gm,(char*)"");

    cohenSutherland cs;
    cs.trivialAcceptance();

    getch();

    closegraph();
    return 0;
}
