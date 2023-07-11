#include<iostream>
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <graphics.h>
#include <dos.h>

class transformation
{
    private:
    int i,j,k,n,prompt;
    int p[3][3],store[3][3];
    float cm[3][3],t[3][3];

    public:
    transformation():n(0),i(0),j(0),k(0)
    {
        //for 2d transformation creating 3 x 3 matrix dynamically
        prompt = 0;
        for(i =0;i<3;i++){
            for(j =0;j<3;j++){
                if(i == j)
                    cm[i][j] = 1;
                else
                cm[i][j] = 0;
            }
        }

        line(300,0,300,500);
        line(0,300,600,300);
       // get the input points of a triangle
       std::cout<<"ENTER THE POINTS OF THE TRIANGLE IN MATRIX FORM: "<<std::endl;
        for(i =0;i<3;i++){
            for(j = 0;j<3;j++){
                    if(i == 2){
                        p[i][j] = 1;
                    }
                    else
                    std::cin>>p[i][j];
                }
            }

        // p[0][0] = 500;
        // p[0][1] = 400;
        // p[0][2] = 500;
        // p[1][0] = 200;
        // p[1][1] = 200;
        // p[1][2] = 100;
        // p[2][0] = 1;
        // p[2][1] = 1;
        // p[2][2] = 1;

        for(i=0;i<3;i++){
            for(j=0;j<3;j++){
                store[i][j] = p[i][j];
            }
        }
        makeTriangle();
    }

    void makeTriangle()
    {
        line(p[0][0],p[1][0],p[0][1],p[1][1]);
        line(p[0][0],p[1][0],p[0][2],p[1][2]);
        line(p[0][1],p[1][1],p[0][2],p[1][2]);
    }

    void chooseOperation()
    {
        system("cls");
        char ch = 'y';
        while(ch == 'y'){
        std::cout<<"\n 1 for TRANSLATION \n 2 FOR SCALING ABOUT ORIGIN \n 3 FOR SCALING ABOUT FIXED POINT \n 4 FOR ROTATION ABOUT ORIGIN \n 5 FOR ROTATING ABOUT A FIXED POINT\n 6 FOR RELECTION ABOUT X-AXIS \n 7 FOR REFLECTION ABOUT Y-AXIS \n ";//8 FOR REFLECTION ABOUT Y = MX +C \n 9 FOR SHARING(XY)
        std::cin>>prompt;
        switch(prompt){
            case 1:{
                translation();
                transform();
                break;
            }
            case 2:{
                scalingAboutOrigin();
                transform();
                break;
            }
            case 3:{
                fixedPointScaling();
                transform();
                break;
            }
            case 4:{
                rotationAboutOrigin();
                transform();
                break;
            }
            case 5:{
                fixedPointRotation();
                transform();
                break;
            }
            case 6:{
                reflectionxy(1);
                break;
            }
            case 7:{
                reflectionxy(2);
                break;
            }
            case 8:{
                clearviewport();
                line(300,0,300,500);
                line(0,300,600,300);
                // reflectiont(1);
                // line(100,500,500,100);
                // reflectiont(-1)
                // line(100,500,500,100);
                        // p[0][0] = 500;
                        
        p[0][1] = 400;
        p[0][2] = 500;
        p[1][0] = 200;
        p[1][1] = 200;
        p[1][2] = 100;
        p[2][0] = 1;
        p[2][1] = 1;
        p[2][2] = 1;
        makeTriangle();
        delay(100);
                reflectiont(1);
                line(100,500,500,100);
                reflectiont(2);
                line(500,500,100,100);
                break;
            }
            default:{
            std::cout<<"choose Operation error";
            break;
            }
        }
        //matrix multiplication cm * p;
        //transform();
        makeTriangle();
        clearall();
        std::cout<<"\n Would you like to try next? 'y': ";
        std::cin>>ch;
        }
    }

    void clearall(){
        for(i =0;i<3;i++){
            for(j =0;j<3;j++){
                if(i == j){
                    cm[i][j] = 1;
                    t[i][j] = 1;
                }
                else{
                cm[i][j] = 0;
                t[i][j] = 0;
                }
            }
        }
                for(i=0;i<3;i++){
            for(j=0;j<3;j++){
                p[i][j] = store[i][j];
            }
        }
    }
    void reflectiont(int slope = 1){
        if(slope == 1){
            p[0][0] = 400;
            p[1][0] = 100;
            makeTriangle();
        }
        else{
            p[0][0] = 200;
            p[1][0] = 500;
            p[0][1] = 200;
            p[1][1] = 400;
            p[0][2] = 100;
            p[1][2] = 500;
            p[2][0] = 1;
            p[2][1] = 1;
            p[2][2] =1;
        }
    }

    void reflection(int m = 1,int c = 0){

        //y = mx+3
         for(i=0;i<3;i++){
            for(j=0;j<3;j++){
                cm[i][j] = p[i][j];
            }   
        }
        float angle = atan(m);
        float temp[3][3];

        //translation(300,300-c)
        for(i=0;i<3;i++){
            for(j=0;j<3;j++){
                if(i == j)
                t[i][j] = 1;
                else
                t[i][j] = 0;
            }
            t[0][2] = 0;
            t[1][2] = -c;    
        }
        matMul(t,cm);
        std::cout<<"translation ";
        //rotation(-theta)
                for(i=0;i<3;i++){
            for(j=0;j<3;j++){
                if(i == j)
                t[i][j] = 1;
                else
                t[i][j] = 0;
            }}
        t[0][0] *= cos(-angle);
        t[0][1] -= sin(-angle);
        t[1][0] += sin(-angle);
        t[1][1] *= t[0][0];

        matMul(t,cm);
        std::cout<<"rotation ";

        //reflection about x-axis
                        for(i=0;i<3;i++){
            for(j=0;j<3;j++){
                if(i == j)
                t[i][j] = 1;
                else
                t[i][j] = 0;
            }}
        for(i=0;i<3;i++){
            for(j =0;j<3;j++){
                temp[i][j] = 0;
                //X-axis
                        if(i == 1)
                        t[1][1] = (2*300/cm[i][j])-1;
                    
                for(k =0;k<3;k++){
                    //std::cout<<i<<j<<k;
                    temp[i][j] += t[i][k]*cm[k][j];
                }
            }
        }
        for(i=0;i<3;i++){
            for(j =0;j<3;j++){
                    cm[i][j] = temp[i][j];
            }
        }
        std::cout<<"reflection ";

        //rotation(+)
        for(i=0;i<3;i++){
            for(j=0;j<3;j++){
                if(i == j)
                t[i][j] = 1;
                else
                t[i][j] = 0;
            }   
        }
        t[0][0] *= cos(angle);
        t[0][1] -= sin(angle);
        t[1][0] += sin(angle);
        t[1][1] *= t[0][0];
        matMul(t,cm);
        std::cout<<"rotation ";

        //t(0,c)
        for(i=0;i<3;i++){
            for(j=0;j<3;j++){
                if(i == j)
                t[i][j] = 1;
                else
                t[i][j] = 0;
            }   
            t[0][2] = 300;
            t[1][2] = 300+c;  
        }
        matMul(t,cm);
        std::cout<<"translation ";

                 for(i=0;i<3;i++){
            for(j=0;j<3;j++){
                p[i][j] = cm[i][j];
                std::cout<<p[i][j];
            }   
        }
        // cm[0][0] = float(a)/b;
        // cm[0][1] = (2*m)/b;
        // cm[0][2] = (-2*m*c)/b;
        // cm[1][0] = cm[0][1];
        // cm[1][1] = -cm[0][0];
        // cm[1][2] = float(2*c)/b;
        // cm[2][0] = 0;
        // cm[2][1] = 0;
        // cm[2][2] = 1;
    }
    
    void translation(){
        std::cout<<"enter the translation vector: ";
        //get the translation vector
        std::cin>>cm[0][2]>>cm[1][2];
    }

    void scaling(){
        std::cout<<"ENTER THE SCALING VECTOR: ";
        std::cin>>cm[0][0]>> cm[1][1] ;
    }

    void scalingAboutOrigin(){
         for(i=0;i<3;i++){
            for(j=0;j<3;j++){
                if(i == j)
                t[i][j] = 1;
                else
                t[i][j] = 0;
            }
            t[0][2] = 300;
            t[1][2] = 300;    
        }
        scaling();
        matMul(t,cm);

            t[0][2] = -p[0][0];
            t[1][2] = -p[1][0];          
        matMul(cm,t);
    }
    void tvec(int check=0){
    
        for(i=0;i<3;i++){
            for(j=0;j<3;j++){
                if(i == j)
                t[i][j] = 1;
                else
                t[i][j] = 0;
            }
        }
        if(check == 1){
            t[0][2] = -p[0][0];
            t[1][2] = -p[1][0];
        }
        else{
            t[0][2] = p[0][0];
            t[1][2] = p[1][0];    
        }
    }

    void fixedPointScaling(){
        tvec();
        scaling();
        matMul(t,cm);
        tvec(1);
        matMul(cm,t);
    }

    void rotationAboutOrigin(){
         for(i=0;i<3;i++){
            for(j=0;j<3;j++){
                if(i == j)
                t[i][j] = 1;
                else
                t[i][j] = 0;
            }
            t[0][2] = 300;
            t[1][2] = 300;    
        }
        rotation();
        matMul(t,cm);

            t[0][2] = -p[0][0];
            t[1][2] = -p[1][0];          
        matMul(cm,t);
    }
    void rotation(){
        float angle;
        std::cout<<"\n ENTER THE ANGLE FOR THE ROTATION:";
        std::cin>>angle;
        cm[0][0] *= cos(3.1415 * (angle/180.0));
        cm[0][1] -= sin(3.1415 * (angle/180.0));
        cm[1][0] += sin(3.1415 * (angle/180.0));
        cm[1][1] *= cm[0][0];

    }

    void fixedPointRotation(){
        tvec();
        rotation();
        matMul(t,cm);
        
        tvec(1);
       matMul(cm,t);
    }

    void reflectionxy(int check = 0){
        std::cout<<"transform \n";
                for(i=0;i<3;i++){
            for(j =0;j<3;j++){
        
        std::cout<<"\n"<<p[i][j];        
            }
                }
        float temp[3][3];
        for(i=0;i<3;i++){
            for(j =0;j<3;j++){
                temp[i][j] = 0;
                    if(check == 1){ //X-axis
                        if(i == 1)
                        cm[1][1] = (2*300/p[i][j])-1;
                    }
                    else {
                        if(i == 0)
                        cm[0][0] = (float(2*300)/p[i][j])-1;
                    }
                    
                for(k =0;k<3;k++){
                    //std::cout<<i<<j<<k;
                    temp[i][j] += cm[i][k]*p[k][j];
                }
            }
        }
        for(i=0;i<3;i++){
            for(j =0;j<3;j++){
                    p[i][j] = int(temp[i][j]);
        
        std::cout<<"\n"<<p[i][j];        
            }
        }
        
        std::cout<<"transform sucess \n";
    }

    void transform(){
        std::cout<<"transform \n";
        float temp[3][3];
        for(i=0;i<3;i++){
            for(j =0;j<3;j++){
                temp[i][j] = 0;
                for(k =0;k<3;k++){
                    //std::cout<<i<<j<<k;
                    temp[i][j] += cm[i][k]*p[k][j];
                }
            }
        }
        for(i=0;i<3;i++){
            for(j =0;j<3;j++){
                    p[i][j] = int(temp[i][j]);
        
        std::cout<<"\n"<<p[i][j];        
            }
        }
        
        std::cout<<"transform sucess \n";
    }

    void matMul(float c[][3],float t[][3]){
        float temp[3][3];
        for(i=0;i<3;i++){
            for(j =0;j<3;j++){
                temp[i][j] = 0;
                for(k =0;k<3;k++){
                    //std::cout<<i<<j<<k;
                    temp[i][j] += c[i][k]*t[k][j];
                }
            }
        }
        for(i=0;i<3;i++){
            for(j =0;j<3;j++){
                    cm[i][j] = temp[i][j];  
            }
        }
    }
};
int main(int argc, char const *argv[])
{
    int gd = DETECT, gm;
    initgraph(&gd,&gm,(char*)"");
            transformation tr;
            tr.chooseOperation();

    getch();
    closegraph();
    return 0;
}

